#include "mainwindow.h"

void MainWindow::read_type_chart(QFile &romfile)
{
    QDataStream read(&romfile);
    romfile.seek(0x3755B0);

    for(short i=0;i<82;i++){
        read>>buf8;
        if(buf8 > 0x1A) this->romtype=INVALID;
        type_chart[i].setType1(buf8);
        read>>buf8;
        if(buf8 > 0x1A) this->romtype=INVALID;
        type_chart[i].setType2(buf8);
        read>>buf8;
        if(buf8 == 0xFF) this->romtype=INVALID;
        type_chart[i].setMultiplier(buf8);
    }
    read>>buf8;
    if(buf8 != 0xFF) this->romtype=INVALID;

    if(this->romtype==INVALID){
        ui->label_rom_debug->setText("Corrupted ROM");

        QMessageBox messageBox;
        messageBox.setText("Type chart is corrupted.");
        messageBox.setWindowTitle("Type chart");
        messageBox.exec();
    }
}


void MainWindow::read_type_names(QFile &romfile)
{
    // ***** Retrieve number of type names *****
    QDataStream read(&romfile);
    romfile.seek(0x7960B3);
    read>>total_type_name;

    // ***** Retrieve type names *****
    for(short i=0;i<total_type_name;i++){
        // Retrieve string pointer
        rom_offset = 0x7960B6 + i*4;
        romfile.seek(rom_offset);
        read>>buf16;

        if(buf16 > 0x8B0){
            this->romtype=INVALID;
            ui->label_rom_debug->setText("Corrupted ROM");

            QMessageBox messageBox;
            messageBox.setText("Type names pointers are corrupted.");
            messageBox.setWindowTitle("Type names pointers");
            messageBox.exec();
        }
        else{
            // Retrieve string
            rom_offset = 0x7960B0 + buf16;
            romfile.seek(rom_offset);
            read>>buf8;

            while(buf8 != 0 && buf8 != 0xFF && type_name[i].size()<10){
                type_name[i] += char_table[buf8];
                rom_offset++;
                romfile.seek(rom_offset);
                read>>buf8;
            }

            // To distinguish between real and unused Flying-type
            if(type_name[6]=="Flying"){
                type_name[6]="Bird";
            }
        }
    }
}
