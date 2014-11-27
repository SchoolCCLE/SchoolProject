import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Rectangle {
    id:footer;
    property alias width: footer.width;
    property alias visibleDialog: dialogFile.visible;
    property var archive: "";
    height:100;
    color:"grey"

    RowLayout{
        anchors.fill:parent;
        Button{
            text: "Exit"
            anchors.right: parent.right
            height: parent.height
            style:ButtonStyle {
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 25
                    border.width: control.activeFocus ? 2 : 1
                    border.color: "#888"
                    radius: 6
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "darkgrey" : "grey" }
                        GradientStop { position: 1 ; color: control.pressed ? "grey" : "darkgrey" }
                    }
                }
            }
            width: 100
            onClicked:{
                visibleDialog=true;
            }
        }
    }


    FileDialog{
        id:dialogFile
        title:"Seleccione archivo a imprimir: "
        onAccepted:{
            archive=dialogFile.fileUrl;
            visibleDialog=false;
        }
        onRejected:{
            visibleDialog=false;
        }
    }
}
