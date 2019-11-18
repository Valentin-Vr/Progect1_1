import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: secondWindow
    signal signalExit
    width: 600
    height: 320

    property int nextWord: 0
    property int countButton: 0
    //    property var eng
    //    property var rus
    Column {
        id: column
        width: parent.width
        height: parent.height
        spacing: 10
        Row {
            id:rowRect
            width: parent.width
            height: parent.height - parent.spacing * 2 - buttons.height
            spacing: 10
            Rectangle {
                color: "red"
                width: (parent.width - parent.spacing) / 2
                height: parent.height
                opacity: 0.5
                Label {
                    id: engLabel
                    color: "black"
                    font.pixelSize: 20
                    text: "eng"
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        verticalCenter: parent.verticalCenter
                    }
                }
            }
            Rectangle {
                color: "blue"
                width: (parent.width - parent.spacing) / 2
                height: parent.height
                opacity: 0.5
                Label {
                    id: rusLabel
                    color: "black"
                    font.pixelSize: 20
                    text: "rus"
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        verticalCenter: parent.verticalCenter
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
                    console.log(nextWord);
                    engLabel.text = myData.engWord(nextWord);
                    nextWord = myData.lineCount;
                    countButton = nextWord;
                    nextWord++;
                }
            }
            Button {
                text: qsTr("Забыл")
                width: 180
                height: 50
                highlighted: true
                onClicked: {
                    rusLabel.text = myData.rusWord(countButton);
                }
            }
        }
    }
}

