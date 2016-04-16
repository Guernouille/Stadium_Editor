#include "mainwindow.h"

void MainWindow::on_comboBox_CPU_Cup_currentIndexChanged(int) {
    buf8 = ui->comboBox_CPU_Cup->currentIndex();
    if(ui->comboBox_CPU_Trainer->currentIndex()<cpu_cup_offset[buf8]||ui->comboBox_CPU_Trainer->currentIndex()>=cpu_cup_offset[buf8+1]){
        ui->comboBox_CPU_Trainer->setCurrentIndex(cpu_cup_offset[buf8]);
    }
}

void MainWindow::on_comboBox_CPU_Trainer_currentIndexChanged(int) {
    buf8 = ui->comboBox_CPU_Trainer->currentIndex();
    display_cpu_trainer_pkmn(buf8);
    ui->comboBox_CPU_Cup->setCurrentIndex(cpu_cup_id[buf8]);
}
