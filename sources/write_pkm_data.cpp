#include "mainwindow.h"

void MainWindow::write_pkm_data(QFile &romfile){
    QDataStream write(&romfile);

    for(short i=1;i<=total_pkm_name;i++){
        rom_offset = 0x71B8A + i*23;
        romfile.seek(rom_offset);

        write<<pkm_base_hp[i];
        write<<pkm_base_atk[i];
        write<<pkm_base_def[i];
        write<<pkm_base_speed[i];
        write<<pkm_base_spc[i];

        if(pkm_type_1[i]>8) pkm_type_1[i] += 11;
        if(pkm_type_2[i]>8) pkm_type_2[i] += 11;
        write<<pkm_type_1[i];
        write<<pkm_type_2[i];
        if(pkm_type_1[i]>19) pkm_type_1[i] -= 11;
        if(pkm_type_2[i]>19) pkm_type_2[i] -= 11;

        write<<pkm_catch_rate[i];
        write<<pkm_base_experience[i];

        write<<pkm_start_move_1[i];
        write<<pkm_start_move_2[i];
        write<<pkm_start_move_3[i];
        write<<pkm_start_move_4[i];

        write<<pkm_growth_rate[i];

        write<<pkm_tmhm_flags[i][0];
        write<<pkm_tmhm_flags[i][1];
        write<<pkm_tmhm_flags[i][2];
        write<<pkm_tmhm_flags[i][3];
        write<<pkm_tmhm_flags[i][4];
        write<<pkm_tmhm_flags[i][5];
        write<<pkm_tmhm_flags[i][6];

    }
}
