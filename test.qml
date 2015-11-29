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

