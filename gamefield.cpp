#include "gamefield.h"

GameField::GameField()
{
    area = new QRect(0, 0, 1220, 720);
    resize(1220, 720);
    latticeInit();
    show();
    //paintEvent(new QPaintEvent(*(area)));
}

void GameField::latticeInit(void)
{
    for (int i = 0; i <= 24; i++)
    {
        lattice.push_back(std::vector<node*>());
        for (int j = 0; j <= 14; j++)
        {
            lattice[i].push_back(new node(0, i * 50, j * 50));
            if (i == 0)
            {
                lattice[i][j]->setstate(1);
            }
            else if (i == 24)
            {
                lattice[i][j]->setstate(2);
            }
        }
    }
}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->setPen(Qt::black);
    painter->setBrush(QColor(170, 170, 170));
    painter->drawRect(*area);
    painter->setBrush(QColor(200, 70, 0));
    for (int i = 0; i <= 24; i++)
    {
        for (int j = 0; j <= 14; j++)
        {
            lattice[i][j]->draw(painter);
        }
    }
    painter->end();
}
