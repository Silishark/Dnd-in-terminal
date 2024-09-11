#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "include/ui/cselect/careerselect.h"
#include "include/log/log.h"

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
    void on_exitButton_clicked();
private:
    Ui::Menu *ui;
};

#endif // MENU_H
