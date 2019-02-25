#ifndef TILE_H
#define TILE_H

class Tile{
private:
    int number;
    int shownNumber;
public:
    Tile();
    Tile(int number);
    ~Tile();
    void setNumber(int number);
    int getNumber();
};
#endif // TILE_H
