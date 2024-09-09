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
signals:
    void returnToCareerSelect();
    void enterToGame();
private slots:
    void on_returnButton_clicked();
private:
    void readJson(const QString&& name);
    Ui::TeacherSelect *ui;
};

#endif // TEACHERSELECT_H
