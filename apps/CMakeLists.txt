# cmake version to be used
cmake_minimum_required(VERSION 3.18)
project(Applications)

#exe file generating
set(APP_NAME ${projectName})
add_executable(${APP_NAME} main.cpp)

#include dir
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/)
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/${projectName})

#Pass the version from cmake file to source code
if(PASS_VERSION)
    add_compile_definitions(PROJECT_VERSION_DEFINITIONED)
    configure_file(${CMAKE_SOURCE_DIR}/src/ver.h.in ${CMAKE_BINARY_DIR}/ver.h)
    target_include_directories(${APP_NAME} PUBLIC ${CMAKE_BINARY_DIR})
endif(PASS_VERSION)


#Linking
SUBDIRLIST(SUBDIRS "${CMAKE_SOURCE_DIR}/include/${projectName}")
FOREACH(subdir ${SUBDIRS})
   string(REPLACE " " "_" subdir ${subdir})
   if(EXISTS  "${CMAKE_SOURCE_DIR}/src/${subdir}")
        target_link_libraries(${APP_NAME} PUBLIC ${subdir})
        target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/${subdir})
   endif()
ENDFOREACH()
SUBDIRLIST(SUBDIRS "${CMAKE_SOURCE_DIR}/src/")
FOREACH(subdir ${SUBDIRS})
   string(REPLACE " " "_" subdir ${subdir})
   if(NOT EXISTS  "${CMAKE_SOURCE_DIR}/include/${projectName}/${subdir}" AND  (NOT ${subdir}  STREQUAL "misc"))
        target_link_libraries(${APP_NAME} PUBLIC ${subdir})
        target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/${subdir})
   endif()
ENDFOREACH()
   
target_link_libraries(${APP_NAME} PRIVATE project_options project_warnings)

#Installing for packaging
install(TARGETS ${APP_NAME} RUNTIME DESTINATION bin COMPONENT applications)

if(NOT BUILD_STATIC)
    target_include_directories(${APP_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/misc/)
    file(GLOB MY_DLL_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/*.dll)
    install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} DESTINATION . COMPONENT DLLS FILES_MATCHING PATTERN "*.dll")
endif()


#clang-format usage

if(ENABLE_clangformat)
    target_clangformat_setup(${APP_NAME})
endif()

