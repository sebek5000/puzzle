#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
