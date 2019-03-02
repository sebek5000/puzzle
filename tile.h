#ifndef TILE_H
#define TILE_H
#include "qpushbutton.h"

class Tile : public QPushButton{
private:
    int number;
    int shownNumber;
    bool isBlank;
public:
    Tile();
    Tile(int number, QWidget *parent = nullptr);
    ~Tile();
    void setNumber(int number);
    int getNumber();
    void changeIsBlank();
};
#endif // TILE_H
