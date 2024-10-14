#ifndef LLM_H
#define LLM_H

#include <Python.h>
#include <QString>

class LLM
{
public:
    static QString getResponse(QString input);
private:
    LLM();
    ~LLM() = default;
};

#endif // LLM_H
