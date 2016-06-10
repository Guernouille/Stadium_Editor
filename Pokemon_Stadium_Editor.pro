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
    display_move_data.cpp \
    open_romfile.cpp \
    read_cpu_rentals.cpp \
    display_cpu_rentals.cpp \
    read_experience_data.cpp \
    initialize_data.cpp \
    randomize_cpu_teams.cpp \
    calc_experience_data.cpp \
    prng.cpp \
    autoconn_randomizer.cpp \
    autoconn_display_cpu_teams.cpp \
    autoconn_edit_cpu_teams.cpp \
    autoconn_display_move_data.cpp \
    autoconn_display_pkm_data.cpp \
    autoconn_edit_move_data.cpp \
    autoconn_save.cpp \
    write_pkm_data.cpp \
    write_cpu_rentals.cpp \
    initialize_nicknames.cpp \
    initialize_min_levels.cpp \
    autoconn_display_rental_pkm.cpp \
    autoconn_edit_rental_pkm.cpp \
    randomize_rental_pkm.cpp \
    randomize_type_data.cpp \
    write_type_data.cpp \
    display_type_data.cpp \
    autoconn_edit_type_data.cpp

HEADERS  += mainwindow.h \
    common.cpp \
    hexqspinbox.h \
    rental_pkm.h \
    type_chart.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

CONFIG += c++14
