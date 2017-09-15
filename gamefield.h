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
#include <node.h>

class GameField : public QWidget
{
    Q_OBJECT
    public:
        GameField();
        void latticeInit(void);
    private:
        std::vector<std::vector<node*>> lattice;
        QRect* area;
        void paintEvent(QPaintEvent *event);
};

#endif // GAMEFIELD_H
