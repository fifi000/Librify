import QtQuick 2.15
import QtQuick.Controls 2.0
import test.test 1.0

Rectangle {
    color: "royalblue"

    Flow {
        anchors.fill: parent
        anchors.margins: 15
        spacing: 10

        Repeater {
            model: Books

            Image {
                height: 180
                fillMode: Image.PreserveAspectFit
                source: Qt.resolvedUrl(modelData.Picture)
            }
        }
    }
}
