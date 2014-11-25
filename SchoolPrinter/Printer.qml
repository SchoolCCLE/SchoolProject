import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    anchors.fill: parent;

    RowLayout
    {
        anchors.fill: parent;
        Rectangle
        {
            id: printerInfo;
            height: 100;
            Layout.fillWidth: true;
            TextArea
            {
                id: textPrinterInfo;

            }
        }

        Rectangle
        {
            id: usersInfo;
            Layout.fillHeight: true;
            Layout.fillWidth: true;
            Label
            {
                text:{
                    "User - Access Level ";
                }
            }
            Column {
                Repeater {
                    model: 2;
                    Text { text: usersData_[index]; }
                }
            }

        }
    }
}
