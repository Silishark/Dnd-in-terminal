#ifndef WORRIOR_H
#define WORRIOR_H

#include "character.h"

class Worrior : public Character
{
    Worrior(QString _name): Character(_name, "Worrior")
    {
    }
    ~Worrior() = default;
    virtual void init() override
    {
    }
    virtual int Cskill() override
    {
        return 0;
    }
};

#endif // WORRIOR_H
