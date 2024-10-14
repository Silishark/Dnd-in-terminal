#include "llm.h"
#include "QDebug"

QString LLM::getResponse(QString input)
{
    //��ʼ��py
    Py_Initialize();
    Py_SetPythonHome(L"include\Python312");
    if(Py_IsInitialized())
    {
        qDebug()<<"Python initialized successfully";
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    //�򿪵���py�ļ�
    PyObject* pModule = PyImport_ImportModule("LLM");
    if(pModule)
    {
        qDebug()<<"LLM imported successfully";
    }
    else
    {
        qDebug()<<"LLM import failed";
    }

    //��ȡpy�ļ��еĺ���
    PyObject* pFunc = PyObject_GetAttrString(pModule, "getResponse");
    if(pFunc && PyCallable_Check(pFunc))
    {
        qDebug()<<"Function retrieved successfully";
    }
    else
    {
        qDebug()<<"Function retrieval failed";
    }

    //����
    PyObject* pPara = PyTuple_New(1);
    PyTuple_SetItem(pPara, 0, PyUnicode_FromString(input.toStdString().c_str()));
    //���ú���
    PyObject* pValue = PyObject_CallObject(pFunc, pPara);
    if(pValue)
    {
        qDebug()<<"Function called successfully";
    }
    else
    {
        qDebug()<<"Function call failed";
    }
    QString result(PyUnicode_AsUTF8(pValue));
    Py_Finalize();
    return result;
}
