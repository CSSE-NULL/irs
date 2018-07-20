#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T18:30:59
#
#-------------------------------------------------

QT       += core gui network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Iris_Recognition_System_Client
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
    main.cpp \
    Client_Window.cpp \
    appinit.cpp \
    Message/Message_Error.cpp \
    Message/Message_Question.cpp \
    Message/Message_Correct.cpp \
    Scan.cpp\
    OsiManager.cpp\
    OsiEye.cpp\
    OsiProcessings.cpp\
    OsiCircle.cpp\
    NDBManipulate.cpp

HEADERS += \
    Client_Window.h \
    appinit.h \
    Message/Message_Error.h \
    Message/Message_Question.h \
    Message/Message_Correct.h \
    Scan.h\
    OsiManager.h\
    OsiEye.h\
    OsiProcessings.h\
    cv.h\
    highgui.h\
    OsiStringUtils.h\
    OsiCircle.h\
    NDBManipulate.h


FORMS += \
    Client_Window.ui \
    Message/Message_Error.ui \
    Message/Message_Question.ui \
    Message/Message_Correct.ui


RESOURCES += \
    qss.qrc \
    image.qrc \
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
