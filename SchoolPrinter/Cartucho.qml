import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
Rectangle {
    id:rootCartucho;
    width: 800;
    height: 600;
    property string idColor: textIdColor.text;
    property string colorCmyk: textColorCmyk.text;
    property string inkLevel: textInkLevel.text;
    property string colorCapInk: textCapInk.text;
    property string myDate: textDate.text;
    color:"lightsteelblue";
    RowLayout
    {
        id:rowLay;
        anchors.fill: parent;
        ColumnLayout
        {
            id: columnData;
            RowLayout
            {
                id: rowImagen;
                Layout.fillWidth: true;
                Image
                {
                    id: imageCartucho;
                    height:60;
                    width:60;
                    source:"idle.png";
                    fillMode:Image.PreserveAspectFit;
                }
            }
            RowLayout
            {
                id:rowIdColor;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                Text
                {
                    id:textIdColor;
                    text:"id";
                }
            }
            RowLayout
            {
                id:rowColorCmyk;
                Layout.fillWidth: true;
                Text
                {
                    id:textColorCmyk;
                    text:"Color CMYK";
                }
            }
            RowLayout
            {
                id:rowInkLevel;
                Layout.fillWidth: true;
                Text
                {
                    id:textInkLevel;
                    text:"Ink Level";
                }
            }
            RowLayout
            {
                id:rowCapInk;
                Layout.fillWidth: true;
                Text
                {
                    id:textCapInk;
                    text:"Capacidad";
                }
            }
            RowLayout
            {
                id:rowDate;
                Layout.fillWidth: true;
                Text
                {
                    id:textDate;
                    text:"Fecha";
                }
            }
        }
        ColumnLayout
        {
            id: columnCartucho;
            Rectangle
            {
                id:capacidadCartucho;
                anchors.fill: parent;
                anchors.margins: 10;
                color:"blue";
            }
        }
    }
}
