#ifndef FILEIO_H
#define FILEIO_H

#include <QString>
#include <QVector>

struct character_info
{
    QString name;
    QString career;
    QString race;
    QString background;
    QString relationship_to_player;
    int health;
    int armor;
    QVector<QString> actions;
    QVector<QString> memory;
    int strength;
    int speed;
    int intelligence;
};

class FileIO
{
public:
    static character_info readCharacter(QString&& name);
    static character_info readCharacter(const QString& name);
private:
    FileIO();
    ~FileIO();
};

#endif // FILEIO_H
