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

#include "esp_cpu.h"
#include "esp_private/esp_clk.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define API_COUNT 37u
#define SAMPLE_COUNT 21u
#define CALLS_PER_SAMPLE 1000u
#define REP32 UINT32_C(0xA5C369F0)
#define REP64 UINT64_C(0xD3A57C9E102468BF)

extern int binavex_audit_main(void);
extern unsigned int binavex_audit_first_failed_api_index(void);

static uint32_t input32;
static uint32_t input_mask;
static uint32_t input_word;
static uint32_t input_count;
static uint64_t input64;
static uint8_t input_first;
static uint8_t input_last;
static uint8_t input_width;
static uint8_t input_check;

typedef uint64_t (*bench_fn_t)(void);
static bench_fn_t volatile active_bench;
static volatile uint64_t bench_sink;

static uint64_t bench_byte_reverse(void) { return pc_bit_byte_reverse_u32(input32); }
static uint64_t bench_deinterleave4(void) { return pc_bit_deinterleave4_u32(input32); }
static uint64_t bench_error_syndrome(void)
{
    uint8_t syndrome = 0u;
    return pc_bit_error_syndrome_u32(input32, input_check, &syndrome) ? syndrome : UINT64_MAX;
}
static uint64_t bench_extract(void)
{
    uint64_t field = 0u;
    return pc_bit_extract_u64(input64, input_first, input_last, &field) ? field : UINT64_MAX;
}
static uint64_t bench_gather(void) { return pc_bit_gather_u32(input32, input_mask); }
static uint64_t bench_interleave4(void) { return pc_bit_interleave4_u32(input32); }
static uint64_t bench_nibble_reverse(void) { return pc_bit_nibble_reverse_u32(input32); }
static uint64_t bench_pair_reverse(void) { return pc_bit_pair_reverse_u32(input32); }
static uint64_t bench_reverse64(void) { return pc_bit_reverse_u64(input64); }
static uint64_t bench_scatter(void) { return pc_bit_scatter_u32(input32, input_mask); }
static uint64_t bench_shuffle(void) { return pc_bit_shuffle_even_odd_u32(input32); }
static uint64_t bench_swap(void)
{
    uint32_t result = 0u;
    return pc_bit_swap_u32(input32, input_first, input_last, &result) ? result : UINT64_MAX;
}
static uint64_t bench_unshuffle(void) { return pc_bit_unshuffle_even_odd_u32(input32); }
static uint64_t bench_count32(void) { return pc_bitset_count_ones_u32(input32); }
static uint64_t bench_rotate32(void) { return pc_bitset_rotate_left_u32(input32, input_count); }
static uint64_t bench_clz(void) { return pc_clz_u64(input64); }
static uint64_t bench_ctz(void) { return pc_ctz_u64(input64); }
static uint64_t bench_deinterleave_nibbles(void) { return pc_deinterleave_nibbles_u32(input32); }
static uint64_t bench_even_parity(void)
{
    uint32_t word = 0u;
    return pc_even_parity_insert_u32(input32, &word) ? word : UINT64_MAX;
}
static uint64_t bench_gray_decode(void) { return pc_gray_decode_u64(input64); }
static uint64_t bench_gray_encode(void) { return pc_gray_encode_u64(input64); }
static uint64_t bench_interleave_bytes(void) { return pc_interleave_bytes_u32(input32); }
static uint64_t bench_interleave_nibbles(void) { return pc_interleave_nibbles_u32(input32); }
static uint64_t bench_mask_between(void)
{
    uint32_t mask = 0u;
    return pc_mask_between_u32(input_first, input_last, &mask) ? mask : UINT64_MAX;
}
static uint64_t bench_count_runs(void) { return pc_mask_count_runs_u32(input_mask); }
static uint64_t bench_is_contiguous(void) { return pc_mask_is_contiguous_u32(input_mask); }
static uint64_t bench_mask_low64(void)
{
    uint64_t mask = 0u;
    return pc_mask_low_u64(input_width, &mask) ? mask : UINT64_MAX;
}
static uint64_t bench_mask_low32(void)
{
    uint32_t mask = 0u;
    return pc_mask_lowest_n_u32(input_width, &mask) ? mask : UINT64_MAX;
}
static uint64_t bench_parity_strip(void)
{
    uint32_t payload = 0u;
    return pc_parity_strip_check_u32(input_word, &payload) ? payload : UINT64_MAX;
}
static uint64_t bench_parity64(void) { return pc_parity_u64(input64); }
static uint64_t bench_popcount64(void) { return pc_popcount_u64(input64); }
static uint64_t bench_rotate64(void) { return pc_rotate_left_u64(input64, input_count); }
static uint64_t bench_secded_parity(void)
{
    uint8_t checks = 0u;
    return pc_secded_parity_u32(input32, &checks) ? checks : UINT64_MAX;
}
static uint64_t bench_swap_bitpairs(void) { return pc_swap_bitpairs_u32(input32); }
static uint64_t bench_swap_bytes16(void) { return pc_swap_bytes16_u32(input32); }
static uint64_t bench_swap_nibbles(void) { return pc_swap_nibbles_u32(input32); }
static uint64_t bench_xorshift(void) { return pc_xorshift32(input32); }
static uint64_t bench_noop(void) { return input64 ^ (uint64_t)input32; }

static const char * const api_names[API_COUNT] = {
    "pc_bit_byte_reverse_u32", "pc_bit_deinterleave4_u32", "pc_bit_error_syndrome_u32",
    "pc_bit_extract_u64", "pc_bit_gather_u32", "pc_bit_interleave4_u32",
    "pc_bit_nibble_reverse_u32", "pc_bit_pair_reverse_u32", "pc_bit_reverse_u64",
    "pc_bit_scatter_u32", "pc_bit_shuffle_even_odd_u32", "pc_bit_swap_u32",
    "pc_bit_unshuffle_even_odd_u32", "pc_bitset_count_ones_u32", "pc_bitset_rotate_left_u32",
    "pc_clz_u64", "pc_ctz_u64", "pc_deinterleave_nibbles_u32", "pc_even_parity_insert_u32",
    "pc_gray_decode_u64", "pc_gray_encode_u64", "pc_interleave_bytes_u32",
    "pc_interleave_nibbles_u32", "pc_mask_between_u32", "pc_mask_count_runs_u32",
    "pc_mask_is_contiguous_u32", "pc_mask_low_u64", "pc_mask_lowest_n_u32",
    "pc_parity_strip_check_u32", "pc_parity_u64", "pc_popcount_u64", "pc_rotate_left_u64",
    "pc_secded_parity_u32", "pc_swap_bitpairs_u32", "pc_swap_bytes16_u32",
    "pc_swap_nibbles_u32", "pc_xorshift32"
};

static bench_fn_t const bench_functions[API_COUNT] = {
    bench_byte_reverse, bench_deinterleave4, bench_error_syndrome, bench_extract,
    bench_gather, bench_interleave4, bench_nibble_reverse, bench_pair_reverse,
    bench_reverse64, bench_scatter, bench_shuffle, bench_swap, bench_unshuffle,
    bench_count32, bench_rotate32, bench_clz, bench_ctz, bench_deinterleave_nibbles,
    bench_even_parity, bench_gray_decode, bench_gray_encode, bench_interleave_bytes,
    bench_interleave_nibbles, bench_mask_between, bench_count_runs, bench_is_contiguous,
    bench_mask_low64, bench_mask_low32, bench_parity_strip, bench_parity64,
    bench_popcount64, bench_rotate64, bench_secded_parity, bench_swap_bitpairs,
    bench_swap_bytes16, bench_swap_nibbles, bench_xorshift
};

static void set_benchmark_inputs(unsigned int api_index, bool boundary)
{
    input32 = boundary ? UINT32_MAX : REP32;
    input64 = boundary ? UINT64_MAX : REP64;
    input_mask = boundary ? UINT32_MAX : UINT32_C(0x5555AAAA);
    input_word = 0u;
    input_count = boundary ? 31u : 13u;
    input_first = boundary ? 0u : 5u;
    input_last = boundary ? 31u : 27u;
    input_width = boundary ? 64u : 37u;
    input_check = 0u;
    switch (api_index) {
    case 2u:
        input32 = boundary ? UINT32_MAX : UINT32_C(0xA55A1234);
        (void)pc_secded_parity_u32(input32, &input_check);
        break;
    case 3u:
        input_first = boundary ? 0u : 9u;
        input_last = boundary ? 63u : 47u;
        break;
    case 11u:
        input_first = boundary ? 0u : 3u;
        input_last = boundary ? 31u : 29u;
        break;
    case 14u:
    case 31u:
        input_count = boundary ? 31u : 13u;
        break;
    case 18u:
        input32 = boundary ? UINT32_C(0x7FFFFFFF) : UINT32_C(0x25C369F0);
        break;
    case 23u:
        input_first = boundary ? 0u : 5u;
        input_last = boundary ? 31u : 27u;
        break;
    case 26u:
        input_width = boundary ? 64u : 37u;
        break;
    case 27u:
        input_width = boundary ? 32u : 23u;
        break;
    case 28u:
        if (!boundary) (void)pc_even_parity_insert_u32(UINT32_C(0x25C369F0), &input_word);
        break;
    case 15u:
    case 16u:
        if (boundary) input64 = 0u;
        break;
    default:
        break;
    }
}

static uint32_t run_sample(void)
{
    uint32_t i;
    const uint32_t start = esp_cpu_get_cycle_count();
    for (i = 0u; i < CALLS_PER_SAMPLE; ++i) bench_sink ^= active_bench();
    return (uint32_t)(esp_cpu_get_cycle_count() - start);
}

static void sort_u32(uint32_t values[SAMPLE_COUNT])
{
    unsigned int i;
    for (i = 1u; i < SAMPLE_COUNT; ++i) {
        const uint32_t value = values[i];
        unsigned int j = i;
        while (j > 0u && values[j - 1u] > value) {
            values[j] = values[j - 1u];
            --j;
        }
        values[j] = value;
    }
}

static void measure_one(unsigned int api_index, bool boundary)
{
    uint32_t adjusted[SAMPLE_COUNT];
    uint32_t no_op[SAMPLE_COUNT];
    uint32_t i;
    uint32_t minimum = UINT32_MAX;
    uint32_t maximum = 0u;
    set_benchmark_inputs(api_index, boundary);
    for (i = 0u; i < SAMPLE_COUNT; ++i) {
        uint32_t actual_cycles;
        uint32_t empty_cycles;
        active_bench = bench_functions[api_index];
        actual_cycles = run_sample();
        active_bench = bench_noop;
        empty_cycles = run_sample();
        adjusted[i] = actual_cycles > empty_cycles ? actual_cycles - empty_cycles : 0u;
        no_op[i] = empty_cycles;
        if (adjusted[i] < minimum) minimum = adjusted[i];
        if (adjusted[i] > maximum) maximum = adjusted[i];
    }
    sort_u32(adjusted);
    sort_u32(no_op);
    printf("API_CYCLES|%u|%s|%s|median=%.2f|min=%.2f|max=%.2f|noop_median_batch=%" PRIu32 "\n",
           api_index + 1u, api_names[api_index], boundary ? "boundary" : "representative",
           (double)adjusted[SAMPLE_COUNT / 2u] / (double)CALLS_PER_SAMPLE,
           (double)minimum / (double)CALLS_PER_SAMPLE,
           (double)maximum / (double)CALLS_PER_SAMPLE, no_op[SAMPLE_COUNT / 2u]);
}

void app_main(void)
{
    unsigned int i;
    int audit_result;
    printf("BINAVEX_HW_START|apis=%u|cpu_hz=%" PRIu32 "|compiler=%s|optimization=O3|samples=%u|calls_per_sample=%u\n",
           API_COUNT, (uint32_t)esp_clk_cpu_freq(), __VERSION__, SAMPLE_COUNT, CALLS_PER_SAMPLE);
    audit_result = binavex_audit_main();
    if (audit_result != 0) {
        printf("BINAVEX_ALL37_FAIL|passed=0/37|first_failed_api=%u\n",
               binavex_audit_first_failed_api_index());
        for (;;) vTaskDelay(pdMS_TO_TICKS(1000));
    }
    printf("BINAVEX_ALL37_PASS|passed=37/37|first_failed_api=0\n");
    for (i = 0u; i < API_COUNT; ++i) {
        measure_one(i, false);
        measure_one(i, true);
    }
    printf("BENCH_SINK=%" PRIu64 "|stack_high_water_bytes=%u\n", bench_sink,
           (unsigned int)uxTaskGetStackHighWaterMark(NULL));
    for (;;) vTaskDelay(pdMS_TO_TICKS(1000));
}
