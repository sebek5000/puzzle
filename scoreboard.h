#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QTextBrowser>
namespace Ui {
class Scoreboard;
}

class Scoreboard : public QWidget
{
    Q_OBJECT

public:
    explicit Scoreboard(QWidget *parent = nullptr);
    ~Scoreboard();

private slots:
    void on_newGameButton_clicked();

private:
    Ui::Scoreboard *ui;
    QTextBrowser *scoreTextBrowser;
};

#endif // SCOREBOARD_H
