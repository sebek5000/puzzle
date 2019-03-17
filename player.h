#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player(const int number);
    Player(const Player&);
    int getNumberOfTiles();
    void setNumberOfMoves(int number);
private:
    int numberOfTiles;
    int numberOfMoves;
};

#endif // PLAYER_H
