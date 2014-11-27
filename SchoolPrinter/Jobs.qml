import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: root
    signal infoClicked(int index);
    property var colorList: ["yellow", "blue", "red", "black"]
    color: "darkgrey"
    Footer{
        id: myFooter
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;

    }




}
