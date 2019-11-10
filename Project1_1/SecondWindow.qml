import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: secondWindow
    signal signalExit
    width: 600
    height: 320

    property int nextWord: 0
    property var eng
    Column {
        id: column
        width: parent.width
        height: parent.height
        spacing: 10
        Row {
            id:rowRect
            width: parent.width
            height: 150
            spacing: 10
            Rectangle {
                color: "red"
                width: (parent.width - parent.spacing) / 2
                height: 150
                opacity: 0.5
                Column {
                    width: parent.width
                    height: parent.height
                    Label {
                        id: engLabel
                        color: "black"
                        font.pixelSize: 20
                        text: "eng"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
            Rectangle {
                color: "blue"
                width: (parent.width - parent.spacing) / 2
                height: 150
                opacity: 0.5
                Column{
                    width: parent.width
                    height: parent.height
                    Label {
                        id: rusLabel
                        color: "black"
                        font.pixelSize: 20
                        text: "rus"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }

        Row {
            id: buttons
            height: 50
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                text: qsTr("Главное окно")
                width: 180
                height: 50
                highlighted: true
                onClicked: {
                    secondWindow.signalExit()
                }
            }
            Button {
                text: qsTr("Следующее слово")
                width: 180
                height: 50
                highlighted: true
                onClicked: {

                    eng = myData.readWords(0);
                    engLabel.text = eng[1];
//                    nextWord++;
                }
            }
        }
    }
}

