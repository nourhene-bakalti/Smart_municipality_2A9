QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui charts
CONFIG += c++11
QT += printsupport

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    conge.cpp \
    connexion.cpp \
    employe.cpp \
    main.cpp \
    mainwindow.cpp \
    stat_employe.cpp

HEADERS += \
    conge.h \
    connexion.h \
    employe.h \
    mainwindow.h \
    stat_employe.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
