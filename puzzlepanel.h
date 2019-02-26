#ifndef PUZZLEPANEL_H
#define PUZZLEPANEL_H

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

private:
    Ui::PuzzlePanel *ui;
    int numberOfTiles;
};

#endif // PUZZLEPANEL_H
