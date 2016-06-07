#include "mainwindow.h"

void MainWindow::display_type_chart() {
    ui->comboBox_Type1_1->setCurrentIndex(type_chart[0].getType1());
    ui->comboBox_Type2_1->setCurrentIndex(type_chart[0].getType2());
    ui->spinBox_Multiplier_1->setValue(type_chart[0].getMultiplier());
}
