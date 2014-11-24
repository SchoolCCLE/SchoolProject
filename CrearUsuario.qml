import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.1

Dialog {
   width:300;
   height: 300;
   visible:true;
    ColumnLayout{
        anchors.fill:parent;
        Rectangle{
            id:rectNickName;
            height:50
            color:"transparent"
            Layout.fillWidth: true;
            Text{
                id:textNickName
                anchors{
                    left:parent.left;
                    leftMargin:20;
                }
                text:"Nickname: "

            }

            TextArea{
                id:textAreaNickName
                text:""
                anchors.left:textNickName.right;
                anchors.right: parent.right;
                height:30
            }
        }
        Rectangle{
            id:rectFullName;
            height:50
            color:"transparent"
            Layout.fillWidth: true;
            Text{
                id:textFullName
                anchors{
                    left:parent.left;
                    leftMargin:20;
                }
                text:"Full name: "
            }

            TextArea{
                id:textAreaFullName
                text:""
                anchors.left:textFullName.right;
                anchors.right: parent.right;

                height:30
            }
        }
        Rectangle{
            id:rectPass;
            height:50
            color:"transparent"
            Layout.fillWidth: true;
            Text{
                id:textPass
                anchors{
                    left:parent.left;
                    leftMargin:20;
                }
                text:"Password: "

            }

            TextArea{
                id:textAreaPass
                text:""
                anchors.left:textPass.right;
                anchors.right: parent.right;
                height:30
            }
        }
        Button{
            id:buttonCrear
            anchors.horizontalCenter: parent.horizontalCenter;
            text:"Crear"
            style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }
             }
         }
    }

}
