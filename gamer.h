#ifndef GAMER_H
#define GAMER_H

#include <QLabel>
#include "include/character/character.h"

class Gamer
{
public:
    Gamer()
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
    void setCareer(int order)
    {
        m_user.setCareer(order);
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
