#ifndef character_h
#define character_h

#include <QVector>
#include <QString>
#include "career.h"

#define MAGE 1
#define WARRIOR 2
#define TEACHER 3
#define THIEF 4

class Character
{

public:
    Character();
    ~Character()
    {
    }
    void addDialog(const QString& log)
    {
        this->dialog.push_back(log);
    }
    QString getDialog(int index)
    {
        return dialog[index];
    }
    void init(QString name, QString race, int health, int armor, int speed, int strength, int intelligence)
    {
        m_name = name;
        m_race = race;
        m_health = health;
        m_armor = armor;
        m_speed = speed;
        m_strength = strength;
        m_intelligence = intelligence;
    }
    void setCareer(int order)
    {
        switch(order)
        {
        case MAGE:
            m_career = "Mage";
            break;
        case WARRIOR:
            m_career = "Warrior";
            break;
        case TEACHER:
            m_career = "Teacher";
            break;
        case THIEF:
            m_career = "Thief";
            break;
        default:
            break;
        }
    }
private:
    QString m_name;
    QString m_career;
    QString m_race;
    int m_health;
    int m_armor;
    int m_speed;
    int m_strength;
    int m_intelligence;
    QVector<QString> dialog;
};

#endif
