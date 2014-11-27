import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

Rectangle
{
    width: 800
    height: 600
    anchors.margins: 10
    property alias tipo: tipo.source
    property alias nombre: nombre.text
    property alias tiempo: tiempo.text
    property alias estado: estado.text
    property alias consumoCyan: cyan.text
    property alias consumoMagenta: magenta.text
    property alias consumoYellow: yellow.text
    property alias consumoBlack: black.text

    ListView
    {
        id:listaJobs
        Layout.fillHeight: true
        Layout.fillWidth: true
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true

        RowLayout
        {
            spacing: 2
            Image
            {
                id:tipo
                width:40
                height:40
                source: "JPG.png"
            }

            Label
            {
                id:nombre
                text: "Nombre archivo"
            }

            Label
            {
                id:tiempo
                text: "Tiempo impresión"
            }

            Label
            {
                id:estado
                text: "Estado"
            }

            Label
            {
                id:cyan
                text: "Consumo Cyan"
            }

            Label
            {
                id:magenta
                text: "Consumo Magenta"
            }

            Label
            {
                id:yellow
                text: "Consumo Amarillo"
            }

            Label
            {
                id:black
                text: "Consumo Negro"
            }
        }
    }
}
