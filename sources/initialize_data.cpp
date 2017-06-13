#include "mainwindow.h"

void MainWindow::initialize_data()
{
    for (short i=0;i<6;i++){
        experience_param_1[i]=0;
        experience_param_2[i]=0;
        experience_param_3[i]=0;
        experience_param_4[i]=0;
    }

    for (short i=0;i<256;i++){
        cpu_ai_id[i]=0;
        cpu_trainers[i].cup_id=0;
        cpu_cup_offset[i]=0;
        cpu_tname[i]="";
        for(short j=0;j<6;j++){
            cpu_pkm_nickname[i][j]="";
        }

        move_accuracy[i]=0;
        move_description[i]="";
        move_description_pointer[i]=0;
        move_effect[i]=0;
        move_iid[i]=0;
        move_name[i]="";
        move_name_pointer[i]=0;
        move_power[i]=0;
        move_pp[i]=0;
        move_tmhm[i]=0;
        move_tmhm_text[i]="";
        move_type[i]=0;

        pkm_base_hp[i] = 0;
        pkm_base_atk[i] = 0;
        pkm_base_def[i] = 0;
        pkm_base_speed[i] = 0;
        pkm_base_spc[i] = 0;
        pkm_type_1[i] = 0;
        pkm_type_2[i] = 0;
        pkm_catch_rate[i] = 0;
        pkm_base_experience[i] = 0;
        pkm_start_move_1[i] = 0;
        pkm_start_move_2[i] = 0;
        pkm_start_move_3[i] = 0;
        pkm_start_move_4[i] = 0;
        pkm_growth_rate[i] = 0;
        pkm_min_level[i] = 2;
        pkm_name[i] = "";
        pkm_name_pointer[i] = 0;
        for(short j=0;j<7;j++){
            pkm_tmhm_flags[i][j] = 0;
        }


        for(short j=0;j<10;j++){
            pkm_rb_lvl[i][j] = 0;
            pkm_rb_move[i][j] = 0;
            pkm_y_lvl[i][j] = 0;
            pkm_y_move[i][j] = 0;
        }

        type_name[i] = "";
    }

    for(short i=0;i<1024;i++){
        rental_pkm_nickname[i]="";
    }


    buf8=0;
    buf16=0;
    buf32=0;

    experience_calc=0;

    glc_level_min=50;
    glc_level_max=50;

    img_path="";

    move_high_ch_shiftvalue=0;
    move_tmhm_byte=0;
    move_tmhm_flag=0;

    rom_offset=0;
}
