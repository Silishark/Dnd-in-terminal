#ifndef TEACHER_H
#define TEACHER_H

#include "character.h"

class Teacher : public Character
{
    Teacher(QString _name): Character(_name, "Teacher")
    {
    }
    ~Teacher() = default;
    virtual void init() override
    {

    }
    virtual int Cskill() override
    {
        return 0;
    }
};

#endif // TEACHER_H
