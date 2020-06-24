cmake_minimum_required(VERSION 3.18)

# project name
project(EXTERNAL_LIBS)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
    
    if(${subdir}  STREQUAL "googletest")
        if(ENABLE_TESTING)
            ADD_SUBDIRECTORY(${subdir})
        endif()
    else()
     ADD_SUBDIRECTORY(${subdir})
    endif() 
ENDFOREACH()