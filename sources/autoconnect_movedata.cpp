#include "mainwindow.h"

void MainWindow::on_spinBox_HighCH_multiplier_valueChanged(int) {
    move_high_ch_multiplier = ui->spinBox_HighCH_multiplier->value();
}
