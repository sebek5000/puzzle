#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <string>

#include "listofbestplayers.h"
template<> std::map<int, int> ListOfBestPlayers<int>::bestFactor = *(new std::map<int, int>());

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ListOfBestPlayers<int>::getInstance("moves.txt");
    ListOfBestPlayers<int>::updateIfBest(13, 790);

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
