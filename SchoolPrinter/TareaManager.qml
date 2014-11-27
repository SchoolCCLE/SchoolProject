import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2


Rectangle {
    signal buttonOk (int number, string fileName);
    id: tareaManager
    width: 100
    height: 450

    TabView
    {
        anchors.right: parent.right;
        anchors.left: parent.left;
        Tab
        {
            title: "Printing"
            ListView
            {
                anchors.fill: parent;
                model: TareaManagerItem {}
                    delegate: tareaItem
                TareaManagerItem
                {

                }
            }

        }

        Tab
        {
            title: "Printed"
        }

        FileDialog
        {
            id:ficheroDialog
            nameFilters: [ "Printable files (*.jpg *.png *.tiff *.pdf)"]
            onAccepted:
            {
                tareaManager.buttonOk(3, ficheroDialog.fileUrl);
            }
        }


    }
    Button
                {

                    id:boton;
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    width:60
                    height:30;
                    text: "Print"
                    onClicked:
                    {
                        ficheroDialog.open();
                    }
                }



}
