#include "mainwindow.h"
#include <algorithm>
#include <math.h>
#include <set>

void MainWindow::write_cpu_rentals(QFile &romfile)
{
    QDataStream write(&romfile);
    std::set<int> cpu_rentals_pointers;

    rom_offset = 0x89800F;
    romfile.seek(rom_offset);
    write>>total_cpu_rentals_array;

    for(short i=0;i<total_cpu_rentals_array;i++){
        rom_offset = 0x898010 + i*16;
        romfile.seek(rom_offset);
        write>>cpu_rentals_pointer[i];
        cpu_rentals_pointers.insert(cpu_rentals_pointer[i]);
    }

    current_rentals_number = 0;
    current_cpu_trainers_cup = 0;
    current_cpu_trainers_number = 0;

    std::set<int>::const_iterator set_iter(cpu_rentals_pointers.begin()), set_end(cpu_rentals_pointers.end());

    for(;set_iter!=set_end;++set_iter){
        rom_offset = 0x898003 + *set_iter;
        romfile.seek(rom_offset);
        write>>total_cpu_rentals;

        // Rental Pokémon
        if(total_cpu_rentals>16){
            for(short i=current_rentals_number;i<(total_cpu_rentals+current_rentals_number);i++){
                // Stats calculation
                // Stat Exp : E = floor(min(255, floor(√(max(0, Stat Experience - 1)) + 1)) / 4)
                // HP       : (((Base + IV) * 2 + E) * Level) / 100 + Level + 10
                // Stats    : (((Base + IV) * 2 + E) * Level) / 100 + 5
                rental_pkm_stat_hp[i] = floor(sqrt(std::max(0,rental_pkm_ev_hp[i]-1))+1);
                rental_pkm_stat_hp[i] = floor(std::min(quint16(255),rental_pkm_stat_hp[i])/4);
                rental_pkm_stat_hp[i] = floor((((pkm_base_hp[rental_pkm_id[i]] + rental_pkm_iv_hp[i])*2 + rental_pkm_stat_hp[i]) * rental_pkm_level[i] / 100) + rental_pkm_level[i]+10);
                rental_pkm_stat_atk[i] = floor(sqrt(std::max(0,rental_pkm_ev_atk[i]-1))+1);
                rental_pkm_stat_atk[i] = floor(std::min(quint16(255),rental_pkm_stat_atk[i])/4);
                rental_pkm_stat_atk[i] = floor((((pkm_base_atk[rental_pkm_id[i]] + rental_pkm_iv_atk[i])*2 + rental_pkm_stat_atk[i]) * rental_pkm_level[i] / 100) + 5);
                rental_pkm_stat_def[i] = floor(sqrt(std::max(0,rental_pkm_ev_def[i]-1))+1);
                rental_pkm_stat_def[i] = floor(std::min(quint16(255),rental_pkm_stat_def[i])/4);
                rental_pkm_stat_def[i] = floor((((pkm_base_def[rental_pkm_id[i]] + rental_pkm_iv_def[i])*2 + rental_pkm_stat_def[i]) * rental_pkm_level[i] / 100) + 5);
                rental_pkm_stat_speed[i] = floor(sqrt(std::max(0,rental_pkm_ev_speed[i]-1))+1);
                rental_pkm_stat_speed[i] = floor(std::min(quint16(255),rental_pkm_stat_speed[i])/4);
                rental_pkm_stat_speed[i] = floor((((pkm_base_speed[rental_pkm_id[i]] + rental_pkm_iv_speed[i])*2 + rental_pkm_stat_speed[i]) * rental_pkm_level[i] / 100) + 5);
                rental_pkm_stat_spc[i] = floor(sqrt(std::max(0,rental_pkm_ev_spc[i]-1))+1);
                rental_pkm_stat_spc[i] = floor(std::min(quint16(255),rental_pkm_stat_spc[i])/4);
                rental_pkm_stat_spc[i] = floor((((pkm_base_spc[rental_pkm_id[i]] + rental_pkm_iv_spc[i])*2 + rental_pkm_stat_spc[i]) * rental_pkm_level[i] / 100) + 5);

                // Write to ROM
                rom_offset = 0x898004 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                write<<rental_pkm_id[i];

                rom_offset = 0x898006 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                write<<rental_pkm_stat_hp[i];
                write<<rental_pkm_level[i];

                rom_offset = 0x89800D + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                write<<rental_pkm_move_1[i];
                write<<rental_pkm_move_2[i];
                write<<rental_pkm_move_3[i];
                write<<rental_pkm_move_4[i];

                rom_offset = 0x898014 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                write<<rental_pkm_experience[i];
                write<<rental_pkm_ev_hp[i];
                write<<rental_pkm_ev_atk[i];
                write<<rental_pkm_ev_def[i];
                write<<rental_pkm_ev_speed[i];
                write<<rental_pkm_ev_spc[i];

                rental_pkm_ivs[i] = rental_pkm_iv_atk[i] << 12;
                rental_pkm_ivs[i] += rental_pkm_iv_def[i] << 8;
                rental_pkm_ivs[i] += rental_pkm_iv_speed[i] << 4;
                rental_pkm_ivs[i] += rental_pkm_iv_spc[i];
                write<<rental_pkm_ivs[i];

                // Moves PPs
                if(move_pp[rental_pkm_move_1[i]] > 0){
                    rental_pkm_pp_1[i] = move_pp[rental_pkm_move_1[i]];
                    rental_pkm_pp_1[i] &= 0x3F;
                }
                if(move_pp[rental_pkm_move_2[i]] > 0){
                    rental_pkm_pp_2[i] = move_pp[rental_pkm_move_2[i]];
                    rental_pkm_pp_2[i] &= 0x3F;
                }
                if(move_pp[rental_pkm_move_3[i]] > 0){
                    rental_pkm_pp_3[i] = move_pp[rental_pkm_move_3[i]];
                    rental_pkm_pp_3[i] &= 0x3F;
                }
                if(move_pp[rental_pkm_move_4[i]] > 0){
                    rental_pkm_pp_4[i] = move_pp[rental_pkm_move_4[i]];
                    rental_pkm_pp_4[i] &= 0x3F;
                }
                if(rental_pkm_ppup_1[i] > 0){
                    rental_pkm_pp_1[i] += (move_pp[rental_pkm_move_1[i]]*rental_pkm_ppup_1[i]) / 5;
                    rental_pkm_pp_1[i] += rental_pkm_ppup_1[i] << 6;
                }
                if(rental_pkm_ppup_2[i] > 0){
                    rental_pkm_pp_2[i] += (move_pp[rental_pkm_move_2[i]]*rental_pkm_ppup_2[i]) / 5;
                    rental_pkm_pp_2[i] += rental_pkm_ppup_2[i] << 6;
                }
                if(rental_pkm_ppup_3[i] > 0){
                    rental_pkm_pp_3[i] += (move_pp[rental_pkm_move_3[i]]*rental_pkm_ppup_3[i]) / 5;
                    rental_pkm_pp_3[i] += rental_pkm_ppup_3[i] << 6;
                }
                if(rental_pkm_ppup_4[i] > 0){
                    rental_pkm_pp_4[i] += (move_pp[rental_pkm_move_4[i]]*rental_pkm_ppup_4[i]) / 5;
                    rental_pkm_pp_4[i] += rental_pkm_ppup_4[i] << 6;
                }
                write<<rental_pkm_pp_1[i];
                write<<rental_pkm_pp_2[i];
                write<<rental_pkm_pp_3[i];
                write<<rental_pkm_pp_4[i];

                write<<rental_pkm_level[i];

                rom_offset = 0x89802A + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                write<<rental_pkm_stat_hp[i];
                write<<rental_pkm_stat_atk[i];
                write<<rental_pkm_stat_def[i];
                write<<rental_pkm_stat_speed[i];
                write<<rental_pkm_stat_spc[i];

                rom_offset = 0x898034 + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                if(rental_pkm_nickname[i].length()<11){
                    for(short k=0;k<rental_pkm_nickname[i].length();k++){
                        if(rental_pkm_nickname[i].at(k).toLatin1()>0x1F && rental_pkm_nickname[i].at(k).toLatin1()<0x7B){
                            buf8=rental_pkm_nickname[i].at(k).toLatin1();
                        }
                        else if(rental_pkm_nickname[i].at(k) == char_table[0xA9]){
                            buf8=0xA9;
                        }
                        else if(rental_pkm_nickname[i].at(k) == char_table[0xBE]){
                            buf8=0xBE;
                        }
                        else if(rental_pkm_nickname[i].at(k) == char_table[0xE9]){
                            buf8=0xE9;
                        }
                        else{
                            buf8=0x20;
                        }
                        write<<buf8;
                    }
                    buf8=0;
                    for(short k=0;k<(11-rental_pkm_nickname[i].length());k++){
                        write<<buf8;
                    }
                }
                else{
                    buf8=0x46;
                    write<<buf8;
                    buf8=0x61;
                    write<<buf8;
                    buf8=0x69;
                    write<<buf8;
                    buf8=0x6C;
                    write<<buf8;
                    buf8=0x2D;
                    write<<buf8;
                    buf8=0x53;
                    write<<buf8;
                    buf8=0x61;
                    write<<buf8;
                    buf8=0x66;
                    write<<buf8;
                    buf8=0x65;
                    write<<buf8;
                    buf8=0;
                    write<<buf8;
                    write<<buf8;
                }
            }
            current_rentals_number += total_cpu_rentals;
        }
        // CPU Pokémon
        else{
            for(short i=current_cpu_trainers_number;i<(total_cpu_rentals+current_cpu_trainers_number);i++){
                cpu_cup_id[i] = current_cpu_trainers_cup;

                // CPU Trainer name
                rom_offset = 0x898004 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                for(short l=0;l<2;l++){
                    if(cpu_tname[i].length()<11){
                        for(short k=0;k<cpu_tname[i].length();k++){
                            if(cpu_tname[i].at(k).toLatin1()>0x1F && cpu_tname[i].at(k).toLatin1()<0x7B){
                                buf8=cpu_tname[i].at(k).toLatin1();
                            }
                            else if(cpu_tname[i].at(k) == char_table[0xA9]){
                                buf8=0xA9;
                            }
                            else if(cpu_tname[i].at(k) == char_table[0xBE]){
                                buf8=0xBE;
                            }
                            else if(cpu_tname[i].at(k) == char_table[0xE9]){
                                buf8=0xE9;
                            }
                            else{
                                buf8=0x20;
                            }
                            write<<buf8;
                        }
                        buf8=0;
                        for(short k=0;k<(11-cpu_tname[i].length());k++){
                            write<<buf8;
                        }
                    }
                    else{
                        buf8=0x46;
                        write<<buf8;
                        buf8=0x61;
                        write<<buf8;
                        buf8=0x69;
                        write<<buf8;
                        buf8=0x6C;
                        write<<buf8;
                        buf8=0x2D;
                        write<<buf8;
                        buf8=0x53;
                        write<<buf8;
                        buf8=0x61;
                        write<<buf8;
                        buf8=0x66;
                        write<<buf8;
                        buf8=0x65;
                        write<<buf8;
                        buf8=0;
                        write<<buf8;
                        write<<buf8;
                    }
                    rom_offset = 0x898010 + (i-current_cpu_trainers_number)*560 + *set_iter;
                    romfile.seek(rom_offset);
                }

                // CPU Trainer sprite
                rom_offset = 0x898038 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                write<<cpu_sprite_id[i];

                // CPU AI id
                write<<cpu_ai_id[i];

                // CPU Trainer party size
                rom_offset = 0x89803B + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                write<<cpu_party_size[i];

                // CPU Trainer Pokémon data
                for(short j=0;j<6;j++){
                    // Stats calculation
                    // Stat Exp : E = floor(min(255, floor(√(max(0, Stat Experience - 1)) + 1)) / 4)
                    // HP       : (((Base + IV) * 2 + E) * Level) / 100 + Level + 10
                    // Stats    : (((Base + IV) * 2 + E) * Level) / 100 + 5
                    cpu_pkm_stat_hp[i][j] = floor(sqrt(std::max(0,cpu_pkm_ev_hp[i][j]-1))+1);
                    cpu_pkm_stat_hp[i][j] = floor(std::min(quint16(255),cpu_pkm_stat_hp[i][j])/4);
                    cpu_pkm_stat_hp[i][j] = floor((((pkm_base_hp[cpu_pkm_id[i][j]] + cpu_pkm_iv_hp[i][j])*2 + cpu_pkm_stat_hp[i][j]) * cpu_pkm_level[i][j] / 100) + cpu_pkm_level[i][j]+10);
                    cpu_pkm_stat_atk[i][j] = floor(sqrt(std::max(0,cpu_pkm_ev_atk[i][j]-1))+1);
                    cpu_pkm_stat_atk[i][j] = floor(std::min(quint16(255),cpu_pkm_stat_atk[i][j])/4);
                    cpu_pkm_stat_atk[i][j] = floor((((pkm_base_atk[cpu_pkm_id[i][j]] + cpu_pkm_iv_atk[i][j])*2 + cpu_pkm_stat_atk[i][j]) * cpu_pkm_level[i][j] / 100) + 5);
                    cpu_pkm_stat_def[i][j] = floor(sqrt(std::max(0,cpu_pkm_ev_def[i][j]-1))+1);
                    cpu_pkm_stat_def[i][j] = floor(std::min(quint16(255),cpu_pkm_stat_def[i][j])/4);
                    cpu_pkm_stat_def[i][j] = floor((((pkm_base_def[cpu_pkm_id[i][j]] + cpu_pkm_iv_def[i][j])*2 + cpu_pkm_stat_def[i][j]) * cpu_pkm_level[i][j] / 100) + 5);
                    cpu_pkm_stat_speed[i][j] = floor(sqrt(std::max(0,cpu_pkm_ev_speed[i][j]-1))+1);
                    cpu_pkm_stat_speed[i][j] = floor(std::min(quint16(255),cpu_pkm_stat_speed[i][j])/4);
                    cpu_pkm_stat_speed[i][j] = floor((((pkm_base_speed[cpu_pkm_id[i][j]] + cpu_pkm_iv_speed[i][j])*2 + cpu_pkm_stat_speed[i][j]) * cpu_pkm_level[i][j] / 100) + 5);
                    cpu_pkm_stat_spc[i][j] = floor(sqrt(std::max(0,cpu_pkm_ev_spc[i][j]-1))+1);
                    cpu_pkm_stat_spc[i][j] = floor(std::min(quint16(255),cpu_pkm_stat_spc[i][j])/4);
                    cpu_pkm_stat_spc[i][j] = floor((((pkm_base_spc[cpu_pkm_id[i][j]] + cpu_pkm_iv_spc[i][j])*2 + cpu_pkm_stat_spc[i][j]) * cpu_pkm_level[i][j] / 100) + 5);

                    // Write to ROM
                    rom_offset = 0x89803C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_pkm_id[i][j];

                    rom_offset = 0x89803E + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_pkm_stat_hp[i][j];
                    write<<cpu_pkm_level[i][j];

                    rom_offset = 0x898045 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_pkm_move_1[i][j];
                    write<<cpu_pkm_move_2[i][j];
                    write<<cpu_pkm_move_3[i][j];
                    write<<cpu_pkm_move_4[i][j];

                    rom_offset = 0x89804C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_pkm_experience[i][j];
                    write<<cpu_pkm_ev_hp[i][j];
                    write<<cpu_pkm_ev_atk[i][j];
                    write<<cpu_pkm_ev_def[i][j];
                    write<<cpu_pkm_ev_speed[i][j];
                    write<<cpu_pkm_ev_spc[i][j];

                    cpu_pkm_ivs[i][j] = cpu_pkm_iv_atk[i][j] << 12;
                    cpu_pkm_ivs[i][j] += cpu_pkm_iv_def[i][j] << 8;
                    cpu_pkm_ivs[i][j] += cpu_pkm_iv_speed[i][j] << 4;
                    cpu_pkm_ivs[i][j] += cpu_pkm_iv_spc[i][j];
                    write<<cpu_pkm_ivs[i][j];

                    // CPU Moves PPs
                    if(move_pp[cpu_pkm_move_1[i][j]] > 0){
                        cpu_pkm_pp_1[i][j] = move_pp[cpu_pkm_move_1[i][j]];
                        cpu_pkm_pp_1[i][j] &= 0x3F;
                    }
                    if(move_pp[cpu_pkm_move_2[i][j]] > 0){
                        cpu_pkm_pp_2[i][j] = move_pp[cpu_pkm_move_2[i][j]];
                        cpu_pkm_pp_2[i][j] &= 0x3F;
                    }
                    if(move_pp[cpu_pkm_move_3[i][j]] > 0){
                        cpu_pkm_pp_3[i][j] = move_pp[cpu_pkm_move_3[i][j]];
                        cpu_pkm_pp_3[i][j] &= 0x3F;
                    }
                    if(move_pp[cpu_pkm_move_4[i][j]] > 0){
                        cpu_pkm_pp_4[i][j] = move_pp[cpu_pkm_move_4[i][j]];
                        cpu_pkm_pp_4[i][j] &= 0x3F;
                    }
                    if(cpu_pkm_ppup_1[i][j] > 0){
                        cpu_pkm_pp_1[i][j] += (move_pp[cpu_pkm_move_1[i][j]]*cpu_pkm_ppup_1[i][j]) / 5;
                        cpu_pkm_pp_1[i][j] += cpu_pkm_ppup_1[i][j] << 6;
                    }
                    if(cpu_pkm_ppup_2[i][j] > 0){
                        cpu_pkm_pp_2[i][j] += (move_pp[cpu_pkm_move_2[i][j]]*cpu_pkm_ppup_2[i][j]) / 5;
                        cpu_pkm_pp_2[i][j] += cpu_pkm_ppup_2[i][j] << 6;
                    }
                    if(cpu_pkm_ppup_3[i][j] > 0){
                        cpu_pkm_pp_3[i][j] += (move_pp[cpu_pkm_move_3[i][j]]*cpu_pkm_ppup_3[i][j]) / 5;
                        cpu_pkm_pp_3[i][j] += cpu_pkm_ppup_3[i][j] << 6;
                    }
                    if(cpu_pkm_ppup_4[i][j] > 0){
                        cpu_pkm_pp_4[i][j] += (move_pp[cpu_pkm_move_4[i][j]]*cpu_pkm_ppup_4[i][j]) / 5;
                        cpu_pkm_pp_4[i][j] += cpu_pkm_ppup_4[i][j] << 6;
                    }
                    write<<cpu_pkm_pp_1[i][j];
                    write<<cpu_pkm_pp_2[i][j];
                    write<<cpu_pkm_pp_3[i][j];
                    write<<cpu_pkm_pp_4[i][j];

                    write<<cpu_pkm_level[i][j];

                    rom_offset = 0x898062 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_pkm_stat_hp[i][j];
                    write<<cpu_pkm_stat_atk[i][j];
                    write<<cpu_pkm_stat_def[i][j];
                    write<<cpu_pkm_stat_speed[i][j];
                    write<<cpu_pkm_stat_spc[i][j];

                    // CPU Trainer Pokémon nickname
                    rom_offset = 0x89806C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    if(cpu_pkm_nickname[i][j].length()<11){
                        for(short k=0;k<cpu_pkm_nickname[i][j].length();k++){
                            if(cpu_pkm_nickname[i][j].at(k).toLatin1()>0x1F && cpu_pkm_nickname[i][j].at(k).toLatin1()<0x7B){
                                buf8=cpu_pkm_nickname[i][j].at(k).toLatin1();
                            }
                            else if(cpu_pkm_nickname[i][j].at(k) == char_table[0xA9]){
                                buf8=0xA9;
                            }
                            else if(cpu_pkm_nickname[i][j].at(k) == char_table[0xBE]){
                                buf8=0xBE;
                            }
                            else if(cpu_pkm_nickname[i][j].at(k) == char_table[0xE9]){
                                buf8=0xE9;
                            }
                            else{
                                buf8=0x20;
                            }
                            write<<buf8;
                        }
                        buf8=0;
                        for(short k=0;k<(11-cpu_pkm_nickname[i][j].length());k++){
                            write<<buf8;
                        }
                    }
                    else{
                        buf8=0x46;
                        write<<buf8;
                        buf8=0x61;
                        write<<buf8;
                        buf8=0x69;
                        write<<buf8;
                        buf8=0x6C;
                        write<<buf8;
                        buf8=0x2D;
                        write<<buf8;
                        buf8=0x53;
                        write<<buf8;
                        buf8=0x61;
                        write<<buf8;
                        buf8=0x66;
                        write<<buf8;
                        buf8=0x65;
                        write<<buf8;
                        buf8=0;
                        write<<buf8;
                        write<<buf8;
                    }
                }
            }
            current_cpu_trainers_cup++;
            current_cpu_trainers_number += total_cpu_rentals;
            cpu_cup_offset[current_cpu_trainers_cup] = current_cpu_trainers_number;
        }
    }
}