import QtQuick 2.0
import QtQuick.Dialogs 1.1

MessageDialog {
    id: errorDialog;
    title: "Error:"
    icon: StandardIcon.Critical
    text: "Error: User not found"
    detailedText: "The introduced user isn't registered or user/password incorrect."
    standardButtons: StandardButton.Ok
    Component.onCompleted: visible = true
    onAccepted: close();
}
