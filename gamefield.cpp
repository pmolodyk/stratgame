#include "gamefield.h"

GameField::GameField()
{
    area = new QRect(0, 0, 1000, 500);
    paintEvent(new QPaintEvent(*(area)));
}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->begin(this);
    painter->drawRect(*area);
    painter->end();
}
