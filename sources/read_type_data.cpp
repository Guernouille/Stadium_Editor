#include "mainwindow.h"

void MainWindow::read_type_names(QFile &romfile)
{
    // ***** Initialize type names *****
    for (short i=0;i<256;i++){
        type_name[i] = "";
    }

    // ***** Retrieve number of type names *****
    QDataStream read(&romfile);
    romfile.seek(0x7960B3);
    read>>total_type_name;

    ui->label_debug_type_names_val->setText(QString::number(total_type_name));

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
