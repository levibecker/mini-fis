#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <vector>

struct Reservation {
    std::string from;
    std::string to;

    /// Standard-Konstruktor, erzeugt eine leere Reservierung.
    Reservation() = default;

    /// Konstruktor, der die Reservierung initialisiert.
    /// Erwartet einen Abfarts- und einen Zielort.
    Reservation(std::string const& from, std::string const& to);

    /// Liefert true, falls die Reservierung leer ist.
    /// D.h. die Abfahrt- und Zielorte sind leer.
    bool isEmpty() const;

    /// Liefert den Anzeigetext für die Reservierung zurück.
    /// Der Text hat das Format "<from> - <to>".
    std::string getDisplayText() const;
};

/// Fügt eine Reservierung in eine Liste bestehender Reservierungen ein.
/// Erwartet die Reservierung und die Liste der bisherigen Reservierungen
/// sowie eine Liste von Haltestellen.
/// Die Liste der Reservierungen wird so sortiert, dass die Reihenfolge der Start-Orte
/// und Ziel-Orte der Reihenfolge der Haltestellen entspricht.
/// Sollte dies nicht möglich sein, wird die Reservierung nicht hinzugefügt
/// und die liste der Reservierungen bleibt unverändert.
void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops);

/// Liefert aus der Liste der Reservierungen diejenige, die für die angegebene Haltestelle und Route gültig ist.
/// D.h. sucht in der Liste nach der ersten Reservierung, deren to-Haltestelle die nächste Station ist
/// oder die von der nächsten Station aus in der Zukunft liegt.
/// Falls keine solche Reservierung gefunden wird oder irgendeine der Reservierungen oder Haltestellen
/// ungültig ist, wird eine leere Reservierung zurückgegeben.
Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops);

/// Liefert true, falls die Reservierung für die angegebene Route gültig ist.
/// D.h. die Abfahrt- und Zielorte sind in der Liste der Haltestellen enthalten
/// und die Abfahrt-Station kommt vor der Ziel-Station in der Liste vor.
/// Die Reservierung darf außerdem nicht leer sein.
bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops);

#endif
