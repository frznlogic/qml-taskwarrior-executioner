/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2015 Oscar Andreasson
 */

#ifndef QML_TASKWARRIOR_EXECUTIONER_PLUGIN_H
#define QML_TASKWARRIOR_EXECUTIONER_PLUGIN_H

#include <QQmlExtensionPlugin>

class Qml_Taskwarrior_ExecutionerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QML_TASKWARRIOR_EXECUTIONER_PLUGIN_H

