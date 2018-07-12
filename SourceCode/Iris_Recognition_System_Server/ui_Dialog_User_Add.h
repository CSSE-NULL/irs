/********************************************************************************
** Form generated from reading UI file 'Dialog_User_Add.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_USER_ADD_H
#define UI_DIALOG_USER_ADD_H

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

class Ui_Dialog_User_Add
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
    QLabel *label_user_authority;
    QComboBox *comboBox_user_authority;
    QPushButton *pushButton_choose;
    QLabel *label_user_name;
    QLineEdit *lineEdit_user_name;
    QLabel *label_iris;
    QLineEdit *lineEdit_iris;
    QWidget *widgetButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Dialog_User_Add)
    {
        if (Dialog_User_Add->objectName().isEmpty())
            Dialog_User_Add->setObjectName(QStringLiteral("Dialog_User_Add"));
        Dialog_User_Add->resize(500, 300);
        Dialog_User_Add->setStyleSheet(QStringLiteral(""));
        Dialog_User_Add->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(Dialog_User_Add);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(Dialog_User_Add);
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

        widgetMain = new QWidget(Dialog_User_Add);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        widgetMain->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(widgetMain);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 3);

        label_user_authority = new QLabel(widgetMain);
        label_user_authority->setObjectName(QStringLiteral("label_user_authority"));

        gridLayout->addWidget(label_user_authority, 1, 0, 1, 1);

        comboBox_user_authority = new QComboBox(widgetMain);
        comboBox_user_authority->setObjectName(QStringLiteral("comboBox_user_authority"));

        gridLayout->addWidget(comboBox_user_authority, 1, 1, 1, 2);

        pushButton_choose = new QPushButton(widgetMain);
        pushButton_choose->setObjectName(QStringLiteral("pushButton_choose"));

        gridLayout->addWidget(pushButton_choose, 2, 2, 1, 1);

        label_user_name = new QLabel(widgetMain);
        label_user_name->setObjectName(QStringLiteral("label_user_name"));

        gridLayout->addWidget(label_user_name, 0, 0, 1, 1);

        lineEdit_user_name = new QLineEdit(widgetMain);
        lineEdit_user_name->setObjectName(QStringLiteral("lineEdit_user_name"));

        gridLayout->addWidget(lineEdit_user_name, 0, 1, 1, 2);

        label_iris = new QLabel(widgetMain);
        label_iris->setObjectName(QStringLiteral("label_iris"));

        gridLayout->addWidget(label_iris, 2, 0, 1, 1);

        lineEdit_iris = new QLineEdit(widgetMain);
        lineEdit_iris->setObjectName(QStringLiteral("lineEdit_iris"));

        gridLayout->addWidget(lineEdit_iris, 2, 1, 1, 1);

        widgetButton = new QWidget(widgetMain);
        widgetButton->setObjectName(QStringLiteral("widgetButton"));
        horizontalLayout_3 = new QHBoxLayout(widgetButton);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_confirm = new QPushButton(widgetButton);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout_3->addWidget(pushButton_confirm);

        pushButton_cancel = new QPushButton(widgetButton);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 15);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 5);
        horizontalLayout_3->setStretch(3, 1);

        gridLayout->addWidget(widgetButton, 4, 0, 1, 3);


        verticalLayout->addWidget(widgetMain);


        retranslateUi(Dialog_User_Add);

        QMetaObject::connectSlotsByName(Dialog_User_Add);
    } // setupUi

    void retranslateUi(QDialog *Dialog_User_Add)
    {
        Dialog_User_Add->setWindowTitle(QApplication::translate("Dialog_User_Add", "Dialog", 0));
        labIco->setText(QString());
        labTitle->setText(QApplication::translate("Dialog_User_Add", "\345\242\236\345\212\240\347\224\250\346\210\267\344\277\241\346\201\257", 0));
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("Dialog_User_Add", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Max->setToolTip(QApplication::translate("Dialog_User_Add", "\346\234\200\345\244\247\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Max->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("Dialog_User_Add", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        label_user_authority->setText(QApplication::translate("Dialog_User_Add", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\346\235\203\351\231\220\357\274\232", 0));
        comboBox_user_authority->clear();
        comboBox_user_authority->insertItems(0, QStringList()
         << QApplication::translate("Dialog_User_Add", "Level_1", 0)
         << QApplication::translate("Dialog_User_Add", "Level_2", 0)
         << QApplication::translate("Dialog_User_Add", "Level_3", 0)
        );
        pushButton_choose->setText(QApplication::translate("Dialog_User_Add", "...", 0));
        label_user_name->setText(QApplication::translate("Dialog_User_Add", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\247\223\345\220\215\357\274\232", 0));
        lineEdit_user_name->setPlaceholderText(QApplication::translate("Dialog_User_Add", "\344\270\215\345\244\232\344\272\21610\344\270\252\345\255\227\347\254\246 | \344\270\215\344\270\272\347\251\272", 0));
        label_iris->setText(QApplication::translate("Dialog_User_Add", "\350\257\267\345\257\271\347\224\250\346\210\267\350\231\271\350\206\234\350\277\233\350\241\214\346\211\253\346\217\217\357\274\232", 0));
        lineEdit_iris->setPlaceholderText(QApplication::translate("Dialog_User_Add", "\350\257\267\351\200\211\346\213\251\350\231\271\350\206\234\345\233\276\347\211\207 | \344\270\215\344\270\272\347\251\272", 0));
        pushButton_confirm->setText(QApplication::translate("Dialog_User_Add", "\347\241\256\350\256\244", 0));
        pushButton_cancel->setText(QApplication::translate("Dialog_User_Add", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_User_Add: public Ui_Dialog_User_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_USER_ADD_H
