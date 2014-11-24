import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

Dialog {
    id: databaseDialog;
    visible: true;
    width: 500;
    height: 500;


    contentItem: Rectangle {
        anchors.fill: parent;

        ColumnLayout {
            id: columnDatabase;

            anchors.fill: parent;



            Rectangle {
                Layout.fillWidth: true;
                Layout.fillHeight: true;



                ListView {
                    anchors.fill: parent

                    delegate: Text{
                        text: "------List-----";
                    }

                }
            }


            RowLayout{
                id: controlButtons;
                visible: true;
                anchors.bottom: columnDatabase.bottom;
                Button{
                    id: remove;


                    text: "Delete user";
                    onClicked: {

                    }
                }
                Button{
                    id: modify;
                    text: "Modify user";
                    onClicked: {

                    }
                }
                Button{
                    id: alta;
                    text: "Alta user";
                    onClicked: {

                    }
                }
            }

        }
    }
}
