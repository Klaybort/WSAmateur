import QtQuick 2.12
import QtQuick.Window 2.12

import wsamateur.cardModel 1.0

Rectangle {
    id: cardsView
    property CardModel mModel
    property bool mIsDeckView: false
    property real mColumnMaxHeight: root.height * 0.5 - header.height
    property bool mOpponent: false
    signal closeSignal()

    y: root.height * 0.33
    width: header.width + header.anchors.leftMargin + closeBtn.width + closeBtn.anchors.rightMargin * 2//Math.max(row.width + 20, header.width + closeBtn.width * 2 + 20)
    height: {
        const calcHeight = calculateViewHeight();
        if (calcHeight > root.height * 0.5)
            return root.height * 0.5 + 20;
        return calcHeight + 20;
    }
    radius: 5
    border.width: 1
    //color: "#A0564747"
    color: "#40000000"
    z: 160

    Text {
        id: header
        width: {
            const minViewWidth = contentWidth + header.anchors.leftMargin + closeBtn.width + closeBtn.anchors.rightMargin * 2;
            if (minViewWidth > row.width + 20)
                return contentWidth;
            else
                return row.width + 20 - (closeBtn.width + closeBtn.anchors.rightMargin * 2);
        }
        anchors {
            left: cardsView.left
            leftMargin: 5
            top: cardsView.top
            topMargin: 3
        }
        text: {
            let txt = mOpponent ? "Opponent's " : " ";
            return txt + (mIsDeckView ? "Deck" : "Waiting Room");
        }
        font.family: "Futura Bk BT"
        font.pointSize: 20
        color: "white"
        horizontalAlignment: Text.AlignHCenter
    }
    Image {
        id: closeBtn
        anchors {
            right: cardsView.right
            rightMargin: 5
            top: cardsView.top
            topMargin: 5
        }
        source: "qrc:///resources/images/closeButton"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: closeBtn.source = "qrc:///resources/images/closeButtonHighlighted"
            onExited: closeBtn.source = "qrc:///resources/images/closeButton"
            onClicked: closeSignal()
        }
    }

    Row {
        id: row
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: header.bottom
            topMargin: 5
        }
        spacing: -root.cardWidth * 0.1

        CardsViewColumn {
            id: col1
            mModel: cardsView.mModel
            predicate: function(entry) {
                if (entry.level === 0 && entry.type === "Char")
                    return true;
                return false;
            }
        }
        CardsViewColumn {
            id: col2
            mModel: cardsView.mModel
            predicate: function(entry) {
                if (entry.level === 1 && entry.type === "Char")
                    return true;
                return false;
            }
        }
        CardsViewColumn {
            id: col3
            mModel: cardsView.mModel
            predicate: function(entry) {
                if ((entry.level === 2 || entry.level === 3) && entry.type === "Char")
                    return true;
                return false;
            }
        }
        CardsViewColumn {
            id: col4
            mModel: cardsView.mModel
            predicate: function(entry) {
                if (entry.type === "Climax" || entry.type === "Event")
                    return true;
                return false;
            }
        }
    }

    function calculateViewHeight() {
        let max = col1.height;
        if (col2.height > max)
            max = col2.height;
        if (col3.height > max)
            max = col3.height;
        if (col4.height > max)
            max = col4.height;
        return max + header.height;
    }
}
