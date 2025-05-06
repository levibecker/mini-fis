#include "display.h"

#include <iostream>

Display::Display()
    : text("")
{
}

Display::Display(std::string const& initialText)
    : text { initialText }
{
}

void Display::updateText(std::string const& newText)
{
    // Aktualisieren Sie den Text des Displays,
    // indem Sie den übergebenen neuen Text setzen.
    // D.h. überschreiben Sie `text` mit `newText`.

    text = newText;
}

std::string Display::getText() const
{
     // Liefern Sie den Wert von `text` zurück.
     
    return text;
}

void Display::show() const
{
    // TODO

    std::cout << getText() << std::endl;
    // Geben Sie das Ergebnis von `getText()` auf der Konsole aus.

    // Anmerkung: In einer echten Anwendung würde hier wahrscheinlich
    // eine grafische Benutzeroberfläche oder ein physisches Display
    // angesprochen werden, um den Text anzuzeigen.
    // Wir verwenden einfach std::cout, um den Text auf die Konsole auszugeben.
}
