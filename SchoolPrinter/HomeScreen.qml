import QtQuick 2.3
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle
{
    width: 400
    height: 300

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 10

        Header
        {
            id:header
            //anchors.top:parent.top
            Layout.fillWidth: true
        }

        RowLayout
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.margins: 20

            Button
            {
                Loader
                {
                    id:printerLoader
                }

                id:botonEstado
                anchors.left: parent.left
                text:"Detalles"
                onClicked:
                {
                    printerLoader.source = "Printer.qml"
                }
            }

            Button
            {
                id:botonPrintHeads
                anchors.right: parent.right
                text:"PrintHeads"
            }
        }
    }
}
