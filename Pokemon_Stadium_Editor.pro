#-------------------------------------------------
#
# Project created by QtCreator 2015-12-31T01:34:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pokemon_Stadium_Editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rom_check.cpp \
    read_move_data.cpp \
    read_pkm_data.cpp \
    initialize_widgets.cpp \
    initialize_char_table.cpp \
    read_type_data.cpp \
    display_pkm_data.cpp \
    autoconnect.cpp \
    display_move_data.cpp \
    open_romfile.cpp \
    read_cpu_rentals.cpp \
    display_cpu_rentals.cpp \
    read_experience_data.cpp \
    display_experience_data.cpp

HEADERS  += mainwindow.h \
    common.cpp

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
