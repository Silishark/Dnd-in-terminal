#include "battlescene.h"
#include "ui_battlescene.h"

BattleScene::BattleScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BattleScene)
{
    ui->setupUi(this);
}

BattleScene::~BattleScene()
{
    delete ui;
}
