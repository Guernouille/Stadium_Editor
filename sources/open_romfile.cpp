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
            read>>header_PI_settings;
            romfile.seek(0x04);
            read>>header_clockrate;
            romfile.seek(0x08);
            read>>header_boot_address;
            romfile.seek(0x0C);
            read>>header_release;
            romfile.seek(0x10);
            read>>header_crc1;
            romfile.seek(0x14);
            read>>header_crc2;
            romfile.seek(0x18);
            read>>header_reserved1;
            romfile.seek(0x1C);
            read>>header_reserved2;
            romfile.seek(0x20);
            read>>header_name1;
            romfile.seek(0x24);
            read>>header_name2;
            romfile.seek(0x28);
            read>>header_name3;
            romfile.seek(0x2C);
            read>>header_name4;
            romfile.seek(0x30);
            read>>header_name5;
            romfile.seek(0x34);
            read>>header_reserved3;
            romfile.seek(0x38);
            read>>header_rom_format;
            romfile.seek(0x3C);
            read>>header_game_id;
            romfile.seek(0x3E);
            read>>header_region_code;
            romfile.seek(0x3F);
            read>>header_rom_version;

            // Checks ROM language and validity
            rom_check();
            romfile.seek(0);

            if(this->romtype != INVALID){
                // ***** Reads the ROM data *****
                // Initialization
                initialize_char_table();
                initialize_data();
                initialize_min_levels();
                initialize_iv_statexp_groups();

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

                // Types chart (Weaknesses and Resistances)
                read_type_chart(romfile);

                // Experience data
                read_experience_data(romfile);

                // CPU Trainers / Rentals data
                read_cpu_rentals(romfile);
                initialize_trainers_names();
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
