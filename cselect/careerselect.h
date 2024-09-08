#ifndef CAREERSELECT_H
#define CAREERSELECT_H

#include <QWidget>
#include "mageselect.h"
#include "warriorselect.h"
#include "thiefselect.h"
#include "teacherselect.h"

namespace Ui
{
class CareerSelect;
}

class CareerSelect : public QWidget
{
    Q_OBJECT

public:
    explicit CareerSelect(QWidget *parent = nullptr);
    ~CareerSelect();
public slots:
    void on_mageButton_clicked();
    void on_warriorButton_clicked();
    void on_thiefButton_clicked();
    void on_teacherButton_clicked();
private:
    Ui::CareerSelect *ui;
};

#endif // CAREERSELECT_H
