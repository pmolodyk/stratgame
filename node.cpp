#include "node.h"

node::node(QObject *parent, int X, int Y) : QObject(parent), state(0)
{
    x = X;
    y = Y;
    state = 0;
}

void node::draw(QPainter *painter)
{
    if (state == 1)
    {
        painter->setBrush(Qt::red);
    }
    else if (state == 2)
    {
        painter->setBrush(Qt::blue);
    } else if (state == 0) {
        painter->setBrush(Qt::black);
    }
    //painter->setBrush(QColor(200, 70, 0));
    painter->drawEllipse(x, y, 10, 10);
}
