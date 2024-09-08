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

void ThiefSelect::on_returnButton_clicked()
{
    this->close();
    emit returnToCareerSelect();
}
