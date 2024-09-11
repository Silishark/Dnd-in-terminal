#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>

namespace Ui
{
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();
signals:
    void returnToCareerSelect();
    void enterToGame();

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
