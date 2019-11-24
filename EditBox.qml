import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

    Rectangle {
        property color rectTitleColor: "green"
        property color rectTextFieldColor: rectTitleColor
        property color titleColor: "black"
        property color textFieldColor: titleColor
        property int rectWidth: 150
        property int rectHeight: 150
        property real rectTitleOpacity: 0.5
        property real rectTextFieldOpacity: 0.5
        property real labelOpacity: 1
        property string titleText: "Value"
        property string editFieldText: word.text
        property int labelTextFont: 20

        height: rectHeight
        width: rectWidth

        Column {
            width: parent.width
            height: parent.height
            z: 1
            Label {
                id: title
                height: parent.height / 4
                color: titleColor
                font.pixelSize: parent.height / 5
                text: titleText
                opacity: labelOpacity
                anchors.horizontalCenter: parent.horizontalCenter
            }
            TextField {
                id: word
                color: textFieldColor
                height: parent.height * 3 / 4
                width: parent.width
                font.pixelSize: 20
                opacity: 0.5
            }
        }
        Column {
            width: parent.width
            height: parent.height

            Rectangle {
                width: parent.width
                height: title.height
                opacity: rectTitleOpacity
                color: rectTitleColor
            }
            Rectangle {
                width: parent.width
                height: word.height
                opacity: rectTextFieldOpacity
                color: rectTextFieldColor
            }
        }
    }


