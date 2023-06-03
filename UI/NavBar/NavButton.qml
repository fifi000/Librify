import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    property string hoverColor
    property int btnPadding: 20
    hoverEnabled: true
    padding: btnPadding

    font {
        pixelSize: fontSize
        family: appFontFamily
    }
    background: Rectangle {
        id: bg
        anchors.fill: parent
        color: "transparent"
    }
    onHighlightedChanged: {
        if (highlighted) {
            background.color = "darkgray"
        } else {
            background.color = "transparent"
        }
    }
}
