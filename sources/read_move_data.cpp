#include "mainwindow.h"

void MainWindow::read_move_data(QFile &romfile)
{
    // ***** Retrieve High CH moves *****
    for(short i=0;i<4;i++){
        rom_offset = 0x37570C + i;

        QDataStream read(&romfile);
        romfile.seek(rom_offset);

        read>>move_high_ch[i];
    }

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

        // Useless moves: Bide, Constrict, Mist, Poison Gas, Poison Powder, Psywave, Roar, Splash, Teleport, Whirlwind
        if(i==0x12||i==0x2E||i==0x36||i==0x4D||i==0x64||i==0x75||i==0x84||i==0x8B||i==0x95||i==0x96){
            useless_move[i]=true;
            // Temporary
            weak_move[i]=true;
        }
        // Weak moves
        if(move_effect[i]==0x08 || move_effect[i]==0x13 || move_effect[i]==0x1A || move_effect[i]==0x1C || move_effect[i]==0x2E || move_effect[i]==0x42 || move_effect[i]==0x51 || move_effect[i]==0x52 || move_effect[i]==0x54 || move_effect[i]==0x55 || move_effect[i]==0x56){
            weak_move[i]=true;
        }
        else if(((move_effect[i]==0 || move_effect[i]==0x02 || move_effect[i]==0x10) && move_power[i]<=70) || ((move_effect[i]==3 || move_effect[i]==0x21) && move_power[i]<40) || ((move_effect[i]==4 || move_effect[i]==6 || move_effect[i]==0x1F || move_effect[i]==0x4C) && move_power[i]<=60)){
            weak_move[i]=true;
        }
        else if((move_effect[i]==0 && move_accuracy[i]<=0xD8 && move_power[i]<=80) || (move_effect[i]==0x16 && move_accuracy[i]<=0xD8) || (move_effect[i]==0x31 && move_accuracy[i]<=0xD8)){
            weak_move[i]=true;
        }
        else if((move_effect[i]==0x1D && move_type[i]==0 && move_power[i]<25) || (move_effect[i]==0x27 && move_power[i]<=100) || (move_effect[i]==0x46 && move_power[i]<=60)){
            weak_move[i]=true;
        }
        else if(i==0x31 || i==0x52){
            weak_move[i]=true;
        }
        // Strong moves
        else if((move_accuracy[i]>=0xD8 && move_power[i]>=85 && move_effect[i]!=0x27 && move_effect[i]!=0x30) || (move_effect[i]==0x30 && move_accuracy[i]>=0xE5 && move_power[i]>=90) || (move_effect[i]==0x30 && move_type[i]!=0 && move_power[i]>=70) || (move_accuracy[i]>=0xCC && move_power[i]>=100 && move_effect[i]!=0x27) || (move_accuracy[i]>=0xE5 && move_power[i]>=75 && move_type[i]!=0 && move_effect[i]!=0x27)){
            strong_move[i]=true;
        }
        else if(move_effect[i]==0xF || (move_effect[i]==0x20 && move_accuracy[i]==0xFF) || move_effect[i]==0x26 || move_effect[i]==0x2F || move_effect[i]==0x32 || move_effect[i]==0x34 || move_effect[i]==0x35 || (move_effect[i]==0x38 && i!=0x9D) || move_effect[i]==0x43 || move_effect[i]==0x4F){
            strong_move[i]=true;
        }
        else if((move_effect[i]==0x1D && move_accuracy[i]>=0xE5 && move_power[i]>=25) || (move_effect[i]==0x2C && move_accuracy[i]>=0xE5 && move_power[i]>=40)){
            strong_move[i]=true;
        }
        else if(i==0x44 || i==0x45 || i==0x65 || i==0xA2){
            strong_move[i]=true;
        }
        for(short j=0;j<4;j++){
            if(i==move_high_ch[j]){
                weak_move[i]=false;
                strong_move[i]=true;
            }
        }
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
