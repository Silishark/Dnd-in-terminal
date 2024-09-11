#include "fileio.h"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonParseError"
#include "QTextStream"
#include "QJsonArray"
#include "include/log/log.h"

FileIO::FileIO()
{
}

FileIO::~FileIO()
{
}

character_info FileIO::readCharacter(QString&& name)
{
    character_info info;
    info.name = name;
    QFile file("include/config/character.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("JSON File could not be opened.");
    }
    QTextStream stream(&file);
    QString str = stream.readAll();
    file.close();

    QJsonParseError jsonError;
    // ��json����ΪUTF-8�����json�ĵ��������д���һ��QJsonDocument��
    // ��������ɹ�������QJsonDocument���󣬷��򷵻�nullptr
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // �ж��Ƿ����ʧ��
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull())
    {
        qDebug("JSON Parse failed.");
    }
    QJsonObject rootObj = doc.object();
    //****************************************************************************************
    //��ȡrace��career��background��relationship_to_player�ȷ�����
    QJsonValue character = rootObj.value(name);
    if (character.type() == QJsonValue::Object)
    {
        QJsonObject characterObject = character.toObject();
        info.career = characterObject.value("career").toString();
        info.race = characterObject.value("race").toString();
        info.background = characterObject.value("background").toString();
        //*****************************************************************************************
        //��ȡstatus
        QJsonValue status = characterObject.value("status");
        if(status.type() == QJsonValue::Object)
        {
            QJsonObject statusObj = status.toObject();
            info.health = statusObj.value("health").toInt();
            info.armor = statusObj.value("armor").toInt();
        }
        else
        {
            qDebug("Status read failed.");
        }

        //��ȡaction
        QJsonValue attributes = characterObject.value("attributes");
        if(attributes.type() == QJsonValue::Object)
        {
            QJsonObject actionsObject = attributes.toObject();
            //��ȡactionsObj�е�����
            info.strength = actionsObject.value("strength").toInt();
            info.speed = actionsObject.value("speed").toInt();
            info.intelligence = actionsObject.value("intelligence").toInt();
        }
        else
        {
            qDebug("Attributes read failed.");
        }
        //*****************************************************************************************
        //��ȡ����
        QJsonValue memory = characterObject.value("memory");
        if(memory.type() == QJsonValue::Array)
        {
            QJsonArray memoryArray = memory.toArray();
            //��ȡmemoryObj�е�����
            for(int i=0;i < memoryArray.size();++i)
            {
                QJsonValue memorySingal = memoryArray.at(i);
                //��ȡmemoryObj�е�����
                info.memory.push_back(memorySingal.toString());
            }
        }
        else
        {
            qDebug("Memory read failed.");
        }

        QJsonValue actions = characterObject.value("actions");
        if(actions.type() == QJsonValue::Array)
        {
            QJsonArray actionsArray = actions.toArray();
            //��ȡactionsObj�е�����
            for(int i=0;i < actionsArray.size();++i)
            {
                QJsonValue action = actionsArray.at(i);
                info.actions.push_back(action.toString());
            }
        }
        else
        {
            qDebug("Actions read failed.");
        }
    }
    else
    {
        qDebug("Data read failed.");
    }
    return info;
}
