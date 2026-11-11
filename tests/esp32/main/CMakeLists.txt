get_filename_component(BINAVEX_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)
file(GLOB BINAVEX_PRODUCTION_SOURCES "${BINAVEX_ROOT}/src/*.c")

idf_component_register(
    SRCS "main.c" "audit_suite.c" ${BINAVEX_PRODUCTION_SOURCES}
    INCLUDE_DIRS "${BINAVEX_ROOT}/include" "${BINAVEX_ROOT}/include/binavex/bit"
    REQUIRES esp_hw_support)

target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu99)
