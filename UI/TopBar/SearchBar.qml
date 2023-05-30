import QtQuick 2.15
import QtGraphicalEffects 1.12
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    Rectangle {
        id: navigationSearchBar
        color: "white"
        radius: 5
        anchors.fill: parent

        // glass icon
        Image {
            id: loupeIcon
            height: parent.height * 0.45
            fillMode: Image.PreserveAspectFit
            anchors {
                left: parent.left
                leftMargin: 20
                verticalCenter: parent.verticalCenter
            }
            source: "qrc:/UI/assets/loupe.png"
        }

        // text edit
        TextField {
            id: searchTextEdit
            placeholderText: "Search"
            textColor: "#8F8D8D"
            font {
                family: appFontFamily
                pixelSize: 18
            }

            anchors {
                left: loupeIcon.right
                right: parent.right
                leftMargin: 20
                verticalCenter: parent.verticalCenter
            }

            style: TextFieldStyle {
                background: Rectangle {
                    anchors.fill: parent
                    border.width: 0
                }
            }
        }
    }

    DropShadow {
        anchors.fill: navigationSearchBar
        //horizontalOffset: 2
        //verticalOffset: 2
        radius: 8.0
        samples: 17
        color: "grey"
        source: navigationSearchBar
    }
}
