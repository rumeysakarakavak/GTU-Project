#include "scoresdialog.h"
#include "ui_scoresdialog.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QTextStream>

ScoresDialog::ScoresDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoresDialog)
{
    ui->setupUi(this);
    readScoresAndPrintTable();

}

ScoresDialog::~ScoresDialog()
{
    delete ui;
}


void ScoresDialog:: readScoresAndPrintTable(){


    //open file for read
    //qDebug() << "App path : " << QDir::current().absolutePath() + "/scores.txt";
    QString path = QDir::current().absolutePath() + "/scores.txt";
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QStringList fields;

    // read file and split
    while(!in.atEnd()) {
        QString line = in.readLine();
        fields = line.split(",");
    }

    // set table background
    QPalette palette = ui->scoreTable->palette();
    QPixmap jpgImage( ":/images/images/background.PNG");
    palette.setBrush(QPalette::Base, QBrush(jpgImage));

    // set table rows and columns
    int rowCount = fields.count() / 2;
    ui->scoreTable->setPalette( palette );
    ui->scoreTable->viewport()->setPalette( palette );
    ui->scoreTable->clear();
    ui->scoreTable->setRowCount(rowCount);
    ui->scoreTable->setColumnCount(ui->scoreTable->columnCount());

    // headers
    QStringList s;
    s << "TEAM 8";
    s << "COMPUTER";
    ui->scoreTable->setHorizontalHeaderLabels(s);

    // reverse scores end to begin
    QStringList result;
    result.reserve( fields.size() ); // reserve is new in Qt 4.7
    std::reverse_copy( fields.begin(), fields.end(), std::back_inserter( result ) );


    // fill table items
    int k = 0;
    for (int i=0; i<rowCount; i++){
         for (int j=0; j<ui->scoreTable->columnCount(); j++){

             QTableWidgetItem *item = ui->scoreTable->item(i, j);
             if(!item)
             {
                item = new QTableWidgetItem();
                ui->scoreTable->setItem(i, j, item);
             }

             // set text properties
             item->setText(result.at(k));
             item->setTextAlignment(Qt::AlignCenter);
             QFont font("Helvetica", 14, QFont::Bold);
             item->setFont(font);
             item->setForeground(QColor::fromRgb(255,255,255));
             ++k;

         }
    }

    //ui->lineEdit->setText(QString::number(fields.count()));

    file.close();
}
