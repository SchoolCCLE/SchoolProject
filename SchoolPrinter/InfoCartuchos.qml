import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle
{
    id:rootInfoCartuchos;
    width: 800;
    height: 600;

    GridLayout
    {
        id:gridCartuchos;
        anchors.fill:parent;

        Repeater
        {
            //model:_model.listaEnteracartuchos;

            delegate:
                Cartucho
            {
            id:infoCartuchoN;
            height: 100;
            width: 100;

//            idColor:
//            colorCmyk:
//            inkLevel:
//            colorCapInk:
//            myDate:
//            }
       }
    }
}
