cmake_minimum_required(VERSION 3.5)
project(modulespp)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

include_directories(include)
link_directories(lib)
include_directories(${BOOST_INCLUDEDIR})

set(MODULE_HEADER_FILES
  include/modulepp/application.h
  include/modulepp/module.h
  include/modulepp/static_module_loader.h
        include/modulepp/plugin_config.h)

set(MODULE_SOURCE_FILES
  src/application.cpp
  src/static_module_loader.cpp)


add_library(modulespp STATIC ${MODULE_SOURCE_FILES} ${MODULE_HEADER_FILES})

add_subdirectory(tests)
add_subdirectory(examples)