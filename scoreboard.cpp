#include "scoreboard.h"
#include "ui_scoreboard.h"
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
    text+="number   number   username\n";
    text+="of tiles    of moves\n";
    text += ListOfBestPlayers<int>::stringFromMap();
    text += "\n\n\n";
    text+="number   time                        username\n";
    text+="of tiles     in min\n";
    text += ListOfBestPlayers<double>::stringFromMap();

    ui->scoreTextBrowser->setText(QString::fromStdString(text));
}

Scoreboard::~Scoreboard(){
    delete ui;
    delete scoreTextBrowser;
}

void Scoreboard::on_newGameButton_clicked(){
    MainWindow *w = new MainWindow();
    w->show();
    this->hide();
}
