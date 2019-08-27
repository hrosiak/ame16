cmake_minimum_required(VERSION 3.8.2)
project(ame)

option(TESTS "build tests" OFF)
######## build type ############
if(NOT ${CMAKE_BUILD_TYPE}  STREQUAL "Debug")
    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
        #set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wfatal-errors -fno-omit-frame-pointer -fsanitize=address")
        set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wfatal-errors")
    endif()
endif()
MESSAGE(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
######### compiler flags ###########
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
MESSAGE(STATUS "install prefix: " ${CMAKE_INSTALL_PREFIX})


if(TESTS)
enable_testing()
add_subdirectory("tests")
endif()


find_package(PythonInterp)
if(PYTHONINTERP_FOUND)
    message("-- Python found: ${PYTHON_EXECUTABLE}")
endif()

######## for python module
if(NOT PYTHONINTERP_FOUND)
    MESSAGE(SEND_ERROR "Python is required to build nurex python modules")
endif(NOT PYTHONINTERP_FOUND)

find_package(pybind11 REQUIRED)

set(PYBIND11_CPP_STANDARD -std=c++1z)
pybind11_add_module(pyame pyame.cpp ame16.cpp)
