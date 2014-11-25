import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle
{
    id: rootHS;
    width: 300;
    height: 200;
    //signal close();

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
            source:
            {
                if(pe_.stateNum == 0)
                {
                    source = "ok-icon.png"
                    console.log("0")
                }
                else if(pe_.stateNum == 1)
                {
                    source = "printing-icon.png"
                    console.log("1")
                }
                else if(pe_.stateNum == 2)
                {
                    source = "warning-icon.png"
                    console.log("2")
                }
                else if(pe_.stateNum == 3)
                {
                    source = "error-icon.png"
                    console.log("3")
                }
            }
            fillMode: Image.PreserveAspectFit
        }

        Text
        {
            id: status;
            Layout.fillWidth: true;
            text: pe_.stateText
        }


        Button
        {
            id: close;
            anchors.right: header.right;
            width: 50;
            text: "X";
            onClicked:
            {
                Qt.quit();
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
