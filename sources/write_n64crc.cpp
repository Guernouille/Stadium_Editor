#include "mainwindow.h"

void MainWindow::write_n64crc(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x10);
    write<<header_crc1;
    write<<header_crc2;
}
