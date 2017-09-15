#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QPaintEvent>
#include <QPainter>

class node : public QObject
{
    Q_OBJECT
public:
    explicit node(QObject *parent = 0, int X = 0, int Y = 0);
    void paintEvent(QPaintEvent *event);
    void draw(QPainter* painter);
private:
    int x;
    int y;
signals:

public slots:
};

#endif // NODE_H
