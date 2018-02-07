cmake_minimum_required(VERSION 3.5)
project(modulespp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(tests)

aux_source_directory(src DIR_MAIN_SRCS)
set(DIR_MAIN_HEADERS,
        src/modules.h
        src/application.h)

add_library(modulespp SHARED ${DIR_MAIN_SRCS} ${DIR_MAIN_HEADERS})