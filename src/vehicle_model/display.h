#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

/// Ein Display repräsentiert ein Anzeigegerät in einem Zug.
/// Diese Klasse enthält zunächst nur den Anzeigetext,
/// sie könnte aber erweitert werden, um auch andere Eigenschaften
/// wie z.B. Auflösung, Helligkeit, etc. zu berücksichtigen.
struct Display {
    /// Der Anzeigetext, der auf dem Display angezeigt wird.
    std::string text;

    /// Standard-Konstruktor, erzeugt ein Display mit Default-Anzeigetext.
    Display();

    /// Konstruktor, der den Anzeigetext initialisiert.
    Display(std::string const& initialText);

    /// Methode, um den Anzeigetext zu aktualisieren.
    void updateText(std::string const& newText);

    /// Getter-Methode, um den aktuellen Text abzufragen.
    std::string getText() const;

    /// Zeigt den aktuellen Anzeigetext an.
    void show() const;
};

#endif
