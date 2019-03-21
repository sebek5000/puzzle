#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <string>
#include "listofbestplayers.h"
template<> std::map<int, User<int>> ListOfBestPlayers<int>::userNumberOfTilesMap = *(new std::map<int, User<int>>());

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ListOfBestPlayers<int>::getInstance("moves.txt");
    ListOfBestPlayers<int>::updateIfBest(13, 27, "stefan");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete puzzle;
}

void MainWindow::on_startButton_clicked()
{
    int sizeNumber = ui->sizeTextEdit->toPlainText().toInt(); //0 if convertion fails
     std::string nickname = ui->nickTextEdit->toPlainText().toStdString();
    //TODO maybe exception or something
    if(sizeNumber>=2){
        std::cout<<sizeNumber<<std::endl;
        this->hide();
        puzzle = new PuzzlePanel(sizeNumber, nickname, this);
        puzzle->show();
    }


}
