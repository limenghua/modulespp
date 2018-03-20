set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(${BOOST_INCLUDEDIR})

add_library(demo_plugin MODULE demo_plugin.cpp )
target_link_libraries(demo_plugin modulespp)
set_property(TARGET demo_plugin PROPERTY FOLDER "examples")

add_library(demo_plugin2 MODULE ../my_plugin.cpp)
target_link_libraries(demo_plugin2 modulespp)
set_property(TARGET demo_plugin2 PROPERTY FOLDER "examples")


add_executable(demo_plugin_test demo_plugin_test.cpp)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(SYSTEM_LIB dl)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SYSTEM_LIB)
ELSE ()
    MESSAGE(STATUS "not suported platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(demo_plugin_test modulespp ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${SYSTEM_LIB})