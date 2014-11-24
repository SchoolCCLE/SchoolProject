import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1



ApplicationWindow {
    signal signalsetuser(var nick, var fullname,var pass);
    id: root;
    visible: true
    width: 640
    height: 480
    title: qsTr("Añadir Primer Usuario")
        Column
        {
            id: firstColumn
            width: 300
            height: 500
            anchors.verticalCenter: parent
            anchors.horizontalCenter: parent
            Component.onCompleted: console.log("Completed Running!")
                 Rectangle {
                     Component.onCompleted: console.log("Nested Completed Running!")
                 }
                 Label
                 {
                     text: "Introduce un nombre de usuario"
                 }

                 TextField
                         {
                             id:nickname
                             anchors.left: parent.left;
                             anchors.right: parent.right;
                         }
                 Label
                 {
                     text: "Introduce un nombre completo"
                 }

                 TextField
                         {
                             id:fullName
                             anchors.left: parent.left;
                             anchors.right: parent.right;
                         }

                 Label
                 {
                     text: "Introduce una contraseña"
                 }
                 TextField
                         {
                             id:password
                             anchors.left: parent.left;
                             anchors.right: parent.right;
                         }

            Button
            {
                id: addUser
                text: "Añadir usuario"
                onClicked:
                {
                    root.signalsetuser(nickname.text, fullName.text, password.text);
                }
            }
        }




}
