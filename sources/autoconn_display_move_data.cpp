#include "mainwindow.h"

void MainWindow::on_comboBox_MovesList_currentIndexChanged(int) {
    if(not_in_init){
        not_in_init=false;
        buf8 = ui->comboBox_MovesList->currentIndex();
        display_move_data(buf8+1);
        not_in_init=true;
    }
}
