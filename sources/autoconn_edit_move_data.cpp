#include "mainwindow.h"

void MainWindow::on_comboBox_MoveEffect_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_MovesList->currentIndex();
        move_effect[buf8+1] = ui->comboBox_MoveEffect->currentIndex();
    }
}
void MainWindow::on_comboBox_MoveType_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_MovesList->currentIndex();
        move_type[buf8+1] = ui->comboBox_MoveType->currentIndex();
    }
}


void MainWindow::on_comboBox_HighCH_MovesList_1_currentIndexChanged(int) {
    if(not_in_init){
        move_high_ch[0] = ui->comboBox_HighCH_MovesList_1->currentIndex();
    }
}
void MainWindow::on_comboBox_HighCH_MovesList_2_currentIndexChanged(int) {
    if(not_in_init){
        move_high_ch[1] = ui->comboBox_HighCH_MovesList_2->currentIndex();
    }
}
void MainWindow::on_comboBox_HighCH_MovesList_3_currentIndexChanged(int) {
    if(not_in_init){
        move_high_ch[2] = ui->comboBox_HighCH_MovesList_3->currentIndex();
    }
}
void MainWindow::on_comboBox_HighCH_MovesList_4_currentIndexChanged(int) {
    if(not_in_init){
        move_high_ch[3] = ui->comboBox_HighCH_MovesList_4->currentIndex();
    }
}


void MainWindow::on_spinBox_HighCH_shiftvalue_valueChanged(int) {
    if(not_in_init){
        move_high_ch_shiftvalue = ui->spinBox_HighCH_shiftvalue->value();
    }
}

void MainWindow::on_spinBox_MovePower_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_MovesList->currentIndex();
        move_power[buf8+1] = ui->spinBox_MovePower->value();
    }
}
void MainWindow::on_spinBox_MoveAccuracy_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_MovesList->currentIndex();
        move_accuracy[buf8+1] = ui->spinBox_MoveAccuracy->value();
    }
}
void MainWindow::on_spinBox_MovePP_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_MovesList->currentIndex();
        move_pp[buf8+1] = ui->spinBox_MovePP->value();
    }
}
