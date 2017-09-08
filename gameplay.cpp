#include "gameplay.h"
#include "ui_gameplay.h"

Gameplay::Gameplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gameplay)
{
    ui->setupUi(this);
}

Gameplay::~Gameplay()
{
    delete ui;
}
