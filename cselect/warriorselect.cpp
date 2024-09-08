#include "warriorselect.h"
#include "ui_warriorselect.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "log/log.h"

WarriorSelect::WarriorSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WarriorSelect)
{
    ui->setupUi(this);
}

WarriorSelect::~WarriorSelect()
{
    delete ui;
}

void WarriorSelect::on_returnButton_clicked()
{
    this->close();
    emit returnToCareerSelect();
}

void readJson()
{
    QFile file("include/config/warrior.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_DEBUG("JSON File could not be opened.");
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonObject obj = doc.object();
    QJsonArray array = obj["warrior"].toArray();
    foreach(const QJsonValue & value, array)
    {
        QJsonObject obj = value.toObject();
    }
    file.close();
}
