#ifndef APPINIT_H
#define APPINIT_H

#include <QWidget>
#include <QObject>
#include <QMutexLocker>

class AppInit : public QObject
{
    Q_OBJECT

public:
    explicit AppInit(QObject *parent = 0);

    static AppInit *Instance(){
        static QMutex mutex;
        if (!self) {
            QMutexLocker locker(&mutex);
            if (!self) {
                self = new AppInit;
            }
        }
        return self;
    }

    void start();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    static AppInit *self;
};

#endif // APPINIT_H
