/********************************************************************************
** Form generated from reading UI file 'Tab_Host.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_HOST_H
#define UI_TAB_HOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab_Host
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *Tab_Host)
    {
        if (Tab_Host->objectName().isEmpty())
            Tab_Host->setObjectName(QStringLiteral("Tab_Host"));
        Tab_Host->resize(501, 446);
        horizontalLayout = new QHBoxLayout(Tab_Host);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Tab_Host);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(Tab_Host);

        QMetaObject::connectSlotsByName(Tab_Host);
    } // setupUi

    void retranslateUi(QWidget *Tab_Host)
    {
        Tab_Host->setWindowTitle(QApplication::translate("Tab_Host", "Form", 0));
        label->setText(QApplication::translate("Tab_Host", "\346\254\242\350\277\216\344\275\277\347\224\250\350\264\237\350\231\271\350\206\234\350\257\206\345\210\253\347\263\273\347\273\237\357\274\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab_Host: public Ui_Tab_Host {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_HOST_H
