set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(${BOOST_INCLUDEDIR})

add_library(demo_plugin MODULE demo_plugin.cpp )
target_link_libraries(demo_plugin modulespp)
set_property(TARGET demo_plugin PROPERTY FOLDER "demo")

INSTALL(TARGETS demo_plugin
       LIBRARY DESTINATION demo/plugins/demo_plugin
)

install(FILES plugin.json 
		DESTINATION demo/plugins/demo_plugin
)

