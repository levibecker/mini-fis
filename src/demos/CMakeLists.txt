add_library(demo_common demo_common.cpp demo_common.h)
target_include_directories(demo_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(display_demo display_demo.cpp)
target_link_libraries(display_demo displays demo_common)

add_executable(coach_demo coach_demo.cpp)
target_link_libraries(coach_demo coaches demo_common)

add_executable(vehicle_demo vehicle_demo.cpp)
target_link_libraries(vehicle_demo vehicles demo_common)
