import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle
{
    id: rootHS;
    width: 300;
    height: 200;
    signal close();

    RowLayout
    {
        id: header;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;

        Image
        {
            id: image;
            Layout.maximumHeight: 40
            Layout.maximumWidth: 40
            anchors.left: header.left;
            source:"ok-icon.png"
            fillMode: Image.PreserveAspectFit
        }

        Text
        {
            id: status;
            Layout.fillWidth: true;
            text: "Printer status"; //get text by signals
        }


        Button
        {
            id: close;
            anchors.right: header.right;
            width: 50;
            text: "X";
            onClicked:
            {
                rootHS.close(); //close window by signals
            }
        }
    }
    Rectangle
    {
        id: footerHeader;
        anchors.bottom: header.bottom;
        height: 5;
        color: "brown";
    }
}
