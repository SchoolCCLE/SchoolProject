import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    Layout.fillWidth: true;
    height: 70;

    RowLayout
    {
        anchors.fill: parent;
        anchors.margins: 10;
        spacing: 10;

        Image {
            id: headerImageView;
            Layout.minimumHeight: 50;
            Layout.minimumWidth: 50;
            Layout.maximumHeight: 50;
            Layout.maximumWidth: 50;
            asynchronous: true;
            smooth: true;
            fillMode: Image.PreserveAspectFit;
            source: "okIcon.png";
        }

        Rectangle
        {
            Layout.fillWidth: true;

            Text {
                id: statusText;
                anchors.centerIn: parent;
                text: qsTr("Estado de la impresora");
            }
        }


        Rectangle
        {
            id: exitButton;
            Layout.minimumHeight: 50;
            Layout.minimumWidth: 50;
            Layout.maximumHeight: 50;
            Layout.maximumWidth: 50;
            radius: 3;
            border.color: "black";

            Text {
                anchors.centerIn: parent;
                text: qsTr("X");
            }

            MouseArea
            {
                anchors.fill: parent;
                onClicked: {
                    Qt.quit();
                }
            }
        }

    }
}
