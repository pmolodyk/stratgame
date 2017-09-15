#include "node.h"

node::node(QObject *parent, int X, int Y) : QObject(parent)
{
    x = X;
    y = Y;
}

void node::draw(QPainter *painter)
{
    painter->drawEllipse(x, y, 10, 10);
}
