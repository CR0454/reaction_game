# Reaction game

Um alle nötigen Dateien und Bibliotheken vorhanden zu haben, müssen folgende Schritte befolgt werden:
- Die Ordner `label_02` und `training` des KITTI Datensatzes müssen in das Grundverzeichnis gelegt werden
- [OpenCV](https://opencv.org/releases/) muss vollständig einsatzbereit installiert sein und der Pfad zum install-Ordner in der CMakeLists.txt in Zeile 9 als Argument übergeben werden

## Klassenbeschreibung

Das Spiel besteht aus mehreren Klassen, die verschiedene Aspekte des Spiels verwalten:

| Klasse       | Beschreibung                                                                          |
|--------------|---------------------------------------------------------------------------------------|
| `Menu`         | liest Spielernamen, Gamemode, Anzahl der Runden und die Sequenz aus der Konsole ein und gibt diese ggf. zurück |
| `Highscore`     | Verantwortlich für die Eingabe der Spielernamen, des Spielmodus, der Anzahl der Runden und der Sequenz über die Konsole. Gibt diese Informationen zurück.                                                                                      |
| `GameHandler`  | Steuert den Ablauf des Spiels und die Interaktion zwischen den verschiedenen Komponenten.                                                                               |
| `GUI`          | Zuständig für die grafische Benutzeroberfläche des Spiels.                                                                       |
| `GameMode`     | Definiert die verschiedenen Spielmodi.                                                                         |
| `clickHandler` | Verarbeitet Mausklicks innerhalb des Spiels.                                                                          |
| `Timer`        | Misst die Zeit für die Reaktionsgeschwindigkeit.                                                                          |
| `labelHandler` | Verwaltet die Labels, die für das Spiel benötigt werden.                                                                                  |
| `Label`        | Repräsentiert ein einzelnes Label im Spiel.                                                                       |

