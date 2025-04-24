add_library(reservations STATIC reservation.cpp reservation.h)
target_include_directories(reservations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
