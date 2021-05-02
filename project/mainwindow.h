#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void selectLevel(QComboBox *level);
    QString getIPFromHardware();
    void setTeamScore(int score);
    void setComputerScore(int score);
    void setLevel(int level);
    void writeFileScores(int computerScore, int teamScore);
    int getComputerScore();
    int getTeamScore();
    int getLevel();





private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_level_currentIndexChanged(int index);

    void on_scoresButton_clicked();

private:
    Ui::MainWindow *ui;
    int computerScore;
    int teamScore;
    int level;
};
#endif // MAINWINDOW_H
