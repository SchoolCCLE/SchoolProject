import QtQuick 2.3
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 230
    height: 125
    color: "steelblue"
    border.width: 5
    border.color: "grey"
    signal dataInput(string user, string passwd);
    signal cancel();
    Connections {
        target: userModel_
        onAccessGranted: {
            console.log("onAccessGranted", access)
            if(!access){
                textUser.text = "";
            }
        }
    }

    GridLayout {
        id: gridLayout1
        rows: 3
        columnSpacing: 1
        columns: 2
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 5

        Text {
            id: text1
            text: qsTr("User")
            font.pixelSize: 12
        }

        TextField {
            id: textUser
            placeholderText: qsTr("User")
        }

        Text {
            id: text2
            text: "Password"
            font.pixelSize: 12
        }

        TextField {
            id: textPasswd
            echoMode: 2
            placeholderText: qsTr("Password")
        }

        Button {
            id: buttonOk
            text: "Ok"
            onClicked: {
                root.dataInput(textUser.text,textPasswd.text);
            }
        }

        Button {
            id: buttonCancel
            text: qsTr("Cancel")
            onClicked: {
                root.cancel();
            }
        }
    }
}
