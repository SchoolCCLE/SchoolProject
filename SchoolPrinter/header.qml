import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle {
    id: rootHS;
    width: 200;
    height: 200;
    signal close();

    RowLayout {
        id: header;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        height: 50;
        Image {
            id: image;
            anchors.left: header.left;
            //image here (visible condition?)

        }
        Text{
            id: status;
            Layout.fillWidth: true;
            text: "Printer status"; //get text by signals
        }


        Button {
            id: close;
            anchors.right: header.right;
            width: 50;
            text: "X";
            onClicked: {
                rootHS.close(); //close window by signals
            }
        }
    }
    Rectangle {
        id: footerHeader;
        anchors.bottom: header.bottom;
        height: 5;
        color: "brown";
    }
}
