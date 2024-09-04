#ifndef STORYNODE_H
#define STORYNODE_H

#include <QVector>
#include <unordered_map>
#include <QString>

class StoryNode
{
public:
    StoryNode(QString text, int stage);
    ~StoryNode();
    void push();
private:
    QString m_text;
    QVector<QString> m_options;
    std::unordered_map<QString, StoryNode*> m_outcomes;
    int m_stage;
    int m_id;
};

#endif // STORYNODE_H
