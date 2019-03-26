#ifndef TILE_H
#define TILE_H
#include "qpushbutton.h"
/**
 * @brief Klasa odpowiedzialna za pojedynczą płytkę w układance
 */
class Tile : public QPushButton{

public:
    /**
     * @brief Konstruktor parametrowy
     * @param numer płytki
     * @param parent opcjonalny rodzic
     */
    Tile(int number, QWidget *parent = nullptr);
    ~Tile();
    /**
     * @brief Funckja ustawiająca numer płytki
     * @param number numer płytki
     */
    void setNumber(int number);
    /**
     * @brief Funkcja ustawiająca wyświetlany na ekranie numer płytki
     * @param number wyświetlany numer płytki
     */
    void setShownNumber (int number);
    /**
     * @brief Funkcja zwracająca numer płytki
     * @return numer płytki
     */
    int getNumber();
    /**
     * @brief Funkcja zwracająca wyświetlany numer płytki
     * @return wyświetlany numer płytki
     */
    int getShownNumber();
    /**
     * @brief Funkcja zmieniająca wartośc czy płytka jest pusta
     */
    void changeIsBlank();

private:
    int number;
    int shownNumber;
    bool isBlank;
};
#endif // TILE_H
