#include "vehicle.h"

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    coaches.push_back(coach);
}

void Vehicle::addStop(std::string const& stop)
{
    route.push_back(stop);
}

void Vehicle::showAllDisplays() const
{
    for (const auto& coach : coaches) {
        coach.showAllDisplays();
    }
}

void Vehicle::setCurrentStop(size_t pos)
{
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
    // TODO: Aktualisierung aufgrund gegebener Reservierungsdaten implementieren.
}
