import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    Layout.fillWidth: true;
    height: 70;

    RowLayout
    {
        anchors.fill: parent;
        anchors.margins: 10;
        spacing: 10;

        Image {
            id: headerImageView;
            Layout.minimumHeight: 50;
            Layout.minimumWidth: 50;
            Layout.maximumHeight: 50;
            Layout.maximumWidth: 50;
            asynchronous: true;
            smooth: true;
            fillMode: Image.PreserveAspectFit;
            source: {
                if(_model.status == 0){
                    source = "okIcon.png";
                } else if(_model.status == 1){
                    source = "printerIcon.png";
                } else if(_model.status == 2){
                    source = "warningIcon.png";
                } else if(_model.status == 3){
                    source = "errorIcon.png";
                }
            }

        }

        Rectangle
        {
            Layout.fillWidth: true;

            Text {
                id: statusText;
                anchors.centerIn: parent;
                text:{
                    if(printerScreen){

                    }else{
                        if(_model.status == 0){
                            text = "Idle";
                        } else if(_model.status == 1){
                            text = "Printing";
                        } else if(_model.status == 2){
                            text = "Warning";
                        } else if(_model.status == 3){
                            text = "Error";
                        }
                    }
                }
            }
        }


        Rectangle
        {
            id: exitButton;
            Layout.minimumHeight: 50;
            Layout.minimumWidth: 50;
            Layout.maximumHeight: 50;
            Layout.maximumWidth: 50;
            radius: 3;
            border.color: "black";

            Text {
                anchors.centerIn: parent;
                text: qsTr("X");
            }

            MouseArea
            {
                anchors.fill: parent;
                onClicked: {
                    Qt.quit();
                }
            }
        }

    }
}
