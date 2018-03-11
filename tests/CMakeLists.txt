find_package(CppUTest REQUIRED)


include_directories(${CppUTest_INCLUDE_DIRS})
link_directories(lib)

set(TEST_SOURCE_FILE
   main.cpp
   test_any_ptr_map.cpp
   test_application.cpp
   test_modules.cpp
   test_topo_sorting.cpp
   test_plugin_config.cpp
   mock_modules.h
        test_plugin_config_load.cpp)

add_executable(tests ${TEST_SOURCE_FILE})

target_link_libraries(tests modulespp ${CppUTest_LIBRARIES})