add_library(displays STATIC display.cpp display.h)
target_include_directories(displays PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
