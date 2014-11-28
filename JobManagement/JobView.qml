import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QtQuick.Layouts 1.1

Window {
    visible: true
    width: 800
    height: 600

    TabView
    {
        anchors.fill: parent

        clip: true
        style: CustomTabViewStyle{}

        Tab {
            title: "Pending"

            clip: true
            sourceComponent: pendingComponent
        }
        Tab {
            title: "Printed"

            clip: true
            sourceComponent: printedComponent
        }
    }

    Component {
        id: printedComponent

        ListView
        {
            id: printedList
            anchors.fill: parent

            model: list
            delegate: Loader {

                width: parent.width
                height: childrenRect.height

                active: modelData.printed
                source: "qrc:/JobDelegate.qml"
                onLoaded:
                {
                    item.model = modelData
                }
            }
        }
    }

    Component {
        id: pendingComponent

        ListView
        {
            id: pendingList
            anchors.fill: parent

            model: list

            delegate: Loader {
                active: !modelData.printed
                source: "qrc:/JobDelegate.qml"

                width: parent.width
                height: childrenRect.height

                onLoaded:
                {
                    item.model = modelData
                }
            }

            add: Transition {
                NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 400 }
                NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 400 }
            }

            displaced: Transition {
                NumberAnimation { properties: "x,y"; duration: 400; easing.type: Easing.OutBounce }
            }

        }

    }

}
