#include "mainwindow.h"

void MainWindow::write_move_data(QFile &romfile){
    QDataStream write(&romfile);

    rom_offset = 0x73700;
    romfile.seek(rom_offset);

    // ***** Write move data *****
    for(short i=1;i<=total_move_name;i++){
        write<<move_iid[i];
        write<<move_effect[i];
        write<<move_power[i];

        if(move_type[i]>8) move_type[i] += 11;
        write<<move_type[i];
        if(move_type[i]>19) move_type[i] -= 11;

        write<<move_accuracy[i];
        write<<move_pp[i];
    }

    // ***** Write move type icons IDs *****
    for(short i=1;i<=total_move_name;i++){
        rom_offset = 0x72F2D + i*12;
        romfile.seek(rom_offset);
        write<<move_type[i];
    }

    // ***** Write High CH moves *****
    rom_offset = 0x37570C;
    romfile.seek(rom_offset);

    write<<move_high_ch[0];
    write<<move_high_ch[1];
    write<<move_high_ch[2];
    write<<move_high_ch[3];
}

void MainWindow::write_tmhm_data(QFile &romfile)
{
    QDataStream write(&romfile);

    // ***** Write TM/HM data *****
    rom_offset = 0x73E30;
    romfile.seek(rom_offset);
    for(uint8_t i=1;i<56;i++) write<<move_tmhm[i];

    rom_offset = 0x375874;
    romfile.seek(rom_offset);
    for(uint8_t i=1;i<56;i++) write<<move_tmhm[i];
}
