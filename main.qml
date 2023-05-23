import QtQuick 2.15
import QtQuick.Window 2.15

import "UI/NavBar"

Window {
    //property string fontFamily: "Arial Rounded MT"
    property string appFontFamily: "Segoe UI"
    property int fontSize: 24

    width: 1280
    height: 720
    visible: true
    title: qsTr("Librify")

    NavBar {
        id: leftSideBar
        width: 140
        color: "purple"
        hoverDarkColor: "darkmagenta"

        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
    }
}
