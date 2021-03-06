#include "mainwindow.h"
#include "rental_pkm.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_rental_init_pkmn(){
    bool no_mew_mewtwo = ui->checkBox_Randomizer_Rental_NoMewMewtwo->isChecked();
    bool no_useless_pokemon = ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();
    bool randomized_base_stats = ui->checkBox_Randomize_PkmnData_BS->isChecked();

    pkm_ids_vector_rental_petitcup.clear();
    pkm_ids_vector_rental_pikacup.clear();
    pkm_ids_vector_rental_primecup.clear();
    pkm_ids_vector_rental_pokecup.clear();

    // Petit Cup
    short pkm_list_petitcup[] = {1,4,7,16,19,21,23,25,27,32,35,37,39,43,46,50,52,54,58,60,63,66,69,74,81,83,90,92,98,100,102,104,109,116,118,133,138,140,147};
    pkm_ids_vector_rental_petitcup.assign(pkm_list_petitcup,pkm_list_petitcup+(sizeof(pkm_list_petitcup)/sizeof(*pkm_list_petitcup)));
    if(no_useless_pokemon == false || (randomized_pkm_data && randomized_base_stats)){
        pkm_ids_vector_rental_petitcup.push_back(10);
        pkm_ids_vector_rental_petitcup.push_back(13);
        pkm_ids_vector_rental_petitcup.push_back(29);
        pkm_ids_vector_rental_petitcup.push_back(41);
        pkm_ids_vector_rental_petitcup.push_back(129);
        pkm_ids_vector_rental_petitcup.push_back(132);
    }


    // Pika Cup
    if(ui->checkBox_Randomizer_Rental_FullyEvolved->isChecked()){
        short pkm_list_pikacup[] = {2,5,8,12,15,17,20,22,26,31,34,36,38,40,47,51,55,59,62,65,68,73,76,80,87,89,91,94,95,99,101,103,106,107,108,112,113,114,115,117,121,122,123,124,127,130,131,137,148};
        pkm_ids_vector_rental_pikacup.assign(pkm_list_pikacup,pkm_list_pikacup+(sizeof(pkm_list_pikacup)/sizeof(*pkm_list_pikacup)));
        if(no_useless_pokemon == false){
            pkm_ids_vector_rental_pikacup.push_back(83);
            pkm_ids_vector_rental_pikacup.push_back(132);
        }
        if(no_mew_mewtwo==false){
            pkm_ids_vector_rental_pikacup.push_back(151);
        }
    }
    else{
        if(no_mew_mewtwo){
            for(short i=1;i<=total_pkm_name;i++){
                if(i!=10 && i!=11 && i!=13 && i!=14 && i!=29 && i!=41 && i!=43 && i!=48 && i!=83 && i!=129 && i!=132 && i!=150 && i!=151){
                    if(pkm_min_level[i]<=20) pkm_ids_vector_rental_pikacup.push_back(i);
                }
            }
        }
        else{
            for(short i=1;i<=total_pkm_name;i++){
                if(i!=10 && i!=11 && i!=13 && i!=14 && i!=29 && i!=41 && i!=43 && i!=48 && i!=83 && i!=129 && i!=132){
                    if(pkm_min_level[i]<=20) pkm_ids_vector_rental_pikacup.push_back(i);
                }
            }
        }
        if(no_useless_pokemon == false){
            pkm_ids_vector_rental_pikacup.push_back(10);
            pkm_ids_vector_rental_pikacup.push_back(11);
            pkm_ids_vector_rental_pikacup.push_back(13);
            pkm_ids_vector_rental_pikacup.push_back(14);
            pkm_ids_vector_rental_pikacup.push_back(29);
            pkm_ids_vector_rental_pikacup.push_back(41);
            pkm_ids_vector_rental_pikacup.push_back(43);
            pkm_ids_vector_rental_pikacup.push_back(48);
            pkm_ids_vector_rental_pikacup.push_back(83);
            pkm_ids_vector_rental_pikacup.push_back(129);
            pkm_ids_vector_rental_pikacup.push_back(132);
        }
    }


    // Prime Cup
    if(ui->checkBox_Randomizer_Rental_FullyEvolved->isChecked()){
        short pkm_list_primecup[] = {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_rental_primecup.assign(pkm_list_primecup,pkm_list_primecup+(sizeof(pkm_list_primecup)/sizeof(*pkm_list_primecup)));
        if(no_useless_pokemon == false){
            pkm_ids_vector_rental_primecup.push_back(83);
            pkm_ids_vector_rental_primecup.push_back(132);
        }
        pkm_ids_vector_rental_primecup.push_back(150);
        pkm_ids_vector_rental_primecup.push_back(151);
    }
    else if(no_useless_pokemon == false){
        for(short i=1;i<=(total_pkm_name);i++){
            if(i!=10 && i!=11 && i!=13 && i!=14 && i!=29 && i!=41 && i!=48 && i!=129 && i!=132){
                pkm_ids_vector_rental_primecup.push_back(i);
            }
        }
    }
    else{
        for(short i=1;i<=(total_pkm_name);i++){
            pkm_ids_vector_rental_primecup.push_back(i);
        }
    }
    if(no_mew_mewtwo){
        pkm_ids_vector_rental_primecup.pop_back();
        pkm_ids_vector_rental_primecup.pop_back();
    }


    // Poké Cup
    if(ui->checkBox_Randomizer_Rental_FullyEvolved->isChecked()){
        short pkm_list_pokecup[] = {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_rental_pokecup.assign(pkm_list_pokecup,pkm_list_pokecup+(sizeof(pkm_list_pokecup)/sizeof(*pkm_list_pokecup)));
        if(no_useless_pokemon == false){
            pkm_ids_vector_rental_pokecup.push_back(83);
            pkm_ids_vector_rental_pokecup.push_back(132);
        }
    }
    else if(no_useless_pokemon == false){
        for(short i=1;i<=(total_pkm_name);i++){
            if(i!=10 && i!=11 && i!=13 && i!=14 && i!=29 && i!=41 && i!=48 && i!=129 && i!=132 && i!=150 && i!=151){
                pkm_ids_vector_rental_pokecup.push_back(i);
            }
        }
    }
    else{
        for(short i=1;i<=total_pkm_name;i++){
            if(pkm_min_level[i]<=55 && i!=150 && i!=151) pkm_ids_vector_rental_pokecup.push_back(i);
        }
    }
}


void MainWindow::randomize_rental_iv_stat_exp(std::mt19937 &mt_rand)
{
    // TO DO: Petit Cup ; Optimize this
    std::uniform_int_distribution<> rand_iv_1(std::max(rental_ivs_min,std::min(quint8(11),rental_ivs_max)),(rental_ivs_max+3));
    std::uniform_int_distribution<> rand_iv_2(std::max(rental_ivs_min,std::min(quint8(9),rental_ivs_max)),(rental_ivs_max+1));
    std::uniform_int_distribution<> rand_iv_3(std::max(rental_ivs_min,std::min(quint8(7),rental_ivs_max)),(rental_ivs_max));
    std::uniform_int_distribution<> rand_iv_4(std::max(rental_ivs_min,std::min(quint8(3),rental_ivs_max)),(rental_ivs_max));
    std::uniform_int_distribution<> rand_iv_5(rental_ivs_min,rental_ivs_max);
    if(rental_ivs_max>=2) buf32 = std::max(quint8(rental_ivs_max-2),rental_ivs_min);
    else buf32 = rental_ivs_max;
    std::uniform_int_distribution<> rand_iv_6(rental_ivs_min,buf32);

    std::uniform_int_distribution<> rand_stat_exp_1(std::max(rental_stat_exp_min,std::min(quint16(44444),rental_stat_exp_max)),65535);
    std::uniform_int_distribution<> rand_stat_exp_2(std::max(rental_stat_exp_min,std::min(quint16(33792),rental_stat_exp_max)),(rental_stat_exp_max+12288));
    std::uniform_int_distribution<> rand_stat_exp_3(std::max(rental_stat_exp_min,std::min(quint16(25600),rental_stat_exp_max)),rental_stat_exp_max);
    if(rental_stat_exp_max>=1152) buf32 = std::max(quint16(rental_stat_exp_max-1152),rental_stat_exp_min);
    else buf32 = rental_stat_exp_max;
    std::uniform_int_distribution<> rand_stat_exp_4(std::max(rental_stat_exp_min,std::min(quint16(14400),rental_stat_exp_max)),buf32);
    if(rental_stat_exp_max>=1408) buf32 = std::max(quint16(rental_stat_exp_max-1408),rental_stat_exp_min);
    else buf32 = rental_stat_exp_max;
    std::uniform_int_distribution<> rand_stat_exp_5(std::max(rental_stat_exp_min,std::min(quint16(6400),rental_stat_exp_max)),buf32);
    std::uniform_int_distribution<> rand_stat_exp_6(rental_stat_exp_min,buf32);
    std::uniform_int_distribution<> rand_stat_exp_default(rental_stat_exp_min,rental_stat_exp_max);

    bool better_stats_nfe = ui->checkBox_Rental_NFE_IVsEVs->isChecked();

    for(short rental_id=0;rental_id<current_rentals_number;rental_id++){
        if(better_stats_nfe){
            // Petit Cup
            if(rental_id < rental_cup_offset[1]){
                switch(iv_statexp_groups[rental_pkm_id[rental_id]]){
                case 0:
                    rental_pkm_iv_atk[rental_id] = rental_ivs_max;
                    rental_pkm_iv_def[rental_id] = rental_ivs_max;
                    rental_pkm_iv_spc[rental_id] = rental_ivs_max;
                    rental_pkm_iv_speed[rental_id] = rental_ivs_max;

                    rental_pkm_ev_hp[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = rental_stat_exp_max;
                    break;
                default:
                    rental_pkm_iv_atk[rental_id] = rand_iv_5(mt_rand);
                    rental_pkm_iv_def[rental_id] = rand_iv_5(mt_rand);
                    rental_pkm_iv_spc[rental_id] = rand_iv_5(mt_rand);
                    rental_pkm_iv_speed[rental_id] = rand_iv_5(mt_rand);

                    rental_pkm_ev_hp[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_atk[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_def[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_spc[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_speed[rental_id] = rand_stat_exp_6(mt_rand);
                    break;
                }
            }
            // Other Cups
            else{
                switch(iv_statexp_groups[rental_pkm_id[rental_id]]){
                case 0:
                    rental_pkm_iv_atk[rental_id] = rental_ivs_max;
                    rental_pkm_iv_def[rental_id] = rental_ivs_max;
                    rental_pkm_iv_spc[rental_id] = rental_ivs_max;
                    rental_pkm_iv_speed[rental_id] = rental_ivs_max;
                    rental_pkm_ev_hp[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = rental_stat_exp_max;
                    break;

                case 1:
                    rental_pkm_iv_atk[rental_id] = std::min(quint8(rand_iv_1(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_def[rental_id] = std::min(quint8(rand_iv_1(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_spc[rental_id] = std::min(quint8(rand_iv_1(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_speed[rental_id] = std::min(quint8(rand_iv_1(mt_rand)),rental_ivs_max);

                    buf32 = rand_stat_exp_1(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_hp[rental_id] = buf32;

                    buf32 = rand_stat_exp_1(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = buf32;

                    buf32 = rand_stat_exp_1(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = buf32;

                    buf32 = rand_stat_exp_1(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = buf32;

                    buf32 = rand_stat_exp_1(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = buf32;
                    break;

                case 2:
                    rental_pkm_iv_atk[rental_id] = std::min(quint8(rand_iv_2(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_def[rental_id] = std::min(quint8(rand_iv_2(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_spc[rental_id] = std::min(quint8(rand_iv_2(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_speed[rental_id] = std::min(quint8(rand_iv_2(mt_rand)),rental_ivs_max);

                    buf32 = rand_stat_exp_2(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_hp[rental_id] = buf32;

                    buf32 = rand_stat_exp_2(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = buf32;

                    buf32 = rand_stat_exp_2(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = buf32;

                    buf32 = rand_stat_exp_2(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = buf32;

                    buf32 = rand_stat_exp_2(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = buf32;
                    break;

                case 3:
                    rental_pkm_iv_atk[rental_id] = std::min(quint8(rand_iv_3(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_def[rental_id] = std::min(quint8(rand_iv_3(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_spc[rental_id] = std::min(quint8(rand_iv_3(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_speed[rental_id] = std::min(quint8(rand_iv_3(mt_rand)),rental_ivs_max);

                    buf32 = rand_stat_exp_3(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_hp[rental_id] = buf32;

                    buf32 = rand_stat_exp_3(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = buf32;

                    buf32 = rand_stat_exp_3(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = buf32;

                    buf32 = rand_stat_exp_3(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = buf32;

                    buf32 = rand_stat_exp_3(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = buf32;
                    break;

                case 4:
                    rental_pkm_iv_atk[rental_id] = std::min(quint8(rand_iv_4(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_def[rental_id] = std::min(quint8(rand_iv_4(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_spc[rental_id] = std::min(quint8(rand_iv_4(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_speed[rental_id] = std::min(quint8(rand_iv_4(mt_rand)),rental_ivs_max);

                    buf32 = rand_stat_exp_4(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_hp[rental_id] = buf32;

                    buf32 = rand_stat_exp_4(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = buf32;

                    buf32 = rand_stat_exp_4(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = buf32;

                    buf32 = rand_stat_exp_4(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = buf32;

                    buf32 = rand_stat_exp_4(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = buf32;
                    break;

                case 5:
                    rental_pkm_iv_atk[rental_id] = std::min(quint8(rand_iv_5(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_def[rental_id] = std::min(quint8(rand_iv_5(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_spc[rental_id] = std::min(quint8(rand_iv_5(mt_rand)),rental_ivs_max);
                    rental_pkm_iv_speed[rental_id] = std::min(quint8(rand_iv_5(mt_rand)),rental_ivs_max);

                    buf32 = rand_stat_exp_5(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_hp[rental_id] = buf32;

                    buf32 = rand_stat_exp_5(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_atk[rental_id] = buf32;

                    buf32 = rand_stat_exp_5(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_def[rental_id] = buf32;

                    buf32 = rand_stat_exp_5(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_spc[rental_id] = buf32;

                    buf32 = rand_stat_exp_5(mt_rand);
                    if(buf32 > rental_stat_exp_max) buf32 = rental_stat_exp_max;
                    rental_pkm_ev_speed[rental_id] = buf32;
                    break;

                default:
                    rental_pkm_iv_atk[rental_id] = rand_iv_6(mt_rand);
                    rental_pkm_iv_def[rental_id] = rand_iv_6(mt_rand);
                    rental_pkm_iv_spc[rental_id] = rand_iv_6(mt_rand);
                    rental_pkm_iv_speed[rental_id] = rand_iv_6(mt_rand);
                    rental_pkm_ev_hp[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_atk[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_def[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_spc[rental_id] = rand_stat_exp_6(mt_rand);
                    rental_pkm_ev_speed[rental_id] = rand_stat_exp_6(mt_rand);
                    break;
                }
            }
        }
        else{
            rental_pkm_iv_atk[rental_id] = rand_iv_5(mt_rand);
            rental_pkm_iv_def[rental_id] = rand_iv_5(mt_rand);
            rental_pkm_iv_spc[rental_id] = rand_iv_5(mt_rand);
            rental_pkm_iv_speed[rental_id] = rand_iv_5(mt_rand);

            rental_pkm_ev_hp[rental_id] = rand_stat_exp_default(mt_rand);
            rental_pkm_ev_atk[rental_id] = rand_stat_exp_default(mt_rand);
            rental_pkm_ev_def[rental_id] = rand_stat_exp_default(mt_rand);
            rental_pkm_ev_spc[rental_id] = rand_stat_exp_default(mt_rand);
            rental_pkm_ev_speed[rental_id] = rand_stat_exp_default(mt_rand);
        }
        rental_pkm_iv_hp[rental_id] = (rental_pkm_iv_atk[rental_id] & 1)*8 + (rental_pkm_iv_def[rental_id] & 1)*4 + (rental_pkm_iv_speed[rental_id] & 1)*2 + (rental_pkm_iv_spc[rental_id] & 1);
    }
}


void MainWindow::randomize_rental_level(std::mt19937 &mt_rand)
{
    bool min_lv_rolled_petitcup = false;
    bool min_lv_rolled_pikacup = false;
    bool min_lv_rolled_pokecup = false;
    quint8 min_lv_petitcup_pkm = 0;
    quint8 min_lv_pikacup_pkm = 0;
    quint8 min_lv_pokecup_pkm = 0;

    if(rental_cup_offset[1]>2){
        std::uniform_int_distribution<> min_lv_petitcup(0,(rental_cup_offset[1]-1));
        min_lv_petitcup_pkm = min_lv_petitcup(mt_rand);
    }
    if((rental_cup_offset[2]-rental_cup_offset[1])>2){
        std::uniform_int_distribution<> min_lv_pikacup(rental_cup_offset[1],(rental_cup_offset[2]-1));
        min_lv_pikacup_pkm = min_lv_pikacup(mt_rand);
    }
    if((rental_cup_offset[4]-rental_cup_offset[3])>2){
        std::uniform_int_distribution<> min_lv_pokecup(rental_cup_offset[3],(rental_cup_offset[4]-1));
        min_lv_pokecup_pkm = min_lv_pokecup(mt_rand);
    }
    std::uniform_int_distribution<> distrib_glc_lv(glc_level_min,glc_level_max);

    // Rental Levels generation
    for(short rental_id=0;rental_id<current_rentals_number;rental_id++){
        // Petit Cup: Lv 25 to Lv 30
        if(rental_cup_id[rental_id]==0){
            if(rental_id == min_lv_petitcup_pkm || (rental_id==(rental_cup_offset[1]-1) && min_lv_rolled_petitcup==false)){
                rental_pkm_level[rental_id]=25;
            }
            else{
                std::uniform_int_distribution<> level(22,30);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]<25) rental_pkm_level[rental_id] = 25;
                if(rental_pkm_level[rental_id]==25 && min_lv_rolled_petitcup==false)
                    min_lv_rolled_petitcup = true;
            }
        }
        // Pika Cup: Lv 15 to Lv 20
        if(rental_cup_id[rental_id]==1){
            if(rental_id == min_lv_pikacup_pkm || (rental_id==(rental_cup_offset[2]-1) && min_lv_rolled_pikacup==false)){
                rental_pkm_level[rental_id]=15;
            }
            else{
                std::uniform_int_distribution<> level(13,20);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]<15) rental_pkm_level[rental_id] = 15;
                if(rental_pkm_level[rental_id]==15 && min_lv_rolled_pikacup==false)
                    min_lv_rolled_pikacup = true;
            }
        }
        // Prime Cup 1: Lv 100
        if(rental_cup_id[rental_id]==2){
            rental_pkm_level[rental_id]=100;
        }
        // Poke Cup: Lv 50 to Lv 55
        if(rental_cup_id[rental_id]==3){
            if(rental_id == min_lv_pokecup_pkm || (rental_id==(rental_cup_offset[4]-2) && min_lv_rolled_pokecup==false)){
                rental_pkm_level[rental_id]=50;
            }
            else if(rental_id==(rental_cup_offset[4]-1)){
                rental_pkm_level[rental_id]=55;
            }
            else{
                std::uniform_int_distribution<> level(49,55);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]<50) rental_pkm_level[rental_id] = 50;
                if(rental_pkm_level[rental_id]==50 && min_lv_rolled_pokecup==false)
                    min_lv_rolled_pokecup = true;
            }
        }
        // Gym Leader Castle: User-specified Lv range
        if(rental_cup_id[rental_id]==4){
            if(glc_level_min != glc_level_max){
                rental_pkm_level[rental_id] = distrib_glc_lv(mt_rand);
            }
            else{
                rental_pkm_level[rental_id] = glc_level_min;
            }
        }
        // Prime Cup 2: Lv 100
        if(rental_cup_id[rental_id]==5){
            rental_pkm_level[rental_id]=100;
        }
    }
}


void MainWindow::randomize_rental_moves(std::mt19937 &mt_rand)
{
    bool no_illegal_moves = ui->checkBox_Randomizer_Rental_NoIllegalMoves->isChecked();
    bool no_useless_moves = ui->checkBox_Randomizer_Rental_NoUselessMoves->isChecked();
    bool no_weak_moves = ui->checkBox_Randomizer_Rental_NoWeakMoves->isChecked();
    bool no_dragon_rage = ui->checkBox_Randomizer_Rental_NoDragonRage->isChecked();
    bool no_evasion_moves = ui->checkBox_Randomizer_Rental_NoEvasion->isChecked();
    bool no_ohko_moves = ui->checkBox_Randomizer_Rental_NoOHKOMoves->isChecked();
    bool have_offensive_move = ui->checkBox_Randomizer_Rental_OffensiveMove->isChecked();
    bool have_stab_move = ui->checkBox_Randomizer_Rental_STABMove->isChecked();
    bool max_pp_ups = ui->checkBox_Randomizer_Rental_MaxPPUps->isChecked();
    bool no_pp_ups = ui->checkBox_Randomizer_Rental_NoPPUps->isChecked();

    for(short rental_id=0;rental_id<current_rentals_number;rental_id++){
        moves_ids_vector.clear();
        buf8 = rental_pkm_id[rental_id];
        bool learns_offensive_move = false;
        bool learns_stab_move = false;

        if(no_illegal_moves){
            // Starting Moves
            if(pkm_start_move_1[buf8]>0 && pkm_start_move_1[buf8]<total_move_name){
                // Dragon Rage
                if(pkm_start_move_1[buf8]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                    if(no_dragon_rage==false){
                        moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                        learns_offensive_move = true;
                    }
                }
                // Double Team, Reflect
                else if(move_effect[pkm_start_move_1[buf8]]==0xF){
                    if(no_evasion_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                }
                // Fissure, Guillotine, Horn Drill
                else if(move_effect[pkm_start_move_1[buf8]]==0x26){
                    if(no_ohko_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                }
                // Other moves
                else if(no_weak_moves==false || weak_move[pkm_start_move_1[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_1[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_1[buf8]);

                        // Offensive move and STAB move check
                        if(move_power[pkm_start_move_1[buf8]]>1){
                            learns_offensive_move = true;
                            if(move_type[pkm_start_move_1[buf8]] == pkm_type_1[buf8] || move_type[pkm_start_move_1[buf8]] == pkm_type_2[buf8]){
                                learns_stab_move = true;
                            }
                        }
                    }
                }
            }
            if(pkm_start_move_2[buf8]>0 && pkm_start_move_2[buf8]<total_move_name){
                // Dragon Rage
                if(pkm_start_move_2[buf8]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                    if(no_dragon_rage==false){
                        moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                        learns_offensive_move = true;
                    }
                }
                // Double Team, Reflect
                else if(move_effect[pkm_start_move_2[buf8]]==0xF){
                    if(no_evasion_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                }
                // Fissure, Guillotine, Horn Drill
                else if(move_effect[pkm_start_move_2[buf8]]==0x26){
                    if(no_ohko_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                }
                // Other moves
                else if(no_weak_moves==false || weak_move[pkm_start_move_2[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_2[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_2[buf8]);

                        // Offensive move and STAB move check
                        if(move_power[pkm_start_move_2[buf8]]>1){
                            learns_offensive_move = true;
                            if(move_type[pkm_start_move_2[buf8]] == pkm_type_1[buf8] || move_type[pkm_start_move_2[buf8]] == pkm_type_2[buf8]){
                                learns_stab_move = true;
                            }
                        }
                    }
                }
            }
            if(pkm_start_move_3[buf8]>0 && pkm_start_move_3[buf8]<total_move_name){
                // Dragon Rage
                if(pkm_start_move_3[buf8]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                    if(no_dragon_rage==false){
                        moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                        learns_offensive_move = true;
                    }
                }
                // Double Team, Reflect
                else if(move_effect[pkm_start_move_3[buf8]]==0xF){
                    if(no_evasion_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                }
                // Fissure, Guillotine, Horn Drill
                else if(move_effect[pkm_start_move_3[buf8]]==0x26){
                    if(no_ohko_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                }
                // Other moves
                else if(no_weak_moves==false || weak_move[pkm_start_move_3[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_3[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_3[buf8]);

                        // Offensive move and STAB move check
                        if(move_power[pkm_start_move_3[buf8]]>1){
                            learns_offensive_move = true;
                            if(move_type[pkm_start_move_3[buf8]] == pkm_type_1[buf8] || move_type[pkm_start_move_3[buf8]] == pkm_type_2[buf8]){
                                learns_stab_move = true;
                            }
                        }
                    }
                }
            }
            if(pkm_start_move_4[buf8]>0 && pkm_start_move_4[buf8]<total_move_name){
                // Dragon Rage
                if(pkm_start_move_4[buf8]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                    if(no_dragon_rage==false){
                        moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                        learns_offensive_move = true;
                    }
                }
                // Double Team, Reflect
                else if(move_effect[pkm_start_move_4[buf8]]==0xF){
                    if(no_evasion_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                }
                // Fissure, Guillotine, Horn Drill
                else if(move_effect[pkm_start_move_4[buf8]]==0x26){
                    if(no_ohko_moves==false){
                        moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                }
                // Other moves
                else if(no_weak_moves==false || weak_move[pkm_start_move_4[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_4[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_4[buf8]);

                        // Offensive move and STAB move check
                        if(move_power[pkm_start_move_4[buf8]]>1){
                            learns_offensive_move = true;
                            if(move_type[pkm_start_move_4[buf8]] == pkm_type_1[buf8] || move_type[pkm_start_move_4[buf8]] == pkm_type_2[buf8]){
                                learns_stab_move = true;
                            }
                        }
                    }
                }
            }

            // TM HM Moves
            for(uint8_t j=1;j<56;j++){
                if(move_tmhm[j]>0 && move_tmhm[j]<total_move_name){
                    move_tmhm_flag = (j-1)%8;
                    move_tmhm_byte = (j-1)/8;

                    if((1<<move_tmhm_flag) & pkm_tmhm_flags[buf8][move_tmhm_byte]){
                        // Dragon Rage
                        if(move_tmhm[j]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                            if(no_dragon_rage==false){
                                moves_ids_vector.push_back(move_tmhm[j]);
                                learns_offensive_move = true;
                            }
                        }
                        // Double Team, Reflect
                        else if(move_effect[move_tmhm[j]]==0xF){
                            if(no_evasion_moves==false){
                                moves_ids_vector.push_back(move_tmhm[j]);
                            }
                        }
                        // Fissure, Guillotine, Horn Drill
                        else if(move_effect[move_tmhm[j]]==0x26){
                            if(no_ohko_moves==false){
                                moves_ids_vector.push_back(move_tmhm[j]);
                            }
                        }
                        // Other moves
                        else if(no_weak_moves==false || weak_move[move_tmhm[j]]==false){
                            if(no_useless_moves==false || useless_move[move_tmhm[j]]==false){
                                moves_ids_vector.push_back(move_tmhm[j]);

                                // Offensive move and STAB move check
                                if(move_power[move_tmhm[j]]>1){
                                    learns_offensive_move = true;
                                    if(move_type[move_tmhm[j]] == pkm_type_1[buf8] || move_type[move_tmhm[j]] == pkm_type_2[buf8]){
                                        learns_stab_move = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // Level-up Moves
            for(uint8_t j=0;j<10;j++){
                if(pkm_rb_move[buf8][j]>0 && pkm_rb_move[buf8][j]<total_move_name && pkm_rb_lvl[buf8][j]<=rental_pkm_level[rental_id]){
                    // Dragon Rage
                    if(pkm_rb_move[buf8][j]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                            learns_offensive_move = true;
                        }
                    }
                    // Double Team, Reflect
                    else if(move_effect[pkm_rb_move[buf8][j]]==0xF){
                        if(no_evasion_moves==false){
                            moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                    }
                    // Fissure, Guillotine, Horn Drill
                    else if(move_effect[pkm_rb_move[buf8][j]]==0x26){
                        if(no_ohko_moves==false){
                            moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[pkm_rb_move[buf8][j]]==false){
                        if(no_useless_moves==false || useless_move[pkm_rb_move[buf8][j]]==false){
                            moves_ids_vector.push_back(pkm_rb_move[buf8][j]);

                            // Offensive move and STAB move check
                            if(move_power[pkm_rb_move[buf8][j]]>1){
                                learns_offensive_move = true;
                                if(move_type[pkm_rb_move[buf8][j]] == pkm_type_1[buf8] || move_type[pkm_rb_move[buf8][j]] == pkm_type_2[buf8]){
                                    learns_stab_move = true;
                                }
                            }
                        }
                    }
                }

                if(pkm_y_move[buf8][j]>0 && pkm_y_move[buf8][j]<total_move_name && pkm_y_lvl[buf8][j]<=rental_pkm_level[rental_id]){
                    // Dragon Rage
                    if(pkm_y_move[buf8][j]==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                            learns_offensive_move = true;
                        }
                    }
                    // Double Team, Reflect
                    else if(move_effect[pkm_y_move[buf8][j]]==0xF){
                        if(no_evasion_moves==false){
                            moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        }
                    }
                    // Fissure, Guillotine, Horn Drill
                    else if(move_effect[pkm_y_move[buf8][j]]==0x26){
                        if(no_ohko_moves==false){
                            moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[pkm_y_move[buf8][j]]==false){
                        if(no_useless_moves==false || useless_move[pkm_y_move[buf8][j]]==false){
                            moves_ids_vector.push_back(pkm_y_move[buf8][j]);

                            // Offensive move and STAB move check
                            if(move_power[pkm_y_move[buf8][j]]>1){
                                learns_offensive_move = true;
                                if(move_type[pkm_y_move[buf8][j]] == pkm_type_1[buf8] || move_type[pkm_y_move[buf8][j]] == pkm_type_2[buf8]){
                                    learns_stab_move = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            bool no_spore = ui->checkBox_Randomizer_Rental_NoSpore->isChecked();
            for(uint8_t cur_illegalmove=1 ; cur_illegalmove<total_move_name ; cur_illegalmove++){
                if(cur_illegalmove!=0x93 || no_spore==false){
                    // TO DO: optimize this
                    // Dragon Rage
                    if(cur_illegalmove==0x52 && (rental_cup_id[rental_id]==0 || rental_cup_id[rental_id]==1)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(cur_illegalmove);
                            learns_offensive_move = true;
                        }
                    }
                    // Double Team, Reflect
                    else if(move_effect[cur_illegalmove]==0xF){
                        if(no_evasion_moves==false){
                            moves_ids_vector.push_back(cur_illegalmove);
                        }
                    }
                    // Fissure, Guillotine, Horn Drill
                    else if(move_effect[cur_illegalmove]==0x26){
                        if(no_ohko_moves==false){
                            moves_ids_vector.push_back(cur_illegalmove);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[cur_illegalmove]==false){
                        if(no_useless_moves==false || useless_move[cur_illegalmove]==false){
                            moves_ids_vector.push_back(cur_illegalmove);

                            // Offensive move and STAB move check
                            if(move_power[cur_illegalmove]>1){
                                learns_offensive_move = true;
                                if(move_type[cur_illegalmove] == pkm_type_1[buf8] || move_type[cur_illegalmove] == pkm_type_2[buf8]){
                                    learns_stab_move = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        /* Remove moves duplicates in the Pokémon's learnset.
        It's faster to NOT convert to a set in an unmodified Stadium ROM, as there are not a lot of duplicates.
        If there are more duplicate moves in your ROM learnsets, it might be more efficient to convert to a set, then assign the set to the vector */
        if(moves_ids_vector.size()>0) {
            sort(moves_ids_vector.begin(), moves_ids_vector.end());
            moves_ids_vector.erase(std::unique(moves_ids_vector.begin(), moves_ids_vector.end()), moves_ids_vector.end());
        }


        // Randomize Pokémon Moves
        bool got_offensive_move = false;
        bool got_stab_move = false;
        uint8_t offset_vector_move = 0;

        // Move 1
        if(moves_ids_vector.size()>0){
            std::shuffle(moves_ids_vector.begin(), moves_ids_vector.end(), mt_rand);
            rental_pkm_move_1[rental_id] = moves_ids_vector[0];
            if(max_pp_ups) rental_pkm_ppup_1[rental_id]=3;
            else if(no_pp_ups) rental_pkm_ppup_1[rental_id]=0;

            if(move_power[rental_pkm_move_1[rental_id]]>1){
                got_offensive_move = true;
                if(move_type[rental_pkm_move_1[rental_id]] == pkm_type_1[buf8] || move_type[rental_pkm_move_1[rental_id]] == pkm_type_2[buf8]){
                    got_stab_move = true;
                }
            }
        }
        else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
             rental_pkm_move_1[rental_id] = pkm_start_move_1[buf8];
             if(max_pp_ups) rental_pkm_ppup_1[rental_id]=3;
             else if(no_pp_ups) rental_pkm_ppup_1[rental_id]=0;
        }
        else{
            rental_pkm_move_1[rental_id] = 1;
            if(max_pp_ups) rental_pkm_ppup_1[rental_id]=3;
            else if(no_pp_ups) rental_pkm_ppup_1[rental_id]=0;
        }

        // Move 2
        if(moves_ids_vector.size()>1){
            rental_pkm_move_2[rental_id] = moves_ids_vector[1];
            if(max_pp_ups) rental_pkm_ppup_2[rental_id]=3;
            else if(no_pp_ups) rental_pkm_ppup_2[rental_id]=0;

            if(move_power[rental_pkm_move_2[rental_id]]>1){
                got_offensive_move = true;
                if(move_type[rental_pkm_move_2[rental_id]] == pkm_type_1[buf8] || move_type[rental_pkm_move_2[rental_id]] == pkm_type_2[buf8]){
                    got_stab_move = true;
                }
            }
        }
        else rental_pkm_move_2[rental_id] = 0;

        // Move 3
        if(moves_ids_vector.size()>2){
            rental_pkm_move_3[rental_id] = moves_ids_vector[2];
            if(max_pp_ups) rental_pkm_ppup_3[rental_id]=3;
            else if(no_pp_ups) rental_pkm_ppup_3[rental_id]=0;

            if(move_power[rental_pkm_move_3[rental_id]]>1){
                got_offensive_move = true;
                if(move_type[rental_pkm_move_3[rental_id]] == pkm_type_1[buf8] || move_type[rental_pkm_move_3[rental_id]] == pkm_type_2[buf8]){
                    got_stab_move = true;
                }
            }
        }
        else rental_pkm_move_3[rental_id] = 0;

        // Move 4
        if(moves_ids_vector.size()>3){
            offset_vector_move = 3;
            // Force STAB move, except on low ATK physical types like Chansey or Gastly
            if(have_stab_move && got_stab_move==false && learns_stab_move==true && (pkm_type_1[buf8]>8 || pkm_type_2[buf8]>8 || pkm_base_atk[buf8]>=40)){
                while(move_power[moves_ids_vector[offset_vector_move]]<=1 || (move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_1[buf8] && move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_2[buf8])){
                    offset_vector_move++;
                    if(offset_vector_move >= moves_ids_vector.size()){
                        offset_vector_move--;
                        break;
                    }
                }
            }
            // Force offensive move
            else if(have_offensive_move && got_offensive_move==false && learns_offensive_move==true){
                while(move_power[moves_ids_vector[offset_vector_move]]<=1){
                    offset_vector_move++;
                    if(offset_vector_move >= moves_ids_vector.size()){
                        offset_vector_move--;
                        break;
                    }
                }
            }

            rental_pkm_move_4[rental_id] = moves_ids_vector[offset_vector_move];
            if(max_pp_ups) rental_pkm_ppup_4[rental_id]=3;
            else if(no_pp_ups) rental_pkm_ppup_4[rental_id]=0;
        }
        else rental_pkm_move_4[rental_id] = 0;
    }
}


void MainWindow::randomize_rental_pkmn(std::mt19937 &mt_rand)
{
    RentalPkm current_rental_pkm[1024];

    std::shuffle(pkm_ids_vector_rental_petitcup.begin(), pkm_ids_vector_rental_petitcup.end(), mt_rand);
    std::shuffle(pkm_ids_vector_rental_pikacup.begin(), pkm_ids_vector_rental_pikacup.end(), mt_rand);
    std::shuffle(pkm_ids_vector_rental_primecup.begin(), pkm_ids_vector_rental_primecup.end(), mt_rand);
    std::shuffle(pkm_ids_vector_rental_pokecup.begin(), pkm_ids_vector_rental_pokecup.end(), mt_rand);

    // Rental Pokémon generation
    // Petit Cup: Lv 25 to Lv 30
    for(short rental_id = rental_cup_offset[0] ; rental_id < rental_cup_offset[1] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_petitcup.size()){
                if(rental_pkm_level[rental_id] < pkm_min_level[pkm_ids_vector_rental_petitcup[index_vector_pkm+offset_vector_pkm]]){
                    offset_vector_pkm++;
                }
                else{
                    not_legal_level = false;
                }
            }
            // Fail-safe
            else{
                offset_vector_pkm = 0;
                not_legal_level = false;
            }
        }
        if(offset_vector_pkm > 0){
            buf8 = pkm_ids_vector_rental_petitcup[index_vector_pkm];
            pkm_ids_vector_rental_petitcup[index_vector_pkm] = pkm_ids_vector_rental_petitcup[index_vector_pkm+offset_vector_pkm];
            pkm_ids_vector_rental_petitcup[index_vector_pkm+offset_vector_pkm] = buf8;
        }

        current_rental_pkm[rental_id-rental_cup_offset[0]].setRentalPkmId(pkm_ids_vector_rental_petitcup[index_vector_pkm]);
        current_rental_pkm[rental_id-rental_cup_offset[0]].setRentalPkmLevel(rental_pkm_level[rental_id]);

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_petitcup.begin(), pkm_ids_vector_rental_petitcup.end(), mt_rand);
        }
    }

    if(current_rental_pkm[0].getRentalPkmLevel() != 2){
        std::sort(current_rental_pkm, current_rental_pkm + (rental_cup_offset[1] - rental_cup_offset[0]),
                  [](RentalPkm const & a, RentalPkm const & b) -> bool
                            { return a.cl_rental_pkm_id < b.cl_rental_pkm_id; });
    }

    for(short rental_id = rental_cup_offset[0] ; rental_id < rental_cup_offset[1] ; rental_id++){
        rental_pkm_id[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[0]].getRentalPkmId();
        rental_pkm_level[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[0]].getRentalPkmLevel();
        rental_pkm_experience[rental_id] = calc_experience(pkm_growth_rate[rental_pkm_id[rental_id]],rental_pkm_level[rental_id]);
        rental_pkm_nickname[rental_id] = pkm_name[rental_pkm_id[rental_id]];
    }


    // Pika Cup: Lv 15 to Lv 20
    for(short rental_id = rental_cup_offset[1] ; rental_id < rental_cup_offset[2] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_pikacup.size()){
                if(rental_pkm_level[rental_id] < pkm_min_level[pkm_ids_vector_rental_pikacup[index_vector_pkm+offset_vector_pkm]]){
                    offset_vector_pkm++;
                }
                else{
                    not_legal_level = false;
                }
            }
            // Fail-safe
            else{
                offset_vector_pkm = 0;
                not_legal_level = false;
            }
        }
        if(offset_vector_pkm > 0){
            buf8 = pkm_ids_vector_rental_pikacup[index_vector_pkm];
            pkm_ids_vector_rental_pikacup[index_vector_pkm] = pkm_ids_vector_rental_pikacup[index_vector_pkm+offset_vector_pkm];
            pkm_ids_vector_rental_pikacup[index_vector_pkm+offset_vector_pkm] = buf8;
        }

        current_rental_pkm[rental_id-rental_cup_offset[1]].setRentalPkmId(pkm_ids_vector_rental_pikacup[index_vector_pkm]);
        current_rental_pkm[rental_id-rental_cup_offset[1]].setRentalPkmLevel(rental_pkm_level[rental_id]);

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_pikacup.begin(), pkm_ids_vector_rental_pikacup.end(), mt_rand);
        }
    }

    if(current_rental_pkm[1].getRentalPkmLevel() != 2){
        std::sort(current_rental_pkm, current_rental_pkm + (rental_cup_offset[2] - rental_cup_offset[1]),
                  [](RentalPkm const & a, RentalPkm const & b) -> bool
                            { return a.cl_rental_pkm_id < b.cl_rental_pkm_id; });
    }

    for(short rental_id = rental_cup_offset[1] ; rental_id < rental_cup_offset[2] ; rental_id++){
        rental_pkm_id[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[1]].getRentalPkmId();
        rental_pkm_level[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[1]].getRentalPkmLevel();
        rental_pkm_experience[rental_id] = calc_experience(pkm_growth_rate[rental_pkm_id[rental_id]],rental_pkm_level[rental_id]);
        rental_pkm_nickname[rental_id] = pkm_name[rental_pkm_id[rental_id]];
    }


    // Prime Cup 1: Lv 100
    for(short rental_id = rental_cup_offset[2] ; rental_id < rental_cup_offset[3] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_primecup.size()){
                if(rental_pkm_level[rental_id] < pkm_min_level[pkm_ids_vector_rental_primecup[index_vector_pkm+offset_vector_pkm]]){
                    offset_vector_pkm++;
                }
                else{
                    not_legal_level = false;
                }
            }
            // Fail-safe
            else{
                offset_vector_pkm = 0;
                not_legal_level = false;
            }
        }
        if(offset_vector_pkm > 0){
            buf8 = pkm_ids_vector_rental_primecup[index_vector_pkm];
            pkm_ids_vector_rental_primecup[index_vector_pkm] = pkm_ids_vector_rental_primecup[index_vector_pkm+offset_vector_pkm];
            pkm_ids_vector_rental_primecup[index_vector_pkm+offset_vector_pkm] = buf8;
        }

        current_rental_pkm[rental_id-rental_cup_offset[2]].setRentalPkmId(pkm_ids_vector_rental_primecup[index_vector_pkm]);
        current_rental_pkm[rental_id-rental_cup_offset[2]].setRentalPkmLevel(rental_pkm_level[rental_id]);

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_primecup.begin(), pkm_ids_vector_rental_primecup.end(), mt_rand);
        }
    }

    if(current_rental_pkm[2].getRentalPkmLevel() != 2){
        std::sort(current_rental_pkm, current_rental_pkm + (rental_cup_offset[3] - rental_cup_offset[2]),
                  [](RentalPkm const & a, RentalPkm const & b) -> bool
                            { return a.cl_rental_pkm_id < b.cl_rental_pkm_id; });
    }

    for(short rental_id = rental_cup_offset[2] ; rental_id < rental_cup_offset[3] ; rental_id++){
        rental_pkm_id[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[2]].getRentalPkmId();
        rental_pkm_level[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[2]].getRentalPkmLevel();
        rental_pkm_experience[rental_id] = calc_experience(pkm_growth_rate[rental_pkm_id[rental_id]],rental_pkm_level[rental_id]);
        rental_pkm_nickname[rental_id] = pkm_name[rental_pkm_id[rental_id]];
    }


    // Poke Cup: Lv 50 to Lv 55
    for(short rental_id = rental_cup_offset[3] ; rental_id < rental_cup_offset[4] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_pokecup.size()){
                if(rental_pkm_level[rental_id] < pkm_min_level[pkm_ids_vector_rental_pokecup[index_vector_pkm+offset_vector_pkm]]){
                    offset_vector_pkm++;
                }
                else{
                    not_legal_level = false;
                }
            }
            // Fail-safe
            else{
                offset_vector_pkm = 0;
                not_legal_level = false;
            }
        }
        if(offset_vector_pkm > 0){
            buf8 = pkm_ids_vector_rental_pokecup[index_vector_pkm];
            pkm_ids_vector_rental_pokecup[index_vector_pkm] = pkm_ids_vector_rental_pokecup[index_vector_pkm+offset_vector_pkm];
            pkm_ids_vector_rental_pokecup[index_vector_pkm+offset_vector_pkm] = buf8;
        }

        current_rental_pkm[rental_id-rental_cup_offset[3]].setRentalPkmId(pkm_ids_vector_rental_pokecup[index_vector_pkm]);
        current_rental_pkm[rental_id-rental_cup_offset[3]].setRentalPkmLevel(rental_pkm_level[rental_id]);

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_pokecup.begin(), pkm_ids_vector_rental_pokecup.end(), mt_rand);
        }
    }

    if(current_rental_pkm[3].getRentalPkmLevel() != 2){
        std::sort(current_rental_pkm, current_rental_pkm + (rental_cup_offset[4] - rental_cup_offset[3]),
                  [](RentalPkm const & a, RentalPkm const & b) -> bool
                            { return a.cl_rental_pkm_id < b.cl_rental_pkm_id; });
    }

    for(short rental_id = rental_cup_offset[3] ; rental_id < rental_cup_offset[4] ; rental_id++){
        rental_pkm_id[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[3]].getRentalPkmId();
        rental_pkm_level[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[3]].getRentalPkmLevel();
        rental_pkm_experience[rental_id] = calc_experience(pkm_growth_rate[rental_pkm_id[rental_id]],rental_pkm_level[rental_id]);
        rental_pkm_nickname[rental_id] = pkm_name[rental_pkm_id[rental_id]];
    }


    // Gym Leader Castle: Lv 50
    for(short rental_id = rental_cup_offset[4] ; rental_id < rental_cup_offset[5] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_pokecup.size()){
                if(rental_pkm_level[rental_id] < pkm_min_level[pkm_ids_vector_rental_pokecup[index_vector_pkm+offset_vector_pkm]]){
                    offset_vector_pkm++;
                }
                else{
                    not_legal_level = false;
                }
            }
            // Fail-safe
            else{
                offset_vector_pkm = 0;
                not_legal_level = false;
            }
        }
        if(offset_vector_pkm > 0){
            buf8 = pkm_ids_vector_rental_pokecup[index_vector_pkm];
            pkm_ids_vector_rental_pokecup[index_vector_pkm] = pkm_ids_vector_rental_pokecup[index_vector_pkm+offset_vector_pkm];
            pkm_ids_vector_rental_pokecup[index_vector_pkm+offset_vector_pkm] = buf8;
        }

        current_rental_pkm[rental_id-rental_cup_offset[4]].setRentalPkmId(pkm_ids_vector_rental_pokecup[index_vector_pkm]);
        current_rental_pkm[rental_id-rental_cup_offset[4]].setRentalPkmLevel(rental_pkm_level[rental_id]);

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_pokecup.begin(), pkm_ids_vector_rental_pokecup.end(), mt_rand);
        }
    }

    if(current_rental_pkm[4].getRentalPkmLevel() != 2){
        std::sort(current_rental_pkm, current_rental_pkm + (rental_cup_offset[5] - rental_cup_offset[4]),
                  [](RentalPkm const & a, RentalPkm const & b) -> bool
                            { return a.cl_rental_pkm_id < b.cl_rental_pkm_id; });
    }

    for(short rental_id = rental_cup_offset[4] ; rental_id < rental_cup_offset[5] ; rental_id++){
        rental_pkm_id[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[4]].getRentalPkmId();
        rental_pkm_level[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[4]].getRentalPkmLevel();
        rental_pkm_experience[rental_id] = calc_experience(pkm_growth_rate[rental_pkm_id[rental_id]],rental_pkm_level[rental_id]);
        rental_pkm_nickname[rental_id] = pkm_name[rental_pkm_id[rental_id]];
    }


    // Prime Cup 2: Lv 100
    for(short rental_id = rental_cup_offset[5] ; rental_id < rental_cup_offset[6] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_primecup.size()){
                if(rental_pkm_level[rental_id] < pkm_min_level[pkm_ids_vector_rental_primecup[index_vector_pkm+offset_vector_pkm]]){
                    offset_vector_pkm++;
                }
                else{
                    not_legal_level = false;
                }
            }
            // Fail-safe
            else{
                offset_vector_pkm = 0;
                not_legal_level = false;
            }
        }
        if(offset_vector_pkm > 0){
            buf8 = pkm_ids_vector_rental_primecup[index_vector_pkm];
            pkm_ids_vector_rental_primecup[index_vector_pkm] = pkm_ids_vector_rental_primecup[index_vector_pkm+offset_vector_pkm];
            pkm_ids_vector_rental_primecup[index_vector_pkm+offset_vector_pkm] = buf8;
        }

        current_rental_pkm[rental_id-rental_cup_offset[5]].setRentalPkmId(pkm_ids_vector_rental_primecup[index_vector_pkm]);
        current_rental_pkm[rental_id-rental_cup_offset[5]].setRentalPkmLevel(rental_pkm_level[rental_id]);

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_primecup.begin(), pkm_ids_vector_rental_primecup.end(), mt_rand);
        }
    }

    if(current_rental_pkm[5].getRentalPkmLevel() != 2){
        std::sort(current_rental_pkm, current_rental_pkm + (rental_cup_offset[6] - rental_cup_offset[5]),
                  [](RentalPkm const & a, RentalPkm const & b) -> bool
                            { return a.cl_rental_pkm_id < b.cl_rental_pkm_id; });
    }

    for(short rental_id = rental_cup_offset[5] ; rental_id < rental_cup_offset[6] ; rental_id++){
        rental_pkm_id[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[5]].getRentalPkmId();
        rental_pkm_level[rental_id] = current_rental_pkm[rental_id-rental_cup_offset[5]].getRentalPkmLevel();
        rental_pkm_experience[rental_id] = calc_experience(pkm_growth_rate[rental_pkm_id[rental_id]],rental_pkm_level[rental_id]);
        rental_pkm_nickname[rental_id] = pkm_name[rental_pkm_id[rental_id]];
    }
}
