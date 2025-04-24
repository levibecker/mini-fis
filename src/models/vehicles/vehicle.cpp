#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    // Fügen Sie den neuen Wagen (Coach) zur Liste der Wagen hinzu.
    // Erstellen Sie eine leere Liste von Reservierungen für den neuen Wagen
    // und fügen Sie diese zur Liste der Reservierungen hinzu.
    coaches.push_back(coach);
    reservations.push_back(std::unordered_map<std::string, std::vector<Reservation>>());
}

void Vehicle::addStop(std::string const& stop)
{
    // Fügen Sie die neue Station zur Route hinzu.
    route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // Überprüfen Sie, ob der Wagen-Index gültig ist.
    // Falls ja, fügen Sie die Reservierung für den Sitzplatz zur Map
    // der Reservierungen für diesen Wagen hinzu (also zu `reservations[coachIndex]`).
    // Dabei sollte auch überprüft werden, ob die Map bereits einen Eintrag für den Sitzplatz hat.
    if (coachIndex < reservations.size()) {
        // Eine leere Liste von Reservierungen für den Sitzplatz erstellen,
        // falls noch keine Reservierungen vorhanden sind.
        auto& coach_res = reservations[coachIndex];
        if (!coach_res.contains(seatId)) {
            coach_res[seatId] = std::vector<Reservation>();
        }
        // Reservierung hinzufügen.
        auto& seat_res = reservations[coachIndex][seatId];
        insert_reservation(reservation, seat_res, route);
    } else {
        std::cerr << "Wagen-Index " << coachIndex << " nicht gefunden." << std::endl;
    }
}

void Vehicle::showAllDisplays() const
{
    // Iterieren Sie über alle Wagen und rufen Sie die Methode `show()` für jedes Display auf.
    for (const auto& coach : coaches) {
        coach.showAllDisplays();
    }
}

void Vehicle::showAllReservations() const
{
    // Iterieren Sie über alle Wagen und deren Reservierungen
    // und geben Sie die Reservierungen für jeden Sitzplatz aus.
    // Dabei verwenden Sie die Methode `getDisplayText()` der Reservierung.
    // Hinweis: Dies ist eine komplexe Schleife, da durch alle Wagen,
    // dann durch deren Sitzplatz-Maps und schließlich durch die Reservierungen
    // iteriert werden muss.
    for (size_t i = 0; i < coaches.size(); ++i) {
        for (const auto& [seatId, reservations] : reservations[i]) {
            std::cout << "Wagen " << i << ", ";
            std::cout << "Platz " << seatId << ": ";
            for (const auto& reservation : reservations) {
                std::cout << reservation.getDisplayText() << ", ";
            }
            std::cout << std::endl;
        }
    }
}

void Vehicle::setCurrentStop(size_t pos)
{
    // Setzen Sie die aktuelle Station des Zuges auf die Stelle pos in der Route.
    // Prüfen Sie, ob pos kleiner als die Größe der Route ist.
    if (pos < route.size()) {
        next_stop = route[pos];
    } else {
        next_stop = "";
    }
}

void Vehicle::arriveAtStop()
{
    // Aktualisiere die Displays für die Ankunft an der Station.
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays(next_stop);
    }

    // Bestimme die Position in der Route und aktualisiere next_stop.
    auto it = std::find(route.begin(), route.end(), next_stop);
    auto current_pos = it - route.begin();
    setCurrentStop(current_pos + 1);

    // Aktualisiere die Reservierungs-Informationen auf den Sitzplatz-Displays.
    updateSeatDisplays();
}

void Vehicle::departFromStop()
{
    // Aktualisiere die Displays für die Abfahrt von der Station.
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays("Nächster Halt: " + next_stop);
    }
}

void Vehicle::updateSeatDisplays()
{
    for (size_t i = 0; i < coaches.size(); ++i) {
        auto& coach = coaches[i];
        for (const auto& [seatId, reservations] : reservations[i]) {
            auto reservation = get_next_reservation(reservations, next_stop, route);
            if (!reservation.isEmpty()) {
                coach.updateSeatDisplay(seatId, reservation.getDisplayText());
            }
        }
    }
}
