#include "mainwindow.h"

void MainWindow::on_comboBox_MovesList_currentIndexChanged(int) {
    buf8 = ui->comboBox_MovesList->currentIndex();
    display_move_data(buf8+1);
}
