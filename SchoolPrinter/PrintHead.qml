import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

Dialog{
    height:400
    width:400
    visible:true
    property alias idColor: textIDColor.text;
    property bool conditionSalud: true;

Rectangle {
    id:rootPrintHead
    anchors.fill:parent

    ColumnLayout{
        id:layoutPrintHead
        anchors.fill:parent;
        Rectangle{
            id:rectIDcolor
            height:30
            radius:4
            color: idColor;
            Layout.fillWidth: true;
            Text{
                id:textIDcolorTitle;
                anchors{
                    left:parent.left;
                    verticalCenter: parent.verticalCenter;
                }
                text:"Color: "
            }
            Text{
                id:textIDColor;
                anchors{
                    left:textIDColorTitle.rigth;
                    verticalCenter: parent.verticalCenter;
                }
                color:text;
            }
        }
        Rectangle{
            id:rectSalud
            height:30
            radius:4
            color: idColor;
            Layout.fillWidth: true;
            Text{
                id:textSaludTitle;
                anchors{
                    left:parent.left;
                    verticalCenter: parent.verticalCenter;
                }
                text:"Salud: "
            }
            Text{
                id:textSalud;
                anchors{
                    left:textSaludTitle.right;
                    verticalCenter: parent.verticalCenter;
                }
                color: conditionSalud ? "#2EFE2E" : "#FF0000";
            }
        }
        Rectangle{
            id:rectGarantia
            height:30
            radius:4
            color: idColor;
            Layout.fillWidth: true;
            Text{
                id:textGarantiaTitle;
                anchors{
                    left:parent.left;
                    verticalCenter: parent.verticalCenter;
                }
                text:"Garantia activa: "
            }
            Text{
                id:textGarantia;
                anchors{
                    left:textGarantiaTitle.right;
                    verticalCenter: parent.verticalCenter;
                }

            }
        }
        Rectangle{
            id:rectFechaGarantia
            height:30
            radius:4
            color: idColor;
            Layout.fillWidth: true;
            Text{
                id:textFechaGarantiaTitle;
                anchors{
                    left:parent.left;
                    verticalCenter: parent.verticalCenter;
                }
                text:"Fecha de Garantia: "
            }
            Text{
                id:textFechaGarantia;
                anchors{
                    left:textFechaGarantiaTitle.rigth;
                    verticalCenter: parent.verticalCenter;
                }
            }
        }
        Rectangle{
            id:rectEstado
            height:30
            radius:4
            color: idColor;
            Layout.fillWidth: true;
            Text{
                id:textEstadoTitle;
                anchors{
                    left:parent.left;
                    verticalCenter: parent.verticalCenter;
                }
                text:"Estado: "
            }
            Text{
                id:textIDEstado;
                anchors{
                    left:textEstadoTitle.right;
                    verticalCenter: parent.verticalCenter;
                }
                color:idColor;
            }
        }
    }
}
}
