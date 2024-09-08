#ifndef TEACHERSELECT_H
#define TEACHERSELECT_H

#include <QWidget>

namespace Ui {
class TeacherSelect;
}

class TeacherSelect : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherSelect(QWidget *parent = nullptr);
    ~TeacherSelect();

private:
    Ui::TeacherSelect *ui;
};

#endif // TEACHERSELECT_H
