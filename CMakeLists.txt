cmake_minimum_required(VERSION 3.20)
project(binavex VERSION 0.1.0 LANGUAGES C)

option(BINAVEX_BUILD_TESTS "Build migrated tests" ON)
option(BINAVEX_STRICT_WARNINGS "Treat supported compiler warnings as errors" ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(GLOB BINAVEX_SOURCES CONFIGURE_DEPENDS src/*.c)
add_library(binavex STATIC ${BINAVEX_SOURCES})
target_include_directories(binavex PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/binavex/bit)
target_compile_features(binavex PUBLIC c_std_99)

if(BINAVEX_STRICT_WARNINGS)
    if(MSVC)
        target_compile_options(binavex PRIVATE /W4 /WX)
    else()
        target_compile_options(binavex PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
endif()

if(BINAVEX_BUILD_TESTS)
    enable_testing()
    file(GLOB BINAVEX_TESTS CONFIGURE_DEPENDS tests/*.c)
    foreach(test_source IN LISTS BINAVEX_TESTS)
        get_filename_component(test_name "${test_source}" NAME_WE)
        add_executable("binavex_${test_name}" "${test_source}")
        target_include_directories("binavex_${test_name}" PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/binavex/bit)
        target_link_libraries("binavex_${test_name}" PRIVATE binavex)
        if(BINAVEX_STRICT_WARNINGS)
            if(MSVC)
                target_compile_options("binavex_${test_name}" PRIVATE /W4 /WX)
            else()
                target_compile_options("binavex_${test_name}" PRIVATE -Wall -Wextra -Wpedantic -Werror)
            endif()
        endif()
        add_test(NAME "${test_name}" COMMAND "binavex_${test_name}")
    endforeach()
endif()
