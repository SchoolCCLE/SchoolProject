import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Rectangle {
    id: rootPH;
    width: 600;
    height: 200;


    RowLayout {
        spacing: 20;
        ColumnLayout{

            Rectangle{
                id: c1;
                height: 100;
                Layout.fillWidth: true;
                color: "cyan";
            }
            Text{

                text: "Cyan 1";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: c2;
                height: 100;
                Layout.fillWidth: true;
                color: "cyan";
            }
            Text{
                text: "Cyan 2";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: m1;
                height: 100;
                Layout.fillWidth: true;
                color: "#FF00FF";
            }
            Text{

                text: "Magenta 1";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: m2;
                height: 100;
                Layout.fillWidth: true;
                color: "#FF00FF";
            }
            Text{
                text: "Magenta 2";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: y1;
                height: 100;
                Layout.fillWidth: true;
                color: "yellow";
            }
            Text{
                text: "Yellow 1";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: y2;
                height: 100;
                Layout.fillWidth: true;
                color: "yellow";
            }
            Text{
                text: "Yellow 2";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: k1;
                height: 100;
                Layout.fillWidth: true;
                color: "black";
            }
            Text{
                text: "Black 1";
                font.bold: true;
            }
        }
        ColumnLayout{
            Rectangle{
                id: k2;
                height: 100;
                Layout.fillWidth: true;
                color: "black";
            }
            Text{
                text: "Black 2";
                font.bold: true;
            }
        }
    }
}
