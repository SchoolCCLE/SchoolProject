import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
Rectangle {
    id:rootCartucho;
    width: 100;
    height: 130;
    property alias idColor: textIdColor.text;
    property alias colorCmyk: textColorCmyk.text;
    property alias inkLevel: textInkLevel.text;
    property alias colorCapInk: textCapInk.text;
    property alias myDate: textDate.text;
    property alias source: imageHeader.source;
    property alias levelImg: capacidadCartucho.value;
    onInkLevelChanged: {
        console.log(inkLevel);
    }

    color:"lightsteelblue";
    RowLayout
    {
        id:rowLay;
        anchors.fill: parent;
        ColumnLayout
        {
            id: columnData;
            Image{
                id:imageHeader;
                Layout.fillHeight: true;
                height: 100;
                fillMode:Image.PreserveAspectFit;

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
            ProgressBar
            {
                id:capacidadCartucho;
                Layout.fillHeight: true;
                orientation: Qt.Vertical;
                maximumValue: 750;
                minimumValue: 0;
            }
        }
    }
}
