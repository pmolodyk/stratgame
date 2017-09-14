#include "gamefield.h"

GameField::GameField()
{
    area = new QRect(0, 0, 200, 300);
    show();
    //paintEvent(new QPaintEvent(*(area)));
}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->setPen(Qt::red);
    painter->drawText(*area, Qt::AlignCenter, "Data");
    *area = event->rect();
    painter->drawRect(*area);
}
