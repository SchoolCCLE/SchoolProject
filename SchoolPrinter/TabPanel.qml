import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: rootTabPanel;
    width: 500;
    height: 500;

    TabView {
        Tab {
            title: "Printing";
            ListView{
                id: listPrinting;
                anchors.fill: rootTabPanel;

                model: _jobs.jobs;
                delegate: JobItem {

                }
            }
        }

        Tab {
            title: "Printed";
            ListView {
                id: listPrinted;
                anchors.fill: rootTabPanel;

            }
        }
    }
}
