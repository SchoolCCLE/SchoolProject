import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    id: main;

    width: 800
    height: 600

    anchors.centerIn: parent;

    color: "steelblue"

    ColumnLayout {

        id: container;

        Loader{
            source: "Header.qml";
        }

        RowLayout {
            id: botonera;

            height: 200;
            width: main.width;

            Item{
                height: 200;
                Layout.fillWidth: true;
            }

            Button {
                width: 200;
                height: 100;

                text : "PRINTER";

                onClicked:
                    cargaPrinter.source = "Printer.qml";
            }

            Loader {
                id: cargaPrinter;
            }

            Item{
                height: 200;
                Layout.fillWidth: true;
            }

            Button {
                width: 200;
                height: 100;

                text : "PRINTHEADS";

                onClicked:
                    cargaPrinteheads.source = "PrintHeads.qml";

            }

            Loader {
                id: cargaPrinteheads;
            }

            Item{
                height: 200;
                Layout.fillWidth: true;
            }
        }
    }


}
