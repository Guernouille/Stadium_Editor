#include "mainwindow.h"

void MainWindow::on_actionSave_triggered(){
    QFile romfile(filename);
    romfile.open(QIODevice::ReadWrite);

    n64crc(romfile);
    write_n64crc(romfile);
    write_move_data(romfile);
    write_pkm_data(romfile);
    write_cpu_rentals(romfile);
    write_type_chart(romfile);

    romfile.close();
}
