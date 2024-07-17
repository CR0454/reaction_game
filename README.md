# Reaction game

Um alle nötigen Dateien und Bibliotheken vorhanden zu haben, müssen folgende Schritte befolgt werden:
- Die Ordner "label_02" und "training" des KITTI Datensatzes müssen in das Grundverzeichnis gelegt werden
- OpenCV muss vollständig einsatzbereit installiert sein und der Pfad zum install-Ordner in der CMakeLists.txt in Zeile 9 als Argument übergeben werden

| Klasse       | Beschreibung                                                                                               |
|--------------|------------------------------------------------------------------------------------------------------------|
| Menu         | liest Spielernamen, Gamemode, Anzahl der Runden und die Sequenz aus der Konsole ein und gibt diese ggf. zurück |
| Highsore     | Content                                                                                                    |
| GameHandler  | Content Cell                                                                                               |
| GUI          | Content Cell                                                                                               |
| GameMode     | Content Cell                                                                                               |
| clickHandler | Content Cell                                                                                               |
| Timer        | Content Cell                                                                                               |
| labelHandler | Content Cell                                                                                               |
| Label        | Content Cell                                                                                               |


# Reaktionsspiel

Dieses Projekt ist ein einfaches Reaktionsspiel, entwickelt in C++. Um das Spiel erfolgreich auszuführen, müssen einige Vorbereitungen getroffen werden. Folgen Sie den Anweisungen unten, um alle notwendigen Dateien und Bibliotheken zu installieren.

## Voraussetzungen

Bevor Sie beginnen, stellen Sie sicher, dass die folgenden Schritte abgeschlossen sind:

- Die Ordner `label_02` und `training` des KITTI Datensatzes müssen in das Grundverzeichnis des Projekts kopiert werden.
- [OpenCV](https://opencv.org/releases/) muss vollständig installiert sein. Der Pfad zum `install`-Ordner von OpenCV muss in der `CMakeLists.txt` in Zeile 9 als Argument übergeben werden.

## Klassenbeschreibung

Das Spiel besteht aus mehreren Klassen, die verschiedene Aspekte des Spiels verwalten:

- `Menu`: Verantwortlich für die Eingabe der Spielernamen, des Spielmodus, der Anzahl der Runden und der Sequenz über die Konsole. Gibt diese Informationen zurück.
- `Highscore`: Verwaltet die Highscore-Liste des Spiels.
- `GameHandler`: Steuert den Ablauf des Spiels und die Interaktion zwischen den verschiedenen Komponenten.
- `GUI`: Zuständig für die grafische Benutzeroberfläche des Spiels.
- `GameMode`: Definiert die verschiedenen Spielmodi.
- `clickHandler`: Verarbeitet Mausklicks innerhalb des Spiels.
- `Timer`: Misst die Zeit für die Reaktionsgeschwindigkeit.
- `labelHandler`: Verwaltet die Labels, die für das Spiel benötigt werden.
- `Label`: Repräsentiert ein einzelnes Label im Spiel.

## Installation

Folgen Sie diesen Schritten, um das Spiel einzurichten:

1. Klonen Sie das Repository auf Ihren lokalen Computer.
2. Stellen Sie sicher, dass OpenCV korrekt installiert ist und der Pfad in der `CMakeLists.txt` korrekt eingetragen ist.
3. Kopieren Sie die Ordner `label_02` und `training` des KITTI Datensatzes in das Grundverzeichnis des Projekts.
4. Führen Sie CMake aus, um das Build-System zu generieren.
5. Kompilieren Sie das Projekt mit Ihrem bevorzugten C++ Compiler.

## Spiel starten

Nachdem Sie das Projekt erfolgreich kompiliert haben, können Sie das Spiel starten, indem Sie die erzeugte ausführbare Datei ausführen. Folgen Sie den Anweisungen im Menü, um ein neues Spiel zu starten.

Viel Spaß beim Spielen!