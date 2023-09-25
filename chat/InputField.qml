import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import com.myapp 1.0

import "C:/Users/Volkov/Documents/chat/ChatField.qml" as ChatField //замените на свой путь

Item {
    property string message: inputText.text
    id: inputField
    Client {
        id: client
    }
    Rectangle {
        id: inputFieldRectangle
        anchors.fill: parent
        Rectangle {
            id: inputTextRectangle
            height: parent.height
            width: parent.width
            color: backgroundColor


            TextInput {
                id: inputText
                anchors.fill: parent
                anchors.leftMargin: 15
                color: "white"
                verticalAlignment: TextInput.AlignVCenter
                activeFocusOnPress: true

                Keys.onReturnPressed: { // enter
                    client.setMessage(inputText.text + "      |- Ivan");
                    client.sendToServer(inputText.text + "      |- Ivan");
                    chatField.message = client.getMessage();
                    inputText.text = "";
                }

//                property string placeholderText: "Enter text here..."
                Text {
                    text: "message"
                    color: "#aaa"
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
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
}
