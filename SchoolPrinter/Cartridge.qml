import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: cartridge;
    property QtObject model;
    width: 80;
    height: 400;
    color: "black";
    radius: 3;

    ColumnLayout
    {
        anchors.fill: parent;
        spacing: 10;

        Image {
            id: cartridgeStatusImage;
            Layout.minimumHeight: 50;
            Layout.minimumWidth: 50;
            Layout.maximumHeight: 50;
            Layout.maximumWidth: 50;
            asynchronous: true;
            smooth: true;
            fillMode: Image.PreserveAspectFit;
            Layout.alignment: Qt.AlignCenter;
            source: {
                if(model.inkLevel == 0){
                    source =  "errorIcon.png";
                }else if(model.inkLevel < (model.inkCapacity*0.05)){
                    source = "warningIcon.png";
                }else {
                    source = "okIcon.png";
                }
            }
        }

        Rectangle
        {
            Layout.minimumHeight: 120;
            Layout.minimumWidth: 60;
            Layout.maximumHeight: 120;
            Layout.maximumWidth: 60;
            Layout.alignment: Qt.AlignCenter;
            color: "transparent";


            Text{
                text: {
                    text = "Color id:\n"+
                    model.idColor +
                    "\nInstallation\ndate:\n"+
                    model.installationDate}
                color: "white"
            }
        }

        Rectangle
        {
            Layout.minimumHeight: 150;
            Layout.minimumWidth: 60;
            Layout.maximumHeight: 150;
            Layout.maximumWidth: 60;
            Layout.alignment: Qt.AlignCenter;
            color: "white";

            Rectangle
            {
                anchors.bottom: parent.bottom;
                anchors.left: parent.left;
                anchors.right: parent.right;
                anchors.margins: 2;
                height: {
                    height = (150 - 4) * (model.inkLevel / model.inkCapacity);
                }

                color:{
                    color = "#"+model.idColor;
                }
            }
        }
    }
}
