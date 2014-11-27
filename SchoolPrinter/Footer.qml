import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: footerRoot;
    width: 500;
    height: 100;

    MyFileDialog{
        id:fileDialog

    }

    Rectangle {
        id: topBorder;
        anchors.top: footerRoot.top;
        anchors.left: footerRoot.left;
        anchors.right: footerRoot.right;
        height: 5;
        color: "green";
    }

    Rectangle {
        id: buttonPrint;
        color:"blue";
        anchors.top: topBorder.bottom;
        anchors.right: footerRoot.right;
        anchors.bottom: footerRoot.bottom;
        width: 150;

        Text {
            text: "PRINT";
            anchors.centerIn: parent;
            font.pixelSize: 20;
        }

        MouseArea {
            anchors.fill: parent;
            onClicked: {
              console.log("aqiiiiiiiiiiii");
                fileDialog.open();
            }


        }
    }

}
