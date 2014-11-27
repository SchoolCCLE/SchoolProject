import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
    id: rootTabPanel;
    width: 500;
    height: 500;

    TabView {

        anchors.fill: parent;
        Tab {
            title: "Printing";
            ListView{
                id: listPrinting;
                anchors.fill: rootTabPanel;

                model: _jobs.jobs;
                delegate: RowLayout{
                    id:rowJob

                    Text{
                        id:type
                        text: _jobs.jobs[index].jobType;
                    }

                    Text{
                        id: name
                        text: _jobs.jobs[index].jobName;
                    }

                    Text{
                        id:time
                        text: _jobs.jobs[index].timePrinting;
                    }

                    Text{
                        id:status
                        text: _jobs.jobs[index].jobState;
                    }

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
