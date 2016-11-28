#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_moves_accuracy(std::mt19937 &mt_rand)
{
    std::uniform_int_distribution<> rand_accuracy_1(243,255);
    std::uniform_int_distribution<> rand_accuracy_2(226,255);
    std::uniform_int_distribution<> rand_accuracy_3(216,240);
    std::uniform_int_distribution<> rand_accuracy_4(200,230);
    std::uniform_int_distribution<> rand_accuracy_5(179,216);
    std::uniform_int_distribution<> rand_accuracy_6(110,150);
    std::uniform_int_distribution<> rand_accuracy_default(205,255);
    std::uniform_int_distribution<> rand_accuracy_sleep(150,200);
    std::uniform_int_distribution<> rand_accuracy_wrap(183,222);

    bool more_power_less_accuracy = ui->checkBox_Randomizer_MoveData_PowerAccuracy->isChecked();

    for(uint8_t i=1; i<total_move_name; i++) {
        // OHKO
        if(move_effect[i] == 0x26)
            move_accuracy[i] = 76;

        // Super Fang
        if(move_effect[i] == 0x28)
            move_accuracy[i] = 229;

        // 100% Accuracy (mostly status, Explosion and Fixed damage moves)
        else if((move_effect[i] >= 0x07 && move_effect[i] <= 0x0F) || move_effect[i] == 0x11 || (move_effect[i] >= 0x12 && move_effect[i] <= 0x14) ||
                (move_effect[i] >= 0x16 && move_effect[i] <= 0x1A) || move_effect[i] == 0x29 || move_effect[i] == 0x2E || move_effect[i] == 0x2F ||
                (move_effect[i] >= 0x32 && move_effect[i] <= 0x36) || move_effect[i] == 0x38 || move_effect[i] == 0x39 || (move_effect[i] >= 0x40 && move_effect[i] <= 0x42) ||
                move_effect[i] == 0x4F || move_effect[i] == 0x51 || move_effect[i] == 0x52 || move_effect[i] == 0x53 || move_effect[i] == 0x55 || i == 0x44)
            move_accuracy[i] = 255;

        // Wrap
        else if(move_effect[i] == 0x2A)
            move_accuracy[i] = rand_accuracy_wrap(mt_rand);

        // Leech Seed, Stat -2 (except Special)
        else if(move_effect[i] == 0x54 || (move_effect[i] >= 0x3A && move_effect[i] <= 0x3C))
            move_accuracy[i] = rand_accuracy_1(mt_rand);

        // Special -1, Confusion, Paralysis, Disable
        else if(move_effect[i] == 0x15 || move_effect[i] == 0x31 || move_effect[i] == 0x43 || move_effect[i] == 0x56)
            move_accuracy[i] = rand_accuracy_2(mt_rand);

        // Special -2
        else if(move_effect[i] == 0x3D || move_effect[i] == 0x3E)
            move_accuracy[i] = rand_accuracy_3(mt_rand);

        // Sleep-inducing moves
        else if(move_effect[i] == 0x20)
            move_accuracy[i] = rand_accuracy_sleep(mt_rand);

        // Accuracy diminishes as Power increases, if option is checked
        else if(more_power_less_accuracy) {
            // High CH moves
            if(i == move_high_ch[0] || i == move_high_ch[1] || i == move_high_ch[2] || i == move_high_ch[3]) {
                if(move_power[i] <= 44) {
                    move_accuracy[i] = 255;
                    move_effect[i] = 0x11;
                }
                else if(move_power[i] <= 50) {
                    move_accuracy[i] = 255;
                    move_effect[i] = 0;
                }
                else if(move_power[i] <= 60) {
                    move_accuracy[i] = rand_accuracy_1(mt_rand);
                    move_effect[i] = 0;
                }
                else if(move_power[i] <= 70) {
                    move_accuracy[i] = rand_accuracy_2(mt_rand);
                    move_effect[i] = 0;
                }
                else if(move_power[i] <= 80) {
                    move_accuracy[i] = rand_accuracy_3(mt_rand);
                    move_effect[i] = 0;
                }
                else if(move_power[i] <= 90) {
                    move_accuracy[i] = rand_accuracy_4(mt_rand);
                    move_effect[i] = 0;
                }
                else {
                    move_accuracy[i] = rand_accuracy_6(mt_rand);
                    move_effect[i] = 0;
                }
            }

            // No added effect, Fly effect
            else if(move_effect[i] == 0 || move_effect[i] == 0x10 || move_effect[i] == 0x2B || move_effect[i] == 0x2D) {
                // Weak moves can't miss
                if(move_power[i] <= 60 && move_effect[i] != 0x2B) {
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
            else if(move_effect[i] == 0x2C || move_effect[i] == 0x4D) {
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
            // 10% Burn / Paralysis / Freeze
            else if((move_effect[i] >= 0x04 && move_effect[i] <= 0x06) || move_effect[i] == 0x23) {
                if(move_power[i] <= 75) move_accuracy[i] = 255;
                else if(move_power[i] <= 85) move_accuracy[i] = rand_accuracy_1(mt_rand);
                else if(move_power[i] <= 95) move_accuracy[i] = rand_accuracy_2(mt_rand);
                else if(move_power[i] <= 105) move_accuracy[i] = rand_accuracy_3(mt_rand);
                else if(move_power[i] <= 115) move_accuracy[i] = rand_accuracy_4(mt_rand);
                else if(move_power[i] <= 125) move_accuracy[i] = rand_accuracy_5(mt_rand);
                else move_accuracy[i] = rand_accuracy_6(mt_rand);
            }

            // Remaining moves
            else move_accuracy[i] = rand_accuracy_default(mt_rand);
        }
        // Else, same Accuracy range for most remaining moves
        else {
            // Recharge moves
            if(move_effect[i] == 0x50)
                move_accuracy[i] = rand_accuracy_2(mt_rand);

            // Two-turn moves, Recoil moves, Multi-hit moves and Two-hit moves
            else if(move_effect[i] == 0x27 || move_effect[i] == 0x30 || move_effect[i] == 0x1D || move_effect[i] == 0x2C || move_effect[i] == 0x4D)
                move_accuracy[i] = rand_accuracy_1(mt_rand);

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

    // High CH moves
    buf8 = moverand_max/2;
    std::uniform_int_distribution<> rand_power_high_ch(moverand_min,buf8);

    bool no_explosion_change = ui->checkBox_Randomizer_MoveData_Explosion->isChecked();
    bool no_effect_more_power = ui->checkBox_Randomizer_MoveData_EffectPower->isChecked();

    // Randomize Base Powers
    for(uint8_t i=1; i<total_move_name; i++) {
        // Exclude Explosion and Selfdestruct if the option is checked
        if(move_power[i] > 1 && (no_explosion_change==false || move_effect[i]!=7)) {
            // High CH moves
            if(i == move_high_ch[0] || i == move_high_ch[1] || i == move_high_ch[2] || i == move_high_ch[3])
                move_power[i] = rand_power_high_ch(mt_rand);

            // No added effect
            else if(no_effect_more_power && (move_effect[i]==0 || move_effect[i] == 0x10))
                move_power[i] = rand_power_no_effect(mt_rand);

            // Recoil moves, Hi Jump Kick, Thrash
            else if(move_effect[i] == 0x1B || move_effect[i] == 0x2D || move_effect[i] == 0x30)
                move_power[i] = rand_power_no_effect(mt_rand);

            // Recharge moves
            else if(move_effect[i] == 0x50)
                move_power[i] = rand_power_recharge(mt_rand);

            // Two-turn moves
            else if(move_effect[i] == 0x27)
                move_power[i] = rand_power_twoturn(mt_rand);

            // Swift
            else if(move_effect[i] == 0x11)
                move_power[i] = rand_power_swift(mt_rand);

            // Wrap
            else if(move_effect[i] == 0x2A)
                move_power[i] = rand_power_wrap(mt_rand);

            // Multi-hit moves
            else if(move_effect[i] == 0x1D)
                move_power[i] = rand_power_multihit(mt_rand);

            // Two-hit moves
            else if(move_effect[i] == 0x2C || move_effect[i] == 0x4D)
                move_power[i] = rand_power_twohit(mt_rand);

            // Good added effects
            else if(move_effect[i] == 0x03 || move_effect[i] == 0x22 || move_effect[i] == 0x24 || move_effect[i] == 0x25 ||(move_effect[i] >= 0x44 && move_effect[i] <= 0x48))
                move_power[i] = rand_power_good_effect(mt_rand);

            // Other moves
            else move_power[i] = rand_power(mt_rand);
        }
    }
}

void MainWindow::randomize_moves_pp(std::mt19937 &mt_rand) {
    bool no_explosion_change = ui->checkBox_Randomizer_MoveData_Explosion->isChecked();

    for(uint8_t i=1; i<total_move_name; i++) {
        // Exclude Explosion and Selfdestruct if the option is checked, and Fixed damage moves
        if((no_explosion_change==false || move_effect[i]!=7) && move_effect[i] != 0x29) {
            // Explosion, OHKO, Evasion -2
            if(move_effect[i] == 0x7 || move_effect[i] == 0x26 || move_effect[i] == 0x3F)
                move_pp[i] = 5;

            // Evasion +1, Bide, Super Fang, Special +2, Focus Energy, Confusion, Recover, Transform, ATK -2, DEF -2, SPEED -2, Toxic/Poison, Substitute, Mimic
            else if(move_effect[i] == 0xF || move_effect[i] == 0x1A || move_effect[i] == 0x28 || move_effect[i] == 0x2F || move_effect[i] == 0x31 || move_effect[i] == 0x35 ||
               (move_effect[i] >= 0x38 && move_effect[i] <= 0x3C) || move_effect[i] == 0x42 || move_effect[i] == 0x4F || move_effect[i] == 0x52)
                move_pp[i] = 10;

            // Stat +2 (bar Special), Metronome, Leech Seed, Splash, Disable
            else if((move_effect[i] >= 0x32 && move_effect[i] <= 0x34) || (move_effect[i] >= 0x53 && move_effect[i] <= 0x56)) {
                if(mt_rand()%2 == 0) move_pp[i] = 10;
                else move_pp[i] = 15;
            }

            // Sleep-inducing moves
            else if(move_effect[i] == 0x20) {
                if(move_accuracy[i] >= 220) move_pp[i] = 5;
                else if(move_accuracy[i] >= 185) move_pp[i] = 10;
                else move_pp[i] = 15;
            }

            // Wrap
            else if(move_effect[i] == 0x2A) {
                if(move_power[i] <= 17) {
                    if(mt_rand()%2 == 0) move_pp[i] = 15;
                    else move_pp[i] = 20;
                }
                else if(move_power[i] <= 24) move_pp[i] = 15;
                else move_pp[i] = 10;
            }

            // Speed -1, Special -1, Accuracy -1, Evasion -1, Adaptation, Haze, Mist, Reflect, Light Screen, Thunder Wave
            else if((move_effect[i] >= 0x14 && move_effect[i] <= 0x19) || move_effect[i] == 0x2E || move_effect[i] == 0x40 || move_effect[i] == 0x41 || move_effect[i] == 0x43)
                move_pp[i] = 15;

            // Mirror Move, Stat +1 (bar Evasion)
            else if(move_effect[i] == 0x9 || (move_effect[i] >= 0xA && move_effect[i] <= 0xE))
                move_pp[i] = 20;

            // ATK -1, DEF -1
            else if(move_effect[i] == 0x12 || move_effect[i] == 0x13) {
                if(mt_rand()%2 == 0) move_pp[i] = 20;
                else move_pp[i] = 25;
            }

            // Damaging moves, High CH
            else if(i == move_high_ch[0] || i == move_high_ch[1] || i == move_high_ch[2] || i == move_high_ch[3]) {
                if(move_power[i] <= 44) {
                    move_pp[i] = 20;
                }
                else if(move_power[i] <= 60) {
                    move_pp[i] = 15;
                }
                else if(move_power[i] <= 80) {
                    if(mt_rand()%2 == 0 && move_accuracy[i] > 216) move_pp[i] = 10;
                    else move_pp[i] = 15;
                }
                else if(move_power[i] <= 90) {
                    if(move_accuracy[i] > 216) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else
                    move_pp[i] = 5;
            }

            // Damaging moves, no added effect
            else if(move_effect[i] == 0) {
                if(move_power[i] < 60) {
                    if(mt_rand()%2 == 0) move_pp[i] = 25;
                    else move_pp[i] = 30;
                }
                else if(move_power[i] < 75) {
                    if(mt_rand()%2 == 0) move_pp[i] = 20;
                    else move_pp[i] = 25;
                }
                else if(move_power[i] < 90) {
                    if(mt_rand()%2 == 0) move_pp[i] = 15;
                    else move_pp[i] = 20;
                }
                else if(move_power[i] <= 100) {
                    if(mt_rand()%2 == 0 && move_accuracy[i] > 226) move_pp[i] = 10;
                    else move_pp[i] = 15;
                }
                else if(move_power[i] <= 110) {
                    if(mt_rand()%2 == 0 && move_accuracy[i] > 222) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else if(move_power[i] <= 120) {
                    buf8 = mt_rand()%4;
                    if(buf8 > 0 && move_accuracy[i] > 210) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else move_pp[i] = 5;
            }

            // Damaging moves, Multi-hit
            else if(move_effect[i] == 0x1D) {
                if(move_power[i] < 18) {
                    move_pp[i] = 25;
                }
                else if(move_power[i] < 19) {
                    if(mt_rand()%2 == 0) move_pp[i] = 20;
                    else move_pp[i] = 25;
                }
                else if(move_power[i] < 22) {
                    if(mt_rand()%2 == 0) move_pp[i] = 15;
                    else move_pp[i] = 20;
                }
                else if(move_power[i] < 25) {
                    if(mt_rand()%2 == 0) move_pp[i] = 10;
                    else move_pp[i] = 15;
                }
                else if(move_power[i] < 27)
                    move_pp[i] = 10;
                else if(move_power[i] < 32) {
                    if(mt_rand()%2 == 0) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else move_pp[i] = 5;
            }

            // Damaging moves, Two-hit
            else if(move_effect[i] == 0x2C || move_effect[i] == 0x4D) {
                if(move_power[i] < 25) {
                    move_pp[i] = 25;
                }
                else if(move_power[i] <= 30) {
                    if(mt_rand()%2 == 0) move_pp[i] = 20;
                    else move_pp[i] = 25;
                }
                else if(move_power[i] <= 35) {
                    if(mt_rand()%2 == 0) move_pp[i] = 15;
                    else move_pp[i] = 20;
                }
                else if(move_power[i] <= 45) {
                    if(mt_rand()%2 == 0) move_pp[i] = 10;
                    else move_pp[i] = 15;
                }
                else if(move_power[i] <= 50)
                    move_pp[i] = 10;
                else if(move_power[i] <= 55) {
                    if(mt_rand()%2 == 0) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else move_pp[i] = 5;
            }

            // Damaging moves, added effect
            else if(move_power[i] > 1) {
                if(move_power[i] < 55) {
                    if(mt_rand()%2 == 0) move_pp[i] = 25;
                    else move_pp[i] = 30;
                }
                else if(move_power[i] < 65) {
                    if(mt_rand()%2 == 0) move_pp[i] = 20;
                    else move_pp[i] = 25;
                }
                else if(move_power[i] < 80) {
                    if(mt_rand()%2 == 0 && move_accuracy[i] > 216) move_pp[i] = 15;
                    else move_pp[i] = 20;
                }
                else if(move_power[i] < 95) {
                    if(mt_rand()%2 == 0 && move_accuracy[i] > 216) move_pp[i] = 10;
                    else move_pp[i] = 15;
                }
                else if(move_power[i] < 110) {
                    if(mt_rand()%2 == 0 && move_accuracy[i] > 216) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else if(move_power[i] <= 120) {
                    if(mt_rand()%4 > 0 && move_accuracy[i] > 203) move_pp[i] = 5;
                    else move_pp[i] = 10;
                }
                else move_pp[i] = 5;
            }

            // Other moves
            else {
                buf8 = mt_rand()%4;
                if(buf8 == 0) move_pp[i] = 5;
                else if(buf8 == 1) move_pp[i] = 10;
                else if(buf8 == 2) move_pp[i] = 15;
                else move_pp[i] = 20;
            }
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
