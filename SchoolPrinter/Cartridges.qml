import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: root
    signal infoClicked(int index);
    property var colorList: ["yellow", "blue", "red", "black"]
    color: "darkgrey"
    RowLayout{
        anchors.centerIn: parent
        spacing: 10
        Repeater{
            model: printheads
            delegate: Cartridge{
                model: modelData
                inkLevel: levelInkMock[index];
                text:colorList[index];
                cColor: colorList[index];
                onInfoClicked: root.infoClicked(index);
            }
        }
    }
}
