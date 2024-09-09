#ifndef MAGESELECT_H
#define MAGESELECT_H

#include <QWidget>

namespace Ui
{
class MageSelect;
}

class MageSelect : public QWidget
{
    Q_OBJECT

public:
    explicit MageSelect(QWidget *parent = nullptr);
    ~MageSelect();
signals:
    void returnToCareerSelect();
    void enterToGame();
private slots:
    void on_returnButton_clicked();
private:
    void readJSON(const QString &&name);
    Ui::MageSelect *ui;
};

#endif // MAGESELECT_H
