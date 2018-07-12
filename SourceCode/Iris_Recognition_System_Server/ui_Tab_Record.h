/********************************************************************************
** Form generated from reading UI file 'Tab_Record.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_RECORD_H
#define UI_TAB_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab_Record
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *table_record;
    QWidget *widgetFilter;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_user_id;
    QLineEdit *lineEdit_device_id;
    QLabel *label_user_id;
    QLineEdit *lineEdit_record_id;
    QLabel *label_device_id;
    QLabel *label_record_register_time;
    QLabel *label_record_id;
    QComboBox *comboBox_result;
    QLabel *label_result;
    QLineEdit *lineEdit_record_register_time;

    void setupUi(QWidget *Tab_Record)
    {
        if (Tab_Record->objectName().isEmpty())
            Tab_Record->setObjectName(QStringLiteral("Tab_Record"));
        Tab_Record->resize(635, 538);
        verticalLayout = new QVBoxLayout(Tab_Record);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        table_record = new QTableView(Tab_Record);
        table_record->setObjectName(QStringLiteral("table_record"));
        table_record->setSelectionMode(QAbstractItemView::SingleSelection);
        table_record->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_record->horizontalHeader()->setDefaultSectionSize(123);
        table_record->horizontalHeader()->setStretchLastSection(true);
        table_record->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(table_record);

        widgetFilter = new QWidget(Tab_Record);
        widgetFilter->setObjectName(QStringLiteral("widgetFilter"));
        gridLayout = new QGridLayout(widgetFilter);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        lineEdit_user_id = new QLineEdit(widgetFilter);
        lineEdit_user_id->setObjectName(QStringLiteral("lineEdit_user_id"));

        gridLayout->addWidget(lineEdit_user_id, 1, 1, 1, 1);

        lineEdit_device_id = new QLineEdit(widgetFilter);
        lineEdit_device_id->setObjectName(QStringLiteral("lineEdit_device_id"));

        gridLayout->addWidget(lineEdit_device_id, 2, 1, 1, 1);

        label_user_id = new QLabel(widgetFilter);
        label_user_id->setObjectName(QStringLiteral("label_user_id"));

        gridLayout->addWidget(label_user_id, 1, 0, 1, 1);

        lineEdit_record_id = new QLineEdit(widgetFilter);
        lineEdit_record_id->setObjectName(QStringLiteral("lineEdit_record_id"));

        gridLayout->addWidget(lineEdit_record_id, 0, 1, 1, 1);

        label_device_id = new QLabel(widgetFilter);
        label_device_id->setObjectName(QStringLiteral("label_device_id"));

        gridLayout->addWidget(label_device_id, 2, 0, 1, 1);

        label_record_register_time = new QLabel(widgetFilter);
        label_record_register_time->setObjectName(QStringLiteral("label_record_register_time"));

        gridLayout->addWidget(label_record_register_time, 3, 0, 1, 1);

        label_record_id = new QLabel(widgetFilter);
        label_record_id->setObjectName(QStringLiteral("label_record_id"));

        gridLayout->addWidget(label_record_id, 0, 0, 1, 1);

        comboBox_result = new QComboBox(widgetFilter);
        comboBox_result->setObjectName(QStringLiteral("comboBox_result"));

        gridLayout->addWidget(comboBox_result, 4, 1, 1, 1);

        label_result = new QLabel(widgetFilter);
        label_result->setObjectName(QStringLiteral("label_result"));

        gridLayout->addWidget(label_result, 4, 0, 1, 1);

        lineEdit_record_register_time = new QLineEdit(widgetFilter);
        lineEdit_record_register_time->setObjectName(QStringLiteral("lineEdit_record_register_time"));

        gridLayout->addWidget(lineEdit_record_register_time, 3, 1, 1, 1);


        verticalLayout->addWidget(widgetFilter);


        retranslateUi(Tab_Record);

        QMetaObject::connectSlotsByName(Tab_Record);
    } // setupUi

    void retranslateUi(QWidget *Tab_Record)
    {
        Tab_Record->setWindowTitle(QApplication::translate("Tab_Record", "Form", 0));
        label_user_id->setText(QApplication::translate("Tab_Record", "\347\224\250\346\210\267id\346\237\245\350\257\242\357\274\232", 0));
        label_device_id->setText(QApplication::translate("Tab_Record", "\350\256\276\345\244\207id\346\237\245\350\257\242\357\274\232", 0));
        label_record_register_time->setText(QApplication::translate("Tab_Record", "\350\257\206\345\210\253\350\256\260\345\275\225\346\227\266\351\227\264\346\237\245\350\257\242\357\274\232", 0));
        label_record_id->setText(QApplication::translate("Tab_Record", "\350\257\206\345\210\253\350\256\260\345\275\225id\346\237\245\350\257\242\357\274\232", 0));
        comboBox_result->clear();
        comboBox_result->insertItems(0, QStringList()
         << QApplication::translate("Tab_Record", "None", 0)
         << QApplication::translate("Tab_Record", "\346\210\220\345\212\237", 0)
         << QApplication::translate("Tab_Record", "\345\244\261\350\264\245", 0)
        );
        label_result->setText(QApplication::translate("Tab_Record", "\350\257\206\345\210\253\347\273\223\346\236\234\346\237\245\350\257\242\357\274\232", 0));
        lineEdit_record_register_time->setPlaceholderText(QApplication::translate("Tab_Record", "yyyy/M/d hh:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab_Record: public Ui_Tab_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_RECORD_H
