import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("School Proyect")
    color: "#CCCCB2";

    ColumnLayout{
        anchors.fill: parent;
        anchors.margins: 10;
        spacing: 10;

        Rectangle
        {
            anchors.top: parent.top;
            Layout.fillWidth: true;
            height: 30;
            color: "transparent";

            Label
            {
                anchors.left: parent.left;
                anchors.leftMargin: 10;
                text: "Login"
                font.pixelSize: 20;
            }
        }

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.fillHeight: true;

            color: "#E6E6D8";

            GridLayout
            {
                anchors.fill: parent;
                anchors.margins: 20;
                rows: 7;
                columns: 3;
                columnSpacing: 20;

                Rectangle
                {
                    width: 10;
                    Layout.row: 0;
                    Layout.column: 0;
                    Layout.rowSpan: 7;
                    color: "transparent";
                }

                // First Column
                Label
                {
                    Layout.row: 0;
                    Layout.column: 1;
                    text: "Username";
                }

                TextField
                {
                    Layout.row: 1;
                    Layout.column: 1;
                    Layout.fillWidth: true;
                    placeholderText: qsTr("Enter username");
                }

                Label
                {
                    Layout.row: 2;
                    Layout.column: 1;
                    text: "Password";
                }

                TextField
                {
                    Layout.row: 3;
                    Layout.column: 1;
                    Layout.fillWidth: true;
                    placeholderText: qsTr("Enter password");
                    echoMode: TextInput.Password;
                }

                Button
                {
                    Layout.row: 6;
                    Layout.column: 1;
                    text: "Login";
                }

                // Second Column
                Label
                {
                    Layout.row: 0;
                    Layout.column: 2;
                    text: "Username";
                }

                TextField
                {
                    Layout.row: 1;
                    Layout.column: 2;
                    Layout.fillWidth: true;
                    placeholderText: qsTr("Enter username");
                }

                Label
                {
                    Layout.row: 2;
                    Layout.column: 2;
                    text: "FullName";
                }

                TextField
                {
                    Layout.row: 3;
                    Layout.column: 2;
                    Layout.fillWidth: true;
                    placeholderText: qsTr("Enter fullname");
                }

                Label
                {
                    Layout.row: 4;
                    Layout.column: 2;
                    text: "Password";
                }

                TextField
                {
                    Layout.row: 5;
                    Layout.column: 2;
                    Layout.fillWidth: true;
                    placeholderText: qsTr("Enter password");
                    echoMode: TextInput.Password;
                }

                Button
                {
                    Layout.row: 6;
                    Layout.column: 2;
                    text: "Register";
                }
            }
        }
    }


}
