#include "scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);
}

Scoreboard::~Scoreboard()
{
    delete ui;
}
