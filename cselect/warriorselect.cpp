#include "warriorselect.h"
#include "ui_warriorselect.h"

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
