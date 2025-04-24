add_library(vehicles STATIC vehicle.cpp vehicle.h)
target_include_directories(vehicles PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(vehicles coaches displays reservations reservation_logic)

add_executable(vehicle_tests vehicle_tests.cpp)
target_link_libraries(vehicle_tests vehicles Catch2::Catch2WithMain)
catch_discover_tests(vehicle_tests)
