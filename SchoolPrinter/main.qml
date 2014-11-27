import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import "Printheads"

Window {
    visible: true
    width: 920
    height: 720
    color:"darkgrey"
    id:rootWindow;
    signal conectador(int n, string f);



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
            color:"darkgrey"
            anchors.left: parent.left
            anchors.right: parent.right
            height: 100
            border.color: "black"
            border.width: 1

            states: [
                State {
                    name: "PRINTER"
                    when: _myModel.stateNumber === 2
                    PropertyChanges {target:imageHeader;source:"qrc:/images/printer.png"}
                },
                State {
                    name: "WARNING"
                    when: _myModel.stateNumber === 3
                    PropertyChanges {target:imageHeader;source:"qrc:/images/Warning.png"}
                },
                State {
                    name: "ERROR"
                    when: _myModel.stateNumber === 4
                    PropertyChanges {target:imageHeader;source:"qrc:/images/error.png"}
                }

            ]


                    //            Connections{
                    //                target: _
                    //            }

                    //            Connections
                    //                   {
                    //                       target: _myModel;
                    //                       stateNumberChanged:
                    //                       {
                    //                           if (_myModel.stateNumber == 1)
                    //                           {
                    //                               imageHeader.source="qrc:ok.png";
                    //                           }
                    //                           if (_myModel.stateNumber == 2)
                    //                           {
                    //                               imageHeader.source="qrc:printer.png";
                    //                           }
                    //                           if (_myModel.stateNumber == 3)
                    //                           {
                    //                               imageHeader.source="qrc:/Warning.png";
                    //                           }
                    //                           if (_myModel.stateNumber == 4)
                    //                           {
                    //                               imageHeader.source="qrc:/error.png";
                    //                           }else
                    //                           {
                    //                               imageHeader.source="qrc:/error.png";
                    //                           }
                    //                       }
                    //                   }
                    Image
                    {

                        id:imageHeader;
                        anchors.left: parent.left;
                        anchors.top:parent.top;
                        anchors.bottom: parent.bottom;

                        source:"qrc:/images/ok.png";

                        fillMode:Image.PreserveAspectFit;

                    }


                    Text{
                        text: "Printer Status"
                        anchors.centerIn: parent
                        font.pixelSize: 20
                    }
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
                        radius:6
                        border.color:"black"
                        color:"grey"
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
                        radius:6
                        border.color:"black"
                        color:"grey"
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
                        radius:6
                        border.color:"black"
                        color:"grey"
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Text{
                            text: "Cartridges"
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
                        radius:6
                        border.color:"black"
                        color:"grey"
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
                Cartridges{
                    //color: "white"

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: stack.pop();
                    }
                }

                property Component green :
                TareaManager{
                    //color: "green"

                    MouseArea
                    {
                        //anchors.fill: parent
                        onClicked: stack.pop();
                    }
                    onButtonOk: {
                        rootWindow.conectador(number,fileName)
                    }
                }

        }
