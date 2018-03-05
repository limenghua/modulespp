cmake_minimum_required(VERSION 3.5)
project(modulespp)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.58.0 REQUIRED)

include_directories(include)
include_directories(${BOOST_INCLUDEDIR})

aux_source_directory(src DIR_MAIN_SRCS)

add_library(modulespp SHARED ${DIR_MAIN_SRCS})

add_subdirectory(tests)