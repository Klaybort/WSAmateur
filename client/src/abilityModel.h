#pragma once

#include <vector>

#include <QAbstractListModel>

#include "abilities.h"

struct AbilityInfo {
    QString text;
    asn::Ability ability;
    int id;
    bool permanent = true;
};

class AbilityModel : public QAbstractListModel
{
    Q_OBJECT
private:
    std::vector<AbilityInfo> mAbilities;

public:
    enum AbilityRoles {
        TextRole = Qt::UserRole + 1,
        PermanentRole
    };
    AbilityModel() : QAbstractListModel(nullptr) {}

    const AbilityInfo& info(int index) const { return mAbilities.at(index); }
    QString textById(int id) const;
    QString textByIndex(int row) const;
    const asn::Ability &ability(int row) const;
    const asn::Ability& abilityById(int id) const;
    void addAbility(const asn::Ability &a, int id, asn::CardType cardType = asn::CardType::Char, bool permanent = true);
    void removeAbilityById(int id);
    int rowCount(const QModelIndex & = QModelIndex()) const override { return static_cast<int>(mAbilities.size()); }
    int count() const { return rowCount(); }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;
};
