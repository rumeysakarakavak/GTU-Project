/********************************************************************************
** Form generated from reading UI file 'scoresdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORESDIALOG_H
#define UI_SCORESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoresDialog
{
public:
    QTableWidget *scoreTable;
    QPushButton *down;

    void setupUi(QDialog *ScoresDialog)
    {
        if (ScoresDialog->objectName().isEmpty())
            ScoresDialog->setObjectName(QStringLiteral("ScoresDialog"));
        ScoresDialog->resize(520, 544);
        scoreTable = new QTableWidget(ScoresDialog);
        if (scoreTable->columnCount() < 3)
            scoreTable->setColumnCount(3);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        scoreTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        scoreTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        scoreTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        scoreTable->setObjectName(QStringLiteral("scoreTable"));
        scoreTable->setGeometry(QRect(0, 0, 531, 501));
        scoreTable->setFrameShape(QFrame::HLine);
        scoreTable->setLineWidth(4);
        scoreTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scoreTable->setAutoScrollMargin(16);
        scoreTable->setGridStyle(Qt::DashLine);
        scoreTable->horizontalHeader()->setVisible(true);
        scoreTable->horizontalHeader()->setCascadingSectionResizes(false);
        scoreTable->horizontalHeader()->setDefaultSectionSize(171);
        scoreTable->horizontalHeader()->setHighlightSections(true);
        scoreTable->horizontalHeader()->setMinimumSectionSize(40);
        scoreTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        scoreTable->horizontalHeader()->setStretchLastSection(false);
        scoreTable->verticalHeader()->setVisible(false);
        scoreTable->verticalHeader()->setCascadingSectionResizes(false);
        scoreTable->verticalHeader()->setDefaultSectionSize(50);
        scoreTable->verticalHeader()->setHighlightSections(false);
        scoreTable->verticalHeader()->setMinimumSectionSize(23);
        scoreTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        scoreTable->verticalHeader()->setStretchLastSection(false);
        down = new QPushButton(ScoresDialog);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(370, 500, 112, 32));

        retranslateUi(ScoresDialog);

        QMetaObject::connectSlotsByName(ScoresDialog);
    } // setupUi

    void retranslateUi(QDialog *ScoresDialog)
    {
        ScoresDialog->setWindowTitle(QApplication::translate("ScoresDialog", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = scoreTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ScoresDialog", "TEAM 8", 0));
        QTableWidgetItem *___qtablewidgetitem1 = scoreTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ScoresDialog", "COMPUTER", 0));
        QTableWidgetItem *___qtablewidgetitem2 = scoreTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ScoresDialog", "DATE", 0));
        down->setText(QApplication::translate("ScoresDialog", "Download", 0));
    } // retranslateUi

};

namespace Ui {
    class ScoresDialog: public Ui_ScoresDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORESDIALOG_H
