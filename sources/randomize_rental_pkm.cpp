#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_rental_init_pkmn(){
    bool no_mew_mewtwo = ui->checkBox_Randomizer_Rental_NoMewMewtwo->isChecked();

    pkm_ids_vector_rental_petitcup.clear();
    pkm_ids_vector_rental_pikacup.clear();
    pkm_ids_vector_rental_primecup.clear();
    pkm_ids_vector_rental_pokecup.clear();

    // Petit Cup
    short pkm_list_petitcup[] = {1,4,7,16,19,21,23,25,27,32,35,37,39,43,46,50,52,54,58,60,63,66,69,74,81,83,90,92,98,100,102,104,109,116,118,133,138,140,147};
    pkm_ids_vector_rental_petitcup.assign(pkm_list_petitcup,pkm_list_petitcup+(sizeof(pkm_list_petitcup)/sizeof(*pkm_list_petitcup)));
    if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked() == false){
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
        if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked() == false){
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
        if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked() == false){
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
        if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_rental_primecup.push_back(83);
            pkm_ids_vector_rental_primecup.push_back(132);
        }
        pkm_ids_vector_rental_primecup.push_back(150);
        pkm_ids_vector_rental_primecup.push_back(151);
    }
    else if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked()){
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
    if(ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()){
        short pkm_list_pokecup[] = {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_rental_pokecup.assign(pkm_list_pokecup,pkm_list_pokecup+(sizeof(pkm_list_pokecup)/sizeof(*pkm_list_pokecup)));
        if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_rental_pokecup.push_back(83);
            pkm_ids_vector_rental_pokecup.push_back(132);
        }
    }
    else if(ui->checkBox_Randomizer_Rental_NoUselessPkmn->isChecked()){
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


void MainWindow::randomize_rental_level(std::mt19937 &mt_rand)
{
    // PRNG
    mt_rand.discard(700000);

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

    // Rental Levels generation
    for(short rental_id=0;rental_id<current_rentals_number;rental_id++){
        // Petit Cup: Lv 25 to Lv 30
        if(rental_cup_id[rental_id]==0){
            if(rental_id == min_lv_petitcup_pkm || (rental_id==(rental_cup_offset[1]-1) && min_lv_rolled_petitcup==false)){
                rental_pkm_level[rental_id]=25;
            }
            else{
                std::uniform_int_distribution<> level(25,30);
                rental_pkm_level[rental_id] = level(mt_rand);
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
                std::uniform_int_distribution<> level(15,20);
                rental_pkm_level[rental_id] = level(mt_rand);
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
                std::uniform_int_distribution<> level(50,55);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]==50 && min_lv_rolled_pokecup==false)
                    min_lv_rolled_pokecup = true;
            }
        }
        // Gym Leader Castle: Lv 50
        if(rental_cup_id[rental_id]==4){
            rental_pkm_level[rental_id]=50;
        }
        // Prime Cup 2: Lv 100
        if(rental_cup_id[rental_id]==5){
            rental_pkm_level[rental_id]=100;
        }
    }
}


void MainWindow::randomize_rental_pkmn(std::mt19937 &mt_rand)
{
    // PRNG
    mt_rand.discard(700000);

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
                if(rental_pkm_level[rental_id]<pkm_min_level[pkm_ids_vector_rental_petitcup[index_vector_pkm+offset_vector_pkm]]){
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

        rental_pkm_id[rental_id] = pkm_ids_vector_rental_petitcup[index_vector_pkm];
        rental_pkm_nickname[rental_id] = pkm_name[pkm_ids_vector_rental_petitcup[index_vector_pkm]];

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_petitcup.begin(), pkm_ids_vector_rental_petitcup.end(), mt_rand);
        }
    }


    // Pika Cup: Lv 15 to Lv 20
    for(short rental_id = rental_cup_offset[1] ; rental_id < rental_cup_offset[2] ; rental_id++){
        bool not_legal_level = true;
        quint8 offset_vector_pkm = 0;
        quint8 index_vector_pkm = rental_id%7;

        while(not_legal_level){
            if((index_vector_pkm+offset_vector_pkm) < pkm_ids_vector_rental_pikacup.size()){
                if(rental_pkm_level[rental_id]<pkm_min_level[pkm_ids_vector_rental_pikacup[index_vector_pkm+offset_vector_pkm]]){
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

        rental_pkm_id[rental_id] = pkm_ids_vector_rental_pikacup[index_vector_pkm];
        rental_pkm_nickname[rental_id] = pkm_name[pkm_ids_vector_rental_pikacup[index_vector_pkm]];

        if(index_vector_pkm == 6){
            std::shuffle(pkm_ids_vector_rental_pikacup.begin(), pkm_ids_vector_rental_pikacup.end(), mt_rand);
        }
    }
}