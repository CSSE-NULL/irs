/********************************************************************************
** Form generated from reading UI file 'Message_Correct.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_CORRECT_H
#define UI_MESSAGE_CORRECT_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Message_Correct
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMenu_Close;
    QWidget *widgetInfo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_ico;
    QLabel *label_info;
    QWidget *button_box;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Message_Correct)
    {
        if (Message_Correct->objectName().isEmpty())
            Message_Correct->setObjectName(QStringLiteral("Message_Correct"));
        Message_Correct->resize(300, 177);
        verticalLayout = new QVBoxLayout(Message_Correct);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(Message_Correct);
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
        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy1);
        QPalette palette;
        labTitle->setPalette(palette);
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widgetMenu->sizePolicy().hasHeightForWidth());
        widgetMenu->setSizePolicy(sizePolicy2);
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
        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
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

        widgetInfo = new QWidget(Message_Correct);
        widgetInfo->setObjectName(QStringLiteral("widgetInfo"));
        horizontalLayout_4 = new QHBoxLayout(widgetInfo);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 20, 20, 20);
        label_ico = new QLabel(widgetInfo);
        label_ico->setObjectName(QStringLiteral("label_ico"));
        label_ico->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_ico);

        label_info = new QLabel(widgetInfo);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_info);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 10);

        verticalLayout->addWidget(widgetInfo);

        button_box = new QWidget(Message_Correct);
        button_box->setObjectName(QStringLiteral("button_box"));
        horizontalLayout_3 = new QHBoxLayout(button_box);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 20, 10, 20);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_confirm = new QPushButton(button_box);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout_3->addWidget(pushButton_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addWidget(button_box);


        retranslateUi(Message_Correct);

        QMetaObject::connectSlotsByName(Message_Correct);
    } // setupUi

    void retranslateUi(QDialog *Message_Correct)
    {
        Message_Correct->setWindowTitle(QApplication::translate("Message_Correct", "Dialog", 0));
        labTitle->setText(QApplication::translate("Message_Correct", "\346\255\243\347\241\256", 0));
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("Message_Correct", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        label_ico->setText(QString());
        label_info->setText(QString());
        pushButton_confirm->setText(QApplication::translate("Message_Correct", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class Message_Correct: public Ui_Message_Correct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_CORRECT_H
