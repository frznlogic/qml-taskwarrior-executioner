/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2015 Oscar Andreasson
 */

import QtQuick 2.0
import net.frozentux.qmlcomponents 1.0

Item {
    id: root

    property string fileName: "jsondata.txt"

    TaskWarrior {
        id: taskwarrior
        jsonFile: fileName
    }

    Timer {
        repeat: true
        interval: 5*1000
        running: true
        triggeredOnStart: true

        onTriggered: {
            console.log("Sync taskwarrior server and export data to fileName")
            taskwarrior.sync()
        }
    }
}

