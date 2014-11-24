import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
  width: 640
  height: 480
  Column {
    anchors.centerIn: parent
    spacing: 16
    Column {
      spacing: 4
      Text { text: "Username:" }
      TextField{id: fieldUserName}
    }
    Column {
      spacing: 4
      Text { text: "Password:" }
      TextField{id: fieldPass}
    }
    Row {
      spacing: 16
      anchors.horizontalCenter: parent.horizontalCenter
      Button { text: "Login"; onClicked: console.log("login") }
      Button { text: "Close"; onClicked: Qt.quit(); }
    }
  }

}

