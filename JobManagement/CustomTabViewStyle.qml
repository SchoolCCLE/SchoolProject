import QtQuick 2.0
import QtQuick.Controls.Styles 1.2

TabViewStyle{
    frame: Rectangle {
        color: "#FFFFFF"
        border.color: "#aaa"

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border.color: "#66ffffff"
            anchors.margins: 1
        }
    }
}
