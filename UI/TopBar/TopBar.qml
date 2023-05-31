import QtQuick 2.15

import "../BookForm"

Rectangle {
    property int sideMargine: 15
    id: upperBar

    SearchBar {
        id: searchBar
        height: parent.height * 0.6
        width: 300
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: sideMargine
        }
    }

    Image {
        id: plusBtn
        height: parent.height * 0.6
        fillMode: Image.PreserveAspectFit
        anchors {
            right: parent.right
            rightMargin: sideMargine * 2
            verticalCenter: parent.verticalCenter
        }
        source: "qrc:/UI/assets/plus.png"

        MouseArea {
            anchors.fill: plusBtn
            onClicked: {
                if (bookFormDialog.opened === false) {
                    bookFormDialog.open()
                }
            }
        }
    }

    BookForm {
        id: bookFormDialog

        onOpened: {
            bookFormDialog.bookTitle = ""
            bookFormDialog.bookAuthor = ""
            bookFormDialog.bookDescription = ""
            bookFormDialog.bookCover = null
            bookFormDialog.readingStatus = ""
        }

        onAccepted: {
            console.log("Book added succesfully")
            close()
        }
    }
}
