#include "mainwindow.h"


void MainWindow::read_move_data(QFile &romfile)
{
    // ***** Retrieve move data *****
    for(short i=1;i<=total_move_name;i++){
        rom_offset = 0x736FA + i*6;

        QDataStream read(&romfile);
        romfile.seek(rom_offset);

        read>>move_iid[i];
        read>>move_effect[i];
        read>>move_power[i];
        read>>move_type[i];
        read>>move_accuracy[i];
        read>>move_pp[i];

        if(move_type[i]>19) move_type[i] -= 11;
    }

    // ***** Retrieve High CH moves *****
    for(short i=0;i<4;i++){
        rom_offset = 0x37570C + i;

        QDataStream read(&romfile);
        romfile.seek(rom_offset);

        read>>move_high_ch[i];
    }
}


void MainWindow::read_move_descriptions(QFile &romfile)
{
    // ***** Retrieve number of move descriptions *****
    QDataStream read(&romfile);
    romfile.seek(0x789D13);
    read>>total_move_description;

    // ***** Retrieve move descriptions *****
    for(short i=1;i<=total_move_description;i++){
        // Retrieve string pointer
        rom_offset = 0x789D12 + i*4;
        romfile.seek(rom_offset);
        read>>buf16;

        if(buf16 > 0x3ADB){
            this->romtype=INVALID;
            ui->label_rom_debug->setText("Corrupted ROM");

            QMessageBox messageBox;
            messageBox.setText("Move descriptions pointers are corrupted.");
            messageBox.setWindowTitle("Move descriptions pointers");
            messageBox.exec();
            QApplication::quit();
        }
        else{
            move_description_pointer[i] = buf16;
            // Retrieve string
            rom_offset = 0x789D10 + buf16;
            romfile.seek(rom_offset);
            read>>buf8;

            while(buf8 != 0 && buf8 != 0xFF && move_description[i].size()<192){
                move_description[i] += char_table[buf8];
                rom_offset++;
                romfile.seek(rom_offset);
                read>>buf8;
            }
        }
    }
}


void MainWindow::read_move_names(QFile &romfile)
{
    // ***** Retrieve number of move names *****
    QDataStream read(&romfile);
    romfile.seek(0x795803);
    read>>total_move_name;

    if(total_move_name == 255){
        this->romtype=INVALID;
        ui->label_rom_debug->setText("Corrupted ROM");

        QMessageBox messageBox;
        messageBox.setText("Too many move names, 254 is the max.");
        messageBox.setWindowTitle("Move names");
        messageBox.exec();
    }
    else{
        // ***** Retrieve move names *****
        for(short i=1;i<=total_move_name;i++){
            // Retrieve string pointer
            rom_offset = 0x795802 + i*4;
            romfile.seek(rom_offset);
            read>>buf16;

            if(buf16 > 0x8B0){
                this->romtype=INVALID;
                ui->label_rom_debug->setText("Corrupted ROM");

                QMessageBox messageBox;
                messageBox.setText("Move names pointers are corrupted.");
                messageBox.setWindowTitle("Move names pointers");
                messageBox.exec();
                QApplication::quit();
            }
            else{
                move_name_pointer[i] = buf16;
                // Retrieve string
                rom_offset = 0x795800 + buf16;
                romfile.seek(rom_offset);
                read>>buf8;

                while(buf8 != 0 && buf8 != 0xFF && move_name[i].size()<13){
                    move_name[i] += char_table[buf8];
                    rom_offset++;
                    romfile.seek(rom_offset);
                    read>>buf8;
                }
            }
        }
    }
}


void MainWindow::read_tmhm_data(QFile &romfile)
{
    // ***** Retrieve TM/HM data *****
    QDataStream read(&romfile);
    for(short i=1;i<56;i++){
        rom_offset = 0x73E2F + i;
        romfile.seek(rom_offset);
        read>>move_tmhm[i];
        rom_offset = 0x375873 + i;
        romfile.seek(rom_offset);
        read>>buf8;
        if(move_tmhm[i]!=buf8){
            this->romtype=INVALID;
        }
    }
    if(this->romtype==INVALID){
        ui->label_rom_debug->setText("Corrupted ROM");
        QMessageBox messageBox;
        messageBox.setText("TM/HM data at 0x73E30 is different from TM/HM data at 0x375874.");
        messageBox.setWindowTitle("TM/HM data");
        messageBox.exec();
        QApplication::quit();
    }


    // ***** Retrieve TMs HMs battle texts *****
    rom_offset = 0x78EBE6;
    for(short i=1;i<=55;i++){
        rom_offset++;
        romfile.seek(rom_offset);
        read>>buf8;

        while(buf8 != 0 && buf8 != 0xFF && move_tmhm_text[i].size()<64){
            move_tmhm_text[i] += char_table[buf8];
            rom_offset++;
            romfile.seek(rom_offset);
            read>>buf8;
        }
    }
}
