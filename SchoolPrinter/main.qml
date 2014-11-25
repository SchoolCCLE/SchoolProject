import QtQuick 2.3
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle {
    width: 800
    height: 600
    anchors.centerIn: parent

    Header
    {
        id:myHeader;
        anchors.top:parent.top;
        //MyHeader
    }
    CuerpoBotones
    {
        anchors.top:myHeader.bottom;
    }





}
