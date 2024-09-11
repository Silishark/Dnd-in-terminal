#include "thiefselect.h"
#include "ui_thiefselect.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "include/log/log.h"
#include "include/game/game.h"

extern Game* game;

ThiefSelect::ThiefSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThiefSelect)
{
    ui->setupUi(this);
}

ThiefSelect::~ThiefSelect()
{
    delete ui;
}

void ThiefSelect::on_returnButton_clicked()
{
    this->close();
    emit returnToCareerSelect();
}
