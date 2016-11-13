#include "mainwindow.h"

void MainWindow::read_burn_shift(QFile &romfile)
{
    QDataStream read(&romfile);

    romfile.seek(0x35B420);
    read>>buf32;
    burn_shift = buf32 & 0x3F;
    if(burn_shift != 0) burn_shift = 1;
    burn_shiftvalue = (buf32 >> 6) & 0x1F;
}

void MainWindow::read_damage_variance(QFile &romfile)
{
    QDataStream read(&romfile);
    romfile.seek(0x35A4F7);
    read>>damage_variance_min;
}

void MainWindow::read_highCH_shift(QFile &romfile)
{
    QDataStream read(&romfile);

    romfile.seek(0x35C5B4);
    read>>buf32;
    move_high_ch_shift = buf32 & 0x3F;
    if(move_high_ch_shift != 0) move_high_ch_shift = 1;
    move_high_ch_shiftvalue = (buf32 >> 6) & 0x1F;
}

void MainWindow::read_odds_paralysis(QFile &romfile)
{
    QDataStream read(&romfile);

    romfile.seek(0x35CC33);
    read>>odds_paralysis;
}
