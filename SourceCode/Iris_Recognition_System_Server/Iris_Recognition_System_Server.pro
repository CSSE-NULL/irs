#-------------------------------------------------
#
# Project created by QtCreator 2018-05-15T14:17:44
#
#-------------------------------------------------

QT       += core gui network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Iris_Recognition_System_Server
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \ 
    Function/Mysql_Operation.cpp \
    Function/appinit.cpp \
    Function/Recognition.cpp \
    Function/NDBManipulate.cpp\
    UI/Dialog/Dialog_Device_Add.cpp \
    UI/Dialog/Dialog_Device_Change.cpp \
    UI/Dialog/Dialog_User_Add.cpp \
    UI/Dialog/Dialog_User_Change.cpp \
    UI/System_Tray/System_Tray.cpp \
    UI/Tab/Tab_Device.cpp \
    UI/Tab/Tab_Host.cpp \
    UI/Tab/Tab_User.cpp \
    UI/Tab/Tab_Record.cpp \
    UI/Window/Main_Window.cpp \
    UI/Window/Login_Window.cpp \
    UI/Message/Message_Question.cpp \
    UI/Message/Message_Error.cpp \
    UI/Message/Message_Correct.cpp \
    main.cpp \
    Server/Server.cpp \
    Server/Socket.cpp \
    Scan/OsiCircle.cpp \
    Scan/OsiEye.cpp \
    Scan/OsiManager.cpp \
    Scan/OsiProcessings.cpp \
    Scan/Scan.cpp
 
HEADERS += \
    Function/Mysql_Operation.h \
    Function/appinit.h \
    UI/Dialog/Dialog_Device_Add.h \
    UI/Dialog/Dialog_Device_Change.h \
    UI/Dialog/Dialog_User_Add.h \
    UI/Dialog/Dialog_User_Change.h \
    UI/System_Tray/System_Tray.h \
    UI/Tab/Tab_Device.h \
    UI/Tab/Tab_Host.h \
    UI/Tab/Tab_User.h \
    UI/Tab/Tab_Record.h \
    UI/Window/Main_Window.h \
    UI/Window/Login_Window.h \
    UI/Message/Message_Question.h \
    UI/Message/Message_Error.h \
    UI/Message/Message_Correct.h \
    Server/Server.h \
    Server/Socket.h \
    Scan/cv.h \
    Scan/highgui.h\
    Scan/OsiCircle.h\
    Scan/OsiEye.h\
    Scan/OsiManager.h\
    Scan/OsiProcessings.h\
    Scan/OsiStringUtils.h\
    Scan/Scan.h

FORMS += \
    UI/Dialog/Dialog_Device_Add.ui \
    UI/Dialog/Dialog_Device_Change.ui \
    UI/Dialog/Dialog_User_Add.ui \
    UI/Dialog/Dialog_User_Change.ui \
    UI/Tab/Tab_Device.ui \
    UI/Tab/Tab_Host.ui \
    UI/Tab/Tab_User.ui \
    UI/Tab/Tab_Record.ui \
    UI/Window/Main_Window.ui \
    UI/Window/Login_Window.ui \
    UI/Message/Message_Error.ui \
    UI/Message/Message_Question.ui \
    UI/Message/Message_Correct.ui


RESOURCES += \
    qss.qrc \
    image.qrc

INCLUDEPATH+=d:/opencv/build/include/opencv \
                    d:/opencv/build/include/opencv2 \
                   d:/opencv/build/include
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_ml2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_calib3d2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_contrib2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_core2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_features2d2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_flann2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_gpu2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_highgui2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_imgproc2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_legacy2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_objdetect2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_ts2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_video2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_nonfree2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_ocl2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_photo2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_stitching2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_superres2410d.lib
LIBS+=D:\opencv\build\x86\vc12\lib\opencv_videostab2410d.lib

