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
        test_plugin_config_load.cpp test_plugin_loader.cpp)

add_executable(tests ${TEST_SOURCE_FILE})

message(STATUS "operation system is ${CMAKE_SYSTEM}")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(SYSTEM_LIB dl)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SYSTEM_LIB)
ELSE ()
    MESSAGE(STATUS "not suported platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

target_link_libraries(tests ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${CppUTest_LIBRARIES} ${SYSTEM_LIB})

