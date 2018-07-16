add_executable(hello_world hello_world.cpp )
target_link_libraries(hello_world ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
set_property(TARGET hello_world PROPERTY FOLDER "examples")

add_executable(register_service register_service.cpp)
target_link_libraries(register_service ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
set_property(TARGET register_service PROPERTY FOLDER "examples")

add_executable(module_depends module_depends.cpp )
target_link_libraries(module_depends ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
set_property(TARGET module_depends PROPERTY FOLDER "examples")

add_executable(static_module_loader static_module_loader.cpp )
target_link_libraries(static_module_loader ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
set_property(TARGET static_module_loader PROPERTY FOLDER "examples")

add_library(my_plugin MODULE my_plugin.cpp)
target_link_libraries(my_plugin ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
set_property(TARGET my_plugin PROPERTY FOLDER "examples")



