#ifndef TILE_H
#define TILE_H
#include "qpushbutton.h"
#include <QKeyEvent>
#include "puzzlepanel.h"
class Tile : public QPushButton{
private:
    int number;
    int shownNumber;
    bool isBlank;
    PuzzlePanel *panel;
public:
    Tile();
    Tile(int number, PuzzlePanel *parent = nullptr);
    ~Tile();
    void setNumber(int number);
    int getNumber();
    void changeIsBlank();
    void keyPressEvent(QKeyEvent *event);
};
#endif // TILE_H
