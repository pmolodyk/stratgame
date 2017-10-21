#include "node.h"

node::node(QObject *parent, int X, int Y) : QObject(parent), state(0)
{
    x = X;
    y = Y;
}

void node::draw(QPainter *painter)
{
    if (state == 1)
    {
        painter->setBrush(Qt::green);
    }
    else if (state == 2)
    {
        painter->setBrush(Qt::blue);
    }
    painter->drawEllipse(x, y, 10, 10);
    painter->setBrush(QColor(200, 70, 0));
}
