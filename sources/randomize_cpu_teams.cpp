#include "mainwindow.h"
#include <algorithm>
#include <random>

// Initialises the pools of Pokemon the CPU randomisation picks from.
void MainWindow::randomize_cpu_init_pkmn()
{
    init_petit_cup_pool();
    init_pika_cup_pool();
    init_prime_cup_pool();
    init_poke_cup_pool();
    init_glc_lowlvl_pool();
    init_vs_mewtwo_pool();
}

void MainWindow::init_petit_cup_pool()
{
    bool no_useless_pokemon = ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();
    bool randomized_base_stats = ui->checkBox_Randomize_PkmnData_BS->isChecked();

    const std::vector<quint8> pkm_list_petitcup {1,4,7,16,19,21,23,25,27,32,35,37,39,43,46,50,52,54,58,60,63,66,69,74,81,83,90,92,98,100,102,104,109,116,118,133,138,140,147};
    pkm_ids_vector_petitcup = pkm_list_petitcup;

    const std::vector<quint8> useless_mons {10, 13, 29, 41, 129, 132};
    if (!no_useless_pokemon || (randomized_pkm_data && randomized_base_stats)) {
        for (quint8 i : useless_mons) {
            pkm_ids_vector_petitcup.push_back(i);
        }
    }

    const std::vector<quint8> pkm_list_petitcup_toptier {25,50,52,60,63,74,90,92,100,102,37};

    if (!randomized_pkm_data) {
        pkm_ids_vector_petitcup_toptier = pkm_list_petitcup_toptier;

        // Charmander > Vulpix if Dragon Rage is allowed
        if(ui->checkBox_Randomizer_CPU_NoDragonRage->isChecked()==false && ui->checkBox_Randomizer_CPU_NoIllegalMoves->isChecked()){
            pkm_ids_vector_petitcup_toptier.pop_back();
            pkm_ids_vector_petitcup_toptier.push_back(4);
        }
    }
    else {
        pkm_ids_vector_petitcup_toptier = pkm_list_petitcup;
    }

    // TO DO: Generate Gambler Pokémon list depending on learned moves
    std::vector<quint8> pkm_list_petitcup_gambler {23,27,32,35,50,63,66,74,90,92,98,100,102,104,109,118};
    pkm_ids_vector_petitcup_gambler = pkm_list_petitcup_gambler;
}

void MainWindow::init_pika_cup_pool()
{
    bool no_mew_mewtwo = ui->checkBox_Randomizer_CPU_NoMewMewtwo->isChecked();
    bool no_illegal_pkmn = ui->checkBox_Randomizer_CPU_NoIllegalPkmn->isChecked();
    bool no_useless_pokemon = ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();

    pkm_ids_vector_pikacup.clear();
    pkm_ids_vector_pikacup_toptier.clear();

    const std::vector<quint8> no_ill_pkm_list_pikacup {2,5,8,12,15,17,20,22,26,31,34,36,38,40,47,51,55,59,62,65,68,73,76,80,87,89,91,94,95,99,101,103,106,107,108,112,113,114,115,117,121,122,123,124,127,130,131,137,148};
    const std::vector<quint8> ill_pkm_list_pikacup {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};

    if (ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()) {
        if (no_illegal_pkmn) {
            pkm_ids_vector_pikacup = no_ill_pkm_list_pikacup;
        }
        else {
            pkm_ids_vector_pikacup = ill_pkm_list_pikacup;
        }
        if (!no_useless_pokemon) {
            pkm_ids_vector_pikacup.push_back(83);
            pkm_ids_vector_pikacup.push_back(132);
        }
        if (!no_mew_mewtwo) {
            if (!no_illegal_pkmn) {
                pkm_ids_vector_pikacup.push_back(150);
            }
            pkm_ids_vector_pikacup.push_back(151);
        }
    }
    else {
        const std::vector<uint8_t> useless_mons {10, 11, 13, 14, 29, 41, 43, 48, 83, 129, 132};
        std::vector<uint8_t> mons_to_skip = useless_mons;
        if (no_mew_mewtwo) {
            mons_to_skip.push_back(150);
            mons_to_skip.push_back(151);
        }

        for (uint8_t i = 1; i <= total_pkm_name; i++) {
            if (!std::binary_search(mons_to_skip.begin(), mons_to_skip.end(), i)) {
                if ((pkm_min_level[i] <= 20) || !no_illegal_pkmn) {
                    pkm_ids_vector_pikacup.push_back(i);
                }
            }
        }

        if (!no_useless_pokemon) {
            for (uint8_t i : useless_mons) {
                pkm_ids_vector_pikacup.push_back(i);
            }
        }
    }

    const std::vector<quint8> no_ill_pkm_list_toptier {26,34,36,55,65,68,76,80,91,94,103,112,113,115,121,124,130,131};
    const std::vector<quint8> ill_pkm_list_toptier {53,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149};

    if (!randomized_pkm_data) {
        if (no_illegal_pkmn) {
            pkm_ids_vector_pikacup_toptier = no_ill_pkm_list_toptier;
        }
        else {
            pkm_ids_vector_pikacup_toptier = ill_pkm_list_toptier;
        }
        if (!no_mew_mewtwo) {
            if (!no_illegal_pkmn) {
                pkm_ids_vector_pikacup_toptier.push_back(150);
            }
            pkm_ids_vector_pikacup_toptier.push_back(151);
        }
    }
    else {
        if (!no_mew_mewtwo) {
            if (!no_illegal_pkmn) {
                pkm_ids_vector_pikacup_toptier.push_back(150);
            }
            pkm_ids_vector_pikacup_toptier.push_back(151);
        }

        unsigned int j = 0;
        int evo_stage = 2;
        while (j <= 6) {
            for (quint8 i = 1; i <= total_pkm_name; i++) {
                if (pkm_evo_stage[i] == evo_stage) {
                    if ((pkm_min_level[i] <= 20) || !no_illegal_pkmn) {
                        pkm_ids_vector_pikacup_toptier.push_back(i);
                    }
                }
            }
            evo_stage--;
            j = pkm_ids_vector_primecup_toptier.size();
            if (evo_stage < 0) {
                j = 7;
            }
        }
    }

    const std::vector<quint8> no_ill_pkm_list_gambler {31,34,36,51,62,65,68,76,80,87,89,91,94,95,97,99,101,103,108,112,113,115,122,124,125,126,127,131};
    const std::vector<quint8> ill_pkm_list_gambler {6,9,24,28,31,34,36,51,57,62,65,68,76,78,80,87,89,91,94,95,97,99,101,103,105,108,110,112,113,115,119,122,124,125,126,127,128,131,139,143,149};

    if (no_illegal_pkmn) {
        pkm_ids_vector_pikacup_gambler = no_ill_pkm_list_gambler;
    }
    else {
        pkm_ids_vector_pikacup_gambler = ill_pkm_list_gambler;
    }
}

void MainWindow::init_prime_cup_pool()
{
    bool no_mew_mewtwo = ui->checkBox_Randomizer_CPU_NoMewMewtwo->isChecked();
    bool no_useless_pokemon = ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();

    pkm_ids_vector_primecup.clear();
    pkm_ids_vector_primecup_toptier.clear();

    if (ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()) {
        const std::vector<quint8> pkm_list_primecup {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_primecup = pkm_list_primecup;
        if (!no_useless_pokemon) {
            pkm_ids_vector_primecup.push_back(83);
            pkm_ids_vector_primecup.push_back(132);
        }
        pkm_ids_vector_primecup.push_back(150);
        pkm_ids_vector_primecup.push_back(151);
    }
    else if (!no_useless_pokemon) {
        const std::vector<quint8> useless_mons {10, 11, 13, 14, 29, 41, 48, 129, 132};
        for (quint8 i = 1; i <= total_pkm_name; i++) {
            if (!std::binary_search(useless_mons.begin(), useless_mons.end(), i)) {
                pkm_ids_vector_primecup.push_back(i);
            }
        }
    }
    else {
        for (quint8 i = 1; i <= total_pkm_name; i++) {
            pkm_ids_vector_primecup.push_back(i);
        }
    }

    if (no_mew_mewtwo) {
        pkm_ids_vector_primecup.pop_back();
        pkm_ids_vector_primecup.pop_back();
    }

    if (!randomized_pkm_data) {
        const std::vector<quint8> pkm_list_primecup_toptier {53,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149};
        pkm_ids_vector_primecup_toptier = pkm_list_primecup_toptier;
    }
    else {
        unsigned int j = 0;
        int evo_stage = 3;
        while (j <= 6) {
            for (quint8 i = 1; i <= total_pkm_name; i++) {
                if ((pkm_evo_stage[i] == evo_stage) && (i != 150) && (i != 151)) {
                    pkm_ids_vector_primecup_toptier.push_back(i);
                }
            }
            evo_stage--;
            j = pkm_ids_vector_primecup_toptier.size();
            if (evo_stage < 0) {
                j = 7;
            }
        }
    }

    // TO DO: Generate Gambler Pokémon list depending on learned moves
    const std::vector<quint8> pkm_list_primecup_gambler {6,9,24,28,31,34,36,51,57,62,65,68,76,78,80,87,89,91,94,95,97,99,101,103,105,108,110,112,113,115,119,122,124,125,126,127,128,131,139,143,149};
    pkm_ids_vector_primecup_gambler = pkm_list_primecup_gambler;

    if (!no_mew_mewtwo) {
        pkm_ids_vector_primecup_toptier.push_back(150);
        pkm_ids_vector_primecup_toptier.push_back(151);
        pkm_ids_vector_primecup_gambler.push_back(150);
        pkm_ids_vector_primecup_gambler.push_back(151);
    }
}

void MainWindow::init_poke_cup_pool()
{
    bool no_mew_mewtwo = ui->checkBox_Randomizer_CPU_NoMewMewtwo->isChecked();
    bool no_illegal_pkmn = ui->checkBox_Randomizer_CPU_NoIllegalPkmn->isChecked();
    bool no_useless_pokemon = ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();

    pkm_ids_vector_pokecup.clear();
    pkm_ids_vector_pokecup_toptier.clear();
    pkm_ids_vector_pokecup_gambler.clear();

    if (ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()) {
        const std::vector<quint8> pkm_list_pokecup {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149};
        pkm_ids_vector_pokecup = pkm_list_pokecup;
        if (!no_useless_pokemon) {
            pkm_ids_vector_pokecup.push_back(83);
            pkm_ids_vector_pokecup.push_back(132);
        }
    }
    else if (!no_useless_pokemon) {
        const std::vector<quint8> mons_to_skip {10, 11, 13, 14, 29, 41, 48, 129, 132, 150, 151};
        for (quint8 i = 1; i <= total_pkm_name; i++) {
            if (!std::binary_search(mons_to_skip.begin(), mons_to_skip.end(), i)) {
                pkm_ids_vector_pokecup.push_back(i);
            }
        }
    }
    else {
        for (quint8 i = 1; i <= total_pkm_name; i++) {
            if (pkm_min_level[i] <= 55 || !no_illegal_pkmn) {
                if ((i != 150) && (i != 151)) {
                    pkm_ids_vector_pokecup.push_back(i);
                }
            }
        }
    }

    if (!randomized_pkm_data) {
        const std::vector<quint8> pkm_list_pokecup_toptier {53,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149};
        pkm_ids_vector_pokecup_toptier = pkm_list_pokecup_toptier;
    }
    else {
        unsigned int j = 0;
        int evo_stage = 3;
        while (j <= 6) {
            for (quint8 i = 1; i <= total_pkm_name; i++) {
                if ((pkm_evo_stage[i] == evo_stage) && (i != 150) && (i != 151)) {
                    pkm_ids_vector_pokecup_toptier.push_back(i);
                }
            }
            j = pkm_ids_vector_pokecup_toptier.size();
            evo_stage--;
            if (evo_stage < 0) {
                j = 7;
            }
        }
    }

    if (!no_mew_mewtwo) {
        if ((pkm_min_level[150] <= 55) || !no_illegal_pkmn) {
            pkm_ids_vector_pokecup.push_back(150);
            pkm_ids_vector_pokecup_toptier.push_back(150);
        }
        if ((pkm_min_level[151] <= 55) || !no_illegal_pkmn) {
            pkm_ids_vector_pokecup.push_back(151);
            pkm_ids_vector_pokecup_toptier.push_back(151);
        }
    }

    // TO DO: Generate Gambler Pokémon list depending on learned moves
    const std::vector<quint8> pkm_list_pokecup_gambler {6,9,24,28,31,34,36,51,57,62,65,68,76,78,80,87,89,91,94,95,97,99,101,103,105,108,110,112,113,115,119,122,124,125,126,127,128,131,139,143,149};
    pkm_ids_vector_pokecup_gambler = pkm_list_pokecup_gambler;
}

void MainWindow::init_glc_lowlvl_pool()
{
    bool no_mew_mewtwo = ui->checkBox_Randomizer_CPU_NoMewMewtwo->isChecked();

    const std::vector<quint8> pkm_list_glc_lowminlv {26,36,53,65,76,80,91,94,97,101,103,112,113,121,122,124,128,131,135,143,144,145,146,149};
    pkm_ids_vector_glc_lowminlv = pkm_list_glc_lowminlv;

    if (!no_mew_mewtwo) {
        pkm_ids_vector_glc_lowminlv.push_back(150);
        pkm_ids_vector_glc_lowminlv.push_back(151);
    }
}

void MainWindow::init_vs_mewtwo_pool()
{
    bool no_useless_pokemon = ui->checkBox_Randomizer_CPU_NoUselessPkmn->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();

    if (ui->checkBox_Randomizer_CPU_FullyEvolved->isChecked()) {
        const std::vector<quint8> pkm_list_vs_mewtwo {3,6,9,12,15,18,20,22,24,26,28,31,34,36,38,40,42,45,47,49,51,53,55,57,59,62,65,68,71,73,76,78,80,82,85,87,89,91,94,95,97,99,101,103,105,106,107,108,110,112,113,114,115,117,119,121,122,123,124,125,126,127,128,130,131,134,135,136,137,139,141,142,143,144,145,146,149,151};
        pkm_ids_vector_vs_mewtwo = pkm_list_vs_mewtwo;
        if (!no_useless_pokemon) {
            pkm_ids_vector_vs_mewtwo.push_back(83);
            pkm_ids_vector_vs_mewtwo.push_back(132);
        }
    }
    else if (!no_useless_pokemon) {
        for(quint8 i = 1; i <= total_pkm_name; i++) {
            const std::vector<quint8> useless_mons {10, 11, 13, 14, 29, 41, 48, 129, 132};
            if (!std::binary_search(useless_mons.begin(), useless_mons.end(), i)) {
                pkm_ids_vector_vs_mewtwo.push_back(i);
            }
        }
    }
    else {
        for(quint8 i = 1; i <= total_pkm_name; i++) {
            pkm_ids_vector_vs_mewtwo.push_back(i);
        }
    }

    if (!randomized_pkm_data) {
        const std::vector<quint8> pkm_list_vs_mewtwo_toptier {53,62,65,76,80,91,94,97,103,112,113,121,124,128,131,135,143,144,145,146,149,151};
        pkm_ids_vector_vs_mewtwo_toptier = pkm_list_vs_mewtwo_toptier;
    }
    else {
        unsigned int j = 0;
        int evo_stage = 3;
        while (j <= 6) {
            for (quint8 i = 1; i <= total_pkm_name; i++) {
                if ((pkm_evo_stage[i] == evo_stage) && (i != 150) && (i != 151)) {
                    pkm_ids_vector_vs_mewtwo_toptier.push_back(i);
                }
            }
            j = pkm_ids_vector_vs_mewtwo_toptier.size();
            evo_stage--;
            if (evo_stage < 0) {
                j = 7;
            }
        }
    }
}

void MainWindow::randomize_cpu_iv_stat_exp(std::mt19937 &mt_rand)
{
    // TO DO: Petit Cup ; Optimize this
    std::uniform_int_distribution<> rand_iv_1(std::max(cpu_ivs_min,std::min(quint8(11),cpu_ivs_max)),(cpu_ivs_max+3));
    std::uniform_int_distribution<> rand_iv_2(std::max(cpu_ivs_min,std::min(quint8(9),cpu_ivs_max)),(cpu_ivs_max+1));
    std::uniform_int_distribution<> rand_iv_3(std::max(cpu_ivs_min,std::min(quint8(7),cpu_ivs_max)),(cpu_ivs_max));
    std::uniform_int_distribution<> rand_iv_4(std::max(cpu_ivs_min,std::min(quint8(3),cpu_ivs_max)),(cpu_ivs_max));
    std::uniform_int_distribution<> rand_iv_5(std::max(cpu_ivs_min,std::min(quint8(1),cpu_ivs_max)),(cpu_ivs_max));
    std::uniform_int_distribution<> rand_iv_6(cpu_ivs_min,cpu_ivs_max);
    std::uniform_int_distribution<> rand_stat_exp_1(std::max(cpu_stat_exp_min,std::min(quint16(50025),cpu_stat_exp_max)),(cpu_stat_exp_max+18432));
    std::uniform_int_distribution<> rand_stat_exp_2(std::max(cpu_stat_exp_min,std::min(quint16(43792),cpu_stat_exp_max)),(cpu_stat_exp_max+10288));
    std::uniform_int_distribution<> rand_stat_exp_3(std::max(cpu_stat_exp_min,std::min(quint16(27600),cpu_stat_exp_max)),(cpu_stat_exp_max+384));
    std::uniform_int_distribution<> rand_stat_exp_4(std::max(cpu_stat_exp_min,std::min(quint16(14400),cpu_stat_exp_max)),cpu_stat_exp_max);
    if(cpu_stat_exp_max>1111) buf32 = std::max(quint16(cpu_stat_exp_max-1111),cpu_stat_exp_min);
    else buf32 = cpu_stat_exp_max;
    std::uniform_int_distribution<> rand_stat_exp_5(std::max(cpu_stat_exp_min,std::min(quint16(6400),cpu_stat_exp_max)),buf32);
    std::uniform_int_distribution<> rand_stat_exp_6(cpu_stat_exp_min,buf32);
    std::uniform_int_distribution<> rand_stat_exp_def(cpu_stat_exp_min,cpu_stat_exp_max);

    bool max_stats_finals = ui->checkBox_Randomizer_CPU_MaxIVsEVsFinal->isChecked();
    bool better_stats_nfe = ui->checkBox_Randomizer_CPU_NFE_IVsEVs->isChecked();
    bool randomized_pkm_data = ui->checkBox_PkmnData->isChecked();

    for(uint8_t cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        if(max_stats_finals
                && (cpu_trainers[cpu_trainer_id].cup_id==18 || cpu_trainers[cpu_trainer_id].cup_id==19 || cpu_trainers[cpu_trainer_id].cup_id==20
                || cpu_trainers[cpu_trainer_id].cup_id==40 ||cpu_trainers[cpu_trainer_id].cup_id==41 || cpu_trainers[cpu_trainer_id].cup_id==42
                || cpu_trainer_id==7 || cpu_trainer_id==15 || cpu_trainer_id==39 || cpu_trainer_id==47
                || cpu_trainer_id==71 || cpu_trainer_id==79 || cpu_trainer_id==83 || cpu_trainer_id==87
                || cpu_trainer_id==91 || cpu_trainer_id==95 || cpu_trainer_id==99 || cpu_trainer_id==103
                || cpu_trainer_id==107 || cpu_trainer_id==111 || cpu_trainer_id==133 || cpu_trainer_id==141
                || cpu_trainer_id==165 || cpu_trainer_id==173 || cpu_trainer_id==197 || cpu_trainer_id==205
                || cpu_trainer_id==209 || cpu_trainer_id==213 || cpu_trainer_id==217 || cpu_trainer_id==221
                || cpu_trainer_id==225 || cpu_trainer_id==229 || cpu_trainer_id==233 || cpu_trainer_id==237)){
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                cpu_pkm_iv_hp[cpu_trainer_id][i] = 15;
                cpu_pkm_iv_atk[cpu_trainer_id][i] = 15;
                cpu_pkm_iv_def[cpu_trainer_id][i] = 15;
                cpu_pkm_iv_spc[cpu_trainer_id][i] = 15;
                cpu_pkm_iv_speed[cpu_trainer_id][i] = 15;
                cpu_pkm_ev_hp[cpu_trainer_id][i] = 65535;
                cpu_pkm_ev_atk[cpu_trainer_id][i] = 65535;
                cpu_pkm_ev_def[cpu_trainer_id][i] = 65535;
                cpu_pkm_ev_spc[cpu_trainer_id][i] = 65535;
                cpu_pkm_ev_speed[cpu_trainer_id][i] = 65535;
            }
        }
        else{
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                if(better_stats_nfe){
                    // Petit Cup
                    if(cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==22){
                        if(randomized_pkm_data == false) {
                            switch(iv_statexp_groups[cpu_trainers[cpu_trainer_id].pkm[i].id]){
                            case 0:
                                cpu_pkm_iv_atk[cpu_trainer_id][i] = cpu_ivs_max;
                                cpu_pkm_iv_def[cpu_trainer_id][i] = cpu_ivs_max;
                                cpu_pkm_iv_spc[cpu_trainer_id][i] = cpu_ivs_max;
                                cpu_pkm_iv_speed[cpu_trainer_id][i] = cpu_ivs_max;

                                cpu_pkm_ev_hp[cpu_trainer_id][i] = cpu_stat_exp_max;
                                cpu_pkm_ev_atk[cpu_trainer_id][i] = cpu_stat_exp_max;
                                cpu_pkm_ev_def[cpu_trainer_id][i] = cpu_stat_exp_max;
                                cpu_pkm_ev_spc[cpu_trainer_id][i] = cpu_stat_exp_max;
                                cpu_pkm_ev_speed[cpu_trainer_id][i] = cpu_stat_exp_max;
                                break;

                            default:
                                cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_1(mt_rand);
                                cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_1(mt_rand);
                                cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_1(mt_rand);
                                cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_1(mt_rand);

                                buf32 = rand_stat_exp_3(mt_rand);
                                if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                                cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                                buf32 = rand_stat_exp_3(mt_rand);
                                if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                                cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                                buf32 = rand_stat_exp_2(mt_rand);
                                if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                                cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                                buf32 = rand_stat_exp_2(mt_rand);
                                if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                                cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                                buf32 = rand_stat_exp_3(mt_rand);
                                if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                                cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;
                                break;
                            }
                        }
                        else {
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_1(mt_rand);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_1(mt_rand);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_1(mt_rand);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_1(mt_rand);

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;
                        }
                    }
                    else if(randomized_pkm_data == false) {
                        switch(iv_statexp_groups[cpu_trainers[cpu_trainer_id].pkm[i].id]) {
                        case 0:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_iv_def[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = cpu_stat_exp_max;
                            break;

                        case 1:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;
                            break;

                        case 2:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = std::min(quint8(rand_iv_2(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = std::min(quint8(rand_iv_2(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = std::min(quint8(rand_iv_2(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = std::min(quint8(rand_iv_2(mt_rand)),cpu_ivs_max);

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;
                            break;

                        case 3:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = std::min(quint8(rand_iv_3(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = std::min(quint8(rand_iv_3(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = std::min(quint8(rand_iv_3(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = std::min(quint8(rand_iv_3(mt_rand)),cpu_ivs_max);

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;
                            break;

                        case 4:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);

                            cpu_pkm_ev_hp[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                            cpu_pkm_ev_def[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                            break;

                        case 5:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_5(mt_rand);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_5(mt_rand);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_5(mt_rand);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_5(mt_rand);

                            cpu_pkm_ev_hp[cpu_trainer_id][i] = rand_stat_exp_5(mt_rand);
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = rand_stat_exp_5(mt_rand);
                            cpu_pkm_ev_def[cpu_trainer_id][i] = rand_stat_exp_5(mt_rand);
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = rand_stat_exp_5(mt_rand);
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = rand_stat_exp_5(mt_rand);
                            break;

                        default:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_6(mt_rand);

                            cpu_pkm_ev_hp[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                            cpu_pkm_ev_def[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                            break;
                        }
                    }
                    else {
                        switch(pkm_evo_stage[cpu_trainers[cpu_trainer_id].pkm[i].id]) {
                        case 0:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_iv_def[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = cpu_ivs_max;
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = cpu_ivs_max;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_1(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;

                            break;
                        case 1:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = std::min(quint8(rand_iv_1(mt_rand)),cpu_ivs_max);

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_2(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;

                            break;
                        case 2:
                            cpu_pkm_iv_atk[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_def[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_spc[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);
                            cpu_pkm_iv_speed[cpu_trainer_id][i] = std::min(quint8(rand_iv_4(mt_rand)),cpu_ivs_max);

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_hp[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_atk[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_def[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_spc[cpu_trainer_id][i] = buf32;

                            buf32 = rand_stat_exp_3(mt_rand);
                            if(buf32 > cpu_stat_exp_max) buf32 = cpu_stat_exp_max;
                            cpu_pkm_ev_speed[cpu_trainer_id][i] = buf32;

                            break;
                        default:
                            if(cpu_trainers[cpu_trainer_id].pkm[i].id<150){
                                cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_5(mt_rand);
                                cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_5(mt_rand);
                                cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_5(mt_rand);
                                cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_5(mt_rand);

                                cpu_pkm_ev_hp[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                                cpu_pkm_ev_atk[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                                cpu_pkm_ev_def[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                                cpu_pkm_ev_spc[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                                cpu_pkm_ev_speed[cpu_trainer_id][i] = rand_stat_exp_4(mt_rand);
                            }
                            else{
                                cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                                cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                                cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                                cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_6(mt_rand);

                                cpu_pkm_ev_hp[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                                cpu_pkm_ev_atk[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                                cpu_pkm_ev_def[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                                cpu_pkm_ev_spc[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                                cpu_pkm_ev_speed[cpu_trainer_id][i] = rand_stat_exp_6(mt_rand);
                            }
                            break;
                        }
                    }
                }
                else{
                    cpu_pkm_iv_atk[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                    cpu_pkm_iv_def[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                    cpu_pkm_iv_spc[cpu_trainer_id][i] = rand_iv_6(mt_rand);
                    cpu_pkm_iv_speed[cpu_trainer_id][i] = rand_iv_6(mt_rand);

                    cpu_pkm_ev_hp[cpu_trainer_id][i] = rand_stat_exp_def(mt_rand);
                    cpu_pkm_ev_atk[cpu_trainer_id][i] = rand_stat_exp_def(mt_rand);
                    cpu_pkm_ev_def[cpu_trainer_id][i] = rand_stat_exp_def(mt_rand);
                    cpu_pkm_ev_spc[cpu_trainer_id][i] = rand_stat_exp_def(mt_rand);
                    cpu_pkm_ev_speed[cpu_trainer_id][i] = rand_stat_exp_def(mt_rand);
                }
                cpu_pkm_iv_hp[cpu_trainer_id][i] = (cpu_pkm_iv_atk[cpu_trainer_id][i] & 1)*8 + (cpu_pkm_iv_def[cpu_trainer_id][i] & 1)*4 + (cpu_pkm_iv_speed[cpu_trainer_id][i] & 1)*2 + (cpu_pkm_iv_spc[cpu_trainer_id][i] & 1);
            }
        }
    }
}

// Assumes the max level is low_lvl + 5 and the max team level is 3 * low_lvl + 5
void randomize_lvls_from_range(Trainer &trainer, std::mt19937 &mt_rand, quint8 low_lvl)
{
    quint8 sum_limit = 3 * low_lvl + 5;
    std::vector<std::uniform_int_distribution<>> distribs;

    for (int j = 0; j < 6; ++j) {
        std::uniform_int_distribution<> new_distrib(low_lvl, low_lvl + j);
        distribs.push_back(new_distrib);
    }
    for (unsigned int i = 0; i < trainer.party_size; ++i) {
        if ((i % 3) == 0) {
            trainer.pkm[i].lvl = distribs[0](mt_rand);
        }
        else if ((i % 3) == 1) {
            quint8 first_lvl = trainer.pkm[i - 1].lvl;
            trainer.pkm[i].lvl = distribs[first_lvl - low_lvl](mt_rand);
        }
        else {
            trainer.pkm[i].lvl = sum_limit;
            trainer.pkm[i].lvl -= trainer.pkm[i - 1].lvl;
            trainer.pkm[i].lvl -= trainer.pkm[i - 2].lvl;
        }
    }
}

void MainWindow::randomize_cpu_level(std::mt19937 &mt_rand)
{
    bool gym_leaders_pokemon = ui->checkBox_Randomizer_CPU_GLPkmn->isChecked();

    // CPU Levels generation
    for (uint8_t cpu_trainer_id=0; cpu_trainer_id<current_cpu_trainers_number; cpu_trainer_id++) {
        Trainer& current_trainer = cpu_trainers[cpu_trainer_id];
        current_trainer.party_size = 6;

        // Petit Cup: Lv 25 to Lv 30
        if (is_petit_trainer(current_trainer)) {
            randomize_lvls_from_range(current_trainer, mt_rand, 25);
        }

        // Pika Cup: Lv 15 to Lv 20
        else if (is_pika_trainer(current_trainer)) {
            randomize_lvls_from_range(current_trainer, mt_rand, 15);
        }

        // Prime Cup: Lv 100
        else if (is_prime_trainer(current_trainer)) {
            for (Pokemon& p : current_trainer.pkm) {
                p.lvl = 100;
            }
        }

        // Poké Cup: Lv 50 to Lv 55
        else if (is_poke_trainer(current_trainer)) {
            randomize_lvls_from_range(current_trainer, mt_rand, 50);
        }

        // Gym Leader Castle: User-specified Lv range
        // TODO: figure out how to clean up the gym leaders stuff.
        else if (is_glc_trainer(current_trainer)) {
            std::uniform_int_distribution<> distrib(glc_level_min, glc_level_max);
            for (uint8_t i = 0; i < current_trainer.party_size; i++) {
                current_trainer.pkm[i].lvl = distrib(mt_rand);
            }

            if (gym_leaders_pokemon && (glc_level_max <= 78)) {
                // Brock
                if(cpu_trainer_id==83 || cpu_trainer_id==209){
                    current_trainer.pkm[0].lvl = glc_level_max*1.13;
                    current_trainer.pkm[1].lvl = glc_level_max*1.06;
                    current_trainer.pkm[2].lvl = glc_level_max*1.17;
                }
                // Misty
                if(cpu_trainer_id==87 || cpu_trainer_id==213){
                    current_trainer.pkm[0].lvl = glc_level_max*1.26;
                    current_trainer.pkm[1].lvl = glc_level_max;
                    current_trainer.pkm[2].lvl = glc_level_max;
                    current_trainer.pkm[3].lvl = glc_level_max*1.12;
                }
                // Lt. Surge
                if(cpu_trainer_id==91 || cpu_trainer_id==217){
                    current_trainer.pkm[0].lvl = glc_level_max*1.06;
                    current_trainer.pkm[1].lvl = glc_level_max;
                    current_trainer.pkm[2].lvl = glc_level_max*1.05;
                }
                // Erika
                if(cpu_trainer_id==95 || cpu_trainer_id==221){
                    if((prng_seed[0]+(cpu_trainer_id/200))%2==0)
                        current_trainer.pkm[0].lvl = glc_level_max*1.06;
                    else
                        current_trainer.pkm[0].lvl = glc_level_max*1.05;
                    if((prng_seed[1]+(cpu_trainer_id/200))%2==0)
                        current_trainer.pkm[1].lvl = glc_level_max;
                    else
                        current_trainer.pkm[1].lvl = glc_level_max*1.04;
                    current_trainer.pkm[2].lvl = glc_level_max*1.03;
                }
                // Koga
                if(cpu_trainer_id==99 || cpu_trainer_id==225){
                    if((prng_seed[2]+(cpu_trainer_id/200))%2==0)
                        current_trainer.pkm[0].lvl = glc_level_max*1.11;
                    else
                        current_trainer.pkm[0].lvl = glc_level_max*1.04;
                    current_trainer.pkm[1].lvl = glc_level_max*1.08;
                    current_trainer.pkm[2].lvl = glc_level_max*1.02;
                }
                // Sabrina
                if(cpu_trainer_id==103 || cpu_trainer_id==229){
                    current_trainer.pkm[0].lvl = glc_level_max;
                    if((prng_seed[4]+(cpu_trainer_id/200))%2==0)
                        current_trainer.pkm[1].lvl = glc_level_max*1.05;
                    else
                        current_trainer.pkm[1].lvl = glc_level_max*1.11;
                    current_trainer.pkm[2].lvl = glc_level_max;
                }
                // Blaine
                if(cpu_trainer_id==107 || cpu_trainer_id==233){
                    if((prng_seed[1]+(cpu_trainer_id/200))%3==0)
                        current_trainer.pkm[0].lvl = glc_level_max*1.05;
                    else if((prng_seed[1]+(cpu_trainer_id/200))%3==1)
                        current_trainer.pkm[0].lvl = glc_level_max*1.09;
                    else
                        current_trainer.pkm[0].lvl = glc_level_max*1.07;
                    current_trainer.pkm[1].lvl = glc_level_max*1.01;
                    current_trainer.pkm[2].lvl = glc_level_max;
                }
                // Giovanni
                if(cpu_trainer_id==111 || cpu_trainer_id==237){
                    current_trainer.pkm[0].lvl = glc_level_max*1.02;
                    if((prng_seed[0]+(cpu_trainer_id/200))%3==0)
                        current_trainer.pkm[1].lvl = glc_level_max*1.02;
                    else if((prng_seed[0]+(cpu_trainer_id/200))%3==1)
                        current_trainer.pkm[1].lvl = glc_level_max*1.08;
                    else
                        current_trainer.pkm[1].lvl = glc_level_max*1.02;
                    current_trainer.pkm[2].lvl = glc_level_max*1.02;
                }
                // Lorelei
                if(cpu_trainer_id==112 || cpu_trainer_id==238){
                    current_trainer.pkm[0].lvl = glc_level_max*1.02;
                    current_trainer.pkm[1].lvl = glc_level_max;
                    current_trainer.pkm[2].lvl = glc_level_max;
                }
                // Bruno
                if(cpu_trainer_id==113 || cpu_trainer_id==239){
                    current_trainer.pkm[0].lvl = glc_level_max*1.05;
                    current_trainer.pkm[1].lvl = glc_level_max*1.13;
                    if((prng_seed[3]+(cpu_trainer_id/200))%3==0)
                        current_trainer.pkm[2].lvl = glc_level_max*1.09;
                    else
                        current_trainer.pkm[2].lvl = glc_level_max*1.05;
                }
                // Agatha
                if(cpu_trainer_id==114 || cpu_trainer_id==240){
                    current_trainer.pkm[0].lvl = glc_level_max*1.02;
                    current_trainer.pkm[1].lvl = glc_level_max*1.03;
                    current_trainer.pkm[2].lvl = glc_level_max*1.17;
                }
                // Lance
                if(cpu_trainer_id==115 || cpu_trainer_id==241){
                    current_trainer.pkm[0].lvl = glc_level_max*1.04;
                    current_trainer.pkm[1].lvl = glc_level_max*1.04;
                    current_trainer.pkm[2].lvl = glc_level_max;
                }
                // Rival
                if(cpu_trainers[cpu_trainer_id].cup_id==19){
                    current_trainer.pkm[0].lvl = glc_level_max;
                    current_trainer.pkm[1].lvl = glc_level_max*1.02;
                    current_trainer.pkm[2].lvl = glc_level_max;
                }
                // Red
                if(cpu_trainers[cpu_trainer_id].cup_id==41){
                    current_trainer.pkm[0].lvl = glc_level_max*1.23;
                    current_trainer.pkm[1].lvl = glc_level_max*1.05;
                    current_trainer.pkm[2].lvl = glc_level_max;
                }
            }
        }

        // Vs Mewtwo: Lv 100
        else if (is_mewtwo_trainer(current_trainer)) {
            if(!(ui->checkBox_Randomizer_CPU_MewtwoFullParty->isChecked())) {
                current_trainer.party_size = 1;
            }
            for (Pokemon& p : current_trainer.pkm) {
                p.lvl = 100;
            }
        }

        // Battle Now: Lv 50
        else if (is_battle_now_trainer(current_trainer)) {
            for (Pokemon& p : current_trainer.pkm) {
                p.lvl = 50;
            }
        }
    }
}

void MainWindow::randomize_cpu_moves(std::mt19937 &mt_rand)
{
    bool no_illegal_moves = ui->checkBox_Randomizer_CPU_NoIllegalMoves->isChecked();
    bool no_useless_moves = ui->checkBox_Randomizer_CPU_NoUselessMoves->isChecked();
    bool no_weak_moves = ui->checkBox_Randomizer_CPU_NoWeakMoves->isChecked();
    bool no_dragon_rage = ui->checkBox_Randomizer_CPU_NoDragonRage->isChecked();
    bool no_evasion_moves = ui->checkBox_Randomizer_CPU_NoEvasion->isChecked();
    bool have_offensive_move = ui->checkBox_Randomizer_CPU_OffensiveMove->isChecked();
    bool have_stab_move = ui->checkBox_Randomizer_CPU_STABMove->isChecked();
    bool gambler_luck_moves = ui->checkBox_Randomizer_CPU_GamblerMoves->isChecked();
    bool gym_leaders_pokemon = ui->checkBox_Randomizer_CPU_GLPkmn->isChecked();

    for(uint8_t cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
            moves_ids_vector.clear();
            strong_moves_ids_vector.clear();
            gambler_moves_ids_vector.clear();
            buf8 = cpu_trainers[cpu_trainer_id].pkm[i].id;
            bool learns_explosion = false;
            bool learns_recover = false;
            bool learns_softboiled = false;
            bool learns_offensive_move = false;
            bool learns_stab_move = false;

            if(no_illegal_moves){
                // Starting Moves
                if(pkm_start_move_1[buf8]>0 && pkm_start_move_1[buf8]<total_move_name){
                    // Explosion check
                    if(pkm_start_move_1[buf8]==0x99) learns_explosion = true;
                    // Recover check
                    if(pkm_start_move_1[buf8]==0x69) learns_recover = true;
                    // Softboiled check
                    if(pkm_start_move_1[buf8]==0x87) learns_softboiled = true;
                    // Dragon Rage in Petit Cup and Pika Cup
                    if(pkm_start_move_1[buf8]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                            learns_offensive_move = true;
                        }
                    }
                    // Rest
                    else if(pkm_start_move_1[buf8]==0x9C){
                        if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                            moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[pkm_start_move_1[buf8]]==false){
                        if((no_useless_moves==false || useless_move[pkm_start_move_1[buf8]]==false) && (move_effect[pkm_start_move_1[buf8]]!=0xF || no_evasion_moves==false)){
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
                    // Strong moves
                    /*
                     * if(strong_move[pkm_start_move_1[buf8]]
                            || ((move_type[pkm_start_move_1[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_1[buf8]]==pkm_type_2[buf8])
                            && move_power[pkm_start_move_1[buf8]]>=75
                            && (move_type[pkm_start_move_1[buf8]]>8 || pkm_base_atk[buf8]>35)
                            && (move_effect[pkm_start_move_1[buf8]]!=0x30 || (move_accuracy[pkm_start_move_1[buf8]]>=0xE5 && move_power[pkm_start_move_1[buf8]]>=90))))
                    */
                    if(strong_move[pkm_start_move_1[buf8]]
                            && (move_power[pkm_start_move_1[buf8]]<=1
                                || move_type[pkm_start_move_1[buf8]]>8
                                || ((move_type[pkm_start_move_1[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_1[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                || pkm_base_atk[buf8]>50)
                            && (move_effect[pkm_start_move_1[buf8]] != 0x50
                                || ((move_type[pkm_start_move_1[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_1[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                            && (move_effect[pkm_start_move_1[buf8]] != 0xF || no_evasion_moves==false))
                    {
                        strong_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                    }
                    // Gambler moves
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                        if((move_effect[pkm_start_move_1[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_1[buf8]]==7 || move_effect[pkm_start_move_1[buf8]]==0x24 || move_effect[pkm_start_move_1[buf8]]==0x26 || move_effect[pkm_start_move_1[buf8]]==0x34 || move_effect[pkm_start_move_1[buf8]]==0x43 || (move_effect[pkm_start_move_1[buf8]]==0x46 && move_power[pkm_start_move_1[buf8]]>=65) || move_effect[pkm_start_move_1[buf8]]==0x53 || (pkm_start_move_1[buf8]==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                        }
                        else if(move_accuracy[pkm_start_move_1[buf8]]<=0xD8 && move_power[pkm_start_move_1[buf8]]>=100 && (move_type[pkm_start_move_1[buf8]]>8 || pkm_base_atk[buf8]>50 || (move_type[pkm_start_move_1[buf8]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[pkm_start_move_1[buf8]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                            gambler_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                        }
                        else if(pkm_start_move_1[buf8]==move_high_ch[0] || pkm_start_move_1[buf8]==move_high_ch[1] || pkm_start_move_1[buf8]==move_high_ch[2] || pkm_start_move_1[buf8]==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(pkm_start_move_1[buf8]);
                        }
                    }
                }
                if(pkm_start_move_2[buf8]>0 && pkm_start_move_2[buf8]<total_move_name){
                    // Explosion check
                    if(pkm_start_move_2[buf8]==0x99) learns_explosion = true;
                    // Recover check
                    if(pkm_start_move_2[buf8]==0x69) learns_recover = true;
                    // Softboiled check
                    if(pkm_start_move_2[buf8]==0x87) learns_softboiled = true;
                    // Dragon Rage in Petit Cup and Pika Cup
                    if(pkm_start_move_2[buf8]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                            learns_offensive_move = true;
                        }
                    }
                    // Rest
                    else if(pkm_start_move_2[buf8]==0x9C){
                        if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                            moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[pkm_start_move_2[buf8]]==false){
                        if((no_useless_moves==false || useless_move[pkm_start_move_2[buf8]]==false) && (move_effect[pkm_start_move_2[buf8]]!=0xF || no_evasion_moves==false)){
                            moves_ids_vector.push_back(pkm_start_move_2[buf8]);

                            // Offensive move and STAB move check
                            if(move_power[pkm_start_move_3[buf8]]>1){
                                learns_offensive_move = true;
                                if(move_type[pkm_start_move_2[buf8]] == pkm_type_1[buf8] || move_type[pkm_start_move_2[buf8]] == pkm_type_2[buf8]){
                                    learns_stab_move = true;
                                }
                            }
                        }
                    }
                    // Strong moves
                    if(strong_move[pkm_start_move_2[buf8]]
                            && (move_power[pkm_start_move_2[buf8]]<=1
                                || move_type[pkm_start_move_2[buf8]]>8
                                || ((move_type[pkm_start_move_2[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_2[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                || pkm_base_atk[buf8]>50)
                            && (move_effect[pkm_start_move_2[buf8]] != 0x50
                                || ((move_type[pkm_start_move_2[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_2[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                            && (move_effect[pkm_start_move_2[buf8]] != 0xF || no_evasion_moves==false))
                    {
                        strong_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                    }
                    // Gambler moves
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                        if((move_effect[pkm_start_move_2[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_2[buf8]]==7 || move_effect[pkm_start_move_2[buf8]]==0x24 || move_effect[pkm_start_move_2[buf8]]==0x26 || move_effect[pkm_start_move_2[buf8]]==0x34 || move_effect[pkm_start_move_2[buf8]]==0x43 || (move_effect[pkm_start_move_2[buf8]]==0x46 && move_power[pkm_start_move_2[buf8]]>=65) || move_effect[pkm_start_move_2[buf8]]==0x53 || (pkm_start_move_2[buf8]==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                        }
                        else if(move_accuracy[pkm_start_move_2[buf8]]<=0xD8 && move_power[pkm_start_move_2[buf8]]>=100 && (move_type[pkm_start_move_2[buf8]]>8 || pkm_base_atk[buf8]>50 || (move_type[pkm_start_move_2[buf8]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[pkm_start_move_2[buf8]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                            gambler_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                        }
                        else if(pkm_start_move_2[buf8]==move_high_ch[0] || pkm_start_move_2[buf8]==move_high_ch[1] || pkm_start_move_2[buf8]==move_high_ch[2] || pkm_start_move_2[buf8]==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(pkm_start_move_2[buf8]);
                        }
                    }
                }
                if(pkm_start_move_3[buf8]>0 && pkm_start_move_3[buf8]<total_move_name){
                    // Explosion check
                    if(pkm_start_move_3[buf8]==0x99) learns_explosion = true;
                    // Recover check
                    if(pkm_start_move_3[buf8]==0x69) learns_recover = true;
                    // Softboiled check
                    if(pkm_start_move_3[buf8]==0x87) learns_softboiled = true;
                    // Dragon Rage in Petit Cup and Pika Cup
                    if(pkm_start_move_3[buf8]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                            learns_offensive_move = true;
                        }
                    }
                    // Rest
                    else if(pkm_start_move_3[buf8]==0x9C){
                        if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                            moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[pkm_start_move_3[buf8]]==false){
                        if((no_useless_moves==false || useless_move[pkm_start_move_3[buf8]]==false) && (move_effect[pkm_start_move_3[buf8]]!=0xF || no_evasion_moves==false)){
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
                    // Strong moves
                    if(strong_move[pkm_start_move_3[buf8]]
                            && (move_power[pkm_start_move_3[buf8]]<=1
                                || move_type[pkm_start_move_3[buf8]]>8
                                || ((move_type[pkm_start_move_3[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_3[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                || pkm_base_atk[buf8]>50)
                            && (move_effect[pkm_start_move_3[buf8]] != 0x50
                                || ((move_type[pkm_start_move_3[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_3[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                            && (move_effect[pkm_start_move_3[buf8]] != 0xF || no_evasion_moves==false))
                    {
                        strong_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                    }
                    // Gambler Moves
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                        if((move_effect[pkm_start_move_3[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_3[buf8]]==7 || move_effect[pkm_start_move_3[buf8]]==0x24 || move_effect[pkm_start_move_3[buf8]]==0x26 || move_effect[pkm_start_move_3[buf8]]==0x34 || move_effect[pkm_start_move_3[buf8]]==0x43 || (move_effect[pkm_start_move_3[buf8]]==0x46 && move_power[pkm_start_move_3[buf8]]>=65) || move_effect[pkm_start_move_3[buf8]]==0x53 || (pkm_start_move_3[buf8]==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                        }
                        else if(move_accuracy[pkm_start_move_3[buf8]]<=0xD8 && move_power[pkm_start_move_3[buf8]]>=100 && (move_type[pkm_start_move_3[buf8]]>8 || pkm_base_atk[buf8]>50 || (move_type[pkm_start_move_3[buf8]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[pkm_start_move_3[buf8]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                            gambler_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                        }
                        else if(pkm_start_move_3[buf8]==move_high_ch[0] || pkm_start_move_3[buf8]==move_high_ch[1] || pkm_start_move_3[buf8]==move_high_ch[2] || pkm_start_move_3[buf8]==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(pkm_start_move_3[buf8]);
                        }
                    }
                }
                if(pkm_start_move_4[buf8]>0 && pkm_start_move_4[buf8]<total_move_name){
                    // Explosion check
                    if(pkm_start_move_4[buf8]==0x99) learns_explosion = true;
                    // Recover check
                    if(pkm_start_move_4[buf8]==0x69) learns_recover = true;
                    // Softboiled check
                    if(pkm_start_move_4[buf8]==0x87) learns_softboiled = true;
                    // Dragon Rage in Petit Cup and Pika Cup
                    if(pkm_start_move_4[buf8]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                            learns_offensive_move = true;
                        }
                    }
                    // Rest
                    else if(pkm_start_move_4[buf8]==0x9C){
                        if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                            moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                            strong_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[pkm_start_move_4[buf8]]==false){
                        if((no_useless_moves==false || useless_move[pkm_start_move_4[buf8]]==false) && (move_effect[pkm_start_move_4[buf8]]!=0xF || no_evasion_moves==false)){
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
                    // Strong moves
                    if(strong_move[pkm_start_move_4[buf8]]
                            && (move_power[pkm_start_move_4[buf8]]<=1
                                || move_type[pkm_start_move_4[buf8]]>8
                                || ((move_type[pkm_start_move_4[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_4[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                || pkm_base_atk[buf8]>50)
                            && (move_effect[pkm_start_move_4[buf8]] != 0x50
                                || ((move_type[pkm_start_move_4[buf8]]==pkm_type_1[buf8] || move_type[pkm_start_move_4[buf8]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                            && (move_effect[pkm_start_move_4[buf8]] != 0xF || no_evasion_moves==false))
                    {
                        strong_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                    }
                    // Gambler moves
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                        if((move_effect[pkm_start_move_4[buf8]]==0xF && no_evasion_moves==false) || move_effect[pkm_start_move_4[buf8]]==7 || move_effect[pkm_start_move_4[buf8]]==0x24 || move_effect[pkm_start_move_4[buf8]]==0x26 || move_effect[pkm_start_move_4[buf8]]==0x34 || move_effect[pkm_start_move_4[buf8]]==0x43 || (move_effect[pkm_start_move_4[buf8]]==0x46 && move_power[pkm_start_move_4[buf8]]>=65) || move_effect[pkm_start_move_4[buf8]]==0x53 || (pkm_start_move_4[buf8]==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                        }
                        else if(move_accuracy[pkm_start_move_4[buf8]]<=0xD8 && move_power[pkm_start_move_4[buf8]]>=100 && (move_type[pkm_start_move_4[buf8]]>8 || pkm_base_atk[buf8]>50 || (move_type[pkm_start_move_4[buf8]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[pkm_start_move_4[buf8]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                            gambler_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                        }
                        else if(pkm_start_move_4[buf8]==move_high_ch[0] || pkm_start_move_4[buf8]==move_high_ch[1] || pkm_start_move_4[buf8]==move_high_ch[2] || pkm_start_move_4[buf8]==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(pkm_start_move_4[buf8]);
                        }
                    }
                }

                // TM HM Moves
                for(uint8_t j=1;j<56;j++){
                    if(move_tmhm[j]>0 && move_tmhm[j]<total_move_name){
                        move_tmhm_flag = (j-1)%8;
                        move_tmhm_byte = (j-1)/8;
                        if((1<<move_tmhm_flag) & pkm_tmhm_flags[buf8][move_tmhm_byte]){
                            // Explosion check
                            if(move_tmhm[j]==0x99) learns_explosion = true;
                            // Recover check
                            if(move_tmhm[j]==0x69) learns_recover = true;
                            // Softboiled check
                            if(move_tmhm[j]==0x87) learns_softboiled = true;
                            // Dragon Rage in Petit Cup and Pika Cup
                            if(move_tmhm[j]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                                if(no_dragon_rage==false){
                                    moves_ids_vector.push_back(move_tmhm[j]);
                                    strong_moves_ids_vector.push_back(move_tmhm[j]);
                                    learns_offensive_move = true;
                                }
                            }
                            // Rest
                            else if(move_tmhm[j]==0x9C){
                                if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                                    moves_ids_vector.push_back(move_tmhm[j]);
                                    strong_moves_ids_vector.push_back(move_tmhm[j]);
                                }
                            }
                            // Other moves
                            else if(no_weak_moves==false || weak_move[move_tmhm[j]]==false){
                                if((no_useless_moves==false || useless_move[move_tmhm[j]]==false) && (move_effect[move_tmhm[j]]!=0xF || no_evasion_moves==false)){
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
                            // Strong moves
                            if(strong_move[move_tmhm[j]]
                                    && (move_power[move_tmhm[j]]<=1
                                        || move_type[move_tmhm[j]]>8
                                        || ((move_type[move_tmhm[j]]==pkm_type_1[buf8] || move_type[move_tmhm[j]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                        || pkm_base_atk[buf8]>50)
                                    && (move_effect[move_tmhm[j]] != 0x50
                                        || ((move_type[move_tmhm[j]]==pkm_type_1[buf8] || move_type[move_tmhm[j]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                                    && (move_effect[move_tmhm[j]] != 0xF || no_evasion_moves==false))
                            {
                                strong_moves_ids_vector.push_back(move_tmhm[j]);
                            }
                            // Gambler moves
                            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                                if((move_effect[move_tmhm[j]]==0xF && no_evasion_moves==false) || move_effect[move_tmhm[j]]==7 || move_effect[move_tmhm[j]]==0x24 || move_effect[move_tmhm[j]]==0x26 || move_effect[move_tmhm[j]]==0x34 || move_effect[move_tmhm[j]]==0x43 || (move_effect[move_tmhm[j]]==0x46 && move_power[move_tmhm[j]]>=65) || move_effect[move_tmhm[j]]==0x53 || (move_tmhm[j]==95 && no_weak_moves==false)){
                                    gambler_moves_ids_vector.push_back(move_tmhm[j]);
                                }
                                else if(move_accuracy[move_tmhm[j]]<=0xD8 && move_power[move_tmhm[j]]>=100 && (move_type[move_tmhm[j]]>8 || pkm_base_atk[buf8]>50 || (move_type[move_tmhm[j]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[move_tmhm[j]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
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
                for(uint8_t j=0;j<10;j++){
                    if(pkm_rb_move[buf8][j]>0 && pkm_rb_move[buf8][j]<total_move_name && pkm_rb_lvl[buf8][j]<=cpu_trainers[cpu_trainer_id].pkm[i].lvl){
                        // Explosion check
                        if(pkm_rb_move[buf8][j]==0x99) learns_explosion = true;
                        // Recover check
                        if(pkm_rb_move[buf8][j]==0x69) learns_recover = true;
                        // Softboiled check
                        if(pkm_rb_move[buf8][j]==0x87) learns_softboiled = true;
                        // Dragon Rage in Petit Cup and Pika Cup
                        if(pkm_rb_move[buf8][j]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                            if(no_dragon_rage==false){
                                moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                                strong_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                                learns_offensive_move = true;
                            }
                        }
                        // Rest
                        else if(pkm_rb_move[buf8][j]==0x9C){
                            if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                                moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                                strong_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                            }
                        }
                        // Other moves
                        else if(no_weak_moves==false || weak_move[pkm_rb_move[buf8][j]]==false){
                            if((no_useless_moves==false || useless_move[pkm_rb_move[buf8][j]]==false) && (move_effect[pkm_rb_move[buf8][j]]!=0xF || no_evasion_moves==false)){
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
                        // Strong moves
                        if(strong_move[pkm_rb_move[buf8][j]]
                                && (move_power[pkm_rb_move[buf8][j]]<=1
                                    || move_type[pkm_rb_move[buf8][j]]>8
                                    || ((move_type[pkm_rb_move[buf8][j]]==pkm_type_1[buf8] || move_type[pkm_rb_move[buf8][j]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                    || pkm_base_atk[buf8]>50)
                                && (move_effect[pkm_rb_move[buf8][j]] != 0x50
                                    || ((move_type[pkm_rb_move[buf8][j]]==pkm_type_1[buf8] || move_type[pkm_rb_move[buf8][j]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                                && (move_effect[pkm_rb_move[buf8][j]] != 0xF || no_evasion_moves==false))
                        {
                            strong_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                        }
                        // Gambler moves
                        if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                            if((move_effect[pkm_rb_move[buf8][j]]==0xF && no_evasion_moves==false) || move_effect[pkm_rb_move[buf8][j]]==7 || move_effect[pkm_rb_move[buf8][j]]==0x24 || move_effect[pkm_rb_move[buf8][j]]==0x26 || move_effect[pkm_rb_move[buf8][j]]==0x34 || move_effect[pkm_rb_move[buf8][j]]==0x43 || (move_effect[pkm_rb_move[buf8][j]]==0x46 && move_power[pkm_rb_move[buf8][j]]>=65) || move_effect[pkm_rb_move[buf8][j]]==0x53 || (pkm_rb_move[buf8][j]==95 && no_weak_moves==false)){
                                gambler_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                            }
                            else if(move_accuracy[pkm_rb_move[buf8][j]]<=0xD8 && move_power[pkm_rb_move[buf8][j]]>=100 && (move_type[pkm_rb_move[buf8][j]]>8 || pkm_base_atk[buf8]>50 || (move_type[pkm_rb_move[buf8][j]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[pkm_rb_move[buf8][j]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                                gambler_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                            }
                            else if(pkm_rb_move[buf8][j]==move_high_ch[0] || pkm_rb_move[buf8][j]==move_high_ch[1] || pkm_rb_move[buf8][j]==move_high_ch[2] || pkm_rb_move[buf8][j]==move_high_ch[3]){
                                gambler_moves_ids_vector.push_back(pkm_rb_move[buf8][j]);
                            }
                        }
                    }
                    if(pkm_y_move[buf8][j]>0 && pkm_y_move[buf8][j]<total_move_name && pkm_y_lvl[buf8][j]<=cpu_trainers[cpu_trainer_id].pkm[i].lvl){
                        // Explosion check
                        if(pkm_y_move[buf8][j]==0x99) learns_explosion = true;
                        // Recover check
                        if(pkm_y_move[buf8][j]==0x69) learns_recover = true;
                        // Softboiled check
                        if(pkm_y_move[buf8][j]==0x87) learns_softboiled = true;
                        // Dragon Rage in Petit Cup and Pika Cup
                        if(pkm_y_move[buf8][j]==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                            if(no_dragon_rage==false){
                                moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                                strong_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                                learns_offensive_move = true;
                            }
                        }
                        // Rest
                        else if(pkm_y_move[buf8][j]==0x9C){
                            if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                                moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                                strong_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                            }
                        }
                        // Other moves
                        else if(no_weak_moves==false || weak_move[pkm_y_move[buf8][j]]==false){
                            if((no_useless_moves==false || useless_move[pkm_y_move[buf8][j]]==false) && (move_effect[pkm_y_move[buf8][j]]!=0xF || no_evasion_moves==false)){
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
                        // Strong moves
                        if(strong_move[pkm_y_move[buf8][j]]
                                && (move_power[pkm_y_move[buf8][j]]<=1
                                    || move_type[pkm_y_move[buf8][j]]>8
                                    || ((move_type[pkm_y_move[buf8][j]]==pkm_type_1[buf8] || move_type[pkm_y_move[buf8][j]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                    || pkm_base_atk[buf8]>50)
                                && (move_effect[pkm_y_move[buf8][j]] != 0x50
                                    || ((move_type[pkm_y_move[buf8][j]]==pkm_type_1[buf8] || move_type[pkm_y_move[buf8][j]]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                                && (move_effect[pkm_y_move[buf8][j]] != 0xF || no_evasion_moves==false))
                        {
                            strong_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                        }
                        // Gambler moves
                        if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                            if((move_effect[pkm_y_move[buf8][j]]==0xF && no_evasion_moves==false) || move_effect[pkm_y_move[buf8][j]]==7 || move_effect[pkm_y_move[buf8][j]]==0x24 || move_effect[pkm_y_move[buf8][j]]==0x26 || move_effect[pkm_y_move[buf8][j]]==0x34 || move_effect[pkm_y_move[buf8][j]]==0x43 || (move_effect[pkm_y_move[buf8][j]]==0x46 && move_power[pkm_y_move[buf8][j]]>=65) || move_effect[pkm_y_move[buf8][j]]==0x53 || (pkm_y_move[buf8][j]==95 && no_weak_moves==false)){
                                gambler_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                            }
                            else if(move_accuracy[pkm_y_move[buf8][j]]<=0xD8 && move_power[pkm_y_move[buf8][j]]>=100 && (move_type[pkm_y_move[buf8][j]]>8 || pkm_base_atk[buf8]>50 || (move_type[pkm_y_move[buf8][j]]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[pkm_y_move[buf8][j]]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                                gambler_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                            }
                            else if(pkm_y_move[buf8][j]==move_high_ch[0] || pkm_y_move[buf8][j]==move_high_ch[1] || pkm_y_move[buf8][j]==move_high_ch[2] || pkm_y_move[buf8][j]==move_high_ch[3]){
                                gambler_moves_ids_vector.push_back(pkm_y_move[buf8][j]);
                            }
                        }
                    }
                }
            }
            else{
                for(uint8_t cur_illegalmove=1 ; cur_illegalmove<total_move_name ; cur_illegalmove++){
                    // Explosion check
                    if(cur_illegalmove==0x99) learns_explosion = true;
                    // Recover check
                    if(cur_illegalmove==0x69) learns_recover = true;
                    // Softboiled check
                    if(cur_illegalmove==0x87) learns_softboiled = true;
                    // Dragon Rage in Petit Cup and Pika Cup
                    if(cur_illegalmove==0x52 && (cpu_trainers[cpu_trainer_id].cup_id==0 || cpu_trainers[cpu_trainer_id].cup_id==1 || cpu_trainers[cpu_trainer_id].cup_id==22 || cpu_trainers[cpu_trainer_id].cup_id==23)){
                        if(no_dragon_rage==false){
                            moves_ids_vector.push_back(cur_illegalmove);
                            strong_moves_ids_vector.push_back(cur_illegalmove);
                            learns_offensive_move = true;
                        }
                    }
                    // Rest
                    else if(cur_illegalmove==0x9C){
                        if(pkm_base_hp[buf8]>=90 && pkm_base_def[buf8]>=90 && pkm_base_spc[buf8]>=80 && buf8!=151){
                            moves_ids_vector.push_back(cur_illegalmove);
                            strong_moves_ids_vector.push_back(cur_illegalmove);
                        }
                    }
                    // Other moves
                    else if(no_weak_moves==false || weak_move[cur_illegalmove]==false){
                        if((no_useless_moves==false || useless_move[cur_illegalmove]==false) && (move_effect[cur_illegalmove]!=0xF || no_evasion_moves==false)){
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
                    // Strong moves
                    if(strong_move[cur_illegalmove]
                            && (move_power[cur_illegalmove]<=1
                                || move_type[cur_illegalmove]>8
                                || move_effect[cur_illegalmove]==0x7
                                || ((move_type[cur_illegalmove]==pkm_type_1[buf8] || move_type[cur_illegalmove]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>30)
                                || pkm_base_atk[buf8]>50)
                            && (move_effect[cur_illegalmove] != 0x50
                                || ((move_type[cur_illegalmove]==pkm_type_1[buf8] || move_type[cur_illegalmove]==pkm_type_2[buf8]) && pkm_base_atk[buf8]>60))
                            && (move_effect[cur_illegalmove] != 0xF || no_evasion_moves==false))
                    {
                        strong_moves_ids_vector.push_back(cur_illegalmove);
                    }
                    // Gambler moves
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                        if((move_effect[cur_illegalmove]==0xF && no_evasion_moves==false) || move_effect[cur_illegalmove]==7 || move_effect[cur_illegalmove]==0x24 || move_effect[cur_illegalmove]==0x26 || move_effect[cur_illegalmove]==0x34 || move_effect[cur_illegalmove]==0x43 || (move_effect[cur_illegalmove]==0x46 && move_power[cur_illegalmove]>=65) || move_effect[cur_illegalmove]==0x53 || (cur_illegalmove==95 && no_weak_moves==false)){
                            gambler_moves_ids_vector.push_back(cur_illegalmove);
                        }
                        else if(move_accuracy[cur_illegalmove]<=0xD8 && move_power[cur_illegalmove]>=100 && (move_type[cur_illegalmove]>8 || pkm_base_atk[buf8]>50 || (move_type[cur_illegalmove]==pkm_type_1[buf8] && pkm_base_atk[buf8]>30) || (move_type[cur_illegalmove]==pkm_type_2[buf8] && pkm_base_atk[buf8]>30))){
                            gambler_moves_ids_vector.push_back(cur_illegalmove);
                        }
                        else if(cur_illegalmove==move_high_ch[0] || cur_illegalmove==move_high_ch[1] || cur_illegalmove==move_high_ch[2] || cur_illegalmove==move_high_ch[3]){
                            gambler_moves_ids_vector.push_back(cur_illegalmove);
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
            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && gambler_moves_ids_vector.size()>0){
                sort(gambler_moves_ids_vector.begin(), gambler_moves_ids_vector.end());
                gambler_moves_ids_vector.erase(std::unique(gambler_moves_ids_vector.begin(), gambler_moves_ids_vector.end()), gambler_moves_ids_vector.end());
            }


            // Randomize Pokémon Moves
            // TO DO: Force offensive move / STAB move
            if(moves_ids_vector.size()>0) std::shuffle(moves_ids_vector.begin(), moves_ids_vector.end(), mt_rand);
            if(strong_moves_ids_vector.size()>0) std::shuffle(strong_moves_ids_vector.begin(), strong_moves_ids_vector.end(), mt_rand);
            if(gambler_moves_ids_vector.size()>0) std::shuffle(gambler_moves_ids_vector.begin(), gambler_moves_ids_vector.end(), mt_rand);

            bool got_offensive_move = false;
            bool got_stab_move = false;
            uint8_t offset_vector_move = 0;

            // Gambler
            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22){
                // Move 1
                cpu_pkm_ppup_1[cpu_trainer_id][i] = 3;
                if(gambler_moves_ids_vector.size()>0){
                    if(gambler_moves_ids_vector[0]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_1[cpu_trainer_id][i] = gambler_moves_ids_vector[0];
                        if(move_power[cpu_pkm_move_1[cpu_trainer_id][i]]>1){
                            got_offensive_move = true;
                            if(move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                                got_stab_move = true;
                            }
                        }
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 0x99;
                        got_offensive_move = true;
                        if(move_type[0x99] == pkm_type_1[buf8] || move_type[0x99] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else if(moves_ids_vector.size()>0){
                    if(have_offensive_move){
                        if(have_stab_move){
                            while(move_power[moves_ids_vector[offset_vector_move]]<=1 || (move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_1[buf8] && move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_2[buf8])){
                                offset_vector_move++;
                                if(offset_vector_move >= moves_ids_vector.size()){
                                    offset_vector_move--;
                                    break;
                                }
                            }
                        }
                        else{
                            while(move_power[moves_ids_vector[offset_vector_move]]<=1){
                                offset_vector_move++;
                                if(offset_vector_move >= moves_ids_vector.size()){
                                    offset_vector_move--;
                                    break;
                                }
                            }
                        }
                        cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[offset_vector_move];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[0];
                    }
                }
                else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
                     cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[buf8];
                }
                else cpu_pkm_move_1[cpu_trainer_id][i] = 1;

                // Move 2
                if(gambler_moves_ids_vector.size()>1){
                    cpu_pkm_ppup_2[cpu_trainer_id][i] = 3;
                    if(gambler_moves_ids_vector[1]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_2[cpu_trainer_id][i] = gambler_moves_ids_vector[1];
                        if(move_power[cpu_pkm_move_2[cpu_trainer_id][i]]>1){
                            got_offensive_move = true;
                            if(move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                                got_stab_move = true;
                            }
                        }
                    }
                    else{
                        cpu_pkm_move_2[cpu_trainer_id][i] = 0x99;
                        got_offensive_move = true;
                        if(move_type[0x99] == pkm_type_1[buf8] || move_type[0x99] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else{
                    cpu_pkm_ppup_2[cpu_trainer_id][i] = 0;
                    cpu_pkm_move_2[cpu_trainer_id][i] = 0;
                }

                // Move 3
                if(gambler_moves_ids_vector.size()>2){
                    cpu_pkm_ppup_3[cpu_trainer_id][i] = 3;
                    if(gambler_moves_ids_vector[2]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_3[cpu_trainer_id][i] = gambler_moves_ids_vector[2];
                        if(move_power[cpu_pkm_move_3[cpu_trainer_id][i]]>1){
                            got_offensive_move = true;
                            if(move_type[cpu_pkm_move_3[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_3[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                                got_stab_move = true;
                            }
                        }
                    }
                    else{
                        cpu_pkm_move_3[cpu_trainer_id][i] = 0x99;
                        got_offensive_move = true;
                        if(move_type[0x99] == pkm_type_1[buf8] || move_type[0x99] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else{
                    cpu_pkm_ppup_3[cpu_trainer_id][i] = 0;
                    cpu_pkm_move_3[cpu_trainer_id][i] = 0;
                }

                // Move 4
                if(gambler_moves_ids_vector.size()>3){
                    cpu_pkm_ppup_4[cpu_trainer_id][i] = 3;
                    offset_vector_move = 3;
                    // Force STAB move
                    if(have_stab_move && got_stab_move==false && learns_stab_move==true){
                        while(move_power[gambler_moves_ids_vector[offset_vector_move]]<=1 || (move_type[gambler_moves_ids_vector[offset_vector_move]]!=pkm_type_1[buf8] && move_type[gambler_moves_ids_vector[offset_vector_move]]!=pkm_type_2[buf8])){
                            offset_vector_move++;
                            if(offset_vector_move >= gambler_moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    // Force offensive move
                    else if(have_offensive_move && got_offensive_move==false && learns_offensive_move){
                        while(move_power[gambler_moves_ids_vector[offset_vector_move]]<=1){
                            offset_vector_move++;
                            if(offset_vector_move >= gambler_moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    if(gambler_moves_ids_vector[offset_vector_move]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_4[cpu_trainer_id][i] = gambler_moves_ids_vector[offset_vector_move];
                    }
                    else{
                        cpu_pkm_move_4[cpu_trainer_id][i] = 0x99;
                    }
                }
                else{
                    cpu_pkm_ppup_4[cpu_trainer_id][i] = 0;
                    cpu_pkm_move_4[cpu_trainer_id][i] = 0;
                }
            }

            // Gym Leaders
            else if(gym_leaders_pokemon
                    && (((cpu_trainers[cpu_trainer_id].cup_id==18 || cpu_trainers[cpu_trainer_id].cup_id==19
                       || cpu_trainers[cpu_trainer_id].cup_id==40 || cpu_trainers[cpu_trainer_id].cup_id==41
                       || cpu_trainer_id==83 || cpu_trainer_id==87 || cpu_trainer_id==91 || cpu_trainer_id==95
                       || cpu_trainer_id==99 || cpu_trainer_id==103 || cpu_trainer_id==107 || cpu_trainer_id==111
                       || cpu_trainer_id==209 || cpu_trainer_id==213 || cpu_trainer_id==217 || cpu_trainer_id==221
                       || cpu_trainer_id==225 || cpu_trainer_id==229 || cpu_trainer_id==233 || cpu_trainer_id==237)
                        && i<3)
                    || ((cpu_trainer_id==87 || cpu_trainer_id==213) && i<4)))
            {
                // PP Ups
                cpu_pkm_ppup_1[cpu_trainer_id][i] = 3;
                cpu_pkm_ppup_2[cpu_trainer_id][i] = 3;
                cpu_pkm_ppup_3[cpu_trainer_id][i] = 3;
                cpu_pkm_ppup_4[cpu_trainer_id][i] = 3;

                // Pokémon IDs only need to be set once
                if(i==0){
                    // Brock
                    if(cpu_trainer_id==83 || cpu_trainer_id==209){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x99;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x59;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x9D;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x22;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x7E;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x6D;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x90;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x73;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x7C;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x48;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x26;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x6D;
                    }
                    // Misty
                    if(cpu_trainer_id==87 || cpu_trainer_id==213){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x38;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x5E;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x85;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x3A;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x39;
                        if(mt_rand()%8<=1) cpu_pkm_move_2[cpu_trainer_id][1] = 0x3A;
                        else if(mt_rand()%8<=4) cpu_pkm_move_2[cpu_trainer_id][1] = 0x5E;
                        else cpu_pkm_move_2[cpu_trainer_id][1] = 0x55;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x56;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x69;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x3B;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x55;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x22;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x6D;
                        cpu_pkm_move_1[cpu_trainer_id][3] = 0x39;
                        cpu_pkm_move_2[cpu_trainer_id][3] = 0x55;
                        cpu_pkm_move_3[cpu_trainer_id][3] = 0x22;
                        cpu_pkm_move_4[cpu_trainer_id][3] = 0x56;
                    }
                    // Lt. Surge
                    if(cpu_trainer_id==91 || cpu_trainer_id==217){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x55;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x39;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x56;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x19;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x55;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x41;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x56;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x73;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x55;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x5E;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x56;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x19;
                    }
                    // Erika
                    if(cpu_trainer_id==95 || cpu_trainer_id==221){
                        if((prng_seed[0]+(cpu_trainer_id/200))%2==0){
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x4F;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x0E;
                            if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][0] = 0x50;
                            else cpu_pkm_move_3[cpu_trainer_id][0] = 0x48;
                            cpu_pkm_move_4[cpu_trainer_id][0] = 0x22;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x4F;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x0E;
                            cpu_pkm_move_3[cpu_trainer_id][0] = 0x4B;
                            if(mt_rand()%2==0) cpu_pkm_move_4[cpu_trainer_id][0] = 0x22;
                            else cpu_pkm_move_4[cpu_trainer_id][0] = 0x33;
                        }
                        if((prng_seed[1]+(cpu_trainer_id/200))%2==0){
                            if(mt_rand()%2==0) cpu_pkm_move_1[cpu_trainer_id][1] = 0x4F;
                            else cpu_pkm_move_1[cpu_trainer_id][1] = 0x4E;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x5E;
                            if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][1] = 0x48;
                            else  cpu_pkm_move_3[cpu_trainer_id][1] = 0x26;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x99;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x4F;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x4E;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x48;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x4A;
                        }
                        if((prng_seed[5]+(cpu_trainer_id/200))%3<=1){
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x22;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x55;
                            cpu_pkm_move_3[cpu_trainer_id][2] = 0x3A;
                            cpu_pkm_move_4[cpu_trainer_id][2] = 0x56;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x39;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x3A;
                            if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][2] = 0x72;
                            else cpu_pkm_move_3[cpu_trainer_id][2] = 0x97;
                            cpu_pkm_move_4[cpu_trainer_id][2] = 0x22;
                        }
                    }
                    // Koga
                    if(cpu_trainer_id==99 || cpu_trainer_id==225){
                        if((prng_seed[2]+(cpu_trainer_id/200))%2==0){
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x4F;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x4E;
                            cpu_pkm_move_3[cpu_trainer_id][0] = 0x5E;
                            cpu_pkm_move_4[cpu_trainer_id][0] = 0x48;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x38;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x3B;
                            cpu_pkm_move_3[cpu_trainer_id][0] = 0x0E;
                            cpu_pkm_move_4[cpu_trainer_id][0] = 0x7C;
                        }
                        if((prng_seed[3]+(cpu_trainer_id/200))%2==0){
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x7C;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x7E;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x55;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x99;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x7C;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x7E;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x48;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x99;
                        }
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x5E;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x56;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x45;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x09;
                    }
                    // Sabrina
                    if(cpu_trainer_id==103 || cpu_trainer_id==229){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x5E;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x56;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x73;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x69;
                        if((prng_seed[4]+(cpu_trainer_id/200))%2==0){
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x5E;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x56;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x55;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x45;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x65;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x55;
                            if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][1] = 0x6D;
                            else cpu_pkm_move_3[cpu_trainer_id][1] = 0x48;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x99;
                        }
                        if((prng_seed[5]+(cpu_trainer_id/200))%2==0){
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x5E;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x56;
                            if(mt_rand()%8<=2) cpu_pkm_move_3[cpu_trainer_id][2] = 0x3B;
                            if(mt_rand()%8<=5) cpu_pkm_move_3[cpu_trainer_id][2] = 0x55;
                            else cpu_pkm_move_3[cpu_trainer_id][2] = 0x38;
                            cpu_pkm_move_4[cpu_trainer_id][2] = 0x69;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x5E;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x4E;
                            if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][2] = 0x48;
                            else cpu_pkm_move_3[cpu_trainer_id][2] = 0x26;
                            cpu_pkm_move_4[cpu_trainer_id][2] = 0x99;
                        }
                    }
                    // Blaine
                    if(cpu_trainer_id==107 || cpu_trainer_id==233){
                        if((prng_seed[1]+(cpu_trainer_id/200))%3==0){
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x7E;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x22;
                            cpu_pkm_move_3[cpu_trainer_id][0] = 0x73;
                            cpu_pkm_move_4[cpu_trainer_id][0] = 0x61;
                        }
                        else if((prng_seed[1]+(cpu_trainer_id/200))%3==1){
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x7E;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x09;
                            cpu_pkm_move_3[cpu_trainer_id][0] = 0x22;
                            cpu_pkm_move_4[cpu_trainer_id][0] = 0x6D;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][0] = 0x7E;
                            cpu_pkm_move_2[cpu_trainer_id][0] = 0x22;
                            cpu_pkm_move_3[cpu_trainer_id][0] = 0x6D;
                            cpu_pkm_move_4[cpu_trainer_id][0] = 0x5F;
                        }
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x7E;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x41;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x26;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x61;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x22;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x7E;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x59;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0xA4;
                    }
                    // Giovanni
                    if(cpu_trainer_id==111 || cpu_trainer_id==237){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0xA3;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x3D;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x55;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0xA4;
                        if((prng_seed[0]+(cpu_trainer_id/200))%3==0){
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x59;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x9D;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x22;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x20;
                        }
                        else if((prng_seed[0]+(cpu_trainer_id/200))%3==1){
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x59;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x3B;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x57;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x20;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x59;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x9D;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x22;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x99;
                        }
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x3B;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x26;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x39;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x99;
                    }
                    // Lorelei
                    if(cpu_trainer_id==112 || cpu_trainer_id==238){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x8E;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x3B;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x5E;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x44;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x3B;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x55;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x22;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x38;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x39;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x85;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x56;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x9C;
                    }
                    // Bruno
                    if(cpu_trainer_id==113 || cpu_trainer_id==239){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x42;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x59;
                        if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][0] = 0x22;
                        else cpu_pkm_move_3[cpu_trainer_id][0] = 0x9D;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x7E;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x99;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x59;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x9D;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x22;
                        if((prng_seed[3]+(cpu_trainer_id/200))%3==0){
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x88;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x22;
                            cpu_pkm_move_3[cpu_trainer_id][2] = 0x9D;
                            cpu_pkm_move_4[cpu_trainer_id][2] = 0x74;
                        }
                        else if((prng_seed[3]+(cpu_trainer_id/200))%3==1){
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x42;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x85;
                            cpu_pkm_move_3[cpu_trainer_id][2] = 0x39;
                            if(mt_rand()%2==0) cpu_pkm_move_4[cpu_trainer_id][2] = 0x3B;
                            else cpu_pkm_move_4[cpu_trainer_id][2] = 0x8E;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][2] = 0x0E;
                            cpu_pkm_move_2[cpu_trainer_id][2] = 0x59;
                            cpu_pkm_move_3[cpu_trainer_id][2] = 0x29;
                            cpu_pkm_move_4[cpu_trainer_id][2] = 0x22;
                        }
                    }
                    // Agatha
                    if(cpu_trainer_id==114 || cpu_trainer_id==240){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x65;
                        if(mt_rand()%4==0) cpu_pkm_move_2[cpu_trainer_id][0] = 0x5E;
                        else  cpu_pkm_move_2[cpu_trainer_id][0] = 0x55;
                        if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][0] = 0x48;
                        else cpu_pkm_move_3[cpu_trainer_id][0] = 0x6D;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x99;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x65;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x5E;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x56;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x22;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x65;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0xA2;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x7C;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x48;
                    }
                    // Lance
                    if(cpu_trainer_id==115 || cpu_trainer_id==241){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x22;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x3B;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x55;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x70;
                        if((prng_seed[2]+(cpu_trainer_id/200))%3==0){
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x38;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x55;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x3B;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x22;
                        }
                        else if((prng_seed[2]+(cpu_trainer_id/200))%3==1){
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x7E;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x0E;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x59;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x22;
                        }
                        else{
                            cpu_pkm_move_1[cpu_trainer_id][1] = 0x9D;
                            cpu_pkm_move_2[cpu_trainer_id][1] = 0x59;
                            cpu_pkm_move_3[cpu_trainer_id][1] = 0x8F;
                            cpu_pkm_move_4[cpu_trainer_id][1] = 0x73;
                        }
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x78;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x22;
                        if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][2] = 0x3B;
                        else cpu_pkm_move_3[cpu_trainer_id][2] = 0x59;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x85;
                    }
                    // Rival
                    if(cpu_trainers[cpu_trainer_id].cup_id==19){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x5E;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x56;
                        cpu_pkm_move_3[cpu_trainer_id][0] = 0x73;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0x69;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x59;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x9D;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x22;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0xA4;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x4E;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x5E;
                        if(mt_rand()%2==0) cpu_pkm_move_3[cpu_trainer_id][2] = 0x48;
                        else cpu_pkm_move_3[cpu_trainer_id][2] = 0x26;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x99;
                    }
                    // Red
                    if(cpu_trainers[cpu_trainer_id].cup_id==41){
                        cpu_pkm_move_1[cpu_trainer_id][0] = 0x55;
                        cpu_pkm_move_2[cpu_trainer_id][0] = 0x39;
                        if(mt_rand()%8>0) cpu_pkm_move_3[cpu_trainer_id][0] = 0x26;
                        else cpu_pkm_move_3[cpu_trainer_id][0] = 0x13;
                        cpu_pkm_move_4[cpu_trainer_id][0] = 0xA4;
                        cpu_pkm_move_1[cpu_trainer_id][1] = 0x42;
                        cpu_pkm_move_2[cpu_trainer_id][1] = 0x85;
                        cpu_pkm_move_3[cpu_trainer_id][1] = 0x39;
                        cpu_pkm_move_4[cpu_trainer_id][1] = 0x3B;
                        cpu_pkm_move_1[cpu_trainer_id][2] = 0x22;
                        cpu_pkm_move_2[cpu_trainer_id][2] = 0x59;
                        cpu_pkm_move_3[cpu_trainer_id][2] = 0x39;
                        cpu_pkm_move_4[cpu_trainer_id][2] = 0x78;
                    }
                }
            }

            // Strong trainers
            else if(cpu_trainer_id==7 || cpu_trainer_id==15 || cpu_trainer_id==39 || cpu_trainer_id==47
                    || cpu_trainer_id==71 || cpu_trainer_id==79 || cpu_trainer_id==83 || cpu_trainer_id==87
                    || cpu_trainer_id==91 || cpu_trainer_id==95 || cpu_trainer_id==99 || cpu_trainer_id==103
                    || cpu_trainer_id==107 || cpu_trainer_id==111 || cpu_trainer_id==133 || cpu_trainer_id==141
                    || cpu_trainer_id==165 || cpu_trainer_id==173 || cpu_trainer_id==197 || cpu_trainer_id==205
                    || cpu_trainer_id==209 || cpu_trainer_id==213 || cpu_trainer_id==217 || cpu_trainer_id==221
                    || cpu_trainer_id==225 || cpu_trainer_id==229 || cpu_trainer_id==233 || cpu_trainer_id==237
                    || cpu_trainers[cpu_trainer_id].cup_id==18 || cpu_trainers[cpu_trainer_id].cup_id==19 || cpu_trainers[cpu_trainer_id].cup_id==20
                    || cpu_trainers[cpu_trainer_id].cup_id==40 || cpu_trainers[cpu_trainer_id].cup_id==41 || cpu_trainers[cpu_trainer_id].cup_id==42)
            {
                // Move 1
                cpu_pkm_ppup_1[cpu_trainer_id][i] = 3;
                if(strong_moves_ids_vector.size()>0){
                    if(strong_moves_ids_vector[0]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_1[cpu_trainer_id][i] = strong_moves_ids_vector[0];
                        if(move_power[cpu_pkm_move_1[cpu_trainer_id][i]]>1){
                            got_offensive_move = true;
                            if(move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                                got_stab_move = true;
                            }
                        }
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 0x99;
                        got_offensive_move = true;
                        if(move_type[0x99] == pkm_type_1[buf8] || move_type[0x99] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else if(moves_ids_vector.size()>0){
                    cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[0];
                    if(move_power[cpu_pkm_move_1[cpu_trainer_id][i]]>1){
                        got_offensive_move = true;
                        if(move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
                     cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[buf8];
                }
                else cpu_pkm_move_1[cpu_trainer_id][i] = 1;


                // Move 2
                if(strong_moves_ids_vector.size()>1){
                    cpu_pkm_ppup_2[cpu_trainer_id][i] = 3;
                    if(strong_moves_ids_vector[1]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_2[cpu_trainer_id][i] = strong_moves_ids_vector[1];
                        if(move_power[cpu_pkm_move_2[cpu_trainer_id][i]]>1){
                            got_offensive_move = true;
                            if(move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                                got_stab_move = true;
                            }
                        }
                    }
                    else{
                        cpu_pkm_move_2[cpu_trainer_id][i] = 0x99;
                        got_offensive_move = true;
                        if(move_type[0x99] == pkm_type_1[buf8] || move_type[0x99] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else if(moves_ids_vector.size()>1){
                    cpu_pkm_ppup_2[cpu_trainer_id][i] = 3;
                    cpu_pkm_move_2[cpu_trainer_id][i] = moves_ids_vector[1];
                    if(move_power[cpu_pkm_move_2[cpu_trainer_id][i]]>1){
                        got_offensive_move = true;
                        if(move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else{
                    cpu_pkm_ppup_2[cpu_trainer_id][i] = 0;
                    cpu_pkm_move_2[cpu_trainer_id][i] = 0;
                }


                // Move 3
                if(strong_moves_ids_vector.size()>2){
                    cpu_pkm_ppup_3[cpu_trainer_id][i] = 3;
                    offset_vector_move = 2;
                    // Force STAB move
                    if(have_stab_move && got_stab_move==false && learns_stab_move==true){
                        while(move_power[strong_moves_ids_vector[offset_vector_move]]<=1 || (move_type[strong_moves_ids_vector[offset_vector_move]]!=pkm_type_1[buf8] && move_type[strong_moves_ids_vector[offset_vector_move]]!=pkm_type_2[buf8])){
                            offset_vector_move++;
                            if(offset_vector_move >= strong_moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    // Force offensive move
                    else if(have_offensive_move && got_offensive_move==false && learns_offensive_move){
                        while(move_power[strong_moves_ids_vector[offset_vector_move]]<=1){
                            offset_vector_move++;
                            if(offset_vector_move >= strong_moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    if(strong_moves_ids_vector[offset_vector_move]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_3[cpu_trainer_id][i] = strong_moves_ids_vector[offset_vector_move];
                    }
                    else{
                        cpu_pkm_move_3[cpu_trainer_id][i] = 0x99;
                    }
                }
                else if(moves_ids_vector.size()>2){
                    cpu_pkm_ppup_3[cpu_trainer_id][i] = 3;
                    cpu_pkm_move_3[cpu_trainer_id][i] = moves_ids_vector[2];
                    if(move_power[cpu_pkm_move_3[cpu_trainer_id][i]]>1){
                        got_offensive_move = true;
                        if(move_type[cpu_pkm_move_3[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_3[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else{
                    cpu_pkm_ppup_3[cpu_trainer_id][i] = 0;
                    cpu_pkm_move_3[cpu_trainer_id][i] = 0;
                }


                // Move 4
                if(strong_moves_ids_vector.size()>3){
                    cpu_pkm_ppup_4[cpu_trainer_id][i] = 3;
                    if(offset_vector_move != 2) offset_vector_move = 2;
                    else offset_vector_move++;
                    if(learns_recover && pkm_base_atk[buf8]<60
                            && cpu_pkm_move_1[cpu_trainer_id][i]!=0x69
                            && cpu_pkm_move_2[cpu_trainer_id][i]!=0x69
                            && cpu_pkm_move_3[cpu_trainer_id][i]!=0x69){
                        cpu_pkm_move_4[cpu_trainer_id][i] = 0x69;
                    }
                    else if(learns_softboiled
                            && cpu_pkm_move_1[cpu_trainer_id][i]!=0x87
                            && cpu_pkm_move_2[cpu_trainer_id][i]!=0x87
                            && cpu_pkm_move_3[cpu_trainer_id][i]!=0x87
                            && cpu_pkm_move_1[cpu_trainer_id][i]!=0x99
                            && cpu_pkm_move_2[cpu_trainer_id][i]!=0x99
                            && cpu_pkm_move_3[cpu_trainer_id][i]!=0x99){
                        if(pkm_base_atk[buf8]<60 || learns_explosion==false){
                            cpu_pkm_move_4[cpu_trainer_id][i] = 0x87;
                        }
                        else if(learns_explosion){
                            if(mt_rand()%2==0) cpu_pkm_move_4[cpu_trainer_id][i] = 0x87;
                            else cpu_pkm_move_4[cpu_trainer_id][i] = 0x99;
                        }
                        else{
                            cpu_pkm_move_4[cpu_trainer_id][i] = strong_moves_ids_vector[offset_vector_move];
                        }
                    }
                    else if(learns_explosion
                            && (cpu_trainer_id==7 || cpu_trainer_id==133)
                            && cpu_pkm_move_1[cpu_trainer_id][i]!=0x99
                            && cpu_pkm_move_2[cpu_trainer_id][i]!=0x99
                            && cpu_pkm_move_3[cpu_trainer_id][i]!=0x99){
                        cpu_pkm_move_4[cpu_trainer_id][i] = 0x99;
                    }
                    else if(strong_moves_ids_vector[offset_vector_move]!=0x78 || learns_explosion==false){
                        cpu_pkm_move_4[cpu_trainer_id][i] = strong_moves_ids_vector[offset_vector_move];
                    }
                    else if(strong_moves_ids_vector.size()>4 && (cpu_trainer_id==7 || cpu_trainer_id==133)){
                        cpu_pkm_move_4[cpu_trainer_id][i] = strong_moves_ids_vector[4];
                    }
                    // Oh well, Explosion × 2 (will fix it better later)
                    else{
                        cpu_pkm_move_4[cpu_trainer_id][i] = 0x99;
                    }
                }
                else if(learns_explosion
                        && cpu_pkm_move_1[cpu_trainer_id][i]!=0x99
                        && cpu_pkm_move_2[cpu_trainer_id][i]!=0x99
                        && cpu_pkm_move_3[cpu_trainer_id][i]!=0x99){
                    cpu_pkm_move_4[cpu_trainer_id][i] = 0x99;
                }
                else if(moves_ids_vector.size()>3){
                    cpu_pkm_ppup_4[cpu_trainer_id][i] = 3;
                    offset_vector_move = 3;
                    // Force STAB move
                    if(have_stab_move && got_stab_move==false && learns_stab_move==true){
                        while(move_power[moves_ids_vector[offset_vector_move]]<=1 || (move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_1[buf8] && move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_2[buf8])){
                            offset_vector_move++;
                            if(offset_vector_move >= moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    // Force offensive move
                    else if(have_offensive_move && got_offensive_move==false && learns_offensive_move){
                        while(move_power[moves_ids_vector[offset_vector_move]]<=1){
                            offset_vector_move++;
                            if(offset_vector_move >= moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    cpu_pkm_move_4[cpu_trainer_id][i] = moves_ids_vector[offset_vector_move];
                }
                else{
                    cpu_pkm_ppup_4[cpu_trainer_id][i] = 0;
                    cpu_pkm_move_4[cpu_trainer_id][i] = 0;
                }
            }

            // Other trainers
            else{
                // Move 1
                if(moves_ids_vector.size()>0){
                    cpu_pkm_move_1[cpu_trainer_id][i] = moves_ids_vector[0];
                    if(move_power[cpu_pkm_move_1[cpu_trainer_id][i]]>1){
                        got_offensive_move = true;
                        if(move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_1[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else if(pkm_start_move_1[buf8] != 0 && pkm_start_move_1[buf8] < total_move_name){
                     cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[buf8];
                }
                else cpu_pkm_move_1[cpu_trainer_id][i] = 1;

                // Move 2
                if(moves_ids_vector.size()>1){
                    cpu_pkm_move_2[cpu_trainer_id][i] = moves_ids_vector[1];
                    if(move_power[cpu_pkm_move_2[cpu_trainer_id][i]]>1){
                        got_offensive_move = true;
                        if(move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_2[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else cpu_pkm_move_2[cpu_trainer_id][i] = 0;

                // Move 3
                if(moves_ids_vector.size()>2){
                    cpu_pkm_move_3[cpu_trainer_id][i] = moves_ids_vector[2];
                    if(move_power[cpu_pkm_move_3[cpu_trainer_id][i]]>1){
                        got_offensive_move = true;
                        if(move_type[cpu_pkm_move_3[cpu_trainer_id][i]] == pkm_type_1[buf8] || move_type[cpu_pkm_move_3[cpu_trainer_id][i]] == pkm_type_2[buf8]){
                            got_stab_move = true;
                        }
                    }
                }
                else cpu_pkm_move_3[cpu_trainer_id][i] = 0;

                // Move 4
                if(moves_ids_vector.size()>3){
                    offset_vector_move = 3;
                    // Force STAB move
                    if(have_stab_move && got_stab_move==false && learns_stab_move){
                        while(move_power[moves_ids_vector[offset_vector_move]]<=1 || (move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_1[buf8] && move_type[moves_ids_vector[offset_vector_move]]!=pkm_type_2[buf8])){
                            offset_vector_move++;
                            if(offset_vector_move >= moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    // Force offensive move
                    else if(have_offensive_move && got_offensive_move==false && learns_offensive_move){
                        while(move_power[moves_ids_vector[offset_vector_move]]<=1){
                            offset_vector_move++;
                            if(offset_vector_move >= moves_ids_vector.size()){
                                offset_vector_move--;
                                break;
                            }
                        }
                    }
                    cpu_pkm_move_4[cpu_trainer_id][i] = moves_ids_vector[offset_vector_move];
                }
                else cpu_pkm_move_4[cpu_trainer_id][i] = 0;
            }
        }
    }
}

void MainWindow::randomize_cpu_nicknames(std::mt19937 &mt_rand)
{
    std::uniform_int_distribution<> distrib_nick(0,9);
    uint8_t nick_id = 0;
    bool gym_leaders_pokemon = ui->checkBox_Randomizer_CPU_GLPkmn->isChecked();

    for(uint8_t cpu_trainer_id=0 ; cpu_trainer_id<current_cpu_trainers_number ; cpu_trainer_id++){
        if((cpu_trainers[cpu_trainer_id].cup_id!=18
                && cpu_trainers[cpu_trainer_id].cup_id!=19
                && cpu_trainers[cpu_trainer_id].cup_id!=40
                && cpu_trainers[cpu_trainer_id].cup_id!=41
                && cpu_trainer_id!=83
                && cpu_trainer_id!=87
                && cpu_trainer_id!=91
                && cpu_trainer_id!=95
                && cpu_trainer_id!=99
                && cpu_trainer_id!=103
                && cpu_trainer_id!=107
                && cpu_trainer_id!=111
                && cpu_trainer_id!=209
                && cpu_trainer_id!=213
                && cpu_trainer_id!=217
                && cpu_trainer_id!=221
                && cpu_trainer_id!=225
                && cpu_trainer_id!=229
                && cpu_trainer_id!=233
                && cpu_trainer_id!=237)
            || gym_leaders_pokemon==false)
        {
            for(uint8_t i=0 ; i<cpu_trainers[cpu_trainer_id].party_size; i++){
                nick_id = distrib_nick(mt_rand);
                cpu_trainers[cpu_trainer_id].pkm[i].nick = preset_nicknames[cpu_trainers[cpu_trainer_id].pkm[i].id][nick_id];
            }
        }
    }
}

void MainWindow::randomize_cpu_pkmn(std::mt19937 &mt_rand)
{
    bool strong_pkm_finals = ui->checkBox_Randomizer_CPU_StrongPkmnFinal->isChecked();
    bool gambler_luck_moves = ui->checkBox_Randomizer_CPU_GamblerMoves->isChecked();
    bool gym_leaders_pokemon = ui->checkBox_Randomizer_CPU_GLPkmn->isChecked();
    bool no_illegal_pkmn = ui->checkBox_Randomizer_CPU_NoIllegalPkmn->isChecked();
    bool no_species_clause = ui->checkBox_Randomizer_CPU_NoSpeciesClause->isChecked();

    // CPU Teams generation
    for(uint8_t cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        cpu_trainers[cpu_trainer_id].party_size=6;

        // Petit Cup
        if(is_petit_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_petitcup.begin(), pkm_ids_vector_petitcup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_petitcup_toptier.begin(), pkm_ids_vector_petitcup_toptier.end(), mt_rand);

            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_petitcup_gambler.begin(), pkm_ids_vector_petitcup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                quint8 offset_vector_pkm = 0;

                // Petit Cup Final
                if((cpu_trainer_id==7 || cpu_trainer_id==133) && strong_pkm_finals){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_petitcup_toptier[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_petitcup_toptier.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_petitcup_toptier[i];
                        pkm_ids_vector_petitcup_toptier[i]=pkm_ids_vector_petitcup_toptier[i+offset_vector_pkm];
                        pkm_ids_vector_petitcup_toptier[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_petitcup_toptier[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_petitcup_toptier[i]];
                }
                // Gambler
                else if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_petitcup_gambler[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_petitcup_gambler.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        if(offset_vector_pkm > 0){
                            buf8=pkm_ids_vector_petitcup_gambler[i];
                            pkm_ids_vector_petitcup_gambler[i]=pkm_ids_vector_petitcup_gambler[i+offset_vector_pkm];
                            pkm_ids_vector_petitcup_gambler[i+offset_vector_pkm]=buf8;
                        }
                    }
                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_petitcup_gambler[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_petitcup_gambler[i]];
                }
                // Other trainers
                else{
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_petitcup[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_petitcup.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_petitcup[i];
                        pkm_ids_vector_petitcup[i]=pkm_ids_vector_petitcup[i+offset_vector_pkm];
                        pkm_ids_vector_petitcup[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_petitcup[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_petitcup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
                if(no_species_clause){
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                        std::shuffle(pkm_ids_vector_petitcup_gambler.begin(), pkm_ids_vector_petitcup_gambler.end(), mt_rand);
                    }
                    else{
                        std::shuffle(pkm_ids_vector_petitcup.begin(), pkm_ids_vector_petitcup.end(), mt_rand);
                        std::shuffle(pkm_ids_vector_petitcup_toptier.begin(), pkm_ids_vector_petitcup_toptier.end(), mt_rand);
                    }
                }
            }
        }


        // Pika Cup
        else if(is_pika_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_pikacup.begin(), pkm_ids_vector_pikacup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_pikacup_toptier.begin(), pkm_ids_vector_pikacup_toptier.end(), mt_rand);

            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_pikacup_gambler.begin(), pkm_ids_vector_pikacup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                quint8 offset_vector_pkm = 0;

                // Pika Cup Final
                if((cpu_trainer_id==15 || cpu_trainer_id==141) && strong_pkm_finals){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_pikacup_toptier[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_pikacup_toptier.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_pikacup_toptier[i];
                        pkm_ids_vector_pikacup_toptier[i]=pkm_ids_vector_pikacup_toptier[i+offset_vector_pkm];
                        pkm_ids_vector_pikacup_toptier[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_pikacup_toptier[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_pikacup_toptier[i]];
                }
                // Gambler
                else if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_pikacup_gambler.size()>0){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_pikacup_gambler[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_pikacup_gambler.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        if(offset_vector_pkm > 0){
                            buf8=pkm_ids_vector_pikacup_gambler[i];
                            pkm_ids_vector_pikacup_gambler[i]=pkm_ids_vector_pikacup_gambler[i+offset_vector_pkm];
                            pkm_ids_vector_pikacup_gambler[i+offset_vector_pkm]=buf8;
                        }
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_pikacup_gambler[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_pikacup_gambler[i]];
                }
                // Other trainers
                else{
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_pikacup[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_pikacup.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_pikacup[i];
                        pkm_ids_vector_pikacup[i]=pkm_ids_vector_pikacup[i+offset_vector_pkm];
                        pkm_ids_vector_pikacup[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_pikacup[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_pikacup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
                if(no_species_clause){
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                        std::shuffle(pkm_ids_vector_pikacup_gambler.begin(), pkm_ids_vector_pikacup_gambler.end(), mt_rand);
                    }
                    else{
                        std::shuffle(pkm_ids_vector_pikacup.begin(), pkm_ids_vector_pikacup.end(), mt_rand);
                        std::shuffle(pkm_ids_vector_pikacup_toptier.begin(), pkm_ids_vector_pikacup_toptier.end(), mt_rand);
                    }
                }
            }
        }


        // Prime Cup
        else if(is_prime_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_primecup_toptier.begin(), pkm_ids_vector_primecup_toptier.end(), mt_rand);

            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_primecup_gambler.begin(), pkm_ids_vector_primecup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                quint8 offset_vector_pkm = 0;

                // Prime Cup Final (Mew check)
                if(cpu_trainer_id==39 || cpu_trainer_id==47 || cpu_trainer_id==165 || cpu_trainer_id==173){
                    if((cpu_trainer_id==47 || cpu_trainer_id==173) && i==0 && ui->checkBox_Randomizer_CPU_MewPrimeCup->isChecked()){
                        cpu_trainers[cpu_trainer_id].pkm[i].id = 151;
                        cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[151];
                    }
                    else if(strong_pkm_finals){
                        if(pkm_ids_vector_primecup_toptier[i] != 151){
                            cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup_toptier[i];
                            cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup_toptier[i]];
                        }
                        else{
                            cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup_toptier.back();
                            cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup_toptier.back()];
                        }
                    }
                    else{
                        if(pkm_ids_vector_primecup[i] != 151){
                            cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup[i];
                            cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup[i]];
                        }
                        else{
                            cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup.back();
                            cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup.back()];
                        }
                    }
                }
                // Gambler
                else if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_primecup_gambler.size()>0){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_primecup_gambler[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_primecup_gambler.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        if(offset_vector_pkm > 0){
                            buf8=pkm_ids_vector_primecup_gambler[i];
                            pkm_ids_vector_primecup_gambler[i]=pkm_ids_vector_primecup_gambler[i+offset_vector_pkm];
                            pkm_ids_vector_primecup_gambler[i+offset_vector_pkm]=buf8;
                        }
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup_gambler[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup_gambler[i]];
                }
                // Other trainers
                else{
                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
                if(no_species_clause){
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                        std::shuffle(pkm_ids_vector_primecup_gambler.begin(), pkm_ids_vector_primecup_gambler.end(), mt_rand);
                    }
                    else{
                        std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
                        std::shuffle(pkm_ids_vector_primecup_toptier.begin(), pkm_ids_vector_primecup_toptier.end(), mt_rand);
                    }
                }
            }
        }


        // Poké Cup
        else if(is_poke_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_pokecup.begin(), pkm_ids_vector_pokecup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_pokecup_toptier.begin(), pkm_ids_vector_pokecup_toptier.end(), mt_rand);

            if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                std::shuffle(pkm_ids_vector_pokecup_gambler.begin(), pkm_ids_vector_pokecup_gambler.end(), mt_rand);
            }

            // Change Pokémon team
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                quint8 offset_vector_pkm = 0;

                // Poké Cup Final
                if((cpu_trainer_id==71 || cpu_trainer_id==79 || cpu_trainer_id==197 || cpu_trainer_id==205) && strong_pkm_finals){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_pokecup_toptier[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_pokecup_toptier.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_pokecup_toptier[i];
                        pkm_ids_vector_pokecup_toptier[i]=pkm_ids_vector_pokecup_toptier[i+offset_vector_pkm];
                        pkm_ids_vector_pokecup_toptier[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_pokecup_toptier[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_pokecup_toptier[i]];
                }
                // Gambler
                else if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_pokecup_gambler.size()>0){
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_pokecup_gambler[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_pokecup_gambler.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        if(offset_vector_pkm > 0){
                            buf8=pkm_ids_vector_pokecup_gambler[i];
                            pkm_ids_vector_pokecup_gambler[i]=pkm_ids_vector_pokecup_gambler[i+offset_vector_pkm];
                            pkm_ids_vector_pokecup_gambler[i+offset_vector_pkm]=buf8;
                        }
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_pokecup_gambler[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_pokecup_gambler[i]];
                }
                // Other trainers
                else{
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_pokecup[i+offset_vector_pkm]]){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_pokecup.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_pokecup[i];
                        pkm_ids_vector_pokecup[i]=pkm_ids_vector_pokecup[i+offset_vector_pkm];
                        pkm_ids_vector_pokecup[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_pokecup[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_pokecup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
                if(no_species_clause){
                    if(gambler_luck_moves && cpu_trainers[cpu_trainer_id].sprite_id==0x22 && pkm_ids_vector_petitcup_gambler.size()>0){
                        std::shuffle(pkm_ids_vector_pokecup_gambler.begin(), pkm_ids_vector_pokecup_gambler.end(), mt_rand);
                    }
                    else{
                        std::shuffle(pkm_ids_vector_pokecup.begin(), pkm_ids_vector_pokecup.end(), mt_rand);
                        std::shuffle(pkm_ids_vector_pokecup_toptier.begin(), pkm_ids_vector_pokecup_toptier.end(), mt_rand);
                    }
                }
            }
        }


        // Gym Leader Castle
        else if(is_glc_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
            std::shuffle(pkm_ids_vector_primecup_toptier.begin(), pkm_ids_vector_primecup_toptier.end(), mt_rand);
            std::shuffle(pkm_ids_vector_glc_lowminlv.begin(), pkm_ids_vector_glc_lowminlv.end(), mt_rand);

            // Change Pokémon team
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                quint8 offset_vector_pkm = 0;
                quint8 glc_index = 0;

                // Gym Leaders / Elite 4 / Rival
                if((cpu_trainers[cpu_trainer_id].cup_id==18
                        || cpu_trainers[cpu_trainer_id].cup_id==19
                        || cpu_trainers[cpu_trainer_id].cup_id==40
                        || cpu_trainers[cpu_trainer_id].cup_id==41
                        || cpu_trainer_id==83
                        || cpu_trainer_id==87
                        || cpu_trainer_id==91
                        || cpu_trainer_id==95
                        || cpu_trainer_id==99
                        || cpu_trainer_id==103
                        || cpu_trainer_id==107
                        || cpu_trainer_id==111
                        || cpu_trainer_id==209
                        || cpu_trainer_id==213
                        || cpu_trainer_id==217
                        || cpu_trainer_id==221
                        || cpu_trainer_id==225
                        || cpu_trainer_id==229
                        || cpu_trainer_id==233
                        || cpu_trainer_id==237)
                    && (strong_pkm_finals || gym_leaders_pokemon))
                {
                    if(gym_leaders_pokemon && i==0){
                        // Brock
                        if(cpu_trainer_id==83 || cpu_trainer_id==209){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 95;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "ONIX";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 38;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "Shapeshift";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 42;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "GOLBAT";
                        }
                        // Misty
                        if(cpu_trainer_id==87 || cpu_trainer_id==213){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 54;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "PSYDUCK";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 121;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "STARMIE";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 131;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "LAPRAS";
                            cpu_trainers[cpu_trainer_id].pkm[3].id = 148;
                            cpu_trainers[cpu_trainer_id].pkm[3].nick = "DRAGONAIR";
                        }
                        // Lt. Surge
                        if(cpu_trainer_id==91 || cpu_trainer_id==217){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 26;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "RAICHU";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 145;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "ZAPDOS";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 125;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "ELECTABUZZ";
                        }
                        // Erika
                        if(cpu_trainer_id==95 || cpu_trainer_id==221){
                            if((prng_seed[0]+(cpu_trainer_id/200))%2==0){
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 45;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "VILEPLUME";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 71;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "VICTREEBEL";
                            }
                            if((prng_seed[1]+(cpu_trainer_id/200))%2==0){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 103;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "EXEGGUTOR";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 114;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "Angela";
                            }
                            if((prng_seed[5]+(cpu_trainer_id/200))%3<=1){
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 36;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "CLEFABLE";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 134;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "VAPOREON";
                            }
                        }
                        // Koga
                        if(cpu_trainer_id==99 || cpu_trainer_id==225){
                            if((prng_seed[2]+(cpu_trainer_id/200))%2==0){
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 49;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "VENOMOTH";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 73;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "TENTACRUEL";
                            }
                            if((prng_seed[3]+(cpu_trainer_id/200))%2==0){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 110;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "WEEZING";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 89;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "MUK";
                            }
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 97;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "HYPNO";
                        }
                        // Sabrina
                        if(cpu_trainer_id==103 || cpu_trainer_id==229){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 65;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "ALAKAZAM";
                            if((prng_seed[4]+(cpu_trainer_id/200))%2==0){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 122;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "MR. MIME";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 93;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "HAUNTER";
                            }
                            if((prng_seed[5]+(cpu_trainer_id/200))%2==0){
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 121;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "STARMIE";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 103;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "EXEGGUTOR";
                            }
                        }
                        // Blaine
                        if(cpu_trainer_id==107 || cpu_trainer_id==233){
                            if((prng_seed[1]+(cpu_trainer_id/200))%3==0){
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 59;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "RK9";
                            }
                            else if((prng_seed[1]+(cpu_trainer_id/200))%3==1){
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 126;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "MAGMAR";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[0].id = 38;
                                cpu_trainers[cpu_trainer_id].pkm[0].nick = "NINETALES";
                            }
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 146;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "MOLTRES";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 128;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "TAUROS";
                        }
                        // Giovanni
                        if(cpu_trainer_id==111 || cpu_trainer_id==237){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 53;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "PERSIAN";
                            if((prng_seed[0]+(cpu_trainer_id/200))%3==0){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 112;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "RHYDON";
                            }
                            else if((prng_seed[0]+(cpu_trainer_id/200))%3==1){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 34;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "NIDOKING";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 76;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "GOLEM";
                            }
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 91;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "CLOYSTER";
                        }
                        // Lorelei
                        if(cpu_trainer_id==112 || cpu_trainer_id==238){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 124;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "JYNX";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 131;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "LAPRAS";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 80;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "SLOWBRO";
                        }
                        // Bruno
                        if(cpu_trainer_id==113 || cpu_trainer_id==239){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 68;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "MACHAMP";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 95;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "ONIX";
                            if((prng_seed[3]+(cpu_trainer_id/200))%3==0){
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 106;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "HITMONLEE";
                            }
                            else if((prng_seed[3]+(cpu_trainer_id/200))%3==1){
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 62;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "POLIWRATH";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[2].id = 127;
                                cpu_trainers[cpu_trainer_id].pkm[2].nick = "PINSIR";
                            }
                        }
                        // Agatha
                        if(cpu_trainer_id==114 || cpu_trainer_id==240){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 94;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "Gengar";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 36;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "NotGengar";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 42;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "Dracula";
                        }
                        // Lance
                        if(cpu_trainer_id==115 || cpu_trainer_id==241){
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 149;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "Dragon";
                            if((prng_seed[2]+(cpu_trainer_id/200))%3==0){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 130;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "NotDragon";
                            }
                            else if((prng_seed[2]+(cpu_trainer_id/200))%3==1){
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 6;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "NextDragon";
                            }
                            else{
                                cpu_trainers[cpu_trainer_id].pkm[1].id = 142;
                                cpu_trainers[cpu_trainer_id].pkm[1].nick = "NotDragon";
                            }
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 143;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "Hiya!";
                        }
                        // Rival
                        if(cpu_trainers[cpu_trainer_id].cup_id==19){
                            cpu_trainers[cpu_trainer_id].sprite_id = 14;
                            cpu_trainers[cpu_trainer_id].name = "BLUE";
                            ui->comboBox_CPU_Trainer->setItemText(cpu_trainer_id,cpu_trainers[cpu_trainer_id].name);
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 65;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "Kazam";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 112;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "Don";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 103;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "Eggy";
                        }
                        // Red
                        if(cpu_trainers[cpu_trainer_id].cup_id==41){
                            cpu_trainers[cpu_trainer_id].sprite_id = 1;
                            cpu_trainers[cpu_trainer_id].name = "RED";
                            ui->comboBox_CPU_Trainer->setItemText(cpu_trainer_id,cpu_trainers[cpu_trainer_id].name);
                            cpu_trainers[cpu_trainer_id].pkm[0].id = 25;
                            cpu_trainers[cpu_trainer_id].pkm[0].nick = "Pika";
                            cpu_trainers[cpu_trainer_id].pkm[1].id = 62;
                            cpu_trainers[cpu_trainer_id].pkm[1].nick = "Poli";
                            cpu_trainers[cpu_trainer_id].pkm[2].id = 143;
                            cpu_trainers[cpu_trainer_id].pkm[2].nick = "Snor";
                        }
                    }
                    // Other Pokémon
                    else if((i>=3 && cpu_trainer_id!=87 && cpu_trainer_id!=213) || i>=4 || gym_leaders_pokemon==false){
                        if(strong_pkm_finals){
                            if(glc_level_min > 10){
                                if(no_species_clause==false){
                                    while((cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_primecup_toptier[i+offset_vector_pkm]]
                                           || (gym_leaders_pokemon && pkm_ids_vector_primecup_toptier[i+offset_vector_pkm] == cpu_trainers[cpu_trainer_id].pkm[0].id)
                                           || (gym_leaders_pokemon && pkm_ids_vector_primecup_toptier[i+offset_vector_pkm] == cpu_trainers[cpu_trainer_id].pkm[1].id)
                                           || (gym_leaders_pokemon && pkm_ids_vector_primecup_toptier[i+offset_vector_pkm] == cpu_trainers[cpu_trainer_id].pkm[2].id))){
                                        offset_vector_pkm++;
                                        if(offset_vector_pkm >= pkm_ids_vector_primecup_toptier.size()){
                                            offset_vector_pkm--;
                                            break;
                                        }
                                    }
                                    buf8=pkm_ids_vector_primecup_toptier[i];
                                    pkm_ids_vector_primecup_toptier[i]=pkm_ids_vector_primecup_toptier[i+offset_vector_pkm];
                                    pkm_ids_vector_primecup_toptier[i+offset_vector_pkm]=buf8;
                                }

                                cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup_toptier[i];
                                cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup_toptier[i]];
                            }
                            else{
                                if(cpu_trainer_id != 87 && cpu_trainer_id!=213) glc_index = i-3;
                                else glc_index = i-4;
                                if(no_species_clause==false){
                                    while((cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_glc_lowminlv[glc_index+offset_vector_pkm]]
                                           || (gym_leaders_pokemon && pkm_ids_vector_glc_lowminlv[glc_index+offset_vector_pkm] == cpu_trainers[cpu_trainer_id].pkm[0].id)
                                           || (gym_leaders_pokemon && pkm_ids_vector_glc_lowminlv[glc_index+offset_vector_pkm] == cpu_trainers[cpu_trainer_id].pkm[1].id)
                                           || (gym_leaders_pokemon && pkm_ids_vector_glc_lowminlv[glc_index+offset_vector_pkm] == cpu_trainers[cpu_trainer_id].pkm[2].id))){
                                        offset_vector_pkm++;
                                        if(offset_vector_pkm >= pkm_ids_vector_glc_lowminlv.size()){
                                            offset_vector_pkm--;
                                            break;
                                        }
                                    }
                                    buf8=pkm_ids_vector_glc_lowminlv[glc_index];
                                    pkm_ids_vector_glc_lowminlv[glc_index]=pkm_ids_vector_glc_lowminlv[glc_index+offset_vector_pkm];
                                    pkm_ids_vector_glc_lowminlv[glc_index+offset_vector_pkm]=buf8;
                                }

                                cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_glc_lowminlv[glc_index];
                                cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_glc_lowminlv[glc_index]];
                            }
                        }
                        else{
                            if(no_illegal_pkmn){
                                while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_primecup[i+offset_vector_pkm]]){
                                    offset_vector_pkm++;
                                    if(offset_vector_pkm >= pkm_ids_vector_primecup.size()){
                                        offset_vector_pkm--;
                                        break;
                                    }
                                }
                                buf8=pkm_ids_vector_primecup[i];
                                pkm_ids_vector_primecup[i]=pkm_ids_vector_primecup[i+offset_vector_pkm];
                                pkm_ids_vector_primecup[i+offset_vector_pkm]=buf8;
                            }

                            cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup[i];
                            cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup[i]];
                        }
                    }
                }
                // Other trainers
                else{
                    if(no_illegal_pkmn){
                        while(cpu_trainers[cpu_trainer_id].pkm[i].lvl<pkm_min_level[pkm_ids_vector_primecup[i+offset_vector_pkm]] && (i+offset_vector_pkm < pkm_ids_vector_primecup.size())){
                            offset_vector_pkm++;
                            if(offset_vector_pkm >= pkm_ids_vector_primecup.size()){
                                offset_vector_pkm--;
                                break;
                            }
                        }
                        buf8=pkm_ids_vector_primecup[i];
                        pkm_ids_vector_primecup[i]=pkm_ids_vector_primecup[i+offset_vector_pkm];
                        pkm_ids_vector_primecup[i+offset_vector_pkm]=buf8;
                    }

                    cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup[i];
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup[i]];
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }


        // Vs Mewtwo
        else if(is_mewtwo_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_vs_mewtwo.begin(), pkm_ids_vector_vs_mewtwo.end(), mt_rand);
            std::shuffle(pkm_ids_vector_vs_mewtwo_toptier.begin(), pkm_ids_vector_vs_mewtwo_toptier.end(), mt_rand);

            // Change Pokémon team
            if(ui->checkBox_Randomizer_CPU_MewtwoFullParty->isChecked() == false){
                cpu_trainers[cpu_trainer_id].party_size = 1;
            }
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                if(i==0 && ui->checkBox_Randomizer_CPU_MewtwoMewtwo->isChecked()){
                    cpu_trainers[cpu_trainer_id].pkm[i].id = 150;
                    cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[150];
                }
                else if(strong_pkm_finals){
                    if(pkm_ids_vector_vs_mewtwo_toptier[i] != 150){
                        cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_vs_mewtwo_toptier[i];
                        cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_vs_mewtwo_toptier[i]];
                    }
                    else{
                        cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_vs_mewtwo_toptier.back();
                        cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_vs_mewtwo_toptier.back()];
                    }
                }
                else{
                    if(pkm_ids_vector_vs_mewtwo[i] != 150){
                        cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_vs_mewtwo[i];
                        cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_vs_mewtwo[i]];
                    }
                    else{
                        cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_vs_mewtwo.back();
                        cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_vs_mewtwo.back()];
                    }
                }

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }

        }


        // Battle Now: Lv 2 to Lv 100
        else if(is_battle_now_trainer(cpu_trainers[cpu_trainer_id])){
            std::shuffle(pkm_ids_vector_primecup.begin(), pkm_ids_vector_primecup.end(), mt_rand);
            // Change Pokémon team
            for(uint8_t i=0;i<cpu_trainers[cpu_trainer_id].party_size;i++){
                cpu_trainers[cpu_trainer_id].pkm[i].id = pkm_ids_vector_primecup[i];
                cpu_trainers[cpu_trainer_id].pkm[i].nick = pkm_name[pkm_ids_vector_primecup[i]];

                // FAIL-SAFE: Set a basic move if none is set
                if(cpu_pkm_move_1[cpu_trainer_id][i] == 0 || cpu_pkm_move_1[cpu_trainer_id][i] > total_move_name){
                    if(pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] != 0 && pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id] < total_move_name){
                        cpu_pkm_move_1[cpu_trainer_id][i] = pkm_start_move_1[cpu_trainers[cpu_trainer_id].pkm[i].id];
                    }
                    else{
                        cpu_pkm_move_1[cpu_trainer_id][i] = 1;
                    }
                }
            }
        }

        cpu_pkm_experience[cpu_trainer_id][0] = calc_experience(pkm_growth_rate[cpu_trainers[cpu_trainer_id].pkm[0].id],cpu_trainers[cpu_trainer_id].pkm[0].lvl);
        cpu_pkm_experience[cpu_trainer_id][1] = calc_experience(pkm_growth_rate[cpu_trainers[cpu_trainer_id].pkm[1].id],cpu_trainers[cpu_trainer_id].pkm[1].lvl);
        cpu_pkm_experience[cpu_trainer_id][2] = calc_experience(pkm_growth_rate[cpu_trainers[cpu_trainer_id].pkm[2].id],cpu_trainers[cpu_trainer_id].pkm[2].lvl);
        cpu_pkm_experience[cpu_trainer_id][3] = calc_experience(pkm_growth_rate[cpu_trainers[cpu_trainer_id].pkm[3].id],cpu_trainers[cpu_trainer_id].pkm[3].lvl);
        cpu_pkm_experience[cpu_trainer_id][4] = calc_experience(pkm_growth_rate[cpu_trainers[cpu_trainer_id].pkm[4].id],cpu_trainers[cpu_trainer_id].pkm[4].lvl);
        cpu_pkm_experience[cpu_trainer_id][5] = calc_experience(pkm_growth_rate[cpu_trainers[cpu_trainer_id].pkm[5].id],cpu_trainers[cpu_trainer_id].pkm[5].lvl);
    }
}

void MainWindow::randomize_cpu_sprites(std::mt19937 &mt_rand)
{
    std::uniform_int_distribution<> rand_sprite(15,51);
    for(uint8_t cpu_trainer_id=0;cpu_trainer_id<current_cpu_trainers_number;cpu_trainer_id++){
        // Not Gym Leaders / Elite 4 / Rival / Mewtwo
        if((cpu_trainers[cpu_trainer_id].cup_id!=18
                && cpu_trainers[cpu_trainer_id].cup_id!=19
                && cpu_trainers[cpu_trainer_id].cup_id!=20
                && cpu_trainers[cpu_trainer_id].cup_id!=40
                && cpu_trainers[cpu_trainer_id].cup_id!=41
                && cpu_trainers[cpu_trainer_id].cup_id!=42
                && cpu_trainer_id!=83
                && cpu_trainer_id!=87
                && cpu_trainer_id!=91
                && cpu_trainer_id!=95
                && cpu_trainer_id!=99
                && cpu_trainer_id!=103
                && cpu_trainer_id!=107
                && cpu_trainer_id!=111
                && cpu_trainer_id!=209
                && cpu_trainer_id!=213
                && cpu_trainer_id!=217
                && cpu_trainer_id!=221
                && cpu_trainer_id!=225
                && cpu_trainer_id!=229
                && cpu_trainer_id!=233
                && cpu_trainer_id!=237)){
            cpu_trainers[cpu_trainer_id].sprite_id = rand_sprite(mt_rand);
            if(ui->checkBox_Randomizer_CPU_Names->isChecked() == false){
                cpu_trainers[cpu_trainer_id].name = preset_trainers_names[cpu_trainers[cpu_trainer_id].sprite_id][0];
                ui->comboBox_CPU_Trainer->setItemText(cpu_trainer_id,cpu_trainers[cpu_trainer_id].name);
            }
        }
    }
}

void MainWindow::randomize_cpu_trainer_names(std::mt19937 &mt_rand)
{
    std::uniform_int_distribution<> distrib_tnames(0,4);
    uint8_t tname_id = 0;
    bool gym_leaders_pokemon = ui->checkBox_Randomizer_CPU_GLPkmn->isChecked();

    for(uint8_t cpu_trainer_id=0 ; cpu_trainer_id<current_cpu_trainers_number ; cpu_trainer_id++){
        // Not Blue / Red
        if((cpu_trainers[cpu_trainer_id].cup_id!=19 && cpu_trainers[cpu_trainer_id].cup_id!=41) || gym_leaders_pokemon==false){
            tname_id = distrib_tnames(mt_rand);
            cpu_trainers[cpu_trainer_id].name = preset_trainers_names[cpu_trainers[cpu_trainer_id].sprite_id][tname_id];
            ui->comboBox_CPU_Trainer->setItemText(cpu_trainer_id,cpu_trainers[cpu_trainer_id].name);
        }
    }
}
