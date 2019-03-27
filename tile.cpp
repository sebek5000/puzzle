#include "tile.h"
#include <iostream>

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
    if(this->getNumber()==this->getShownNumber())
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
int Tile::getShownNumber(){
    return this->shownNumber;
}
void Tile::changeIsBlank(){
    this->isBlank=!isBlank;
    if(this->isBlank){
        this->setFocus();
        this->setNumber(-1);
}
    }

