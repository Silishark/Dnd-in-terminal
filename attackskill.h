#ifndef ATTACKSKILL_H
#define ATTACKSKILL_H

#include "Action.h"

class AttackSkill : public Action {
    QString name;
    int minDamage, maxDamage;
    int cost;
public:
    AttackSkill(QString name, int minDamage, int maxDamage, int cost)
        : name(name), minDamage(minDamage), maxDamage(maxDamage), cost(cost) {}

    QString perform() override {
        int hitChance = RandomUtils::generateRandom(1, 21);
        if (hitChance >= 10) { 
            int damage = RandomUtils::generateRandom(minDamage, maxDamage + 1);
            return name + " hits for " + QString::number(damage) + " damage.";
        }
        return name + " misses.";
    }
};

#endif