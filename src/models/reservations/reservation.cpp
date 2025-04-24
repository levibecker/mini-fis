#include "reservation.h"

Reservation::Reservation(std::string const& from, std::string const& to)
    : from(from)
    , to(to)
{
}

bool Reservation::isEmpty() const
{
    // Eine Reservierung ist leer, wenn sowohl von- als auch zu-String leer sind.
    return from.empty() && to.empty();
}

std::string Reservation::getDisplayText() const
{
    // Setzen Sie den Text mittels des `+`-Operators zusammen.
    return from + " - " + to;
}
