#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "abilityModel.h"
#include "cardModel.h"
#include "choiceDialog.h"
#include "game.h"
#include "player.h"
#include "imageProvider.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES, true);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Game>("wsamateur.game", 1, 0, "Game");
    qmlRegisterAnonymousType<Player>("wsamateur.player", 1);
    qmlRegisterType<CardModel>("wsamateur.cardModel", 1, 0, "CardModel");
    qmlRegisterType<AbilityModel>("wsamateur.abilityModel", 1, 0, "AbilityModel");
    qmlRegisterType<ChoiceDialogModel>("wsamateur.choiceDialogModel", 1, 0, "ChoiceDialogModel");

    QQmlApplicationEngine engine;

    engine.addImageProvider("imgprov", new AsyncImageProvider);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
