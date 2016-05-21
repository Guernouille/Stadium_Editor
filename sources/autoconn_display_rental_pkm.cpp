#include "mainwindow.h"

void MainWindow::on_comboBox_Rental_Cup_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_Rental_Cup->currentIndex();
        if(ui->comboBox_Rental_Page->currentIndex()<(rental_cup_offset[buf8]/6) || ui->comboBox_Rental_Page->currentIndex()>=(rental_cup_offset[buf8+1]/6)) {
            ui->comboBox_Rental_Page->setCurrentIndex(rental_cup_offset[buf8]/6);
        }
    }
}

void MainWindow::on_comboBox_Rental_Page_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        not_in_init=false;
        ui->comboBox_Rental_Cup->setCurrentIndex(rental_cup_id[buf16+5]);
        not_in_init=true;
        display_rental_pkmn(buf16);
    }
}
