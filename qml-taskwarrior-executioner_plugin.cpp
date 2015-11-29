/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2015 Oscar Andreasson
 */

#include "qml-taskwarrior-executioner_plugin.h"
#include "taskwarrior.h"

#include <qqml.h>

void Qml_Taskwarrior_ExecutionerPlugin::registerTypes(const char *uri)
{
    // @uri net.frozentux.qmlcomponents
    qmlRegisterType<TaskWarrior>(uri, 1, 0, "TaskWarrior");
}


