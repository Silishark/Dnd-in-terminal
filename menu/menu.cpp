#include "menu.h"
#include "ui_menu.h"

extern Game* game;

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
    game->init();
    CareerSelect *cselect = new CareerSelect();
    cselect->show();
}

void Menu::on_exitButton_clicked()
{
    this->close();
}
