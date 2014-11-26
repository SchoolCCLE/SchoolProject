import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import "Printheads"

Window {
    visible: true
    width: 800
    height: 600


    StackView
    {
        id: stack
        initialItem: homescreen

        delegate: StackViewDelegate {
            function transitionFinished(properties)
            {
                properties.exitItem.opacity = 1
            }

            property Component pushTransition: StackViewTransition {
                PropertyAnimation {
                    target: enterItem
                    property: "opacity"
                    from: 0
                    to: 1
                }
                PropertyAnimation {
                    target: exitItem
                    property: "opacity"
                    from: 1
                    to: 0
                }
            }
        }
    }

    property Component homescreen : Item {
        Rectangle{
            id: header
            anchors.left: parent.left
            anchors.right: parent.right
            height: 100
            border.color: "black"
            border.width: 1
            Image
            {
                anchors.left: parent.left
                height: parent.height
                width: 100
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

            Text{
                text: pe_.stateText
                anchors.centerIn: parent
                font.pixelSize: 20
            }
            Button{
                text: "Exit"
                anchors.right: parent.right
                height: parent.height
                width: 100
                onClicked: Qt.quit()
            }
        }

        GridLayout {

            //anchors.fill: parent
            anchors.top: header.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.topMargin: 20
            anchors.bottomMargin: 20
            anchors.leftMargin: 20
            anchors.rightMargin: 20

            columns: 2
            rowSpacing: 20
            columnSpacing: 20

            Rectangle{
                border.color:"red"

                Layout.fillHeight: true
                Layout.fillWidth: true

                Text{
                    text: "Printer"
                    anchors.centerIn: parent
                    font.pixelSize: 20
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: stack.push(red);
                }
            }

            Rectangle{
                border.color:"red"

                Layout.fillHeight: true
                Layout.fillWidth: true

                Text{
                    text: "Printheads"
                    anchors.centerIn: parent
                    font.pixelSize: 20
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: stack.push(blue);
                }
            }

            Rectangle{
                border.color:"red"

                Layout.fillHeight: true
                Layout.fillWidth: true

                Text{
                    text: "App 3"
                    anchors.centerIn: parent
                    font.pixelSize: 20
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: stack.push(white);
                }
            }

            Rectangle{
                border.color:"red"

                Layout.fillHeight: true
                Layout.fillWidth: true

                Text{
                    text: "App 4"
                    anchors.centerIn: parent
                    font.pixelSize: 20
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: stack.push(green);
                }
            }
        }
    }


    property Component blue :
        Printheads{
        //color: "blue"

        MouseArea
        {
            anchors.fill: parent
            onClicked: stack.pop();
        }
    }

    property Component red :
        Rectangle{
        color: "red"

        MouseArea
        {
            anchors.fill: parent
            onClicked: stack.pop();
        }
    }

    property Component white :
        Rectangle{
        color: "white"

        MouseArea
        {
            anchors.fill: parent
            onClicked: stack.pop();
        }
    }

    property Component green :
        Rectangle{
        color: "green"

        MouseArea
        {
            anchors.fill: parent
            onClicked: stack.pop();
        }
    }
}
