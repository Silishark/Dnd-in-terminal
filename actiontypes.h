#ifndef ACTION_H
#define ACTION_H

#include <QString>
#include "utils/RandomUtils.h" 

class Action {
public:
    virtual ~Action() {}
    virtual QString perform() = 0;
};

#endif 