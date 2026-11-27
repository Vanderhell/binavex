cmake_minimum_required(VERSION 3.20)
project(Binavex VERSION 0.1.0 LANGUAGES C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BINAVEX_BUILD_TESTS "Build Binavex validation tests" OFF)
option(BINAVEX_STRICT_WARNINGS "Enable strict warnings for Binavex targets" ON)

set(BINAVEX_SOURCES
    src/binavex_bit_byte_reverse_u32.c
    src/binavex_bit_deinterleave4_u32.c
    src/binavex_bit_error_syndrome_u32.c
    src/binavex_bit_extract_u64.c
    src/binavex_bit_gather_u32.c
    src/binavex_bit_interleave4_u32.c
    src/binavex_bit_nibble_reverse_u32.c
    src/binavex_bit_pair_reverse_u32.c
    src/binavex_bit_reverse_u64.c
    src/binavex_bit_scatter_u32.c
    src/binavex_bit_shuffle_even_odd_u32.c
    src/binavex_bit_swap_u32.c
    src/binavex_bit_unshuffle_even_odd_u32.c
    src/binavex_bitset_count_ones_u32.c
    src/binavex_bitset_rotate_left_u32.c
    src/binavex_clz_u64.c
    src/binavex_ctz_u64.c
    src/binavex_deinterleave_nibbles_u32.c
    src/binavex_even_parity_insert_u32.c
    src/binavex_gray_decode_u64.c
    src/binavex_gray_encode_u64.c
    src/binavex_interleave_bytes_u32.c
    src/binavex_interleave_nibbles_u32.c
    src/binavex_mask_between_u32.c
    src/binavex_mask_count_runs_u32.c
    src/binavex_mask_is_contiguous_u32.c
    src/binavex_mask_low_u64.c
    src/binavex_mask_lowest_n_u32.c
    src/binavex_parity_strip_check_u32.c
    src/binavex_parity_u64.c
    src/binavex_popcount_u64.c
    src/binavex_rotate_left_u64.c
    src/binavex_secded_parity_u32.c
    src/binavex_swap_bitpairs_u32.c
    src/binavex_swap_bytes16_u32.c
    src/binavex_swap_nibbles_u32.c
    src/binavex_xorshift32.c
)
add_library(binavex STATIC ${BINAVEX_SOURCES})
add_library(Binavex::Binavex ALIAS binavex)
target_compile_features(binavex PUBLIC c_std_99)
target_include_directories(binavex PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
set_target_properties(binavex PROPERTIES EXPORT_NAME Binavex POSITION_INDEPENDENT_CODE OFF)

if(BINAVEX_STRICT_WARNINGS)
    if(MSVC)
        target_compile_options(binavex PRIVATE /W4 /WX)
    else()
        target_compile_options(binavex PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
endif()

if(BINAVEX_BUILD_TESTS)
    enable_testing()
    include(CheckLanguage)
    check_language(CXX)
    file(GLOB BINAVEX_TEST_SOURCES CONFIGURE_DEPENDS tests/*.c)
    foreach(test_source IN LISTS BINAVEX_TEST_SOURCES)
        get_filename_component(test_name "${test_source}" NAME_WE)
        set(test_target "binavex_${test_name}")
        add_executable("${test_target}" "${test_source}")
        target_link_libraries("${test_target}" PRIVATE Binavex::Binavex)
        if(BINAVEX_STRICT_WARNINGS)
            if(MSVC)
                target_compile_options("${test_target}" PRIVATE /W4 /WX /UNDEBUG)
            else()
                target_compile_options("${test_target}" PRIVATE -Wall -Wextra -Wpedantic -Werror -UNDEBUG)
            endif()
        elseif(MSVC)
            target_compile_options("${test_target}" PRIVATE /UNDEBUG)
        else()
            target_compile_options("${test_target}" PRIVATE -UNDEBUG)
        endif()
        add_test(NAME "binavex.${test_name}" COMMAND "${test_target}")
    endforeach()
    if(CMAKE_CXX_COMPILER)
        enable_language(CXX)
        add_executable(binavex_public_headers_cpp tests/public_headers_cpp.cpp)
        target_link_libraries(binavex_public_headers_cpp PRIVATE Binavex::Binavex)
        set_target_properties(binavex_public_headers_cpp PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)
        add_test(NAME binavex.public_headers_cpp COMMAND binavex_public_headers_cpp)
    endif()
endif()

install(TARGETS binavex EXPORT BinavexTargets ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY include/binavex DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT BinavexTargets NAMESPACE Binavex:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Binavex)
configure_package_config_file(cmake/BinavexConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/BinavexConfig.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Binavex)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/BinavexConfigVersion.cmake VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/BinavexConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/BinavexConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Binavex)
