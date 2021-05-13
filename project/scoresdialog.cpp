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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct __json_data{
    char date[128];
    char human_score[10];
    char robot_score[10];

}json_data_t;

void get_json_file_content(char* json_content)
{
    // buraya json dosyasının adı yazılacak
    QString path = QDir::current().absolutePath() + "/scores.json";
    std::string p=path.toStdString();
    char *cstr = &p[0];

    int json_file_fd = open(cstr, O_RDONLY);
    size_t file_size = lseek(json_file_fd,0,SEEK_END);
    lseek(json_file_fd, 0, SEEK_SET);

    read(json_file_fd, json_content, file_size);
    json_content[file_size] = '\0';
    close(json_file_fd);
}

void parse_json_data(const char* json_data, json_data_t* parsed_json_data, int* entry_size)
{
    // Format --> {date, human_score, robot_score}; {date, human_score, robot_score}
    char copy_str[1024];
    int total_entry_size  = 0;

    // eliminate whitespace / tab
    int str_len = strlen(json_data);
    int new_str_size = 0;
    for (int i = 0; i < str_len; ++i)
        if(json_data[i] != ' ' && json_data[i] != '\t')
            copy_str[new_str_size++] = json_data[i];
    copy_str[new_str_size] = '\0';

    char* entry_token = strtok(copy_str, ";");
    while(entry_token != NULL)
    {
        entry_token[strlen(entry_token) - 1] = '\0';
        entry_token = &entry_token[1];
        // get json entry & values
        char* date = strtok_r(entry_token, ",", &entry_token);
        char* human_score = strtok_r(entry_token, ",", &entry_token);
        char* robot_score = strtok_r(entry_token, ",", &entry_token);

        // store parsed values into struct
        strcpy(parsed_json_data[total_entry_size].date, date);
        strcpy(parsed_json_data[total_entry_size].human_score, human_score);
        strcpy(parsed_json_data[total_entry_size].robot_score, robot_score);
        entry_token = strtok(NULL, ";");
        if(strcmp(entry_token," ")==-1){
            total_entry_size=total_entry_size+1;
            break;
        }

        total_entry_size=total_entry_size+1;
        if(total_entry_size==5000)
            break;
    }
    // store total entry size
    *entry_size = total_entry_size;
}



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

    //QFile file(path);
    //if (!file.exists()) {       // Check to see if QFile found the file at given file_path
    //    qDebug() << "NO FILE HERE";
    //}
    //file.open(QIODevice::ReadOnly | QIODevice::Text);


    /*
    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
       qDebug() << jsonError.errorString();
     }
     QList<QVariant> list = flowerJson.toVariant().toList();

    */
    // set table background
    QPalette palette = ui->scoreTable->palette();
    QPixmap jpgImage( ":/images/images/background.PNG");
    palette.setBrush(QPalette::Base, QBrush(jpgImage));

    char content[1024];
    int entry_size = 0;
    get_json_file_content(content);
    json_data_t jsonData[5000];
    parse_json_data(content, jsonData, &entry_size);


    // set table rows and columns
    //int rowCount = list.count();
    int rowCount = entry_size;
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
    QFont fon("Helvetica", 15, QFont::Bold);
    ui->scoreTable->setFont(fon);



    // fill table items
    for (int i=0; i<rowCount; i++){
             //QMap<QString, QVariant> map = list[i].toMap();
             QTableWidgetItem *item = ui->scoreTable->item(i, 0);
             if(!item)
             {
                item = new QTableWidgetItem();
                ui->scoreTable->setItem(i, 0, item);
             }
             // set text properties
             //item->setText(map["human_score"].toString());
             QString temp1= QString::fromStdString(jsonData[i].human_score);
             item->setText(temp1);
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
             QString temp2= QString::fromStdString(jsonData[i].robot_score);
             item2->setText(temp2);
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
             QString temp3= QString::fromStdString(jsonData[i].date);
             item3->setText(temp3);
             item3->setTextAlignment(Qt::AlignCenter);
             QFont font3("Helvetica", 13, QFont::Bold);
             item3->setFont(font3);
             item3->setForeground(QColor::fromRgb(255,255,0));

    }

}

void ScoresDialog::on_down_clicked(bool  checked)
{

    if(checked==true)
        qDebug() << "cliked download";
    QString path = QDir::current().absolutePath() + "/scores.json";
    //QFile file(path);
    //if (!file.exists()) {       // Check to see if QFile found the file at given file_path
    //    qDebug() << "NO FILE HERE";
    //}
    //file.open(QIODevice::ReadOnly | QIODevice::Text);

    char content[1024];
    int entry_size = 0;
    get_json_file_content(content);
    json_data_t jsonData[5000];
    parse_json_data(content, jsonData, &entry_size);

    /*
    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
       qDebug() << jsonError.errorString();
     }
     QList<QVariant> list = flowerJson.toVariant().toList();
    */

     QTextDocument *doc = new QTextDocument;
     doc->setDocumentMargin(10);
     QTextCursor cursor(doc);

     cursor.movePosition(QTextCursor::Start);

     QTextTable *table = cursor.insertTable(entry_size + 1, 3);
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


     for(int i = 0; i < entry_size; i++){
         //QMap<QString, QVariant> map = list[i].toMap();
         QTextTableCell cell = table->cellAt(i + 1, 0);
         QTextCursor cellCursor = cell.firstCursorPosition();
         QString temp1= QString::fromStdString(jsonData[i].human_score);
         cellCursor.insertText(temp1);

         cell = table->cellAt(i + 1, 1);
         cellCursor = cell.firstCursorPosition();
         QString temp2= QString::fromStdString(jsonData[i].robot_score);
         cellCursor.insertText(temp2);
         cell = table->cellAt(i + 1, 2);
         cellCursor = cell.firstCursorPosition();
         QString temp3= QString::fromStdString(jsonData[i].date);
         cellCursor.insertText(temp3);
     }
     QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
     QPrinter printer(QPrinter::ScreenResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOutputFileName(fileName);
     doc->print(&printer);
       //qDebug() << "buraya geliyor";
     //file.close();
}
