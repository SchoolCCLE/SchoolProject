import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

import JobManagement 1.0

Item {
    id: jobDelegate
    property QtObject model;

    height: 50
    width: parent !== null ? parent.width : 0

    Rectangle
    {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        height: 1
        color: "grey"
    }
    RowLayout
    {
        anchors.fill: parent
        anchors.leftMargin: 15
        anchors.rightMargin: 15
        Item
        {
            width: icon.width
            height: icon.height
            Image {
                id: icon

                width: 50
                height: 50
                fillMode: Image.PreserveAspectFit

                states: [
                    State {
                        name: "PDF"
                        when: jobDelegate.model.type === Job.PDF
                        PropertyChanges {
                            target: icon
                            source: "qrc:/PDF.png"
                        }
                    },
                    State {
                        name: "JPG"
                        when: jobDelegate.model.type === Job.JPG
                        PropertyChanges {
                            target: icon
                            source: "qrc:/jpg.png"
                        }
                    },
                    State {
                        name: "TIFF"
                        when: jobDelegate.model.type === Job.TIFF
                        PropertyChanges {
                            target: icon
                            source: "qrc:/tiff.png"
                        }
                    }
                ]
            }
        }

        Text {
            Layout.fillWidth: true
            text: jobDelegate.model.name
            color: "black"
            font.weight: Font.Bold
        }
        Item{
            width: 10
            height: parent.height
        }
        Text {
            text: "Time " + jobDelegate.model.printTime + " sec"
            color: "black"
            visible: !jobDelegate.model.printed
        }
        Item{
            width: 10
            height: parent.height
        }

        Text {
            text: {
                if (jobDelegate.model.printing)
                {
                    return "Printing";
                }
                else if (jobDelegate.model.printed)
                {
                    return "Printed";
                }
                else
                {
                    return "Waiting";
                }
            }

            color: "black"
        }

        Item
        {
            width: childrenRect.width
            height: parent.height
            BusyIndicator{

                anchors.verticalCenter: parent.verticalCenter
                width: running ? parent.height / 2 : 0
                running: jobDelegate.model.printing
            }
        }
    }
}
