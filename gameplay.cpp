#include "gameplay.h"
#include "ui_gameplay.h"

Gameplay::Gameplay(QWidget *parent) :
    QMainWindow(parent)
{
    field = new GameField();
}

Gameplay::~Gameplay()
{
}
