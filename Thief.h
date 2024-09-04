#ifndef THIEF_H
#define THIEF_H

#include "character.h"

class Thief : public Character
{
    Thief(QString _name): Character(_name, "Thief")
    {
    }
    ~Thief() = default;
    virtual void init() override
    {

    }
    virtual int Cskill() override
    {
        return 0;
    }
};
#endif // THIEF_H
