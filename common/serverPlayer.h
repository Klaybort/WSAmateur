#pragma once

#include <string>
#include <unordered_map>

#include <google/protobuf/message.h>

#include "commands.h"
#include "deckList.h"
#include "serverCardZone.h"

class GameCommand;
class ServerGame;
class ServerProtocolHandler;

class CommandMulligan;
class CommandClockPhase;
class CommandPlayCard;
class CommandSwitchStagePositions;
class CommandDeclareAttack;

class ServerPlayer
{
    ServerGame *mGame;
    ServerProtocolHandler *mClient;
    size_t mId;
    bool mReady = false;
    bool mMulliganFinished = false;
    bool mStartingPlayer = false;
    std::unique_ptr<DeckList> mDeck;
    std::unordered_map<std::string_view, std::unique_ptr<ServerCardZone>> mZones;
    std::vector<ExpectedCommand> mExpectedCommands;

    int mLevel = 0;

public:
    ServerPlayer(ServerGame *game, ServerProtocolHandler *client, size_t id);

    size_t id() const { return mId; }
    bool ready() const { return mReady; }
    void setReady(bool ready) { mReady = ready; }
    bool mulliganFinished() const { return mMulliganFinished; }
    bool startingPlayer() const { return mStartingPlayer; }
    void setStartingPlayer() { mStartingPlayer = true; }
    bool hasBattleOpponent(size_t pos) const;

    void clearExpectedComands();
    void addExpectedCommand(const std::string &command);
    bool expectsCommand(const GameCommand &command);

    void processGameCommand(GameCommand &cmd);
    void sendGameEvent(const ::google::protobuf::Message &event, size_t playerId = 0);

    void addDeck(const std::string &deck);
    DeckList* deck() { return mDeck.get(); }
    ServerCardZone* addZone(std::string_view name, ZoneType type = ZoneType::PublicZone);
    ServerCardZone* zone(std::string_view name);
    void setupZones();
    void startGame();
    void startTurn();
    void dealStartingHand();
    void mulligan(const CommandMulligan &cmd);
    void drawCards(size_t number);
    void moveCard(std::string_view startZoneName, const std::vector<size_t> &cardIds, std::string_view targetZoneName);
    void processClockPhaseResult(const CommandClockPhase &cmd);
    void playCard(const CommandPlayCard &cmd);
    void playCharacter(const CommandPlayCard &cmd);
    void playClimax(size_t handIndex);
    void switchPositions(const CommandSwitchStagePositions &cmd);
    bool canPlay(ServerCard *card);
    void climaxPhase();
    void attackPhase();
    void declareAttack(const CommandDeclareAttack &cmd);
};
