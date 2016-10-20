#include "mainwindow.h"
#include "common.cpp"

void MainWindow::rom_check()
{
   if(header_PI_settings   == 0x80371240 &&
       header_clockrate    == 0x0000000F &&
       header_boot_address == 0x80100400 &&
       header_release      == 0x00001449 &&
       header_reserved1    == 0 &&
       header_reserved2    == 0 &&
       header_name1        == 0x504F4B45 &&
       header_name2        == 0x4D4F4E20 &&
       header_name3        == 0x53544144 &&
       header_name4        == 0x49554D20 &&
       header_name5        == 0x20202020 &&
       header_reserved3    == 0 &&
       header_rom_format   == 0x0000004E &&
       header_game_id      == 0x504F)
   {
       if(header_region_code == 0x44){
           this->romtype=GERMAN;
       }
       else if(header_region_code == 0x45){
           this->romtype=US_ENGLISH;

           if(header_rom_version == 0){
               if(header_crc1 == 0x90F5D9B3 && header_crc2 == 0x9D0EDCF0){
                   ui->label_rom_debug->setText("US ROM");
               }
               else{
                   ui->label_rom_debug->setText("Modified US ROM");
               }
           }
           else if(header_rom_version == 1){
               if(header_crc1 == 0x1A122D43 && header_crc2 == 0xC17DAF0F){
                   ui->label_rom_debug->setText("Kiosk US ROM");
               }
               else{
                   ui->label_rom_debug->setText("Modified Kiosk US ROM");
               }
           }
           else{
               widget_text = "US ROM v";
               buf8 = header_rom_version >> 4;
               buf8++;
               widget_text += QLocale(QLocale::English).toString(buf8);
               widget_text += ".";
               buf8 = header_rom_version & 0xF;
               widget_text += QLocale(QLocale::English).toString(buf8);
               ui->label_rom_debug->setText(widget_text);
           }
       }
       else if(header_region_code == 0x46){
           this->romtype=FRENCH;
       }
       else if(header_region_code == 0x4A){
           this->romtype=JAPANESE;
       }
       else if(header_region_code == 0x50){
           this->romtype=EU_ENGLISH;

           if(header_rom_version == 0){
               if(header_crc1 == 0x84077275 && header_crc2 == 0x57315B9C){
                   ui->label_rom_debug->setText("UK ROM v1.0");
               }
               else if(header_crc1 == 0x9DFE20E9 && header_crc2 == 0x18894032){
                   ui->label_rom_debug->setText("Fixed UK ROM v1.0");
               }
               else{
                   ui->label_rom_debug->setText("Modified UK ROM v1.0");
               }
           }
           else if(header_rom_version == 1){
               if(header_crc1 == 0x91C9E05D && header_crc2 == 0xAD3AAFB9){
                   ui->label_rom_debug->setText("UK ROM v1.1");
               }
               else{
                   ui->label_rom_debug->setText("Modified UK ROM v1.1");
               }
           }
       }
       else if(header_region_code == 0x53){
           this->romtype=SPANISH;
       }
       else{
           this->romtype=INVALID;
           ui->label_rom_debug->setText("Invalid ROM");
       }
   }
   else {
       this->romtype=INVALID;
       ui->label_rom_debug->setText("Invalid ROM");
   }
}
