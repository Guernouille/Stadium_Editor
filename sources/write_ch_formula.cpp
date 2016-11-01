#include "mainwindow.h"

void MainWindow::write_ch_formula(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x35C523);
    write<<ch_formula_add;

    romfile.seek(0x35C528);
    if(ch_formula_shift[0] != 0) buf32 = 3;
    else buf32 = 0;
    buf32 ^= (ch_formula_shiftvalue[0] << 6);
    buf32 ^= 0x31800; // reg V1 to reg V1
    write<<buf32;

    romfile.seek(0x35C58C);
    if(ch_fe_formula_shift != 0) buf32 = 3;
    else buf32 = 0;
    buf32 ^= (ch_fe_formula_shiftvalue << 6);
    buf32 ^= 0x31800; // reg V1 to reg V1
    write<<buf32;

    romfile.seek(0x35C597);
    write<<ch_fe_formula_add;

    romfile.seek(0x35C598);
    if(ch_formula_shift[1] != 0) buf32 = 3;
    else buf32 = 0;
    buf32 ^= (ch_formula_shiftvalue[1] << 6);
    buf32 ^= 0x31800; // reg V1 to reg V1
    write<<buf32;

    romfile.seek(0x35C5BC);
    if(ch_formula_shift[2] != 0) buf32 = 3;
    else buf32 = 0;
    buf32 ^= (ch_formula_shiftvalue[2] << 6);
    buf32 ^= 0x31800; // reg V1 to reg V1
    write<<buf32;
}
