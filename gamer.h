#ifndef GAMER_H
#define GAMER_H

#include <QLabel>
#include "include/character/character.h"

class Gamer
{
public:
    Gamer():m_x(0),m_y(0)
    {
    }
    ~Gamer()
    {
    }
    void setPostion(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    void move(int x,int y)
    {
        m_x += x;
        m_y += y;
    }
    Character* getUser()
    {
        return &m_user;
    }
private:
    Character m_user;
    QLabel* m_label;
    int m_x;
    int m_y;
};

#endif // GAMER_H
