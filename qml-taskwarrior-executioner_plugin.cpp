#include "qml-taskwarrior-executioner_plugin.h"
#include "taskwarrior.h"

#include <qqml.h>

void Qml_Taskwarrior_ExecutionerPlugin::registerTypes(const char *uri)
{
    // @uri net.frozentux.qmlcomponents
    qmlRegisterType<TaskWarrior>(uri, 1, 0, "TaskWarrior");
}


