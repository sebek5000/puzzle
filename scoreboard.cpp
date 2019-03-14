#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <fstream>
#include <string>
#include <QString>
#include <iostream>

Scoreboard::Scoreboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);
    QString temp = "Nickname Number of Tiles Number Of Moves\n";
    std::string line;
    std::ifstream myFile;
    myFile.open("score.txt");
    if (myFile.is_open())
      {
        while ( getline (myFile,line) )
        {
          temp+=QString::fromStdString(line) + "\n";
          std::cout<<line<<std::endl;
        }
        myFile.close();
      }

    ui->scoreTextBrowser->setText(temp);
    //scoreTextBrowser->show();

}

Scoreboard::~Scoreboard()
{
    delete ui;
    delete scoreTextBrowser;
}
