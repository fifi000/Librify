import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    property string hoverColor
    property int btnPadding: 20
    font {
        pixelSize: fontSize
        family: appFontFamily

    }
    background: Rectangle {
        id: bg
        anchors.fill: parent
        color: "transparent"
    }
    hoverEnabled: true
    onHoveredChanged: {
        if (hovered) {
            background.color = hoverColor
        } else {
            background.color = "transparent"
        }
    }
    padding: btnPadding
}
