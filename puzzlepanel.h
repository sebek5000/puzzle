#ifndef PUZZLEPANEL_H
#define PUZZLEPANEL_H
#include "tile.h"
#include <QKeyEvent>
#include <QDialog>


namespace Ui {
class PuzzlePanel;
}

class PuzzlePanel : public QDialog
{
    Q_OBJECT

public:
    explicit PuzzlePanel(int number, QWidget *parent = nullptr);
    ~PuzzlePanel();
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::PuzzlePanel *ui;
    int numberOfTiles;
    void switchTiles(int X, int Y);
    int blankCoordinateX;
    int blankCoordinateY;
    Tile *buttons[10][10];
    int numberOfMoves = 0;
};

#endif // PUZZLEPANEL_H
