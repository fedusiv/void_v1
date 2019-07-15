import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("void_game")

    Text {
        id: txt
        text: qsTr("VOID GAME GUI")
        anchors.centerIn: parent
        font.pixelSize: 30
    }

    Button {
        text: "Start"
        anchors.top: txt.bottom
        anchors.horizontalCenter: txt.horizontalCenter
        anchors.margins: 15

        onClicked: {
            txt.text = "SAK MAI PIPI HOUMI :*";
            visible = false;
        }
    }
}
