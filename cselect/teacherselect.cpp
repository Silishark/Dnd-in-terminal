#include "teacherselect.h"
#include "ui_teacherselect.h"

TeacherSelect::TeacherSelect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherSelect)
{
    ui->setupUi(this);
}

TeacherSelect::~TeacherSelect()
{
    delete ui;
}
