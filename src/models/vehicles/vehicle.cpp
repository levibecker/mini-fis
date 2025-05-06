#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    // TODO
    

    coaches.push_back(coach);
    reservations.push_back(std::unordered_map<std::string, std::vector<Reservation>>());

}

void Vehicle::addStop(std::string const& stop)
{
    // TODO
    

    route.push_back(stop);

}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // TODO

    // Überprüfen Sie, ob der Wagen-Index gültig ist.
    // Falls ja, fügen Sie die Reservierung für den Sitzplatz zur Map
    // der Reservierungen für diesen Wagen hinzu (also zu `reservations[coachIndex]`).
    // Dabei sollte auch überprüft werden, ob die Map bereits einen Eintrag für den Sitzplatz hat.

    if (coachIndex < reservations.size()){

        // Eine leere Liste von Reservierungen für den Sitzplatz erstellen,
        // falls noch keine Reservierungen vorhanden sind.

        auto& coach_res = reservations[coachIndex];
        if (!coach_res.contains(seatId)) {
            coach_res[seatId] = std::vector<Reservation>();
        }

        // In diesem Schritt wird die Reservierung hinzugefügt

        auto& seat_res = reservations[coachIndex][seatId];
        insert_reservation(reservation, seat_res, route);

    } else {
        std::cout << "Reservierung fehlgeschlagen" << std::endl;
    }

}

void Vehicle::showAllDisplays() const
{
    // TODO
    // Iterieren Sie über alle Wagen und rufen Sie die Methode `show()` für jedes Display auf.
    
    for (const auto& coach : coaches) {
        coach.showAllDisplays();
    }

}

void Vehicle::showAllReservations() const
{
    // TODO

    // Iterieren Sie über alle Wagen und rufen Sie die Methode `show()` für jedes Display auf.
    for (const auto& coach : coaches) {
        coach.showAllDisplays();
    }

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
