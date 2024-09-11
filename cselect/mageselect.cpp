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
