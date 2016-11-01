#include "mainwindow.h"

void MainWindow::read_ch_formula(QFile &romfile)
{
    QDataStream read(&romfile);

    romfile.seek(0x35C523);
    read>>ch_formula_add;

    romfile.seek(0x35C528);
    read>>buf32;
    ch_formula_shift[0] = buf32 & 0x3F;
    if(ch_formula_shift[0] != 0) ch_formula_shift[0] = 1;
    ch_formula_shiftvalue[0] = (buf32 >> 6) & 0x1F;

    romfile.seek(0x35C58C);
    read>>buf32;
    ch_fe_formula_shift = buf32 & 0x3F;
    if(ch_fe_formula_shift != 0) ch_fe_formula_shift = 1;
    ch_fe_formula_shiftvalue = (buf32 >> 6) & 0x1F;

    romfile.seek(0x35C597);
    read>>ch_fe_formula_add;

    romfile.seek(0x35C598);
    read>>buf32;
    ch_formula_shift[1] = buf32 & 0x3F;
    if(ch_formula_shift[1] != 0) ch_formula_shift[1] = 1;
    ch_formula_shiftvalue[1] = (buf32 >> 6) & 0x1F;

    romfile.seek(0x35C5BC);
    read>>buf32;
    ch_formula_shift[2] = buf32 & 0x3F;
    if(ch_formula_shift[2] != 0) ch_formula_shift[2] = 1;
    ch_formula_shiftvalue[2] = (buf32 >> 6) & 0x1F;
}
