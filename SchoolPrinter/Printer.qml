import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    width: 100
    height: 62

    Rectangle{
        id: printerState;
        color: "grey";
        anchors.top:parent.top;
        anchors.left:parent.left;
        anchors.right: parent.right;
        height: 22;
        RowLayout{
            anchors.fill: parent;
            ColumnLayout{
                Label{
                    text:"Type of Printer:"
                }
                Text {
                    id: type
                    text: _myModel.printerType;
                }
                Label{
                    text:"State of Printer:"
                }
                Text {
                    id: state
                    text: _myModel.stateText;
                }
            }
            Label{
                text: "Time Started"
            }
            Text{
                id:time
                text: _myModel.timeStarted;

            }
        }


    }

}
