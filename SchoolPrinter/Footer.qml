import QtQuick 2.0

Rectangle {
    id: footerRoot;
    width: 500;
    height: 100;

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
                //open dialog
            }
        }
    }

}
