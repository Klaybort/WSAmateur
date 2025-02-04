#include "serverPlayer.h"

#include "abilityEvents.pb.h"

#include "abilityPlayer.h"
#include "abilityUtils.h"
#include "globalAbilities/globalAbilities.h"

Resumable ServerPlayer::resolveTrigger(ServerCard *card, asn::TriggerIcon trigger) {
    EventAbilityActivated event;
    auto ab = event.add_abilities();
    ab->set_zone("res");
    ab->set_type(ProtoAbilityType::ProtoClimaxTrigger);
    ab->set_card_id(card->id());
    ab->set_ability_id(static_cast<::google::protobuf::int32>(trigger));
    ab->set_card_code(card->code());
    auto uniqueId = abilityHash(*ab);
    ab->set_unique_id(uniqueId);
    sendToBoth(event);

    EventStartResolvingAbility evStart;
    evStart.set_unique_id(uniqueId);
    sendToBoth(evStart);

    AbilityPlayer a(this);
    a.setThisCard(CardImprint("res", card));
    a.setTriggerIcon(trigger);
    co_await a.playAbility(triggerAbility(trigger));

    EventAbilityResolved ev2;
    ev2.set_unique_id(uniqueId);
    sendToBoth(ev2);

    sendToBoth(EventEndResolvingAbilties());
}

void ServerPlayer::queueActivatedAbility(const asn::AutoAbility &ability,
                                         AbilityState &abilityState,
                                         ServerCard *card,
                                         std::string_view cardZone,
                                         ServerCard *cardFromTrigger) {
    if (ability.activationTimes > 0) {
        if (abilityState.activationTimes >= ability.activationTimes)
            return;
        else
            abilityState.activationTimes++;
    }

    TriggeredAbility ta;
    ta.card = CardImprint(cardZone.empty() ? card->zone()->name() : std::string(cardZone), card);
    ta.type = ProtoCard;
    ta.abilityId = abilityState.id;
    ta.cardFromTrigger = cardFromTrigger;
    if (!abilityState.permanent)
        ta.ability = abilityState.ability;
    mQueue.emplace_back(std::move(ta));
}

void ServerPlayer::checkZoneChangeTrigger(ServerCard *movedCard, std::string_view from, std::string_view to) {
    auto checkTrigger = [=, this](ServerCard *card) {
        for (int j = 0; static_cast<size_t>(j) < card->abilities().size(); ++j) {
            auto &a = card->abilities()[j];
            if (a.ability.type != asn::AbilityType::Auto)
                continue;
            const auto &aa = std::get<asn::AutoAbility>(a.ability.ability);
            if (aa.trigger.type != asn::TriggerType::OnZoneChange)
                continue;
            const auto &t = std::get<asn::ZoneChangeTrigger>(aa.trigger.trigger);
            if (t.from != asn::Zone::NotSpecified && asnZoneToString(t.from) != from)
                continue;
            if (t.to != asn::Zone::NotSpecified && asnZoneToString(t.to) != to)
                continue;
            std::string_view cardZone = card->zone()->name();
            bool found = false;
            for (const auto &target: t.target) {
                if (target.type == asn::TargetType::ThisCard) {
                    if (card != movedCard)
                        continue;
                    cardZone = to;
                } else if (t.target[0].type == asn::TargetType::SpecificCards) {
                    const auto &spec = *t.target[0].targetSpecification;

                    if (!checkTargetMode(spec.mode, card, movedCard))
                        continue;

                    if (!checkCard(spec.cards.cardSpecifiers, *movedCard))
                        continue;
                } else {
                    assert(false);
                }
                found = true;
                break;
            }
            if (!found)
                continue;

            queueActivatedAbility(aa, a, card, cardZone, movedCard);
        }
    };

    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;
        checkTrigger(card);
    }

    if ((to == "stage" && movedCard->zone()->name() != to) ||
        (to == "climax" && movedCard->zone()->name() == "climax"))
        checkTrigger(movedCard);
}

void ServerPlayer::checkGlobalEncore(ServerCard *movedCard, std::string_view from, std::string_view to) {
    if (from == "stage" && to == "wr" && movedCard->zone()->name() == "wr") {
        TriggeredAbility ta;
        ta.card = CardImprint(movedCard->zone()->name(), movedCard);
        ta.type = ProtoGlobal;
        ta.abilityId = static_cast<int>(GlobalAbility::Encore);
        mQueue.push_back(ta);
    }
}

void ServerPlayer::checkOnAttack(ServerCard *attCard) {
    auto checkTrigger = [=, this](ServerCard *card) {
        auto &abs = card->abilities();
        for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
            if (abs[i].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &autoab = std::get<asn::AutoAbility>(abs[i].ability.ability);
            if (autoab.trigger.type != asn::TriggerType::OnAttack)
                continue;
            const auto &trig = std::get<asn::OnAttackTrigger>(autoab.trigger.trigger);
            if (trig.target.type == asn::TargetType::ThisCard) {
                if (card != attCard)
                    continue;
            } else if (trig.target.type == asn::TargetType::SpecificCards) {
                const auto &spec = *trig.target.targetSpecification;

                if (!checkTargetMode(spec.mode, card, attCard))
                    continue;

                if (!checkCard(spec.cards.cardSpecifiers, *attCard))
                    continue;
            }

            queueActivatedAbility(autoab, abs[i], attCard, "", attCard);
        }
    };

    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        checkTrigger(card);
    }
}

void ServerPlayer::checkOnBeingAttacked(ServerCard *attackTarget, asn::AttackType attackType) {
    if (!attackTarget)
        return;
    auto checkTrigger = [=, this](ServerCard *card) {
        auto &abs = card->abilities();
        for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
            if (abs[i].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &aa = std::get<asn::AutoAbility>(abs[i].ability.ability);
            if (aa.trigger.type != asn::TriggerType::OnBeingAttacked)
                continue;
            const auto &trig = std::get<asn::OnBeingAttackedTrigger>(aa.trigger.trigger);
            if (trig.attackType != attackType)
                continue;
            if (trig.target.type == asn::TargetType::ThisCard) {
                if (card != attackTarget)
                    continue;
            } else if (trig.target.type == asn::TargetType::SpecificCards) {
                const auto &spec = *trig.target.targetSpecification;

                if (!checkTargetMode(spec.mode, card, attackTarget))
                    continue;

                if (!checkCard(spec.cards.cardSpecifiers, *attackTarget))
                    continue;
            }

            queueActivatedAbility(aa, abs[i], card, card->zone()->name(), attackTarget);
        }
    };

    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        checkTrigger(card);
    }
}

void ServerPlayer::checkPhaseTrigger(asn::PhaseState state, asn::Phase phase) {
    auto checkTrigger = [=, this](ServerCard *card, bool topClock) {
        auto &abs = card->abilities();
        for (int j = 0; j < static_cast<int>(abs.size()); ++j) {
            if (abs[j].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &autoab = std::get<asn::AutoAbility>(abs[j].ability.ability);
            if (autoab.trigger.type != asn::TriggerType::OnPhaseEvent)
                continue;
            // do not activate alarm if the card is on the stage
            // (otherwise ability is shown for a brief moment, but the condition is not met)
            // also prevent activating non alarm abilities from top clock
            bool alarm = std::any_of(autoab.keywords.begin(), autoab.keywords.end(),
                            [](asn::Keyword k){ return k == asn::Keyword::Alarm; });
            if (alarm != topClock)
                continue;

            const auto &trig = std::get<asn::PhaseTrigger>(autoab.trigger.trigger);
            if (trig.phase != phase || (trig.state != state && phase != asn::Phase::EndPhase) ||
                (trig.player == asn::Player::Player && !mActive) ||
                (trig.player == asn::Player::Opponent && mActive))
                continue;

            queueActivatedAbility(autoab, abs[j], card);
        }
    };

    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        checkTrigger(card, false);
    }

    auto clock = zone("clock");
    auto card = clock->topCard();
    if (card)
        checkTrigger(card, true);
}

void ServerPlayer::checkOnBackup(ServerCard *card) {
    auto &abs = card->abilities();
    for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
        if (abs[i].ability.type != asn::AbilityType::Auto)
            continue;
        const auto &autoab = std::get<asn::AutoAbility>(abs[i].ability.ability);
        if (autoab.trigger.type != asn::TriggerType::OnBackupOfThis)
            continue;

        queueActivatedAbility(autoab, abs[i], card);
    }
}

void ServerPlayer::checkOnTriggerReveal(ServerCard *revealedCard) {
    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        auto &abs = card->abilities();
        for (int j = 0; j < static_cast<int>(abs.size()); ++j) {
            if (abs[j].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &autoab = std::get<asn::AutoAbility>(abs[j].ability.ability);
            if (autoab.trigger.type != asn::TriggerType::OnTriggerReveal)
                continue;
            const auto &trig = std::get<asn::TriggerRevealTrigger>(autoab.trigger.trigger);
            if (!checkCard(trig.card.cardSpecifiers, *revealedCard))
                continue;

            queueActivatedAbility(autoab, abs[j], card);
        }
    }
}

void ServerPlayer::checkOtherTrigger(const std::string &code) {
    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        auto &abs = card->abilities();
        for (int j = 0; j < static_cast<int>(abs.size()); ++j) {
            if (abs[j].ability.type != asn::AbilityType::Auto)
                continue;

            const auto &autoab = std::get<asn::AutoAbility>(abs[j].ability.ability);
            if (autoab.trigger.type != asn::TriggerType::OtherTrigger)
                continue;

            const auto &trig = std::get<asn::OtherTrigger>(autoab.trigger.trigger);
            if (code != trig.cardCode)
                continue;

            queueActivatedAbility(autoab, abs[j], card);
        }
    }
}

void ServerPlayer::triggerBackupAbility(ServerCard *card) {
    if (!card->isCounter())
        return;

    auto &abs = card->abilities();
    for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
        if (abs[i].ability.type != asn::AbilityType::Act)
            continue;
        const auto &actab = std::get<asn::ActAbility>(abs[i].ability.ability);
        if (actab.keywords.empty() || actab.keywords[0] != asn::Keyword::Backup)
            continue;

        TriggeredAbility a;
        a.card = CardImprint(card->zone()->name(), card);
        a.type = ProtoCard;
        a.abilityId = abs[i].id;
        mQueue.push_back(a);

        return;
    }
}

void ServerPlayer::triggerRuleAction(RuleAction action, ServerCard *thisCard) {
    if (action == RuleAction::InsufficientPower) {
        // only one instance of this rule action is needed
        auto it = std::find_if(mQueue.begin(), mQueue.end(), [](const TriggeredAbility &el) {
            return el.type == ProtoRuleAction &&
                    el.abilityId == static_cast<int>(RuleAction::InsufficientPower);
        });
        if (it != mQueue.end())
            return;
    }
    TriggeredAbility a;
    a.type = ProtoRuleAction;
    a.abilityId = static_cast<int>(action);
    if (thisCard)
        a.card = CardImprint(thisCard->zone()->name(), thisCard);
    mQueue.push_back(a);
}

void ServerPlayer::triggerOnEndOfCardsAttack(ServerCard *card) {
    auto &abs = card->abilities();
    for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
        if (abs[i].ability.type != asn::AbilityType::Auto)
            continue;
        const auto &actab = std::get<asn::AutoAbility>(abs[i].ability.ability);
        if (actab.trigger.type != asn::TriggerType::OnEndOfThisCardsAttack)
            continue;

        TriggeredAbility a;
        a.card = CardImprint(card->zone()->name(), card);
        a.type = ProtoCard;
        a.abilityId = abs[i].id;
        mQueue.push_back(a);

        return;
    }
}

void ServerPlayer::triggerOnOppCharPlacedByStandby() {
    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        auto &abs = card->abilities();
        for (int j = 0; j < static_cast<int>(abs.size()); ++j) {
            if (abs[j].ability.type != asn::AbilityType::Auto)
                continue;

            const auto &autoab = std::get<asn::AutoAbility>(abs[j].ability.ability);
            if (autoab.trigger.type != asn::TriggerType::OnOppCharPlacedByStandbyTriggerReveal)
                continue;

            queueActivatedAbility(autoab, abs[j], card);
        }
    }
}

void ServerPlayer::checkOnReversed(ServerCard *card) {
    auto &abs = card->abilities();
    for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
        if (abs[i].ability.type != asn::AbilityType::Auto)
            continue;
        const auto &autoab = std::get<asn::AutoAbility>(abs[i].ability.ability);
        if (autoab.trigger.type != asn::TriggerType::OnStateChange)
            continue;
        const auto &trigger = std::get<asn::StateChangeTrigger>(autoab.trigger.trigger);
        if (trigger.state != asn::State::Reversed)
            continue;
        const auto &target = trigger.target;
        if (target.type != asn::TargetType::ThisCard)
            continue;

        queueActivatedAbility(autoab, abs[i], card);
    }
}

void ServerPlayer::checkOnBattleOpponentReversed(ServerCard *thisCard, ServerCard *battleOpp) {
    auto &abs = thisCard->abilities();
    for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
        if (abs[i].ability.type != asn::AbilityType::Auto)
            continue;
        const auto &autoab = std::get<asn::AutoAbility>(abs[i].ability.ability);
        if (autoab.trigger.type != asn::TriggerType::OnStateChange)
            continue;
        const auto &trig = std::get<asn::StateChangeTrigger>(autoab.trigger.trigger);
        if (trig.state != asn::State::Reversed)
            continue;
        if (trig.target.type != asn::TargetType::BattleOpponent)
            continue;
        const auto &spec = trig.target.targetSpecification.value();
        if (!checkCard(spec.cards.cardSpecifiers, *battleOpp))
            continue;

        queueActivatedAbility(autoab, abs[i], thisCard);
    }
}

void ServerPlayer::checkOnPlayTrigger(ServerCard *playedCard) {
    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        auto &abs = card->abilities();
        for (int j = 0; j < static_cast<int>(abs.size()); ++j) {
            if (abs[j].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &autoab = std::get<asn::AutoAbility>(abs[j].ability.ability);
            if (autoab.trigger.type != asn::TriggerType::OnPlay)
                continue;
            const auto &trig = std::get<asn::OnPlayTrigger>(autoab.trigger.trigger);
            if (trig.target.type == asn::TargetType::ThisCard) {
                if (card != playedCard)
                    continue;
            } else if (trig.target.type == asn::TargetType::SpecificCards) {
                const auto &spec = *trig.target.targetSpecification;
                if (!checkTargetMode(spec.mode, card, playedCard))
                    continue;

                if (!checkCard(spec.cards.cardSpecifiers, *playedCard))
                    continue;
            }

            queueActivatedAbility(autoab, abs[j], card, "", playedCard);
        }
    }
}

void ServerPlayer::checkOnDamageCancel(ServerCard *attCard, bool cancelled) {
    auto checkTrigger = [=, this](ServerCard *card) {
        auto &abs = card->abilities();
        for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
            if (abs[i].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &aa = std::get<asn::AutoAbility>(abs[i].ability.ability);
            if (aa.trigger.type != asn::TriggerType::OnDamageCancel)
                continue;
            const auto &trig = std::get<asn::OnDamageCancelTrigger>(aa.trigger.trigger);
            if (trig.cancelled != cancelled)
                continue;
            if (trig.damageDealer.type == asn::TargetType::ThisCard) {
                if (card != attCard)
                    continue;
            } else if (trig.damageDealer.type == asn::TargetType::SpecificCards) {
                const auto &spec = *trig.damageDealer.targetSpecification;

                if (!checkTargetMode(spec.mode, card, attCard))
                    continue;

                if (!checkCard(spec.cards.cardSpecifiers, *attCard))
                    continue;
            }

            queueActivatedAbility(aa, abs[i], card, card->zone()->name(), attCard);
        }
    };

    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        checkTrigger(card);
    }
}

void ServerPlayer::checkOnDamageTakenCancel(bool cancelled) {
    auto checkTrigger = [=, this](ServerCard *card) {
        auto &abs = card->abilities();
        for (int i = 0; i < static_cast<int>(abs.size()); ++i) {
            if (abs[i].ability.type != asn::AbilityType::Auto)
                continue;
            const auto &aa = std::get<asn::AutoAbility>(abs[i].ability.ability);
            if (aa.trigger.type != asn::TriggerType::OnDamageTakenCancel)
                continue;
            const auto &trig = std::get<asn::OnDamageTakenCancelTrigger>(aa.trigger.trigger);
            if (trig.cancelled != cancelled)
                continue;

            queueActivatedAbility(aa, abs[i], card);
        }
    };

    auto stage = zone("stage");
    for (int i = 0; i < stage->count(); ++i) {
        auto card = stage->card(i);
        if (!card)
            continue;

        checkTrigger(card);
    }
}
