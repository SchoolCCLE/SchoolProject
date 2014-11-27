import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: root
    signal infoClicked(int index);
    signal callAddJob (string ruta);
    property var colorList: ["yellow", "blue", "red", "black"]
    color: "darkgrey"
    Footer{
        id: myFooter
        onCallAddJob:
        {
            root.callAddJob(ruta);
        }

        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;

    }
    Header{
        id: myHeader
        anchors.top:parent.top;
        anchors.right: parent.right;
        anchors.left: parent.left;

    }
    TabPanel{
        id: myTabPanel
        anchors.top:myHeader.bottom;
        anchors.right: parent.right;
        anchors.left: parent.left;
        anchors.bottom: myFooter.top;

    }



}
