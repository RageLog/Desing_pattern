# cmake version to be used
cmake_minimum_required(VERSION 3.18)

# project name
project(tests)

enable_testing()

set(UNIT_TEST_BIN_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/tests/tests_output)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
if(NOT ${subdir} STREQUAL "tests_output")
    ADD_SUBDIRECTORY(${subdir})
endif()
ENDFOREACH()

