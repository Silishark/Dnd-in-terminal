#include "log.h"

Log::Log():m_path(QString(".../log/log.txt"))
{
    init();
}

Log::~Log()
{
    if(m_queue.size() > 0)
        write();
}

Log* Log::instance()
{
    if(!m_instance)
        m_instance = new Log();
    return m_instance;
}

void Log::init()
{
    QFile file(m_path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
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
    while(m_queue.size() > 256)
    {
        file.write(m_queue.front().toUtf8());
        file.write("\n");
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
    if(m_queue.size() >= 256)
        write();
}
