#include "fileio.h"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonParseError"
#include "QTextStream"
#include "QJsonArray"
#include <QDebug>
#include <QString>
#include "include/game/game.h"

FileIO::FileIO()
{
}

FileIO::~FileIO()
{
}

void FileIO::readCharacter(const QString name)
{
    Game::game->test();
    qDebug() << name;
    QString career,race,background;
    int health,armor;
    int speed,strength,intelligence;
    QFile file("include/config/character.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("JSON File could not be opened.");
    }
    QTextStream stream(&file);
    QString str = stream.readAll();
    file.close();

    QJsonParseError jsonError;
    // 将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。
    // 如果解析成功，返回QJsonDocument对象，否则返回nullptr
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull())
    {
        qDebug("JSON Parse failed.");
    }
    QJsonObject rootObj = doc.object();
    //****************************************************************************************
    //读取race、career、background、relationship_to_player等非数组
    QJsonValue character = rootObj.value(name);
    if (character.type() == QJsonValue::Object)
    {
        QJsonObject characterObject = character.toObject();
        career = characterObject.value("career").toString();
        race = characterObject.value("race").toString();
        background = characterObject.value("background").toString();
        //*****************************************************************************************
        //读取status
        QJsonValue status = characterObject.value("status");
        if(status.type() == QJsonValue::Object)
        {
            QJsonObject statusObj = status.toObject();
            health = statusObj.value("health").toInt();
            armor = statusObj.value("armor").toInt();
        }
        else
        {
            qDebug("Status read failed.");
        }

        //读取action
        QJsonValue attributes = characterObject.value("attributes");
        if(attributes.type() == QJsonValue::Object)
        {
            QJsonObject actionsObject = attributes.toObject();
            //读取actionsObj中的内容
            strength = actionsObject.value("strength").toInt();
            speed = actionsObject.value("speed").toInt();
            intelligence = actionsObject.value("intelligence").toInt();
            qDebug() << strength;
            qDebug() << speed;
            qDebug() << intelligence;
        }
        else
        {
            qDebug("Attributes read failed.");
        }
        //*****************************************************************************************
        //读取记忆
        QJsonValue memory = characterObject.value("memory");
        if(memory.type() == QJsonValue::Array)
        {
            QJsonArray memoryArray = memory.toArray();
            //读取memoryObj中的内容
            for(int i=0;i < memoryArray.size();++i)
            {
                QJsonValue memorySingal = memoryArray.at(i);
                //读取memoryObj中的内容
                Game::game->gamer->getUser()->addMemory(QString(memorySingal.toString()));
                qDebug() << memorySingal.toString();
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
            //读取actionsObj中的内容
            for(int i=0;i < actionsArray.size();++i)
            {
                QJsonValue action = actionsArray.at(i);
                Game::game->gamer->getUser()->addAction(QString(action.toString()));
                qDebug() << action.toString();
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
    Game::game->gamer->getUser()->init(career, race,health,armor,speed,strength,intelligence);
}
