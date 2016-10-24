#include "mainwindow.h"

void MainWindow::on_comboBox_PokemonSpecies_currentIndexChanged(int) {
    if(not_in_init){
        not_in_init=false;
        buf8 = ui->comboBox_PokemonSpecies->currentIndex();
        display_pkm_data(buf8+1);
        ui->label_Pokedex_Number_value->setText(QString::number(buf8+1));
        not_in_init=true;
    }
}
