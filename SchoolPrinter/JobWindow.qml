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
        JobList{
            id:jobList
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    Tab{
        title:"Printed"
        JobList{
            id:jobListDone
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
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
