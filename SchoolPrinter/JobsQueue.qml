import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.2

Rectangle {

    anchors.fill: parent;

    ColumnLayout
    {
        anchors.fill: parent;
        spacing: 0;

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.preferredHeight: 30;
            Layout.maximumHeight: 30;
            color: "transparent";

            RowLayout
            {
                anchors.fill: parent;
                anchors.margins: 5;

                Text
                {
                    text: "JOBS QUEUE";
                }

            }

            Rectangle
            {
                anchors.bottom : parent.bottom;
                height: 2;
                width: parent.width;
                color: "black";
            }

        }

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            color: "transparent";

            TabView {
                anchors.fill: parent;
                Tab {
                    title: "Printing";
                    Rectangle {

                        color: "transparent";
                        anchors.margins: 5;
                        anchors.fill: parent;
                        ColumnLayout
                        {
                            anchors.fill: parent;
                            spacing: 5;

                            Button
                            {
                                id: printingPlayPauseButton;
                                text: "Play";
                                onClicked: {
                                    if(text == "Play"){
                                        text = "Pause";
                                    }else{
                                        text = "Play";
                                    }
                                }
                            }

                            Rectangle{
                                Layout.fillHeight: true;
                                Layout.fillWidth: true;
                                color: "transparent";
                                border.color: "black";
                                radius: 3;

                                Flickable {
                                    contentWidth: printingList.width;
                                    contentHeight: printingList.height

                                    ListView{
                                        id: printingList;
                                        anchors.fill: parent;
                                        // Falta meter el modelo
                                        model:  {}
                                        delegate: printComponent;
                                        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                                        focus: true;
                                    }
                                }
                            }
                        }
                    }
                }
                Tab {
                    title: "Printed"
                    Rectangle {

                        color: "transparent";
                        anchors.margins: 5;
                        anchors.fill: parent;
                        ColumnLayout
                        {
                            anchors.fill: parent;
                            spacing: 5;

                            Button
                            {
                                id: printedDeleteAllButton;
                                text: "Delete all";
                            }

                            Rectangle{
                                Layout.fillHeight: true;
                                Layout.fillWidth: true;
                                color: "transparent";
                                border.color: "black";
                                radius: 3;

                                Flickable {
                                    contentWidth: printedList.width;
                                    contentHeight: printedList.height

                                    ListView{
                                        id: printedList;
                                        anchors.fill: parent;
                                        // Falta meter el modelo
                                        model:  {}
                                        delegate: printComponent;
                                        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                                        focus: true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }

        Rectangle
        {
            Layout.fillWidth: true;
            Layout.preferredHeight: 35;
            Layout.maximumHeight: 35;
            color: "transparent";

            ColumnLayout
            {
                anchors.fill: parent;

                Rectangle
                {
                    Layout.fillWidth: true;
                    id: footerSeparator;
                    height: 2;
                    width: parent.width;
                    color: "black";
                }

                Rectangle
                {
                    Layout.fillHeight: true;
                    Layout.fillWidth: true;
                    color: "transparent";

                    Button
                    {
                        anchors.right: parent.right;
                        anchors.margins: 5;
                        text: "Print";
                        onClicked: {
                            fileDialog.open();
                        }
                    }
                }
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: [ "Image files (*.jpg *.png *.tiff *.pdf)" ];
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            console.log()
        }
        onRejected: {
            console.log("Canceled")
        }
    }


    Component {
        id: printComponent
        Item {
            width: 180; height: 40
            Row {
                Text { text: '<b> Tipo:</b> ' + type }
                Text { text: '<b> Name:</b> ' + name }
                Text { text: '<b> PrintingTime:</b> ' + printingTime }
                Text { text: '<b> Status:</b> ' + status }

            }
        }
    }
}
