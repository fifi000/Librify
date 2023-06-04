import QtQuick 2.15
import QtQuick.Controls 2.15

BookForm {
    property int bookId

    id: bookFormDialog
    title: "Edit Book"

    onAccepted: {
        BookManager.updateBook(bookId, bookTitle, bookAuthor, bookDescription,
                               bookCoverPath, readingStatus)
        close()
    }

    loader.sourceComponent: editButtonComponent

    Component {
        id: editButtonComponent
        Row {
            layoutDirection: Qt.RightToLeft
            Button {
                text: "Submit"
                onClicked: {
                    if (bookFormDialog.isFormValid()) {
                        bookFormDialog.accepted()
                    }
                }
            }
        }
    }
}
