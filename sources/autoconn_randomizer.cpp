#include "mainwindow.h"

void MainWindow::on_checkBox_Randomizer_Rental_MaxPPUps_stateChanged(int state){
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_NoPPUps->setChecked(false);
    }
}
void MainWindow::on_checkBox_Randomizer_Rental_NoPPUps_stateChanged(int state){
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_MaxPPUps->setChecked(false);
    }
}

void MainWindow::on_pushButton_Randomize_CPU_Teams_pressed(){
    if(ui->checkBox_Randomize_CPU_Levels->isChecked()){
        randomize_cpu_level();
    }

    if(ui->checkBox_Randomize_CPU_Pkmn->isChecked()){
        randomize_init_pkmn();
        randomize_cpu_pkmn();
    }

    if(ui->checkBox_Randomize_CPU_Moves->isChecked()){
        randomize_cpu_moves();
    }
}

void MainWindow::on_pushButton_CPU_Metronome_pressed(){
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


void MainWindow::on_pushButton_Rental_Metronome_pressed(){
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


void MainWindow::on_pushButton_Maximize_CPU_EVsIVs_pressed(){
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


void MainWindow::on_pushButton_Maximize_Rental_EVsIVs_pressed(){
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
