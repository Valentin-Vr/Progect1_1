import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Программа 1_1")
    Column {
        id: mainColumn
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
                        id: label1
                        color: "black"
                        font.pixelSize: 20
                        text: "Слово"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    TextField {
                        id: engWord
                        width: parent.width
                        height: parent.height - label1.height
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 20
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
                        color: "black"
                        font.pixelSize: 20
                        text: "Перевод"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    TextField {
                        id: rusWords
                        width: parent.width
                        height: parent.height - label1.height
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 20
                    }
                }
            }
        }

        Rectangle {
            width: parent.width
            height: 150
            color: "green"
            opacity: 0.5

            Label {
                id: labelFile
                width: parent.width
                height: parent.height
                text: "asdasda"
                font.pixelSize: 15
            }

        }

        Row {
            id: buttons
            height: 50
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                width: 150
                height: parent.height
                highlighted: true
                text: "Добавить"

                onClicked: {
                    myData.writeFile(engWord.text, rusWords.text)
                }
            }
            Button {
                width: 150
                height: parent.height
                highlighted: true
                text: "Открыть файл"

                onClicked: {
                    labelFile.text = myData.openFile()
                }
            }
            Button {
                width: 150
                height: parent.height
                highlighted: true
                text: "Очистить"

                onClicked: {
                    engWord.clear()
                    rusWords.clear()
                }
            }
            Button {
                width: 150
                height: parent.height
                highlighted: true
                text: "Окно повторения"

                onClicked: {
                    mainWindow.close()
                    secondWindow.show()
                }
            }
        }
    }

    SecondWindow {
        id: secondWindow
        title: qsTr("Повторение")

        onSignalExit: {
            secondWindow.close()
            mainWindow.show()
        }
    }

}


