#include "mageselect.h"
#include "ui_mageselect.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "log/log.h"
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

void MageSelect::readJSON()
{
    /*
    QFile file("include/config/mage.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_DEBUG("JSON File could not be opened.");
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonObject obj = doc.object();
    QJsonArray array = obj["mage"].toArray();
    foreach(const QJsonValue & value, array)
    {
        QJsonObject obj = value.toObject();
    }
    file.close();
    */
}
