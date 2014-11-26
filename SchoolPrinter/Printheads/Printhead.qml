import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: printhead
    signal infoClicked;
    property var colorList: ["yellow", "blue", "red", "black"]
    property QtObject model;
    width: 100
    height: 400
    color: "black"

    RowLayout{
        anchors.fill: parent
        spacing: 2
        Repeater{
            model: colorList.length
            delegate: Rectangle{
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: colorList[index]
            }
        }
    }

    Rectangle{
        color: "black"
        width: parent.width
        height: 380
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            text: printhead.model.color
            font.pixelSize: 20
            color: "white"
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: infoClicked()
    }
}
