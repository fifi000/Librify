import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

BookForm {
    property int bookId

    id: bookFormDialog
    title: "Edit Book"

    onAccepted: {
        BookManager.updateBook(bookId, bookTitle, bookAuthor, bookDescription,
                               bookCoverPath, readingStatus)
        close()
    }

    MessageDialog {
        id: confirmationMsgBox
        title: "Confirm Deletion"
        icon: StandardIcon.Question
        text: "Are you sure you want to delete this book?"
        standardButtons: StandardButton.Yes | StandardButton.No

        onYes: {
            BookManager.deleteBook(bookId)
            bookFormDialog.close()
            close()
        }
    }

    loader.sourceComponent: editButtonComponent

    Component {
        id: editButtonComponent
        Row {
            layoutDirection: Qt.RightToLeft
            spacing: 20

            Button {
                text: "Submit"
                onClicked: {
                    if (bookFormDialog.isFormValid()) {
                        bookFormDialog.accepted()
                    }
                }
            }

            Button {
                text: "Delete"
                onClicked: {
                    confirmationMsgBox.open()
                }
            }
        }
    }
}
