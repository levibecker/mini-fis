add_executable(display_demo display_demo.cpp demo_common.cpp demo_common.h)
target_link_libraries(display_demo displays)

add_executable(coach_demo coach_demo.cpp coach.cpp demo_common.cpp coach.h demo_common.h)
target_link_libraries(coach_demo displays)

add_executable(vehicle_demo vehicle_demo.cpp vehicle.cpp coach.cpp demo_common.cpp vehicle.h coach.h demo_common.h)

target_link_libraries(vehicle_demo reservations displays)
