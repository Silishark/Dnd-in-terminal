#include "teacherselect.h"
#include "ui_teacherselect.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "include/log/log.h"
#include "include/game/game.h"

extern Game* game;

TeacherSelect::TeacherSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherSelect)
{
    ui->setupUi(this);
}

TeacherSelect::~TeacherSelect()
{
    delete ui;
}

void TeacherSelect::on_returnButton_clicked()
{
    this->close();
    emit returnToCareerSelect();
}
