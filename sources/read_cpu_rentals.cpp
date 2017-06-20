#include "mainwindow.h"
#include <set>

void MainWindow::read_cpu_rentals(QFile &romfile)
{
    QDataStream read(&romfile);
    std::set<int> cpu_rentals_pointers;

    rom_offset = 0x89800F;
    romfile.seek(rom_offset);
    read>>total_cpu_rentals_array;

    for(short i=0;i<total_cpu_rentals_array;i++){
        rom_offset = 0x898010 + i*16;
        romfile.seek(rom_offset);
        read>>cpu_rentals_pointer[i];
        cpu_rentals_pointers.insert(cpu_rentals_pointer[i]);

        // rom_offset = 0x898016 + i*16;
        // romfile.seek(rom_offset);
        // read>>cpu_rentals_arraylen[i];
    }

    current_rentals_cup = 0;
    current_rentals_number = 0;
    current_cpu_trainers_cup = 0;
    current_cpu_trainers_number = 0;

    std::set<int>::const_iterator set_iter(cpu_rentals_pointers.begin()), set_end(cpu_rentals_pointers.end());

    for(;set_iter!=set_end;++set_iter){
        rom_offset = 0x898003 + *set_iter;
        romfile.seek(rom_offset);
        read>>total_cpu_rentals;

        // Rental Pokémon
        if(total_cpu_rentals>16){
            for(short i=current_rentals_number;i<(total_cpu_rentals+current_rentals_number);i++){
                rental_cup_id[i] = current_rentals_cup;

                rom_offset = 0x898004 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_id[i];

                rom_offset = 0x898008 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_level[i];

                rom_offset = 0x89800D + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_move_1[i];
                read>>rental_pkm_move_2[i];
                read>>rental_pkm_move_3[i];
                read>>rental_pkm_move_4[i];

                rom_offset = 0x898014 + (i-current_rentals_number)*84 + *set_iter;
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

                rom_offset = 0x89802A + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>rental_pkm_stat_hp[i];
                read>>rental_pkm_stat_atk[i];
                read>>rental_pkm_stat_def[i];
                read>>rental_pkm_stat_spc[i];
                read>>rental_pkm_stat_speed[i];

                // Rental Pokémon nickname
                rom_offset = 0x898034 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                read>>buf8;
                while(buf8 != 0 && buf8 != 0xFF && rental_pkm_nickname[i].size()<11){
                    rental_pkm_nickname[i] += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }

                // Rental Pokémon IVs
                rental_pkm_iv_atk[i] = rental_pkm_ivs[i] >> 12;
                rental_pkm_iv_def[i] = (rental_pkm_ivs[i] >> 8) & 0xF;
                rental_pkm_iv_speed[i] = (rental_pkm_ivs[i] >> 4) & 0xF;
                rental_pkm_iv_spc[i] = rental_pkm_ivs[i] & 0xF;
                rental_pkm_iv_hp[i] = (rental_pkm_iv_atk[i] & 1)*8 + (rental_pkm_iv_def[i] & 1)*4 + (rental_pkm_iv_speed[i] & 1)*2 + (rental_pkm_iv_spc[i] & 1);

                // Rental Pokémon PP Ups
                rental_pkm_ppup_1[i] = rental_pkm_pp_1[i] >> 6;
                rental_pkm_ppup_2[i] = rental_pkm_pp_2[i] >> 6;
                rental_pkm_ppup_3[i] = rental_pkm_pp_3[i] >> 6;
                rental_pkm_ppup_4[i] = rental_pkm_pp_4[i] >> 6;
            }
            current_rentals_cup++;
            current_rentals_number += total_cpu_rentals;
            rental_cup_offset[current_rentals_cup] = current_rentals_number;
        }
        // CPU Pokémon
        else{
            for(short i=current_cpu_trainers_number;i<(total_cpu_rentals+current_cpu_trainers_number);i++){
                cpu_trainers[i].cup_id = current_cpu_trainers_cup;

                rom_offset = 0x898004 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                read>>buf8;

                // CPU Trainer name
                while(buf8 != 0 && buf8 != 0xFF && cpu_trainers[i].name.size()<11){
                    cpu_trainers[i].name += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }

                // CPU Trainer sprite
                rom_offset = 0x898038 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                read>>cpu_trainers[i].sprite_id;

                // CPU AI id
                read>>cpu_trainers[i].ai_id;

                // CPU Trainer party size
                rom_offset = 0x89803B + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                read>>cpu_trainers[i].party_size;

                // CPU Trainer Pokémon data
                for(short j=0;j<6;j++){
                    rom_offset = 0x89803C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_trainers[i].pkm[j].id;

                    rom_offset = 0x898040 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_trainers[i].pkm[j].lvl;

                    rom_offset = 0x898045 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_trainers[i].pkm[j].move_1;
                    read>>cpu_trainers[i].pkm[j].move_2;
                    read>>cpu_trainers[i].pkm[j].move_3;
                    read>>cpu_trainers[i].pkm[j].move_4;

                    rom_offset = 0x89804C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_trainers[i].pkm[j].exp;
                    read>>cpu_trainers[i].pkm[j].hp_ev;
                    read>>cpu_trainers[i].pkm[j].atk_ev;
                    read>>cpu_trainers[i].pkm[j].def_ev;
                    read>>cpu_trainers[i].pkm[j].speed_ev;
                    read>>cpu_trainers[i].pkm[j].spc_ev;
                    read>>cpu_trainers[i].pkm[j].ivs;
                    read>>cpu_trainers[i].pkm[j].pp_1;
                    read>>cpu_trainers[i].pkm[j].pp_2;
                    read>>cpu_trainers[i].pkm[j].pp_3;
                    read>>cpu_trainers[i].pkm[j].pp_4;

                    rom_offset = 0x898062 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>cpu_pkm_stat_hp[i][j];
                    read>>cpu_pkm_stat_atk[i][j];
                    read>>cpu_pkm_stat_def[i][j];
                    read>>cpu_pkm_stat_spc[i][j];
                    read>>cpu_pkm_stat_speed[i][j];

                    // CPU Trainer Pokémon nickname
                    rom_offset = 0x89806C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    read>>buf8;
                    while(buf8 != 0 && buf8 != 0xFF && cpu_trainers[i].pkm[j].nick.size()<11){
                        cpu_trainers[i].pkm[j].nick += char_table[buf8];
                        rom_offset++;
                        romfile.seek(rom_offset);
                        read>>buf8;
                    }

                    // CPU Pokémon IVs
                    cpu_trainers[i].pkm[j].atk_iv = cpu_trainers[i].pkm[j].ivs >> 12;
                    cpu_trainers[i].pkm[j].def_iv = (cpu_trainers[i].pkm[j].ivs >> 8) & 0xF;
                    cpu_trainers[i].pkm[j].speed_iv = (cpu_trainers[i].pkm[j].ivs >> 4) & 0xF;
                    cpu_trainers[i].pkm[j].spc_iv = cpu_trainers[i].pkm[j].ivs & 0xF;
                    cpu_trainers[i].pkm[j].hp_iv = (cpu_trainers[i].pkm[j].atk_iv & 1)*8 + (cpu_trainers[i].pkm[j].def_iv & 1)*4 + (cpu_trainers[i].pkm[j].speed_iv & 1)*2 + (cpu_trainers[i].pkm[j].spc_iv & 1);

                    // CPU Pokémon PP Ups
                    cpu_pkm_ppup_1[i][j] = cpu_trainers[i].pkm[j].pp_1 >> 6;
                    cpu_pkm_ppup_2[i][j] = cpu_trainers[i].pkm[j].pp_2 >> 6;
                    cpu_pkm_ppup_3[i][j] = cpu_trainers[i].pkm[j].pp_3 >> 6;
                    cpu_pkm_ppup_4[i][j] = cpu_trainers[i].pkm[j].pp_4 >> 6;
                }
            }
            current_cpu_trainers_cup++;
            current_cpu_trainers_number += total_cpu_rentals;
            cpu_cup_offset[current_cpu_trainers_cup] = current_cpu_trainers_number;
        }
    }

    if(current_rentals_number%6!=0 && (current_rentals_number+5)<1024){
        rental_cup_id[current_rentals_number+4] = current_rentals_cup-1;
    }
}
