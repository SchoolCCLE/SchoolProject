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
            model: _myModel.cartridges
            delegate: Cartridge{
                //model: modelData
                inkLevel: _myModel.cartridges[index].levelcc*4;
                text:_myModel.cartridges[index].color;
                capacity:"Ink Level: "+ _myModel.cartridges[index].capacity;
                cColor: _myModel.cartridges[index].color;
                onInfoClicked: root.infoClicked(index);
            }
        }
    }
}
