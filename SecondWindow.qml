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
    Column {
        id: column
        width: parent.width
        height: parent.height
        spacing: 10

        Row {
            id:rowRect
            width: parent.width
            height: parent.height - parent.spacing * 3 - buttons.height - 50
            spacing: 10

            OutputField {
                id: engWord
                width: (parent.width - parent.spacing) / 2
                height: parent.height
                rectTitleColor: "red"
                rectTitleOpacity: 0.5
                titleText: "Слово"
            }

            OutputField {
                id: rusWord
                width: (parent.width - parent.spacing) / 2
                height: parent.height
                rectOutFieldColor: "green"
                rectOutFieldOpacity: 0.5
                titleText: "Перевод"
            }

//            Rectangle {
//                color: "red"
//                width: (parent.width - parent.spacing) / 2
//                height: parent.height
//                opacity: 0.5
//                Label {
//                    id: engLabel
//                    color: "black"
//                    font.pixelSize: 20
//                    text: "eng"
//                    anchors {
//                        horizontalCenter: parent.horizontalCenter
//                        verticalCenter: parent.verticalCenter
//                    }
//                }
//            }
//            Rectangle {
//                color: "blue"
//                width: (parent.width - parent.spacing) / 2
//                height: parent.height
//                opacity: 0.5
//                Label {
//                    id: rusLabel
//                    color: "black"
//                    font.pixelSize: 20
//                    text: "rus"
//                    anchors {
//                        horizontalCenter: parent.horizontalCenter
//                        verticalCenter: parent.verticalCenter
//                    }
//                }
//            }
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
                    engWord.outFieldText = myData.engWord(nextWord);
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
                    rusWord.outFieldText = myData.rusWord(countButton);
                }
            }
        }

        Rectangle {
            color: "yellow"
            border {
                color: "black"
                width: 4
            }

            width: parent.width
            height: 50
            opacity: 0.5
        }
    }
}

