#include "demo_common.h"

#include <iostream>

/// Ausgabe vor Start des Demo-Laufs MA-HH
void print_info_ma_hh()
{
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
    wait_for_input();
}

/// Auf Benutzer-Eingabe warten.
void wait_for_input()
{
    std::cout << "Enter um fortzufahren..." << std::endl;
    std::cin.get();
}
