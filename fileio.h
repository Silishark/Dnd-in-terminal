#ifndef FILEIO_H
#define FILEIO_H

#include <QString>
#include <QVector>


class FileIO
{
public:
    static void readCharacter(const QString name);
    static void readMap(const int id);
private:
    FileIO();
    ~FileIO();
};

#endif // FILEIO_H
