#include "gamefield.h"

#include <QPainter>
#include <QTimer>
GameField::GameField(QWidget * parent, int X, int Y) : QWidget(parent)
{
    x = X;
    y = Y;
    area = new QRect(x / 10, 0, 8 * x / 10, y);
    //paintEvent(new QPaintEvent(*(area)));
    //area = new QRect(0, 0, 1220, 720);
    resize(x, y);
    //area = new QRect(0, 0, 1500, 720);
    latticeInit();
    //paintEvent(new QPaintEvent(*(area)));
}

void GameField::latticeInit(void)
{
    for (int i = 0; i < l; i++)
    {
        lattice.push_back(std::vector<node*>());
        for (int j = 0; j < h; j++)
        {
            lattice[i].push_back(new node(0, (i * x * 8 / 10 / l) + x / 10, j * y / h));
            if (i == 0 && j >= (h / 2 - 1) && j <= (h / 2 + 1))
            {
                lattice[i][j]->setstate(1);
            }
            else if (i == l - 1 && j >= (h / 2 - 1) && j <= (h / 2 + 1))
            {
                lattice[i][j]->setstate(2);
            }
        }
    }
}

void GameField::paintEvent(QPaintEvent*)
{
    QPainter* painter = new QPainter(this);
    //painter->begin(this);
    painter->drawRect(*area);
    painter->setPen(Qt::black);
    painter->setBrush(QColor(170, 170, 170));
    painter->drawRect(*area);
    painter->setBrush(QColor(200, 70, 0));
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < h; j++)
        {
            lattice[i][j]->draw(painter);
        }
    }
    for (auto elem : roads) {
        elem->draw(painter);
    }
    painter->end();
}
