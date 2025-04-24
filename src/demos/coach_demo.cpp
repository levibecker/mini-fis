// Dies ist ein Programm, das die Verwendung der Klasse `Coach` demonstriert.
// Es ist an sich nicht für den Produktivbetrieb eines Fahrgasinformationssystems
// von Interesse, sondern enthält Beispiele für typische Folgen von Kommandos und
// Abfragen, die im Laufe einer Fahrt an ein `Coach`-Objekt gerichtet werden könnten.

#include "coach.h"
#include "demo_common.h"
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
    // Erzeuge ein Coach-Objekt mit einem Decken- und einem Sitzplatz-Display.
    Coach coach;
    coach.addCeilingDisplay(Display());
    coach.addSeatDisplay("42", Display());

    print_info_ma_hh();

    // Wir fahren die selbe Route ab und führen die selben Aktionen aus,
    // wie in der Display-Demo.
    // Allerdings verwenden wir hier die Coach-Klasse, um die Displays zu steuern.

    // Vor Start in Mannheim:
    // Aktualisiere den Anzeigetext auf "Mannheim Hbf".
    coach.updateCeilingDisplays("Mannheim Hbf");
    coach.updateSeatDisplay("42", "Mannheim -> Frankfurt");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Mannheim:
    // Aktualisiere den Anzeigetext auf "Nächster Halt: Frankfurt (Main) Hbf".
    coach.updateCeilingDisplays("Nächster Halt: Frankfurt (Main) Hbf");
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
    coach.updateCeilingDisplays("Nächster Halt: Kassel-Wilhelmshöhe");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Kassel:
    coach.updateCeilingDisplays("Kassel-Wilhelmshöhe");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Kassel:
    coach.updateCeilingDisplays("Nächster Halt: Göttingen");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Göttingen:
    coach.updateCeilingDisplays("Göttingen");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Göttingen:
    coach.updateCeilingDisplays("Nächster Halt: Hannover Hbf");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Hannover:
    coach.updateCeilingDisplays("Hannover Hbf");
    coach.updateSeatDisplay("42", "Hannover - Hamburg");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Abfahrt in Hannover:
    coach.updateCeilingDisplays("Nächster Halt: Hamburg Hbf");
    coach.showAllDisplays();
    wait_for_input();

    // Nach Ankunft in Hamburg:
    coach.updateCeilingDisplays("Hamburg Hbf \n Ende der Fahrt, bitte aussteigen.");
    coach.updateSeatDisplay("42", "");
    coach.showAllDisplays();
    wait_for_input();
}
