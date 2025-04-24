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

#endif
