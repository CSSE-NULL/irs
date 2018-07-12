/********************************************************************************
** Form generated from reading UI file 'Tab_User.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_USER_H
#define UI_TAB_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab_User
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableView *table_user;
    QWidget *widgetButtom;
    QGridLayout *gridLayout;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_add;
    QPushButton *pushButton_change;
    QWidget *widgetFilter_2;
    QFormLayout *widgetFilter;
    QLineEdit *lineEdit_user_id;
    QLabel *label_user_name;
    QLineEdit *lineEdit_user_name;
    QLabel *label_user_authority;
    QComboBox *comboBox_user_authority;
    QLabel *label_user_register_time;
    QLabel *label_user_id;
    QLineEdit *lineEdit_user_register_time;

    void setupUi(QWidget *Tab_User)
    {
        if (Tab_User->objectName().isEmpty())
            Tab_User->setObjectName(QStringLiteral("Tab_User"));
        Tab_User->resize(648, 489);
        verticalLayout_2 = new QVBoxLayout(Tab_User);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        table_user = new QTableView(Tab_User);
        table_user->setObjectName(QStringLiteral("table_user"));
        table_user->setSelectionMode(QAbstractItemView::SingleSelection);
        table_user->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_user->horizontalHeader()->setStretchLastSection(true);
        table_user->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(table_user);

        widgetButtom = new QWidget(Tab_User);
        widgetButtom->setObjectName(QStringLiteral("widgetButtom"));
        gridLayout = new QGridLayout(widgetButtom);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        pushButton_delete = new QPushButton(widgetButtom);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        gridLayout->addWidget(pushButton_delete, 1, 1, 1, 1);

        pushButton_add = new QPushButton(widgetButtom);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 0, 1, 1, 1);

        pushButton_change = new QPushButton(widgetButtom);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));

        gridLayout->addWidget(pushButton_change, 2, 1, 1, 1);

        widgetFilter_2 = new QWidget(widgetButtom);
        widgetFilter_2->setObjectName(QStringLiteral("widgetFilter_2"));
        widgetFilter = new QFormLayout(widgetFilter_2);
        widgetFilter->setObjectName(QStringLiteral("widgetFilter"));
        widgetFilter->setContentsMargins(1, 1, 1, 1);
        lineEdit_user_id = new QLineEdit(widgetFilter_2);
        lineEdit_user_id->setObjectName(QStringLiteral("lineEdit_user_id"));

        widgetFilter->setWidget(0, QFormLayout::FieldRole, lineEdit_user_id);

        label_user_name = new QLabel(widgetFilter_2);
        label_user_name->setObjectName(QStringLiteral("label_user_name"));

        widgetFilter->setWidget(1, QFormLayout::LabelRole, label_user_name);

        lineEdit_user_name = new QLineEdit(widgetFilter_2);
        lineEdit_user_name->setObjectName(QStringLiteral("lineEdit_user_name"));

        widgetFilter->setWidget(1, QFormLayout::FieldRole, lineEdit_user_name);

        label_user_authority = new QLabel(widgetFilter_2);
        label_user_authority->setObjectName(QStringLiteral("label_user_authority"));

        widgetFilter->setWidget(2, QFormLayout::LabelRole, label_user_authority);

        comboBox_user_authority = new QComboBox(widgetFilter_2);
        comboBox_user_authority->setObjectName(QStringLiteral("comboBox_user_authority"));

        widgetFilter->setWidget(2, QFormLayout::FieldRole, comboBox_user_authority);

        label_user_register_time = new QLabel(widgetFilter_2);
        label_user_register_time->setObjectName(QStringLiteral("label_user_register_time"));

        widgetFilter->setWidget(3, QFormLayout::LabelRole, label_user_register_time);

        label_user_id = new QLabel(widgetFilter_2);
        label_user_id->setObjectName(QStringLiteral("label_user_id"));

        widgetFilter->setWidget(0, QFormLayout::LabelRole, label_user_id);

        lineEdit_user_register_time = new QLineEdit(widgetFilter_2);
        lineEdit_user_register_time->setObjectName(QStringLiteral("lineEdit_user_register_time"));

        widgetFilter->setWidget(3, QFormLayout::FieldRole, lineEdit_user_register_time);


        gridLayout->addWidget(widgetFilter_2, 0, 0, 3, 1);

        gridLayout->setColumnStretch(0, 15);
        gridLayout->setColumnStretch(1, 2);

        verticalLayout_2->addWidget(widgetButtom);


        retranslateUi(Tab_User);

        QMetaObject::connectSlotsByName(Tab_User);
    } // setupUi

    void retranslateUi(QWidget *Tab_User)
    {
        Tab_User->setWindowTitle(QApplication::translate("Tab_User", "Form", 0));
        pushButton_delete->setText(QApplication::translate("Tab_User", "\345\210\240\351\231\244", 0));
        pushButton_add->setText(QApplication::translate("Tab_User", "\345\242\236\345\212\240", 0));
        pushButton_change->setText(QApplication::translate("Tab_User", "\344\277\256\346\224\271", 0));
        label_user_name->setText(QApplication::translate("Tab_User", "\347\224\250\346\210\267\345\247\223\345\220\215\346\237\245\350\257\242\357\274\232", 0));
        label_user_authority->setText(QApplication::translate("Tab_User", "\347\224\250\346\210\267\346\235\203\351\231\220\346\237\245\350\257\242\357\274\232", 0));
        comboBox_user_authority->clear();
        comboBox_user_authority->insertItems(0, QStringList()
         << QApplication::translate("Tab_User", "None", 0)
         << QApplication::translate("Tab_User", "Level_1", 0)
         << QApplication::translate("Tab_User", "Level_2", 0)
         << QApplication::translate("Tab_User", "Level_3", 0)
        );
        label_user_register_time->setText(QApplication::translate("Tab_User", "\347\224\250\346\210\267\346\263\250\345\206\214\346\227\266\351\227\264\346\237\245\350\257\242\357\274\232", 0));
        label_user_id->setText(QApplication::translate("Tab_User", "\347\224\250\346\210\267id\346\237\245\350\257\242\357\274\232", 0));
        lineEdit_user_register_time->setPlaceholderText(QApplication::translate("Tab_User", "yyyy/M/d hh:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab_User: public Ui_Tab_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_USER_H
