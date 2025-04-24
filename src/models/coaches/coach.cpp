#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    // TODO

    // Fügen Sie mittels push_back() ein neues Display
    // zur Liste der Deckenanzeigen (`ceiling_displays`) hinzu.
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    // TODO
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    // TODO

    // Iterieren Sie über die Liste der Deckenanzeigen
    // und aktualisieren Sie den Text jedes Displays
    // mit dessen Methode `updateText()`.
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    // TODO

    // Suchen Sie das Display in der Map der Sitzplatzanzeigen (z.B. mit `find()`).
    // Wenn es gefunden wird, aktualisieren Sie den Text des Displays.
}

void Coach::showCeilingDisplays() const
{
    // TODO

    // Iterieren Sie über die Liste der Deckenanzeigen
    // und rufen Sie für jedes Display die Methode `show()` auf.
}

void Coach::showSeatDisplays() const
{
    // TODO

    // Iterieren Sie über die Map der Sitzplatzanzeigen
    // und rufen Sie für jedes Display die Methode `show()` auf.
    // Hinweis: Iterieren über Maps ist ähnlich wie über Vektoren,
    // es kann mittels einer Range-based for-Schleife erfolgen.
    // Sie bekommen dann aber ein Paar (Key, Value) zurück.
}

void Coach::showAllDisplays() const
{
    // TODO
}
