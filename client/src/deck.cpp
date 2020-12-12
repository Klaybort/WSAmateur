#include "deck.h"

#include <QQmlContext>

#include "player.h"
#include "game.h"

Deck::Deck(Player *player, Game *game)
    : mPlayer(player), mGame(game) {
    mCardsModel.addCards(50);

    QQmlComponent component(mGame->engine(), "qrc:/qml/Deck.qml");
    QQmlContext *context = new QQmlContext(mGame->context(), mGame->parent());
    context->setContextProperty("innerModel", QVariant::fromValue(&mCardsModel));
    QObject *obj = component.create(context);
    mQmlObject = qobject_cast<QQuickItem*>(obj);
    mQmlObject->setParentItem(mGame->parentItem());
    mQmlObject->setParent(mGame->parent());
    mQmlObject->setProperty("opponent", player->isOpponent());

}
