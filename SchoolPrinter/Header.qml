import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    id: header;
    anchors.left : parent.left;
    anchors.right: parent.right;
    anchors.top : parent.top;
    height: 62;
    color: "steelblue";
    signal close();

    RowLayout
    {
        anchors.fill: parent;
        Rectangle
        {
            id: printerStatusContainer;
            height: 60;
            width: 60;
            color:"transparent";
            Image
            {
                id: statusOk;
                anchors.fill: parent;
                source: "icons/Alarm-Tick-icon.png";
                visible: true;
            }
            Image
            {
                id: statusWarning;
                anchors.fill: parent;
                source: "icons/Alarm-Warning-icon.png";
                visible: true;
            }
            Image
            {
                id: statusFail;
                anchors.fill: parent;
                source: "icons/Alarm-Error-icon.png";
                visible: true;
            }

        }

        Rectangle
        {
            id: titleContainer;
            Layout.fillHeight: true;
            Layout.fillWidth: true;
            color:"transparent";
            Text{
                id: textPrinterStatus;
                anchors.centerIn: parent;
                color: "White";
                text: "Printer status";

            }

        }

        Rectangle
        {
            id: buttonContainer;
            height: 60;
            width: 60;
            color:"transparent";
            Image
            {
                id: buttonClose;
                anchors.fill: parent;
                source: "icons/Windows-Close-Program-icon.png";
                MouseArea
                {
                    anchors.fill: parent;
                    onClicked:
                    {
                        header.close();
                    }
                }
            }
        }
    }

}
