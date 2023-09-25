import QtQuick 2.15
import QtQuick.Window 2.15

Item{
    property color backgroundColor: "#343838"
    property color buttonColor: "#008C9E"
    id: mainWindow
    anchors.fill: parent
    Rectangle{
        anchors.fill: parent
        color: backgroundColor
        ChatField {
            id: chatField
            anchors.top: parent.top
            width: parent.width
            height: parent.height * 0.95
        }
        InputField {
            id: inputField
            width: parent.width
            anchors.top: chatField.bottom
            anchors.bottom: parent.bottom
        }
    }
}
