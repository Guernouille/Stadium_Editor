#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actionOpen_triggered() {
    filename = QFileDialog::getOpenFileName(this, "Open Stadium ROM", QString(), "Pokémon Stadium ROM (*.z64)");

    // ROM opening
    if(!filename.isEmpty()){
        QFile romfile(filename);
        romfile.open(QIODevice::ReadOnly);

        QDataStream read(&romfile);

        // ***** Checks the ROM validity *****
        if(romfile.size() == 0x2000000) {
            romfile.seek(0x00);
            read>>magic[0];
            romfile.seek(0x04);
            read>>magic[1];
            romfile.seek(0x08);
            read>>magic[2];
            romfile.seek(0x0C);
            read>>magic[3];
            romfile.seek(0x10);
            read>>magic[4];
            romfile.seek(0x14);
            read>>magic[5];
            romfile.seek(0x20);
            read>>magic[6];
            romfile.seek(0x24);
            read>>magic[7];
            romfile.seek(0x28);
            read>>magic[8];
            romfile.seek(0x2C);
            read>>magic[9];
            romfile.seek(0x30);
            read>>magic[10];
            romfile.seek(0x3B);
            read>>magic[11];
            romfile.seek(0x40);
            read>>magic[12];
            romfile.seek(0x44);
            read>>magic[13];

            // Checks ROM language and validity
            rom_check();
            romfile.seek(0);

            if(this->romtype != INVALID){
                // ***** Reads the ROM data *****
                // Initialization
                initialize_char_table();
                initialize_data();
                initialize_min_levels();

                // Pokémon names
                read_pkm_names(romfile);
                initialize_nicknames();

                // Pokémon data
                read_pkm_data(romfile);
                read_pokedex_data(romfile);

                // Moves names and data
                read_move_names(romfile);
                read_move_data(romfile);
                read_move_descriptions(romfile);
                read_tmhm_data(romfile);

                // Types names
                read_type_names(romfile);

                // Types data - Weaknesses and Resistances

                // Experience data
                read_experience_data(romfile);

                // CPU Trainers / Rentals data
                read_cpu_rentals(romfile);
            }
        }
        else {
            this->romtype=INVALID;
            ui->label_rom_debug->setText("Invalid ROM");

            QMessageBox messageBox;
            messageBox.setText("This is not a valid Pokémon Stadium ROM.");
            messageBox.setWindowTitle("Invalid ROM");
            messageBox.exec();
        }
        romfile.close();
        initialize_widgets();
    }
}
