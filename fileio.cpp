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

constexpr auto MAP_LENGTH = 96;
constexpr auto MAP_WIDTH = 60;


FileIO::FileIO()
{
}

FileIO::~FileIO()
{
}

void FileIO::readCharacter(const QString name)
{
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
        career = characterObject.value("career").toString();
        race = characterObject.value("race").toString();
        background = characterObject.value("background").toString();
        //*****************************************************************************************
        //��ȡstatus
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

        //��ȡaction
        QJsonValue attributes = characterObject.value("attributes");
        if(attributes.type() == QJsonValue::Object)
        {
            QJsonObject actionsObject = attributes.toObject();
            //��ȡactionsObj�е�����
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
            //��ȡactionsObj�е�����
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

void FileIO::readMap(const int id)
{
    QFile file;
    switch (id)
    {
    case 1:
        file.setFileName("include/config/map1.json");
        break;
    case 2:
        file.setFileName("include/config/map2.json");
        break;
    case 3:
        file.setFileName("include/config/map3.json");
        break;
    default:
        file.setFileName("include/config/map1.json");
        break;
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug("JSON File could not be opened.");
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
    QJsonValue map = rootObj.value(QString::number(id));
    if (map.type() == QJsonValue::Array)
    {
        QJsonArray mapArrayArray = map.toArray();
        //��ȡmapArrayArray�е�����
        for(int i=0; i < MAP_LENGTH; ++i)
        {
            QJsonValue mapArray = mapArrayArray.at(i);
            //��ȡmapArray�е�����
            for(int j=0; j < MAP_WIDTH; ++j)
            {
                QJsonValue mapSingle = mapArray.toArray().at(j);
                //��ȡmapSingle�е�����
                QJsonObject mapObject = mapSingle.toObject();
                Game::game->map->addMapNode(mapObject.value("texture").toInt(), mapObject.value("path").toString(), mapObject.value("level").toInt(), i, j);
            }
        }
    }
    else
    {
        qDebug("Data read failed.");
    }
}
