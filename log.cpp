#include "log.h"

Log::Log()
{
    init();
}

Log::~Log()
{
    qDebug() << "Log::~Log()";
    clear();
}

Log* Log::instance()
{
    static Log log;
    return &log;
}

void Log::init()
{
    QDir* tmp = new QDir(QDir::currentPath());
    m_path = tmp->path() + "/log/log.txt";
    QFile file(m_path);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen())
    {
        qDebug() << "Failed to open file" << m_path;
    }
    file.close();
}

void Log::write()
{
    std::lock_guard lock(m_mutex);
    QFile file(m_path);
    file.open(QIODevice::Append);
    while(m_queue.size() > 0)
    {
        file.write(m_queue.front().toUtf8());
        file.write("\n");
        m_queue.pop();
    }
    file.close();
}

void Log::add(int level, const QString& str)
{
    QString log = "";
    switch(level)
    {
    case 0:
        log+="[DEBUG]";
        break;
    case 1:
        log+="[INFO]";
        break;
    case 2:
        log+="[WARN]";
        break;
    case 3:
        log+="[ERROR]";
        break;
    default:
        log+="[DEBUG]";
        break;
    }
    m_queue.push(log + str);
    if(m_queue.size() >= 128 || level >= 3)
        write();
}

void Log::clear()
{
    m_queue.swap();
    write();
}
