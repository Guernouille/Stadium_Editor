#include "mainwindow.h"

void MainWindow::write_type_chart(QFile &romfile)
{
    QDataStream write(&romfile);

    rom_offset = 0x3755B0;
    romfile.seek(rom_offset);

    for(uint8_t i=0;i<82;i++){
        write<<type_chart[i].getType1();
        write<<type_chart[i].getType2();
        write<<type_chart[i].getMultiplier();
    }
}
