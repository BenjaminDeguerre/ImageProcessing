#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T17:23:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageExtractor
TEMPLATE = app

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

SOURCES += main.cpp\
        mainwindow.cpp \
    roiwizard.cpp \
    dataselection.cpp \
    intropage.cpp \
    parameterpage.cpp \
    conclusionpage.cpp \
    classadder.cpp \
    qlabelimage.cpp \
    roiselection.cpp \
    roiselectioncutdown.cpp \
    parameterpagecutdown.cpp \
    roiwizardcutdown.cpp \
    roiselectioninterface.cpp

HEADERS  += mainwindow.h \
    roiwizard.h \
    dataselection.h \
    intropage.h \
    parameterpage.h \
    conclusionpage.h \
    classadder.h \
    qlabelimage.h \
    roiselection.h \
    roiselectioncutdown.h \
    parameterpagecutdown.h \
    roiwizardcutdown.h \
    roiselectioninterface.h

FORMS    += mainwindow.ui \
    dataselection.ui \
    parameterpage.ui \
    intropage.ui \
    conclusionpage.ui \
    classadder.ui \
    roiselection.ui \
    roiselectioncutdown.ui \
    parameterpagecutdown.ui

DISTFILES +=

RESOURCES +=
