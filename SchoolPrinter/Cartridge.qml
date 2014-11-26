import QtQuick 2.0

import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: cartridge
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
            model: 4 //condition ? 4 : 8 NECESITO CONDICION DE ALTA O BAJA CAPACIDAD.
            delegate: Rectangle{
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "white"
            }
        }
    }

    Rectangle{
        color: "blue"
        width: parent.width
        height: 380
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            font.pixelSize: 20
            color: "white"
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: infoClicked()
    }
}
