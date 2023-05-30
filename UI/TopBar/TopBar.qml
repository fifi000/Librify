import QtQuick 2.15

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
    }
}
