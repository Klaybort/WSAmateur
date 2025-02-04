import QtQuick 2.12

import wsamateur 1.0

Image {
    id: bgImage

    property AbilityModel mModel

    z: 100
    width: 300
    height: effectsView.height + borderRect.borderWidth * 2
    source: "qrc:///resources/images/textFrame"

    /* references work but need proper visualization
    ListView {
        width: contentWidth
        height: root.cardHeight / 2
        y: bgImage.height
        orientation: ListView.Horizontal
        model: mModel.getReferences()
        delegate: Card {
            mSource: modelData
        }
    }*/

    Rectangle {
        id: borderRect
        property real borderWidth: 2

        color: "#FFFFFF"
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom

            leftMargin: borderWidth
            rightMargin: borderWidth
            topMargin: borderWidth
            bottomMargin: borderWidth
        }

        ListView {
            id: effectsView
            anchors.left: parent.left
            anchors.right: parent.right
            height: contentHeight
            model: mModel

            delegate: Rectangle {
                color: model.permanent ? "#FFFFFF" : "#FFFDD7"
                radius: 5
                border.width: 1
                width: bgImage.width - borderRect.borderWidth * 2
                height: effectText.contentHeight
                Text {
                    id: effectText
                    width: parent.width
                    wrapMode: Text.WordWrap
                    textFormat: Text.StyledText
                    horizontalAlignment: Text.AlignJustify
                    leftPadding: 4
                    rightPadding: 4
                    text: model.text
                    font.family: "Futura Bk BT"
                    font.pointSize: 10
                }
            }
        }
    }
}
