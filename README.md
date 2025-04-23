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
der Stationen auf der aktuellen Route sowie für jeden Sitz eine Reihe
von Reservierungen, jeweils bestehend aus zwei Stationen.

## Zielsetzung

Es wird ein Gerüst aus Klassen und Funktionen vorgegeben,
das das oben beschriebene System modelliert.
Die Aufgabe besteht darin, die vorgegebenen Klassen und Funktionen
zu implementieren und die Funktionalität zu testen.

Dazu ist eine Reihe an Tests vorgegeben, die das Verhalten des Systems überprüfen.
