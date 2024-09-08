#include "thiefselect.h"
#include "ui_thiefselect.h"

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
