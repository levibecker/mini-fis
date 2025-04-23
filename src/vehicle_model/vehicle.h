#ifndef VEHICLE_H
#define VEHICLE_H

#include "coach.h"
#include <string>
#include <vector>

/// Ein Fahrzeug (Vehicle) repräsentiert einen Zug während der Fahrt.
/// Diese Klassen enthält zum Einen Informationen über die Wagen-Konfiguration
/// des Zuges und zum Anderen Informationen über den Fahrplan und die aktuelle
/// Position des Zuges.
struct Vehicle {

    /// Die Liste der Wagen (Coaches) im Zug.
    std::vector<Coach> coaches;

    /// Die aktuelle Route.
    std::vector<std::string> route;

    /// Die nächste Station, die der Zug anfahren wird.
    /// An der Endstation soll dies der leere String sein.
    std::string next_stop;

    /// Standard-Konstruktor, erzeugt ein Vehicle-Objekt mit
    /// Default-Wagen-Konfiguration (leer).
    Vehicle();

    /// Fügt einen neuen Wagen (Coach) zum Zug hinzu.
    void addCoach(Coach const& coach);

    /// Fügt eine neue Station zur Route hinzu.
    void addStop(std::string const& stop);

    /// Setzt die aktuelle Station des Zuges auf die Stelle pos in der Route.
    /// Falls die Position nicht existiert, wird next_stop auf den leeren String gesetzt.
    void setCurrentStop(size_t pos);

    /// Zeigt alle Displays in allen Wagen an.
    void showAllDisplays() const;

    /// Ankunft an einer Station.
    /// Akualisiert die Displays und schaltet next_stop weiter.
    void arriveAtStop();

    /// Abfahrt von einer Station.
    /// Aktualisiert die Displays.
    void departFromStop();

    /// Aktualisert die Reservierungs-Informationen auf den Sitzplatz-Displays.
    void updateSeatDisplays();
};

#endif
