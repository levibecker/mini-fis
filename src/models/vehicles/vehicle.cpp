#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    // TODO

    // Fügen Sie den neuen Wagen (Coach) zur Liste der Wagen hinzu.
    // Erstellen Sie eine leere Liste von Reservierungen für den neuen Wagen
    // und fügen Sie diese zur Liste der Reservierungen hinzu.
}

void Vehicle::addStop(std::string const& stop)
{
    // TODO

    // Fügen Sie die neue Station zur Route hinzu.
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // TODO

    // Überprüfen Sie, ob der Wagen-Index gültig ist.
    // Falls ja, fügen Sie die Reservierung für den Sitzplatz zur Map
    // der Reservierungen für diesen Wagen hinzu (also zu `reservations[coachIndex]`).
    // Dabei sollte auch überprüft werden, ob die Map bereits einen Eintrag für den Sitzplatz hat.
}

void Vehicle::showAllDisplays() const
{
    // TODO

    // Iterieren Sie über alle Wagen und rufen Sie die Methode `show()` für jedes Display auf.
}

void Vehicle::showAllReservations() const
{
    // TODO

    // Iterieren Sie über alle Wagen und deren Reservierungen
    // und geben Sie die Reservierungen für jeden Sitzplatz aus.
    // Dabei verwenden Sie die Methode `getDisplayText()` der Reservierung.
    // Hinweis: Dies ist eine komplexe Schleife, da durch alle Wagen,
    // dann durch deren Sitzplatz-Maps und schließlich durch die Reservierungen
    // iteriert werden muss.
}

void Vehicle::setCurrentStop(size_t pos)
{
    // TODO

    // Setzen Sie die aktuelle Station des Zuges auf die Stelle pos in der Route.
    // Prüfen Sie, ob pos kleiner als die Größe der Route ist.
}

void Vehicle::arriveAtStop()
{
    // TODO

    // Aktualisiere die Displays für die Ankunft an der Station.

    // Bestimme die Position in der Route und aktualisiere next_stop.

    // Aktualisiere die Reservierungs-Informationen auf den Sitzplatz-Displays.
}

void Vehicle::departFromStop()
{
    // TODO

    // Aktualisiere die Displays für die Abfahrt von der Station.
}

void Vehicle::updateSeatDisplays()
{
    // TODO
}
