#ifndef character_h
#define character_h

#include <QVector>
#include <QString>
#include <QDebug>

#define MAGE 1
#define WARRIOR 2
#define TEACHER 3
#define THIEF 4

class Character
{
public:
    Character()
    {
    }
    ~Character()
    {
    }
    void setName(const QString& name)
    {
        m_name = name;
        qDebug("name success");

    }
    void init(QString& career, QString& race,int health,int armor,int speed,int strength,int intelligence)
    {
        m_career = career;
        m_race = race;
        m_health = health;
        m_armor = armor;
        m_speed = speed;
        m_strength = strength;
        m_intelligence = intelligence;
        qDebug("init success");
    }
    void addMemory(const QString& memory)
    {
        m_memory.push_back(memory);
        qDebug("momory");
    }
    void addAction(const QString& action)
    {
        m_actions.push_back(action);
        qDebug("action");
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
    QVector<QString> m_memory;
    QVector<QString> m_actions;
};

#endif
