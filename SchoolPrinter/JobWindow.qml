import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
Rectangle {
    color:"grey"
    TabView{
        id:tabJobs
        width: 700;
        height: 500;

    Tab{
        title:"Printing"
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

    }
    Tab{
        title:"Printed"
        Rectangle {
            property var index:0;

            id: jobListPrinted;

            width: 600;
            height: 600;

            color: "darkgrey";
            border.color:"black"
            radius:6

            Item {

                id: listaDeJobsPrinted;
                anchors.fill: parent;

                    Component {
                        id: jobDelegatePrinted
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
                        model: _myModel.jobsPrinted;
                        delegate:jobDelegatePrinted
                        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                        focus: true;
                    }
                }

        }

    }
    }


    Button{
        id:pauseButton
        anchors.left: tabJobs.right
        anchors.verticalCenter: tabJobs.verticalCenter
        text: "Play"
        style:ButtonStyle {
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 100
                border.width: control.activeFocus ? 2 : 1
                border.color: "#888"
                radius: 6
                gradient: Gradient {
                    GradientStop { position: 0 ; color: control.pressed ? "darkgrey" : "grey" }
                    GradientStop { position: 1 ; color: control.pressed ? "grey" : "darkgrey" }
                }
            }
        }
        width: 100
        onClicked:{
            if(pauseButton.text=="Pause"){
                pauseButton.text="Play";
            } else{
                pauseButton.text="Pause";
            }
        }
    }
FooterJob{
    anchors.bottom: parent.bottom
    width:parent.width;
}

}
