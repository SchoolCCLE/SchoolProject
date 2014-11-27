import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {
    property var index:0;

    id: jobList;

    width: 500;
    height: 500;

    color: "blue";


    Item {

        id: listaDeJobs;
        anchors.fill: parent;

        //Layout.fillHeight: true;
        //Layout.fillWidth: true;

//        ListModel {

//            id: modelo;
//            ListElement {
//                    jobId:_myModel.jobs[index].jobId;
//                    type:_myModel.jobs[index].type;
//                    name:_myModel.jobs[index].name;
//                    printingTime:_myModel.jobs[index].printingTime;
//                    state:_myModel.jobs[index].state;
//                    cyan:_myModel.jobs[index].cyan;
//                    magenta:_myModel.jobs[index].magenta;
//                    yellow:_myModel.jobs[index].yellow;
//                    black:_myModel.jobs[index].black;
//                }

//        }

//        Rectangle {

//            width: 180;
//            height: 200;

//            Component {

//                id: contactDelegate;

//                Item {
//                    width: 180;
//                    height: 80;

//                    Column {
//                        Text { text: '<b>Job ID: </b> ' + jobId }
//                        Text { text: '<b>Type: </b> ' + type }
//                        Text { text: '<b>Name: </b>' + name }
//                        Text { text: '<b>Printing time: </b> ' + printingTime }
//                        Text { text: '<b>State: </b> ' + state }
//                        Text { text: '<b>Cyan: </b>' + cyan }
//                        Text { text: '<b>Magenta: </b> ' + magenta }
//                        Text { text: '<b>Yellow: </b> ' + yellow }
//                        Text { text: '<b>Black: </b>' + black }
//                    }
//                }
//            }

            Component {
                id: jobDelegate
                Item {
                    width: 180; height: 40

                    Column {
                    Text { text: '<b>Job ID: </b> ' + _myModel.jobs[index].jobId }
                    Text { text: '<b>Type: </b> ' + _myModel.jobs[index].type }
                    Text { text: '<b>Name: </b>' + _myModel.jobs[index].name }
                    Text { text: '<b>Printing time: </b> ' + _myModel.jobs[index].printingTime }
                    Text { text: '<b>State: </b> ' + _myModel.jobs[index].state }
                    Text { text: '<b>Cyan: </b>' + _myModel.jobs[index].cyan }
                    Text { text: '<b>Magenta: </b> ' + _myModel.jobs[index].magenta }
                    Text { text: '<b>Yellow: </b> ' + _myModel.jobs[index].yellow }
                    Text { text: '<b>Black: </b>' + _myModel.jobs[index].black }
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
