#include "mainwindow.h"

void MainWindow::on_spinBox_Status_Paralysis_probability_valueChanged(int) {
    if(not_in_init){
        odds_paralysis = ui->spinBox_Status_Paralysis_probability->value();
    }
}
