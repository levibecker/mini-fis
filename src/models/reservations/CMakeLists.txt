add_library(reservations STATIC reservation.cpp reservation.h)
target_include_directories(reservations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(reservation_tests reservation_tests.cpp)
target_link_libraries(reservation_tests reservations Catch2::Catch2WithMain)
catch_discover_tests(reservation_tests)
