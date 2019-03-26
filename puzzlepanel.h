#ifndef PUZZLEPANEL_H
#define PUZZLEPANEL_H
#include "tile.h"
#include <QKeyEvent>
#include <QDialog>
#include <string>
#include <ctime>

namespace Ui {
class PuzzlePanel;
}
/**
 * @brief Klasa odpowiedzialna za panel z układanką
 */
class PuzzlePanel : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor parametrowy
     * @param number liczba płytek w układance (rozmiar kwadratu)
     * @param nickname nazwa użytkownika
     * @param parent opcjonalny rodzic
     */
    explicit PuzzlePanel(int number, std::string nickname, QWidget *parent = nullptr);
    ~PuzzlePanel();


private slots:
    void on_winningButton_clicked();
    void keyPressEvent(QKeyEvent *event);
    void on_newGame_clicked();

private:
    Ui::PuzzlePanel *ui;
    int numberOfTiles;
    void switchTiles(int X, int Y);
    int blankCoordinateX;
    int blankCoordinateY;
    Tile *buttons[10][10];
    int numberOfMoves = 0;
    QPushButton *winningButton;
    std::string nickname;
    std::time_t beginningOfTimeCalculation;
    double timeInMinutes;
};

#endif // PUZZLEPANEL_H
