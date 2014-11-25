import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    id: header;

    signal exit();

    anchors.top: parent.top;
    anchors.left: parent.left;
    anchors.right: parent.right;

    width: parent.width;
    height: 200;

    RowLayout {

        id:containerHeader;

        anchors.fill: header;

        Image {
            id: iconoHeader;

            fillMode: Image.PreserveAspectFit;

            asynchronous: true;

            source: pathImage( _model.int_status );
        }

        Text {
            id: textHeader;

            Layout.fillWidth: true;
            height: header.height;

            text: _model.status;
        }

        Button {
            id: exitApp;

            width: 200;
            height: 100;

            text: "EXIT";

            onClicked:
                root.exit();
        }
    }

    function pathImage( num )
    {
        if ( num == 1 )
            return "/home/jcoque/Downloads/ldle.png";

        else if ( num == 2 )
            return "/home/jcoque/Downloads/printing.png";

        else if ( num == 3 )
            return "/home/jcoque/Downloads/warning.png";

        else
            return "/home/jcoque/Downloads/error.png";
    }

}
