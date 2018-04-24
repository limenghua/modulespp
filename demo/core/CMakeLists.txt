set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(${BOOST_INCLUDEDIR})

add_library(core MODULE core.cpp )
target_link_libraries(core modulespp)
set_property(TARGET core PROPERTY FOLDER "demo")

INSTALL(TARGETS core
       LIBRARY DESTINATION demo/core
)

install(FILES plugin.json 
		DESTINATION demo/core
)

