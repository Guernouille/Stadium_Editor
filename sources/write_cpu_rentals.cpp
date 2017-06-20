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

    for(short i = 0; i < total_cpu_rentals_array; i++){
        rom_offset = 0x898010 + i*16;
        romfile.seek(rom_offset);
        write>>cpu_rentals_pointer[i];
        cpu_rentals_pointers.insert(cpu_rentals_pointer[i]);
    }

    current_rentals_number = 0;
    current_cpu_trainers_cup = 0;
    current_cpu_trainers_number = 0;

    std::set<int>::const_iterator set_iter(cpu_rentals_pointers.begin()), set_end(cpu_rentals_pointers.end());

    for(; set_iter!=set_end; ++set_iter){
        rom_offset = 0x898003 + *set_iter;
        romfile.seek(rom_offset);
        write>>total_cpu_rentals;

        // Rental Pokémon
        if(total_cpu_rentals > 16){
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

                rom_offset = 0x89800A + (i-current_rentals_number)*84 + *set_iter;
                romfile.seek(rom_offset);
                if(pkm_type_1[i]>8) pkm_type_1[i] += 11;
                if(pkm_type_2[i]>8) pkm_type_2[i] += 11;
                write<<pkm_type_1[rental_pkm_id[i]];
                write<<pkm_type_2[rental_pkm_id[i]];
                if(pkm_type_1[i]>19) pkm_type_1[i] -= 11;
                if(pkm_type_2[i]>19) pkm_type_2[i] -= 11;

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
                if(rental_pkm_nickname[i].size()<11){
                    for(short k=0;k<rental_pkm_nickname[i].length();k++){
                        buf8 = control_char_table(rental_pkm_nickname[i].at(k));
                        if(buf8 > 253) buf8=0x20;
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
                cpu_trainers[i].cup_id = current_cpu_trainers_cup;

                // CPU Trainer name
                for(uint8_t l = 0; l < 2; l++) {
                    if(cpu_trainers[i].name.length() < 1 || cpu_trainers[i].name.size() > 11) cpu_trainers[i].name = "Fail-Safe";

                    for(uint8_t k = 0; k < cpu_trainers[i].name.size(); k++){
                        buf8 = control_char_table(cpu_trainers[i].name.at(k));
                        if(buf8 > 253) buf8 = 0x20;

                        rom_offset = 0x898004 + (i-current_cpu_trainers_number)*560 + k + *set_iter;
                        romfile.seek(rom_offset);
                        write<<buf8;

                        rom_offset = 0x898010 + (i-current_cpu_trainers_number)*560 + k + *set_iter;
                        romfile.seek(rom_offset);
                        write<<buf8;

                        for(uint8_t pkt = 0; pkt < 6; pkt++) {
                            buf16 = pkt * 0x54;
                            buf16 += k;
                            rom_offset = 0x898077 + (i-current_cpu_trainers_number)*560 + buf16 + *set_iter;
                            romfile.seek(rom_offset);
                            write<<buf8;
                        }
                    }

                    // Fill remaining characters with 00s
                    buf8=0;

                    for(short k = 0; k < (11-cpu_trainers[i].name.size()); k++){
                        buf16 = cpu_trainers[i].name.size() + k;
                        rom_offset = 0x898004 + (i-current_cpu_trainers_number)*560 + buf16 + *set_iter;
                        romfile.seek(rom_offset);
                        write<<buf8;

                        rom_offset = 0x898010 + (i-current_cpu_trainers_number)*560 + buf16 + *set_iter;
                        romfile.seek(rom_offset);
                        write<<buf8;
                    }
                }

                // CPU Trainer sprite
                rom_offset = 0x898038 + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                write<<cpu_trainers[i].sprite_id;

                // CPU AI id
                write<<cpu_trainers[i].ai_id;

                // CPU Trainer party size
                rom_offset = 0x89803B + (i-current_cpu_trainers_number)*560 + *set_iter;
                romfile.seek(rom_offset);
                write<<cpu_trainers[i].party_size;

                // CPU Trainer Pokémon data
                for(short j=0;j<6;j++){
                    // Stats calculation
                    // Stat Exp : E = floor(min(255, floor(√(max(0, Stat Experience - 1)) + 1)) / 4)
                    // HP       : (((Base + IV) * 2 + E) * Level) / 100 + Level + 10
                    // Stats    : (((Base + IV) * 2 + E) * Level) / 100 + 5
                    cpu_trainers[i].pkm[j].hp_stat = floor(sqrt(std::max(0,cpu_trainers[i].pkm[j].hp_ev-1))+1);
                    cpu_trainers[i].pkm[j].hp_stat = floor(std::min(quint16(255),cpu_trainers[i].pkm[j].hp_stat)/4);
                    cpu_trainers[i].pkm[j].hp_stat = floor((((pkm_base_hp[cpu_trainers[i].pkm[j].id] + cpu_trainers[i].pkm[j].hp_iv)*2 + cpu_trainers[i].pkm[j].hp_stat) * cpu_trainers[i].pkm[j].lvl / 100) + cpu_trainers[i].pkm[j].lvl+10);
                    cpu_trainers[i].pkm[j].atk_stat = floor(sqrt(std::max(0,cpu_trainers[i].pkm[j].atk_ev-1))+1);
                    cpu_trainers[i].pkm[j].atk_stat = floor(std::min(quint16(255),cpu_trainers[i].pkm[j].atk_stat)/4);
                    cpu_trainers[i].pkm[j].atk_stat = floor((((pkm_base_atk[cpu_trainers[i].pkm[j].id] + cpu_trainers[i].pkm[j].atk_iv)*2 + cpu_trainers[i].pkm[j].atk_stat) * cpu_trainers[i].pkm[j].lvl / 100) + 5);
                    cpu_trainers[i].pkm[j].def_stat = floor(sqrt(std::max(0,cpu_trainers[i].pkm[j].def_ev-1))+1);
                    cpu_trainers[i].pkm[j].def_stat = floor(std::min(quint16(255),cpu_trainers[i].pkm[j].def_stat)/4);
                    cpu_trainers[i].pkm[j].def_stat = floor((((pkm_base_def[cpu_trainers[i].pkm[j].id] + cpu_trainers[i].pkm[j].def_iv)*2 + cpu_trainers[i].pkm[j].def_stat) * cpu_trainers[i].pkm[j].lvl / 100) + 5);
                    cpu_trainers[i].pkm[j].speed_stat = floor(sqrt(std::max(0,cpu_trainers[i].pkm[j].speed_ev-1))+1);
                    cpu_trainers[i].pkm[j].speed_stat = floor(std::min(quint16(255),cpu_trainers[i].pkm[j].speed_stat)/4);
                    cpu_trainers[i].pkm[j].speed_stat = floor((((pkm_base_speed[cpu_trainers[i].pkm[j].id] + cpu_trainers[i].pkm[j].speed_iv)*2 + cpu_trainers[i].pkm[j].speed_stat) * cpu_trainers[i].pkm[j].lvl / 100) + 5);
                    cpu_trainers[i].pkm[j].spc_stat = floor(sqrt(std::max(0,cpu_trainers[i].pkm[j].spc_ev-1))+1);
                    cpu_trainers[i].pkm[j].spc_stat = floor(std::min(quint16(255),cpu_trainers[i].pkm[j].spc_stat)/4);
                    cpu_trainers[i].pkm[j].spc_stat = floor((((pkm_base_spc[cpu_trainers[i].pkm[j].id] + cpu_trainers[i].pkm[j].spc_iv)*2 + cpu_trainers[i].pkm[j].spc_stat) * cpu_trainers[i].pkm[j].lvl / 100) + 5);

                    // Write to ROM
                    rom_offset = 0x89803C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_trainers[i].pkm[j].id;

                    rom_offset = 0x89803E + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_trainers[i].pkm[j].hp_stat;
                    write<<cpu_trainers[i].pkm[j].lvl;

                    rom_offset = 0x898045 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_trainers[i].pkm[j].move_1;
                    write<<cpu_trainers[i].pkm[j].move_2;
                    write<<cpu_trainers[i].pkm[j].move_3;
                    write<<cpu_trainers[i].pkm[j].move_4;

                    rom_offset = 0x89804C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_trainers[i].pkm[j].exp;
                    write<<cpu_trainers[i].pkm[j].hp_ev;
                    write<<cpu_trainers[i].pkm[j].atk_ev;
                    write<<cpu_trainers[i].pkm[j].def_ev;
                    write<<cpu_trainers[i].pkm[j].speed_ev;
                    write<<cpu_trainers[i].pkm[j].spc_ev;

                    cpu_trainers[i].pkm[j].ivs = cpu_trainers[i].pkm[j].atk_iv << 12;
                    cpu_trainers[i].pkm[j].ivs += cpu_trainers[i].pkm[j].def_iv << 8;
                    cpu_trainers[i].pkm[j].ivs += cpu_trainers[i].pkm[j].speed_iv << 4;
                    cpu_trainers[i].pkm[j].ivs += cpu_trainers[i].pkm[j].spc_iv;
                    write<<cpu_trainers[i].pkm[j].ivs;

                    // CPU Moves PPs
                    if(move_pp[cpu_trainers[i].pkm[j].move_1] > 0){
                        cpu_trainers[i].pkm[j].pp_1 = move_pp[cpu_trainers[i].pkm[j].move_1];
                        cpu_trainers[i].pkm[j].pp_1 &= 0x3F;
                    }
                    if(move_pp[cpu_trainers[i].pkm[j].move_2] > 0){
                        cpu_trainers[i].pkm[j].pp_2 = move_pp[cpu_trainers[i].pkm[j].move_2];
                        cpu_trainers[i].pkm[j].pp_2 &= 0x3F;
                    }
                    if(move_pp[cpu_trainers[i].pkm[j].move_3] > 0){
                        cpu_trainers[i].pkm[j].pp_3 = move_pp[cpu_trainers[i].pkm[j].move_3];
                        cpu_trainers[i].pkm[j].pp_3 &= 0x3F;
                    }
                    if(move_pp[cpu_trainers[i].pkm[j].move_4] > 0){
                        cpu_trainers[i].pkm[j].pp_4 = move_pp[cpu_trainers[i].pkm[j].move_4];
                        cpu_trainers[i].pkm[j].pp_4 &= 0x3F;
                    }
                    if(cpu_trainers[i].pkm[j].ppup_1 > 0){
                        cpu_trainers[i].pkm[j].pp_1 += (move_pp[cpu_trainers[i].pkm[j].move_1]*cpu_trainers[i].pkm[j].ppup_1) / 5;
                        cpu_trainers[i].pkm[j].pp_1 += cpu_trainers[i].pkm[j].ppup_1 << 6;
                    }
                    if(cpu_trainers[i].pkm[j].ppup_2 > 0){
                        cpu_trainers[i].pkm[j].pp_2 += (move_pp[cpu_trainers[i].pkm[j].move_2]*cpu_trainers[i].pkm[j].ppup_2) / 5;
                        cpu_trainers[i].pkm[j].pp_2 += cpu_trainers[i].pkm[j].ppup_2 << 6;
                    }
                    if(cpu_trainers[i].pkm[j].ppup_3 > 0){
                        cpu_trainers[i].pkm[j].pp_3 += (move_pp[cpu_trainers[i].pkm[j].move_3]*cpu_trainers[i].pkm[j].ppup_3) / 5;
                        cpu_trainers[i].pkm[j].pp_3 += cpu_trainers[i].pkm[j].ppup_3 << 6;
                    }
                    if(cpu_trainers[i].pkm[j].ppup_4 > 0){
                        cpu_trainers[i].pkm[j].pp_4 += (move_pp[cpu_trainers[i].pkm[j].move_4]*cpu_trainers[i].pkm[j].ppup_4) / 5;
                        cpu_trainers[i].pkm[j].pp_4 += cpu_trainers[i].pkm[j].ppup_4 << 6;
                    }
                    write<<cpu_trainers[i].pkm[j].pp_1;
                    write<<cpu_trainers[i].pkm[j].pp_2;
                    write<<cpu_trainers[i].pkm[j].pp_3;
                    write<<cpu_trainers[i].pkm[j].pp_4;

                    write<<cpu_trainers[i].pkm[j].lvl;

                    rom_offset = 0x898062 + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);
                    write<<cpu_trainers[i].pkm[j].hp_stat;
                    write<<cpu_trainers[i].pkm[j].atk_stat;
                    write<<cpu_trainers[i].pkm[j].def_stat;
                    write<<cpu_trainers[i].pkm[j].speed_stat;
                    write<<cpu_trainers[i].pkm[j].spc_stat;

                    // CPU Trainer Pokémon nickname
                    rom_offset = 0x89806C + (i-current_cpu_trainers_number)*560 + j*84 + *set_iter;
                    romfile.seek(rom_offset);

                    if(cpu_trainers[i].pkm[j].nick.length()<11){
                        for(short k = 0; k < cpu_trainers[i].pkm[j].nick.size(); k++){
                            buf8 = control_char_table(cpu_trainers[i].pkm[j].nick.at(k));
                            if(buf8 > 253) buf8=0x20;
                            write<<buf8;
                        }
                        buf8=0;
                        for(short k = 0; k < (11-cpu_trainers[i].pkm[j].nick.size()); k++){
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
