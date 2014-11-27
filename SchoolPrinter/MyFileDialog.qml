import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2


FileDialog {
    id: fileDialog
    signal addJob(string ruta);
    title: "Please choose a file"
    onAccepted: {
        console.log("You chose: " + fileDialog.fileUrls)
        fileDialog.addJob(fileDialog.fileUrl);
    }
    onRejected: {
        console.log("Canceled")

    }


}
