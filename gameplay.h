#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QMainWindow>

namespace Ui {
class Gameplay;
}

class Gameplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gameplay(QWidget *parent = 0);
    ~Gameplay();

private:
    Ui::Gameplay *ui;
};

#endif // GAMEPLAY_H
