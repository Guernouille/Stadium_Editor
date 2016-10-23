#include "mainwindow.h"

void MainWindow::on_comboBox_GrowthRate_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_growth_rate[buf8] = ui->comboBox_GrowthRate->currentIndex();
    }
}


void MainWindow::on_comboBox_Pokemon_Type_1_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_type_1[buf8] = ui->comboBox_Pokemon_Type_1->currentIndex();
    }
}
void MainWindow::on_comboBox_Pokemon_Type_2_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_type_2[buf8] = ui->comboBox_Pokemon_Type_2->currentIndex();
    }
}


void MainWindow::on_spinBox_BaseExperience_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_base_experience[buf8] = ui->spinBox_BaseExperience->value();
    }
}
void MainWindow::on_spinBox_CatchRate_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_catch_rate[buf8] = ui->spinBox_CatchRate->value();
    }
}


void MainWindow::on_spinBox_Base_HP_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_base_hp[buf8] = ui->spinBox_Base_HP->value();
    }
}
void MainWindow::on_spinBox_Base_Attack_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_base_atk[buf8] = ui->spinBox_Base_Attack->value();
    }
}
void MainWindow::on_spinBox_Base_Defense_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_base_def[buf8] = ui->spinBox_Base_Defense->value();
    }
}
void MainWindow::on_spinBox_Base_Special_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_base_spc[buf8] = ui->spinBox_Base_Special->value();
    }
}
void MainWindow::on_spinBox_Base_Speed_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        pkm_base_speed[buf8] = ui->spinBox_Base_Speed->value();
    }
}
