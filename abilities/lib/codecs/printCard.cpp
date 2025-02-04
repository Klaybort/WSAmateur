#include "print.h"

using namespace asn;

std::string printCard(const Card &c, bool plural, bool article, TargetMode mode) {
    std::string s;

    if (c.cardSpecifiers.empty()) {
        if (!plural && article)
            s += "a ";
        s += "card";
        if (plural)
            s += "s";
        return s;
    }

    if (!plural && article) {
        auto hasOwnerSpecifier = [](const CardSpecifier &c){ return c.type == CardSpecifierType::Owner; };
        auto it = std::find_if(c.cardSpecifiers.begin(), c.cardSpecifiers.end(), hasOwnerSpecifier);
        if (it == c.cardSpecifiers.end())
            s += "a ";
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::Owner) {
            switch (std::get<Player>(cardSpec.specifier)) {
            case Player::Player:
                s += "your ";
                break;
            case Player::Opponent:
                s += "your opponent's ";
                break;
            default:
                break;
            }
        }
    }

    if (mode == TargetMode::AllOther || mode == TargetMode::FrontRowOther ||
            mode == TargetMode::BackRowOther)
        s += "other ";

    int count = 0;
    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::ExactName) {
            if (count)
                s += "or ";
            s += "\"" + std::get<ExactName>(cardSpec.specifier).value + "\" ";
            count++;
        }
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::Level) {
            const auto &level = std::get<Level>(cardSpec.specifier);
            s += "level " + std::to_string(level.value.value) + " ";
            if (level.value.mod == NumModifier::UpTo)
                s += "or lower ";
            else if (level.value.mod == NumModifier::AtLeast)
                s += "or higher ";
        }
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::Cost) {
            const auto &cost = std::get<CostSpecifier>(cardSpec.specifier);
            s += "cost " + std::to_string(cost.value.value) + " ";
            if (cost.value.mod == NumModifier::UpTo)
                s += "or lower ";
            else if (cost.value.mod == NumModifier::AtLeast)
                s += "or higher ";
        }
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::Trait) {
            s += printTrait(std::get<Trait>(cardSpec.specifier).value) + " ";
        }
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::CardType) {
            switch (std::get<CardType>(cardSpec.specifier)) {
            case CardType::Char:
                s += "character";
                break;
            case CardType::Climax:
                s += "climax";
                if (plural)
                    s += "e";
                break;
            case CardType::Event:
                if (s.size() >= 2) {
                    if (s.substr(s.size() - 2, 2) == "a ") {
                        s[s.size() - 1] = 'n';
                        s.push_back(' ');
                    }
                }
                s += "event";
                break;
            case CardType::Marker:
                s += "marker";
                break;
            }
            if (plural)
                s += 's';
            s += " ";
        }
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::TriggerIcon)
            s += "with a " + printTriggerIcon(std::get<TriggerIcon>(cardSpec.specifier)) + " trigger ";
    }

    count = 0;
    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::NameContains) {
            if (!count++)
                s += "with ";
            else
                s += " or ";
            s += "\"" + std::get<NameContains>(cardSpec.specifier).value + "\"";
        }
    }
    if (count)
        s += " in its card name ";

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::LevelHigherThanOpp)
            s += "with level higher than your opponent's level ";
    }

    for (const auto &cardSpec: c.cardSpecifiers) {
        if (cardSpec.type == CardSpecifierType::StandbyTarget)
            s += "with level equal to or less than your level +1 ";
    }

    if (s[s.size() - 1] == ' ')
        s.pop_back();

    return s;
}
