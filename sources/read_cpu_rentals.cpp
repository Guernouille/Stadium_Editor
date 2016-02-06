#include "mainwindow.h"
#include <set>

void MainWindow::read_cpu_rentals(QFile &romfile)
{
    QDataStream read(&romfile);
    std::set<int> cpu_rentals_pointers;

    rom_offset = 0x89800F;
    romfile.seek(rom_offset);
    read>>total_cpu_rentals_array;


    for(short i=0;i<256;i++){
        cpu_tname[i]="";
        for(short j=0;j<6;j++){
            cpu_pkm_nickname[i][j]="";
        }
    }
    for(short i=0;i<1024;i++){
        rental_pkm_nickname[i]="";
    }

    for(short i=0;i<=total_cpu_rentals_array;i++){
        rom_offset = 0x898010 + i*16;
        romfile.seek(rom_offset);
        read>>cpu_rentals_pointer[i];
        cpu_rentals_pointers.insert(cpu_rentals_pointer[i]);

        // rom_offset = 0x898016 + i*16;
        // romfile.seek(rom_offset);
        // read>>cpu_rentals_arraylen[i];
    }

    short current_rentals_number = 0;
    short current_cpu_trainers_number = 0;

    std::set<int>::const_iterator set_iter(cpu_rentals_pointers.begin()), set_end(cpu_rentals_pointers.end());

    for(;set_iter!=set_end;++set_iter){
        rom_offset = 0x898003 + *set_iter;
        romfile.seek(rom_offset);
        read>>total_cpu_rentals;

        // Rental Pokémon
        if(total_cpu_rentals>16){
            for(short i=current_rentals_number;i<(total_cpu_rentals+current_rentals_number);i++){
                rom_offset = 0x898004 + i*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_id[i];

                rom_offset = 0x898008 + i*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_level[i];

                rom_offset = 0x89800D + i*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_move_1[i];
                read>>rental_pkm_move_2[i];
                read>>rental_pkm_move_3[i];
                read>>rental_pkm_move_4[i];

                rom_offset = 0x898014 + i*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_experience[i];
                read>>rental_pkm_ev_hp[i];
                read>>rental_pkm_ev_atk[i];
                read>>rental_pkm_ev_def[i];
                read>>rental_pkm_ev_speed[i];
                read>>rental_pkm_ev_spc[i];
                read>>rental_pkm_ivs[i];
                read>>rental_pkm_pp_1[i];
                read>>rental_pkm_pp_2[i];
                read>>rental_pkm_pp_3[i];
                read>>rental_pkm_pp_4[i];

                rom_offset = 0x898034 + i*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>buf8;

                // Rental Pokémon nickname
                while(buf8 != 0 && buf8 != 0xFF && rental_pkm_nickname[i].size()<11){
                    rental_pkm_nickname[i] += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }
            }
            current_rentals_number += total_cpu_rentals;
        }
        // CPU Pokémon
        else{
            for(short i=current_cpu_trainers_number;i<(total_cpu_rentals+current_cpu_trainers_number);i++){
                rom_offset = 0x898004 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                read>>buf8;

                // CPU Trainer name
                while(buf8 != 0 && buf8 != 0xFF && cpu_tname[i].size()<11){
                    cpu_tname[i] += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }

                // CPU Trainer sprite
                rom_offset = 0x898038 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                read>>cpu_sprite_id[i];

                // CPU Trainer party size
                rom_offset = 0x89803B + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                read>>cpu_party_size[i];

                // CPU Trainer Pokémon data
                for(short j=0;j<cpu_party_size[i];j++){
                    rom_offset = 0x89803C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_pkm_id[i][j];

                    rom_offset = 0x898040 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_pkm_level[i][j];

                    rom_offset = 0x898045 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_pkm_move_1[i][j];
                    read>>cpu_pkm_move_2[i][j];
                    read>>cpu_pkm_move_3[i][j];
                    read>>cpu_pkm_move_4[i][j];

                    rom_offset = 0x89804C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_pkm_experience[i][j];
                    read>>cpu_pkm_ev_hp[i][j];
                    read>>cpu_pkm_ev_atk[i][j];
                    read>>cpu_pkm_ev_def[i][j];
                    read>>cpu_pkm_ev_speed[i][j];
                    read>>cpu_pkm_ev_spc[i][j];
                    read>>cpu_pkm_ivs[i][j];
                    read>>cpu_pkm_pp_1[i][j];
                    read>>cpu_pkm_pp_2[i][j];
                    read>>cpu_pkm_pp_3[i][j];
                    read>>cpu_pkm_pp_4[i][j];

                    rom_offset = 0x89806C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>buf8;

                    // CPU Trainer Pokémon nickname
                    while(buf8 != 0 && buf8 != 0xFF && cpu_pkm_nickname[i][j].size()<11){
                        cpu_pkm_nickname[i][j] += char_table[buf8];
                        rom_offset++;
                        romfile.seek(rom_offset);
                        read>>buf8;
                    }

                    // CPU Pokémon IVs
                    cpu_pkm_iv_atk[i][j] = cpu_pkm_ivs[i][j] >> 12;
                    cpu_pkm_iv_def[i][j] = (cpu_pkm_ivs[i][j] >> 8) & 0xF;
                    cpu_pkm_iv_speed[i][j] = (cpu_pkm_ivs[i][j] >> 4) & 0xF;
                    cpu_pkm_iv_spc[i][j] = cpu_pkm_ivs[i][j] & 0xF;
                    cpu_pkm_iv_hp[i][j] = (cpu_pkm_iv_atk[i][j] & 1)*8 + (cpu_pkm_iv_def[i][j] & 1)*4 + (cpu_pkm_iv_speed[i][j] & 1)*2 + (cpu_pkm_iv_spc[i][j] & 1);

                    // CPU Pokémon PP Ups
                    cpu_pkm_ppup_1[i][j] = cpu_pkm_pp_1[i][j] >> 6;
                    cpu_pkm_ppup_2[i][j] = cpu_pkm_pp_2[i][j] >> 6;
                    cpu_pkm_ppup_3[i][j] = cpu_pkm_pp_3[i][j] >> 6;
                    cpu_pkm_ppup_4[i][j] = cpu_pkm_pp_4[i][j] >> 6;
                }
            }
            current_cpu_trainers_number += total_cpu_rentals;
        }
    }
}
