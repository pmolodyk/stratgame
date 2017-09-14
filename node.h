#ifndef NODE_H
#define NODE_H

#include <QObject>

class node : public QObject
{
    Q_OBJECT
public:
    explicit node(QObject *parent = 0);

signals:

public slots:
};

#endif // NODE_H