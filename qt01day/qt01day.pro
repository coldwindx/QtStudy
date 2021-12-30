#-------------------------------------------------
#
# Project created by QtCreator 2021-12-29T19:30:22
#
#-------------------------------------------------

# 为Qt添加模块 coreQT核心模块 gui图形用户界面
QT       += core gui
# 4.0版本以后的版本添加widgets模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# 生成的.exe的名字
TARGET = qt01day
# 使用的模板
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
# 定义选项添加 QT_DEPRECATED_WARNINGS 编译器提升警告
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        Widget.cpp \
    Mybutton.cpp \
    Boss.cpp

HEADERS += \
        Widget.h \
    Mybutton.h \
    Boss.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
