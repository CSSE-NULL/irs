/********************************************************************************
** Form generated from reading UI file 'Main_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Window
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
    QToolButton *btnMenu;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Close;
    QWidget *widgetMain;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widgetLeft;
    QVBoxLayout *verticalLayout_2;
    QToolButton *btn_host;
    QToolButton *btn_user;
    QToolButton *btn_device;
    QToolButton *btn_record;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidgetRight;

    void setupUi(QDialog *Main_Window)
    {
        if (Main_Window->objectName().isEmpty())
            Main_Window->setObjectName(QStringLiteral("Main_Window"));
        Main_Window->resize(954, 587);
        Main_Window->setStyleSheet(QStringLiteral(""));
        Main_Window->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(Main_Window);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(Main_Window);
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
        widgetMenu->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widgetMenu);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnMenu = new QToolButton(widgetMenu);
        btnMenu->setObjectName(QStringLiteral("btnMenu"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnMenu->sizePolicy().hasHeightForWidth());
        btnMenu->setSizePolicy(sizePolicy3);
        btnMenu->setMinimumSize(QSize(35, 0));
        btnMenu->setMaximumSize(QSize(35, 16777215));
        btnMenu->setFocusPolicy(Qt::NoFocus);
        btnMenu->setStyleSheet(QStringLiteral(""));
        btnMenu->setAutoRepeat(false);
        btnMenu->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(btnMenu);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy4);
        btnMenu_Min->setMinimumSize(QSize(35, 0));
        btnMenu_Min->setMaximumSize(QSize(35, 16777215));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);
        btnMenu_Min->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Min);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        sizePolicy3.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy3);
        btnMenu_Max->setMinimumSize(QSize(35, 0));
        btnMenu_Max->setMaximumSize(QSize(35, 16777215));
        btnMenu_Max->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);
        btnMenu_Max->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Max);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        sizePolicy3.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy3);
        btnMenu_Close->setMinimumSize(QSize(35, 0));
        btnMenu_Close->setMaximumSize(QSize(35, 16777215));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        btnMenu_Close->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Close);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        widgetMain = new QWidget(Main_Window);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        widgetMain->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(widgetMain);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widgetLeft = new QWidget(widgetMain);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        widgetLeft->setMinimumSize(QSize(100, 0));
        widgetLeft->setMaximumSize(QSize(100, 16777215));
        widgetLeft->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widgetLeft);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_host = new QToolButton(widgetLeft);
        btn_host->setObjectName(QStringLiteral("btn_host"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_host->sizePolicy().hasHeightForWidth());
        btn_host->setSizePolicy(sizePolicy5);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/infoextend.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_host->setIcon(icon);
        btn_host->setIconSize(QSize(50, 50));
        btn_host->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(btn_host);

        btn_user = new QToolButton(widgetLeft);
        btn_user->setObjectName(QStringLiteral("btn_user"));
        sizePolicy5.setHeightForWidth(btn_user->sizePolicy().hasHeightForWidth());
        btn_user->setSizePolicy(sizePolicy5);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/troublecheck.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_user->setIcon(icon1);
        btn_user->setIconSize(QSize(50, 50));
        btn_user->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(btn_user);

        btn_device = new QToolButton(widgetLeft);
        btn_device->setObjectName(QStringLiteral("btn_device"));
        sizePolicy5.setHeightForWidth(btn_device->sizePolicy().hasHeightForWidth());
        btn_device->setSizePolicy(sizePolicy5);
        btn_device->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/wifitest.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_device->setIcon(icon2);
        btn_device->setIconSize(QSize(50, 50));
        btn_device->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(btn_device);

        btn_record = new QToolButton(widgetLeft);
        btn_record->setObjectName(QStringLiteral("btn_record"));
        sizePolicy5.setHeightForWidth(btn_record->sizePolicy().hasHeightForWidth());
        btn_record->setSizePolicy(sizePolicy5);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/speedtest.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_record->setIcon(icon3);
        btn_record->setIconSize(QSize(50, 50));
        btn_record->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(btn_record);

        verticalSpacer = new QSpacerItem(20, 53, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widgetLeft);

        stackedWidgetRight = new QStackedWidget(widgetMain);
        stackedWidgetRight->setObjectName(QStringLiteral("stackedWidgetRight"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(9);
        stackedWidgetRight->setFont(font);

        horizontalLayout_3->addWidget(stackedWidgetRight);


        verticalLayout->addWidget(widgetMain);


        retranslateUi(Main_Window);

        QMetaObject::connectSlotsByName(Main_Window);
    } // setupUi

    void retranslateUi(QDialog *Main_Window)
    {
        Main_Window->setWindowTitle(QApplication::translate("Main_Window", "Dialog", 0));
        labIco->setText(QString());
        labTitle->setText(QApplication::translate("Main_Window", "\350\264\237\350\231\271\350\206\234\350\257\206\345\210\253\347\263\273\347\273\237", 0));
        btnMenu->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("Main_Window", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Max->setToolTip(QApplication::translate("Main_Window", "\346\234\200\345\244\247\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Max->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("Main_Window", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        btn_host->setText(QApplication::translate("Main_Window", "\344\270\273\351\241\265", 0));
        btn_user->setText(QApplication::translate("Main_Window", "\347\224\250\346\210\267\347\225\214\351\235\242", 0));
        btn_device->setText(QApplication::translate("Main_Window", "\350\256\276\345\244\207\347\225\214\351\235\242", 0));
        btn_record->setText(QApplication::translate("Main_Window", "\350\257\206\345\210\253\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class Main_Window: public Ui_Main_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
