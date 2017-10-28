#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QMainWindow>
#include <gamefield.h>
#include <menu.h>
#include <statusbar.h>
#include <QInputDialog>
#include <player.h>
class Gameplay;

class Gameplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gameplay(QWidget *parent = nullptr);
    ~Gameplay();

private:
    int x = 1320;
    int y = 700;
    GameField* field;
    Menu* menu;
    int move;
    Statusbar* statusbar;
    QInputDialog* buildroad1;
    QInputDialog* buildroad2;
    Player* players[2];
signals:
    void readyroad(int, int, int, int, int);
    void error(int);
public slots:
    void tonumbers1(QString);
    void tonumbers2(QString);
};

#endif // GAMEPLAY_H
