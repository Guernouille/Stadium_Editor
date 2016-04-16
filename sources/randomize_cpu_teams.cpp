#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_init_pkmn(){
    bool no_mew_mewtwo = ui->checkBox_Randomizer_CPU_NoMewMewtwo->isChecked();

    pkm_ids_vector_petitcup.clear();
    pkm_ids_vector_petitcup_toptier.clear();
    pkm_ids_vector_petitcup_gambler.clear();
    pkm_ids_vector_pikacup.clear();
    pkm_ids_vector_pikacup_toptier.clear();
    pkm_ids_vector_primecup.clear();
    pkm_ids_vector_primecup_toptier.clear();
    pkm_ids_vector_pokecup.clear();
    pkm_ids_vector_pokecup_toptier.clear();

    // Petit Cup
    short pkm_list_petitcup[] = {1,4,7,16,19,21,23,25,27,32,35,37,39,43,46,50,52,54,58,60,63,66,69,74,81,83,90,92,98,100,102,104,109,116,118,133,138,140,147};
    pkm_ids_vector_petitcup.assign(pkm_list_petitcup,pkm_list_petitcup+(sizeof(pkm_list_petitcup)/sizeof(*pkm_list_petitcup)));
    if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked() == false){
        pkm_ids_vector_petitcup.push_back(10);
        pkm_ids_vector_petitcup.push_back(13);
        pkm_ids_vector_petitcup.push_back(29);
        pkm_ids_vector_petitcup.push_back(41);
        pkm_ids_vector_petitcup.push_back(129);
        pkm_ids_vector_petitcup.push_back(132);
    }
    short pkm_list_petitcup_toptier[] = {4,35,50,52,60,63,74,90,92,100,102};
    pkm_ids_vector_petitcup_toptier.assign(pkm_list_petitcup_toptier,pkm_list_petitcup_toptier+(sizeof(pkm_list_petitcup_toptier)/sizeof(*pkm_list_petitcup_toptier)));
    // Add Growlithe if Dragon Rage is allowed
    if(ui->checkBox_Randomizer_CPU_NoDragonRage->isChecked()==false && ui->checkBox_Randomizer_CPU_NoIllegalMoves->isChecked()){
        pkm_ids_vector_petitcup_toptier.push_back(58);
    }
    // TO DO: Generate Gambler Pokémon list depending on learned moves
    short pkm_list_petitcup_gambler[] = {23,27,32,35,50,63,66,74,90,92,98,100,102,104,109,118};
    pkm_ids_vector_petitcup_gambler.assign(pkm_list_petitcup_gambler,pkm_list_petitcup_gambler+(sizeof(pkm_list_petitcup_gambler)/sizeof(*pkm_list_petitcup_gambler)));


    // Pika Cup
    if(ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()){
        short pkm_list_pikacup[] = {2,5,8,12,15,17,20,22,26,31,34,36,38,40,47,51,55,59,62,65,68,73,76,80,87,89,91,94,95,99,101,103,106,107,108,112,113,114,115,117,121,122,123,124,127,130,131,137,148};
        pkm_ids_vector_pikacup.assign(pkm_list_pikacup,pkm_list_pikacup+(sizeof(pkm_list_pikacup)/sizeof(*pkm_list_pikacup)));
        if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_pikacup.push_back(83);
            pkm_ids_vector_pikacup.push_back(132);
        }
    }
    else{
        if(no_mew_mewtwo){
            for(short i=1;i<=total_pkm_name;i++){
                if(i!=10 && i!=11 && i!=13 && i!=14 && i!=29 && i!=41 && i!=43 && i!=48 && i!=83 && i!=129 && i!=132 && i!=150 && i!=151){
                    if(pkm_min_level[i]<=20) pkm_ids_vector_pikacup.push_back(i);
                }
            }
        }
        else{
            for(short i=1;i<=total_pkm_name;i++){
                if(i!=10 && i!=11 && i!=13 && i!=14 && i!=29 && i!=41 && i!=43 && i!=48 && i!=83 && i!=129 && i!=132){
                    if(pkm_min_level[i]<=20) pkm_ids_vector_pikacup.push_back(i);
                }
            }
        }
        if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_pikacup.push_back(10);
            pkm_ids_vector_pikacup.push_back(11);
            pkm_ids_vector_pikacup.push_back(13);
            pkm_ids_vector_pikacup.push_back(14);
            pkm_ids_vector_pikacup.push_back(29);
            pkm_ids_vector_pikacup.push_back(41);
            pkm_ids_vector_pikacup.push_back(43);
            pkm_ids_vector_pikacup.push_back(48);
            pkm_ids_vector_pikacup.push_back(83);
            pkm_ids_vector_pikacup.push_back(129);
            pkm_ids_vector_pikacup.push_back(132);
        }
    }
    short pkm_list_pikacup_toptier[] = {26,34,36,55,59,65,68,73,76,80,91,94,99,103,112,113,115,121,124,127,130,131};
    pkm_ids_vector_pikacup_toptier.assign(pkm_list_pikacup_toptier,pkm_list_pikacup_toptier+(sizeof(pkm_list_pikacup_toptier)/sizeof(*pkm_list_pikacup_toptier)));
    // TO DO: Generate Gambler Pokémon list depending on learned moves
    short pkm_list_pikacup_gambler[] = {31,34,36,51,62,65,68,76,80,87,89,91,94,95,97,99,101,103,108,112,113,115,122,124,125,126,127,131};
    pkm_ids_vector_pikacup_gambler.assign(pkm_list_pikacup_gambler,pkm_list_pikacup_gambler+(sizeof(pkm_list_pikacup_gambler)/sizeof(*pkm_list_pikacup_gambler)));


    // Prime Cup
    if(ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()){
        short pkm_list_primecup[] = {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_primecup.assign(pkm_list_primecup,pkm_list_primecup+(sizeof(pkm_list_primecup)/sizeof(*pkm_list_primecup)));
        if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_primecup.push_back(83);
            pkm_ids_vector_primecup.push_back(132);
        }
        pkm_ids_vector_primecup.push_back(150);
        pkm_ids_vector_primecup.push_back(151);
    }
    else if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked()){
        for(short i=1;i<=(total_pkm_name);i++){
            if(i!=10 || i!=11 || i!=13 || i!=14 || i!=29 || i!=41 || i!=48 || i!=129 || i!=132){
                pkm_ids_vector_primecup.push_back(i);
            }
        }
    }
    else{
        for(short i=1;i<=(total_pkm_name);i++){
            pkm_ids_vector_primecup.push_back(i);
        }
    }
    if(no_mew_mewtwo){
        pkm_ids_vector_primecup.pop_back();
        pkm_ids_vector_primecup.pop_back();
    }
    short pkm_list_primecup_toptier[] = {53,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149};
    pkm_ids_vector_primecup_toptier.assign(pkm_list_primecup_toptier,pkm_list_primecup_toptier+(sizeof(pkm_list_primecup_toptier)/sizeof(*pkm_list_primecup_toptier)));
    // TO DO: Generate Gambler Pokémon list depending on learned moves
    short pkm_list_primecup_gambler[] = {6,9,24,28,31,34,36,51,57,62,65,68,76,78,80,87,89,91,94,95,97,99,101,103,105,108,110,112,113,115,119,122,124,125,126,127,128,131,139,143,149};
    pkm_ids_vector_primecup_gambler.assign(pkm_list_primecup_gambler,pkm_list_primecup_gambler+(sizeof(pkm_list_primecup_gambler)/sizeof(*pkm_list_primecup_gambler)));
    if(no_mew_mewtwo==false){
        pkm_ids_vector_primecup_toptier.push_back(150);
        pkm_ids_vector_primecup_toptier.push_back(151);
        pkm_ids_vector_primecup_gambler.push_back(150);
        pkm_ids_vector_primecup_gambler.push_back(151);
    }

    // Poké Cup
    if(ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()){
        short pkm_list_pokecup[] = {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_pokecup.assign(pkm_list_pokecup,pkm_list_pokecup+(sizeof(pkm_list_pokecup)/sizeof(*pkm_list_pokecup)));
        if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_pokecup.push_back(83);
            pkm_ids_vector_pokecup.push_back(132);
        }
    }
    else{
        for(short i=1;i<=total_pkm_name;i++){
            if(pkm_min_level[i]<=55 && i!=150 && i!=151) pkm_ids_vector_pokecup.push_back(i);
        }
    }
    short pkm_list_pokecup_toptier[] = {53,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149};
    pkm_ids_vector_pokecup_toptier.assign(pkm_list_pokecup_toptier,pkm_list_pokecup_toptier+(sizeof(pkm_list_pokecup_toptier)/sizeof(*pkm_list_pokecup_toptier)));
    // TO DO: Generate Gambler Pokémon list depending on learned moves
    short pkm_list_pokecup_gambler[] = {6,9,24,28,31,34,36,51,57,62,65,68,76,78,80,87,89,91,94,95,97,99,101,103,105,108,110,112,113,115,119,122,124,125,126,127,128,131,139,143,149};
    pkm_ids_vector_pokecup_gambler.assign(pkm_list_pokecup_gambler,pkm_list_pokecup_gambler+(sizeof(pkm_list_pokecup_gambler)/sizeof(*pkm_list_pokecup_gambler)));


    // Vs Mewtwo
    if(ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()){
        short pkm_list_vs_mewtwo[] = {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149,151};
        pkm_ids_vector_vs_mewtwo.assign(pkm_list_vs_mewtwo,pkm_list_vs_mewtwo+(sizeof(pkm_list_vs_mewtwo)/sizeof(*pkm_list_vs_mewtwo)));
        if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked() == false){
            pkm_ids_vector_vs_mewtwo.push_back(83);
            pkm_ids_vector_vs_mewtwo.push_back(132);
        }
    }
    else if(ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked()){
        for(short i=1;i<=(total_pkm_name);i++){
            if(i!=10 || i!=11 || i!=13 || i!=14 || i!=29 || i!=41 || i!=48 || i!=129 || i!=132){
                pkm_ids_vector_vs_mewtwo.push_back(i);
            }
        }
    }
    else{
        for(short i=1;i<=(total_pkm_name);i++){
            pkm_ids_vector_vs_mewtwo.push_back(i);
        }
    }
    short pkm_list_vs_mewtwo_toptier[] = {53,62,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149,151};
    pkm_ids_vector_vs_mewtwo_toptier.assign(pkm_list_vs_mewtwo_toptier,pkm_list_vs_mewtwo_toptier+(sizeof(pkm_list_vs_mewtwo_toptier)/sizeof(*pkm_list_vs_mewtwo_toptier)));
}


void MainWindow::randomize_cpu_level()
{
    // PRNG
    std::seed_seq seeds{prng_seed[0], prng_seed[1], prng_seed[2], prng_seed[3], prng_seed[4], prng_seed[5]};
    std::mt19937 mt_rand(seeds);
    mt_rand.discard(700000);


    // CPU Levels generation
    for(short cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        cpu_party_size[cpu_trainer_id]=6;

        // Petit Cup: Lv 25 to Lv 30
        if(cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==22){
            std::uniform_int_distribution<> distrib1(25,30);
            std::uniform_int_distribution<> distrib2(25,29);
            std::uniform_int_distribution<> distrib3(25,28);
            std::uniform_int_distribution<> distrib4(25,27);
            std::uniform_int_distribution<> distrib5(25,26);

            for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                if(i==0 || i==3) cpu_pkm_level[cpu_trainer_id][i] = distrib1(mt_rand);
                else if(i==1 || i==4){
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==25) cpu_pkm_level[cpu_trainer_id][i] = distrib1(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==26) cpu_pkm_level[cpu_trainer_id][i] = distrib2(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==27) cpu_pkm_level[cpu_trainer_id][i] = distrib3(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==28) cpu_pkm_level[cpu_trainer_id][i] = distrib4(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==29) cpu_pkm_level[cpu_trainer_id][i] = distrib5(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==30) cpu_pkm_level[cpu_trainer_id][i] = 25;
                }
                else if(i==2 || i==5){
                    cpu_pkm_level[cpu_trainer_id][i] = 80-cpu_pkm_level[cpu_trainer_id][i-1];
                    cpu_pkm_level[cpu_trainer_id][i] -= cpu_pkm_level[cpu_trainer_id][i-2];
                }
            }
        }

        // Pika Cup: Lv 15 to Lv 20
        else if(cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==23){
            std::uniform_int_distribution<> distrib1(15,20);
            std::uniform_int_distribution<> distrib2(15,19);
            std::uniform_int_distribution<> distrib3(15,18);
            std::uniform_int_distribution<> distrib4(15,17);
            std::uniform_int_distribution<> distrib5(15,16);

            for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                if(i==0 || i==3) cpu_pkm_level[cpu_trainer_id][i] = distrib1(mt_rand);
                else if(i==1 || i==4){
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==15) cpu_pkm_level[cpu_trainer_id][i] = distrib1(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==16) cpu_pkm_level[cpu_trainer_id][i] = distrib2(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==17) cpu_pkm_level[cpu_trainer_id][i] = distrib3(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==18) cpu_pkm_level[cpu_trainer_id][i] = distrib4(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==19) cpu_pkm_level[cpu_trainer_id][i] = distrib5(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==20) cpu_pkm_level[cpu_trainer_id][i] = 15;
                }
                else if(i==2 || i==5){
                    cpu_pkm_level[cpu_trainer_id][i] = 50-cpu_pkm_level[cpu_trainer_id][i-1];
                    cpu_pkm_level[cpu_trainer_id][i] -= cpu_pkm_level[cpu_trainer_id][i-2];
                }
            }
        }

        // Prime Cup: Lv 100
        else if((cpu_cup_id[cpu_trainer_id]>=2 && cpu_cup_id[cpu_trainer_id]<=5) || (cpu_cup_id[cpu_trainer_id]>=24 && cpu_cup_id[cpu_trainer_id]<=27)){
            for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                cpu_pkm_level[cpu_trainer_id][i] = 100;
            }
        }

        // Poké Cup: Lv 50 to Lv 55
        else if((cpu_cup_id[cpu_trainer_id]>=6 && cpu_cup_id[cpu_trainer_id]<=9) || (cpu_cup_id[cpu_trainer_id]>=28 && cpu_cup_id[cpu_trainer_id]<=31)){
            std::uniform_int_distribution<> distrib1(50,55);
            std::uniform_int_distribution<> distrib2(50,54);
            std::uniform_int_distribution<> distrib3(50,53);
            std::uniform_int_distribution<> distrib4(50,52);
            std::uniform_int_distribution<> distrib5(50,51);

            for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                if(i==0 || i==3) cpu_pkm_level[cpu_trainer_id][i] = distrib1(mt_rand);
                else if(i==1 || i==4){
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==50) cpu_pkm_level[cpu_trainer_id][i] = distrib1(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==51) cpu_pkm_level[cpu_trainer_id][i] = distrib2(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==52) cpu_pkm_level[cpu_trainer_id][i] = distrib3(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==53) cpu_pkm_level[cpu_trainer_id][i] = distrib4(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==54) cpu_pkm_level[cpu_trainer_id][i] = distrib5(mt_rand);
                    if(cpu_pkm_level[cpu_trainer_id][i-1]==55) cpu_pkm_level[cpu_trainer_id][i] = 50;
                }
                else if(i==2 || i==5){
                    cpu_pkm_level[cpu_trainer_id][i] = 155-cpu_pkm_level[cpu_trainer_id][i-1];
                    cpu_pkm_level[cpu_trainer_id][i] -= cpu_pkm_level[cpu_trainer_id][i-2];
                }
            }
        }

        // Gym Leader Castle: User-specified Lv range
        else if((cpu_cup_id[cpu_trainer_id]>=10 && cpu_cup_id[cpu_trainer_id]<=19) || (cpu_cup_id[cpu_trainer_id]>=32 && cpu_cup_id[cpu_trainer_id]<=41)){
            if(glc_level_min != glc_level_max){
                std::uniform_int_distribution<> distrib(glc_level_min,glc_level_max);
                for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                    cpu_pkm_level[cpu_trainer_id][i] = distrib(mt_rand);
                }
            }
            else{
                for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                    cpu_pkm_level[cpu_trainer_id][i] = glc_level_min;
                }
            }
        }

        // Vs Mewtwo: Lv 100
        else if(cpu_cup_id[cpu_trainer_id] == 20 || cpu_cup_id[cpu_trainer_id] == 42){
            if(ui->checkBox_Randomizer_CPU_MewtwoFullParty->isChecked() == false){
                cpu_party_size[cpu_trainer_id] = 1;
            }
            for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                cpu_pkm_level[cpu_trainer_id][i] = 100;
            }
        }

        // Battle Now: Lv 50
        else if(cpu_cup_id[cpu_trainer_id]==21 || cpu_cup_id[cpu_trainer_id]==43){
            for(short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                cpu_pkm_level[cpu_trainer_id][i] = 50;
            }
        }
    }

    prng_seed[0] = mt_rand();
    prng_seed[1] = mt_rand();
    prng_seed[2] = mt_rand();
    prng_seed[3] = mt_rand();
    prng_seed[4] = mt_rand();
    prng_seed[5] = mt_rand();
}


void MainWindow::randomize_cpu_moves()
{
    // PRNG
    std::seed_seq seeds{prng_seed[0], prng_seed[1], prng_seed[2], prng_seed[3], prng_seed[4], prng_seed[5]};
    std::mt19937 mt_rand(seeds);
    mt_rand.discard(700000);

    bool no_illegal_moves = ui->checkBox_Randomizer_CPU_NoIllegalMoves->isChecked();
    bool no_useless_moves = ui->checkBox_Randomizer_CPU_NoUselessMoves->isChecked();
    bool no_weak_moves = ui->checkBox_Randomizer_CPU_NoWeakMoves->isChecked();
    bool no_dragon_rage = ui->checkBox_Randomizer_CPU_NoDragonRage->isChecked();
    bool no_evasion_moves = ui->checkBox_Randomizer_CPU_NoEvasion->isChecked();
    bool have_offensive_move = ui->checkBox_Randomizer_CPU_OffensiveMove->isChecked();
    bool have_stab_move = ui->checkBox_Randomizer_CPU_STABMove->isChecked();
    bool gambler_luck_moves = ui->checkBox_Randomizer_CPU_GamblerMoves->isChecked();

    for(short cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
            moves_ids_vector.clear();
            strong_moves_ids_vector.clear();
            gambler_moves_ids_vector.clear();
            buf8 = cpu_pkm_id[cpu_trainer_id][i];

            // Starting Moves
            if(pkm_start_move_1[buf8]>0 && pkm_start_move_1[buf8]<total_move_name){
                if(pkm_start_move_1[buf8]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                    moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    strong_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                }
                else if(no_weak_moves==false || weak_move[pkm_start_move_1[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_1[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                }
                if(strong_move[pkm_start_move_1[buf8]] || (move_type[pkm_start_move_1[buf8]]==pkm_type_1[buf8] && move_power[pkm_start_move_1[buf8]]>=75) || (move_type[pkm_start_move_1[buf8]]== pkm_type_2[buf8] && move_power[pkm_start_move_1[buf8]]>=75)){
                    strong_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                }
                if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                    if((move_effect[pkm_start_move_1[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_1[buf8]]==7 || move_effect[pkm_start_move_1[buf8]]==0x24 || move_effect[pkm_start_move_1[buf8]]==0x26 || move_effect[pkm_start_move_1[buf8]]==0x34 || move_effect[pkm_start_move_1[buf8]]==0x43 || (move_effect[pkm_start_move_1[buf8]]==0x46 && move_power[pkm_start_move_1[buf8]]>=65) || move_effect[pkm_start_move_1[buf8]]==0x53 || (pkm_start_move_1[buf8]==95 && no_weak_moves==false)){
                        gambler_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                    else if(move_accuracy[pkm_start_move_1[buf8]]<=0xD8 && move_power[pkm_start_move_1[buf8]]>=100 && (move_type[pkm_start_move_1[buf8]]>8 || pkm_base_atk[buf8]>50 || move_type[pkm_start_move_1[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_1[buf8]]==pkm_type_2[buf8])){
                        gambler_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                    else if(pkm_start_move_1[buf8]==move_high_ch[0] || pkm_start_move_1[buf8]==move_high_ch[1] || pkm_start_move_1[buf8]==move_high_ch[2] || pkm_start_move_1[buf8]==move_high_ch[3]){
                        gambler_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                }
            }
            if(pkm_start_move_2[buf8]>0 && pkm_start_move_2[buf8]<total_move_name){
                if(pkm_start_move_2[buf8]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                    moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    strong_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                }
                if(no_weak_moves==false || weak_move[pkm_start_move_2[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_2[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                }
                if(strong_move[pkm_start_move_2[buf8]] || (move_type[pkm_start_move_2[buf8]]== pkm_type_1[buf8] && move_power[pkm_start_move_2[buf8]]>=75) || (move_type[pkm_start_move_2[buf8]]== pkm_type_2[buf8] && move_power[pkm_start_move_2[buf8]]>=75)){
                    strong_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                }
                if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                    if((move_effect[pkm_start_move_2[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_2[buf8]]==7 || move_effect[pkm_start_move_2[buf8]]==0x24 || move_effect[pkm_start_move_2[buf8]]==0x26 || move_effect[pkm_start_move_2[buf8]]==0x34 || move_effect[pkm_start_move_2[buf8]]==0x43 || (move_effect[pkm_start_move_2[buf8]]==0x46 && move_power[pkm_start_move_2[buf8]]>=65) || move_effect[pkm_start_move_2[buf8]]==0x53 || (pkm_start_move_2[buf8]==95 && no_weak_moves==false)){
                        gambler_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                    else if(move_accuracy[pkm_start_move_2[buf8]]<=0xD8 && move_power[pkm_start_move_2[buf8]]>=100 && (move_type[pkm_start_move_2[buf8]]>8 || pkm_base_atk[buf8]>50 || move_type[pkm_start_move_2[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_2[buf8]]==pkm_type_2[buf8])){
                        gambler_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                    else if(pkm_start_move_2[buf8]==move_high_ch[0] || pkm_start_move_2[buf8]==move_high_ch[1] || pkm_start_move_2[buf8]==move_high_ch[2] || pkm_start_move_2[buf8]==move_high_ch[3]){
                        gambler_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                }
            }
            if(pkm_start_move_3[buf8]>0 && pkm_start_move_3[buf8]<total_move_name){
                if(pkm_start_move_3[buf8]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                    moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    strong_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                }
                if(no_weak_moves==false || weak_move[pkm_start_move_3[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_3[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                }
                if(strong_move[pkm_start_move_3[buf8]] || (move_type[pkm_start_move_3[buf8]]== pkm_type_1[buf8] && move_power[pkm_start_move_3[buf8]]>=75) || (move_type[pkm_start_move_3[buf8]]== pkm_type_2[buf8] && move_power[pkm_start_move_3[buf8]]>=75)){
                    strong_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                }
                if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                    if((move_effect[pkm_start_move_3[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_3[buf8]]==7 || move_effect[pkm_start_move_3[buf8]]==0x24 || move_effect[pkm_start_move_3[buf8]]==0x26 || move_effect[pkm_start_move_3[buf8]]==0x34 || move_effect[pkm_start_move_3[buf8]]==0x43 || (move_effect[pkm_start_move_3[buf8]]==0x46 && move_power[pkm_start_move_3[buf8]]>=65) || move_effect[pkm_start_move_3[buf8]]==0x53 || (pkm_start_move_3[buf8]==95 && no_weak_moves==false)){
                        gambler_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                    else if(move_accuracy[pkm_start_move_3[buf8]]<=0xD8 && move_power[pkm_start_move_3[buf8]]>=100 && (move_type[pkm_start_move_3[buf8]]>8 || pkm_base_atk[buf8]>50 || move_type[pkm_start_move_3[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_3[buf8]]==pkm_type_2[buf8])){
                        gambler_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                    else if(pkm_start_move_3[buf8]==move_high_ch[0] || pkm_start_move_3[buf8]==move_high_ch[1] || pkm_start_move_3[buf8]==move_high_ch[2] || pkm_start_move_3[buf8]==move_high_ch[3]){
                        gambler_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                }
            }
            if(pkm_start_move_4[buf8]>0 && pkm_start_move_4[buf8]<total_move_name){
                if(pkm_start_move_4[buf8]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                    moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    strong_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                }
                if(no_weak_moves==false || weak_move[pkm_start_move_4[buf8]]==false){
                    if(no_useless_moves==false || useless_move[pkm_start_move_4[buf8]]==false){
                        moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                }
                if(strong_move[pkm_start_move_4[buf8]] || (move_type[pkm_start_move_4[buf8]]== pkm_type_1[buf8] && move_power[pkm_start_move_4[buf8]]>=75) || (move_type[pkm_start_move_4[buf8]]== pkm_type_2[buf8] && move_power[pkm_start_move_4[buf8]]>=75)){
                    strong_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                }
                if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                    if((move_effect[pkm_start_move_4[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_4[buf8]]==7 || move_effect[pkm_start_move_4[buf8]]==0x24 || move_effect[pkm_start_move_4[buf8]]==0x26 || move_effect[pkm_start_move_4[buf8]]==0x34 || move_effect[pkm_start_move_4[buf8]]==0x43 || (move_effect[pkm_start_move_4[buf8]]==0x46 && move_power[pkm_start_move_4[buf8]]>=65) || move_effect[pkm_start_move_4[buf8]]==0x53 || (pkm_start_move_4[buf8]==95 && no_weak_moves==false)){
                        gambler_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                    else if(move_accuracy[pkm_start_move_4[buf8]]<=0xD8 && move_power[pkm_start_move_4[buf8]]>=100 && (move_type[pkm_start_move_4[buf8]]>8 || pkm_base_atk[buf8]>50 || move_type[pkm_start_move_4[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_4[buf8]]==pkm_type_2[buf8])){
                        gambler_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                    else if(pkm_start_move_4[buf8]==move_high_ch[0] || pkm_start_move_4[buf8]==move_high_ch[1] || pkm_start_move_4[buf8]==move_high_ch[2] || pkm_start_move_4[buf8]==move_high_ch[3]){
                        gambler_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                }
            }

            // TM HM Moves
            for(short j=1;j<56;j++){
                if(move_tmhm[j]>0 && move_tmhm[j]<total_move_name){
                    move_tmhm_flag = (j-1)%8;
                    move_tmhm_byte = (j-1)/8;
                    if((1<<move_tmhm_flag) & pkm_tmhm_flags[buf8][move_tmhm_byte]){
                        if(move_tmhm[j]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                            moves_ids_vector.push_back(move_tmhm[j]);
                            strong_moves_ids_vector.push_back(move_tmhm[j]);
                        }
                        if(no_weak_moves==false || weak_move[move_tmhm[j]]==false){
                            if(no_useless_moves==false || useless_move[move_tmhm[j]]==false){
                                moves_ids_vector.push_back(move_tmhm[j]);
                            }
                        }
                        if(strong_move[move_tmhm[j]] || (move_type[move_tmhm[j]]== pkm_type_1[buf8] && move_power[move_tmhm[j]]>=75) || (move_type[move_tmhm[j]]== pkm_type_2[buf8] && move_power[move_tmhm[j]]>=75)){
                            strong_moves_ids_vector.push_back(move_tmhm[j]);
                        }
                        if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                            if((move_effect[move_tmhm[j]]==0xF && no_evasion_moves==false) || move_effect[move_tmhm[j]]==7 || move_effect[move_tmhm[j]]==0x24 || move_effect[move_tmhm[j]]==0x26 || move_effect[move_tmhm[j]]==0x34 || move_effect[move_tmhm[j]]==0x43 || (move_effect[move_tmhm[j]]==0x46 && move_power[move_tmhm[j]]>=65) || move_effect[move_tmhm[j]]==0x53 || (move_tmhm[j]==95 && no_weak_moves==false)){
                                gambler_moves_ids_vector.push_back(move_tmhm[j]);
                            }
                            else if(move_accuracy[move_tmhm[j]]<=0xD8 && move_power[move_tmhm[j]]>=100 && (move_type[move_tmhm[j]]>8 || pkm_base_atk[buf8]>50 || move_type[move_tmhm[j]]==pkm_type_1[buf8] || move_type[move_tmhm[j]]==pkm_type_2[buf8])){
                                gambler_moves_ids_vector.push_back(move_tmhm[j]);
                            }
                            else if(move_tmhm[j]==move_high_ch[0] || move_tmhm[j]==move_high_ch[1] || move_tmhm[j]==move_high_ch[2] || move_tmhm[j]==move_high_ch[3]){
                                gambler_moves_ids_vector.push_back(move_tmhm[j]);
                            }
                        }
                    }
                }
            }

            // Level-up Moves
            for(short j=0;j<10;j++){
                if(pkm_rb_move[buf8][j]>0 && pkm_rb_move[buf8][j]<total_move_name && pkm_rb_lvl[buf8][j]<=cpu_pkm_level[cpu_trainer_id][i]){
                    if(pkm_rb_move[buf8][j]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                        moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        strong_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                    }
                    if(no_weak_moves==false || weak_move[pkm_rb_move[buf8][j]]==false){
                        if(no_useless_moves==false || useless_move[pkm_rb_move[buf8][j]]==false){
                            moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                    }
                    if(strong_move[pkm_rb_move[buf8][j]] || (move_type[pkm_rb_move[buf8][j]]== pkm_type_1[buf8] && move_power[pkm_rb_move[buf8][j]]>=75) || (move_type[pkm_rb_move[buf8][j]]== pkm_type_2[buf8] && move_power[pkm_rb_move[buf8][j]]>=75)){
                        strong_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                    }
                    if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                        if((move_effect[pkm_rb_move[buf8][j]]==0xF && no_evasion_moves==false) || move_effect[pkm_rb_move[buf8][j]]==7 || move_effect[pkm_rb_move[buf8][j]]==0x24 || move_effect[pkm_rb_move[buf8][j]]==0x26 || move_effect[pkm_rb_move[buf8][j]]==0x34 || move_effect[pkm_rb_move[buf8][j]]==0x43 || (move_effect[pkm_rb_move[buf8][j]]==0x46 && move_power[pkm_rb_move[buf8][j]]>=65) || move_effect[pkm_rb_move[buf8][j]]==0x53 || (pkm_rb_move[buf8][j]==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                        else if(move_accuracy[pkm_rb_move[buf8][j]]<=0xD8 && move_power[pkm_rb_move[buf8][j]]>=100 && (move_type[pkm_rb_move[buf8][j]]>8 || pkm_base_atk[buf8]>50 || move_type[pkm_rb_move[buf8][j]]==pkm_type_1[buf8] || move_type[pkm_rb_move[buf8][j]]==pkm_type_2[buf8])){
                            gambler_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                        else if(pkm_rb_move[buf8][j]==move_high_ch[0] || pkm_rb_move[buf8][j]==move_high_ch[1] || pkm_rb_move[buf8][j]==move_high_ch[2] || pkm_rb_move[buf8][j]==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                    }
                }
                if(pkm_y_move[buf8][j]>0 && pkm_y_move[buf8][j]<total_move_name && pkm_y_lvl[buf8][j]<=cpu_pkm_level[cpu_trainer_id][i]){
                    if(pkm_y_move[buf8][j]==0x52 && no_dragon_rage==false && (cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==22 || cpu_cup_id[cpu_trainer_id]==23)){
                        moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        strong_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                    }
                    if(no_weak_moves==false || weak_move[pkm_y_move[buf8][j]]==false){
                        if(no_useless_moves==false || useless_move[pkm_y_move[buf8][j]]==false){
                            moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        }
                    }
                    if(strong_move[pkm_y_move[buf8][j]] || (move_type[pkm_y_move[buf8][j]]== pkm_type_1[buf8] && move_power[pkm_y_move[buf8][j]]>=75) || (move_type[pkm_y_move[buf8][j]]== pkm_type_2[buf8] && move_power[pkm_y_move[buf8][j]]>=75)){
                        strong_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                    }
                    if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                        if((move_effect[pkm_y_move[buf8][j]]==0xF && no_evasion_moves==false) || move_effect[pkm_y_move[buf8][j]]==7 || move_effect[pkm_y_move[buf8][j]]==0x24 || move_effect[pkm_y_move[buf8][j]]==0x26 || move_effect[pkm_y_move[buf8][j]]==0x34 || move_effect[pkm_y_move[buf8][j]]==0x43 || (move_effect[pkm_y_move[buf8][j]]==0x46 && move_power[pkm_y_move[buf8][j]]>=65) || move_effect[pkm_y_move[buf8][j]]==0x53 || (pkm_y_move[buf8][j]==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        }
                        else if(move_accuracy[pkm_y_move[buf8][j]]<=0xD8 && move_power[pkm_y_move[buf8][j]]>=100 && (move_type[pkm_y_move[buf8][j]]>8 || pkm_base_atk[buf8]>50 || move_type[pkm_y_move[buf8][j]]==pkm_type_1[buf8] || move_type[pkm_y_move[buf8][j]]==pkm_type_2[buf8])){
                            gambler_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        }
                        else if(pkm_y_move[buf8][j]==move_high_ch[0] || pkm_y_move[buf8][j]==move_high_ch[1] || pkm_y_move[buf8][j]==move_high_ch[2] || pkm_y_move[buf8][j]==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
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
            if(strong_moves_ids_vector.size()>0){
                sort(strong_moves_ids_vector.begin(), strong_moves_ids_vector.end());
                strong_moves_ids_vector.erase(std::unique(strong_moves_ids_vector.begin(), strong_moves_ids_vector.end()), strong_moves_ids_vector.end());
            }
            if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && gambler_moves_ids_vector.size()>0){
                sort(gambler_moves_ids_vector.begin(), gambler_moves_ids_vector.end());
                gambler_moves_ids_vector.erase(std::unique(gambler_moves_ids_vector.begin(), gambler_moves_ids_vector.end()), gambler_moves_ids_vector.end());
            }


            // Randomize Pokémon Moves
            // TO DO: Force offensive move / STAB move
            if(moves_ids_vector.size()>0) std::shuffle(moves_ids_vector.begin(), moves_ids_vector.end(), mt_rand);
            if(strong_moves_ids_vector.size()>0) std::shuffle(strong_moves_ids_vector.begin(), strong_moves_ids_vector.end(), mt_rand);
            if(gambler_moves_ids_vector.size()>0) std::shuffle(gambler_moves_ids_vector.begin(), gambler_moves_ids_vector.end(), mt_rand);

            if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22){
                if(gambler_moves_ids_vector.size()>0) cpu_pkm_move_1[cpu_trainer_id][i] = gambler_moves_ids_vector[0];
                else if(moves_ids_vector.size()>0) cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[0];
                else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
                     cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[buf8];
                }
                else cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                if(gambler_moves_ids_vector.size()>1) cpu_pkm_move_2[cpu_trainer_id][i] = gambler_moves_ids_vector[1];
                else cpu_pkm_move_2[cpu_trainer_id][i] = 0;
                if(gambler_moves_ids_vector.size()>2) cpu_pkm_move_3[cpu_trainer_id][i] = gambler_moves_ids_vector[2];
                else cpu_pkm_move_3[cpu_trainer_id][i] = 0;
                if(gambler_moves_ids_vector.size()>3) cpu_pkm_move_4[cpu_trainer_id][i] = gambler_moves_ids_vector[3];
                else cpu_pkm_move_4[cpu_trainer_id][i] = 0;
            }
            else if(cpu_trainer_id==7 || cpu_trainer_id==15 || cpu_trainer_id==47 || cpu_trainer_id==71 || cpu_trainer_id==79 || cpu_trainer_id==133 || cpu_trainer_id==141 || cpu_trainer_id==173 || cpu_trainer_id==197 || cpu_trainer_id==205 || cpu_cup_id[cpu_trainer_id]==18 || cpu_cup_id[cpu_trainer_id]==19 || cpu_cup_id[cpu_trainer_id]==20 || cpu_cup_id[cpu_trainer_id]==40 || cpu_cup_id[cpu_trainer_id]==41 || cpu_cup_id[cpu_trainer_id]==42){
                if(strong_moves_ids_vector.size()>0) cpu_pkm_move_1[cpu_trainer_id][i] = strong_moves_ids_vector[0];
                else if(moves_ids_vector.size()>0) cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[0];
                else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
                     cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[buf8];
                }
                else cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                if(strong_moves_ids_vector.size()>1) cpu_pkm_move_2[cpu_trainer_id][i] = strong_moves_ids_vector[1];
                else if(moves_ids_vector.size()>1) cpu_pkm_move_2[cpu_trainer_id][i] = moves_ids_vector[1];
                else cpu_pkm_move_2[cpu_trainer_id][i] = 0;
                if(strong_moves_ids_vector.size()>2) cpu_pkm_move_3[cpu_trainer_id][i] = strong_moves_ids_vector[2];
                else if(moves_ids_vector.size()>2) cpu_pkm_move_3[cpu_trainer_id][i] = moves_ids_vector[2];
                else cpu_pkm_move_3[cpu_trainer_id][i] = 0;
                if(strong_moves_ids_vector.size()>3) cpu_pkm_move_4[cpu_trainer_id][i] = strong_moves_ids_vector[3];
                else if(moves_ids_vector.size()>3) cpu_pkm_move_4[cpu_trainer_id][i] = moves_ids_vector[3];
                else cpu_pkm_move_4[cpu_trainer_id][i] = 0;
            }
            else{
                if(moves_ids_vector.size()>0) cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[0];
                else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
                     cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[buf8];
                }
                else cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                if(moves_ids_vector.size()>1) cpu_pkm_move_2[cpu_trainer_id][i] = moves_ids_vector[1];
                else cpu_pkm_move_2[cpu_trainer_id][i] = 0;
                if(moves_ids_vector.size()>2) cpu_pkm_move_3[cpu_trainer_id][i] = moves_ids_vector[2];
                else cpu_pkm_move_3[cpu_trainer_id][i] = 0;
                if(moves_ids_vector.size()>3) cpu_pkm_move_4[cpu_trainer_id][i] = moves_ids_vector[3];
                else cpu_pkm_move_4[cpu_trainer_id][i] = 0;
            }
        }
    }

    prng_seed[0] = mt_rand();
    prng_seed[1] = mt_rand();
    prng_seed[2] = mt_rand();
    prng_seed[3] = mt_rand();
    prng_seed[4] = mt_rand();
    prng_seed[5] = mt_rand();
}


void MainWindow::randomize_cpu_pkmn()
{
    // PRNG
    std::seed_seq seeds{prng_seed[0], prng_seed[1], prng_seed[2], prng_seed[3], prng_seed[4], prng_seed[5]};
    std::mt19937 mt_rand(seeds);
    mt_rand.discard(700000);

    bool strong_pkm_finals = ui->checkBox_Randomizer_CPU_StrongPkmnFinal->isChecked();
    bool gambler_luck_moves = ui->checkBox_Randomizer_CPU_GamblerMoves->isChecked();


    // CPU Teams generation
    for(short cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        cpu_party_size[cpu_trainer_id]=6;

        // Petit Cup
        if(cpu_cup_id[cpu_trainer_id]==0 || cpu_cup_id[cpu_trainer_id]==22){
            std::shuffle(pkm_ids_vector_petitcup.begin(), pkm_ids_vector_petitcup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_petitcup_toptier.begin(), pkm_ids_vector_petitcup_toptier.end(), mt_rand);
            if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_petitcup_gambler.begin(), pkm_ids_vector_petitcup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                quint8 offset_vector_pkm = 0;

                // Petit Cup Final
                if((cpu_trainer_id==7 || cpu_trainer_id==133) && strong_pkm_finals){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_petitcup_toptier[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_petitcup_toptier.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_petitcup_toptier[i];
                    pkm_ids_vector_petitcup_toptier[i]=pkm_ids_vector_petitcup_toptier[i+offset_vector_pkm];
                    pkm_ids_vector_petitcup_toptier[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_petitcup_toptier[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_petitcup_toptier[i]];
                }
                // Gambler
                else if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_petitcup_gambler[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_petitcup_gambler.size())){
                        offset_vector_pkm++;
                    }
                    if(offset_vector_pkm > 0){
                        buf8=pkm_ids_vector_petitcup_gambler[i];
                        pkm_ids_vector_petitcup_gambler[i]=pkm_ids_vector_petitcup_gambler[i+offset_vector_pkm];
                        pkm_ids_vector_petitcup_gambler[i+offset_vector_pkm]=buf8;
                    }
                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_petitcup_gambler[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_petitcup_gambler[i]];
                }
                // Other trainers
                else{
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_petitcup[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_petitcup.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_petitcup[i];
                    pkm_ids_vector_petitcup[i]=pkm_ids_vector_petitcup[i+offset_vector_pkm];
                    pkm_ids_vector_petitcup[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_petitcup[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_petitcup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }



        // Pika Cup
        else if(cpu_cup_id[cpu_trainer_id]==1 || cpu_cup_id[cpu_trainer_id]==23){
            std::shuffle(pkm_ids_vector_pikacup.begin(), pkm_ids_vector_pikacup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_pikacup_toptier.begin(), pkm_ids_vector_pikacup_toptier.end(), mt_rand);
            if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_pikacup_gambler.begin(), pkm_ids_vector_pikacup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                quint8 offset_vector_pkm = 0;

                // Pika Cup Final
                if((cpu_trainer_id==15 || cpu_trainer_id==141) && strong_pkm_finals){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_pikacup_toptier[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_pikacup_toptier.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_pikacup_toptier[i];
                    pkm_ids_vector_pikacup_toptier[i]=pkm_ids_vector_pikacup_toptier[i+offset_vector_pkm];
                    pkm_ids_vector_pikacup_toptier[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_pikacup_toptier[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_pikacup_toptier[i]];
                }
                // Gambler
                else if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_pikacup_gambler.size()>0){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_pikacup_gambler[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_pikacup_gambler.size())){
                        offset_vector_pkm++;
                    }
                    if(offset_vector_pkm > 0){
                        buf8=pkm_ids_vector_pikacup_gambler[i];
                        pkm_ids_vector_pikacup_gambler[i]=pkm_ids_vector_pikacup_gambler[i+offset_vector_pkm];
                        pkm_ids_vector_pikacup_gambler[i+offset_vector_pkm]=buf8;
                    }
                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_pikacup_gambler[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_pikacup_gambler[i]];
                }
                // Other trainers
                else{
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_pikacup[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_pikacup.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_pikacup[i];
                    pkm_ids_vector_pikacup[i]=pkm_ids_vector_pikacup[i+offset_vector_pkm];
                    pkm_ids_vector_pikacup[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_pikacup[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_pikacup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }



        // Prime Cup
        else if((cpu_cup_id[cpu_trainer_id]>=2 && cpu_cup_id[cpu_trainer_id]<=5) || (cpu_cup_id[cpu_trainer_id]>=24 && cpu_cup_id[cpu_trainer_id]<=27)){
            std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_primecup_toptier.begin(), pkm_ids_vector_primecup_toptier.end(), mt_rand);
            if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_primecup_gambler.begin(), pkm_ids_vector_primecup_gambler.end(), mt_rand);
            }


            // Change Pokémon team
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                // Prime Cup Final (Mew check)
                if(cpu_trainer_id==47 || cpu_trainer_id==173){
                    if(i==0 && ui->checkBox_Randomizer_CPU_MewPrimeCup->isChecked()){
                        cpu_pkm_id[cpu_trainer_id][i] = 151;
                        cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[151];
                    }
                    else if(strong_pkm_finals){
                        if(pkm_ids_vector_primecup_toptier[i] != 151){
                            cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup_toptier[i];
                            cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup_toptier[i]];
                        }
                        else{
                            cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup_toptier.back();
                            cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup_toptier.back()];
                        }
                    }
                    else{
                        if(pkm_ids_vector_primecup[i] != 151){
                            cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup[i];
                            cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup[i]];
                        }
                        else{
                            cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup.back();
                            cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup.back()];
                        }
                    }
                }
                // Gambler
                else if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_primecup_gambler.size()>0){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_primecup_gambler[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_primecup_gambler.size())){
                        offset_vector_pkm++;
                    }
                    if(offset_vector_pkm > 0){
                        buf8=pkm_ids_vector_primecup_gambler[i];
                        pkm_ids_vector_primecup_gambler[i]=pkm_ids_vector_primecup_gambler[i+offset_vector_pkm];
                        pkm_ids_vector_primecup_gambler[i+offset_vector_pkm]=buf8;
                    }
                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup_gambler[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup_gambler[i]];
                }
                // Other trainers
                else{
                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }



        // Poké Cup
        else if((cpu_cup_id[cpu_trainer_id]>=6 && cpu_cup_id[cpu_trainer_id]<=9) || (cpu_cup_id[cpu_trainer_id]>=28 && cpu_cup_id[cpu_trainer_id]<=31)){
            std::shuffle(pkm_ids_vector_pokecup.begin(), pkm_ids_vector_pokecup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_pokecup_toptier.begin(), pkm_ids_vector_pokecup_toptier.end(), mt_rand);
            if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_pokecup_gambler.begin(), pkm_ids_vector_pokecup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                quint8 offset_vector_pkm = 0;
                // Poké Cup Final
                if((cpu_trainer_id==71 || cpu_trainer_id==79 || cpu_trainer_id==197 || cpu_trainer_id==205) && strong_pkm_finals){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_pokecup_toptier[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_pokecup_toptier.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_pokecup_toptier[i];
                    pkm_ids_vector_pokecup_toptier[i]=pkm_ids_vector_pokecup_toptier[i+offset_vector_pkm];
                    pkm_ids_vector_pokecup_toptier[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_pokecup_toptier[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_pokecup_toptier[i]];
                }
                // Gambler
                else if(gambler_luck_moves && cpu_sprite_id[cpu_trainer_id]==0x22 && pkm_ids_vector_pokecup_gambler.size()>0){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_pokecup_gambler[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_pokecup_gambler.size())){
                        offset_vector_pkm++;
                    }
                    if(offset_vector_pkm > 0){
                        buf8=pkm_ids_vector_pokecup_gambler[i];
                        pkm_ids_vector_pokecup_gambler[i]=pkm_ids_vector_pokecup_gambler[i+offset_vector_pkm];
                        pkm_ids_vector_pokecup_gambler[i+offset_vector_pkm]=buf8;
                    }
                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_pokecup_gambler[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_pokecup_gambler[i]];
                }
                // Other trainers
                else{
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_pokecup[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_pokecup.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_pokecup[i];
                    pkm_ids_vector_pokecup[i]=pkm_ids_vector_pokecup[i+offset_vector_pkm];
                    pkm_ids_vector_pokecup[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_pokecup[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_pokecup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }



        // Gym Leader Castle
        else if((cpu_cup_id[cpu_trainer_id]>=10 && cpu_cup_id[cpu_trainer_id]<=19) || (cpu_cup_id[cpu_trainer_id]>=32 && cpu_cup_id[cpu_trainer_id]<=41)){
            std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_primecup_toptier.begin(), pkm_ids_vector_primecup_toptier.end(), mt_rand);

            // Change Pokémon team
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                quint8 offset_vector_pkm = 0;

                // Gym Leaders / Elite 4 / Rival
                if((cpu_cup_id[cpu_trainer_id]==18 || cpu_cup_id[cpu_trainer_id]==19 || cpu_cup_id[cpu_trainer_id]>=40) && strong_pkm_finals){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_primecup_toptier[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_primecup_toptier.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_primecup_toptier[i];
                    pkm_ids_vector_primecup_toptier[i]=pkm_ids_vector_primecup_toptier[i+offset_vector_pkm];
                    pkm_ids_vector_primecup_toptier[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup_toptier[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup_toptier[i]];
                }
                else if(((cpu_trainer_id-79)%4 == 0 && cpu_cup_id[cpu_trainer_id]<=17) || ((cpu_trainer_id-205)%4 == 0 && cpu_cup_id[cpu_trainer_id]>=32)){
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_primecup_toptier[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_primecup_toptier.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_primecup_toptier[i];
                    pkm_ids_vector_primecup_toptier[i]=pkm_ids_vector_primecup_toptier[i+offset_vector_pkm];
                    pkm_ids_vector_primecup_toptier[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup_toptier[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup_toptier[i]];
                }
                // Other trainers
                else{
                    while(cpu_pkm_level[cpu_trainer_id][i]<pkm_min_level[pkm_ids_vector_primecup[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_primecup.size())){
                        offset_vector_pkm++;
                    }
                    buf8=pkm_ids_vector_primecup[i];
                    pkm_ids_vector_primecup[i]=pkm_ids_vector_primecup[i+offset_vector_pkm];
                    pkm_ids_vector_primecup[i+offset_vector_pkm]=buf8;

                    cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup[i];
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }



        // Vs Mewtwo
        else if(cpu_cup_id[cpu_trainer_id] == 20 || cpu_cup_id[cpu_trainer_id] == 42){
            std::shuffle(pkm_ids_vector_vs_mewtwo.begin(), pkm_ids_vector_vs_mewtwo.end(), mt_rand);
            std::shuffle(pkm_ids_vector_vs_mewtwo_toptier.begin(), pkm_ids_vector_vs_mewtwo_toptier.end(), mt_rand);

            // Change Pokémon team
            if(ui->checkBox_Randomizer_CPU_MewtwoFullParty->isChecked() == false){
                cpu_party_size[cpu_trainer_id] = 1;
            }
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                if(i==0 && ui->checkBox_Randomizer_CPU_MewtwoMewtwo->isChecked()){
                    cpu_pkm_id[cpu_trainer_id][i] = 150;
                    cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[150];
                }
                else if(strong_pkm_finals){
                    if(pkm_ids_vector_vs_mewtwo_toptier[i] != 150){
                        cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_vs_mewtwo_toptier[i];
                        cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_vs_mewtwo_toptier[i]];
                    }
                    else{
                        cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_vs_mewtwo_toptier.back();
                        cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_vs_mewtwo_toptier.back()];
                    }
                }
                else{
                    if(pkm_ids_vector_vs_mewtwo[i] != 150){
                        cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_vs_mewtwo[i];
                        cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_vs_mewtwo[i]];
                    }
                    else{
                        cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_vs_mewtwo.back();
                        cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_vs_mewtwo.back()];
                    }
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }

        }


        // Battle Now: Lv 2 to Lv 100
        else if(cpu_cup_id[cpu_trainer_id]==21 || cpu_cup_id[cpu_trainer_id]==43){
            std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
            // Change Pokémon team
            for(unsigned short i=0;i<cpu_party_size[cpu_trainer_id];i++){
                cpu_pkm_id[cpu_trainer_id][i] = pkm_ids_vector_primecup[i];
                cpu_pkm_nickname[cpu_trainer_id][i] = pkm_name[pkm_ids_vector_primecup[i]];

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] != 0 && pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_pkm_id[cpu_trainer_id][i]];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }
    }

    prng_seed[0] = mt_rand();
    prng_seed[1] = mt_rand();
    prng_seed[2] = mt_rand();
    prng_seed[3] = mt_rand();
    prng_seed[4] = mt_rand();
    prng_seed[5] = mt_rand();
}
