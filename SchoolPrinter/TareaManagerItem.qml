import QtQuick 2.0
import QtQuick.Layouts 1.1


    RowLayout
    {
        width:parent.width
        RowLayout
        {
            Image
            {
                id: fileIcon
                width:60
                height: 60
                fillMode: Image.PreserveAspectFit
                source:
                    ficheroDialog.fileUrl
            }
        }


        RowLayout
        {
            id: nameRect
            Text {
                id: name
                text: ficheroDialog.fileUrl
            }
        }
        RowLayout
        {
            id: pTimeRect;

                Text {
                id: pTime
                text: qsTr("Time")
            }
        }
        RowLayout
        {
            id:statusRect
            Text {
                id: status
                text: qsTr("Estado")
            }
        }
    }



