#include "logqueue.h"
#include "qdebug.h"
#include <mutex>
LogQueue::LogQueue(): _write(), _read()
{
}

LogQueue::~LogQueue()
{
}

void LogQueue::push(const QString& str)
{
    std::mutex mtx;
    std::lock_guard lock(mtx);
    if(_read.size() >= 256)
    {
        _write=std::move(_read);
        _read=QQueue<QString>();
    }
    _read.push_back(str);
}

void LogQueue::push(const QString&& str)
{
    std::mutex mtx;
    std::lock_guard lock(mtx);
    if(_read.size() >= 256)
    {
        _write=std::move(_read);
        _read=QQueue<QString>();
    }
    _read.push_back(str);
}

void LogQueue::pop()
{
    std::mutex mtx;
    std::lock_guard lock(mtx);
    if(_read.size() > 0)
        _read.pop_front();
}

QString LogQueue::front()
{
    std::mutex mtx;
    std::lock_guard lock(mtx);
    if(_write.size() > 0)
        return _write.front();
    return "";
}

qsizetype LogQueue::size()
{
    return _read.size() + _write.size();
}
