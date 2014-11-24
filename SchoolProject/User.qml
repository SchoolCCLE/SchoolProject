import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    width: 640
    height: 480

    ColumnLayout{
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: buttonData.top;

        Label{
            id: labelUserName;
            Layout.fillWidth: true;
            height: 60;
            text: "";
        }

        Label{
            id: labelAccessLevel;
            Layout.fillWidth: true;
            height: 60;
            text: "";
        }

        Label{
            id: labelFullName;
            Layout.fillWidth: true;
            height: 60;
            text: "";
        }

        Label{
            id: labelPassword;
            Layout.fillWidth: true;
            height: 60;
            text: "";
        }

    }

    Button
    {
        id: buttonData;
        anchors.bottom: parent.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
        text: "Show User Data";
        onClicked: {

        }

    }

}
