import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {

    width: 640;
    height: 480;

    RowLayout {

        Item {
            width: 40;
            Layout.fillHeight: true;
        }

        Rectangle {

            width: 100;
            height: 300;

            color: "cyan";

            Text {
                text: "Cyan level";

                anchors.bottom: parent.bottom;
            }
        }

        Item {
            width: 40;
            Layout.fillHeight: true;
        }

        Rectangle {

            width: 100;
            height: 300;

            color: "magenta";

            Text {
                text: "Magenta level";

                anchors.bottom: parent.bottom;
            }
        }

        Item {
            width: 40;
            Layout.fillHeight: true;
        }

        Rectangle {

            width: 100;
            height: 300;

            color: "yellow";

            Text {
                text: "Yellow level";

                anchors.bottom: parent.bottom;
            }
        }

        Item {
            width: 40;
            Layout.fillHeight: true;
        }

        Rectangle {

            width: 100;
            height: 300;

            color: "black";

            Text {
                text: "Black level";

                anchors.bottom: parent.bottom;
            }
        }

        Item {
            width: 40;
            Layout.fillHeight: true;
        }
    }
}
