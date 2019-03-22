#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <fstream>
#include <string>
#include <QString>
#include <iostream>
#include "listofbestplayers.h"
#include "mainwindow.h"
Scoreboard::Scoreboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);
    std::string text;
    text = ListOfBestPlayers<int>::stringFromMap();
    text += "\n\n\n";
    text += ListOfBestPlayers<double>::stringFromMap();

    ui->scoreTextBrowser->setText(QString::fromStdString(text));
}

Scoreboard::~Scoreboard()
{
    delete ui;
    delete scoreTextBrowser;
}

void Scoreboard::on_newGameButton_clicked()
{
    MainWindow w;
    w.show();
    this->hide();

}
