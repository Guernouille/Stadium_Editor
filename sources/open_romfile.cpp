#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actionOpen_triggered() {
    QString filename = QFileDialog::getOpenFileName(this, "Open Stadium ROM", QString(), "Pokémon Stadium ROM (*.n64 *.v64 *.z64)");

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
                // Initialize Character table
                initialize_char_table();

                // ***** Reads the ROM data *****

                // Pokémon names
                read_pkm_names(romfile);

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
            romfile.close();
        }
        else {
            this->romtype=INVALID;
            ui->label_rom_debug->setText("Invalid ROM");

            QMessageBox messageBox;
            messageBox.setText("This is not a valid Pokémon Stadium ROM.");
            messageBox.setWindowTitle("Invalid ROM");
            messageBox.exec();

            ui->label_debug_pkm_names_val->setText(QString::number(0));
            ui->label_debug_move_names_val->setText(QString::number(0));
            ui->label_debug_type_names_val->setText(QString::number(0));
            ui->label_debug_pokedex_entries_val->setText(QString::number(0));
        }
        initialize_widgets();
    }
}
