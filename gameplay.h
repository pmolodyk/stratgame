#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QMainWindow>
#include <gamefield.h>

class Gameplay;

class Gameplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gameplay(QWidget *parent = 0);
    ~Gameplay();

private:
    GameField* field;
    int move;
};

#endif // GAMEPLAY_H
