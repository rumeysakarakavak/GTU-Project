QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    scoresdialog.cpp \
    dialog.cpp \
    moveitem.cpp \
    renderarea.cpp

HEADERS += \
    mainwindow.h \
    scoresdialog.h \
    dialog.h \
    moveitem.h \
    renderarea.h

FORMS += \
    mainwindow.ui \
    scoresdialog.ui \
    dialog.ui

TRANSLATIONS += \
    project_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    langırt.PNG

RESOURCES += \
    resources.qrc
