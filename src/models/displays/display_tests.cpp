#include <catch2/catch_test_macros.hpp>

#include "display.h"

TEST_CASE("default_display", "[display]")
{
    Display d;

    REQUIRE(d.getText() == "");
}

TEST_CASE("custom_display", "[display]")
{
    Display d("Initial Text");

    REQUIRE(d.getText() == "Initial Text");
}

TEST_CASE("update_display", "[display]")
{
    Display d("Initial Text");
    d.updateText("Updated Text");

    REQUIRE(d.getText() == "Updated Text");
}
