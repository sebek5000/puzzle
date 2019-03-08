#include "tile.h"
#include <iostream>
Tile::Tile(){
    this->setNumber(0);
    this->shownNumber = 0;
}

Tile::Tile(int number, QWidget *parent) : QPushButton(parent){

    if(number >0)
        this->setNumber(number);
    this->shownNumber = 0;
    isBlank = false;

}
Tile::~Tile(){
}
void Tile::setNumber(int number){
    this->number = number;
    this->setText(QString::number(number));
    if(number<0)
         this->setText("");
    if(this->getNumber()==this->shownNumber)
        this->setStyleSheet("background-color: green}");
    else
        this->setStyleSheet("background-color: red}");
}
void Tile::setShownNumber(int number){
    this->shownNumber = number;
}

int Tile::getNumber(){
    return this->number;
}
void Tile::changeIsBlank(){
    this->isBlank=!isBlank;
    if(this->isBlank){
        this->setFocus();
        this->setNumber(-1);
       // std::cout<<"Im blank"<<std::endl;
}
    }

