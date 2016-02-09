#include "mainwindow.h"

void MainWindow::read_pkm_data(QFile &romfile)
{
    QDataStream read(&romfile);

    for(short i=1;i<=total_pkm_name;i++){
        rom_offset = 0x71B8A + i*23;
        romfile.seek(rom_offset);
        read>>pkm_base_hp[i];
        read>>pkm_base_atk[i];
        read>>pkm_base_def[i];
        read>>pkm_base_spc[i];
        read>>pkm_base_speed[i];

        read>>pkm_type_1[i];
        read>>pkm_type_2[i];
        read>>pkm_catch_rate[i];
        read>>pkm_base_experience[i];

        read>>pkm_start_move_1[i];
        read>>pkm_start_move_2[i];
        read>>pkm_start_move_3[i];
        read>>pkm_start_move_4[i];

        read>>pkm_growth_rate[i];

        read>>pkm_tmhm_flags[i][0];
        read>>pkm_tmhm_flags[i][1];
        read>>pkm_tmhm_flags[i][2];
        read>>pkm_tmhm_flags[i][3];
        read>>pkm_tmhm_flags[i][4];
        read>>pkm_tmhm_flags[i][5];
        read>>pkm_tmhm_flags[i][6];

        if(pkm_type_1[i]>19) pkm_type_1[i] -= 11;
        if(pkm_type_2[i]>19) pkm_type_2[i] -= 11;
    }

    // RB Level-up moves
    for(short i=1;i<=total_pkm_name;i++){
        rom_offset = 0x77FB00+(i*32);
        romfile.seek(rom_offset);
        for(short j=0;j<10;j++){
            read>>pkm_rb_lvl[i][j];
        }
        for(short j=0;j<10;j++){
            read>>pkm_rb_move[i][j];
        }
    }
    // Y Level-up moves
    for(short i=1;i<=total_pkm_name;i++){
        rom_offset = 0x780DE0+(i*32);
        romfile.seek(rom_offset);
        for(short j=0;j<10;j++){
            read>>pkm_y_lvl[i][j];
        }
        for(short j=0;j<10;j++){
            read>>pkm_y_move[i][j];
        }
    }
}

void MainWindow::read_pkm_names(QFile &romfile)
{
    // ***** Initialize Pokémon names *****
    for (short i=0;i<256;i++){
        pkm_name[i] = "";
        pkm_name_pointer[i] = 0;
    }

    // ***** Retrieve number of Pokémon names *****
    QDataStream read(&romfile);
    romfile.seek(0x7950B3);
    read>>total_pkm_name;

    if(total_pkm_name == 255){
        this->romtype=INVALID;
        ui->label_rom_debug->setText("Corrupted ROM");

        QMessageBox messageBox;
        messageBox.setText("Too many Pokémon names, 254 is the max.");
        messageBox.setWindowTitle("Pokémon names");
        messageBox.exec();
    }
    else{
        // ***** Retrieve Pokémon names *****
        for(short i=1;i<=total_pkm_name;i++){
            // Retrieve string pointer
            rom_offset = 0x7950B2 + i*4;
            romfile.seek(rom_offset);
            read>>buf16;

            if(buf16 > 0x750){
                this->romtype=INVALID;
                ui->label_rom_debug->setText("Corrupted ROM");

                QMessageBox messageBox;
                messageBox.setText("Pokémon names pointers are corrupted.");
                messageBox.setWindowTitle("Pokémon names pointers");
                messageBox.exec();
            }
            else{
                pkm_name_pointer[i] = buf16;
                // Retrieve string
                rom_offset = 0x7950B0 + buf16;
                romfile.seek(rom_offset);
                read>>buf8;

                while(buf8 != 0 && buf8 != 0xFF && pkm_name[i].size()<11){
                    pkm_name[i] += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }
            }
        }
    }
}

void MainWindow::read_pokedex_data(QFile &romfile)
{
    // ***** Initialize Pokédex entries *****
    for (short i=0;i<256;i++){
        pokedex_entry[i] = "";
        pokedex_entry_pointer[i] = 0;
    }

    // ***** Retrieve number of Pokédex entries *****
    QDataStream read(&romfile);
    romfile.seek(0x785843);
    read>>total_pokedex_entry;

    if(total_pokedex_entry == 255){
        this->romtype=INVALID;
        ui->label_rom_debug->setText("Corrupted ROM");

        QMessageBox messageBox;
        messageBox.setText("Too many Pokédex entries, 254 is the max.");
        messageBox.setWindowTitle("Pokédex entries");
        messageBox.exec();
    }
    else{
        // ***** Retrieve Pokédex entries *****
        for(short i=1;i<=total_pokedex_entry;i++){
            // Retrieve Pokédex entry pointer
            rom_offset = 0x785842 + i*4;
            romfile.seek(rom_offset);
            read>>buf16;

            if(buf16 > 0x44D0){
                this->romtype=INVALID;
                ui->label_rom_debug->setText("Corrupted ROM");

                QMessageBox messageBox;
                messageBox.setText("Pokédex entries pointers are corrupted.");
                messageBox.setWindowTitle("Pokédex entries pointers");
                messageBox.exec();
            }
            else{
                pokedex_entry_pointer[i] = buf16;
                // Retrieve string
                rom_offset = 0x785840 + buf16;
                romfile.seek(rom_offset);
                read>>buf8;

                while(buf8 != 0 && buf8 != 0xFF && pokedex_entry[i].size()<192){
                    pokedex_entry[i] += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }
            }
        }
    }
}

