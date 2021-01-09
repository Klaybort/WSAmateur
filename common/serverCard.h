#pragma once

#include <string>

#include "attributeChange.h"
#include "cardInfo.h"

class ServerCardZone;

enum StageRow {
    CenterStage,
    BackStage
};

class ServerCard
{
    std::shared_ptr<CardInfo> mCardInfo;
    ServerCardZone *mZone;
    std::string mCode;
    std::vector<AttributeChange> mBuffs;

    // stage position
    StageRow mRow;
    int mPosition;

    int mPower;
    int mSoul;
    CardState mState = CardState::Standing;
    //bool mAttacking = false;
    //AttackType mAttackType;

public:
    ServerCard(std::shared_ptr<CardInfo> info, ServerCardZone *zone);
    ServerCard(int pos, ServerCardZone *zone);

    bool cardPresent() const { return !mCode.empty(); }
    void setPos(int pos);
    int pos() const;
    void setZone(ServerCardZone *zone) { mZone = zone; }
    const std::string& code() { return mCode; }
    int level() const { return mCardInfo->level(); }
    int cost() const { return mCardInfo->cost(); }
    int power() const { return mPower; }
    int soul() const { return mSoul; }
    CardType type() const { return mCardInfo->type(); }
    char color() const { return mCardInfo->color(); }
    CardState state() const { return mState; }
    void setState(CardState state) { mState = state; }
    //bool attacking() const { return mAttacking; }
    //void setAttacking(bool attacking) { mAttacking = attacking; }
    const std::vector<Trigger>& triggers() { return mCardInfo->triggers(); }
    void addSoulBuff(int delta, int duration);
};
