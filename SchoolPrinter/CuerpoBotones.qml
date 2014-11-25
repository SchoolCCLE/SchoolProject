import QtQuick 2.3
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2



Rectangle {
    id:rectangleCuerpo;

    property bool vista:true;
    width: 800;
    height: 50;




    ColumnLayout
    {
        anchors.fill:parent;
        RowLayout
        {
            anchors.fill: parent;
            Button
            {
                id: buttonPrinter;
                text: "Botón Printer";
                Layout.fillWidth:true;
                onClicked:
                {
                    rectangleCuerpo.vista=true;
                }
            }
            Button
            {
                id: buttonPrintHeads;
                text: "Botón PrintHeads";
                Layout.fillWidth: true;
                onClicked:
                {
                    rectangleCuerpo.vista=false;
                }
            }
        }

        RowLayout
        {
            id:rowSelector;
            Layout.fillHeight: true;
            //anchors.centerIn: parent;
            Loader
            {
                id:miLoader;
                //anchors.top:columnLay.bottom;
                //anchors.left: columnLay.left;
                //anchors.right: columnLay.right;
                //anchors.bottom: columnLay.top;

                sourceComponent: rectangleCuerpo.vista ? comp1: comp2;

            }

            Component
            {

                id:comp1;
                Rectangle
                {
                    color:"red";
                    height:90;
                    width:90;
                }

                //Aquí va la vista printer

            }

            Component
            {
                id:comp2;
                //Aquí va la vista printHeads
                Rectangle
                {
                    height:90;
                    width:90;
                    color:"blue";
                }
            }


        }
    }
}
