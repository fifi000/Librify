import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

import "UI/NavBar"
import "UI/TopBar"
import "UI/MainControllers"

Window {
    //property string fontFamily: "Arial Rounded MT"
    property string appFontFamily: "Segoe UI"
    property int fontSize: 24

    property variant readingStatuses: ["Reading", "To Read", "Finished"]

    id: mainWindow
    width: 1280
    height: 720
    minimumWidth: 600
    minimumHeight: 300
    visible: true
    title: qsTr("Librify")

    NavBar {
        id: leftSideBar
        width: 140
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
        color: "lightgrey"
    }

    TopBar {
        id: upperBar
        height: 72
        anchors {
            left: leftSideBar.right
            right: parent.right
            top: parent.top
        }
    }

    Item {
        anchors {
            left: leftSideBar.right
            right: parent.right
            top: upperBar.bottom
            bottom: parent.bottom
        }

        Loader {
            id: contentLoader
            source: "qrc:/UI/MainControllers/Reading.qml"
            anchors.fill: parent
        }
    }
}
