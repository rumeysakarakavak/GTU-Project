#ifndef SCORESDIALOG_H
#define SCORESDIALOG_H

#include <QDialog>

namespace Ui {
class ScoresDialog;
}

class ScoresDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoresDialog(QWidget *parent = nullptr);
    ~ScoresDialog();
    void readScoresAndPrintTable();
    void on_down_clicked();


private:
    Ui::ScoresDialog *ui;
};

#endif // SCORESDIALOG_H
