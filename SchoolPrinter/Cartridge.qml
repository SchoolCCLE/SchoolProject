import QtQuick 2.0

import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: cartridge
    signal infoClicked;
    property alias cColor: cartridgeRect.color;
    property alias inkLevel: cartridgeRect.height;
    property var levelInkMock: [100,400,300,200];
    property alias text: cartridgeText.text;
    property QtObject model;
    width: 100
    height: 450
    radius:6
    color:"transparent"
    Text{
        id:textLevel
        anchors.top:parent.top;
        width:50
        text:"Ink Level: "
    }

    Rectangle{
        anchors.top:textLevel.bottom;
        width:parent.width
        height:400
        radius:6
        color:"grey"
//    RowLayout{
//        anchors.fill: parent
//        spacing: 2
//        Repeater{
//            model: 4 //condition ? 4 : 8 NECESITO CONDICION DE ALTA O BAJA CAPACIDAD.
//            delegate: Rectangle{
//                Layout.fillHeight: true
//                Layout.fillWidth: true
//                color: "white"
//            }
//        }
//    }

        Rectangle{
            id: cartridgeRect;
            anchors.bottom:parent.bottom
            width: parent.width
            height: 395
            radius:6
        }

        Image{
            id:icon
            width: 60; height: 60
            fillMode:Image.PreserveAspectFit
            anchors.top:parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            source:"qrc:/images/ok.png";
        }

        Text{
            id:cartridgeText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top:icon.bottom;
            font.pixelSize: 20
            color: "black"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: infoClicked()
        }
    }
}

