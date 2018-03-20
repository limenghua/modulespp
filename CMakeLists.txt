cmake_minimum_required(VERSION 3.5)
project(modulespp)

set(CMAKE_CXX_STANDARD 14)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Boost COMPONENTS filesystem system REQUIRED)

include_directories(.)
include_directories(${BOOST_INCLUDEDIR})


set(MODULE_HEADER_FILES
        modulepp/application.h
        modulepp/module.h
        modulepp/loader/static_module_loader.h
        modulepp/plugin/plugin_config.h
        modulepp/loader/plugin_loader.h
        modulepp/loader/details/plugin_loader_impl.h
        modulepp/plugin/plugin_module.h modulepp/modulepp.h)

set(MODULE_SOURCE_FILES
        modulepp/loader/static_module_loader.cpp
        )


add_library(modulespp STATIC ${MODULE_SOURCE_FILES} ${MODULE_HEADER_FILES})
target_link_libraries(modulespp ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

add_subdirectory(tests)
add_subdirectory(examples)