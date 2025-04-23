// Dies ist ein Programm, das die Verwendung der Klasse `Display` demonstriert.
// Es ist an sich nicht für den Produktivbetrieb eines Fahrgasinformationssystems
// von interesse, sondern enthält Beispiele für typische Folgen von Kommandos und
// Abfragen, die im Laufe einer Fahrt an ein `Display`-Objekt gerichtet werden könnten.

#include "coach.h"
#include <iostream>

void run_ma_hh();
void wait_for_input();

int main()
{
    run_ma_hh();

    return 0;
}

/// Beispiel-Ablauf für ein Decken-Display auf einer Fahrt von Mannheim nach Hamburg.
void run_ma_hh()
{
    // Erzeuge ein Coach-Objekt mit einem Decken- und einem Sitzplatz-Display.
    Coach coach;
    coach.addCeilingDisplay(Display());
    coach.addSeatDisplay("42", Display());

    // Ausgabe vor Start des Demo-Laufs:
    std::cout
        << "Demo-Lauf für Beispiel-Route: " << std::endl;
    std::cout << "Mannheim Hbf -> "
              << "Frankfurt (Main) Hbf -> "
              << "Kassel-Wilhelmshöhe -> "
              << "Göttingen -> "
              << "Hannover Hbf -> "
              << "Hamburg Hbf"
              << std::endl;
    std::cout << "Reservierungen: "
              << "Mannheim -> Frankfurt, "
              << "Kassel -> Hannover, "
              << "Hannover -> Hamburg"
              << std::endl;

    // Wir fahren die Route ab.
    // An jeder Station zeigen wir auf dem Decken-Display den Namen der Station an,
    // nach Abfahrt dann einen Text mit dem nächsten Halt und der Ausstiegsrichtung.
    // Auf dem Sitzplatz-Display zeigen wir den passenden Reservierungstext an.
    // Nach jeder Anzeige warten wir auf eine Eingabe, bevor die nächste Anzeige erfolgt.

    // Vor Start in Mannheim:
    // Aktualisiere den Anzeigetext auf "Mannheim Hbf".
    coach.updateCeilingDisplays("Mannheim Hbf");
    coach.updateSeatDisplay("42", "Mannheim -> Frankfurt");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Mannheim:
    // Aktualisiere den Anzeigetext auf "Nächster Halt: Frankfurt (Main) Hbf".
    coach.updateCeilingDisplays("Nächster Halt: Frankfurt (Main) Hbf \nAusstieg in Fahrtrichtung links.");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Frankfurt:
    // Aktualisiere den Anzeigetext auf "Frankfurt (Main) Hbf".
    coach.updateCeilingDisplays("Frankfurt (Main) Hbf");
    coach.updateSeatDisplay("42", "Kassel -> Hannover");
    coach.showAllDisplays();
    wait_for_input();

    // Weitere Simulation der Fahrt...

    // Nach Abfahrt in Frankfurt:
    coach.updateCeilingDisplays("Nächster Halt: Kassel-Wilhelmshöhe \nAusstieg in Fahrtrichtung rechts.");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Kassel:
    coach.updateCeilingDisplays("Kassel-Wilhelmshöhe");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Kassel:
    coach.updateCeilingDisplays("Nächster Halt: Göttingen \nAusstieg in Fahrtrichtung links.");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Göttingen:
    coach.updateCeilingDisplays("Göttingen");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Göttingen:
    coach.updateCeilingDisplays("Nächster Halt: Hannover Hbf \nAusstieg in Fahrtrichtung rechts.");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Hannover:
    coach.updateCeilingDisplays("Hannover Hbf");
    coach.updateSeatDisplay("42", "Hannover - Hamburg");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Hannover:
    coach.updateCeilingDisplays("Nächster Halt: Hamburg Hbf \nAusstieg in Fahrtrichtung links.");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Hamburg:
    coach.updateCeilingDisplays("Hamburg Hbf \n Ende der Fahrt, bitte aussteigen.");
    coach.updateSeatDisplay("42", "");
    coach.showAllDisplays();
    wait_for_input();
}

void wait_for_input()
{
    std::cout << "Enter um fortzufahren..." << std::endl;
    std::cin.get();
}
