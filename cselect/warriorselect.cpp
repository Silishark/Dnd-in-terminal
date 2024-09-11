#include "warriorselect.h"
#include "ui_warriorselect.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "include/io/fileio.h"

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

void WarriorSelect::on_AldricButton_clicked()
{
    FileIO::readCharacter("Aldric");
    this->hide();
    MainScene *mainScene = new MainScene();
    connect(mainScene,&MainScene::returnToCareerSelect,this,&QWidget::show);
    mainScene->setAttribute(Qt::WA_DeleteOnClose);
    mainScene->show();
}

void WarriorSelect::on_JorvanButton_clicked()
{
    FileIO::readCharacter("Jorvan");
    this->hide();
    MainScene *mainScene = new MainScene();
    connect(mainScene,&MainScene::returnToCareerSelect,this,&QWidget::show);
    mainScene->setAttribute(Qt::WA_DeleteOnClose);
    mainScene->show();
}

