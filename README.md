# Mini-FIS

In diesem Repo wird Beispielhaft ein einfaches
*Fahrgast-Informations-System* (FIS) entwickelt,
wie es in modernen Zügen zu finden ist.

Die Aufgabe eines solchen Systems ist es, die verschiedenen Anzeigen,
Ansagen und Ansagen zu steuern, die während der Fahrt Informationen über den Zug,
die Strecke und die nächsten Halte geben.
Dabei gibt es eine Vielzahl an Aspekten zu beachten. Bspw. müssen Displays und Lautsprecher
angesteuert werden, die Position des Fahrzeugs muss ermittelt und aufbereitet werden,
es müssen Fahrplaninformationen berücksichtig werden, sowie Daten über die aktuelle
Streckenlage (Verspätungen, Ausfälle).

Ein solches System komplett zu entwickeln, sprengt hier den Rahmen,
jedoch soll hier eine vereinfachte Version vorgestellt werden,
bei der Wagen mit Decken- und Sitzplatz-Displays modelliert und mit Daten
aufgrund eines Fahrplans sowie Positionsdaten versorgt werden.

## Anforderungen

Ziel ist es, ein vereinfachtes Fahrgast-Informations-System mit den
folgenden Eigenschaften zu entwickeln:

- Es sollen Fahrzeuge mit einer beliebigen Anzahl von Wagen modelliert werden.
- In jedem Wagen gibt es Decken-Displays, die allgemeine Informationen
  zur aktuellen/nächsten Station anzeigen.
- In jedem Wagen gibt es Sitzplatz-Displays, die Informationen zu den
  Reservierungen der Sitzplätze anzeigen.
- Die Informationen sollen jeweils bei Ankunft und/oder Abfahrt an einer Station
  aktualisiert werden.

## Fahrzeug-Modell

Ein *Fahrzeug* (`Vehicle`) ist i.W. eine Aneinanderreihung von *Wagen* (`Coach`),
die ihrerseits wiederum einer Reihe von *Displays* bestehen.
Dabei unterscheiden wir zwei Arten, zum Einen *Decken-Displays*
und zum Anderen *Sitzplatz-Displays*.

Technisch gesehen sind die Display-Arten gleich, daher verwenden wir auch
für beide Arten die gleiche Klasse (`Display`).
Auf den Decken-Displays werden während einer Fahrt allgemeine Informations-
Texte wie z.B. "Nächster Halt Mannheim" oder "Ausstieg in Fahrtrichtung links"
angezeigt.
Auf den Sitzplatz-Displays werden Reservierungs- oder Belegungs-Texte
angezeigt, z.B. "Mannheim - Hamburg" oder "belegt bis Hannover".

Zusätzlich zu den Displays speichern wir für ein Fahrzeug noch eine Liste
der Stationen auf der aktuellen Route, die nächste Station,
sowie für jeden Sitz eine Reihe von *Reservierungen* (`Reservation`).,
jeweils bestehend aus zwei Stationen.

## Zielsetzung/Verhalten

Das System soll während der Fahrt die Displays mit den aktuellen Informationen
versorgen.
Dabei gibt es eine Reihe von Regeln, die beachtet werden müssen:

- Decken-Displays:
  - Bei Stand an einer Station wird nur der Stationsname angezeigt.
  - Während der Fahrt wird dem Stationsnamen der Text "Nächster Halt:"
    vorangestellt.
- Sitzplatz-Displays:
  - Es wird als Text jeweils die nächste gültige Reservierung angezeigt.
  - Beispiel 1: Wenn der nächste Halt Mannheim ist und es eine Reservierung
    von Mannheim nach Hamburg gibt, wird "Mannheim - Hamburg" angezeigt.
  - Beispiel 2: Wenn der nächste Halt Mannheim ist und es eine Reservierung
    von Frankfurt nach Hamburg gibt, wird "Frankfurt - Hamburg" angezeigt.
  - Dabei wird aus allen Reservierungen für einen Platz immer diejenige
    gewählt, die in Fahrtrichtung am nächsten zur aktuellen Station liegt.

## Umsetzung

Es wird ein Gerüst aus Klassen und Funktionen vorgegeben,
das das oben beschriebene System modelliert.
Für diese Klassen gibt es bereits Demo-Programme, die den Umgang und
das erwartete Verhalten für eine Beispiel-Route zeigen.

Die Aufgabe besteht darin, die vorgegebenen Klassen und Funktionen
zu implementieren und die Funktionalität zu testen.

## Empfohlene Reihenfolge der Aufgaben

- Reservierungen (in `src/models/reservation`)
- Displays (in `src/models/display`)
- Wagen (in `src/models/coach`)
- Reservierungslogik (in `src/logic`)
- Fahrzeug (in `src/models/vehicle`)

## Weitere Aufgaben (Ideen)

- Erstellen Sie ausführlichere System-Tests.
  Bauen Sie z.B. die Demo-Programme als Tests nach, um die Funktionalität
  automatisiert testen zu können.
- Erweitern Sie das System, so dass Reservierungen und Fahrplandaten
  aus einer externen Quelle (z.B. einer CSV-Datei) geladen werden.
