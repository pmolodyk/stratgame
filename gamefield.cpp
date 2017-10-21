#include "gamefield.h"

#include <QPainter>
#include <QTimer>
GameField::GameField()
{
    area = new QRect(0, 0, 1000, 500);
    paintEvent(new QPaintEvent(*(area)));
    area = new QRect(0, 0, 1220, 720);
    resize(1220, 720);
    area = new QRect(0, 0, 1500, 720);
    resize(1500, 720);
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
    QPainter painter;
    painter.begin(this);

    painter.end();
}
