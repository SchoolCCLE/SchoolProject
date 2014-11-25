import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    id: header;

    width: 800;
    height: 200;

    color: "steelblue";

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
                Qt.quit();
        }
    }

    function pathImage( num )
    {
        if ( num == 0 )
            return "/home/jcoque/Desktop/Project 1/SchoolProject/SchoolPrinter/ldle.png";

        else if ( num == 1 )
            return "/home/jcoque/Desktop/Project 1/SchoolProject/SchoolPrinter/printing.png";

        else if ( num == 2 )
            return "/home/jcoque/Desktop/Project 1/SchoolProject/SchoolPrinter/warning.png";

        else if ( num == 3)
            return "/home/jcoque/Desktop/Project 1/SchoolProject/SchoolPrinter/error.png";
    }

}
