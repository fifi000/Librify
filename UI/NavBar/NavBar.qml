import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property string hoverDarkColor

    id: navBar

    // Reading
    NavButton {
        id: readingLink
        hoverColor: hoverDarkColor
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        text: "Reading"
    }

    // Finished
    NavButton {
        id: finishedLink
        hoverColor: hoverDarkColor
        anchors {
            top: readingLink.bottom
            left: parent.left
            right: parent.right
        }
        text: "Finished"
    }

    // To Read
    NavButton {
        id: toReadLink
        hoverColor: hoverDarkColor
        anchors {
            top: finishedLink.bottom
            left: parent.left
            right: parent.right
        }
        text: "To Read"
    }
}
