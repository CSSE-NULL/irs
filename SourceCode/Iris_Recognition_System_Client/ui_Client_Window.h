/********************************************************************************
** Form generated from reading UI file 'Client_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_WINDOW_H
#define UI_CLIENT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client_Window
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QSpacerItem *horizontalSpacer;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QWidget *widget;
    QLineEdit *lineEdit_device_id;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_scanner;
    QLabel *label_device_id;
    QLineEdit *lineEdit_scanner;
    QPushButton *pushButton_exit;
    QLabel *label_scanner;

    void setupUi(QDialog *Client_Window)
    {
        if (Client_Window->objectName().isEmpty())
            Client_Window->setObjectName(QStringLiteral("Client_Window"));
        Client_Window->resize(480, 313);
        Client_Window->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(Client_Window);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(Client_Window);
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
        labIco->setMargin(0);
        labIco->setIndent(-1);

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
        QPalette palette;
        labTitle->setPalette(palette);
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        sizePolicy1.setHeightForWidth(widgetMenu->sizePolicy().hasHeightForWidth());
        widgetMenu->setSizePolicy(sizePolicy1);
        widgetMenu->setStyleSheet(QLatin1String("QToolButton,QPushButton{\n"
"border:0px solid #FF0000;\n"
"}\n"
"QToolButton:hover,QPushButton:hover,QToolButton:pressed,QPushButton:pressed{\n"
"background:#067DB8;\n"
"}"));
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

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy4);
        btnMenu_Close->setMinimumSize(QSize(35, 0));
        btnMenu_Close->setMaximumSize(QSize(35, 16777215));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        btnMenu_Close->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Close);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout_2->addWidget(widgetTitle);

        widget = new QWidget(Client_Window);
        widget->setObjectName(QStringLiteral("widget"));
        lineEdit_device_id = new QLineEdit(widget);
        lineEdit_device_id->setObjectName(QStringLiteral("lineEdit_device_id"));
        lineEdit_device_id->setGeometry(QRect(180, 130, 221, 21));
        pushButton_submit = new QPushButton(widget);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));
        pushButton_submit->setGeometry(QRect(100, 190, 101, 31));
        pushButton_scanner = new QPushButton(widget);
        pushButton_scanner->setObjectName(QStringLiteral("pushButton_scanner"));
        pushButton_scanner->setGeometry(QRect(310, 70, 89, 24));
        label_device_id = new QLabel(widget);
        label_device_id->setObjectName(QStringLiteral("label_device_id"));
        label_device_id->setGeometry(QRect(70, 130, 111, 16));
        lineEdit_scanner = new QLineEdit(widget);
        lineEdit_scanner->setObjectName(QStringLiteral("lineEdit_scanner"));
        lineEdit_scanner->setGeometry(QRect(70, 70, 221, 23));
        pushButton_exit = new QPushButton(widget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(270, 190, 101, 31));
        label_scanner = new QLabel(widget);
        label_scanner->setObjectName(QStringLiteral("label_scanner"));
        label_scanner->setGeometry(QRect(70, 40, 341, 20));

        verticalLayout_2->addWidget(widget);


        retranslateUi(Client_Window);

        QMetaObject::connectSlotsByName(Client_Window);
    } // setupUi

    void retranslateUi(QDialog *Client_Window)
    {
        Client_Window->setWindowTitle(QApplication::translate("Client_Window", "Dialog", 0));
        labIco->setText(QString());
        labTitle->setText(QApplication::translate("Client_Window", "\350\264\237\350\231\271\350\206\234\350\257\206\345\210\253\347\263\273\347\273\237", 0));
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("Client_Window", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("Client_Window", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        lineEdit_device_id->setPlaceholderText(QApplication::translate("Client_Window", "int \345\236\213\346\225\260\346\215\256 | \344\270\215\344\270\272\347\251\272", 0));
        pushButton_submit->setText(QApplication::translate("Client_Window", "\350\257\206\345\210\253", 0));
        pushButton_scanner->setText(QApplication::translate("Client_Window", "...", 0));
        label_device_id->setText(QApplication::translate("Client_Window", "\346\250\241\346\213\237\350\256\276\345\244\207id\357\274\232", 0));
        lineEdit_scanner->setPlaceholderText(QApplication::translate("Client_Window", "\350\257\267\351\200\211\346\213\251\350\231\271\350\206\234\345\233\276\347\211\207 | \344\270\215\344\270\272\347\251\272", 0));
        pushButton_exit->setText(QApplication::translate("Client_Window", "\351\200\200\345\207\272", 0));
        label_scanner->setText(QApplication::translate("Client_Window", "\350\257\267\345\260\206\350\231\271\350\206\234\346\255\243\345\257\271\346\211\253\346\217\217\345\231\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Client_Window: public Ui_Client_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_WINDOW_H
