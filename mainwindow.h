#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "puzzlepanel.h"
namespace Ui {
class MainWindow;
}
/**
 * @brief Klasa odpowiedzialna za okno powitalne programu
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor parametrowy
     * @param parent opcjonalny rodzic
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    PuzzlePanel *puzzle;
};

#endif // MAINWINDOW_H
