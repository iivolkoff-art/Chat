import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import "C:/Users/Volkov/Documents/chat/ChatField.qml" as ChatField

Item {
    property string message: inputText.text
    id: inputField
    width: parent.width
    anchors.top: chatField.bottom
    anchors.bottom: parent.bottom
    Rectangle {
        id: inputFieldRectangle
        anchors.fill: parent
        Rectangle {
            id: inputTextRectangle
            height: parent.height
            width: parent.width
            color: backgroundColor

            TextInput  {
                id: inputText
                anchors.fill: parent
                anchors.leftMargin: 5
                color: "white"
                verticalAlignment: TextInput.AlignVCenter
                activeFocusOnPress: true // Добавляем это свойство
                //PlaceholderText: "message"

                Keys.onReturnPressed: {
                    chatField.message = inputText.text + "      |- Ivan";
                    inputText.text = "";
                    Qt.inputMethod.visible = true;
                }
                property string placeholderText: "Enter text here..."
                Text {
                    text: inputText.placeholderText
                    color: "#aaa"
                    anchors.fill: parent
                    visible: !inputText.text && !inputText.activeFocus
                }

            }
        }
        Rectangle {
            id: line
            anchors.bottom: inputFieldRectangle.top
            height: 1
            width: parent.width
            color: "grey"
        }
    }

//    onMessageChanged: {
//        if (message !== "") {
//            placeholderText.visible = false;
//        } else {
//            placeholderText.visible = true;
//        }
//    }
}
