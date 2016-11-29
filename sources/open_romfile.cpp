#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actionOpen_triggered() {
    filename = QFileDialog::getOpenFileName(this, "Open Stadium ROM", QString(), "Pokémon Stadium ROM (*.z64)");

    // ROM opening
    if(!filename.isEmpty()){
        QFile romfile(filename);
        romfile.open(QIODevice::ReadOnly);

        QDataStream read(&romfile);

        ui->progressBar->setVisible(true);
        ui->label_StatusBar->setText("");

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

            // Display CRC and Region Code info
            ui->lineEdit_crc1->setText(QString("%1").arg(header_crc1,8,16,QLatin1Char('0')).toUpper());
            ui->lineEdit_crc2->setText(QString("%1").arg(header_crc2,8,16,QLatin1Char('0')).toUpper());
            ui->lineEdit_RegionCode->setText(QString("%1").arg(header_region_code,2,16,QLatin1Char('0')).toUpper());

            // Checks ROM language and validity
            rom_check();
            romfile.seek(0);

            if(this->romtype != INVALID){
                ui->progressBar->setValue(3);
                // ***** Reads the ROM data *****
                // Initialization
                initialize_char_table();
                initialize_data();
                initialize_evo_stages();
                initialize_iv_statexp_groups();
                initialize_min_levels();
                ui->progressBar->setValue(7);

                // Formulas
                read_ch_formula(romfile);
                ui->progressBar->setValue(8);
                read_damage_variance(romfile);
                ui->progressBar->setValue(9);
                read_highCH_shift(romfile);
                ui->progressBar->setValue(10);
                read_burn_shift(romfile);
                read_odds_paralysis(romfile);
                ui->progressBar->setValue(11);

                // Pokémon names
                read_pkm_names(romfile);
                ui->progressBar->setValue(15);
                initialize_nicknames();
                ui->progressBar->setValue(16);

                // Pokémon data
                read_pkm_data(romfile);
                ui->progressBar->setValue(26);
                read_pokedex_data(romfile);
                ui->progressBar->setValue(35);

                // Moves names and data
                read_move_names(romfile);
                ui->progressBar->setValue(40);
                read_move_data(romfile);
                ui->progressBar->setValue(52);
                read_move_descriptions(romfile);
                ui->progressBar->setValue(57);
                read_tmhm_data(romfile);
                ui->progressBar->setValue(60);

                // Types names
                read_type_names(romfile);
                ui->progressBar->setValue(65);

                // Types chart (Weaknesses and Resistances)
                read_type_chart(romfile);
                ui->progressBar->setValue(70);

                // Experience data
                read_experience_data(romfile);
                ui->progressBar->setValue(72);

                // CPU Trainers / Rentals data
                read_cpu_rentals(romfile);
                ui->progressBar->setValue(94);
                initialize_trainers_names();
                ui->progressBar->setValue(96);
            }
            else {
                ui->label_StatusBar->setText("Invalid ROM header");
                QMessageBox messageBox;
                messageBox.setText("The ROM header appears to be incorrect.\nMake sure this is not a bad dump before reporting! ;-)");
                messageBox.setWindowTitle("Invalid ROM");
                messageBox.exec();
            }
        }
        else {
            this->romtype=INVALID;
            ui->label_rom_debug->setText("Invalid ROM");
            ui->label_StatusBar->setText("Wrong ROM file size");

            QMessageBox messageBox;
            messageBox.setText("This is not a valid Pokémon Stadium ROM.");
            messageBox.setWindowTitle("Invalid ROM");
            messageBox.exec();
        }
        romfile.close();
        initialize_widgets();

        if(this->romtype != INVALID) {
            ui->progressBar->setValue(100);
            ui->label_StatusBar->setText("Pokémon Stadium ROM successfully loaded");
        }
    }
}
