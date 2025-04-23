// Dies ist ein Programm, das die Verwendung der Klasse `Vehicle` demonstriert.
// Es ist an sich nicht für den Produktivbetrieb eines Fahrgasinformationssystems
// von Interesse, sondern enthält Beispiele für typische Folgen von Kommandos und
// Abfragen, die im Laufe einer Fahrt an ein `Vehicle`-Objekt gerichtet werden könnten.

#include "demo_common.h"
#include "vehicle.h"
#include <iostream>

void run_ma_hh();
void wait_for_input();

int main()
{
    run_ma_hh();

    return 0;
}

/// Beispiel-Ablauf für eine Fahrt von Mannheim nach Hamburg.
void run_ma_hh()
{
    // Erzeuge ein Vehicle-Objekt mit einem Wagen wie in der Coach-Demo.

    Vehicle vehicle;

    Coach c1;
    c1.addCeilingDisplay(Display());
    c1.addSeatDisplay("42", Display());

    vehicle.addCoach(c1);

    // Route hinzufügen
    vehicle.addStop("Mannheim Hbf");
    vehicle.addStop("Frankfurt (Main) Hbf");
    vehicle.addStop("Kassel-Wilhelmshöhe");
    vehicle.addStop("Göttingen");
    vehicle.addStop("Hannover Hbf");
    vehicle.addStop("Hamburg Hbf");
    vehicle.setCurrentStop(0);

    // Reservierungen hinzufügen (alle für Wagen 0, Platz 42)
    vehicle.addReservation(0, "42", Reservation("Mannheim Hbf", "Frankfurt (Main) Hbf"));
    vehicle.addReservation(0, "42", Reservation("Kassel-Wilhelmshöhe", "Hannover Hbf"));
    vehicle.addReservation(0, "42", Reservation("Hannover Hbf", "Hamburg Hbf"));

    print_info_ma_hh();
    vehicle.showAllReservations();

    // Wir fahren die selbe Route wie in den Display- und Coach-Demos.
    // Allerdings verwenden wir hier direkt die Vehicle-Klasse, um die Displays zu steuern.
    // Dabei steuern wir nicht mehr die Displays direkt, sondern verwenden
    // arriveAtStop() und departFromStop(), um die Displays zu aktualisieren.
    // D.h. dies wird erst funktionieren, wenn diese Methoden implementiert sind.
    // Das ist die Kern-Logik des Fahrgastinformationssystems.

    // Vor Start in Mannheim
    vehicle.arriveAtStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Abfahrt in Mannheim:
    vehicle.departFromStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Ankunft in Frankfurt:
    vehicle.arriveAtStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Abfahrt in Frankfurt:
    vehicle.departFromStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Ankunft in Kassel:
    vehicle.arriveAtStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Abfahrt in Kassel:
    vehicle.departFromStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Ankunft in Göttingen:
    vehicle.arriveAtStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Abfahrt in Göttingen:
    vehicle.departFromStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Ankunft in Hannover:
    vehicle.arriveAtStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Abfahrt in Hannover:
    vehicle.departFromStop();
    vehicle.showAllDisplays();
    wait_for_input();

    // Bei Ankunft in Hamburg:
    vehicle.arriveAtStop();
    vehicle.showAllDisplays();
    wait_for_input();
}
