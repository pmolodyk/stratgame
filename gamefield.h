#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QSize>
#include <QPoint>

class GameField
{
    public:
        GameField();
    private:
        QRect* area;
};

#endif // GAMEFIELD_H
