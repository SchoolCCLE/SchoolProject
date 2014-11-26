import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

Rectangle
{
    id:rootCartuchos
    width: 800
    height: 600

    RowLayout
    {
        Layout.fillHeight: true
        Layout.fillWidth: true
        anchors.margins: 200
        anchors.centerIn: parent

        Repeater
        {
            model:cartridges;
            delegate:

            ColumnLayout
            {

            Image
            {
                height: 100
                width: 100
                anchors.horizontalCenter: parent.horizontalCenter
                source:
                {
                    if(cartridges.numberStatus == 0)
                    {
                        return "ok-icon.png"
                    }
                    else if(cartridges.numberStatus == 1)
                    {
                        return "warning-icon.png"
                    }
                    else if(cartridges.numberStatus == 2)
                    {
                        return "error-icon.png"
                    }
                    else
                    {
                        return "ok-icon.png"
                    }
                }
                fillMode: Image.PreserveAspectFit
            }
                ProgressBar
                {
                    id:cartuchoBar
                    anchors.horizontalCenter: parent.horizontalCenter
                    minimumValue: 0
                    maximumValue: 100
                    value: modelData.level
                    orientation: Qt.Vertical
                    style:ProgressBarStyle
                    {
                        background: Rectangle
                        {
                            implicitWidth: 300
                            implicitHeight: 100
                            color:"transparent"
                            border.color:"black"
                        }
                        progress: Rectangle
                        {
                            id:cartuchoRec
                            color: modelData.color
                            border.color:"black"
                        }
                    }
                }

                Label
                {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:modelData.idColor
                }

                Label
                {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: modelData.color
                }

                Label
                {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: modelData.level
                }

                Label
                {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: modelData.capacity
                }

                Label
                {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text:modelData.installDate
                }
            }
        }

/*
        ColumnLayout
        {
            ProgressBar
            {
                id:magentaBar
                minimumValue: 0
                maximumValue: 100
                value: 50
                orientation: Qt.Vertical
                style:ProgressBarStyle
                {
                    background: Rectangle
                    {
                        implicitWidth: 300
                        implicitHeight: 100
                        color:"transparent"
                        border.color:"black"
                    }
                    progress: Rectangle
                    {
                        id:magentaRec
                        color: "magenta"
                        border.color:"black"
                    }
                }
            }

            Label
            {
                id:labelIdMagenta
                text:"Id cartucho"
            }

            Label
            {
                id:labelColorMagenta
                text: magentaRec.color
            }

            Label
            {
                id:labelNivelMagenta
                text: magentaBar.value
            }

            Label
            {
                id:labelCapacidadMagenta
                text: "Capacidad"
            }

            Label
            {
                id:labelFechaMagenta
                text:"Fecha"
            }
        }

        ColumnLayout
        {
                ProgressBar
                {
                    id:yellowBar
                    minimumValue: 0
                    maximumValue: 100
                    value: 50
                    orientation: Qt.Vertical
                    style:ProgressBarStyle
                    {
                        background: Rectangle
                        {
                            implicitWidth: 300
                            implicitHeight: 100
                            color:"transparent"
                            border.color:"black"
                        }
                        progress: Rectangle
                        {
                            id:yellowRec
                            color: "yellow"
                            border.color:"black"
                        }
                    }
                }

                Label
                {
                    id:labelIdYellow
                    text:"Id cartucho"
                }

                Label
                {
                    id:labelColorYellow
                    text: yellowRec.color
                }

                Label
                {
                    id:labelNivelYellow
                    text: yellowBar.value
                }

                Label
                {
                    id:labelCapacidadYellow
                    text: "Capacidad"
                }

                Label
                {
                    id:labelFechaYellow
                    text:"Fecha"
                }
        }


        ColumnLayout
        {
                ProgressBar
                {
                    id:blackBar
                    minimumValue: 0
                    maximumValue: 100
                    value: 50
                    orientation: Qt.Vertical
                    style:ProgressBarStyle
                    {
                        background: Rectangle
                        {
                            implicitWidth: 300
                            implicitHeight: 100
                            color:"transparent"
                            border.color:"black"
                        }
                        progress: Rectangle
                        {
                            id:blackRec
                            color: "black"
                            border.color:"black"
                        }
                    }
                }

                Label
                {
                    id:labelIdBlack
                    text:"Id cartucho"
                }

                Label
                {
                    id:labelColorBlack
                    text: blackRec.color
                }

                Label
                {
                    id:labelNivelBlack
                    text: blackBar.value
                }

                Label
                {
                    id:labelCapacidadBlack
                    text: "Capacidad"
                }

                Label
                {
                    id:labelFechaBlack
                    text:"Fecha"
                }
        }

*/
    }
}
