

#include "reservation_logic.h"

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    // TODO

    // Überprüfen, ob die Reservierung gültig ist

    // Füge die Reservierung in die Liste ein

    // Sortiere die Reservierungen basierend auf den Haltestellen
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{
    // TODO

    // Bestimme die Position von next_stop in der Liste der Haltestellen.
    // Dabei überprüfen, ob die nächste Haltestelle gültig ist und ggf. abbrechen.

    // Überprüfen, ob Reservierungen vorhanden sind und ggf. abbrechen.

    // Überprüfen, ob die Reservierungen gültig sind.

    // Suche nach der nächsten Reservierung, deren to-Haltestelle die nächste Haltestelle ist
    // oder die von der nächsten Haltestelle aus in der Zukunft liegt. Dazu:
    // - Finde für jede Reservierung die to-Position in der Liste der Haltestellen.
    // - Suche danach die größte dieser Positionen, die kleiner oder gleich der stop_pos ist.

    // Suche nach der ersten to-Position, die größer oder gleich der stop_pos ist.

    return Reservation();
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    // TODO

    // Überprüfen, ob die Reservierung leer ist

    // Bestimmen der Positionen der from- und to-Haltestellen in der Liste der Haltestellen.

    // Überprüfen, ob die Haltestellen gültig sind und die from-Haltestelle vor der to-Haltestelle liegt.

    return true;
}
