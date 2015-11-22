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

