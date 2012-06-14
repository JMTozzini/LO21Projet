#-------------------------------------------------
#
# Project created by QtCreator 2012-05-24T08:18:04
#
#-------------------------------------------------

QT       += core gui

TARGET = Calculatrice
TEMPLATE = app

#ICON = iconeCalculatte.png

SOURCES += main.cpp\
        mainwindow.cpp \
    affichageNum.cpp \
    affichageAutre.cpp \
    affichageOp.cpp \
    menu.cpp \
    fonctionsAnnexe.cpp \
    pile.cpp \
    memento.cpp \
    pileOp.cpp \
    operateursUnaires.cpp \
    constanteOpPlus.cpp \
    constanteOpMoins.cpp \
    constanteOpDiv.cpp \
    constanteOpMult.cpp \
    constanteOpPow.cpp \
    constanteOpMod.cpp

HEADERS  += mainwindow.h \
    pile.h \
    constante.h \
    fonctionsAnnexe.h \
    exceptionCalculatrice.h \
    memento.h

FORMS    += \
    mainwindow.ui

RESOURCES +=

