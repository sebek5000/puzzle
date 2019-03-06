#include "tile.h"
#include <iostream>
Tile::Tile(){
    this->setNumber(0);
    this->shownNumber = 0;
}

Tile::Tile(int number, PuzzlePanel *parent) : QPushButton(parent){

    if(number >0)
        this->setNumber(number);
    this->shownNumber = 0;
    isBlank = false;
    panel = parent;
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
    if(this->isBlank){
        this->setFocusPolicy(Qt::StrongFocus);
        this->setFocus();
        std::cout<<"Im blank"<<std::endl;
}
    }
void Tile::keyPressEvent(QKeyEvent *event){

    switch(event->key())
        {
        case Qt::Key_Up:
           std::cout<<"Kliknieta strzala  up"<<std::endl;
            break;
        case Qt::Key_Down:
            std::cout<<"Kliknieta strzala down"<<std::endl;
            break;
        case Qt::Key_Left:
            std::cout<<"Kliknieta strzala left"<<std::endl;
            break;
        case Qt::Key_Right:
            std::cout<<"Kliknieta strzala right"<<std::endl;
            break;
        default:
                event->ignore();
                break;

        }

}
