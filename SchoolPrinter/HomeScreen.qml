import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    id: homeScreenRoot;
    width: 500;
    height: 250;
    anchors.centerIn: parent;
    signal loadPrinter();
    property bool printerScreen: false;

    ColumnLayout
    {
        anchors.fill: parent;
        Header
        {

        }

        Rectangle{
            height: 3;
            Layout.fillWidth: true;
            color: "black";
        }

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            RowLayout
            {
                anchors.fill: parent;
                spacing: 10;

                Rectangle
                {
                    Layout.fillWidth: true;
                    Layout.fillHeight: true;
                    Button
                    {
                        id: printerButton;
                        anchors.centerIn: parent;
                        text: "Printer";
                        onClicked: {
                            homeScreenRoot.loadPrinter();
                        }
                    }
                }

                Rectangle
                {
                    Layout.fillWidth: true;
                    Layout.fillHeight: true;
                    Button
                    {
                        id: printHeadsButton;
                        anchors.centerIn: parent;
                        text: "Print Heads";
                    }
                }

            }
        }



    }
}
