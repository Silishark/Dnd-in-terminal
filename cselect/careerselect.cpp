#include "careerselect.h"
#include "ui_careerselect.h"
#include "include/game/game.h"

extern Game* game;

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
    connect(mage,&MageSelect::returnToCareerSelect,this,&QWidget::show);
    connect(mage,&MageSelect::enterToGame,this,&QWidget::close);
    mage->setAttribute(Qt::WA_DeleteOnClose);
    //game->gamer->setCareer(MAGE);
    mage->show();
}

void CareerSelect::on_warriorButton_clicked()
{
    this->hide();
    WarriorSelect *warrior = new WarriorSelect();
    connect(warrior,&WarriorSelect::returnToCareerSelect,this,&QWidget::show);
    warrior->setAttribute(Qt::WA_DeleteOnClose);
    //game->gamer->setCareer(WARRIOR);
    warrior->show();
}

void CareerSelect::on_thiefButton_clicked()
{
    this->hide();
    ThiefSelect *thief = new ThiefSelect();
    connect(thief,&ThiefSelect::returnToCareerSelect,this,&QWidget::show);
    thief->setAttribute(Qt::WA_DeleteOnClose);
    //game->gamer->setCareer(THIEF);
    thief->show();
}

void CareerSelect::on_teacherButton_clicked()
{
    this->hide();
    TeacherSelect *teacher = new TeacherSelect();
    connect(teacher,&TeacherSelect::returnToCareerSelect,this,&QWidget::show);
    teacher->setAttribute(Qt::WA_DeleteOnClose);
    //game->gamer->setCareer(TEACHER);
    teacher->show();
}
