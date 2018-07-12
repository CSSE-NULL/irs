/********************************************************************************
** Form generated from reading UI file 'Dialog_Device_Add.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_DEVICE_ADD_H
#define UI_DIALOG_DEVICE_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Device_Add
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QSpacerItem *horizontalSpacer;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Close;
    QWidget *widgetMain;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label__device_name;
    QLabel *label_device_authority;
    QComboBox *comboBox_device_authority;
    QLabel *label_position;
    QLineEdit *lineEdit_position;
    QLineEdit *lineEdit_device_name;
    QWidget *widgetButton;
    QHBoxLayout *button_box;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Dialog_Device_Add)
    {
        if (Dialog_Device_Add->objectName().isEmpty())
            Dialog_Device_Add->setObjectName(QStringLiteral("Dialog_Device_Add"));
        Dialog_Device_Add->resize(500, 300);
        Dialog_Device_Add->setStyleSheet(QStringLiteral(""));
        Dialog_Device_Add->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(Dialog_Device_Add);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(Dialog_Device_Add);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setMinimumSize(QSize(0, 40));
        widgetTitle->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(15, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labIco->sizePolicy().hasHeightForWidth());
        labIco->setSizePolicy(sizePolicy1);
        labIco->setMinimumSize(QSize(100, 0));
        labIco->setStyleSheet(QStringLiteral(""));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        horizontalSpacer = new QSpacerItem(24, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy2);
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        sizePolicy1.setHeightForWidth(widgetMenu->sizePolicy().hasHeightForWidth());
        widgetMenu->setSizePolicy(sizePolicy1);
        widgetMenu->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widgetMenu);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy3);
        btnMenu_Min->setMinimumSize(QSize(35, 0));
        btnMenu_Min->setMaximumSize(QSize(35, 16777215));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);
        btnMenu_Min->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Min);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy4);
        btnMenu_Max->setMinimumSize(QSize(35, 0));
        btnMenu_Max->setMaximumSize(QSize(35, 16777215));
        btnMenu_Max->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);
        btnMenu_Max->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Max);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        sizePolicy4.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy4);
        btnMenu_Close->setMinimumSize(QSize(35, 0));
        btnMenu_Close->setMaximumSize(QSize(35, 16777215));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        btnMenu_Close->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Close);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        widgetMain = new QWidget(Dialog_Device_Add);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        widgetMain->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(widgetMain);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 2);

        label__device_name = new QLabel(widgetMain);
        label__device_name->setObjectName(QStringLiteral("label__device_name"));

        gridLayout->addWidget(label__device_name, 0, 0, 1, 1);

        label_device_authority = new QLabel(widgetMain);
        label_device_authority->setObjectName(QStringLiteral("label_device_authority"));

        gridLayout->addWidget(label_device_authority, 1, 0, 1, 1);

        comboBox_device_authority = new QComboBox(widgetMain);
        comboBox_device_authority->setObjectName(QStringLiteral("comboBox_device_authority"));

        gridLayout->addWidget(comboBox_device_authority, 1, 1, 1, 1);

        label_position = new QLabel(widgetMain);
        label_position->setObjectName(QStringLiteral("label_position"));

        gridLayout->addWidget(label_position, 2, 0, 1, 1);

        lineEdit_position = new QLineEdit(widgetMain);
        lineEdit_position->setObjectName(QStringLiteral("lineEdit_position"));

        gridLayout->addWidget(lineEdit_position, 2, 1, 1, 1);

        lineEdit_device_name = new QLineEdit(widgetMain);
        lineEdit_device_name->setObjectName(QStringLiteral("lineEdit_device_name"));

        gridLayout->addWidget(lineEdit_device_name, 0, 1, 1, 1);

        widgetButton = new QWidget(widgetMain);
        widgetButton->setObjectName(QStringLiteral("widgetButton"));
        button_box = new QHBoxLayout(widgetButton);
        button_box->setSpacing(20);
        button_box->setObjectName(QStringLiteral("button_box"));
        button_box->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        button_box->addItem(horizontalSpacer_2);

        pushButton_confirm = new QPushButton(widgetButton);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        button_box->addWidget(pushButton_confirm);

        pushButton_cancel = new QPushButton(widgetButton);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        button_box->addWidget(pushButton_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        button_box->addItem(horizontalSpacer_3);

        button_box->setStretch(0, 15);
        button_box->setStretch(1, 5);
        button_box->setStretch(2, 5);
        button_box->setStretch(3, 1);

        gridLayout->addWidget(widgetButton, 4, 0, 1, 2);


        verticalLayout->addWidget(widgetMain);


        retranslateUi(Dialog_Device_Add);

        QMetaObject::connectSlotsByName(Dialog_Device_Add);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Device_Add)
    {
        Dialog_Device_Add->setWindowTitle(QApplication::translate("Dialog_Device_Add", "Dialog", 0));
        labIco->setText(QString());
        labTitle->setText(QApplication::translate("Dialog_Device_Add", "\346\267\273\345\212\240\350\256\276\345\244\207\344\277\241\346\201\257", 0));
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("Dialog_Device_Add", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Max->setToolTip(QApplication::translate("Dialog_Device_Add", "\346\234\200\345\244\247\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Max->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("Dialog_Device_Add", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        label__device_name->setText(QApplication::translate("Dialog_Device_Add", "\350\257\267\350\276\223\345\205\245\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", 0));
        label_device_authority->setText(QApplication::translate("Dialog_Device_Add", "\350\257\267\350\276\223\345\205\245\350\256\276\345\244\207\346\235\203\351\231\220\357\274\232", 0));
        comboBox_device_authority->clear();
        comboBox_device_authority->insertItems(0, QStringList()
         << QApplication::translate("Dialog_Device_Add", "Level_1", 0)
         << QApplication::translate("Dialog_Device_Add", "Level_2", 0)
         << QApplication::translate("Dialog_Device_Add", "Level_3", 0)
        );
        label_position->setText(QApplication::translate("Dialog_Device_Add", "\350\257\267\350\276\223\345\205\245\350\256\276\345\244\207\344\275\215\347\275\256\344\277\241\346\201\257\357\274\232", 0));
        lineEdit_position->setPlaceholderText(QApplication::translate("Dialog_Device_Add", "\344\270\215\345\244\232\344\272\21620\344\270\252\345\255\227\347\254\246 | \344\270\215\344\270\272\347\251\272", 0));
        lineEdit_device_name->setPlaceholderText(QApplication::translate("Dialog_Device_Add", "\344\270\215\345\244\232\344\272\21610\344\270\252\345\255\227\347\254\246 | \344\270\215\344\270\272\347\251\272", 0));
        pushButton_confirm->setText(QApplication::translate("Dialog_Device_Add", "\347\241\256\350\256\244", 0));
        pushButton_cancel->setText(QApplication::translate("Dialog_Device_Add", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Device_Add: public Ui_Dialog_Device_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_DEVICE_ADD_H
