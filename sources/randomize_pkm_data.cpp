#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_pkm_base_stats(std::mt19937 &mt_rand)
{
    // Base Stat Total ranges definition
    std::uniform_int_distribution<> rand_bst_basic(bstmin_basic,bstmax_basic);
    std::uniform_int_distribution<> rand_bst_stage1(bstmin_stage1,bstmax_stage1);
    std::uniform_int_distribution<> rand_bst_fullevo(bstmin_fullevo,bstmax_fullevo);
    std::uniform_int_distribution<> rand_bst_legend(bstmin_legend,bstmax_legend);
    std::array<int,5> stat_order {STAT_HP,STAT_ATK,STAT_DEF,STAT_SPC,STAT_SPEED};

    for(short i=1;i<=total_pkm_name;i++) {
        // Make sure that submitted Base Stats ranges can produce results within BST range
        switch (pkm_evo_stage[i]) {
        case 0:
            buf16 = bstmin_basic;
            break;
        case 1:
            buf16 = bstmin_stage1;
            break;
        case 2:
            buf16 = bstmin_fullevo;
            break;
        case 3:
            buf16 = bstmin_legend;
            break;
        default:
            buf16 = bstmin_basic;
            break;
        }

        if(bsmin_total <= buf16) {
            switch (pkm_evo_stage[i]) {
            case 0:
                buf16 = bstmax_basic;
                break;
            case 1:
                buf16 = bstmax_stage1;
                break;
            case 2:
                buf16 = bstmax_fullevo;
                break;
            case 3:
                buf16 = bstmax_legend;
                break;
            default:
                buf16 = bstmax_basic;
                break;
            }

            if(bsmax_total >= buf16) bufbool = true;
            else bufbool = false;
        }
        else bufbool = false;

        if(bufbool) {
            // BST roll
            switch (pkm_evo_stage[i]) {
            case 0:
                bst_temp = rand_bst_basic(mt_rand);
                break;
            case 1:
                bst_temp = rand_bst_stage1(mt_rand);
                break;
            case 2:
                bst_temp = rand_bst_fullevo(mt_rand);
                break;
            case 3:
                if(i < 150) bst_temp = rand_bst_legend(mt_rand);
                // Mewtwo
                else if(i == 150) {
                    if(bsmin_total <= (bstmax_legend+80) && bsmax_total >= (bstmax_legend+80)) bst_temp = bstmax_legend+80;
                    else bst_temp = std::max(bsmax_total,bstmax_legend);
                }
                // Mew
                else bst_temp = bstmax_legend;
                break;
            default:
                bst_temp = rand_bst_basic(mt_rand);
                break;
            }

            // Randomize stat order to ensure equiprobability
            std::shuffle(stat_order.begin(), stat_order.end(), mt_rand);

            // Modified Base Stats flags
            buf8 = 0;

            for(short j=0;j<4;j++) {
                // Remaining Base Stats points to allocate
                buf16 = bst_temp;
                buf16s = bst_temp;

                // Randomize stats, check if we need to limit the BS range to reach BST at every iteration
                switch(stat_order[j]) {
                case STAT_HP:
                {
                    // Set BaseHP flag
                    buf8 ^= 1;

                    // if(bsmin_hp == bsmax_hp), just set the stat
                    if(bsmin_hp == bsmax_hp) pkm_base_hp[i] = bsmax_hp;
                    else {
                        // Define min-max range for Base HP
                        // min
                        if((buf8&2) == 0) buf16s -= bsmax_atk;
                        if((buf8&4) == 0) buf16s -= bsmax_def;
                        if((buf8&8) == 0) buf16s -= bsmax_spc;
                        if((buf8&16) == 0) buf16s -= bsmax_speed;

                        if(buf16s < bsmin_hp) buf16s = bsmin_hp;
                        else if(buf16s > bsmax_hp) buf16s = bsmax_hp;

                        // max
                        if((buf8&2) == 0) buf16 -= bsmin_atk;
                        if((buf8&4) == 0) buf16 -= bsmin_def;
                        if((buf8&8) == 0) buf16 -= bsmin_spc;
                        if((buf8&16) == 0) buf16 -= bsmin_speed;

                        if(buf16 > bsmax_hp) buf16 = bsmax_hp;
                        else if(buf16 < bsmin_hp) buf16 = bsmin_hp;

                        // Base HP roll
                        std::uniform_int_distribution<> rand_bs_hp(buf16s,buf16);
                        pkm_base_hp[i] = rand_bs_hp(mt_rand);
                    }
                    bst_temp -= pkm_base_hp[i];
                    break;
                }
                case STAT_ATK:
                {
                    // Set BaseATK flag
                    buf8 ^= 2;

                    // if(bsmin_atk == bsmax_atk), just set the stat
                    if(bsmin_atk == bsmax_atk) pkm_base_atk[i] = bsmax_atk;
                    else {
                        // Define min-max range for Base ATK
                        // min
                        if((buf8&1) == 0) buf16s -= bsmax_hp;
                        if((buf8&4) == 0) buf16s -= bsmax_def;
                        if((buf8&8) == 0) buf16s -= bsmax_spc;
                        if((buf8&16) == 0) buf16s -= bsmax_speed;

                        if(buf16s < bsmin_atk) buf16s = bsmin_atk;
                        else if(buf16s > bsmax_atk) buf16s = bsmax_atk;

                        // max
                        if((buf8&1) == 0) buf16 -= bsmax_hp;
                        if((buf8&4) == 0) buf16 -= bsmin_def;
                        if((buf8&8) == 0) buf16 -= bsmin_spc;
                        if((buf8&16) == 0) buf16 -= bsmin_speed;

                        if(buf16 > bsmax_atk) buf16 = bsmax_atk;
                        else if(buf16 < bsmin_atk) buf16 = bsmin_atk;

                        // Base ATK roll
                        std::uniform_int_distribution<> rand_bs_atk(buf16s,buf16);
                        pkm_base_atk[i] = rand_bs_atk(mt_rand);
                    }
                    bst_temp -= pkm_base_atk[i];
                    break;
                }
                case STAT_DEF:
                {
                    // Set BaseDEF flag
                    buf8 ^= 4;

                    // if(bsmin_def == bsmax_def), just set the stat
                    if(bsmin_def == bsmax_def) pkm_base_def[i] = bsmax_def;
                    else {
                        // Define min-max range for Base DEF
                        // min
                        if((buf8&1) == 0) buf16s -= bsmax_hp;
                        if((buf8&2) == 0) buf16s -= bsmax_atk;
                        if((buf8&8) == 0) buf16s -= bsmax_spc;
                        if((buf8&16) == 0) buf16s -= bsmax_speed;

                        if(buf16s < bsmin_def) buf16s = bsmin_def;
                        else if(buf16s > bsmax_def) buf16s = bsmax_def;

                        // max
                        if((buf8&1) == 0) buf16 -= bsmax_hp;
                        if((buf8&2) == 0) buf16 -= bsmin_atk;
                        if((buf8&8) == 0) buf16 -= bsmin_spc;
                        if((buf8&16) == 0) buf16 -= bsmin_speed;

                        if(buf16 > bsmax_def) buf16 = bsmax_def;
                        else if(buf16 < bsmin_def) buf16 = bsmin_def;

                        // Base DEF roll
                        std::uniform_int_distribution<> rand_bs_def(buf16s,buf16);
                        pkm_base_def[i] = rand_bs_def(mt_rand);
                    }
                    bst_temp -= pkm_base_def[i];
                    break;
                }
                case STAT_SPC:
                {
                    // Set BaseSPC flag
                    buf8 ^= 8;

                    // if(bsmin_spc == bsmax_spc), just set the stat
                    if(bsmin_spc == bsmax_spc) pkm_base_spc[i] = bsmax_spc;
                    else {
                        // Define min-max range for Base SPC
                        // min
                        if((buf8&1) == 0) buf16s -= bsmax_hp;
                        if((buf8&2) == 0) buf16s -= bsmax_atk;
                        if((buf8&4) == 0) buf16s -= bsmax_def;
                        if((buf8&16) == 0) buf16s -= bsmax_speed;

                        if(buf16s < bsmin_spc) buf16s = bsmin_spc;
                        else if(buf16s > bsmax_spc) buf16s = bsmax_spc;

                        // max
                        if((buf8&1) == 0) buf16 -= bsmax_hp;
                        if((buf8&2) == 0) buf16 -= bsmin_atk;
                        if((buf8&4) == 0) buf16 -= bsmin_def;
                        if((buf8&16) == 0) buf16 -= bsmin_speed;

                        if(buf16 > bsmax_spc) buf16 = bsmax_spc;
                        else if(buf16 < bsmin_spc) buf16 = bsmin_spc;

                        // Base SPC roll
                        std::uniform_int_distribution<> rand_bs_spc(buf16s,buf16);
                        pkm_base_spc[i] = rand_bs_spc(mt_rand);
                    }
                    bst_temp -= pkm_base_spc[i];
                    break;
                }
                case STAT_SPEED:
                {
                    // Set BaseSPEED flag
                    buf8 ^= 16;

                    // if(bsmin_speed == bsmax_speed), just set the stat
                    if(bsmin_speed == bsmax_speed) pkm_base_speed[i] = bsmax_speed;
                    else {
                        // Define min-max range for Base SPEED
                        // min
                        if((buf8&1) == 0) buf16s -= bsmax_hp;
                        if((buf8&2) == 0) buf16s -= bsmax_atk;
                        if((buf8&4) == 0) buf16s -= bsmax_def;
                        if((buf8&8) == 0) buf16s -= bsmax_spc;

                        if(buf16s < bsmin_speed) buf16s = bsmin_speed;
                        else if(buf16s > bsmax_speed) buf16s = bsmax_speed;

                        // max
                        if((buf8&1) == 0) buf16 -= bsmax_hp;
                        if((buf8&2) == 0) buf16 -= bsmin_atk;
                        if((buf8&4) == 0) buf16 -= bsmin_def;
                        if((buf8&8) == 0) buf16 -= bsmin_spc;

                        if(buf16 > bsmax_speed) buf16 = bsmax_speed;
                        else if(buf16 < bsmin_speed) buf16 = bsmin_speed;

                        // Base SPEED roll
                        std::uniform_int_distribution<> rand_bs_speed(buf16s,buf16);
                        pkm_base_speed[i] = rand_bs_speed(mt_rand);
                    }
                    bst_temp -= pkm_base_speed[i];
                    break;
                }
                }
            }

            // Set last Base Stat
            switch(stat_order[4]) {
            case STAT_HP:
                pkm_base_hp[i] = bst_temp;
                break;
            case STAT_ATK:
                pkm_base_atk[i] = bst_temp;
                break;
            case STAT_DEF:
                pkm_base_def[i] = bst_temp;
                break;
            case STAT_SPC:
                pkm_base_spc[i] = bst_temp;
                break;
            case STAT_SPEED:
                pkm_base_speed[i] = bst_temp;
                break;
            }
        }
    }
}

void MainWindow::randomize_pkm_learnsets(std::mt19937 &mt_rand)
{
    if(total_move_name > 4){
        bool noSpore = ui->Randomize_PkmnData_NoSpore->isChecked();
        bool noAmnesia = ui->Randomize_PkmnData_NoAmnesia->isChecked();
        bool noRecover = ui->Randomize_PkmnData_NoRecover->isChecked();
        std::uniform_int_distribution<> rand_move(1,total_move_name);

        // Initialize randomized moves vector
        std::vector<quint8> vec_randomized_moves;

        // Initialize STAB moves matrix
        std::vector<std::vector<uint8_t> > mat_stab_moves(16);
        for(uint8_t i=0; i<16; i++) mat_stab_moves[i].push_back(0);

        for(uint8_t i=1; i<total_move_name; i++) {
            // Remove banned moves if options are checked
            if((noSpore==false || move_effect[i]!=0x20 || move_accuracy[i]<=0xBF) &&
               (noAmnesia==false || move_effect[i]!=0x35) &&
               (noRecover==false || move_effect[i]!=0x38)){
                vec_randomized_moves.push_back(i);
            }

            if(move_effect[i]==0x39) pkm_start_move_3[132] = i;
            if(move_effect[i]==0x35) pkm_start_move_3[150] = i;
        }

        // Lists STAB moves of each type
        if(ui->Randomize_PkmnData_STABmove->isChecked()) {
            for(uint8_t i=1;i<=total_move_name;i++){
                if(move_power[i]>1) {
                    if(mat_stab_moves[move_type[i]][0] == 0) mat_stab_moves[move_type[i]][0] = i;
                    else mat_stab_moves[move_type[i]].push_back(i);
                }
            }
        }

        for(uint8_t i=1;i<=total_pkm_name;i++) {
            // Shuffle moves vector
            std::shuffle(vec_randomized_moves.begin(), vec_randomized_moves.end(), mt_rand);

            // Starting moves
            if(ui->Randomize_PkmnData_STABmove->isChecked()) {
                // Shuffle STAB moves vectors
                std::shuffle(mat_stab_moves[pkm_type_1[i]].begin(), mat_stab_moves[pkm_type_1[i]].end(), mt_rand);
                if(pkm_type_1[i] != pkm_type_2[i]) std::shuffle(mat_stab_moves[pkm_type_2[i]].begin(), mat_stab_moves[pkm_type_2[i]].end(), mt_rand);

                // Pokémon learns a random STAB move if one exists
                if(mat_stab_moves[pkm_type_1[i]][0] != 0) pkm_start_move_1[i] = mat_stab_moves[pkm_type_1[i]][0];
                else if(vec_randomized_moves.size() > 0) pkm_start_move_1[i] = vec_randomized_moves[0];
                else pkm_start_move_1[i] = rand_move(mt_rand);

                // Pokémon can get a second STAB move if it has a secondary Type
                if(pkm_type_1[i] != pkm_type_2[i]) {
                    if(mat_stab_moves[pkm_type_2[i]][0] != 0) pkm_start_move_2[i] = mat_stab_moves[pkm_type_2[i]][0];
                    else if(vec_randomized_moves.size() > 1) pkm_start_move_2[i] = vec_randomized_moves[1];
                    else pkm_start_move_2[i] = rand_move(mt_rand);
                }
                else if(vec_randomized_moves.size() > 1) pkm_start_move_2[i] = vec_randomized_moves[1];
                else pkm_start_move_2[i] = rand_move(mt_rand);
            }
            else {
                if(vec_randomized_moves.size() > 0) pkm_start_move_1[i] = vec_randomized_moves[0];
                else pkm_start_move_1[i] = rand_move(mt_rand);
                if(vec_randomized_moves.size() > 1) pkm_start_move_2[i] = vec_randomized_moves[1];
                else pkm_start_move_2[i] = rand_move(mt_rand);
            }

            if(i != 132 && i != 150){
                if(vec_randomized_moves.size() > 2) pkm_start_move_3[i] = vec_randomized_moves[2];
                else pkm_start_move_3[i] = rand_move(mt_rand);
            }
            else if((pkm_start_move_3[i] == 0) || (pkm_start_move_3[i] > total_move_name)) {
                if(vec_randomized_moves.size() > 2) pkm_start_move_3[i] = vec_randomized_moves[2];
                else pkm_start_move_3[i] = rand_move(mt_rand);
            }
            if(vec_randomized_moves.size() > 3) pkm_start_move_4[i] = vec_randomized_moves[3];
            else pkm_start_move_4[i] = rand_move(mt_rand);


            // Level-up moves
            for(uint8_t j=0; j<10; j++) {
                if(pkm_rb_lvl[i][j]>0) {
                    buf8 = j+4;
                    if(vec_randomized_moves.size() > buf8) pkm_rb_move[i][j] = vec_randomized_moves[buf8];
                    else pkm_rb_move[i][j] = rand_move(mt_rand);
                }
                else if(j==0) { // ensure at least one level-up move
                    buf8 = 4;
                    pkm_rb_lvl[i][0] = 1;
                    if(vec_randomized_moves.size() > (buf8)) pkm_rb_move[i][0] = vec_randomized_moves[buf8];
                    else pkm_rb_move[i][j] = rand_move(mt_rand);
                }
            }
            for(uint8_t j=0; j<10; j++) {
                if(pkm_y_lvl[i][j]>0) {
                    buf8 = j+14;
                    if(vec_randomized_moves.size() > (buf8)) pkm_y_move[i][j] = vec_randomized_moves[buf8];
                    else pkm_y_move[i][j] = rand_move(mt_rand);
                }
                else if(j==0) { // ensure at least one level-up move
                    buf8 = 14;
                    pkm_y_lvl[i][0] = 1;
                    if(vec_randomized_moves.size() > (buf8)) pkm_y_move[i][0] = vec_randomized_moves[buf8];
                    else pkm_y_move[i][j] = rand_move(mt_rand);
                }
            }


            // TM HM flags
            for(uint8_t j=0; j<6; j++) {
                pkm_tmhm_flags[i][j] = mt_rand()%256;
                // Mewtwo learns a little more TMs on average
                if(i==150) pkm_tmhm_flags[i][j] |= 3;
            }
            pkm_tmhm_flags[i][6] = mt_rand()%128;
        }

        // Mew learns every TM and HM
        for(uint8_t j=0; j<6; j++) {
            pkm_tmhm_flags[151][j] = 255;
        }
        pkm_tmhm_flags[151][6] = 127;

        // TM HM moves
        randomize_moves_tmhm(mt_rand);
    }
}

void MainWindow::randomize_pkm_types(std::mt19937 &mt_rand)
{
    // Retrieves number of Types
    buf8 = total_type_name;

    // Ignore unused Bird Type
    if(buf8 == 16 && type_name[6]=="Bird") buf8 = 15;

    // Randomize Types
    if(buf8 > 1) {
        buf8--;
        std::uniform_int_distribution<> rand_type(0,buf8);
        std::uniform_int_distribution<> rand_mono(0,100);

        for(short i=1;i<=total_pkm_name;i++) {
            pkm_type_1[i] = rand_type(mt_rand);

            // About 60% mono-Type, 40% dual-Type
            if(rand_mono(mt_rand) > 42) pkm_type_2[i] = pkm_type_1[i];
            else pkm_type_2[i] = rand_type(mt_rand);

            if(pkm_type_1[i] >=6) pkm_type_1[i]++;
            if(pkm_type_2[i] >=6) pkm_type_2[i]++;
        }
    }
}

void MainWindow::refresh_bs_parameters()
{
    if(not_in_init) {
        if(bsmax_hp < bsmin_hp) {
            bsmax_hp = bsmin_hp;
            not_in_init = false;
            ui->spinBox_BSmax_HP->setValue(bsmax_hp);
            not_in_init = true;
        }
        if(bsmax_atk < bsmin_atk) {
            bsmax_atk = bsmin_atk;
            not_in_init = false;
            ui->spinBox_BSmax_ATK->setValue(bsmax_atk);
            not_in_init = true;
        }
        if(bsmax_def < bsmin_def) {
            bsmax_def = bsmin_def;
            not_in_init = false;
            ui->spinBox_BSmax_DEF->setValue(bsmax_def);
            not_in_init = true;
        }
        if(bsmax_spc < bsmin_spc) {
            bsmax_spc = bsmin_spc;
            not_in_init = false;
            ui->spinBox_BSmax_SPC->setValue(bsmax_spc);
            not_in_init = true;
        }
        if(bsmax_speed < bsmin_speed) {
            bsmax_speed = bsmin_speed;
            not_in_init = false;
            ui->spinBox_BSmax_SPEED->setValue(bsmax_speed);
            not_in_init = true;
        }

        bsmax_total = bsmax_hp + bsmax_atk + bsmax_def + bsmax_spc + bsmax_speed;
        bsmin_total = bsmin_hp + bsmin_atk + bsmin_def + bsmin_spc + bsmin_speed;

        if(bstmax_basic > bsmax_total) {
            bstmax_basic = bsmax_total;
            ui->spinBox_BSTmax_Basic->setValue(bstmax_basic);

            if(bstmin_basic > bstmax_basic) {
                bstmin_basic = bstmax_basic;
                ui->spinBox_BSTmin_Basic->setValue(bstmin_basic);
            }
        }
        if(bstmax_stage1 > bsmax_total) {
            bstmax_stage1 = bsmax_total;
            ui->spinBox_BSTmax_Stage1->setValue(bstmax_stage1);

            if(bstmin_stage1 > bstmax_stage1) {
                bstmin_stage1 = bstmax_stage1;
                ui->spinBox_BSTmin_Stage1->setValue(bstmin_stage1);
            }
        }
        if(bstmax_fullevo > bsmax_total) {
            bstmax_fullevo = bsmax_total;
            ui->spinBox_BSTmax_FullyEvolved->setValue(bstmax_fullevo);

            if(bstmin_fullevo > bstmax_fullevo) {
                bstmin_fullevo = bstmax_fullevo;
                ui->spinBox_BSTmin_FullyEvolved->setValue(bstmin_fullevo);
            }
        }
        if(bstmax_legend > bsmax_total) {
            bstmax_legend = bsmax_total;
            ui->spinBox_BSTmax_Legend->setValue(bstmax_legend);

            if(bstmin_legend > bstmax_legend) {
                bstmin_legend = bstmax_legend;
                ui->spinBox_BSTmin_Legend->setValue(bstmin_legend);
            }
        }


        if(bstmin_basic < bsmin_total) {
            bstmin_basic = bsmin_total;
            ui->spinBox_BSTmin_Basic->setValue(bstmin_basic);

            if(bstmax_basic < bstmin_basic) {
                bstmax_basic = bstmin_basic;
                ui->spinBox_BSTmax_Basic->setValue(bstmax_basic);
            }
        }
        if(bstmin_stage1 < bsmin_total) {
            bstmin_stage1 = bsmin_total;
            ui->spinBox_BSTmin_Stage1->setValue(bstmin_stage1);

            if(bstmax_stage1 < bstmin_stage1) {
                bstmax_stage1 = bstmin_stage1;
                ui->spinBox_BSTmax_Stage1->setValue(bstmax_stage1);
            }
        }
        if(bstmin_fullevo < bsmin_total) {
            bstmin_fullevo = bsmin_total;
            ui->spinBox_BSTmin_FullyEvolved->setValue(bstmin_fullevo);

            if(bstmax_fullevo < bstmin_fullevo) {
                bstmax_fullevo = bstmin_fullevo;
                ui->spinBox_BSTmax_FullyEvolved->setValue(bstmax_fullevo);
            }
        }
        if(bstmin_legend < bsmin_total) {
            bstmin_legend = bsmin_total;
            ui->spinBox_BSTmin_Legend->setValue(bstmin_legend);

            if(bstmax_legend < bstmin_legend) {
                bstmax_legend = bstmin_legend;
                ui->spinBox_BSTmax_Legend->setValue(bstmax_legend);
            }
        }
    }
}
