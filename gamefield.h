#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QSize>
#include <QPoint>
#include <QPaintEvent>
#include <vector>
#include <set>
#include <node.h>
#include <road.h>

class GameField : public QWidget
{
    Q_OBJECT
    public:
        GameField(QWidget * parent, int X, int Y);
        void latticeInit(void);
        std::vector<std::vector<node*>> lattice;
    private:
        int x;
        int y;
        int l = 25;
        int h = 20;
        QRect* area;
        void paintEvent(QPaintEvent*);
        std::set<road*> roads;
};

#endif // GAMEFIELD_H
