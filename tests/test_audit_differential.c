#include "pc_bit_byte_reverse_u32.h"
#include "pc_bit_deinterleave4_u32.h"
#include "pc_bit_error_syndrome_u32.h"
#include "pc_bit_extract_u64.h"
#include "pc_bit_gather_u32.h"
#include "pc_bit_interleave4_u32.h"
#include "pc_bit_nibble_reverse_u32.h"
#include "pc_bit_pair_reverse_u32.h"
#include "pc_bit_reverse_u64.h"
#include "pc_bit_scatter_u32.h"
#include "pc_bit_shuffle_even_odd_u32.h"
#include "pc_bit_swap_u32.h"
#include "pc_bit_unshuffle_even_odd_u32.h"
#include "pc_bitset_count_ones_u32.h"
#include "pc_bitset_rotate_left_u32.h"
#include "pc_clz_u64.h"
#include "pc_ctz_u64.h"
#include "pc_deinterleave_nibbles_u32.h"
#include "pc_even_parity_insert_u32.h"
#include "pc_gray_decode_u64.h"
#include "pc_gray_encode_u64.h"
#include "pc_interleave_bytes_u32.h"
#include "pc_interleave_nibbles_u32.h"
#include "pc_mask_between_u32.h"
#include "pc_mask_count_runs_u32.h"
#include "pc_mask_is_contiguous_u32.h"
#include "pc_mask_low_u64.h"
#include "pc_mask_lowest_n_u32.h"
#include "pc_parity_strip_check_u32.h"
#include "pc_parity_u64.h"
#include "pc_popcount_u64.h"
#include "pc_rotate_left_u64.h"
#include "pc_secded_parity_u32.h"
#include "pc_swap_bitpairs_u32.h"
#include "pc_swap_bytes16_u32.h"
#include "pc_swap_nibbles_u32.h"
#include "pc_xorshift32.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "audit check failed at line %d: %s\n", __LINE__, #condition); \
    return 1; \
} } while (0)

static uint64_t rng_state = UINT64_C(0xD1B54A32D192ED03);

static uint64_t next_random(void)
{
    rng_state += UINT64_C(0x9E3779B97F4A7C15);
    uint64_t z = rng_state;
    z = (z ^ (z >> 30u)) * UINT64_C(0xBF58476D1CE4E5B9);
    z = (z ^ (z >> 27u)) * UINT64_C(0x94D049BB133111EB);
    return z ^ (z >> 31u);
}

static uint32_t ref_pop32(uint32_t x)
{
    uint32_t n = 0u;
    unsigned i;
    for (i = 0u; i < 32u; ++i) n += (x >> i) & 1u;
    return n;
}

static unsigned ref_pop64(uint64_t x)
{
    unsigned n = 0u, i;
    for (i = 0u; i < 64u; ++i) n += (unsigned)((x >> i) & UINT64_C(1));
    return n;
}

static uint32_t ref_gather(uint32_t x, uint32_t mask)
{
    uint32_t out = 0u;
    unsigned src, dst = 0u;
    for (src = 0u; src < 32u; ++src) {
        if (((mask >> src) & 1u) != 0u) {
            out |= ((x >> src) & 1u) << dst;
            ++dst;
        }
    }
    return out;
}

static uint32_t ref_scatter(uint32_t x, uint32_t mask)
{
    uint32_t out = 0u;
    unsigned dst, src = 0u;
    for (dst = 0u; dst < 32u; ++dst) {
        if (((mask >> dst) & 1u) != 0u) {
            out |= ((x >> src) & 1u) << dst;
            ++src;
        }
    }
    return out;
}

static uint32_t ref_byte_reverse(uint32_t x)
{
    uint32_t out=0u; unsigned byte, bit;
    for(byte=0u;byte<4u;++byte)for(bit=0u;bit<8u;++bit)
        out|=((x>>(8u*byte+bit))&1u)<<(8u*byte+7u-bit);
    return out;
}

static uint32_t ref_nibble_reverse(uint32_t x)
{
    uint32_t out=0u; unsigned nibble, bit;
    for(nibble=0u;nibble<8u;++nibble)for(bit=0u;bit<4u;++bit)
        out|=((x>>(4u*nibble+bit))&1u)<<(4u*nibble+3u-bit);
    return out;
}

static uint32_t ref_pair_reverse(uint32_t x)
{
    uint32_t out=0u; unsigned pair;
    for(pair=0u;pair<16u;++pair){out|=((x>>(2u*pair))&1u)<<(2u*pair+1u);out|=((x>>(2u*pair+1u))&1u)<<(2u*pair);}
    return out;
}

static uint32_t ref_swap_bitpairs(uint32_t x)
{
    uint32_t out=0u; unsigned nibble;
    for(nibble=0u;nibble<8u;++nibble){const uint32_t n=(x>>(4u*nibble))&15u;out|=(((n&3u)<<2u)|((n>>2u)&3u))<<(4u*nibble);}
    return out;
}

static uint32_t ref_swap_bytes16(uint32_t x)
{
    uint32_t out=0u; unsigned half;
    for(half=0u;half<2u;++half){const uint32_t h=(x>>(16u*half))&UINT32_C(0xFFFF);out|=(((h&UINT32_C(0xFF))<<8u)|(h>>8u))<<(16u*half);}
    return out;
}

static uint32_t ref_swap_nibbles(uint32_t x)
{
    uint32_t out=0u; unsigned byte;
    for(byte=0u;byte<4u;++byte){const uint32_t b=(x>>(8u*byte))&UINT32_C(0xFF);out|=(((b&15u)<<4u)|(b>>4u))<<(8u*byte);}
    return out;
}

static bool ref_is_contiguous(uint32_t x)
{
    bool seen_one=false, seen_zero_after_one=false; unsigned i;
    for(i=0u;i<32u;++i){const bool bit=((x>>i)&1u)!=0u;if(bit){if(seen_zero_after_one)return false;seen_one=true;}else if(seen_one)seen_zero_after_one=true;}
    return seen_one;
}

static uint64_t ref_reverse64(uint64_t x)
{
    uint64_t out = 0u;
    unsigned i;
    for (i = 0u; i < 64u; ++i) out |= ((x >> i) & UINT64_C(1)) << (63u - i);
    return out;
}

static uint32_t ref_shuffle(uint32_t x)
{
    uint32_t out = 0u;
    unsigned i;
    for (i = 0u; i < 16u; ++i) {
        out |= ((x >> (2u * i)) & 1u) << i;
        out |= ((x >> (2u * i + 1u)) & 1u) << (i + 16u);
    }
    return out;
}

static uint32_t ref_unshuffle(uint32_t x)
{
    uint32_t out = 0u;
    unsigned i;
    for (i = 0u; i < 16u; ++i) {
        out |= ((x >> i) & 1u) << (2u * i);
        out |= ((x >> (i + 16u)) & 1u) << (2u * i + 1u);
    }
    return out;
}

static uint32_t ref_interleave4(uint32_t x)
{
    uint32_t out = 0u;
    unsigned lane, bit;
    for (lane = 0u; lane < 4u; ++lane)
        for (bit = 0u; bit < 8u; ++bit)
            out |= ((x >> (8u * lane + bit)) & 1u) << (4u * bit + lane);
    return out;
}

static uint32_t ref_deinterleave4(uint32_t x)
{
    uint32_t out = 0u;
    unsigned lane, bit;
    for (lane = 0u; lane < 4u; ++lane)
        for (bit = 0u; bit < 8u; ++bit)
            out |= ((x >> (4u * bit + lane)) & 1u) << (8u * lane + bit);
    return out;
}

static uint32_t ref_interleave_bytes(uint32_t x)
{
    uint32_t out=0u; unsigned bit;
    for(bit=0u;bit<8u;++bit){
        out|=((x>>bit)&1u)<<bit;
        out|=((x>>(16u+bit))&1u)<<(8u+bit);
        out|=((x>>(8u+bit))&1u)<<(16u+bit);
        out|=((x>>(24u+bit))&1u)<<(24u+bit);
    }
    return out;
}

static uint32_t ref_interleave_nibbles(uint32_t x)
{
    static const uint8_t src_for_dst[8] = { 0u, 4u, 1u, 5u, 2u, 6u, 3u, 7u };
    uint32_t out = 0u;
    unsigned i;
    for (i = 0u; i < 8u; ++i)
        out |= ((x >> (4u * src_for_dst[i])) & UINT32_C(0xF)) << (4u * i);
    return out;
}

static uint32_t ref_deinterleave_nibbles(uint32_t x)
{
    static const uint8_t src_for_dst[8] = { 0u, 2u, 4u, 6u, 1u, 3u, 5u, 7u };
    uint32_t out = 0u;
    unsigned i;
    for (i = 0u; i < 8u; ++i)
        out |= ((x >> (4u * src_for_dst[i])) & UINT32_C(0xF)) << (4u * i);
    return out;
}

static unsigned ref_clz64(uint64_t x)
{
    unsigned n = 0u;
    if (x == 0u) return 64u;
    while ((x & (UINT64_C(1) << 63u)) == 0u) { ++n; x <<= 1u; }
    return n;
}

static unsigned ref_ctz64(uint64_t x)
{
    unsigned n = 0u;
    if (x == 0u) return 64u;
    while ((x & UINT64_C(1)) == 0u) { ++n; x >>= 1u; }
    return n;
}

static uint64_t ref_rotate64(uint64_t x, uint32_t count)
{
    uint32_t i; count &= 63u;
    for(i=0u;i<count;++i)x=(x<<1u)|(x>>63u);
    return x;
}

static uint32_t ref_rotate32(uint32_t x, uint32_t count)
{
    uint32_t i; count &= 31u;
    for(i=0u;i<count;++i)x=(x<<1u)|(x>>31u);
    return x;
}

static uint8_t ref_count_runs(uint32_t x)
{
    uint8_t count=0u; bool previous=false; unsigned i;
    for(i=0u;i<32u;++i){const bool bit=((x>>i)&1u)!=0u;if(bit&&!previous)++count;previous=bit;}
    return count;
}

static uint32_t ref_secded_checks(uint32_t data)
{
    uint8_t hamming = 0u;
    unsigned data_bit = 0u, pos;
    for (pos = 1u; pos <= 38u; ++pos) {
        if ((pos & (pos - 1u)) == 0u) continue;
        if (((data >> data_bit) & 1u) != 0u) hamming ^= (uint8_t)pos;
        ++data_bit;
    }
    {
        uint8_t overall = (uint8_t)(ref_pop32(data) & 1u);
        unsigned i;
        for (i = 0u; i < 6u; ++i) overall ^= (uint8_t)((hamming >> i) & 1u);
        return (uint32_t)hamming | ((uint32_t)overall << 6u);
    }
}

static uint8_t ref_syndrome(uint32_t data, uint8_t check)
{
    uint8_t coordinate = 0u;
    uint8_t parity = (uint8_t)((ref_pop32(data) + ref_pop32((uint32_t)(check & 0x3fu)) +
                                ((check >> 6u) & 1u)) & 1u);
    unsigned data_bit = 0u, check_bit = 0u, pos;
    for (pos = 1u; pos <= 38u; ++pos) {
        uint32_t set;
        if ((pos & (pos - 1u)) == 0u) {
            set = (check >> check_bit) & 1u;
            ++check_bit;
        } else {
            set = (data >> data_bit) & 1u;
            ++data_bit;
        }
        if (set != 0u) coordinate ^= (uint8_t)pos;
    }
    return (uint8_t)(coordinate | ((uint8_t)(parity << 6u)));
}

static uint32_t ref_xorshift32(uint32_t x)
{
    x ^= (uint32_t)(x << 13u);
    x ^= x >> 17u;
    x ^= (uint32_t)(x << 5u);
    return x;
}

int main(void)
{
    static const uint64_t u64_edges[] = { 0u, 1u, UINT64_MAX, UINT64_C(0x8000000000000000),
        UINT64_C(0x0123456789ABCDEF), UINT64_C(0xAAAAAAAAAAAAAAAA) };
    static const uint32_t u32_edges[] = { 0u, 1u, UINT32_MAX, UINT32_C(0x80000000),
        UINT32_C(0x01234567), UINT32_C(0xAAAAAAAA) };
    unsigned i, j;

    /* Exhaust every 32-bit single-bit position for reversible fixed-width maps. */
    for (i = 0u; i < 32u; ++i) {
        const uint32_t bit = UINT32_C(1) << i;
        CHECK(pc_bit_byte_reverse_u32(bit) == ref_byte_reverse(bit));
        CHECK(pc_bit_gather_u32(bit, UINT32_MAX) == bit);
        CHECK(pc_bit_scatter_u32(bit, UINT32_MAX) == bit);
        { uint32_t swapped=0u; CHECK(pc_bit_swap_u32(bit,(uint8_t)i,(uint8_t)(31u-i),&swapped)); CHECK(swapped==(((bit>>i)&1u)==((bit>>(31u-i))&1u)?bit:(bit^(UINT32_C(1)<<i)^(UINT32_C(1)<<(31u-i))))); }
    }

    for (i = 0u; i < 6u; ++i) {
        const uint32_t x = u32_edges[i];
        const uint64_t y = u64_edges[i];
        uint32_t out32 = UINT32_C(0xA5A5A5A5);
        uint64_t out64 = UINT64_C(0xA5A5A5A5A5A5A5A5);
        CHECK(pc_bit_gather_u32(x, UINT32_MAX) == x);
        CHECK(pc_bit_scatter_u32(x, UINT32_MAX) == x);
        CHECK(pc_bit_gather_u32(pc_bit_scatter_u32(x, x), x) == (x & ((x == UINT32_MAX) ? UINT32_MAX : ((UINT32_C(1) << ref_pop32(x))-1u))));
        CHECK(pc_bit_reverse_u64(y) == ref_reverse64(y));
        CHECK(pc_bit_reverse_u64(pc_bit_reverse_u64(y)) == y);
        CHECK(pc_gray_decode_u64(pc_gray_encode_u64(y)) == y);
        CHECK(pc_popcount_u64(y) == ref_pop64(y));
        CHECK(pc_parity_u64(y) == (ref_pop64(y) & 1u));
        CHECK(pc_clz_u64(y) == ref_clz64(y));
        CHECK(pc_ctz_u64(y) == ref_ctz64(y));
        CHECK(pc_rotate_left_u64(y, 0u) == y);
        CHECK(pc_rotate_left_u64(y, 64u) == y);
        CHECK(pc_bit_extract_u64(y, 0u, 63u, &out64) && out64 == y);
        CHECK(pc_mask_low_u64(64u, &out64) && out64 == UINT64_MAX);
        CHECK(pc_mask_lowest_n_u32(32u, &out32) && out32 == UINT32_MAX);
    }
    {
        static const uint32_t counts[] = { 0u, 1u, 31u, 32u, 63u, 64u, UINT32_MAX };
        for(i=0u;i<sizeof(counts)/sizeof(counts[0]);++i){
            const uint64_t value=UINT64_C(0x8123456789ABCDEF);
            const uint32_t value32=UINT32_C(0x81234567);
            CHECK(pc_rotate_left_u64(value,counts[i])==ref_rotate64(value,counts[i]));
            CHECK(pc_bitset_rotate_left_u32(value32,counts[i])==ref_rotate32(value32,counts[i]));
        }
    }

    /* All width and range edges, plus invalid output-preservation paths. */
    for (i = 0u; i <= 64u; ++i) {
        uint64_t got = UINT64_MAX;
        const uint64_t expected = i == 64u ? UINT64_MAX : (i == 0u ? 0u : (UINT64_MAX >> (64u-i)));
        CHECK(pc_mask_low_u64((uint8_t)i, &got) && got == expected);
    }
    for (i = 0u; i <= 32u; ++i) {
        uint32_t got = UINT32_MAX;
        const uint32_t expected = i == 32u ? UINT32_MAX : (i == 0u ? 0u : (UINT32_MAX >> (32u-i)));
        CHECK(pc_mask_lowest_n_u32((uint8_t)i, &got) && got == expected);
    }
    for (i = 0u; i < 64u; ++i) for (j = i; j < 64u; ++j) {
        uint64_t got = UINT64_MAX;
        const unsigned width = j-i+1u;
        const uint64_t mask = width == 64u ? UINT64_MAX : ((UINT64_C(1) << width)-1u);
        const uint64_t value = UINT64_C(0xD3A57C9E102468BF);
        CHECK(pc_bit_extract_u64(value, (uint8_t)i, (uint8_t)j, &got));
        CHECK(got == ((value >> i) & mask));
    }
    {
        uint64_t out = UINT64_C(0x123456789ABCDEF0);
        CHECK(!pc_bit_extract_u64(0u, 1u, 0u, &out) && out == UINT64_C(0x123456789ABCDEF0));
        CHECK(!pc_bit_extract_u64(0u, 0u, 64u, &out) && out == UINT64_C(0x123456789ABCDEF0));
        CHECK(!pc_bit_extract_u64(0u, 255u, 255u, &out) && out == UINT64_C(0x123456789ABCDEF0));
        CHECK(!pc_bit_extract_u64(0u, 0u, 0u, NULL));
        CHECK(!pc_mask_low_u64(65u, &out) && out == UINT64_C(0x123456789ABCDEF0));
        CHECK(!pc_mask_low_u64(1u, NULL));
    }
    for (i = 0u; i < 32u; ++i) for (j = i; j < 32u; ++j) {
        uint32_t got = 0u;
        const uint32_t mask = j-i == 31u ? UINT32_MAX : ((UINT32_C(1) << (j-i+1u))-1u) << i;
        CHECK(pc_mask_between_u32((uint8_t)i,(uint8_t)j,&got) && got == mask);
    }
    {
        uint32_t out = UINT32_C(0xA5A5A5A5);
        CHECK(!pc_mask_between_u32(2u,1u,&out) && out == UINT32_C(0xA5A5A5A5));
        CHECK(!pc_mask_between_u32(0u,32u,&out) && out == UINT32_C(0xA5A5A5A5));
        CHECK(!pc_mask_between_u32(0u,255u,&out) && out == UINT32_C(0xA5A5A5A5));
        CHECK(!pc_mask_between_u32(0u,0u,NULL));
        CHECK(!pc_mask_lowest_n_u32(33u,&out) && out == UINT32_C(0xA5A5A5A5));
        CHECK(!pc_mask_lowest_n_u32(1u,NULL));
    }
    {
        uint32_t out = UINT32_C(0xA5A5A5A5);
        CHECK(pc_bit_swap_u32(UINT32_C(0x80000000),0u,31u,&out) && out == UINT32_C(0x00000001));
        CHECK(!pc_bit_swap_u32(0u,32u,0u,&out) && out == UINT32_C(0x00000001));
        CHECK(!pc_bit_swap_u32(0u,0u,255u,&out) && out == UINT32_C(0x00000001));
        CHECK(!pc_bit_swap_u32(0u,0u,0u,NULL));
    }

    /* Exhaustive nibble and byte lane models. */
    for (i = 0u; i < 256u; ++i) CHECK(pc_bit_byte_reverse_u32((uint32_t)i)==ref_byte_reverse((uint32_t)i));
    for (i = 0u; i < 65536u; ++i) {
        const uint32_t x = (uint32_t)i | ((uint32_t)(i ^ 0xFFFFu) << 16u);
        CHECK(pc_bit_interleave4_u32(x) == ref_interleave4(x));
        CHECK(pc_bit_deinterleave4_u32(pc_bit_interleave4_u32(x)) == x);
    }

    for (i = 0u; i < 100000u; ++i) {
        const uint64_t a = next_random(), b = next_random();
        const uint32_t x = (uint32_t)a, mask = (uint32_t)b;
        uint64_t got64;
        uint32_t got32;
        const unsigned first = (unsigned)(b % 64u);
        const unsigned last = first + (unsigned)((b >> 8u) % (64u-first));

        CHECK(pc_bit_extract_u64(a,(uint8_t)first,(uint8_t)last,&got64));
        { const unsigned w=last-first+1u; const uint64_t m=w==64u?UINT64_MAX:((UINT64_C(1)<<w)-1u); CHECK(got64==((a>>first)&m)); }
        CHECK(pc_bit_reverse_u64(a)==ref_reverse64(a));
        CHECK(pc_gray_encode_u64(a)==(a^(a>>1u)));
        CHECK(pc_gray_decode_u64(pc_gray_encode_u64(a))==a);
        CHECK(pc_popcount_u64(a)==ref_pop64(a));
        CHECK(pc_parity_u64(a)==(ref_pop64(a)&1u));
        CHECK(pc_clz_u64(a)==ref_clz64(a));
        CHECK(pc_ctz_u64(a)==ref_ctz64(a));
        CHECK(pc_rotate_left_u64(a,(uint32_t)b)==ref_rotate64(a,(uint32_t)b));
        CHECK(pc_mask_low_u64((uint8_t)(b%65u),&got64));
        CHECK(got64==((b%65u)==64u?UINT64_MAX:((b%65u)==0u?0u:(UINT64_MAX>>(64u-(b%65u))))));

        CHECK(pc_bit_byte_reverse_u32(x)==ref_byte_reverse(x));
        CHECK(pc_bit_gather_u32(x,mask)==ref_gather(x,mask));
        CHECK(pc_bit_scatter_u32(x,mask)==ref_scatter(x,mask));
        CHECK(pc_bit_gather_u32(pc_bit_scatter_u32(x,mask),mask)==(x & (ref_pop32(mask)==32u?UINT32_MAX:((UINT32_C(1)<<ref_pop32(mask))-1u))));
        CHECK(pc_bit_interleave4_u32(x)==ref_interleave4(x));
        CHECK(pc_bit_deinterleave4_u32(x)==ref_deinterleave4(x));
        CHECK(pc_bit_deinterleave4_u32(pc_bit_interleave4_u32(x))==x);
        CHECK(pc_bit_nibble_reverse_u32(x)==ref_nibble_reverse(x));
        CHECK(pc_bit_pair_reverse_u32(x)==ref_pair_reverse(x));
        CHECK(pc_bit_reverse_u64(a)==ref_reverse64(a));
        CHECK(pc_bit_shuffle_even_odd_u32(x)==ref_shuffle(x));
        CHECK(pc_bit_unshuffle_even_odd_u32(x)==ref_unshuffle(x));
        CHECK(pc_bit_unshuffle_even_odd_u32(pc_bit_shuffle_even_odd_u32(x))==x);
        CHECK(pc_bitset_count_ones_u32(x)==ref_pop32(x));
        CHECK(pc_bitset_rotate_left_u32(x,(uint32_t)b)==ref_rotate32(x,(uint32_t)b));
        CHECK(pc_deinterleave_nibbles_u32(x)==ref_deinterleave_nibbles(x));
        CHECK(pc_interleave_nibbles_u32(x)==ref_interleave_nibbles(x));
        CHECK(pc_interleave_nibbles_u32(pc_deinterleave_nibbles_u32(x))==x);
        CHECK(pc_interleave_bytes_u32(x)==ref_interleave_bytes(x));
        CHECK(pc_mask_count_runs_u32(x)==ref_count_runs(x));
        CHECK(pc_mask_is_contiguous_u32(x)==ref_is_contiguous(x));
        CHECK(pc_swap_bitpairs_u32(x)==ref_swap_bitpairs(x));
        CHECK(pc_swap_bytes16_u32(x)==ref_swap_bytes16(x));
        CHECK(pc_swap_nibbles_u32(x)==ref_swap_nibbles(x));
        CHECK(pc_xorshift32(x)==ref_xorshift32(x));
        CHECK(ref_pop64(pc_gray_encode_u64(a+1u)^pc_gray_encode_u64(a))==1u);

        CHECK(pc_bit_swap_u32(x,(uint8_t)(b&31u),(uint8_t)((b>>7u)&31u),&got32));
        { unsigned p=(unsigned)(b&31u),q=(unsigned)((b>>7u)&31u); uint32_t e=x; if(((x>>p)&1u)!=((x>>q)&1u))e^=(UINT32_C(1)<<p)|(UINT32_C(1)<<q); CHECK(got32==e); }
        CHECK(pc_even_parity_insert_u32(x&UINT32_C(0x7FFFFFFF),&got32));
        CHECK((ref_pop32(got32)&1u)==0u && (got32&UINT32_C(0x7FFFFFFF))==(x&UINT32_C(0x7FFFFFFF)));
        CHECK(pc_parity_strip_check_u32(got32,&got32));
        CHECK(got32==(x&UINT32_C(0x7FFFFFFF)));
        { uint8_t checks=0u,syndrome=UINT8_C(0xA5); CHECK(pc_secded_parity_u32(x,&checks)); CHECK(checks==ref_secded_checks(x)); CHECK(pc_bit_error_syndrome_u32(x,checks,&syndrome)); CHECK(syndrome==ref_syndrome(x,checks) && syndrome==0u); }
    }

    /* Invalid arguments preserve all documented output values. */
    {
        uint32_t w = UINT32_C(0xA5A5A5A5), p = UINT32_C(0xA5A5A5A5);
        uint8_t s = UINT8_C(0xA5);
        CHECK(!pc_even_parity_insert_u32(UINT32_C(0x80000000),&w) && w==UINT32_C(0xA5A5A5A5));
        CHECK(!pc_even_parity_insert_u32(0u,NULL));
        CHECK(!pc_parity_strip_check_u32(1u,&p) && p==UINT32_C(0xA5A5A5A5));
        CHECK(!pc_parity_strip_check_u32(0u,NULL));
        CHECK(!pc_secded_parity_u32(0u,NULL));
        CHECK(!pc_bit_error_syndrome_u32(0u,UINT8_C(0x80),&s) && s==UINT8_C(0xA5));
        CHECK(!pc_bit_error_syndrome_u32(0u,0u,NULL));
        CHECK(!pc_mask_between_u32(31u,32u,&w) && w==UINT32_C(0xA5A5A5A5));
        CHECK(!pc_bit_swap_u32(0u,255u,0u,&w) && w==UINT32_C(0xA5A5A5A5));
        CHECK(!pc_bit_swap_u32(0u,0u,0u,NULL));
        CHECK(pc_bit_error_syndrome_u32(0u,0u,&s) && s==0u);
    }

    /* Exhaust all SECDED bit-error locations and all 741 double-error pairs. */
    {
        const uint32_t data = UINT32_C(0xA55A1234);
        const uint8_t checks = (uint8_t)ref_secded_checks(data);
        unsigned a, b;
        for (a=1u;a<=39u;++a) {
            uint32_t d=data; uint8_t c=checks; uint8_t syndrome;
            if ((a & (a-1u))==0u && a<=32u) c^=(uint8_t)(1u << (a==1u?0u:a==2u?1u:a==4u?2u:a==8u?3u:a==16u?4u:5u));
            else if(a==39u)c^=UINT8_C(0x40);
            else { unsigned p,bit=0u; for(p=1u;p<=38u;++p)if((p&(p-1u))!=0u){if(p==a)d^=UINT32_C(1)<<bit; ++bit;} }
            CHECK(pc_bit_error_syndrome_u32(d,c,&syndrome));
            CHECK(syndrome==(uint8_t)((a==39u?0u:a)|UINT8_C(0x40)));
            for (b=a+1u;b<=39u;++b) {
                uint32_t dd=data; uint8_t cc=checks; unsigned p,bit=0u; uint8_t expected;
                for(p=1u;p<=38u;++p){if((p&(p-1u))==0u){unsigned cb=(p==1u?0u:p==2u?1u:p==4u?2u:p==8u?3u:p==16u?4u:5u);if(p==a||p==b)cc^=(uint8_t)(1u<<cb);}else{if(p==a||p==b)dd^=UINT32_C(1)<<bit;++bit;}}
                if(a==39u||b==39u)cc^=UINT8_C(0x40);
                expected=(uint8_t)((a==39u?b:b==39u?a:(a^b)) & 0x3fu);
                CHECK(pc_bit_error_syndrome_u32(dd,cc,&syndrome) && syndrome==expected);
            }
        }
    }

    /* Long fixed-seed state sequence checks the exact xorshift recurrence. */
    {
        uint32_t state=UINT32_C(0x12345678), actual_state=UINT32_C(0x12345678);
        CHECK(pc_xorshift32(0u)==0u);
        CHECK(pc_xorshift32(state)==UINT32_C(0x87985AA5));
        for(i=0u;i<100000u;++i){state=ref_xorshift32(state);actual_state=pc_xorshift32(actual_state);CHECK(actual_state==state);}
    }

    puts("Binavex independent audit differential checks passed.");
    return 0;
}
