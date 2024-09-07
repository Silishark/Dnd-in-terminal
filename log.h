#ifndef LOG_H
#define LOG_H
#include "logqueue.h"
#include <QDebug>
#include <mutex>
#include <QFile>
#include <QDir>

class Log
{
public:
    static Log* instance();
    void add(int level, const QString& str);
    Log(Log const&) = delete;
    void operator=(Log const&) = delete;
private:
    Log();
    ~Log();
    void write();
    void init();
    void clear();
private:
    std::mutex m_mutex;
    std::condition_variable m_cond;
    QString m_path;
    LogQueue m_queue;
};

#define LOG_BASE(level, content) \
do \
{\
        Log* log = Log::instance(); \
        log->add(level, content); \
} while(0);

#define LOG_DEBUG(content) do {LOG_BASE(0, content)} while(0);
#define LOG_INFO(content) do {LOG_BASE(1, content)} while(0);
#define LOG_WARN(content) do {LOG_BASE(2, content)} while(0);
#define LOG_ERROR(content) do {LOG_BASE(3, content)} while(0);

#endif // LOG_H
