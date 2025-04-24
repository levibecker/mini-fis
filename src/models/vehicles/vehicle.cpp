#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    // TODO
}

void Vehicle::addStop(std::string const& stop)
{
    // TODO
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // TODO
}

void Vehicle::showAllDisplays() const
{
    // TODO
}

void Vehicle::showAllReservations() const
{
    // TODO
}

void Vehicle::setCurrentStop(size_t pos)
{
    // TODO
}

void Vehicle::arriveAtStop()
{
    // TODO
}

void Vehicle::departFromStop()
{
    // TODO
}

void Vehicle::updateSeatDisplays()
{
    // TODO
}
