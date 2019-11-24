import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

    Rectangle {
        property color rectTitleColor: "green"
        property color rectOutFieldColor: rectTitleColor
        property color titleColor: "black"
        property color outFieldColor: titleColor
        property int rectWidth: 150
        property int rectHeight: 150
        property real rectTitleOpacity: 0.5
        property real rectOutFieldOpacity: 0.5
        property real labelOpacity: 1
        property string titleText: "Value"
        property string outFieldText
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
                font.pixelSize: title.height * 2 / 3
                text: titleText
                opacity: labelOpacity
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Label {
                id: word
                color: titleColor
                font.pixelSize: labelTextFont
                opacity: labelOpacity
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                text: outFieldText
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
                height: parent.height * 3 / 4
                opacity: rectOutFieldOpacity
                color: rectOutFieldColor
            }
        }
    }
