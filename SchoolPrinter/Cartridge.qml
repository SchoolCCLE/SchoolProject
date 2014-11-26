import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: cartridge;
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

    Rectangle {
        id: fullRect
        color: "black"
        width: parent.width
        height: 380

    }
    Rectangle {
        color: "#707070"; //dark grey
        width: parent.width;
        height: fullRect.height * 50/100; //cambiar por nivel correcto
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            text: cartridge.model.colorCart
            font.pixelSize: 20
            color: "white"
        }

    }

    MouseArea{
        anchors.fill: parent
        onClicked: infoClicked()
    }
}
