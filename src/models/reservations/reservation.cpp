#include "reservation.h"

Reservation::Reservation(std::string const& from, std::string const& to)
    : from(from)
    , to(to)
{
}

bool Reservation::isEmpty() const
{
    return to.empty() && from.empty();
}

std::string Reservation::getDisplayText() const
{
    // TODO

    return from + " - " + to;
}
