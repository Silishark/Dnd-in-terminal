#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character
{
    Mage(QString _name): Character(_name, "Mage")
    {
    }
    ~Mage() = default;
    virtual void init() override
    {

    }
    virtual int Cskill() override
    {
        return 0;
    }
};


#endif // MAGE_H
