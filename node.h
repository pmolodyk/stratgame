#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <vector>

class node : public QObject
{
    Q_OBJECT
public:
    explicit node(QObject *parent = 0, int X = 0, int Y = 0);
    void paintEvent(QPaintEvent *event);
    void draw(QPainter* painter);
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void setstate(int s)
    {
        state = s;
    }
    int getstate(void)
    {
        return state;
    }
private:
    int x;
    int y;
    int state;
    std::vector<node*> a;
signals:

public slots:
};

#endif // NODE_H
