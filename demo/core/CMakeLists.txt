set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(${BOOST_INCLUDEDIR})

add_library(core MODULE core.cpp )
target_link_libraries(core ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
set_property(TARGET core PROPERTY FOLDER "demo")

INSTALL(TARGETS core
       LIBRARY DESTINATION demo/core
)

install(FILES plugin.json 
		DESTINATION demo/core
)

