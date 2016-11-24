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
                if(i != 150) bst_temp = rand_bst_legend(mt_rand);
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
