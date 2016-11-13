#include "mainwindow.h"

void MainWindow::write_burn_shift(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x35B420);
    if(burn_shift != 0) buf32 = 2;
    else buf32 = 0;
    buf32 ^= (burn_shiftvalue << 6);
    buf32 ^= 0x18C800; // reg T8 to reg T9
    write<<buf32;
}

void MainWindow::write_damage_variance(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x35A4F7);
    write<<damage_variance_min;
}

void MainWindow::write_highCH_shift(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x35C5B4);
    if(move_high_ch_shift != 0) buf32 = 3;
    else buf32 = 0;
    buf32 ^= (move_high_ch_shiftvalue << 6);
    buf32 ^= 0x31800; // reg V1 to reg V1
    write<<buf32;
}

void MainWindow::write_odds_paralysis(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x35CC33);
    write<<odds_paralysis;
}
