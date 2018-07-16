cmake_minimum_required(VERSION 3.5)
project(modulespp)

set(CMAKE_CXX_STANDARD 14)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(Boost COMPONENTS filesystem system REQUIRED)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    find_package(Boost REQUIRED)
ELSE ()
    MESSAGE(STATUS "not suported platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

include_directories(.)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


add_subdirectory(tests)
add_subdirectory(examples)
add_subdirectory(demo)