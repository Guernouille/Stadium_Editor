#include "mainwindow.h"

// Rental Move IDs
//TO DO: PPs and PP Ups
void MainWindow::on_comboBox_Rental_Move1_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move1_1->currentIndex();
    }
}
void MainWindow::on_comboBox_Rental_Move2_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_1->currentIndex();
    }
}
void MainWindow::on_comboBox_Rental_Move3_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_1->currentIndex();
    }
}
void MainWindow::on_comboBox_Rental_Move4_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_1->currentIndex();
    }
}
