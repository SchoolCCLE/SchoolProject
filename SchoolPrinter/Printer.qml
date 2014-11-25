import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    id: printer;

    width: 800;
    height: 500;

    ColumnLayout {

        id: container;

        anchors.fill: parent;

        RowLayout {

            Layout.fillWidth: true;
            height: 100;

            Item {
                height: parent.height;
                Layout.fillWidth: true;
            }

            TextField {
                height: parent.height;
                Layout.fillWidth: true;

                text: "Printer state: " + _model.status;

                readOnly: true;
            }

            Item {
                height: parent.height;
                Layout.fillWidth: true;
            }
        }

        RowLayout {

            Layout.fillWidth: true;
            height: 100;

            Item {
                height: parent.height;
                Layout.fillWidth: true;
            }

            TextField {
                height: parent.height;
                Layout.fillWidth: true;

                text: "Running time: " + _model.time + " seconds";

                readOnly: true;
            }

            Item {
                height: parent.height;
                Layout.fillWidth: true;
            }
        }

        Item {

            id: mileto;

            Layout.fillHeight: true;
            Layout.fillWidth: true;

            ListModel {

                id: modelo;

                Repeater {

                    ListElement {

                        name: "Pepe";
                        number: "12345";
                        status: "Admin"
                        //name: userModel_;
                        //number: userModel_;
                        //status: userModel_;
                    }

                }

            }

            Rectangle {

                width: 180;
                height: 200;

                Component {

                    id: contactDelegate;

                    Item {
                        width: 180;
                        height: 80;

                        Column {
                            Text { text: '<b>Nick name: </b> ' + name }
                            Text { text: '<b>Full name: </b> ' + number }
                            Text { text: '<b>Status: </b>' + status }
                        }
                    }
                }

                ListView {
                    anchors.fill: parent;
                    model: modelo;
                    delegate: contactDelegate;
                    focus: true;
                }
            }

        }

    }

}
