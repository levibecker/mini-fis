#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    // TODO     WIEDERHOLUNG!!! AUFGABE NICHT GELÖST
    
    // Fügen Sie mittels push_back() ein neues Display
    // zur Liste der Deckenanzeigen (`ceiling_displays`) hinzu.
    
    ceiling_displays.push_back(display); 
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    // TODO     WIEDERHOLUNG!!! AUFGABE NICHT GELÖST

    // Fügen Sie das Display zur Map der Sitzplatzanzeigen (`seat_displays`) hinzu.
    // Dabei wird die Sitzplatz-ID als Schlüssel verwendet.

    seat_displays[seatId] = display;
}

void Coach::updateCeilingDisplays(std::string const& newText)
{  
    // TODO     WIEDERHOLUNG!!! AUFGABE NICHT GELÖST

    // Iterieren Sie über die Liste der Deckenanzeigen
    // und aktualisieren Sie den Text jedes Displays
    // mit dessen Methode `updateText()`.

    for (auto& display : ceiling_displays) {
        display.updateText(newText);
    }

}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    // TODO     WIEDERHOLUNG!!! AUFGABE NICHT GELÖST

    // Suchen Sie das Display in der Map der Sitzplatzanzeigen (z.B. mit `find()`).
    // Wenn es gefunden wird, aktualisieren Sie den Text des Displays.

    auto it = seat_displays.find(seatId);

    if (it != seat_displays.end()) {
        it->second.updateText(newText);
    } else {
        std::cerr << "Sitzplatz " << seatId << " nicht gefunden." << std::endl;
    }

}

void Coach::showCeilingDisplays() const
{
    // TODO     WIEDERHOLUNG!!! AUFGABE NICHT GELÖST

    // Iterieren Sie über die Liste der Deckenanzeigen
    // und rufen Sie für jedes Display die Methode `show()` auf.

    for (const auto& display : ceiling_displays) {
        display.show();
    }

}

void Coach::showSeatDisplays() const
{
    // TODO WIEDERHOLUNG!!! AUFGABE NICHT GELÖST

    // Iterieren Sie über die Map der Sitzplatzanzeigen
    // und rufen Sie für jedes Display die Methode `show()` auf.
    // Hinweis: Iterieren über Maps ist ähnlich wie über Vektoren,
    // es kann mittels einer Range-based for-Schleife erfolgen.
    // Sie bekommen dann aber ein Paar (Key, Value) zurück.

    for (const auto& [id, display] : seat_displays) {
        std::cout << id << ": ";
        display.show();
    }
}

void Coach::showAllDisplays() const
{
    // TODO
    
    showCeilingDisplays();
    showSeatDisplays();
    
}
