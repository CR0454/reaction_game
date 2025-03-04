# Reaction game

Um alle nötigen Dateien und Bibliotheken vorhanden zu haben, müssen folgende Schritte befolgt werden:
- Die Ordner `label_02` und `training` des KITTI Datensatzes müssen in das Grundverzeichnis gelegt werden
- [OpenCV](https://opencv.org/releases/) muss vollständig einsatzbereit installiert sein und der Pfad zum install-Ordner in der CMakeLists.txt in Zeile 9 als Argument übergeben werden

## Klassenbeschreibung

Das Spiel besteht aus mehreren Klassen, die verschiedene Aspekte des Spiels verwalten:

| Klasse       | Beschreibung                                                                                                                                              |
|--------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| `Menu`         | Liest Spielernamen, Gamemode, Anzahl der Runden und die Sequenz aus der Konsole ein und gibt diese ggf. zurück                                            |
| `Highscore`     | Speichert die Highscores in einer Datei und gibt diese bei Bedarf aus. |
| `GameHandler`  | Steuert den Ablauf des Spiels und die Interaktion zwischen den verschiedenen Komponenten.                                                                 |
| `GUI`          | Zuständig für die grafische Benutzeroberfläche des Spiels.                                                                                                |
| `GameMode`     | Definiert die verschiedenen Spielmodi.                                                                                                                    |
| `clickHandler` | Verarbeitet Mausklicks innerhalb des Spiels.                                                                                                              |
| `Timer`        | Misst die Zeit für die Reaktionsgeschwindigkeit.                                                                                                          |
| `labelHandler` | Verwaltet die Labels, die für das Spiel benötigt werden.                                                                                                  |
| `Label`        | Repräsentiert ein einzelnes Label im Spiel.                                                                                                               |

# Gamemodes 

- Der Spieler hat 3 Sekunden Zeit, um auf die Box zu klicken, sollte er dies nicht schaffen bekommt er eine 10 Sekunden Strafe.
- Der Score berechnet sich aus den Zeiten, die der Spieler benötigt hat, um auf die Boxen zu klicken (inklusive Strafzeiten) und wird dann durch die gespielten Frames geteilt.

## 1. GameMode
- Der Spieler muss auf eine rote Box klicken, sobald es erscheint. Sollte er dieses label nicht treffen, bekommt er eine 5 Sekunden Strafe.

## 2. GameMode
- Der Spieler muss auf eine rote Box klicken, dies erscheint nach 1-2 Sek nach Laden des neuen Bildes, auf welchem bereits blaue Boxen gezeichnet sind. Sollte er diese Box nicht treffen, bekommt er eine 5 Sekunden Strafe.

# Erweiterung: Highscore

Mit einer setHighscore-Funktion wird ein möglicher neuer Highscore gespeichert. 
Hierzu wird der übergebene Parameter mit dem aktuellen Highscore verglichen. Highscores werden in der Textdatei highscore.txt abgespeichert.

Die getHighscore-Funktion gibt den aktuellen Highscore (aus der Datei) zurück.

## Exception Handling

### Case Datei nicht vorhanden
Eine neue Datei wird erstellt.
### Case Datei enthält keinen double Wert
Der Benutzer wird auf den Fehler hingewiesen und gefragt ob der Inhalt gelöscht werden soll. Wenn der Benutzer 'yes' eingibt, wird der Inhalt der Datei gelöscht und entsprechend der Highscore nach dem Spiel gespeichert. Falls er 'no' eingibt, dann verändert das Programm nichts und solange man den Inhalt nicht löschen kann, wird das Programm nicht ausgeführt.
Bei einer invaliden Eingabe wird der Benutzer erneut gefragt bis eine valide Eingbe getätigt wird.
Dies wird mit Hilfe einer deleteContent-Funktion.

