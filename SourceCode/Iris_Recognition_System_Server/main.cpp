#include "UI/Window/Login_Window.h"
#include "UI/Window/Main_Window.h"
#include "Function/appinit.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //实现窗体拖动
    AppInit::Instance()->start();

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif

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

    Login_Window l;
    if (l.exec() == QDialog::Accepted) {
        Main_Window f;
        f.show();
        return a.exec();
    } else {
        return 0;
    }
}

