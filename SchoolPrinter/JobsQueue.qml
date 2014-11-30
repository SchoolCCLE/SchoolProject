import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.2
import JobQml 1.0

Rectangle {

    id: root;
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
                                        jobs.statusChanged(true);
                                        text = "Pause";
                                    }else{
                                        jobs.statusChanged(false);
                                        text = "Play";
                                    }
                                }
                            }

                            Rectangle{
                                id: printingList;
                                Layout.fillHeight: true;
                                Layout.fillWidth: true;
                                color: "transparent";
                                border.color: "black";
                                radius: 3;

                                    ListView{
                                        anchors.fill: parent
                                        anchors.margins: 2;
                                        // Falta meter el modelo
                                        model: jobs.jobs
                                        // ANGEL: To delegate in a component you have to use a loader
                                        delegate:  Loader {
                                            // ANGEL: Set the width to parent width
                                            width: parent.width
                                            sourceComponent: printComponent;

                                            // ANGEL: Set the model when loaded
                                            onLoaded: {
                                                item.model = modelData;
                                            }
                                        }
                                        // ANGEL: Highlight was animated because no width was set
                                        highlight: Rectangle { width: parent.width; color: "lightsteelblue"; radius: 3 }
                                        focus: true;
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
                                    ListView{
                                        id: printedList;
                                        anchors.fill: parent
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
            jobs.createJob("Job1",0);
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    Component {
        id: printComponent
        Item {
            // ANGEL: Added a variable to store the model
            property QtObject model;
            width: parent.width ; height: 20
            Row {
                spacing: 5;
                Text { text: '<b> Tipo:</b> ' + model.type }
                Text { text: '<b> Name:</b> ' + model.name }
                Text { text: '<b> PrintingTime:</b> ' + model.time }
                Text { text: '<b> Status:</b> ' + model.status }

            }
        }
    }
}