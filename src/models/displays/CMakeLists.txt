add_library(displays STATIC display.cpp display.h)
target_include_directories(displays PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(display_tests display_tests.cpp)
target_link_libraries(display_tests displays Catch2::Catch2WithMain)
catch_discover_tests(display_tests)
