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

private:
    Ui::ThiefSelect *ui;
};

#endif // THIEFSELECT_H
