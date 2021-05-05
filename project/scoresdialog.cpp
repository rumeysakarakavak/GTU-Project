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
#include <QJsonDocument>
#include <QJsonParseError>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTableFormat>
#include <QTextTableCell>
#include <QFont>
#include <QPrinter>
#include <QDebug>

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
    QString path = QDir::current().absolutePath() + "/scores.json";
    //QString path = "/Users/mustafatokgoz/Desktop/proje/scores.json";

    QFile file(path);
    if (!file.exists()) {       // Check to see if QFile found the file at given file_path
        qDebug() << "NO FILE HERE";
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
       qDebug() << jsonError.errorString();
     }
     QList<QVariant> list = flowerJson.toVariant().toList();


    // set table background
    QPalette palette = ui->scoreTable->palette();
    QPixmap jpgImage( ":/images/images/background.PNG");
    palette.setBrush(QPalette::Base, QBrush(jpgImage));

    // set table rows and columns
    int rowCount = list.count();
    ui->scoreTable->setPalette( palette );
    ui->scoreTable->viewport()->setPalette( palette );
    ui->scoreTable->clear();
    ui->scoreTable->setRowCount(rowCount);
    ui->scoreTable->setColumnCount(ui->scoreTable->columnCount());

    // headers
    QStringList s;
    s << "TEAM 8";
    s << "COMPUTER";
    s << "DATE";
    ui->scoreTable->setHorizontalHeaderLabels(s);



    // fill table items
    for (int i=0; i<rowCount; i++){
             QMap<QString, QVariant> map = list[i].toMap();
             QTableWidgetItem *item = ui->scoreTable->item(i, 0);
             if(!item)
             {
                item = new QTableWidgetItem();
                ui->scoreTable->setItem(i, 0, item);
             }
             // set text properties
             item->setText(map["human_score"].toString());
             item->setTextAlignment(Qt::AlignCenter);
             QFont font("Helvetica", 13, QFont::Bold);
             item->setFont(font);
             item->setForeground(QColor::fromRgb(255,255,0));

             QTableWidgetItem *item2 = ui->scoreTable->item(i, 1);
             if(!item2)
             {
                item2 = new QTableWidgetItem();
                ui->scoreTable->setItem(i, 1, item2);
             }
             // set text properties
             item2->setText(map["robot_score"].toString());
             item2->setTextAlignment(Qt::AlignCenter);
             QFont font2("Helvetica", 13, QFont::Bold);
             item2->setFont(font2);
             item2->setForeground(QColor::fromRgb(255,255,0));

             QTableWidgetItem *item3 = ui->scoreTable->item(i, 2);
             if(!item3)
             {
                item3 = new QTableWidgetItem();
                ui->scoreTable->setItem(i, 2, item3);
             }
             // set text properties
             item3->setText(map["date"].toString());
             item3->setTextAlignment(Qt::AlignCenter);
             QFont font3("Helvetica", 13, QFont::Bold);
             item3->setFont(font3);
             item3->setForeground(QColor::fromRgb(255,255,0));

    }
    file.close();

}


void ScoresDialog::on_down_clicked(bool checked)
{
    if(checked==true)
        qDebug() << "cliked download";
    QString path = QDir::current().absolutePath() + "/scores.json";
    QFile file(path);
    if (!file.exists()) {       // Check to see if QFile found the file at given file_path
        qDebug() << "NO FILE HERE";
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);


    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
       qDebug() << jsonError.errorString();
     }
     QList<QVariant> list = flowerJson.toVariant().toList();

     QTextDocument *doc = new QTextDocument;
     doc->setDocumentMargin(10);
     QTextCursor cursor(doc);

     cursor.movePosition(QTextCursor::Start);

     QTextTable *table = cursor.insertTable(list.count() + 1, 3);
     QTextTableCell headerCell = table->cellAt(0, 0);
     QTextCursor headerCellCursor = headerCell.firstCursorPosition();
     QTextCharFormat format;
      format.setFontWeight(QFont::Bold);
     headerCellCursor.insertText(QObject::tr("Team 8"),format);

     headerCell = table->cellAt(0, 1);
     headerCellCursor = headerCell.firstCursorPosition();
     headerCellCursor.insertText(QObject::tr("Computer"), format);
     headerCell = table->cellAt(0, 2);
     headerCellCursor = headerCell.firstCursorPosition();
     headerCellCursor.insertText(QObject::tr("Date"), format);


     for(int i = 0; i < list.count(); i++){
         QMap<QString, QVariant> map = list[i].toMap();
         QTextTableCell cell = table->cellAt(i + 1, 0);
         QTextCursor cellCursor = cell.firstCursorPosition();
         cellCursor.insertText(map["human_score"].toString());

         cell = table->cellAt(i + 1, 1);
         cellCursor = cell.firstCursorPosition();
         cellCursor.insertText(map["robot_score"].toString());
         cell = table->cellAt(i + 1, 2);
         cellCursor = cell.firstCursorPosition();
         cellCursor.insertText(map["date"].toString());
     }
     QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
     QPrinter printer(QPrinter::ScreenResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOutputFileName(fileName);
     doc->print(&printer);
     file.close();

}
