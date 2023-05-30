import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Controls 2.15

Rectangle {
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
                model: Books

                Image {
                    height: 250
                    fillMode: Image.PreserveAspectFit
                    source: Qt.resolvedUrl(modelData.Picture)
                }
            }
        }
    }
}
