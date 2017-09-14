#include "gamefield.h"

GameField::GameField()
{
    area = new QRect(0, 0, 1150, 700);
    resize(1150, 700);
    show();
    //paintEvent(new QPaintEvent(*(area)));
}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::yellow);
    painter->drawRect(*area);
}
