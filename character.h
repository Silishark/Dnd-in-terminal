#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:
    Character();
    ~Character();

    void setName(const QString& name);
    void setName(const QString&& name);
    QString name();

    Character& operator=(Character const&) = delete;
    Character(Character const&) = delete;

private:
    QString m_name;
    QString m_career;
    qint64 m_general_ability;
    qint64 m_career_ability;
};

#endif // CHARACTER_H
