#include "mainwindow.h"

void MainWindow::on_comboBox_TMsHMsNames_currentIndexChanged(int) {
    buf8 = ui->comboBox_TMsHMsNames->currentIndex();
    ui->textEdit_MoveTMHMText->setText(move_tmhm_text[buf8+1]);
}
