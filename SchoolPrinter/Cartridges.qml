import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: root;
    signal infoClicked(int index);
    color: "khaki";
    RowLayout{
        anchors.centerIn: parent
        spacing: 10
        Repeater{
            model: cartridges;
            delegate: Cartridge{
                model: modelData;
            }
        }
    }

}
