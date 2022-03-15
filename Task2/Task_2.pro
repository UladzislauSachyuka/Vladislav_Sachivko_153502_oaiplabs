QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Task2/circle.cpp \
    ../Task2/hexagon.cpp \
    ../Task2/main.cpp \
    ../Task2/parallelogram.cpp \
    ../Task2/rectangle.cpp \
    ../Task2/romb.cpp \
    ../Task2/square.cpp \
    ../Task2/star.cpp \
    ../Task2/star5.cpp \
    ../Task2/star6.cpp \
    ../Task2/star8.cpp \
    ../Task2/triangle.cpp \
    ../Task2/universal.cpp \
    ../Task2/widget.cpp

HEADERS += \
    ../Task2/circle.h \
    ../Task2/hexagon.h \
    ../Task2/parallelogram.h \
    ../Task2/rectangle.h \
    ../Task2/romb.h \
    ../Task2/square.h \
    ../Task2/star.h \
    ../Task2/star5.h \
    ../Task2/star6.h \
    ../Task2/star8.h \
    ../Task2/triangle.h \
    ../Task2/universal.h \
    ../Task2/widget.h

FORMS += \
    ../Task2/widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
