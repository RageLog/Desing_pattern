# cmake version to be used
cmake_minimum_required(VERSION 3.18)
project(Libraries)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include/${projectName}")

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
    if(NOT ${subdir}  STREQUAL "misc")
        ADD_SUBDIRECTORY(${subdir})
    endif()
ENDFOREACH()
