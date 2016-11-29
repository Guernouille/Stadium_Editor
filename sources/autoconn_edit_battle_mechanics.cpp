#include "mainwindow.h"

void MainWindow::on_comboBox_HighCH_shift_currentIndexChanged(int) {
    if(not_in_init){
        move_high_ch_shift = ui->comboBox_HighCH_shift->currentIndex();
    }
}

void MainWindow::on_comboBox_Status_Burn_shift_currentIndexChanged(int) {
    if(not_in_init){
        burn_shift = ui->comboBox_Status_Burn_shift->currentIndex();
    }
}


void MainWindow::on_spinBox_DamageVariance_1_valueChanged(int) {
    if(not_in_init){
        damage_variance_min = ui->spinBox_DamageVariance_1->value();
    }
}

void MainWindow::on_spinBox_HighCH_shiftvalue_valueChanged(int) {
    if(not_in_init){
        move_high_ch_shiftvalue = ui->spinBox_HighCH_shiftvalue->value();
    }
}

void MainWindow::on_spinBox_Status_Burn_shiftvalue_valueChanged(int) {
    if(not_in_init){
        burn_shiftvalue = ui->spinBox_Status_Burn_shiftvalue->value();
    }
}

void MainWindow::on_spinBox_Status_Paralysis_probability_valueChanged(int) {
    if(not_in_init){
        odds_paralysis = ui->spinBox_Status_Paralysis_probability->value();
    }
}
