QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    edge3d.cpp \
    light.cpp \
    main.cpp \
    mainwindow.cpp \
    mathtransformation.cpp \
    model3d.cpp \
    modelbuilder.cpp \
    renderer.cpp \
    scene.cpp

HEADERS += \
    camera.h \
    edge3d.h \
    light.h \
    mainwindow.h \
    mathtransformation.h \
    model3d.h \
    modelbuilder.h \
    renderer.h \
    scene.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
