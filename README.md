# QML TaskWarrior Executioner

This QML extension provide a way to perform different taskwarrior commands via command line from QML. For the time being it is extremely basic and only
developped for the needs of the QmlMirror project. 

## Requirements

This extension requires:
* taskwarrior 2.4.0 or higher
* Qt 6

## Installation

To install this package with CMake and a private Qt installation:

* download qml-taskwarrior-executioner
* cd qml-taskwarrior-executioner
* cmake -B build -S . -DCMAKE_PREFIX_PATH=<QT_PREFIX>/lib/cmake -DCMAKE_INSTALL_PREFIX=<QT_PREFIX>
* cmake --build build/
* cmake --install build/

The QML plugin and qmldir file are installed into Qt's QML import tree automatically.

If you already configured the build tree, you can also override the install location at install time:

* cmake --install build/ --prefix <QT_PREFIX>

## Usage

See the test.qml for a simple usage. 
