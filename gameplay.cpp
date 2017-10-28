#include "gameplay.h"
#include "ui_gameplay.h"
#include <QPushButton>
#include <QMainWindow>
#include <string>
#include <sstream>
#include <player.h>
#include <statusbar.h>
Gameplay::Gameplay(QWidget *parent) : QMainWindow(parent)
{
    //QMainWindow(parent);
    move = 0;
    players[0] = new Player(1000, 1);
    players[1] = new Player(1000, 2);
    buildroad1 = new QInputDialog(this);
    buildroad2 = new QInputDialog(this);
    field = new GameField(this, x, y);
    menu = new Menu(this, x, y);
    statusbar = new Statusbar(this, 1000, 1000, x, y);
    resize(x, y);
    show();
    QObject::connect(menu->endturn1, SIGNAL(clicked()), menu->endturn2, SLOT(show()));
    QObject::connect(menu->endturn1, SIGNAL(clicked()), menu->build2, SLOT(show()));
    QObject::connect(menu->endturn1, SIGNAL(clicked()), menu->endturn1, SLOT(hide()));
    QObject::connect(menu->endturn1, SIGNAL(clicked()), menu->build1, SLOT(hide()));
    QObject::connect(menu->endturn2, SIGNAL(clicked()), menu->endturn1, SLOT(show()));
    QObject::connect(menu->endturn2, SIGNAL(clicked()), menu->build1, SLOT(show()));
    QObject::connect(menu->endturn2, SIGNAL(clicked()), menu->endturn2, SLOT(hide()));
    QObject::connect(menu->endturn2, SIGNAL(clicked()), menu->build2, SLOT(hide()));
    QObject::connect(menu->build1, SIGNAL(clicked()), buildroad1, SLOT(show()));
    QObject::connect(buildroad1, SIGNAL(textValueSelected(QString)), this, SLOT(tonumbers1(QString)));
    QObject::connect(menu->build2, SIGNAL(clicked()), buildroad2, SLOT(show()));
    QObject::connect(buildroad2, SIGNAL(textValueSelected(QString)), this, SLOT(tonumbers2(QString)));
}

void Gameplay::tonumbers1(QString s) {
    int turn = 1;
    int x1, x2, y1, y2;
    std::string stds = s.toStdString();
    std::istringstream is(stds);
    is >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int cost = 100 * ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (players[0]->getmoney() >= cost && ((field->lattice[x1][y1]->getstate() == 1) || (field->lattice[x2][y2]->getstate() == 1))) {
        emit readyroad(x1, y1, x2, y2, turn);
    } else {
        emit error(1);
    }
}
void Gameplay::tonumbers2(QString s) {
    int turn = 2;
    int x1, x2, y1, y2;
    std::string stds = s.toStdString();
    std::istringstream is(stds);
    is >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int cost = 100 * ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (players[1]->getmoney() >= cost && ((field->lattice[x1][y1]->getstate() == 2) || (field->lattice[x2][y2]->getstate() == 2))) {
        emit readyroad(x1, y1, x2, y2, turn);
    } else {
        emit error(1);
    }
}
Gameplay::~Gameplay()
{
}
