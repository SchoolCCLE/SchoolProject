import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

Rectangle
{
    width: 800
    height: 600

    FileDialog
    {
        id: fileDialog
        title: "Elige un fichero"
        nameFilters: [ "JPG file (*.jpg)", "PNG file (*.png)", "TIFF file (*.tiff)", "PDF file (*.pdf)" ]
        onAccepted:
        {
            console.log("Fichero: " + fileDialog.fileUrls);
            fileDialog.close();
        }

        onRejected:
        {
            fileDialog.close();
        }
    }

    Dialog
    {
        id:deleteDialog
        title:"Borrar tareas"
        standardButtons: StandardButton.Yes | StandardButton.No
        Text
        {
            anchors.centerIn: parent
            text:"¿Quieres borrar todas las tareas?"
        }
        onYes:
        {
            //Borrar Printed
        }
        onNo:
        {
            deleteDialog.close()
        }
    }

    ColumnLayout
    {
        anchors.fill: parent

        Label
        {
            id:header
            anchors.margins: 10
            anchors.top: parent.top
            Layout.fillWidth: true
            Layout.minimumHeight: 50
            Layout.maximumHeight: 50
            text: "Job Manager"
            font.pixelSize: 24
        }

        TabView
        {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Tab
            {
                title: "Printing"
                ColumnLayout
                {
                    anchors.fill: parent

                    RowLayout
                    {
                        Layout.fillWidth: true

                        Rectangle
                        {
                            Layout.fillWidth: true
                        }

                        GroupBox
                        {
                            title:"State"
                            RowLayout
                            {
                                ExclusiveGroup { id: positionButton }

                                RadioButton
                                {
                                    id:play
                                    text:"Play"
                                    checked: true
                                    exclusiveGroup: positionButton
                                }

                                RadioButton
                                {
                                    id:pause
                                    text:"Pause"
                                    exclusiveGroup: positionButton
                                }
                            }
                        }
                    }

                    JobQueue
                    {

                    }
                }
            }

            Tab
            {
                title: "Printed"
                ColumnLayout
                {
                    anchors.fill: parent

                    RowLayout
                    {
                        Layout.fillWidth: true

                        Rectangle
                        {
                            Layout.fillWidth: true
                        }

                        Button
                        {
                            id:buttonPrinted
                            text:"Delete All"
                            onClicked:
                            {
                                deleteDialog.open()
                            }
                        }
                    }

                    JobQueue
                    {

                    }
                }
            }
        }

        RowLayout
        {
            id:footer
            anchors.margins: 10
            anchors.bottom: parent.bottom
            Layout.fillWidth: true
            Layout.minimumHeight: 50
            Layout.maximumHeight: 50

            Rectangle
            {
                Layout.fillWidth: true
            }

            Button
            {
                id:buttonPrint
                text:"Print"
                onClicked:
                {
                    fileDialog.open();
                }
            }
        }
    }
}
