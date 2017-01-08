cmake_minimum_required(VERSION 3.0)

project(Project)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -O3")
endif()

find_package(wxWidgets COMPONENTS aui html adv core xml base net gl propgrid REQUIRED)

include("${wxWidgets_USE_FILE}")

find_package(OpenGL REQUIRED)

find_library(SDL REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${SRC_DIR})

add_subdirectory(${SRC_DIR})
