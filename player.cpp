#include "player.h"

Player::Player(int number){
   numberOfTiles = number;
}

int Player::getNumberOfTiles(){
    return numberOfTiles;
}
void Player::setNumberOfMoves(const int number){
    this->numberOfMoves =number;
}
