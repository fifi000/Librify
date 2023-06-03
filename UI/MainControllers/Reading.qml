import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Controls 2.15

Rectangle {
    property int bookWidth: 180
    property int bookMaxHeight: 1.5 * bookWidth

    color: "royalblue"
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
                }
            }
        }
    }
}
