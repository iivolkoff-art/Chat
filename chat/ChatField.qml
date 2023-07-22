import QtQuick 2.15
import QtQuick.Controls 2.15
import "C:/Users/Volkov/Documents/chat/InputField.qml" as InputField //замените на свой путь

Item {
    property color messageColor: "#00DFFC"
    property string message: ""
    id: chatField
    anchors.top: parent.top
    width: parent.width
    height: parent.height * 0.95

    ListModel {
        id: messageModel
    }

    ListView {
        id: chatListView
        anchors.fill: parent
        model: messageModel
        orientation: Qt.Vertical
        spacing: 5
        clip: true
        interactive: false

        ScrollBar.vertical: ScrollBar {
            anchors.right: parent.right
            policy: ScrollBar.AlwaysOn
        }

        delegate: Rectangle {
            width: parent.width
            height: contentText.height
            color: backgroundColor

            Text {
                id: contentText
                text: model.messageText
                color: messageColor
                font.pixelSize: 18
                wrapMode: Text.WordWrap
                anchors.onLeftChanged: parent
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        onModelChanged: {
            chatListView.contentY = chatListView.contentHeight - chatListView.height;
        }

        onContentYChanged: {
            if (chatListView.contentY >= chatListView.contentHeight - chatListView.height)
                chatListView.contentY = chatListView.contentHeight - chatListView.height;
        }
    }
    onMessageChanged: {
        if(message != ""){
            messageModel.append({ messageText: message });
            chatListView.contentY = chatListView.contentHeight - chatListView.height;
            message = ""
            messageColor = "#00DFFC"
        }
    }
}
