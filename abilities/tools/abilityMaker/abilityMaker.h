#pragma once

#include <QObject>
#include <QQuickItem>

#include <QDebug>

#include "abilityComponent.h"

class AbilityMaker : public QQuickItem {
    Q_OBJECT
private:
    std::unique_ptr<AbilityComponent> qmlAbility;

public slots:
    void translate(const asn::Ability &ability);

protected:
    void componentComplete() override;
};
