# cmake version to be used
cmake_minimum_required(VERSION 3.18)

#options
option(USE_VCPKG "Use VCPKG" OFF)
option(PASS_VERSION "Pass the version from cmake file to source code" ON)
option(USE_CUSTOM_DIR "Use custom dir" ON)
option(BUILD_STATIC "Build static or dinamic library" ON)
option(CREATE_RUNTIME_FILE "Create executable filese" ON)
option(ADD_TO_PACKAGE_LIB_HEADER "Create lib and Header folders in package" ON)
option(USE_NSIS "Use NSIS generator to produce installer" ON)
option(USE_ICON "use icon" ON)
option(ENABLE_TESTING "Enable testing" OFF)
option(ENABLE_clangformat "Activate ClangFormat.cmake module" ON)

#Modules (include .cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(util)
include(VersionFromGit)
if(ENABLE_clangformat)
    include(ClangFormat)
endif()
if(NOT BUILD_STATIC)
        include(GenerateExportHeader)
endif()



# project name
get_filename_component(projectName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" projectName ${projectName})
version_from_git()
project(${projectName} VERSION ${VERSION} LANGUAGES CXX) 

#Company name
set(COMPANY_NAME "YOUR_COMPANY_NAME")


# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#if you,how can you use clang-tidy open thia comment
#set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=*;)

#Thank you for this Jason Turner :)
add_library(project_options INTERFACE)
add_library(project_warnings INTERFACE)


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -std=c++20")
    target_compile_features(project_options INTERFACE cxx_std_20)
endif()

if(MSVC)
  target_compile_options(project_warnings INTERFACE /W4 /WX "/permissive-")
else()
  target_compile_options(project_warnings
                         INTERFACE -Wall
                                   -Werror # treat all warnings as errors
                                   -Wextra # reasonable and standard
                                   -Wshadow # warn the user if a variable
                                            # declaration shadows one from a
                                            # parent context
                                   -Wnon-virtual-dtor # warn the user if a class
                                                      # with virtual functions
                                                      # has a non-virtual
                                                      # destructor. This helps
                                                      # catch hard to track down
                                                      # memory errors
                                   -Wold-style-cast # warn for c-style casts
                                   -Wcast-align # warn for potential performance
                                                # problem casts
                                   -Wunused # warn on anything being unused
                                   -Woverloaded-virtual # warn if you overload
                                                        # (not override) a
                                                        # virtual function
                                   -Wpedantic # warn if non-standard C++ is used
                                   -Wconversion # warn on type conversions that
                                                # may lose data
                                   -Wsign-conversion # warn on sign conversions
                                   -Wnull-dereference # warn if a null
                                                      # dereference is detected
                                   -Wdouble-promotion # warn if float is
                                                      # implicit promoted to
                                                      # double
                                   -Wformat=2 # warn on security issues around
                                              # functions that format output (ie
                                              # printf)
                         )

  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(project_warnings
                           INTERFACE -Wmisleading-indentation # warn if
                                                              # identation
                                                              # implies blocks
                                                              # where blocks do
                                                              # not exist
                                     -Wduplicated-cond # warn if if / else chain
                                                       # has duplicated
                                                       # conditions
                                     -Wduplicated-branches # warn if if / else
                                                           # branches have
                                                           # duplicated code
                                     -Wlogical-op # warn about logical
                                                  # operations being used where
                                                  # bitwise were probably wanted
                                     -Wuseless-cast # warn if you perform a cast
                                                    # to the same type
                                                    )
    target_link_libraries(project_options INTERFACE stdc++fs)
  endif()
endif()

#If you use vcpkg,USE_VCPKG must be ON
if(USE_VCPKG)
    set(vcpkgRoot "SET THIS")
    if(NOT EXISTS ${vcpkgRoot})
        message(FATAL_ERROR "Please set vcpkg root for exemple: C:/vcpkg or C:/vcpkg-master")
    else()
        set(CMAKE_TOOLCHAIN_FILE "${vcpkgRoot}/scripts/buildsystems/vcpkg.cmake")
    endif()

endif()

#If you want use output folder, USE_CUSTOM_DIR must be on
if(USE_CUSTOM_DIR)
    if(EXISTS ${CMAKE_SOURCE_DIR}/output/)
        file(GLOB_RECURSE OUTPUT_FILES  ${CMAKE_SOURCE_DIR}/output/*)
        file (REMOVE_RECURSE ${OUTPUT_FILES})
    endif()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/${projectName}/bin)
    file(GLOB MY_PUBLIC_HEADERS  "${CMAKE_SOURCE_DIR}/include/*")
    file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${CMAKE_SOURCE_DIR}/output/include)
endif()

# Find packages go here.


#
# files
add_subdirectory(src)
if(CREATE_RUNTIME_FILE)
    add_subdirectory(apps)
endif()


# external libs
add_subdirectory(external_libs)


#testing
#CTest
if(ENABLE_TESTING)
    if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        include(CTest)
        #message(AUTHOR_WARNING "In ctest if ${CMAKE_PROJECT_NAME} ve ${PROJECT_NAME}")
    endif()
    add_subdirectory(tests)
endif()

#vcpkg linking

#packaging
set(CPACK_PACKAGE_NAME ${projectName})
set(CPACK_PACKAGE_VENDOR ${COMPANY_NAME})
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_PACKAGE_FILE_NAME "${projectName} installer")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${projectName} - CPack Component Installation Example")
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${projectName})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENCE.md")
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_SOURCE_DIR}/packages)


set(CPACK_COMPONENTS_ALL applications DLLS libraries headers)
if(ADD_TO_PACKAGE_LIB_HEADER)
    #CPACK_COMPONENT_<YOUR_COMPONENT_NAME>_DISPLAY_NAME
    set(CPACK_COMPONENT_LIBRARIES_GROUP "Development")
    set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
    set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION  "Static libraries used to build programs with ${projectName}")

    set(CPACK_COMPONENT_HEADERS_GROUP "Development")
    set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")
    set(CPACK_COMPONENT_HEADERS_DESCRIPTION  "C/C++ header files for use with ${projectName}")
    set(CPACK_COMPONENT_HEADERS_DEPENDS libraries) #set component dependcies
endif()
set(CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")
set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "Application")
set(CPACK_COMPONENT_APPLICATIONS_DESCRIPTION  "An extremely useful application that makes use of ${projectName}")
set(CPACK_COMPONENT_DLLS_GROUP "Runtime")



set(CPACK_NSIS_INSTALL_ROOT "C:")

if(USE_NSIS)
    set(CPACK_GENERATOR "NSIS")
else(USE_NSIS)
    set(CPACK_GENERATOR "ZIP")
endif(USE_NSIS)
set(CPACK_SOURCE_GENERATOR "TGZ")


#
if(USE_ICON)
    set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/resources\\\\${projectName}.ico")
    set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/resources/${projectName}.ico")
    set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/resources/${projectName}.ico")
endif()

# This must always be last!
include(CPack)