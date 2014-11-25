import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    anchors.fill: parent;
    Rectangle
    {
        id: printerInfo;
        TextArea
        {
            id: textPrinterInfo;

        }
    }

    Rectangle
    {
        id: usersInfo;
        TextArea
        {
            id: textUserInfo;

        }
    }
}
