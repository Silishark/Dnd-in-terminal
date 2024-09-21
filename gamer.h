#ifndef GAMER_H
#define GAMER_H

#include <QMovie>
#include <QLabel>
#include "include/character/character.h"

class Gamer
{
public:
    Gamer():m_x(0),m_y(0),m_velocity(STOP),m_runningCondition(false)
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
    void turn(int direction)
    {
        m_user.setDircetion(direction);
        //m_label->setMovie();
    }
    void changeRunningCondition(int condition)
    {
        m_runningCondition = condition;
        m_velocity = m_runningCondition;
    }
    int m_x;
    int m_y;
    int m_velocity;
private:
    Character m_user;
    //QMovie* m_movie;
    //save the picture of the character
    //QLabel* m_label;
    int m_runningCondition;
};

#endif // GAMER_H
