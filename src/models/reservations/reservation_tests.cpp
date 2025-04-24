#include <catch2/catch_test_macros.hpp>

#include "reservation.h"

TEST_CASE("empty_reservation", "[reservation]")
{
    Reservation r;

    REQUIRE(r.isEmpty());
    REQUIRE(r.from == "");
    REQUIRE(r.to == "");
}

TEST_CASE("valid_reservation", "[reservation]")
{
    Reservation r("A", "B");

    REQUIRE(!r.isEmpty());
    REQUIRE(r.from == "A");
    REQUIRE(r.to == "B");
}

TEST_CASE("get_display_text", "[reservation]")
{
    Reservation r("A", "B");

    REQUIRE(r.getDisplayText() == "A - B");
}
