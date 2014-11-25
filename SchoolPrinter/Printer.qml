import QtQuick 2.3
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle
{
    width: 400
    height: 300

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 10

        RowLayout
        {
            Layout.fillWidth: true

            RowLayout
            {
                id: header;
                anchors.top: parent.top;
                anchors.left: parent.left;
                anchors.right: parent.right;
                Layout.minimumHeight: 60
                Layout.maximumHeight: 60

                Image
                {
                    id: image;
                    Layout.maximumHeight: 30
                    Layout.maximumWidth: 30
                    anchors.left: header.left;
                    source:
                    {
                        if(pe_.stateNum == 0)
                        {
                            source = "ok-icon.png"
                            console.log("0")
                        }
                        else if(pe_.stateNum == 1)
                        {
                            source = "printing-icon.png"
                            console.log("1")
                        }
                        else if(pe_.stateNum == 2)
                        {
                            source = "warning-icon.png"
                            console.log("2")
                        }
                        else if(pe_.stateNum == 3)
                        {
                            source = "error-icon.png"
                            console.log("3")
                        }
                    }
                    fillMode: Image.PreserveAspectFit
                }

                Text
                {
                    id: status;
                    Layout.fillWidth: true;
                    text: pe_.stateText
                }


                Label
                {
                    id:labelTiempo
                    width: 40
                    text:"Tiempo:"
                }

                Text
                {
                    id: textTiempo;
                    Layout.fillWidth: true;
                    text: pe_.tiempo
                }
            }
        }

        ListView
        {
            id:listaUsuarios
            Layout.fillWidth: true
            Layout.fillHeight: true
            anchors.margins: 30

            RowLayout
            {
                Layout.fillWidth: true
                Layout.fillHeight: true

                Text
                {
                    id:nickname
                    anchors.verticalCenter: parent.verticalCenter
                    text: "User nickname"
                }

                Text
                {
                    id:fullname
                    anchors.verticalCenter: parent.verticalCenter
                    text: "User full name"
                }

                Text
                {
                    id:tipoUsuario
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Admin"
                }
            }

        }
    }
}
