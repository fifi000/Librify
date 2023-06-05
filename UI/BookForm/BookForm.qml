import QtQuick 2.15
import QtQuick.Controls 2.15

Dialog {
    property string bookTitle: ""
    property string bookAuthor: ""
    property string bookDescription: ""
    property string readingStatus: BookManager.getStringStatus()
    property string bookCoverPath: ""

    property alias loader: mainColumnLoader

    function isFormValid() {
        return bookTitle !== "" && bookAuthor !== "" && readingStatus !== ""
    }

    width: 430
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
            text: "Title"
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
            text: "Author"
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
            text: "Description"
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
            text: "Cover"
        }
        Item {
            anchors {
                left: parent.left
                right: parent.right
            }
            height: 180
            DropArea {
                id: coverDropArea
                anchors.fill: parent
                onDropped: {
                    bookCoverPath = ""
                    if (drop.hasUrls) {
                        bookCoverPath = drop.urls[0]
                    }
                }
                Rectangle {
                    anchors.fill: parent
                    anchors {
                        leftMargin: parent.width * 0.2
                        rightMargin: parent.width * 0.2
                    }
                    border.width: 2
                    border.color: "gray"
                    color: "lightgray"
                    Image {
                        id: coverField
                        anchors.fill: parent
                        source: (bookCoverPath !== "") ? Qt.resolvedUrl(
                                                             bookCoverPath) : ""
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }
        }

        // Reading Status
        Label {
            text: "Reading Status"
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

        Loader {
            id: mainColumnLoader
            anchors {
                left: parent.left
                right: parent.right
            }
        }
    }
}
