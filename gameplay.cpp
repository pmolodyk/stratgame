#include "gameplay.h"
#include "ui_gameplay.h"

Gameplay::Gameplay(QWidget *parent) :
    QMainWindow(parent), move(0)
{
    field = new GameField();
}

Gameplay::~Gameplay()
{
}
