#ifndef THIEFSELECT_H
#define THIEFSELECT_H

#include <QWidget>

namespace Ui {
class ThiefSelect;
}

class ThiefSelect : public QWidget
{
    Q_OBJECT

public:
    explicit ThiefSelect(QWidget *parent = nullptr);
    ~ThiefSelect();
signals:
    void returnToCareerSelect();
    void enterToGame();
private slots:
    void on_returnButton_clicked();
private:
    Ui::ThiefSelect *ui;
};

#endif // THIEFSELECT_H
