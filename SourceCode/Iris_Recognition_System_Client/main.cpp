#include "Client_Window.h"
#include "appinit.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppInit::Instance()->start();

    //加载样式表
    QFile file(":/qss/flatblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }

    a.setWindowIcon(QIcon(":/image/main.png"));
    a.setFont(QFont("Microsoft Yahei", 9));

    Client_Window w;
    w.show();

    return a.exec();
}
