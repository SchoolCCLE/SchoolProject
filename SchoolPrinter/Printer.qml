import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    width: 500;
    height: 250;
    anchors.centerIn: parent;

    ColumnLayout
    {
        anchors.fill: parent;
        Header
        {

        }

        Rectangle{
            height: 3;
            Layout.fillWidth: true;
            color: "black";
        }


    }
}
