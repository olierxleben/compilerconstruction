# Braindump

Alle Ideen, Notizen, (Un-)wichtiges für die Hausarbeit

## Titel:

Implementierung eines Source-To-Source-Kompilierers zur Optimierung von CSS-Dateien im Webstack

## Features

* CSS optimieren nach diversen Regeln
* Kommandozeilentool

### Kommandozeilentool

#### Funktionen

* mehrere CSS Dateien zu einer Datei zusammenführen 
* minifizierer
* beautifier

### Optmierungsregeln

in CSS-Dateien:

* sharthand (Beispiel: margin-top: 50px; margin-left:50px; => margin: 50px 0 0 50px;)
* Gruppierung ähnlicher Stile
* Linebreaks-Reduzierung
* Entfernung unnötiger Zeichen (zum Beispiel letztes Semikolon je Selektor)
* Farb-Shorthands (#fffff => #fff, #babab => #bab)
* Entfernen von "px" bei Wert 0 (padding: 0px; => padding: 0;)
* Entfernen von unbenutzten Selektoren (Vgl. mit DOM)
* Kompression
* Strukturierung
* Automatisches Einfügen von Standard-Styles (gibt verschiedene NoWraps und Default-Wrapper)

außerhalb von CSS-Dateien:

* CSS Platzierung (in html)
* Zusammenführung zu einer Datei

## Testdaten

* VM/Webserver mit großen Beispiel (zur Zeitmessung)
* im Vergleich werden identische Seite mit und ohne Optimierung getestet
* Zu testende Daten: Ausgabeergebnis (immernoch korrekt?), Ladezeiten, Übertragungsgrößen


## Offene Punkte

* Welche CSS Version?
* welche Browser sollen unterstützt werden?

## Links

http://www.queness.com/post/402/15-css-tips-and-tricks
http://www.queness.com/post/588/15-ways-to-optimize-css-and-reduce-css-file-size
http://www.w3.org/TR/css3-syntax/#grammar0