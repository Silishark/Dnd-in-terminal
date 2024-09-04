#ifndef STORYMAP_H
#define STORYMAP_H

#include "storynode.h"

class StoryMap
{
public:
    StoryMap();
    ~StoryMap();
private:
    QVector<QVector<StoryNode*>> m_map;
};

#endif // STORYMAP_H
