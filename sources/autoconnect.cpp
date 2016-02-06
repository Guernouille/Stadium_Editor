#include "mainwindow.h"

void MainWindow::on_comboBox_PokemonSpecies_currentIndexChanged(int) {
    buf8 = ui->comboBox_PokemonSpecies->currentIndex();
    display_pkm_data(buf8+1);
}

void MainWindow::on_comboBox_MovesList_currentIndexChanged(int) {
    buf8 = ui->comboBox_MovesList->currentIndex();
    display_move_data(buf8+1);
}

void MainWindow::on_spinBox_TrainerSpriteID_valueChanged(int) {
    buf8 = ui->spinBox_TrainerSpriteID->value();
    display_cpu_trainer_sprite(buf8);
}
