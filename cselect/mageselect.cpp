#include "mageselect.h"
#include "ui_mageselect.h"

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
