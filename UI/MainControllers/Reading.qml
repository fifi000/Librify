import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Controls 2.15

import "../BookForm"

Rectangle {
    property int bookWidth: 180
    property int bookMaxHeight: 1.5 * bookWidth

    ScrollView {
        clip: true
        anchors.fill: parent
        padding: 15

        Flow {
            id: content
            width: parent.parent.width
            spacing: 10

            Repeater {
                model: BookManager.Books

                Image {
                    width: bookWidth
                    fillMode: Image.PreserveAspectFit
                    source: Qt.resolvedUrl(modelData.Picture)

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            editBookForm.bookId = modelData.Id
                            editBookForm.bookTitle = modelData.Title
                            editBookForm.bookAuthor = modelData.Author
                            editBookForm.bookDescription = modelData.Description
                            editBookForm.bookCoverPath = modelData.Picture
                            //title, author, description, readingStatus, coverPath
//                            editBookForm.initForm(modelData.Title, modelData.Author,
//                                                  modelData.Description, "", modelData.Picture)
                            editBookForm.open()
                        }
                    }
                }
            }
        }
    }

    EditBookForm {
        id: editBookForm
    }
}
