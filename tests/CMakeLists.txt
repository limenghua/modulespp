aux_source_directory(. DIR_TEST_SRCS)

add_executable(tests ${DIR_TEST_SRCS} test_topo_sorting.cpp)

target_link_libraries(tests modulespp CppUTest CppUTestExt)