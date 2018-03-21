set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include_directories(${BOOST_INCLUDEDIR})

add_executable(demo main.cpp)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(SYSTEM_LIB dl)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SYSTEM_LIB)
ELSE ()
    MESSAGE(STATUS "not suported platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(demo modulespp ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${SYSTEM_LIB})
set_property(TARGET demo PROPERTY FOLDER "demo")

INSTALL(TARGETS demo
       RUNTIME DESTINATION demo
)

add_subdirectory(plugins)