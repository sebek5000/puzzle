#include "puzzlepanel.h"
#include "ui_puzzlepanel.h"
#include <vector>
#include <string>
#include "qpushbutton.h"
#include "tile.h"
#include "scoreboard.h"
#include <fstream>
#include "mainwindow.h"
#include "listofbestplayers.h"

template<> std::map<int, User<int>> ListOfBestPlayers<int>::userNumberOfTilesMap = *(new std::map<int, User<int>>());
template<> std::fstream ListOfBestPlayers<int>::file = std::fstream();
template<> std::string ListOfBestPlayers<int>::fileName = "";

template<> std::map<int, User<double>> ListOfBestPlayers<double>::userNumberOfTilesMap = *(new std::map<int, User<double>>());
template<> std::fstream ListOfBestPlayers<double>::file = std::fstream();
template<> std::string ListOfBestPlayers<double>::fileName = "";
PuzzlePanel::PuzzlePanel(int number, std::string nickname, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PuzzlePanel)
{
    ui->setupUi(this);
    this->nickname = nickname;
    numberOfTiles = number;
    beginningOfTimeCalculation = std::time(nullptr);

    for (int i=0; i<numberOfTiles; i++){
        for(int j=0; j<numberOfTiles; j++){
            buttons[i][j] = new Tile(numberOfTiles, this);
            buttons[i][j]->setShownNumber(j+numberOfTiles*i);
            buttons[i][j]->setNumber(j+numberOfTiles*i);
            buttons[i][j]->move(40*j, 40*i);
            buttons[i][j]->resize(40,40);
            if(i==numberOfTiles-1 && j==numberOfTiles-1){
                buttons[i][j]->setShownNumber(-1);
                buttons[i][j]->changeIsBlank();
                blankCoordinateX = j;
                blankCoordinateY = i;
                this->setFocus();
            }
        }}
    for(int i=0; i<100; i++){//random setting of the board
        int arrow = rand() % 4;
        switch(arrow)
            {
            case 0:{
               if(blankCoordinateY==0)
                   std::cout<<"Poza ekranem!"<<std::endl;
               else{
                switchTiles(0, -1);
               }
        }
                break;
        case 1:{
                if(blankCoordinateY==numberOfTiles-1)
                    std::cout<<"Poza ekranem!"<<std::endl;
                else{
                switchTiles(0, 1);
                }
      }
                break;

        case 2:{
            if(blankCoordinateX==0)
                std::cout<<"Poza ekranem!"<<std::endl;
            else{
             switchTiles(-1, 0);
            }
                }break;
        case 3:{
                if(blankCoordinateX==numberOfTiles-1)
                    std::cout<<"Poza ekranem!"<<std::endl;
                else{
                 switchTiles(1,0);
                }
        }break;
            default:
                    std::cout<<"ERROR"<<std::endl;;
                    break;
            }
    }
}

PuzzlePanel::~PuzzlePanel(){
    delete winningButton;
    delete ui;
}

void PuzzlePanel::keyPressEvent(QKeyEvent *event){

    switch(event->key())
        {
        case Qt::Key_Up:{
           std::cout<<"Kliknieta strzala  up"<<std::endl;
           if(blankCoordinateY==0)
               std::cout<<"Poza ekranem!"<<std::endl;
           else{
            switchTiles(0, -1);
           }
          }
          break;
    case Qt::Key_Down:{
            std::cout<<"Kliknieta strzala down"<<std::endl;
            if(blankCoordinateY==numberOfTiles-1)
                std::cout<<"Poza ekranem!"<<std::endl;
            else{
            switchTiles(0, 1);
            }
           }
           break;

    case Qt::Key_Left:{
        std::cout<<"Kliknieta strzala left"<<std::endl;
        if(blankCoordinateX==0)
            std::cout<<"Poza ekranem!"<<std::endl;
        else{
         switchTiles(-1, 0);
        }
            }break;
    case Qt::Key_Right:{
            std::cout<<"Kliknieta strzala right"<<std::endl;
            if(blankCoordinateX==numberOfTiles-1)
                std::cout<<"Poza ekranem!"<<std::endl;
            else{
             switchTiles(1,0);
            }
    }break;
        default:
                event->ignore();
                break;
        }
    numberOfMoves++;
    if(buttons[blankCoordinateY][blankCoordinateX]->getNumber()==buttons[blankCoordinateY][blankCoordinateX]->getShownNumber()){
        bool isWin = true;
        for (int i=0; i<numberOfTiles; i++){
            for(int j=0; j<numberOfTiles; j++){
               if(buttons[i][j]->getNumber()!=buttons[i][j]->getShownNumber())
                   isWin=false;
            }}
        if(isWin){
            std::time_t endOfTimeCalculation = std::time(nullptr);
            double timeInMinutes = (double)(endOfTimeCalculation - beginningOfTimeCalculation)/(double)60;
            std::cout<<"Czas w minutach: "<<timeInMinutes<<std::endl;
            this->timeInMinutes = timeInMinutes;
            winningButton = new QPushButton(this);
            winningButton->setText("End the Game");
            winningButton->move(300, 0);
            winningButton->resize(100, 40);
            winningButton->setFocus();
            winningButton->setVisible(true);
            connect(winningButton, SIGNAL (clicked()),this, SLOT (on_winningButton_clicked()));
        }
    }

}
void PuzzlePanel::switchTiles(int X, int Y){
    buttons[blankCoordinateY][blankCoordinateX]->setNumber(buttons[blankCoordinateY+Y][blankCoordinateX+X]->getNumber());
    buttons[blankCoordinateY+Y][blankCoordinateX+X]->setText("");
    buttons[blankCoordinateY][blankCoordinateX]->changeIsBlank();
    buttons[blankCoordinateY+Y][blankCoordinateX+X]->changeIsBlank();
    blankCoordinateX+=X;
    blankCoordinateY+=Y;
    this->setFocus();
}
void PuzzlePanel::on_winningButton_clicked(){
    ListOfBestPlayers<int>::getInstance("moves.txt");
    ListOfBestPlayers<int>::updateIfBest(numberOfTiles, numberOfMoves, nickname);
    ListOfBestPlayers<int>::saveToFile();
    ListOfBestPlayers<double>::getInstance("time.txt");
    ListOfBestPlayers<double>::updateIfBest(numberOfTiles, timeInMinutes, nickname);
    ListOfBestPlayers<double>::saveToFile();

    Scoreboard *board = new Scoreboard();
    this->hide();
    board->show();
}

void PuzzlePanel::on_newGame_clicked(){
    this->hide();
    MainWindow *w = new MainWindow();
    w->show();
}
