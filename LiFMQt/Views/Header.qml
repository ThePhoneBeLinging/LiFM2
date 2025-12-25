import QtQuick 6.5
import QtQuick.Controls 6.5

Rectangle {
    id: header
    width: parent.width
    height: 50
    color: "lightgray"

    Text {
        id: titleText
        text: "LiFMQt"
        anchors.centerIn: parent
        font.pixelSize: 24
        font.bold: true
    }
}