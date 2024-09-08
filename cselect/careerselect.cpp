#include "careerselect.h"
#include "ui_careerselect.h"

CareerSelect::CareerSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CareerSelect)
{
    ui->setupUi(this);
}

CareerSelect::~CareerSelect()
{
    delete ui;
}

void CareerSelect::on_mageButton_clicked()
{
    this->hide();
    MageSelect *mage = new MageSelect();
    mage->show();
}

void CareerSelect::on_warriorButton_clicked()
{
    this->hide();
    WarriorSelect *warrior = new WarriorSelect();
    warrior->show();
}

void CareerSelect::on_thiefButton_clicked()
{
    this->hide();
    ThiefSelect *thief = new ThiefSelect();
    thief->show();
}

void CareerSelect::on_teacherButton_clicked()
{
    this->hide();
    TeacherSelect *teacher = new TeacherSelect();
    teacher->show();
}
