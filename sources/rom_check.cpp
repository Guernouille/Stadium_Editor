#include "mainwindow.h"
#include "common.cpp"

void MainWindow::rom_check()
{
   if((magic[0]==0x80371240&&
       magic[1]==0x0000000F&&
       magic[2]==0x80100400&&
       magic[3]==0x00001449&&
       magic[4]==0x90F5D9B3&&
       magic[5]==0x9D0EDCF0&&
       magic[6]==0x504F4B45&&
       magic[7]==0x4D4F4E20&&
       magic[8]==0x53544144&&
       magic[9]==0x49554D20&&
       magic[10]==0x20202020&&
       magic[11]==0x4E504F45&&
       magic[12]==0x40806800&&
       magic[13]==0x40804800)) {
       this->romtype=ENGLISH;
       ui->label_rom_debug->setText("English ROM");
   }
   else {
       this->romtype=INVALID;
       ui->label_rom_debug->setText("Invalid ROM");
   }
}
