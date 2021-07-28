#include "print.h"

#include <string>
#include <unordered_map>

using namespace asn;

namespace {
std::unordered_map<std::string, std::string> gOtherTriggers {
    { "KGL/S79-016", "When your opponent uses \"<b>Brainstorm</b>\" and that effect puts at least 1 climax\
 card in their waiting room, " }
};
}

std::string printZoneChangeTrigger(const ZoneChangeTrigger &t) {
    std::string s = "When ";

    for (size_t i = 0; i < t.target.size(); ++i) {
        if (i)
            s += "or ";
        s += printTarget(t.target[i]);
    }
    s += "is placed ";
    if (t.to == Zone::Stage)
        s += "on ";
    else
        s += "into ";
    if (t.to != Zone::Stage)
        s += "your ";
    s += printZone(t.to);

    if (t.from != Zone::NotSpecified) {
        s += " from ";
        if (t.from == Zone::Stage)
            s += "the stage";
        else
            s += "your " + printZone(t.from);
    }

    s += ", ";

    return s;
}

std::string printOnAttackTrigger(const OnAttackTrigger &t) {
    if (t.target.type == TargetType::ThisCard)
        return "When this card attacks, ";
    return "";
}

std::string printBattleOpponentReversedTrigger(const BattleOpponentReversedTrigger &) {
    return "When this card's battle opponent becomes" + printState(State::Reversed) + ", ";
}
std::string printOnBackupOfThis() {
    return "When you use this card's \"<b>Backup</b>\", ";
}
std::string printOnReversed() {
    return "When this card becomes" + printState(State::Reversed) + ", ";
}
std::string printPhaseTrigger(const PhaseTrigger &t) {
    std::string s;

    if (t.state == PhaseState::Start)
        s += "at the start of ";
    s += printPlayer(t.player);
    s += printPhase(t.phase) + ", ";

    return s;
}

std::string printOnTriggerReveal(const TriggerRevealTrigger &t) {
    std::string s = "when your character's trigger check reveals ";

    s += printCard(t.card) + ", ";

    return s;
}

std::string printOnPlay(const OnPlayTrigger &t) {
    std::string s = "when you play ";

    s += printTarget(t.target);
    s.pop_back();
    s += ", ";

    return s;
}

std::string printOtherTrigger(const OtherTrigger &t) {
    return gOtherTriggers[t.cardCode];
}

std::string printTrigger(const Trigger &t) {
    std::string s;

    switch (t.type) {
    case TriggerType::OnZoneChange:
        s += printZoneChangeTrigger(std::get<ZoneChangeTrigger>(t.trigger));
        break;
    case TriggerType::OnAttack:
        s += printOnAttackTrigger(std::get<OnAttackTrigger>(t.trigger));
        break;
    case TriggerType::OnBattleOpponentReversed:
        s += printBattleOpponentReversedTrigger(std::get<BattleOpponentReversedTrigger>(t.trigger));
        break;
    case TriggerType::OnPhaseEvent:
        s += printPhaseTrigger(std::get<PhaseTrigger>(t.trigger));
        break;
    case TriggerType::OnBackupOfThis:
        s += printOnBackupOfThis();
        break;
    case TriggerType::OnReversed:
        s += printOnReversed();
        break;
    case TriggerType::OnTriggerReveal:
        s += printOnTriggerReveal(std::get<TriggerRevealTrigger>(t.trigger));
        break;
    case TriggerType::OnPlay:
        s += printOnPlay(std::get<OnPlayTrigger>(t.trigger));
        break;
    case TriggerType::OtherTrigger:
        s += printOtherTrigger(std::get<OtherTrigger>(t.trigger));
        break;
    }

    return s;
}
