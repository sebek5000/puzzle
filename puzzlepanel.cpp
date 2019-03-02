#include "puzzlepanel.h"
#include "ui_puzzlepanel.h"
#include <vector>
//#include "qtextedit.h"
//#include "qpushbutton.h"
#include "tile.h"

#include <iostream>
PuzzlePanel::PuzzlePanel(int number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PuzzlePanel)
{
    ui->setupUi(this);
    numberOfTiles = number;
//        QTextEdit **tiles =  new QTextEdit[numberOfTiles][numberOfTiles];
//       // [numberOfTiles][numberOfTiles];// =  new QPushButton[numberOfTiles][numberOfTiles];
//    std::vector< std::vector < QTextEdit> > tiles;// = new std::vector< std::vector < QTextEdit > >();
//    std::vector< std::vector < QPushButton > > buttons;
  Tile *buttons[10][10];
    for (int i=0; i<numberOfTiles; i++){
        for(int j=0; j<numberOfTiles; j++){
            buttons[i][j] = new Tile(numberOfTiles, this);//QPushButton(this);
            buttons[i][j]->setText((QString::number(i) + " " + QString::number(j)));
            buttons[i][j]->move(40*j, 40*i);
            buttons[i][j]->resize(40,40);
            if(i==numberOfTiles-1 && j==numberOfTiles-1){
                buttons[i][j]->setText("");
                buttons[i][j]->changeIsBlank();
            }
            // buttons[i].push_back(* (new QPushButton(this)));
            //tiles[i].push_back( *(new QTextEdit(this)));
            // tiles[i][j].setText(QString::number(i) + " " + QString::number(j));
             std::cout<<std::to_string(i) + " " + std::to_string(j)<<std::endl;
        }}
}

PuzzlePanel::~PuzzlePanel()
{
    delete ui;
}
