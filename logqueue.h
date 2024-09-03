#ifndef LOGQUEUE_H
#define LOGQUEUE_H

#include <QQueue>
#include <QString>

class LogQueue
{
public:
    LogQueue();
    ~LogQueue();
    void push(const QString& str);
    void push(const QString&& str);
    void pop();
    qsizetype size();
    QString write_front();
    QString front();

private:
    QQueue<QString> _write;
    QQueue<QString> _read;
};

#endif // LOGQUEUE_H
