#include "mainwindow.h"

// Rental Move IDs
//TO DO: PPs and PP Ups
void MainWindow::on_comboBox_Rental_Move1_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_1[buf16] = ui->comboBox_Rental_Move1_1->currentIndex();

        rental_pkm_pp_1[buf16] = 0;
        if(rental_pkm_ppup_1[buf16]>0 && rental_pkm_move_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp1_1->setValue(0);
            rental_pkm_ppup_1[buf16]=0;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move2_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_1->currentIndex();

        rental_pkm_pp_2[buf16] = 0;
        if(rental_pkm_ppup_2[buf16]>0 && rental_pkm_move_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp2_1->setValue(0);
            rental_pkm_ppup_2[buf16]=0;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move3_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_1->currentIndex();

        rental_pkm_pp_3[buf16] = 0;
        if(rental_pkm_ppup_3[buf16]>0 && rental_pkm_move_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp3_1->setValue(0);
            rental_pkm_ppup_3[buf16]=0;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move4_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_1->currentIndex();

        rental_pkm_pp_4[buf16] = 0;
        if(rental_pkm_ppup_4[buf16]>0 && rental_pkm_move_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp4_1->setValue(0);
            rental_pkm_ppup_4[buf16]=0;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}


void MainWindow::on_comboBox_Rental_Move1_2_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_1[buf16] = ui->comboBox_Rental_Move1_2->currentIndex();

        rental_pkm_pp_1[buf16] = 0;
        if(rental_pkm_ppup_1[buf16]>0 && rental_pkm_move_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp1_2->setValue(0);
            rental_pkm_ppup_1[buf16]=0;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move2_2_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_2->currentIndex();

        rental_pkm_pp_2[buf16] = 0;
        if(rental_pkm_ppup_2[buf16]>0 && rental_pkm_move_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp2_2->setValue(0);
            rental_pkm_ppup_2[buf16]=0;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move3_2_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_2->currentIndex();

        rental_pkm_pp_3[buf16] = 0;
        if(rental_pkm_ppup_3[buf16]>0 && rental_pkm_move_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp3_2->setValue(0);
            rental_pkm_ppup_3[buf16]=0;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move4_2_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_2->currentIndex();

        rental_pkm_pp_4[buf16] = 0;
        if(rental_pkm_ppup_4[buf16]>0 && rental_pkm_move_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp4_2->setValue(0);
            rental_pkm_ppup_4[buf16]=0;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}


void MainWindow::on_comboBox_Rental_Move1_3_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_1[buf16] = ui->comboBox_Rental_Move1_3->currentIndex();

        rental_pkm_pp_1[buf16] = 0;
        if(rental_pkm_ppup_1[buf16]>0 && rental_pkm_move_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp1_3->setValue(0);
            rental_pkm_ppup_1[buf16]=0;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move2_3_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_3->currentIndex();

        rental_pkm_pp_2[buf16] = 0;
        if(rental_pkm_ppup_2[buf16]>0 && rental_pkm_move_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp2_3->setValue(0);
            rental_pkm_ppup_2[buf16]=0;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move3_3_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_3->currentIndex();

        rental_pkm_pp_3[buf16] = 0;
        if(rental_pkm_ppup_3[buf16]>0 && rental_pkm_move_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp3_3->setValue(0);
            rental_pkm_ppup_3[buf16]=0;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move4_3_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_3->currentIndex();

        rental_pkm_pp_4[buf16] = 0;
        if(rental_pkm_ppup_4[buf16]>0 && rental_pkm_move_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp4_3->setValue(0);
            rental_pkm_ppup_4[buf16]=0;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}


void MainWindow::on_comboBox_Rental_Move1_4_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_1[buf16] = ui->comboBox_Rental_Move1_4->currentIndex();

        rental_pkm_pp_1[buf16] = 0;
        if(rental_pkm_ppup_1[buf16]>0 && rental_pkm_move_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp1_4->setValue(0);
            rental_pkm_ppup_1[buf16]=0;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move2_4_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_4->currentIndex();

        rental_pkm_pp_2[buf16] = 0;
        if(rental_pkm_ppup_2[buf16]>0 && rental_pkm_move_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp2_4->setValue(0);
            rental_pkm_ppup_2[buf16]=0;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move3_4_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_4->currentIndex();

        rental_pkm_pp_3[buf16] = 0;
        if(rental_pkm_ppup_3[buf16]>0 && rental_pkm_move_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp3_4->setValue(0);
            rental_pkm_ppup_3[buf16]=0;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move4_4_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_4->currentIndex();

        rental_pkm_pp_4[buf16] = 0;
        if(rental_pkm_ppup_4[buf16]>0 && rental_pkm_move_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp4_4->setValue(0);
            rental_pkm_ppup_4[buf16]=0;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}


void MainWindow::on_comboBox_Rental_Move1_5_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_1[buf16] = ui->comboBox_Rental_Move1_5->currentIndex();

        rental_pkm_pp_1[buf16] = 0;
        if(rental_pkm_ppup_1[buf16]>0 && rental_pkm_move_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp1_5->setValue(0);
            rental_pkm_ppup_1[buf16]=0;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move2_5_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_5->currentIndex();

        rental_pkm_pp_2[buf16] = 0;
        if(rental_pkm_ppup_2[buf16]>0 && rental_pkm_move_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp2_5->setValue(0);
            rental_pkm_ppup_2[buf16]=0;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move3_5_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_5->currentIndex();

        rental_pkm_pp_3[buf16] = 0;
        if(rental_pkm_ppup_3[buf16]>0 && rental_pkm_move_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp3_5->setValue(0);
            rental_pkm_ppup_3[buf16]=0;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move4_5_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_5->currentIndex();

        rental_pkm_pp_4[buf16] = 0;
        if(rental_pkm_ppup_4[buf16]>0 && rental_pkm_move_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp4_5->setValue(0);
            rental_pkm_ppup_4[buf16]=0;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}


void MainWindow::on_comboBox_Rental_Move1_6_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_1[buf16] = ui->comboBox_Rental_Move1_6->currentIndex();

        rental_pkm_pp_1[buf16] = 0;
        if(rental_pkm_ppup_1[buf16]>0 && rental_pkm_move_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp1_6->setValue(0);
            rental_pkm_ppup_1[buf16]=0;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move2_6_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_2[buf16] = ui->comboBox_Rental_Move2_6->currentIndex();

        rental_pkm_pp_2[buf16] = 0;
        if(rental_pkm_ppup_2[buf16]>0 && rental_pkm_move_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp2_6->setValue(0);
            rental_pkm_ppup_2[buf16]=0;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move3_6_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_3[buf16] = ui->comboBox_Rental_Move3_6->currentIndex();

        rental_pkm_pp_3[buf16] = 0;
        if(rental_pkm_ppup_3[buf16]>0 && rental_pkm_move_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp3_6->setValue(0);
            rental_pkm_ppup_3[buf16]=0;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_comboBox_Rental_Move4_6_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_move_4[buf16] = ui->comboBox_Rental_Move4_6->currentIndex();

        rental_pkm_pp_4[buf16] = 0;
        if(rental_pkm_ppup_4[buf16]>0 && rental_pkm_move_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        else{
            ui->spinBox_Rental_PPUp4_6->setValue(0);
            rental_pkm_ppup_4[buf16]=0;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}
