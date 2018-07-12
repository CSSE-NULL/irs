/********************************************************************************
** Form generated from reading UI file 'Tab_Device.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_DEVICE_H
#define UI_TAB_DEVICE_H

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

class Ui_Tab_Device
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *table_device;
    QWidget *widgetButtom;
    QGridLayout *gridLayout;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_change;
    QWidget *widgetFilter;
    QFormLayout *formLayout;
    QLabel *label_device_id;
    QLineEdit *lineEdit_device_id;
    QLabel *label_device_name;
    QLineEdit *lineEdit_device_name;
    QLabel *label_device_authority;
    QComboBox *comboBox_device_authority;
    QLabel *label_position;
    QLineEdit *lineEdit_position;
    QLabel *label;
    QLineEdit *lineEdit_device_register_time;

    void setupUi(QWidget *Tab_Device)
    {
        if (Tab_Device->objectName().isEmpty())
            Tab_Device->setObjectName(QStringLiteral("Tab_Device"));
        Tab_Device->resize(717, 499);
        verticalLayout = new QVBoxLayout(Tab_Device);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        table_device = new QTableView(Tab_Device);
        table_device->setObjectName(QStringLiteral("table_device"));
        table_device->setSelectionMode(QAbstractItemView::SingleSelection);
        table_device->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_device->horizontalHeader()->setVisible(true);
        table_device->horizontalHeader()->setStretchLastSection(true);
        table_device->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(table_device);

        widgetButtom = new QWidget(Tab_Device);
        widgetButtom->setObjectName(QStringLiteral("widgetButtom"));
        gridLayout = new QGridLayout(widgetButtom);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        pushButton_add = new QPushButton(widgetButtom);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setMinimumSize(QSize(0, 0));
        pushButton_add->setIconSize(QSize(50, 20));

        gridLayout->addWidget(pushButton_add, 0, 1, 1, 1);

        pushButton_delete = new QPushButton(widgetButtom);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setMinimumSize(QSize(0, 0));
        pushButton_delete->setIconSize(QSize(50, 20));

        gridLayout->addWidget(pushButton_delete, 1, 1, 1, 1);

        pushButton_change = new QPushButton(widgetButtom);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));
        pushButton_change->setMinimumSize(QSize(0, 0));
        pushButton_change->setIconSize(QSize(50, 20));

        gridLayout->addWidget(pushButton_change, 2, 1, 1, 1);

        widgetFilter = new QWidget(widgetButtom);
        widgetFilter->setObjectName(QStringLiteral("widgetFilter"));
        formLayout = new QFormLayout(widgetFilter);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(1, 1, 1, 1);
        label_device_id = new QLabel(widgetFilter);
        label_device_id->setObjectName(QStringLiteral("label_device_id"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_device_id);

        lineEdit_device_id = new QLineEdit(widgetFilter);
        lineEdit_device_id->setObjectName(QStringLiteral("lineEdit_device_id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_device_id);

        label_device_name = new QLabel(widgetFilter);
        label_device_name->setObjectName(QStringLiteral("label_device_name"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_device_name);

        lineEdit_device_name = new QLineEdit(widgetFilter);
        lineEdit_device_name->setObjectName(QStringLiteral("lineEdit_device_name"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_device_name);

        label_device_authority = new QLabel(widgetFilter);
        label_device_authority->setObjectName(QStringLiteral("label_device_authority"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_device_authority);

        comboBox_device_authority = new QComboBox(widgetFilter);
        comboBox_device_authority->setObjectName(QStringLiteral("comboBox_device_authority"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_device_authority);

        label_position = new QLabel(widgetFilter);
        label_position->setObjectName(QStringLiteral("label_position"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_position);

        lineEdit_position = new QLineEdit(widgetFilter);
        lineEdit_position->setObjectName(QStringLiteral("lineEdit_position"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_position);

        label = new QLabel(widgetFilter);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        lineEdit_device_register_time = new QLineEdit(widgetFilter);
        lineEdit_device_register_time->setObjectName(QStringLiteral("lineEdit_device_register_time"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_device_register_time);


        gridLayout->addWidget(widgetFilter, 0, 0, 3, 1);

        gridLayout->setColumnStretch(0, 15);
        gridLayout->setColumnStretch(1, 2);

        verticalLayout->addWidget(widgetButtom);


        retranslateUi(Tab_Device);

        QMetaObject::connectSlotsByName(Tab_Device);
    } // setupUi

    void retranslateUi(QWidget *Tab_Device)
    {
        Tab_Device->setWindowTitle(QApplication::translate("Tab_Device", "Form", 0));
        pushButton_add->setText(QApplication::translate("Tab_Device", "\345\242\236\345\212\240", 0));
        pushButton_delete->setText(QApplication::translate("Tab_Device", "\345\210\240\351\231\244", 0));
        pushButton_change->setText(QApplication::translate("Tab_Device", "\344\277\256\346\224\271", 0));
        label_device_id->setText(QApplication::translate("Tab_Device", "\350\256\276\345\244\207id\346\237\245\350\257\242\357\274\232", 0));
        label_device_name->setText(QApplication::translate("Tab_Device", "\350\256\276\345\244\207\345\220\215\347\247\260\346\237\245\350\257\242\357\274\232", 0));
        label_device_authority->setText(QApplication::translate("Tab_Device", "\350\256\276\345\244\207\346\235\203\351\231\220\346\237\245\350\257\242\357\274\232", 0));
        comboBox_device_authority->clear();
        comboBox_device_authority->insertItems(0, QStringList()
         << QApplication::translate("Tab_Device", "None", 0)
         << QApplication::translate("Tab_Device", "Level_1", 0)
         << QApplication::translate("Tab_Device", "Level_2", 0)
         << QApplication::translate("Tab_Device", "Level_3", 0)
        );
        label_position->setText(QApplication::translate("Tab_Device", "\350\256\276\345\244\207\344\275\215\347\275\256\346\237\245\350\257\242\357\274\232", 0));
        label->setText(QApplication::translate("Tab_Device", "\350\256\276\345\244\207\346\263\250\345\206\214\346\227\266\351\227\264\346\237\245\350\257\242\357\274\232", 0));
        lineEdit_device_register_time->setPlaceholderText(QApplication::translate("Tab_Device", "yyyy/M/d hh:mm", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab_Device: public Ui_Tab_Device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_DEVICE_H
