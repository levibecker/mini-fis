add_executable(display_demo display_demo.cpp demo_common.cpp display.cpp display.h demo_common.h)
add_executable(coach_demo coach_demo.cpp coach.cpp display.cpp demo_common.cpp coach.h display.h demo_common.h)
add_executable(vehicle_demo vehicle_demo.cpp vehicle.cpp coach.cpp display.cpp demo_common.cpp vehicle.h coach.h display.h demo_common.h)
