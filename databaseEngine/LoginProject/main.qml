import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Window {
    visible: true
    width: 600
    height: 600

    Rectangle {
        id: bacground;

        anchors.fill: parent;

        color: "grey";
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        GridLayout {
            id: layout;

            columns: 2;

            Layout.fillHeight: true;
            Layout.fillWidth: true;

            ColumnLayout {

                id: loginLayout;

                spacing: 3;

                Layout.minimumWidth: 200;
                Layout.fillWidth: true;
                Layout.fillHeight: true;

                TextEdit {
                    id: nickFld;

                    width:150;
                    height:20;

                    text: "Nickname";

                }

                TextEdit {
                    id: passFld;

                    width:150;
                    height:20;

                    text: "Password";

                }

                Button {
                    id: loginBtn;

                    width:50;
                    height:50;

                    text: "Login";

                    onClicked: {
                        //Check data is correct
                        if (comprobarDatos(nickFld.text.toString(), passFld.text.toString())) {
                            console.debug("Login correcto");
                        } else {
                            console.debug("Login incorrecto");
                        }
                    }
                }

            }

            ColumnLayout {

                id: regLayout;

                spacing: 3;

                Layout.minimumWidth: 200;
                Layout.fillWidth: true;
                Layout.fillHeight: true;

                Label {
                    id: titleRegLbl;
                    text: qsTr("Register:");
                }

                TextEdit {
                    id: fullNameRegFld;

                    width:150;
                    height:20;

                    text: "Full Name";

                }

                TextEdit {
                    id: nickRegFld;

                    width:150;
                    height:20;

                    text: "Nickname";

                }

                TextEdit {
                    id: passRegFld;

                    width:150;
                    height:20;

                    text: "Password";

                }

                Label {
                    id: rollsLbl;
                    text: qsTr("Rolls:");
                }

                ExclusiveGroup { id: rollsGroup }

                CheckBox {
                    id: userRole;

                    text: qsTr("User");

                    exclusiveGroup: rollsGroup;
                }

                CheckBox {
                    id: adminRole;

                    text: qsTr("Admin");

                    checked: true
                    exclusiveGroup: rollsGroup;
                }

                Button {
                    id: registerBtn;

                    width:50;
                    height:50;

                    text: "Register";

                    onClicked: {
                        //Llamar a DataBaseController añadirUser()
                        //var rolls = rolls
                        //_dbmodel.addUser(fullNameRegFld.text, nickRegFld.text, passRegFld.toString(), rolls );

                    }
                }

            }
        }
    }

}
