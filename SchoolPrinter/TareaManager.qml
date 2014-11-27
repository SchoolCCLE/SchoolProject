import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2


Rectangle {
    id: tareaManager
    signal buttonOk (int number, string fileName);
    width: 100
    height: 450

    FileDialog
    {
        id:ficheroDialog
        nameFilters: [ "Image files (*.jpg *.png *.tiff *.pdf)"]
        onAccepted:
        {
            tareaManager.buttonOk(3, "asdf");
        }
    }

    RowLayout
    {
        width:parent.width
        RowLayout
        {
            Image
            {
                id: fileIcon
                width:60
                height: 60
                fillMode: Image.PreserveAspectFit
                source:ficheroDialog.fileUrl
            }
        }


        RowLayout
        {
            id: nameRect
            anchors.top: parent.top;
            Text {
                id: name
                text: qsTr("Name")
            }
        }
        RowLayout
        {
            id: pTimeRect;

                Text {
                id: pTime
                text: qsTr("Time")
            }
        }
        RowLayout
        {
            Text {
                id: status
                text: qsTr("Estado")
            }
        }
    }
    Button
                {

                    id:boton;
                    anchors.centerIn: parent
                    width:200
                    height:100;
                    text: "Boton"
                    onClicked:
                    {
                        ficheroDialog.open();
                    }
                }


}
