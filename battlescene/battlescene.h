#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QWidget>

namespace Ui {
class BattleScene;
}

class BattleScene : public QWidget
{
    Q_OBJECT

public:
    explicit BattleScene(QWidget *parent = nullptr);
    ~BattleScene();

private:
    Ui::BattleScene *ui;
};

#endif // BATTLESCENE_H
