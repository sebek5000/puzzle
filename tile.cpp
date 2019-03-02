#include "tile.h"

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
}

int Tile::getNumber(){
    return this->number;
}
void Tile::changeIsBlank(){
    this->isBlank=!isBlank;
}
