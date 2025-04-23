// Dies ist ein Programm, das die Verwendung der Klasse `Display` demonstriert.
// Es ist an sich nicht für den Produktivbetrieb eines Fahrgasinformationssystems
// von Interesse, sondern enthält Beispiele für typische Folgen von Kommandos und
// Abfragen, die im Laufe einer Fahrt an ein `Display`-Objekt gerichtet werden könnten.

#include "demo_common.h"
#include "display.h"
#include <iostream>

void run_ma_hh();

int main()
{
    run_ma_hh();

    return 0;
}

/// Beispiel-Ablauf für eine Fahrt von Mannheim nach Hamburg.
void run_ma_hh()
{
    // Erzeuge ein Decken-Display-Objekt mit einem Standardtext.
    Display ceiling;

    // Erzeuge ein Sitzplatz-Display-Objekt mit einem Standardtext.
    Display seat;

    print_info_ma_hh();

    // Wir fahren die Route ab.
    // An jeder Station zeigen wir auf dem Decken-Display den Namen der Station an,
    // nach Abfahrt dann einen Text mit dem nächsten Halt.
    // Auf dem Sitzplatz-Display zeigen wir den passenden Reservierungstext an.
    // Nach jeder Anzeige warten wir auf eine Eingabe, bevor die nächste Anzeige erfolgt.

    // Vor Start in Mannheim:
    // Aktualisiere den Anzeigetext auf "Mannheim Hbf".
    ceiling.updateText("Mannheim Hbf");
    ceiling.show();
    seat.updateText("Mannheim -> Frankfurt");
    seat.show();
    wait_for_input();

    // Nach Abfahrt in Mannheim:
    // Aktualisiere den Anzeigetext auf "Nächster Halt: Frankfurt (Main) Hbf".
    ceiling.updateText("Nächster Halt: Frankfurt (Main) Hbf");
    ceiling.show();
    seat.show();
    wait_for_input();

    // Nach Ankunft in Frankfurt:
    // Aktualisiere den Anzeigetext auf "Frankfurt (Main) Hbf".
    ceiling.updateText("Frankfurt (Main) Hbf");
    ceiling.show();
    seat.updateText("Kassel -> Hannover");
    seat.show();
    wait_for_input();

    // Weitere Simulation der Fahrt...

    // Nach Abfahrt in Frankfurt:
    ceiling.updateText("Nächster Halt: Kassel-Wilhelmshöhe");
    ceiling.show();
    seat.show();
    wait_for_input();

    // Nach Ankunft in Kassel:
    ceiling.updateText("Kassel-Wilhelmshöhe");
    ceiling.show();
    seat.show();
    wait_for_input();

    // Nach Abfahrt in Kassel:
    ceiling.updateText("Nächster Halt: Göttingen");
    ceiling.show();
    seat.show();
    wait_for_input();

    // Nach Ankunft in Göttingen:
    ceiling.updateText("Göttingen");
    ceiling.show();
    seat.show();
    wait_for_input();

    // Nach Abfahrt in Göttingen:
    ceiling.updateText("Nächster Halt: Hannover Hbf");
    ceiling.show();
    seat.show();
    wait_for_input();

    // Nach Ankunft in Hannover:
    ceiling.updateText("Hannover Hbf");
    ceiling.show();
    seat.updateText("Hannover - Hamburg");
    seat.show();
    wait_for_input();

    // Nach Abfahrt in Hannover:
    ceiling.updateText("Nächster Halt: Hamburg Hbf");
    ceiling.show();
    wait_for_input();

    // Nach Ankunft in Hamburg:
    ceiling.updateText("Hamburg Hbf \n Ende der Fahrt, bitte aussteigen.");
    ceiling.show();
    seat.updateText("");
    seat.show();
    wait_for_input();
}
