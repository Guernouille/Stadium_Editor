#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_moves_accuracy(std::mt19937 &mt_rand)
{
    std::uniform_int_distribution<> rand_accuracy_1(243,255);
    std::uniform_int_distribution<> rand_accuracy_2(226,255);
    std::uniform_int_distribution<> rand_accuracy_3(216,242);
    std::uniform_int_distribution<> rand_accuracy_4(200,232);
    std::uniform_int_distribution<> rand_accuracy_5(179,218);
    std::uniform_int_distribution<> rand_accuracy_6(110,150);
    std::uniform_int_distribution<> rand_accuracy_default(185,255);
    std::uniform_int_distribution<> rand_accuracy_sleep(150,200);
    std::uniform_int_distribution<> rand_accuracy_wrap(183,222);

    bool more_power_less_accuracy = ui->checkBox_Randomizer_MoveData_PowerAccuracy->isChecked();

    for(uint8_t i=1; i<total_move_name; i++) {
        // OHKO
        if(move_effect[i] == 0x26) move_accuracy[i] = 76;

        // Super Fang
        if(move_effect[i] == 0x28) move_accuracy[i] = 229;

        // 100% Accuracy (mostly status, Explosion and Fixed damage moves)
        else if((move_effect[i] >= 0x07 && move_effect[i] <= 0x0F) || move_effect[i] == 0x11 || (move_effect[i] >= 0x12 && move_effect[i] <= 0x14) ||
                (move_effect[i] >= 0x16 && move_effect[i] <= 0x1A) || move_effect[i] == 0x29 || move_effect[i] == 0x2E || move_effect[i] == 0x2F ||
                (move_effect[i] >= 0x32 && move_effect[i] <= 0x36) || move_effect[i] == 0x38 || move_effect[i] == 0x39 || (move_effect[i] >= 0x40 && move_effect[i] <= 0x42) ||
                move_effect[i] == 0x4F || move_effect[i] == 0x51 || move_effect[i] == 0x52 || move_effect[i] == 0x53 || move_effect[i] == 0x55 || i == 0x44)
            move_accuracy[i] = 255;

        // Wrap
        else if(move_effect[i] == 0x2A) move_accuracy[i] = rand_accuracy_wrap(mt_rand);

        // Leech Seed, Stat -2 (except Special)
        else if(move_effect[i] == 0x54 || (move_effect[i] >= 0x3A && move_effect[i] <= 0x3C)) move_accuracy[i] = rand_accuracy_1(mt_rand);

        // Special -1, Confusion, Paralysis, Disable
        else if(move_effect[i] == 0x15 || move_effect[i] == 0x31 || move_effect[i] == 0x43 || move_effect[i] == 0x56) move_accuracy[i] = rand_accuracy_2(mt_rand);

        // Special -2
        else if(move_effect[i] == 0x3D || move_effect[i] == 0x3E) move_accuracy[i] = rand_accuracy_3(mt_rand);

        // Sleep-inducing moves
        else if(move_effect[i] == 0x20) move_accuracy[i] = rand_accuracy_sleep(mt_rand);


        // Accuracy diminishes as Power increases, if option is checked
        else if(more_power_less_accuracy) {
            // No added effect, Fly effect
            if(move_effect[i] == 0 || move_effect[i] == 0x10 || move_effect[i] == 0x2B || move_effect[i] == 0x2D) {
                // Weak moves can't miss
                if(move_power[i] <= 60) {
                    move_accuracy[i] = 255;
                    move_effect[i] = 0x11;
                }
                else if(move_power[i] <= 80) move_accuracy[i] = 255;
                else if(move_power[i] <= 95) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 100) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 110) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 120) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else if(move_power[i] <= 130) move_accuracy[i] = rand_accuracy_5(mt_rand);
                else move_accuracy[i] = rand_accuracy_6(mt_rand);
            }
            // Recoil moves
            else if(move_effect[i] == 0x30) {
                if(move_power[i] <= 95) move_accuracy[i] = 255;
                else if(move_power[i] <= 110) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 120) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 130) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else move_accuracy[i] = rand_accuracy_5(mt_rand);
            }
            // Thrash
            else if(move_effect[i] == 0x1B) {
                if(move_power[i] <= 100) move_accuracy[i] = 255;
                else if(move_power[i] <= 110) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 120) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 130) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else move_accuracy[i] = rand_accuracy_5(mt_rand);
            }
            // Two-turn moves
            else if(move_effect[i] == 0x27) {
                if(move_power[i] <= 135) move_accuracy[i] = 255;
                else if(move_power[i] <= 175) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else move_accuracy[i] = rand_accuracy_2(mt_rand);
            }
            // Recharge moves
            else if(move_effect[i] == 0x50) {
                if(move_power[i] <= 135) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 150) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 170) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else move_accuracy[i] = rand_accuracy_4(mt_rand);
            }
            // Multi-hit moves
            else if(move_effect[i] == 0x1D) {
                if(move_power[i] <= 21) move_accuracy[i] = 255;
                else if(move_power[i] <= 23) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 25) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 30) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 32) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else if(move_power[i] <= 33) move_accuracy[i] = rand_accuracy_5(mt_rand);
                else move_accuracy[i] = rand_accuracy_6(mt_rand);
            }
            // Two-hit moves
            else if(move_effect[i] == 0x2C) {
                if(move_power[i] <= 35) move_accuracy[i] = 255;
                else if(move_power[i] <= 45) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 52) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 55) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 60) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else if(move_power[i] <= 65) move_accuracy[i] = rand_accuracy_5(mt_rand);
                else move_accuracy[i] = rand_accuracy_6(mt_rand);
            }
            // Good added effects
            else if(move_effect[i] == 0x03 || move_effect[i] == 0x25) {
                if(move_power[i] <= 78) move_accuracy[i] = 255;
                else if(move_power[i] <= 91) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 100) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 109) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else if(move_power[i] <= 118) move_accuracy[i] = rand_accuracy_5(mt_rand);
                else move_accuracy[i] = rand_accuracy_6(mt_rand);
            }
            else if(move_effect[i] == 0x22 || move_effect[i] == 0x24 || (move_effect[i] >= 0x44 && move_effect[i] <= 0x48)) {
                if(move_power[i] <= 60) move_accuracy[i] = 255;
                else if(move_power[i] <= 80) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 88) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 96) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 103) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else if(move_power[i] <= 108) move_accuracy[i] = rand_accuracy_5(mt_rand);
                else move_accuracy[i] = rand_accuracy_6(mt_rand);
            }

            // Remaining moves
            else move_accuracy[i] = rand_accuracy_default(mt_rand);
        }
        // Else, same Accuracy range for most remaining moves
        else {
            // Recharge moves
            if(move_effect[i] == 0x50) move_accuracy[i] = rand_accuracy_2(mt_rand);

            // Two-turn moves, Recoil moves, Multi-hit moves and Two-hit moves
            else if(move_effect[i] == 0x27 || move_effect[i] == 0x30 || move_effect[i] == 0x1D || move_effect[i] == 0x2C) move_accuracy[i] = rand_accuracy_1(mt_rand);

            // Remaining moves
            else move_accuracy[i] = rand_accuracy_default(mt_rand);
        }
    }
}

void MainWindow::randomize_moves_power(std::mt19937 &mt_rand)
{
    // Range for most moves
    std::uniform_int_distribution<> rand_power(moverand_min,moverand_max);

    // Range for Recharge moves
    if(moverand_max < 210) {
        buf16 = moverand_max * 6;
        buf16 /= 5;
        buf8 = buf16;
    }
    else buf8 = 253;
    std::uniform_int_distribution<> rand_power_recharge(moverand_max,buf8);

    // Range for Two-turn moves
    if(moverand_max < 218) {
        buf16 = moverand_max * 7;
        buf16 /= 6;
        buf8 = buf16;
    }
    else buf8 = 253;
    std::uniform_int_distribution<> rand_power_twoturn(moverand_max,buf8);

    // Range for Wrap moves
    std::uniform_int_distribution<> rand_power_wrap(15,35);

    // Range for Multi-hit moves
    std::uniform_int_distribution<> rand_power_multihit(15,25);

    // Range for Two-hit moves
    std::uniform_int_distribution<> rand_power_twohit((moverand_min/2),(moverand_max/2));

    // Range for Swift moves
    buf16 = moverand_min + moverand_max;
    buf8 = buf16/2;
    std::uniform_int_distribution<> rand_power_swift(moverand_min,buf8);

    // Range for moves without effect if option is checked
    buf16 = moverand_min + buf8;
    buf8 = buf16/2;
    std::uniform_int_distribution<> rand_power_no_effect(buf8,moverand_max);

    // Range for moves with good added effects
    buf16 = buf8 + moverand_max;
    buf8 = buf16/2;
    std::uniform_int_distribution<> rand_power_good_effect(moverand_min,buf8);

    bool no_explosion_change = ui->checkBox_Randomizer_MoveData_Explosion->isChecked();
    bool no_effect_more_power = ui->checkBox_Randomizer_MoveData_EffectPower->isChecked();

    // Randomize Base Powers
    for(uint8_t i=1; i<total_move_name; i++) {
        // Exclude Explosion and Selfdestruct if the option is checked
        if(move_power[i] > 1 && (no_explosion_change==false || move_effect[i]!=7)) {
            // No added effect
            if(no_effect_more_power && (move_effect[i]==0 || move_effect[i] == 0x10)) move_power[i] = rand_power_no_effect(mt_rand);

            // Recoil moves, Hi Jump Kick, Thrash
            else if(move_effect[i] == 0x1B || move_effect[i] == 0x2D || move_effect[i] == 0x30) move_power[i] = rand_power_no_effect(mt_rand);

            // Recharge moves
            else if(move_effect[i] == 0x50) move_power[i] = rand_power_recharge(mt_rand);

            // Two-turn moves
            else if(move_effect[i] == 0x27) move_power[i] = rand_power_twoturn(mt_rand);

            // Swift
            else if(move_effect[i] == 0x11) move_power[i] = rand_power_swift(mt_rand);

            // Wrap
            else if(move_effect[i] == 0x2A) move_power[i] = rand_power_wrap(mt_rand);

            // Multi-hit moves
            else if(move_effect[i] == 0x1D) move_power[i] = rand_power_multihit(mt_rand);

            // Two-hit moves
            else if(move_effect[i] == 0x2C) move_power[i] = rand_power_twohit(mt_rand);

            // Good added effects
            else if(move_effect[i] == 0x03 || move_effect[i] == 0x22 || move_effect[i] == 0x24 || move_effect[i] == 0x25 || (move_effect[i] >= 0x44 && move_effect[i] <= 0x48))
                move_power[i] = rand_power_good_effect(mt_rand);

            // Other moves
            else move_power[i] = rand_power(mt_rand);
        }
    }
}

void MainWindow::randomize_moves_tmhm(std::mt19937 &mt_rand)
{
    if(total_move_name > 55) {
        // Initialize randomized moves vector
        std::vector<quint8> vec_randomized_tmhms;
        bool noSpore = ui->Randomize_PkmnData_NoSpore->isChecked();
        bool noAmnesia = ui->Randomize_PkmnData_NoAmnesia->isChecked();
        bool noRecover = ui->Randomize_PkmnData_NoRecover->isChecked();

        for(uint8_t i=1; i<total_move_name; i++) {
            // Remove banned moves if options are checked
            if((noSpore==false || move_effect[i]!=0x20 || move_accuracy[i]<=0xBF) &&
               (noAmnesia==false || move_effect[i]!=0x35) &&
               (noRecover==false || move_effect[i]!=0x38)){
                vec_randomized_tmhms.push_back(i);
            }
        }

        if(vec_randomized_tmhms.size()>55){
            // Shuffle moves vector
            std::shuffle(vec_randomized_tmhms.begin(), vec_randomized_tmhms.end(), mt_rand);

            // Randomize TM/HM moves
            for(uint8_t i=1; i<56; i++) {
                move_tmhm[i] = vec_randomized_tmhms[i];
            }
        }
    }
}
