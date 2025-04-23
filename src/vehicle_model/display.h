#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

/// Ein Display repräsentiert ein Anzeigegerät in einem Zug.
/// Diese Klasse enthält zunächst nur den Anzeigetext,
/// sie könnte aber erweitert werden, um auch andere Eigenschaften
/// wie z.B. Auflösung, Helligkeit, etc. zu berücksichtigen.
struct Display {
  /// Standard-Konstruktor, erzeugt ein Display mit Default-Anzeigetext.
  Display();
};

#endif
