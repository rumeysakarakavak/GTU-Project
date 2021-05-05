/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *startButton;
    QCommandLinkButton *stopButton;
    QComboBox *level;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLCDNumber *teamScoreLabel;
    QLCDNumber *computerScoreLabel;
    QLabel *levelimage;
    QCommandLinkButton *scoresButton;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1800, 900);
        MainWindow->setMinimumSize(QSize(1000, 750));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startButton = new QCommandLinkButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(520, 510, 81, 81));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/play-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        startButton->setIcon(icon);
        startButton->setIconSize(QSize(60, 60));
        stopButton = new QCommandLinkButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(620, 510, 81, 81));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/stopp.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(70, 70));
        level = new QComboBox(centralwidget);
        level->setObjectName(QString::fromUtf8("level"));
        level->setGeometry(QRect(410, 590, 69, 21));
        level->setAutoFillBackground(false);
        level->setFrame(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 10, 331, 111));
        label_2->setMaximumSize(QSize(331, 16777215));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 60, 161, 151));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/images/team8.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(870, 60, 141, 131));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/images/computer.png")));
        label_4->setScaledContents(true);
        teamScoreLabel = new QLCDNumber(centralwidget);
        teamScoreLabel->setObjectName(QString::fromUtf8("teamScoreLabel"));
        teamScoreLabel->setGeometry(QRect(270, 270, 81, 121));
        teamScoreLabel->setFrameShape(QFrame::NoFrame);
        teamScoreLabel->setSegmentStyle(QLCDNumber::Flat);
        teamScoreLabel->setProperty("intValue", QVariant(4));
        computerScoreLabel = new QLCDNumber(centralwidget);
        computerScoreLabel->setObjectName(QString::fromUtf8("computerScoreLabel"));
        computerScoreLabel->setEnabled(true);
        computerScoreLabel->setGeometry(QRect(890, 270, 81, 121));
        computerScoreLabel->setLayoutDirection(Qt::RightToLeft);
        computerScoreLabel->setFrameShape(QFrame::NoFrame);
        computerScoreLabel->setSegmentStyle(QLCDNumber::Flat);
        computerScoreLabel->setProperty("intValue", QVariant(3));
        levelimage = new QLabel(centralwidget);
        levelimage->setObjectName(QString::fromUtf8("levelimage"));
        levelimage->setGeometry(QRect(410, 520, 61, 51));
        levelimage->setPixmap(QPixmap(QString::fromUtf8(":/images/images/struggle.png")));
        levelimage->setScaledContents(true);
        scoresButton = new QCommandLinkButton(centralwidget);
        scoresButton->setObjectName(QString::fromUtf8("scoresButton"));
        scoresButton->setGeometry(QRect(740, 510, 81, 81));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/scores.png"), QSize(), QIcon::Normal, QIcon::Off);
        scoresButton->setIcon(icon2);
        scoresButton->setIconSize(QSize(60, 60));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(380, 170, 491, 281));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1800, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QString());
        stopButton->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        levelimage->setText(QString());
        scoresButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
