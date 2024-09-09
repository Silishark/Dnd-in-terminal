#include "mageselect.h"
#include "ui_mageselect.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "include/log/log.h"
#include "include/game/game.h"

extern Game* game;

MageSelect::MageSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MageSelect)
{
    ui->setupUi(this);
}

MageSelect::~MageSelect()
{
    delete ui;
}

void MageSelect::on_returnButton_clicked()
{
    this->close();
    emit returnToCareerSelect();
}

void MageSelect::readJSON(const QString&& name)
{
    QFile file("include/config/teacher.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("JSON File could not be opened.");
        return;
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
        LOG_ERROR("JSON Parse failed.");
        return;
    }
    QJsonObject rootObj = doc.object();
    //****************************************************************************************
    //读取race、career、background、relationship_to_player等非数组
    QJsonObject characterObj;
    QJsonValue race, career, background, relationship_to_player;

    QJsonValue character = rootObj.value(name);
    if (character.type() == QJsonValue::Object)
    {
        // 转换为QJsonObject类型
        characterObj = character.toObject();

        race = characterObj.value("race");
        career = characterObj.value("career");
        background = characterObj.value("background");
        relationship_to_player = characterObj.value("relationship_to_player");
    }
    else
    {
        LOG_ERROR("Data read failed.");
        return;
    }
    //*****************************************************************************************
    //读取status,actions,memory,attributes 等对象
    QJsonValue health, armor, strength, speed, intelligence;

    if(character.type() == QJsonValue::Object)
    {
        QJsonValue status = characterObj.value("status");
        if(status.type() == QJsonValue::Object)
        {
            QJsonObject statusObj = status.toObject();
            health = statusObj.value("health");
            armor = statusObj.value("armor");
        }
        else
        {
            LOG_ERROR("Status read failed.");
            return;
        }

        QJsonValue attributes = characterObj.value("attributes");
        if(attributes.type() == QJsonValue::Object)
        {
            QJsonObject actionsObj = attributes.toObject();
            //读取actionsObj中的内容
            strength = actionsObj.value("strength");
            speed = actionsObj.value("speed");
            intelligence = actionsObj.value("intelligence");
        }
        else
        {
            LOG_ERROR("Attributes read failed.");
            return;
        }

        QJsonValue memory = characterObj.value("memory");
        if(memory.type() == QJsonValue::Object)
        {
            QJsonObject memoryObj = memory.toObject();
            //读取memoryObj中的内容

        }
        else
        {
            LOG_ERROR("Memory read failed.");
            return;
        }

        QJsonValue actions = characterObj.value("actions");
        if(actions.type() == QJsonValue::Object)
        {
            QJsonObject actionsObj = actions.toObject();
            //读取actionsObj中的内容
        }
        else
        {
            LOG_ERROR("Actions read failed.");
            return;
        }
    }
    else
    {
        LOG_ERROR("Object read failed.");
        return;
    }
    //game->gamer->getUser()->init(name,race.toString(),health.toInt(),armor.toInt(),speed.toInt(),strength.toInt(),intelligence.toInt());
}
