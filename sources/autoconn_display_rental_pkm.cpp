#include "mainwindow.h"

void MainWindow::on_comboBox_Rental_Cup_currentIndexChanged(int) {
    //buf8 = ui->comboBox_Rental_Cup->currentIndex();
    //if(ui->comboBox_Rental_Page->currentIndex()<rental_cup_offset[buf8]||ui->comboBox_Rental_Page->currentIndex()>=rental_cup_offset[buf8+1]){
    //    ui->comboBox_Rental_Page->setCurrentIndex(rental_cup_offset[buf8]);
    //}
}

void MainWindow::on_comboBox_Rental_Page_currentIndexChanged(int) {
    buf16 = ui->comboBox_Rental_Page->currentIndex();
    buf16 *= 6;
    display_rental_pkmn(buf16);
    ui->comboBox_Rental_Cup->setCurrentIndex(rental_cup_id[buf16]);
}
