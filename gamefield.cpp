#include "gamefield.h"

GameField::GameField()
{
    area = new QRect(0, 0, 1220, 720);
    resize(1220, 720);
    show();
    //paintEvent(new QPaintEvent(*(area)));
}

void GameField::latticeInit(void)
{
    for (int i = 0; i <= 1200; i += 500)
    {
        lattice.push_back(std::vector<node*>());
        for (int j = 0; j <= 700; j += 50)
        {
            lattice[i / 50].push_back(new node(0, i, j));
        }
    }
}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->setPen(Qt::black);
    painter->setBrush(QColor(100, 100, 100));
    painter->drawRect(*area);
    painter->setBrush(Qt::blue);
    for (int i = 0; i <= 1200; i += 50)
    {
        for (int j = 0; j <= 700; j += 50)
        {
            painter->drawEllipse(i, j, 10, 10);
        }
    }
    painter->end();
}
