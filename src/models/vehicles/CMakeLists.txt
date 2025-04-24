add_library(vehicles STATIC vehicle.cpp vehicle.h)
target_include_directories(vehicles PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(vehicles coaches displays reservations)
