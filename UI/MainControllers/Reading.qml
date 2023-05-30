import QtQuick 2.15
import QtQuick.Controls 2.0

Rectangle {
    color: "royalblue"

    //    Label {
    //        anchors.centerIn: parent
    //        text: Books.length
    //    }
    Flow {
        anchors.fill: parent
        anchors.margins: 5
        spacing: 10

        Repeater {
            model: Books

            Button {
                text: modelData.Title
            }
        }
    }
}
