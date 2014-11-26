import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle
{
    id:rootInfoCartuchos;
    width: 800;
    height: 600;

    color: "#BDBDBD";

    GridLayout
    {
        id:gridCartuchos;
        anchors.fill:parent;

        columns: 4;

        Repeater
        {
            model:cartuchos_;

            delegate:      Cartucho{

                idColor: modelData.status ;
                colorCmyk: modelData.color;
                inkLevel: modelData.level;
                colorCapInk: modelData.capacity;
                myDate: modelData.installDate;
                levelImg: modelData.level;
                source: modelData.image;
            }
        }
    }
}
