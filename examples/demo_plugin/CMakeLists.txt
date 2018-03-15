set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(${BOOST_INCLUDEDIR})

add_library(demo_plugin MODULE demo_plugin.cpp )
target_link_libraries(demo_plugin modulespp)
set_property(TARGET demo_plugin PROPERTY FOLDER "examples")

add_library(demo_plugin2 MODULE  demo_plugin2.cpp)
target_link_libraries(demo_plugin2 modulespp)
set_property(TARGET demo_plugin2 PROPERTY FOLDER "examples")


add_executable(demo_plugin_test demo_plugin_test.cpp)
target_link_libraries(demo_plugin_test modulespp ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} dl)