#ifndef character_h
#define character_h

#include <QVector>
#include <Qstring>

class Character
{
public:
    Character(QString name,int health,int attack,int defense):
    cname(name),chealth(health),cattack(attack),cdefense(defense)
    {
    }
    virtual ~Character()
    {

    }
    private:
    QString cname;
    int chealth;
    int cattack;
    int cdefense;
    union career
    {

    };
};

#endif
