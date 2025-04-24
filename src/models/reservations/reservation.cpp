#include "reservation.h"

Reservation::Reservation(std::string const& from, std::string const& to)
    : from(from)
    , to(to)
{
}

bool Reservation::isEmpty() const
{
    // TODO

    // Eine Reservierung ist leer, wenn sowohl von- als auch zu-String leer sind.
    return false;
}

std::string Reservation::getDisplayText() const
{
    // TODO

    // Setzen Sie den Text mittels des `+`-Operators zusammen.
    return "";
}
