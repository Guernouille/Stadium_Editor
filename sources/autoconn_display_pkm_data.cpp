#include "mainwindow.h"

void MainWindow::on_comboBox_PokemonSpecies_currentIndexChanged(int) {
    buf8 = ui->comboBox_PokemonSpecies->currentIndex();
    display_pkm_data(buf8+1);
    ui->label_Pokedex_Number_value->setText(QString::number(buf8+1));
}
