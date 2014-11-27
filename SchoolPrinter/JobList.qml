import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {
    property var index:0;

    id: jobList;

    width: 600;
    height: 600;

    color: "darkgrey";
    border.color:"black"
    radius:6

    Item {

        id: listaDeJobs;
        anchors.fill: parent;

            Component {
                id: jobDelegate
                Item {
                    width: 480; height: 150

                    Column {
                    Text { text: '<b>Job ID: </b> ' + modelData.jobId }
                    Text { text: '<b>Type: </b> ' +  modelData.type }
                    Text { text: '<b>Name: </b>' +  modelData.name }
                    Text { text: '<b>Printing time: </b> ' +  modelData.printingTime }
                    Text { text: '<b>State: </b> ' +  modelData.state }
                    Text { text: '<b>Cyan: </b>' +  modelData.cyan }
                    Text { text: '<b>Magenta: </b> ' +  modelData.magenta }
                    Text { text: '<b>Yellow: </b> ' +  modelData.yellow }
                    Text { text: '<b>Black: </b>' +  modelData.black }
                                        }
                }
            }

            ListView {
                anchors.fill: parent;
                model: _myModel.jobs;
                delegate:jobDelegate
                highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                focus: true;
            }
        }

}
