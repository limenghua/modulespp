cmake_minimum_required(VERSION 3.5)
project(modulespp)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

include_directories(include)
include_directories(${BOOST_INCLUDEDIR})

set(MODULE_HEADER_FILES
  include/modulepp/application.h
  include/modulepp/module.h
  )

set(MODULE_SOURCE_FILES
  src/application.cpp
        examples/hello_world.cpp)


add_library(modulespp SHARED ${MODULE_SOURCE_FILES} ${MODULE_HEADER_FILES})

add_subdirectory(tests)
add_subdirectory(examples)