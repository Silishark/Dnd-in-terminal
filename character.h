#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:
    Character(QString _name, QString _career): weapon(false), name(_name), career(_career)
    {
    }
    ~Character() = default;

    virtual void init();
    virtual int Cskill();

    Character& operator=(Character const&) = delete;
    Character(Character const&) = delete;

    bool weapon;
    QString name;
    QString career;
};

#endif // CHARACTER_H

