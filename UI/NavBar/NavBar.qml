import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property string hoverDarkColor

    id: navBar

    function updateButtonHighlight() {
        const status = BookManager.getStringStatus()
        readingLink.highlighted = readingLink.text === status
        finishedLink.highlighted = finishedLink.text === status
        toReadLink.highlighted = toReadLink.text === status
    }

    // Reading
    NavButton {
        id: readingLink
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        text: "Reading"
        onClicked: {
            BookManager.changeStatus("Reading")
            updateButtonHighlight()
        }
        highlighted: true
    }

    // Finished
    NavButton {
        id: finishedLink
        anchors {
            top: readingLink.bottom
            left: parent.left
            right: parent.right
        }
        text: "Finished"
        onClicked: {
            BookManager.changeStatus("Finished")
            updateButtonHighlight()
        }
    }

    // To Read
    NavButton {
        id: toReadLink
        anchors {
            top: finishedLink.bottom
            left: parent.left
            right: parent.right
        }
        text: "To Read"
        onClicked: {
            BookManager.changeStatus("To Read")
            updateButtonHighlight()
        }
    }
}
