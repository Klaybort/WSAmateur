import QtQuick 2.12
import QtQuick.Controls 2.12

import "../basicTypes"

Rectangle {
    id: effectImpl

    signal editEffects()
    signal ifYouDo()
    signal ifYouDont()

    width: root.width

    MouseArea {
        anchors.fill: parent
    }

    Text {
        id: label
        anchors.horizontalCenter: effectImpl.horizontalCenter
        text: "Non Mandatory"
        font.pointSize: 12
    }

    Row {
        spacing: 5
        anchors{ top: label.bottom; topMargin: 10 }
        anchors.horizontalCenter: effectImpl.horizontalCenter

        Column {
            Text { text: "Effect" }
            Button {
                text: "Add effects"
                onClicked: {
                    editEffects();
                }
            }
        }

        Column {
            Text { text: "If you do" }
            Button {
                text: "Add effects"
                onClicked: {
                    ifYouDo();
                }
            }
        }

        Column {
            Text { text: "If you don't" }
            Button {
                text: "Add effects"
                onClicked: {
                    ifYouDont();
                }
            }
        }
    }
}
