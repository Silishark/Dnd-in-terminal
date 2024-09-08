#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_enterButton_clicked()
{
    this->close();
    CareerSelect *cselect = new CareerSelect();
    cselect->show();
}

