#ifndef FILEIO_H
#define FILEIO_H

#include <QString>
#include <QVector>


class FileIO
{
public:
    static void readCharacter(const QString name);
private:
    FileIO();
    ~FileIO();
};

#endif // FILEIO_H
