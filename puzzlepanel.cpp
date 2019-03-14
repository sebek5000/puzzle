#include "puzzlepanel.h"
#include "ui_puzzlepanel.h"
#include <vector>
#include <string>
//#include "qtextedit.h"
#include "qpushbutton.h"
#include "tile.h"
#include "scoreboard.h"
#include <fstream>

#include <iostream>
PuzzlePanel::PuzzlePanel(int number, std::string nickname, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PuzzlePanel)
{
    ui->setupUi(this);
    this->nickname = nickname;
    std::cout<<nickname<<std::endl;
    numberOfTiles = number;
//        QTextEdit **tiles =  new QTextEdit[numberOfTiles][numberOfTiles];
//       // [numberOfTiles][numberOfTiles];// =  new QPushButton[numberOfTiles][numberOfTiles];
//    std::vector< std::vector < QTextEdit> > tiles;// = new std::vector< std::vector < QTextEdit > >();
//    std::vector< std::vector < QPushButton > > buttons;

    for (int i=0; i<numberOfTiles; i++){
        for(int j=0; j<numberOfTiles; j++){
            buttons[i][j] = new Tile(numberOfTiles, this);//QPushButton(this);
            buttons[i][j]->setShownNumber(j+numberOfTiles*i);
            buttons[i][j]->setNumber(j+numberOfTiles*i);
            buttons[i][j]->move(40*j, 40*i);
            buttons[i][j]->resize(40,40);
            if(i==numberOfTiles-1 && j==numberOfTiles-1){
                buttons[i][j]->setShownNumber(-1);
                buttons[i][j]->changeIsBlank();
                blankCoordinateX = j;
                blankCoordinateY = i;
                this->setFocus();//TODO this causes that 1st tile has a frame of being active added
            }
        }}
    for(int i=0; i<100; i++){//random setting of the board
        int arrow = rand() % 4;
        switch(arrow)
            {
            case 0:{
               std::cout<<"Kliknieta strzala  up"<<std::endl;
               if(blankCoordinateY==0)
                   std::cout<<"Poza ekranem!"<<std::endl;
               else{
                switchTiles(0, -1);
               }
        }
                break;
        case 1:{
                std::cout<<"Kliknieta strzala down"<<std::endl;
                if(blankCoordinateY==numberOfTiles-1)
                    std::cout<<"Poza ekranem!"<<std::endl;
                else{
                switchTiles(0, 1);
                }
      }
                break;

        case 2:{
            std::cout<<"Kliknieta strzala left"<<std::endl;
            if(blankCoordinateX==0)
                std::cout<<"Poza ekranem!"<<std::endl;
            else{
             switchTiles(-1, 0);
            }
                }break;
        case 3:{
                std::cout<<"Kliknieta strzala right"<<std::endl;
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

PuzzlePanel::~PuzzlePanel()
{
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
            winningButton = new QPushButton(this);
            winningButton->setText("End the Game");
            winningButton->move(300, 0);
            winningButton->resize(100, 40);
            winningButton->setFocus();
            winningButton->setVisible(true);
            std::cout<<"Wygranko!!!" +  std::to_string(numberOfMoves)<<std::endl;
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

    std::fstream myFile;
    std::string temp = "";
    std::string line;

    myFile.open("score.txt");
    if (myFile.is_open())
      {
        while ( getline (myFile,line) )
        {
          temp+=line + "\n";
          std::cout<<line<<std::endl;
        }
      }
     myFile.close();
      myFile.open("score.txt");
        std::cout<<"Ohayou!"<<temp<<std::endl;
      myFile <<temp << nickname<<" "<<numberOfTiles<<" "<<numberOfMoves<<"\n";
      myFile.close();

      std::cout<<"Klikniety przycisk"<<std::endl;
      Scoreboard *board = new Scoreboard();
      this->hide();
      board->show();
}
