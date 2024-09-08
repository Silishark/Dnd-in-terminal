#ifndef STORYNODE_H
#define STORYNODE_H

#include <QString>

struct StoryNode
{
    StoryNode(QString text, int stage);
    ~StoryNode();
    QString text;
    int stage;
    int id;
};

#endif // STORYNODE_H
