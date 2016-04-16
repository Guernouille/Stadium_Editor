#include "mainwindow.h"

void MainWindow::on_comboBox_PokemonSpecies_currentIndexChanged(int) {
    buf8 = ui->comboBox_PokemonSpecies->currentIndex();
    display_pkm_data(buf8+1);
}
