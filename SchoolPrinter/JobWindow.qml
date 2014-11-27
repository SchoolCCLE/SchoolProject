import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {

    JobList{

    }


    Button{
        id:pauseButton
        text: "Play"
        style:ButtonStyle {
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 25
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
            if(text=="Pause"){
                text="Play";
            } else{
                text=="Pause";
            }
        }
    }
FooterJob{
    anchors.bottom: parent.bottom
    width:parent.width;
}

}
