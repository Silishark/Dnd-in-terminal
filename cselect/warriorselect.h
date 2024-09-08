#ifndef WARRIORSELECT_H
#define WARRIORSELECT_H

#include <QWidget>

namespace Ui {
class WarriorSelect;
}

class WarriorSelect : public QWidget
{
    Q_OBJECT

public:
    explicit WarriorSelect(QWidget *parent = nullptr);
    ~WarriorSelect();

private:
    Ui::WarriorSelect *ui;
};

#endif // WARRIORSELECT_H
