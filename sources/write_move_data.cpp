#include "mainwindow.h"

void MainWindow::write_move_data(QFile &romfile){
    QDataStream write(&romfile);

    // ***** Write move data *****
    for(short i=1;i<=total_move_name;i++){
        rom_offset = 0x736FA + i*6;
        romfile.seek(rom_offset);

        write<<move_iid[i];
        write<<move_effect[i];
        write<<move_power[i];
        write<<move_type[i];
        write<<move_accuracy[i];
        write<<move_pp[i];

        if(move_type[i]>8) move_type[i] += 11;
        write<<move_type[i];
        if(move_type[i]>19) move_type[i] -= 11;
    }

    // ***** Write High CH moves *****
    rom_offset = 0x37570C + i;
    romfile.seek(rom_offset);

    write<<move_high_ch[0];
    write<<move_high_ch[1];
    write<<move_high_ch[2];
    write<<move_high_ch[3];
}
