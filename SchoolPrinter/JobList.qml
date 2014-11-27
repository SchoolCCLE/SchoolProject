import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    id: jobList;

    width: 500;
    height: 500;

    color: "blue";


    Item {

        id: listaDeJobs;

        anchors.fill: parent;

        //Layout.fillHeight: true;
        //Layout.fillWidth: true;

        ListModel {

            id: modelo;

            Repeater {

                model: _myModel.jobs;
                delegate: ListElement {

                    jobId;
                    type;
                    name;
                    printingTime;
                    state;
                    cyan;
                    magenta;
                    yellow;
                    black;
                }

            }

        }

        Rectangle {

            width: 180;
            height: 200;

            Component {

                id: contactDelegate;

                Item {
                    width: 180;
                    height: 80;

                    Column {
                        Text { text: '<b>Job ID: </b> ' + jobId }
                        Text { text: '<b>Type: </b> ' + type }
                        Text { text: '<b>Name: </b>' + name }
                        Text { text: '<b>Printing time: </b> ' + printingTime }
                        Text { text: '<b>State: </b> ' + state }
                        Text { text: '<b>Cyan: </b>' + cyan }
                        Text { text: '<b>Magenta: </b> ' + magenta }
                        Text { text: '<b>Yellow: </b> ' + yellow }
                        Text { text: '<b>Black: </b>' + black }
                    }
                }
            }

            ListView {
                anchors.fill: parent;
                model: modelo;
                delegate: contactDelegate;
                focus: true;
            }
        }

    }

}
