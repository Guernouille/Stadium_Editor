#include "mainwindow.h"


void MainWindow::on_comboBox_CH_formula_shift_1_currentIndexChanged(int) {
    if(not_in_init){
        ch_formula_shift[0] = ui->comboBox_CH_formula_shift_1->currentIndex();
    }
}
void MainWindow::on_comboBox_CH_formula_shift_2_currentIndexChanged(int) {
    if(not_in_init){
        ch_formula_shift[1] = ui->comboBox_CH_formula_shift_2->currentIndex();
    }
}
void MainWindow::on_comboBox_CH_formula_shift_3_currentIndexChanged(int) {
    if(not_in_init){
        ch_formula_shift[2] = ui->comboBox_CH_formula_shift_3->currentIndex();
    }
}
void MainWindow::on_comboBox_FE_CH_formula_shift_2_currentIndexChanged(int) {
    if(not_in_init){
        ch_fe_formula_shift = ui->comboBox_FE_CH_formula_shift_2->currentIndex();
    }
}


void MainWindow::on_spinBox_CH_formula_add_valueChanged(int) {
    if(not_in_init){
        ch_formula_add = ui->spinBox_CH_formula_add->value();
    }
}
void MainWindow::on_spinBox_FE_CH_formula_add_2_valueChanged(int) {
    if(not_in_init){
        ch_fe_formula_add = ui->spinBox_FE_CH_formula_add_2->value();
    }
}

void MainWindow::on_spinBox_CH_formula_shiftvalue_1_valueChanged(int) {
    if(not_in_init){
        ch_formula_shiftvalue[0] = ui->spinBox_CH_formula_shiftvalue_1->value();
    }
}
void MainWindow::on_spinBox_CH_formula_shiftvalue_2_valueChanged(int) {
    if(not_in_init){
        ch_formula_shiftvalue[1] = ui->spinBox_CH_formula_shiftvalue_2->value();
    }
}
void MainWindow::on_spinBox_CH_formula_shiftvalue_3_valueChanged(int) {
    if(not_in_init){
        ch_formula_shiftvalue[2] = ui->spinBox_CH_formula_shiftvalue_3->value();
    }
}
