import QtQuick 2.0

import wsamateur.cardModel 1.0

Card {
    id: deck
    property bool opponent
    property bool hidden: true
    property CardModel mModel: innerModel

    mSource: "cardback"
    rotation: opponent ? 180 : 0

    x: {
        if (opponent)
            return root.width * 0.03;
        return root.width * 0.97 - root.cardWidth;
    }
    y: {
        if (opponent)
            return root.height * 0.47 - root.cardHeight;
        return root.height * 0.53;
    }
    z: 1

    function addCard(code) { deck.mModel.addCard(code); }
    function removeCard(index) { deck.mModel.removeCard(index); }

    function getXForNewCard() { return deck.x; }
    function getYForNewCard() { return deck.y; }
    function getXForCard() { return deck.x; }
    function getYForCard() { return deck.y; }
}
