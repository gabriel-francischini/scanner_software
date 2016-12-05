#-------------------------------------------------
#
# Project created by QtCreator 2016-11-12T02:40:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scanner_table
TEMPLATE = app


SOURCES += main.cpp \
    gerenciador_janelas.cpp \
    gerenciador_informacoes.cpp

HEADERS  += \
    gerenciador_janelas.h \
    gerenciador_informacoes.h

FORMS    += \
    janela_principal.ui \
    apontar_banco_de_dados.ui

RESOURCES +=

RC_ICONS = "resources/icon.ico"
