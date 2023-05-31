import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Dialog {
    title: "Add Book"

    property string bookTitle: ""
    property string bookAuthor: ""
    property string bookDescription: ""
    property var bookCover: null
    property string readingStatus: ""

    width: parent.width / 3
    padding: 15

    Column {
        spacing: 7
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }

        // Title
        Label {
            text: "Title:"
        }
        TextField {
            id: titleField
            text: bookTitle
            onTextChanged: bookTitle = text
            anchors {
                left: parent.left
                right: parent.right
            }
        }

        // Author
        Label {
            text: "Author:"
        }
        TextField {
            id: authorField
            text: bookAuthor
            onTextChanged: bookAuthor = text
            anchors {
                left: parent.left
                right: parent.right
            }
        }

        // Description
        Label {
            text: "Description:"
        }
        TextArea {
            id: descriptionField
            text: bookDescription
            onTextChanged: bookDescription = text
            background: Rectangle {
                color: "transparent"
                border.color: "lightgray"
                border.width: 1
            }
            anchors {
                left: parent.left
                right: parent.right
            }
        }

        // Cover
        Label {
            text: "Cover:"
        }
        Item {
            anchors {
                left: parent.left
                right: parent.right
            }
            height: 100
            DropArea {
                id: coverDropArea
                anchors.fill: parent
                onEntered: {
                    if (drag.hasImage) {
                        bookCover = drag.image
                    }
                }
                onDropped: {
                    if (drag.hasImage) {
                        bookCover = drag.image
                    }
                }
                Rectangle {
                    anchors.fill: parent
                    border.width: 2
                    border.color: "gray"
                    color: "lightgray"
                    Image {
                        anchors.fill: parent
                        source: bookCover ? Qt.resolvedUrl(bookCover) : ""
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }
        }

        // Reading Status
        Label {
            text: "Reading Status:"
        }
        Row {
            Repeater {
                model: readingStatuses

                RadioButton {
                    text: modelData
                    checked: modelData === readingStatus
                    onClicked: {
                        readingStatus = modelData
                    }
                }
            }
        }

        // Submit Button
        Button {
            text: "Add Book"
            anchors {
                right: parent.right
            }

            onClicked: {
                if (titleField.text.trim() === "" || authorField.text.trim(
                            ) === "") {
                    // Display an error message if required fields are empty
                    console.log("Please enter the title and author.")
                } else {
                    // Emit a signal to notify the parent component about the new book
                    bookFormDialog.accepted()
                }
            }
        }
    }
}
