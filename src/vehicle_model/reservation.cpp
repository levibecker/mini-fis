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

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    // Überprüfen, ob die Reservierung gültig ist
    auto from_it = std::find(stops.begin(), stops.end(), reservation.from);
    auto to_it = std::find(stops.begin(), stops.end(), reservation.to);

    if (from_it == stops.end() || to_it == stops.end() || from_it >= to_it) {
        return; // Ungültige Reservierung, nicht hinzufügen
    }

    // Füge die Reservierung in die Liste ein
    reservations.push_back(reservation);

    // Sortiere die Reservierungen basierend auf den Haltestellen
    std::sort(reservations.begin(), reservations.end(), [&stops](Reservation const& a, Reservation const& b) {
        return std::find(stops.begin(), stops.end(), a.from) < std::find(stops.begin(), stops.end(), b.from);
    });
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{
    // Bestimme die Position von next_stop in der Liste der Haltestellen.
    // Dabei überprüfen, ob die nächste Haltestelle gültig ist und ggf. abbrechen.
    auto stop_it = std::find(stops.begin(), stops.end(), next_stop);
    if (stop_it == stops.end()) {
        return Reservation();
    }
    size_t stop_pos = std::distance(stops.begin(), stop_it);

    // Überprüfen, ob Reservierungen vorhanden sind und ggf. abbrechen.
    if (reservations.empty()) {
        return Reservation();
    }

    // Überprüfen, ob die Reservierungen gültig sind.
    for (const auto& reservation : reservations) {
        if (!is_valid_for_route(reservation, stops)) {
            return Reservation();
        }
    }

    // Suche nach der nächsten Reservierung, deren to-Haltestelle die nächste Haltestelle ist
    // oder die von der nächsten Haltestelle aus in der Zukunft liegt. Dazu:
    // - Finde für jede Reservierung die to-Position in der Liste der Haltestellen.
    // - Suche danach die größte dieser Positionen, die kleiner oder gleich der stop_pos ist.
    std::vector<size_t> to_positions;
    for (const auto& reservation : reservations) {
        auto to_it = std::find(stops.begin(), stops.end(), reservation.to);
        to_positions.push_back(std::distance(stops.begin(), to_it));
    }

    // Suche nach der ersten to-Position, die größer oder gleich der stop_pos ist.
    auto res_pos_it = std::find_if(to_positions.begin(), to_positions.end(), [stop_pos](size_t pos) {
        return pos >= stop_pos;
    });
    if (res_pos_it == to_positions.end()) {
        return Reservation();
    }
    size_t res_pos = std::distance(to_positions.begin(), res_pos_it);

    return reservations[res_pos];
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    if (reservation.isEmpty()) {
        return false;
    }

    auto from_it = std::find(stops.begin(), stops.end(), reservation.from);
    auto to_it = std::find(stops.begin(), stops.end(), reservation.to);

    if (from_it == stops.end() || to_it == stops.end() || from_it >= to_it) {
        return false; // Ungültige Reservierung
    }
    return true; // Gültige Reservierung
}
