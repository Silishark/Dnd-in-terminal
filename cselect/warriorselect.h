#ifndef WARRIORSELECT_H
#define WARRIORSELECT_H

#include <QWidget>
#include "include/game/game.h"

extern Game* game;

namespace Ui
{
class WarriorSelect;
}

class WarriorSelect : public QWidget
{
    Q_OBJECT

public:
    explicit WarriorSelect(QWidget *parent = nullptr);
    ~WarriorSelect();

signals:
    void returnToCareerSelect();
    void enterToGame();
private slots:
    void on_returnButton_clicked();
    void on_AldricButton_clicked();

private:
    void readJson(const QString&& name);
    Ui::WarriorSelect *ui;
};

#endif // WARRIORSELECT_H
