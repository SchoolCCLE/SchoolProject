import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Team 3 Proyect")

    ColumnLayout
    {
        anchors.fill:parent;
        anchors.margins: 5

        ColumnLayout
        {
            anchors.margins: 5

            Label
            {
                Layout.fillWidth: true
                Layout.minimumHeight: 60
                Layout.maximumHeight: 60

                Text
                {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Lista de usuarios"
                    font.pixelSize: 20
                }

            }

            ListView
            {
                id:listUsers
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.margins: 20

                Text
                {
                    id:textListUsers
                    text:"Usuario de prueba"
                }

                MouseArea
                {
                    id: mouseAreaListUsers
                    z: 1
                    hoverEnabled: false
                    anchors.fill: parent

                    onClicked:
                    {
                        console.log("test");
                        textListUsers.color="red"
                    }
                }
            }

            RowLayout
            {
                anchors.margins: 10
                Layout.maximumHeight: 100
                Layout.minimumHeight: 100
                Layout.fillWidth: true

                Rectangle
                {
                    anchors.fill: parent
                    color:"transparent"

                    Button
                    {
                        id:buttonAdd
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        text:"Add user"
                        //Habilitar solo para Admin
                    }

                    Button
                    {
                        id:buttonModify
                        anchors.centerIn: parent
                        anchors.verticalCenter: parent.verticalCenter

                        text:"Modify user"
                        //Habilitar solo para Admin
                    }

                    Button
                    {
                        id:buttonDelete
                        anchors.right: parent.right
                        anchors.rightMargin: 20
                        anchors.verticalCenter: parent.verticalCenter

                        text:"Delete user"
                        //Habilitar solo para Admin
                    }
                }



            }
        }
    }
}
