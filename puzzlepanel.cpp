#include "puzzlepanel.h"
#include "ui_puzzlepanel.h"

PuzzlePanel::PuzzlePanel(int number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PuzzlePanel)
{
    ui->setupUi(this);
    numberOfTiles = number;
}

PuzzlePanel::~PuzzlePanel()
{
    delete ui;
}
