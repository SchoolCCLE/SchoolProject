import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2


FileDialog {
    id: fileDia
    signal callAddJob(string ruta);
    title: "Please choose a file"
    onAccepted: {
        console.log("You chose: " + fileDialog.fileUrls)
        fileDia.callAddJob(fileDialog.fileUrl);
    }
    onRejected: {
        console.log("Canceled")

    }


}
