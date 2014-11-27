import QtQuick 2.0

Rectangle {
    id: headerRoot;
    width: 500;
    height: 100;
    color: "#A21315";

    Text {
        id: textHeader;
        x: 30;
        anchors.verticalCenter: headerRoot.verticalCenter;
        text: "JOB MANAGER";
        color: "white";
        font.pixelSize: 30;
    }

    Rectangle {
        id: bottomBorder;
        anchors.bottom: headerRoot.bottom;
        anchors.left: headerRoot.left;
        anchors.right: headerRoot.right;
        height: 5;
        color: "red";
    }

    Loader {
        id: loader;
        anchors.top: headerRoot.top;
        anchors.right: headerRoot.right;
        anchors.bottom: bottomBorder.top;

        sourceComponent: buttonDeleteAllComp;
    }

    Component{
        id: buttonDeleteAllComp;

        Rectangle {
            id: buttonDeleteAll;
            color:"blue";
//            anchors.top: headerRoot.top;
//            anchors.right: headerRoot.right;
//            anchors.bottom: bottomBorder.top;
            width: 150;

            Text {
                text: "DELETE ALL";
                anchors.centerIn: parent;
                color: "white";
                font.pixelSize: 20;
            }

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                  console.log("deletinggggg");
                }
            }
        }
    }//fin comp 1

    Component{
        id: buttonPlayPauseComp;

        Rectangle {
            id: buttonPlayPause;
            color:"blue";
//            anchors.top: headerRoot.top;
//            anchors.right: headerRoot.right;
//            anchors.bottom: bottomBorder.top;
            width: 150;

            Text {
                text: "PLAY/PAUSE";
                anchors.centerIn: parent;
                color: "white";
                font.pixelSize: 20;
            }

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                  console.log("play/pauseeeee");

                }
            }
        }
    }//fin comp 2
}
