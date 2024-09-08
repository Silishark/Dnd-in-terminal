#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "include/ui/cselect/careerselect.h"

namespace Ui
{
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_enterButton_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
