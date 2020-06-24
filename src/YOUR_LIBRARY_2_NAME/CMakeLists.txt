# cmake version to be used
cmake_minimum_required(VERSION 3.18)

# project name
get_filename_component("${CMAKE_CURRENT_SOURCE_DIR}_Name" ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(LIBRARY_Name "${${CMAKE_CURRENT_SOURCE_DIR}_Name}")
string(REPLACE " " "_" LIBRARY_Name ${LIBRARY_Name})
project(${LIBRARY_Name} LANGUAGES CXX) 

set(THIS_SOURCE "${INCLUDE_DIR}/${LIBRARY_Name}")
file(GLOB "src_${CMAKE_CURRENT_SOURCE_DIR}" "${THIS_SOURCE}/*.h*"  "*.cpp")

if(BUILD_STATIC)
    add_library(${LIBRARY_Name} STATIC "${src_${CMAKE_CURRENT_SOURCE_DIR}}")
else()
    add_library(${LIBRARY_Name} SHARED "${src_${CMAKE_CURRENT_SOURCE_DIR}}")
    generate_export_header(${LIBRARY_Name} EXPORT_FILE_NAME ${CMAKE_SOURCE_DIR}/src/misc/${LIBRARY_Name}_export.h)
    target_include_directories(${LIBRARY_Name} PRIVATE ${CMAKE_SOURCE_DIR}/src/misc/)
endif()

SET_TARGET_PROPERTIES(${LIBRARY_Name} PROPERTIES PREFIX " ")
#where is your include file
target_include_directories(${LIBRARY_Name} PUBLIC "${INCLUDE_DIR}/")
#GIVE to ID for each
set(LIB_IDENTIFIER "YOUR_IDENTIFIER")
target_compile_definitions(${LIBRARY_Name} PUBLIC ${LIBRARY_Name}_ID="${LIB_IDENTIFIER}")
#Options and warnings
target_link_libraries(${LIBRARY_Name} PRIVATE project_options project_warnings)

if(ADD_TO_PACKAGE_LIB_HEADER)
    install(TARGETS ${LIBRARY_Name} ARCHIVE DESTINATION lib COMPONENT libraries)
    
    file(GLOB MY_OUTPUT_HEADERS ${CMAKE_SOURCE_DIR}/output/include/${projectName}/${LIBRARY_Name})
    install(DIRECTORY ${MY_OUTPUT_HEADERS} DESTINATION headers COMPONENT headers FILES_MATCHING PATTERN "*.h*")
endif()

#clang format
if(ENABLE_clangformat)
    target_clangformat_setup(${LIBRARY_Name})
endif()

unset(THIS_SOURCE)
unset(LIBRARY_Name)
unset(LIB_IDENTIFIER)
