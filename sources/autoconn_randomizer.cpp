#include "mainwindow.h"

// Max PPs (Rental)
void MainWindow::on_checkBox_Randomizer_Rental_MaxPPUps_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_NoPPUps->setChecked(false);
    }
}

// Min PPs (Rental)
void MainWindow::on_checkBox_Randomizer_Rental_NoPPUps_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_MaxPPUps->setChecked(false);
    }
}


// Randomize
void MainWindow::on_pushButton_Randomize_pressed()
{
    std::seed_seq seeds{prng_seed[0], prng_seed[1], prng_seed[2], prng_seed[3], prng_seed[4], prng_seed[5]};
    std::mt19937 mt_rand(seeds);
    mt_rand.discard(700000);

    // CPU Teams
    if(ui->checkBox_CPUTeams->isChecked()){
        if(ui->checkBox_Randomize_CPU_Levels->isChecked()){
            randomize_cpu_level(mt_rand);
        }

        if(ui->checkBox_Randomize_CPU_Pkmn->isChecked()){
            randomize_cpu_init_pkmn();
            randomize_cpu_pkmn(mt_rand);
        }

        if(ui->checkBox_Randomize_CPU_Moves->isChecked()){
            randomize_cpu_moves(mt_rand);
        }

        if(ui->checkBox_Randomizer_CPU_Names->isChecked()){
            randomize_cpu_nicknames(mt_rand);
        }

        // Update display
        if(not_in_init){
            display_cpu_trainer_pkmn(ui->comboBox_CPU_Trainer->currentIndex());
        }
    }


    // Rental
    if(ui->checkBox_RentalPkmn->isChecked()){
        if(ui->checkBox_Randomize_Rental_Levels->isChecked()){
            randomize_rental_level(mt_rand);
        }

        if(ui->checkBox_Randomize_Rental_Pkmn->isChecked()){
            randomize_rental_init_pkmn();
            randomize_rental_pkmn(mt_rand);
        }

        if(ui->checkBox_Randomize_Rental_Moves->isChecked()){
            randomize_rental_moves(mt_rand);
        }

        // Update display
        if(not_in_init){
            display_rental_pkmn(ui->comboBox_Rental_Page->currentIndex());
        }
    }


    // Type chart
    if(ui->checkBox_Randomize_TypeChart->isChecked()){
        randomize_type_chart(mt_rand);
    }
    else{
        if(ui->checkBox_Ghost_vs_Psychic->isChecked()){
            type_chart[75].setType1(0x8);
            type_chart[75].setType2(0x1A);
            type_chart[75].setMultiplier(20);
        }
        else{
            type_chart[75].setType1(0x8);
            type_chart[75].setType2(0x1A);
            type_chart[75].setMultiplier(0);
        }

        if(ui->checkBox_Ice_vs_Fire->isChecked()){
            type_chart[81].setType1(0x19);
            type_chart[81].setType2(0x14);
            type_chart[81].setMultiplier(5);
        }
        else{
            type_chart[81].setType1(0x1A);
            type_chart[81].setType2(0x1A);
            type_chart[81].setMultiplier(20);
        }

        if(ui->checkBox_Bug_vs_Poison->isChecked()){
            type_chart[67].setType1(0x7);
            type_chart[67].setType2(0x3);
            type_chart[67].setMultiplier(5);
        }
        else{
            type_chart[67].setType1(0x7);
            type_chart[67].setType2(0x3);
            type_chart[67].setMultiplier(20);
        }
    }

    // Update display
    if(not_in_init){
        display_type_chart();
    }


    // New seeds
    if(ui->checkBox_FixedSeeds->isChecked()==false){
        prng_seed[0] = mt_rand();
        prng_seed[1] = mt_rand();
        prng_seed[2] = mt_rand();
        prng_seed[3] = mt_rand();
        prng_seed[4] = mt_rand();
        prng_seed[5] = mt_rand();
    }


}
void MainWindow::on_checkBox_CPUTeams_stateChanged(int state)
{
    // TO DO: debug this
    if(state == Qt::Checked){
        ui->groupBox_Randomizer_CPU->setEnabled(true);
    }
    else{
        ui->groupBox_Randomizer_CPU->setEnabled(false);
    }
    ui->checkBox_CPUTeams->setEnabled(true);
}
void MainWindow::on_checkBox_RentalPkmn_stateChanged(int state)
{
    // TO DO: debug this
    if(state == Qt::Checked){
        ui->groupBox_Randomizer_Rental->setEnabled(true);
    }
    else{
        ui->groupBox_Randomizer_Rental->setEnabled(false);
    }
    ui->checkBox_RentalPkmn->setEnabled(true);
}

// Full Metronome (CPU)
void MainWindow::on_pushButton_CPU_Metronome_pressed()
{
    for(short i=0;i<256;i++){
        for(short j=0;j<6;j++){
            cpu_pkm_move_1[i][j] = 0x76;
            cpu_pkm_move_2[i][j] = 0x76;
            cpu_pkm_move_3[i][j] = 0x76;
            cpu_pkm_move_4[i][j] = 0x76;
        }
    }
    ui->comboBox_Move1_1->setCurrentIndex(0x76);
    ui->comboBox_Move2_1->setCurrentIndex(0x76);
    ui->comboBox_Move3_1->setCurrentIndex(0x76);
    ui->comboBox_Move4_1->setCurrentIndex(0x76);
    ui->comboBox_Move1_2->setCurrentIndex(0x76);
    ui->comboBox_Move2_2->setCurrentIndex(0x76);
    ui->comboBox_Move3_2->setCurrentIndex(0x76);
    ui->comboBox_Move4_2->setCurrentIndex(0x76);
    ui->comboBox_Move1_3->setCurrentIndex(0x76);
    ui->comboBox_Move2_3->setCurrentIndex(0x76);
    ui->comboBox_Move3_3->setCurrentIndex(0x76);
    ui->comboBox_Move4_3->setCurrentIndex(0x76);
    ui->comboBox_Move1_4->setCurrentIndex(0x76);
    ui->comboBox_Move2_4->setCurrentIndex(0x76);
    ui->comboBox_Move3_4->setCurrentIndex(0x76);
    ui->comboBox_Move4_4->setCurrentIndex(0x76);
    ui->comboBox_Move1_5->setCurrentIndex(0x76);
    ui->comboBox_Move2_5->setCurrentIndex(0x76);
    ui->comboBox_Move3_5->setCurrentIndex(0x76);
    ui->comboBox_Move4_5->setCurrentIndex(0x76);
    ui->comboBox_Move1_6->setCurrentIndex(0x76);
    ui->comboBox_Move2_6->setCurrentIndex(0x76);
    ui->comboBox_Move3_6->setCurrentIndex(0x76);
    ui->comboBox_Move4_6->setCurrentIndex(0x76);
}


// Full Metronome (Rentals)
void MainWindow::on_pushButton_Rental_Metronome_pressed()
{
    for(short i=0;i<1024;i++){
        rental_pkm_move_1[i] = 0x76;
        rental_pkm_move_2[i] = 0x76;
        rental_pkm_move_3[i] = 0x76;
        rental_pkm_move_4[i] = 0x76;
    }

    ui->comboBox_Rental_Move1_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_6->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_6->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_6->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_6->setCurrentIndex(0x76);
}


// Max EVs IVs (CPU)
void MainWindow::on_pushButton_Maximize_CPU_EVsIVs_pressed()
{
    for(short i=0;i<256;i++){
        for(short j=0;j<6;j++){
            cpu_pkm_ev_hp[i][j] = 0xFFFF;
            cpu_pkm_ev_atk[i][j] = 0xFFFF;
            cpu_pkm_ev_def[i][j] = 0xFFFF;
            cpu_pkm_ev_spc[i][j] = 0xFFFF;
            cpu_pkm_ev_speed[i][j] = 0xFFFF;
            cpu_pkm_ivs[i][j] = 0xFFFF;
            cpu_pkm_iv_hp[i][j] = 0xF;
            cpu_pkm_iv_atk[i][j] = 0xF;
            cpu_pkm_iv_def[i][j] = 0xF;
            cpu_pkm_iv_spc[i][j] = 0xF;
            cpu_pkm_iv_speed[i][j] = 0xF;
        }
    }

    ui->spinBox_EV_HP_1->setValue(0xFFFF);
    ui->spinBox_EV_HP_2->setValue(0xFFFF);
    ui->spinBox_EV_HP_3->setValue(0xFFFF);
    ui->spinBox_EV_HP_4->setValue(0xFFFF);
    ui->spinBox_EV_HP_5->setValue(0xFFFF);
    ui->spinBox_EV_HP_6->setValue(0xFFFF);
    ui->spinBox_EV_Attack_1->setValue(0xFFFF);
    ui->spinBox_EV_Attack_2->setValue(0xFFFF);
    ui->spinBox_EV_Attack_3->setValue(0xFFFF);
    ui->spinBox_EV_Attack_4->setValue(0xFFFF);
    ui->spinBox_EV_Attack_5->setValue(0xFFFF);
    ui->spinBox_EV_Attack_6->setValue(0xFFFF);
    ui->spinBox_EV_Defense_1->setValue(0xFFFF);
    ui->spinBox_EV_Defense_2->setValue(0xFFFF);
    ui->spinBox_EV_Defense_3->setValue(0xFFFF);
    ui->spinBox_EV_Defense_4->setValue(0xFFFF);
    ui->spinBox_EV_Defense_5->setValue(0xFFFF);
    ui->spinBox_EV_Defense_6->setValue(0xFFFF);
    ui->spinBox_EV_Special_1->setValue(0xFFFF);
    ui->spinBox_EV_Special_2->setValue(0xFFFF);
    ui->spinBox_EV_Special_3->setValue(0xFFFF);
    ui->spinBox_EV_Special_4->setValue(0xFFFF);
    ui->spinBox_EV_Special_5->setValue(0xFFFF);
    ui->spinBox_EV_Special_6->setValue(0xFFFF);
    ui->spinBox_EV_Speed_1->setValue(0xFFFF);
    ui->spinBox_EV_Speed_2->setValue(0xFFFF);
    ui->spinBox_EV_Speed_3->setValue(0xFFFF);
    ui->spinBox_EV_Speed_4->setValue(0xFFFF);
    ui->spinBox_EV_Speed_5->setValue(0xFFFF);
    ui->spinBox_EV_Speed_6->setValue(0xFFFF);
    ui->spinBox_IV_HP_1->setValue(0xF);
    ui->spinBox_IV_HP_2->setValue(0xF);
    ui->spinBox_IV_HP_3->setValue(0xF);
    ui->spinBox_IV_HP_4->setValue(0xF);
    ui->spinBox_IV_HP_5->setValue(0xF);
    ui->spinBox_IV_HP_6->setValue(0xF);
    ui->spinBox_IV_Attack_1->setValue(0xF);
    ui->spinBox_IV_Attack_2->setValue(0xF);
    ui->spinBox_IV_Attack_3->setValue(0xF);
    ui->spinBox_IV_Attack_4->setValue(0xF);
    ui->spinBox_IV_Attack_5->setValue(0xF);
    ui->spinBox_IV_Attack_6->setValue(0xF);
    ui->spinBox_IV_Defense_1->setValue(0xF);
    ui->spinBox_IV_Defense_2->setValue(0xF);
    ui->spinBox_IV_Defense_3->setValue(0xF);
    ui->spinBox_IV_Defense_4->setValue(0xF);
    ui->spinBox_IV_Defense_5->setValue(0xF);
    ui->spinBox_IV_Defense_6->setValue(0xF);
    ui->spinBox_IV_Special_1->setValue(0xF);
    ui->spinBox_IV_Special_2->setValue(0xF);
    ui->spinBox_IV_Special_3->setValue(0xF);
    ui->spinBox_IV_Special_4->setValue(0xF);
    ui->spinBox_IV_Special_5->setValue(0xF);
    ui->spinBox_IV_Special_6->setValue(0xF);
    ui->spinBox_IV_Speed_1->setValue(0xF);
    ui->spinBox_IV_Speed_2->setValue(0xF);
    ui->spinBox_IV_Speed_3->setValue(0xF);
    ui->spinBox_IV_Speed_4->setValue(0xF);
    ui->spinBox_IV_Speed_5->setValue(0xF);
    ui->spinBox_IV_Speed_6->setValue(0xF);
}


// Max EVs IVs (Rentals)
void MainWindow::on_pushButton_Maximize_Rental_EVsIVs_pressed()
{
    for(short i=0;i<1024;i++){
        rental_pkm_ev_hp[i] = 0xFFFF;
        rental_pkm_ev_atk[i] = 0xFFFF;
        rental_pkm_ev_def[i] = 0xFFFF;
        rental_pkm_ev_spc[i] = 0xFFFF;
        rental_pkm_ev_speed[i] = 0xFFFF;
        rental_pkm_ivs[i] = 0xFFFF;
        rental_pkm_iv_hp[i] = 0xF;
        rental_pkm_iv_atk[i] = 0xF;
        rental_pkm_iv_def[i] = 0xF;
        rental_pkm_iv_spc[i] = 0xF;
        rental_pkm_iv_speed[i] = 0xF;
    }

    ui->spinBox_Rental_EV_HP_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_6->setValue(0xFFFF);
    ui->spinBox_Rental_IV_HP_1->setValue(0xF);
    ui->spinBox_Rental_IV_HP_2->setValue(0xF);
    ui->spinBox_Rental_IV_HP_3->setValue(0xF);
    ui->spinBox_Rental_IV_HP_4->setValue(0xF);
    ui->spinBox_Rental_IV_HP_5->setValue(0xF);
    ui->spinBox_Rental_IV_HP_6->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_1->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_2->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_3->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_4->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_5->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_6->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_1->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_2->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_3->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_4->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_5->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_6->setValue(0xF);
    ui->spinBox_Rental_IV_Special_1->setValue(0xF);
    ui->spinBox_Rental_IV_Special_2->setValue(0xF);
    ui->spinBox_Rental_IV_Special_3->setValue(0xF);
    ui->spinBox_Rental_IV_Special_4->setValue(0xF);
    ui->spinBox_Rental_IV_Special_5->setValue(0xF);
    ui->spinBox_Rental_IV_Special_6->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_1->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_2->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_3->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_4->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_5->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_6->setValue(0xF);
}


// Gym Leader Castle
void MainWindow::on_checkBox_Randomizer_CPU_GLPkmn_stateChanged(int state)
{
    if(not_in_init){
        not_in_init = false;
        if(state == Qt::Checked){
            if(glc_level_min < 10){
                glc_level_min = 10;
                ui->spinBox_Randomizer_GLCLevelRange_1->setValue(glc_level_min);
                if(glc_level_max < glc_level_min){
                    glc_level_max = glc_level_min;
                    ui->spinBox_Randomizer_GLCLevelRange_2->setValue(glc_level_max);
                }
            }
            if(glc_level_max > 78){
                glc_level_max = 78;
                ui->spinBox_Randomizer_GLCLevelRange_2->setValue(glc_level_max);
                if(glc_level_min > glc_level_max){
                    glc_level_min = glc_level_max;
                    ui->spinBox_Randomizer_GLCLevelRange_1->setValue(glc_level_min);
                }
            }
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_Randomizer_GLCLevelRange_1_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        glc_level_min = ui->spinBox_Randomizer_GLCLevelRange_1->value();
        if(glc_level_min > glc_level_max){
            glc_level_max = glc_level_min;
            ui->spinBox_Randomizer_GLCLevelRange_2->setValue(glc_level_max);
        }
        if(glc_level_max > 78){
            ui->checkBox_Randomizer_CPU_GLPkmn->setChecked(false);
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_Randomizer_GLCLevelRange_2_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        glc_level_max = ui->spinBox_Randomizer_GLCLevelRange_2->value();
        if(glc_level_max < glc_level_min){
            glc_level_min = glc_level_max;
            ui->spinBox_Randomizer_GLCLevelRange_1->setValue(glc_level_min);
        }
        if(glc_level_max > 78){
            ui->checkBox_Randomizer_CPU_GLPkmn->setChecked(false);
        }
        not_in_init = true;
    }
}


// Type chart
void MainWindow::on_checkBox_Ghost_vs_Psychic_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_TypeChart->setChecked(false);
    }
}
void MainWindow::on_checkBox_Ice_vs_Fire_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_TypeChart->setChecked(false);
    }
}
void MainWindow::on_checkBox_Bug_vs_Poison_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_TypeChart->setChecked(false);
    }
}
void MainWindow::on_checkBox_Randomize_TypeChart_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Ghost_vs_Psychic->setChecked(false);
        ui->checkBox_Ice_vs_Fire->setChecked(false);
        ui->checkBox_Bug_vs_Poison->setChecked(false);
    }
}

