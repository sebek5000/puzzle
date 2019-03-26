#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QTextBrowser>
namespace Ui {
class Scoreboard;
}
/**
 * @brief Klasa odpowiedzialna za wyświetlanie najlepszych wyników
 */
class Scoreboard : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor parametrowy
     * @param parent opcjonalny rodzic do tablicy
     */
    explicit Scoreboard(QWidget *parent = nullptr);
    ~Scoreboard();

private slots:
    void on_newGameButton_clicked();

private:
    Ui::Scoreboard *ui;
    QTextBrowser *scoreTextBrowser;
};

#endif // SCOREBOARD_H
