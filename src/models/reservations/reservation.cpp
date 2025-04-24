#include "reservation.h"

Reservation::Reservation(std::string const& from, std::string const& to)
    : from(from)
    , to(to)
{
}

bool Reservation::isEmpty() const
{
    return from.empty() && to.empty();
}

std::string Reservation::getDisplayText() const
{
    return from + " - " + to;
}
