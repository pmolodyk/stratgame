#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QSize>
#include <QPoint>
#include <QPaintEvent>

class GameField : public QWidget
{
    Q_OBJECT
    public:
        GameField();
    private:
        QRect* area;
        void paintEvent(QPaintEvent *event);
};

#endif // GAMEFIELD_H
