#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    ceiling_displays.push_back(display);
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    seat_displays[seatId] = display;
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    for (auto& display : ceiling_displays) {
        display.updateText(newText);
    }
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    auto it = seat_displays.find(seatId);
    if (it != seat_displays.end()) {
        it->second.updateText(newText);
    } else {
        std::cerr << "Sitzplatz " << seatId << " nicht gefunden." << std::endl;
    }
}

void Coach::showCeilingDisplays() const
{
    for (const auto& display : ceiling_displays) {
        display.show();
    }
}

void Coach::showSeatDisplays() const
{
    for (const auto& [id, display] : seat_displays) {
        std::cout << id << ": ";
        display.show();
    }

    // Anmerkung: Normalerweise würde man hier nur display.show()
    // für jeden Sitz aufrufen, da dies zu einem Anzeigewechsel auf den Displays
    // führen würde. Wir geben hier zusätzlich die ID des Sitzplatzes aus,
    // um die Zuordnung besser überprüfen zu können.
}

void Coach::showAllDisplays() const
{
    showCeilingDisplays();
    showSeatDisplays();
}
