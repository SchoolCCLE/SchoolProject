import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Dialog {
    id: logDialog;
    visible: true;
    width: 300;
    height: 300;

    contentItem: Rectangle {
        color: "#00000000";

        ColumnLayout{
            id: columnLog;
            anchors.fill: parent;

            RowLayout{
                width: 300;

                Label{
                    anchors.left: parent.left;
                    width: 50;

                    text: "User";


                }
                TextField{
                    id: userInput;
                    anchors.right: parent.right;
                    width: 200;

                }
            }
            RowLayout{
                Label{
                    anchors.left: parent.left;
                    width: 50;

                    text: "Password";


                }
                TextField{
                    id: passInput;
                    anchors.right: parent.right;
                    width: 200;

                }
            }
            RowLayout{
                id: controlLoggin;
                Button{
                    id: log;
                    anchors.left: parent.left;
                    anchors.bottom: parent.bottom;
                    text: "Log in";
                    onClicked: {

                    }
                }
                Button{
                    id: anotherOpt;
                    anchors.left: parent.right;
                    anchors.bottom: parent.bottom;
                    text: "Sign in";
                    onClicked: {

                    }
                }
            }

        }
    }


}
