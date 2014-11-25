import QtQuick 2.3
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle {
        id:rootHeader;
    width: 800;
    height: 62
    color:"red";
    property int estado;
    signal buttonClose();

    RowLayout
    {
        //width: 62;
        anchors.fill: parent;
        anchors.margins: 3;


        Connections
        {
            target: _myModel;
            stateNumberChanged:
            {
                if (_myModel.stateNumber == 1)
                {
                    imageHeader.source="idle.png";
                }
                if (_myModel.stateNumber == 2)
                {
                    imageHeader.source="printing.jpg";
                }
                if (_myModel.stateNumber == 3)
                {
                    imageHeader.source="warning.png";
                }
                if (_myModel.stateNumber == 4)
                {
                    imageHeader.source="error.png";
                }else
                {
                    imageHeader.source="error.png";
                }
            }
        }

        Image
        {

            id:imageHeader;
            Layout.fillHeight: true;
            Layout.left: true;
            source:"idle.png";
            //fillMode:Image.PreserveAspectCrop;
            fillMode:Image.PreserveAspectFit;

//            onStatusChanged:
//            {
//                // la variable recibida de Qt status
//                if (estado == 1)
//                {
//                    imageHeader.source="idle.png";
//                }
//                if (estado == 2)
//                {
//                    imageHeader.source="printing.jpg";
//                }
//                if (estado == 3)
//                {
//                    imageHeader.source="warning.png";
//                }
//                if (estado== 4)
//                {
//                    imageHeader.source="error.png";
//                }else
//                {
//                    imageHeader.source="error.png";
//                }

//            }

//            states: [
//                State {
//                    name: "IDLE"
//                    PropertyChanges { target: signal; source: "idle.png"}

//                },
//                State {
//                    name: "PRINTING"
//                    PropertyChanges { target: signal; source: "printing.jpg"}

//                },
//                State {
//                    name: "WARNING"
//                    PropertyChanges { target: signal; source: "warning.jpg"}

//                },
//                State {
//                    name: "ERROR"
//                    PropertyChanges { target: signal; source: "error.png"}

//                }
//            ]

        }

        TextArea
        {
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            text:"AHOLAAA";
        }

        Button
        {
            text:"Cerrar";
            onClicked:
            {
                rootHeader.buttonClose();
            }

        }
    }



}
