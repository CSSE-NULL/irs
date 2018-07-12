/********************************************************************************
** Form generated from reading UI file 'Login_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login_Window
{
public:
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;
    QLineEdit *lineEdit_admin_name;
    QLineEdit *lineEdit_admin_password;
    QLabel *labIco;
    QLabel *label_system;

    void setupUi(QDialog *Login_Window)
    {
        if (Login_Window->objectName().isEmpty())
            Login_Window->setObjectName(QStringLiteral("Login_Window"));
        Login_Window->resize(507, 358);
        pushButton_login = new QPushButton(Login_Window);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(110, 270, 111, 31));
        pushButton_exit = new QPushButton(Login_Window);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(280, 270, 111, 31));
        lineEdit_admin_name = new QLineEdit(Login_Window);
        lineEdit_admin_name->setObjectName(QStringLiteral("lineEdit_admin_name"));
        lineEdit_admin_name->setGeometry(QRect(110, 150, 281, 31));
        lineEdit_admin_password = new QLineEdit(Login_Window);
        lineEdit_admin_password->setObjectName(QStringLiteral("lineEdit_admin_password"));
        lineEdit_admin_password->setGeometry(QRect(110, 210, 281, 31));
        lineEdit_admin_password->setEchoMode(QLineEdit::Password);
        labIco = new QLabel(Login_Window);
        labIco->setObjectName(QStringLiteral("labIco"));
        labIco->setGeometry(QRect(130, 40, 111, 81));
        label_system = new QLabel(Login_Window);
        label_system->setObjectName(QStringLiteral("label_system"));
        label_system->setGeometry(QRect(250, 50, 141, 61));
        label_system->setScaledContents(false);
        label_system->setMargin(0);
        label_system->setIndent(-1);

        retranslateUi(Login_Window);

        QMetaObject::connectSlotsByName(Login_Window);
    } // setupUi

    void retranslateUi(QDialog *Login_Window)
    {
        Login_Window->setWindowTitle(QApplication::translate("Login_Window", "Dialog", 0));
        pushButton_login->setText(QApplication::translate("Login_Window", "\347\231\273\351\231\206", 0));
        pushButton_exit->setText(QApplication::translate("Login_Window", "\351\200\200\345\207\272", 0));
        lineEdit_admin_name->setInputMask(QString());
        lineEdit_admin_name->setPlaceholderText(QApplication::translate("Login_Window", "\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\345\220\215", 0));
        lineEdit_admin_password->setInputMask(QString());
        lineEdit_admin_password->setPlaceholderText(QApplication::translate("Login_Window", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201", 0));
        labIco->setText(QString());
        label_system->setText(QApplication::translate("Login_Window", "   \350\264\237\350\231\271\350\206\234\350\257\206\345\210\253\347\263\273\347\273\237", 0));
    } // retranslateUi

};

namespace Ui {
    class Login_Window: public Ui_Login_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WINDOW_H
