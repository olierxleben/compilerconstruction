# Braindump

Alle Ideen, Notizen, (Un-)wichtiges für die Hausarbeit

## Titel:

Implementierung eines Source-To-Source-Kompilierers zur Optimierung von CSS-Dateien im Webstack

## Hintergrund / Motivation

Im Rahmen der Hausarbeit für das Fach Compilerbau im Sommersemester 2013 im Master-Studiengang Informatik - Verteilte und Mobile Anwendungen an der Hochschule Osnabrück / University of Applied Sciences soll ein Werkzeug entwickelt werden mit dem sich Stylesheets optimieren lassen. Dazu soll ein Kommandozeilentool entwickelt werden, womit CSS-Optimierungen gesteuert und ausgegeben werden können. 

### Use Cases

#### Allgemein

Im Alltag eines Frontend-Entwicklers, bzw. eines Mitarbeiters an einem Web-Projekt kommt es nciht selten vor, dass die aufgrund von Zeitdruck, unterschiedlichen Entwicklern und durch nachträgliches Bugfixing des User Interfaces zu inkonsistenten Aufstellen von CSS-Regeln kommen kann. Regeln die garnicht mehr im DOM der Seite zu finden sind, sind noch in den CSS-Regeln vorhanden. Regeln werden u. U. überschrieben und es wird nicht auf Optimierung von Selektoren geachtet. Mit dem Ergebnis der Hausarbeit soll ein Tool geschaffen werden, womit im Nachhinein CSS-Dateien optimiert werden können. 

Im Folgenden sollen Use Cases für das Tool aufgestellt werden.

#### Google Page Ranking

Seit 2010 berücksichtigt der Page Ranking Algorithmus von Google auch die Ladezeiten für Websites. Seiten die neben SEO ein gutes Page Ranking erhalten, werden demnach auch durch ihre Ladezeiten bestimmt. Die Optimierung von CSS-Regeln und die damit einhergehende verbesserte Ladezeit im Browser sind ein Use Case für den CSS-Optimierer. Die Ladezeiten spielen zwar im Vergleich mit SEO nur eine kleine Rolle, können aber zu einem besseren Ergebnis beitragen. <!-- TODO: Link von Google zur Statistik --> 

#### Ladezeiten bei mobilen web-Anwendungen 

Ladezeiten von mobilen Websites und Web-Anwendungen, bzw. Seiten die über mobile Internetverbindungen geladen werden, sollten schnell und nur wenig Daten Übertragen um ein konsistentes Benutzererlebnis zu gewährleisten. Statistiken zeigen, dass Benutzer auf Websites eher verbleiben wenn diese schnell geladen werden und der Benutzer schnell Informationen abrufen kann oder mit der Anwendung interagieren kann. CSS-Optimierung spielt dabei 

## Features

* CSS optimieren nach diversen Regeln
* Kommandozeilentool

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
* Minifizieren
* Verschönerung

## Testdaten

* VM/Webserver mit großen Beispiel (zur Zeitmessung)
* im Vergleich werden identische Seite mit und ohne Optimierung getestet
* Zu testende Daten: Ausgabeergebnis (immernoch korrekt?), Ladezeiten, Übertragungsgrößen

### Kommandozeilentool

Das Kommandozeilentool nimmt als Eingabe einen Ordner, führt die definierten CSS-Regeln an und gibt als Ausgabe eine optimierte CSS-Datei aus. 

### Workflow



### Beispiel


## Offene Punkte

* welche Browser sollen unterstützt werden?


## Links

http://www.queness.com/post/402/15-css-tips-and-tricks
http://www.queness.com/post/588/15-ways-to-optimize-css-and-reduce-css-file-size
http://www.w3.org/TR/css3-syntax/#grammar0
