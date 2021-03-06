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


// Rental Pokémon IDs
void MainWindow::on_comboBox_Rental_Pkmn_1_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_id[buf16] = ui->comboBox_Rental_Pkmn_1->currentIndex();
        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_comboBox_Rental_Pkmn_2_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_id[buf16] = ui->comboBox_Rental_Pkmn_2->currentIndex();
        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_comboBox_Rental_Pkmn_3_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_id[buf16] = ui->comboBox_Rental_Pkmn_3->currentIndex();
        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_comboBox_Rental_Pkmn_4_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_id[buf16] = ui->comboBox_Rental_Pkmn_4->currentIndex();
        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_comboBox_Rental_Pkmn_5_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_id[buf16] = ui->comboBox_Rental_Pkmn_5->currentIndex();
        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_comboBox_Rental_Pkmn_6_currentIndexChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_id[buf16] = ui->comboBox_Rental_Pkmn_6->currentIndex();
        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}


// Nicknames
void MainWindow::on_lineEdit_Rental_Nickname_1_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Rental_Nickname_1->text();
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_nickname[buf16] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                rental_pkm_nickname[buf16] += buf_text.at(k);
            }
            else {
                rental_pkm_nickname[buf16] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Rental_Nickname_1->setText(rental_pkm_nickname[buf16]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Rental_Nickname_2_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Rental_Nickname_2->text();
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_nickname[buf16] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                rental_pkm_nickname[buf16] += buf_text.at(k);
            }
            else {
                rental_pkm_nickname[buf16] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Rental_Nickname_2->setText(rental_pkm_nickname[buf16]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Rental_Nickname_3_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Rental_Nickname_3->text();
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_nickname[buf16] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                rental_pkm_nickname[buf16] += buf_text.at(k);
            }
            else {
                rental_pkm_nickname[buf16] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Rental_Nickname_3->setText(rental_pkm_nickname[buf16]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Rental_Nickname_4_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Rental_Nickname_4->text();
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_nickname[buf16] = "";

        for(short k=0;k<buf_text.length();k++) {
            if(control_char_table(buf_text.at(k)) < 253) {
                rental_pkm_nickname[buf16] += buf_text.at(k);
            }
            else {
                rental_pkm_nickname[buf16] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Rental_Nickname_4->setText(rental_pkm_nickname[buf16]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Rental_Nickname_5_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Rental_Nickname_5->text();
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_nickname[buf16] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                rental_pkm_nickname[buf16] += buf_text.at(k);
            }
            else {
                rental_pkm_nickname[buf16] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Rental_Nickname_5->setText(rental_pkm_nickname[buf16]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Rental_Nickname_6_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Rental_Nickname_6->text();
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_nickname[buf16] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                rental_pkm_nickname[buf16] += buf_text.at(k);
            }
            else {
                rental_pkm_nickname[buf16] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Rental_Nickname_6->setText(rental_pkm_nickname[buf16]);
        not_in_init = true;
    }
}

// Rental EVs
void MainWindow::on_spinBox_Rental_EV_HP_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_hp[buf16] = ui->spinBox_Rental_EV_HP_1->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_HP_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_hp[buf16] = ui->spinBox_Rental_EV_HP_2->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_HP_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_hp[buf16] = ui->spinBox_Rental_EV_HP_3->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_HP_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_hp[buf16] = ui->spinBox_Rental_EV_HP_4->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_HP_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_hp[buf16] = ui->spinBox_Rental_EV_HP_5->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_HP_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_hp[buf16] = ui->spinBox_Rental_EV_HP_6->value();
    }
}

void MainWindow::on_spinBox_Rental_EV_Attack_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_atk[buf16] = ui->spinBox_Rental_EV_Attack_1->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Attack_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_atk[buf16] = ui->spinBox_Rental_EV_Attack_2->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Attack_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_atk[buf16] = ui->spinBox_Rental_EV_Attack_3->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Attack_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_atk[buf16] = ui->spinBox_Rental_EV_Attack_4->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Attack_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_atk[buf16] = ui->spinBox_Rental_EV_Attack_5->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Attack_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_atk[buf16] = ui->spinBox_Rental_EV_Attack_6->value();
    }
}

void MainWindow::on_spinBox_Rental_EV_Defense_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_def[buf16] = ui->spinBox_Rental_EV_Defense_1->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Defense_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_def[buf16] = ui->spinBox_Rental_EV_Defense_2->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Defense_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_def[buf16] = ui->spinBox_Rental_EV_Defense_3->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Defense_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_def[buf16] = ui->spinBox_Rental_EV_Defense_4->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Defense_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_def[buf16] = ui->spinBox_Rental_EV_Defense_5->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Defense_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_def[buf16] = ui->spinBox_Rental_EV_Defense_6->value();
    }
}

void MainWindow::on_spinBox_Rental_EV_Special_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_spc[buf16] = ui->spinBox_Rental_EV_Special_1->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Special_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_spc[buf16] = ui->spinBox_Rental_EV_Special_2->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Special_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_spc[buf16] = ui->spinBox_Rental_EV_Special_3->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Special_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_spc[buf16] = ui->spinBox_Rental_EV_Special_4->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Special_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_spc[buf16] = ui->spinBox_Rental_EV_Special_5->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Special_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_spc[buf16] = ui->spinBox_Rental_EV_Special_6->value();
    }
}

void MainWindow::on_spinBox_Rental_EV_Speed_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_speed[buf16] = ui->spinBox_Rental_EV_Speed_1->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Speed_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_speed[buf16] = ui->spinBox_Rental_EV_Speed_2->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Speed_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_speed[buf16] = ui->spinBox_Rental_EV_Speed_3->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Speed_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_speed[buf16] = ui->spinBox_Rental_EV_Speed_4->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Speed_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_speed[buf16] = ui->spinBox_Rental_EV_Speed_5->value();
    }
}
void MainWindow::on_spinBox_Rental_EV_Speed_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_ev_speed[buf16] = ui->spinBox_Rental_EV_Speed_6->value();
    }
}


// Rental IVs
void MainWindow::on_spinBox_Rental_IV_Attack_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_atk[buf16] = ui->spinBox_Rental_IV_Attack_1->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_1->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Attack_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_atk[buf16] = ui->spinBox_Rental_IV_Attack_2->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_2->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Attack_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_atk[buf16] = ui->spinBox_Rental_IV_Attack_3->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_3->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Attack_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_atk[buf16] = ui->spinBox_Rental_IV_Attack_4->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_4->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Attack_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_atk[buf16] = ui->spinBox_Rental_IV_Attack_5->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_5->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Attack_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_atk[buf16] = ui->spinBox_Rental_IV_Attack_6->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_6->setValue(rental_pkm_iv_hp[buf16]);
    }
}

void MainWindow::on_spinBox_Rental_IV_Defense_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_def[buf16] = ui->spinBox_Rental_IV_Defense_1->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_1->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Defense_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_def[buf16] = ui->spinBox_Rental_IV_Defense_2->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_2->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Defense_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_def[buf16] = ui->spinBox_Rental_IV_Defense_3->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_3->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Defense_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_def[buf16] = ui->spinBox_Rental_IV_Defense_4->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_4->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Defense_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_def[buf16] = ui->spinBox_Rental_IV_Defense_5->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_5->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Defense_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_def[buf16] = ui->spinBox_Rental_IV_Defense_6->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_6->setValue(rental_pkm_iv_hp[buf16]);
    }
}

void MainWindow::on_spinBox_Rental_IV_Special_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_spc[buf16] = ui->spinBox_Rental_IV_Special_1->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_1->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Special_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_spc[buf16] = ui->spinBox_Rental_IV_Special_2->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_2->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Special_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_spc[buf16] = ui->spinBox_Rental_IV_Special_3->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_3->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Special_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_spc[buf16] = ui->spinBox_Rental_IV_Special_4->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_4->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Special_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_spc[buf16] = ui->spinBox_Rental_IV_Special_5->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_5->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Special_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_spc[buf16] = ui->spinBox_Rental_IV_Special_6->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_6->setValue(rental_pkm_iv_hp[buf16]);
    }
}

void MainWindow::on_spinBox_Rental_IV_Speed_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_speed[buf16] = ui->spinBox_Rental_IV_Speed_1->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_1->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Speed_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_speed[buf16] = ui->spinBox_Rental_IV_Speed_2->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_2->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Speed_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_speed[buf16] = ui->spinBox_Rental_IV_Speed_3->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_3->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Speed_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_speed[buf16] = ui->spinBox_Rental_IV_Speed_4->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_4->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Speed_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_speed[buf16] = ui->spinBox_Rental_IV_Speed_5->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_5->setValue(rental_pkm_iv_hp[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_IV_Speed_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_iv_speed[buf16] = ui->spinBox_Rental_IV_Speed_6->value();
        rental_pkm_iv_hp[buf16] = (rental_pkm_iv_atk[buf16] & 1)*8 + (rental_pkm_iv_def[buf16] & 1)*4 + (rental_pkm_iv_speed[buf16] & 1)*2 + (rental_pkm_iv_spc[buf16] & 1);
        ui->spinBox_Rental_IV_HP_6->setValue(rental_pkm_iv_hp[buf16]);
    }
}


// Rental Pokémon Levels
void MainWindow::on_spinBox_Rental_Lv_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_level[buf16] = ui->spinBox_Rental_Lv_1->value();

        if(rental_pkm_level[buf16]>100){
            rental_pkm_level[buf16]=100;
            ui->spinBox_Rental_Lv_1->setValue(100);
        }
        if(rental_pkm_level[buf16]<2){
            rental_pkm_level[buf16]=2;
            ui->spinBox_Rental_Lv_1->setValue(2);
        }
        if(pkm_growth_rate[rental_pkm_id[buf16]]>5) pkm_growth_rate[rental_pkm_id[buf16]]=5;

        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_Lv_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_level[buf16] = ui->spinBox_Rental_Lv_2->value();

        if(rental_pkm_level[buf16]>100){
            rental_pkm_level[buf16]=100;
            ui->spinBox_Rental_Lv_2->setValue(100);
        }
        if(rental_pkm_level[buf16]<2){
            rental_pkm_level[buf16]=2;
            ui->spinBox_Rental_Lv_2->setValue(2);
        }
        if(pkm_growth_rate[rental_pkm_id[buf16]]>5) pkm_growth_rate[rental_pkm_id[buf16]]=5;

        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_Lv_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_level[buf16] = ui->spinBox_Rental_Lv_3->value();

        if(rental_pkm_level[buf16]>100){
            rental_pkm_level[buf16]=100;
            ui->spinBox_Rental_Lv_3->setValue(100);
        }
        if(rental_pkm_level[buf16]<2){
            rental_pkm_level[buf16]=2;
            ui->spinBox_Rental_Lv_3->setValue(2);
        }
        if(pkm_growth_rate[rental_pkm_id[buf16]]>5) pkm_growth_rate[rental_pkm_id[buf16]]=5;

        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_Lv_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_level[buf16] = ui->spinBox_Rental_Lv_4->value();

        if(rental_pkm_level[buf16]>100){
            rental_pkm_level[buf16]=100;
            ui->spinBox_Rental_Lv_4->setValue(100);
        }
        if(rental_pkm_level[buf16]<2){
            rental_pkm_level[buf16]=2;
            ui->spinBox_Rental_Lv_4->setValue(2);
        }
        if(pkm_growth_rate[rental_pkm_id[buf16]]>5) pkm_growth_rate[rental_pkm_id[buf16]]=5;

        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_Lv_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_level[buf16] = ui->spinBox_Rental_Lv_5->value();

        if(rental_pkm_level[buf16]>100){
            rental_pkm_level[buf16]=100;
            ui->spinBox_Rental_Lv_5->setValue(100);
        }
        if(rental_pkm_level[buf16]<2){
            rental_pkm_level[buf16]=2;
            ui->spinBox_Rental_Lv_5->setValue(2);
        }
        if(pkm_growth_rate[rental_pkm_id[buf16]]>5) pkm_growth_rate[rental_pkm_id[buf16]]=5;

        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}
void MainWindow::on_spinBox_Rental_Lv_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_level[buf16] = ui->spinBox_Rental_Lv_6->value();

        if(rental_pkm_level[buf16]>100){
            rental_pkm_level[buf16]=100;
            ui->spinBox_Rental_Lv_6->setValue(100);
        }
        if(rental_pkm_level[buf16]<2){
            rental_pkm_level[buf16]=2;
            ui->spinBox_Rental_Lv_6->setValue(2);
        }
        if(pkm_growth_rate[rental_pkm_id[buf16]]>5) pkm_growth_rate[rental_pkm_id[buf16]]=5;

        rental_pkm_experience[buf16] = calc_experience(pkm_growth_rate[rental_pkm_id[buf16]],rental_pkm_level[buf16]);
    }
}


// Rental PP Ups
void MainWindow::on_spinBox_Rental_PPUp1_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_1[buf16] = 0;

        if(rental_pkm_move_1[buf16]==0) ui->spinBox_Rental_PPUp1_1->setValue(0);
        rental_pkm_ppup_1[buf16] = ui->spinBox_Rental_PPUp1_1->value();

        if(rental_pkm_ppup_1[buf16]>3){
            rental_pkm_ppup_1[buf16]=3;
            ui->spinBox_Rental_PPUp1_1->setValue(3);
        }
        if(rental_pkm_ppup_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp2_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_2[buf16] = 0;

        if(rental_pkm_move_2[buf16]==0) ui->spinBox_Rental_PPUp2_1->setValue(0);
        rental_pkm_ppup_2[buf16] = ui->spinBox_Rental_PPUp2_1->value();

        if(rental_pkm_ppup_2[buf16]>3){
            rental_pkm_ppup_2[buf16]=3;
            ui->spinBox_Rental_PPUp2_1->setValue(3);
        }
        if(rental_pkm_ppup_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp3_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_3[buf16] = 0;

        if(rental_pkm_move_3[buf16]==0) ui->spinBox_Rental_PPUp3_1->setValue(0);
        rental_pkm_ppup_3[buf16] = ui->spinBox_Rental_PPUp3_1->value();

        if(rental_pkm_ppup_3[buf16]>3){
            rental_pkm_ppup_3[buf16]=3;
            ui->spinBox_Rental_PPUp3_1->setValue(3);
        }
        if(rental_pkm_ppup_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp4_1_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_4[buf16] = 0;

        if(rental_pkm_move_4[buf16]==0) ui->spinBox_Rental_PPUp4_1->setValue(0);
        rental_pkm_ppup_4[buf16] = ui->spinBox_Rental_PPUp4_1->value();

        if(rental_pkm_ppup_4[buf16]>3){
            rental_pkm_ppup_4[buf16]=3;
            ui->spinBox_Rental_PPUp4_1->setValue(3);
        }
        if(rental_pkm_ppup_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}

void MainWindow::on_spinBox_Rental_PPUp1_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_1[buf16] = 0;

        if(rental_pkm_move_1[buf16]==0) ui->spinBox_Rental_PPUp1_2->setValue(0);
        rental_pkm_ppup_1[buf16] = ui->spinBox_Rental_PPUp1_2->value();

        if(rental_pkm_ppup_1[buf16]>3){
            rental_pkm_ppup_1[buf16]=3;
            ui->spinBox_Rental_PPUp1_2->setValue(3);
        }
        if(rental_pkm_ppup_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp2_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_2[buf16] = 0;

        if(rental_pkm_move_2[buf16]==0) ui->spinBox_Rental_PPUp2_2->setValue(0);
        rental_pkm_ppup_2[buf16] = ui->spinBox_Rental_PPUp2_2->value();

        if(rental_pkm_ppup_2[buf16]>3){
            rental_pkm_ppup_2[buf16]=3;
            ui->spinBox_Rental_PPUp2_2->setValue(3);
        }
        if(rental_pkm_ppup_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp3_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_3[buf16] = 0;

        if(rental_pkm_move_3[buf16]==0) ui->spinBox_Rental_PPUp3_2->setValue(0);
        rental_pkm_ppup_3[buf16] = ui->spinBox_Rental_PPUp3_2->value();

        if(rental_pkm_ppup_3[buf16]>3){
            rental_pkm_ppup_3[buf16]=3;
            ui->spinBox_Rental_PPUp3_2->setValue(3);
        }
        if(rental_pkm_ppup_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp4_2_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16++;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_4[buf16] = 0;

        if(rental_pkm_move_4[buf16]==0) ui->spinBox_Rental_PPUp4_2->setValue(0);
        rental_pkm_ppup_4[buf16] = ui->spinBox_Rental_PPUp4_2->value();

        if(rental_pkm_ppup_4[buf16]>3){
            rental_pkm_ppup_4[buf16]=3;
            ui->spinBox_Rental_PPUp4_2->setValue(3);
        }
        if(rental_pkm_ppup_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}

void MainWindow::on_spinBox_Rental_PPUp1_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_1[buf16] = 0;

        if(rental_pkm_move_1[buf16]==0) ui->spinBox_Rental_PPUp1_3->setValue(0);
        rental_pkm_ppup_1[buf16] = ui->spinBox_Rental_PPUp1_3->value();

        if(rental_pkm_ppup_1[buf16]>3){
            rental_pkm_ppup_1[buf16]=3;
            ui->spinBox_Rental_PPUp1_3->setValue(3);
        }
        if(rental_pkm_ppup_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp2_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_2[buf16] = 0;

        if(rental_pkm_move_2[buf16]==0) ui->spinBox_Rental_PPUp2_3->setValue(0);
        rental_pkm_ppup_2[buf16] = ui->spinBox_Rental_PPUp2_3->value();

        if(rental_pkm_ppup_2[buf16]>3){
            rental_pkm_ppup_2[buf16]=3;
            ui->spinBox_Rental_PPUp2_3->setValue(3);
        }
        if(rental_pkm_ppup_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp3_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_3[buf16] = 0;

        if(rental_pkm_move_3[buf16]==0) ui->spinBox_Rental_PPUp3_3->setValue(0);
        rental_pkm_ppup_3[buf16] = ui->spinBox_Rental_PPUp3_3->value();

        if(rental_pkm_ppup_3[buf16]>3){
            rental_pkm_ppup_3[buf16]=3;
            ui->spinBox_Rental_PPUp3_3->setValue(3);
        }
        if(rental_pkm_ppup_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp4_3_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 2;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_4[buf16] = 0;

        if(rental_pkm_move_4[buf16]==0) ui->spinBox_Rental_PPUp4_3->setValue(0);
        rental_pkm_ppup_4[buf16] = ui->spinBox_Rental_PPUp4_3->value();

        if(rental_pkm_ppup_4[buf16]>3){
            rental_pkm_ppup_4[buf16]=3;
            ui->spinBox_Rental_PPUp4_3->setValue(3);
        }
        if(rental_pkm_ppup_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}

void MainWindow::on_spinBox_Rental_PPUp1_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_1[buf16] = 0;

        if(rental_pkm_move_1[buf16]==0) ui->spinBox_Rental_PPUp1_4->setValue(0);
        rental_pkm_ppup_1[buf16] = ui->spinBox_Rental_PPUp1_4->value();

        if(rental_pkm_ppup_1[buf16]>3){
            rental_pkm_ppup_1[buf16]=3;
            ui->spinBox_Rental_PPUp1_4->setValue(3);
        }
        if(rental_pkm_ppup_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp2_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_2[buf16] = 0;

        if(rental_pkm_move_2[buf16]==0) ui->spinBox_Rental_PPUp2_4->setValue(0);
        rental_pkm_ppup_2[buf16] = ui->spinBox_Rental_PPUp2_4->value();

        if(rental_pkm_ppup_2[buf16]>3){
            rental_pkm_ppup_2[buf16]=3;
            ui->spinBox_Rental_PPUp2_4->setValue(3);
        }
        if(rental_pkm_ppup_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp3_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_3[buf16] = 0;

        if(rental_pkm_move_3[buf16]==0) ui->spinBox_Rental_PPUp3_4->setValue(0);
        rental_pkm_ppup_3[buf16] = ui->spinBox_Rental_PPUp3_4->value();

        if(rental_pkm_ppup_3[buf16]>3){
            rental_pkm_ppup_3[buf16]=3;
            ui->spinBox_Rental_PPUp3_4->setValue(3);
        }
        if(rental_pkm_ppup_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp4_4_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 3;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_4[buf16] = 0;

        if(rental_pkm_move_4[buf16]==0) ui->spinBox_Rental_PPUp4_4->setValue(0);
        rental_pkm_ppup_4[buf16] = ui->spinBox_Rental_PPUp4_4->value();

        if(rental_pkm_ppup_4[buf16]>3){
            rental_pkm_ppup_4[buf16]=3;
            ui->spinBox_Rental_PPUp4_4->setValue(3);
        }
        if(rental_pkm_ppup_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}

void MainWindow::on_spinBox_Rental_PPUp1_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_1[buf16] = 0;

        if(rental_pkm_move_1[buf16]==0) ui->spinBox_Rental_PPUp1_5->setValue(0);
        rental_pkm_ppup_1[buf16] = ui->spinBox_Rental_PPUp1_5->value();

        if(rental_pkm_ppup_1[buf16]>3){
            rental_pkm_ppup_1[buf16]=3;
            ui->spinBox_Rental_PPUp1_5->setValue(3);
        }
        if(rental_pkm_ppup_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp2_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_2[buf16] = 0;

        if(rental_pkm_move_2[buf16]==0) ui->spinBox_Rental_PPUp2_5->setValue(0);
        rental_pkm_ppup_2[buf16] = ui->spinBox_Rental_PPUp2_5->value();

        if(rental_pkm_ppup_2[buf16]>3){
            rental_pkm_ppup_2[buf16]=3;
            ui->spinBox_Rental_PPUp2_5->setValue(3);
        }
        if(rental_pkm_ppup_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp3_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_3[buf16] = 0;

        if(rental_pkm_move_3[buf16]==0) ui->spinBox_Rental_PPUp3_5->setValue(0);
        rental_pkm_ppup_3[buf16] = ui->spinBox_Rental_PPUp3_5->value();

        if(rental_pkm_ppup_3[buf16]>3){
            rental_pkm_ppup_3[buf16]=3;
            ui->spinBox_Rental_PPUp3_5->setValue(3);
        }
        if(rental_pkm_ppup_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp4_5_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 4;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_4[buf16] = 0;

        if(rental_pkm_move_4[buf16]==0) ui->spinBox_Rental_PPUp4_5->setValue(0);
        rental_pkm_ppup_4[buf16] = ui->spinBox_Rental_PPUp4_5->value();

        if(rental_pkm_ppup_4[buf16]>3){
            rental_pkm_ppup_4[buf16]=3;
            ui->spinBox_Rental_PPUp4_5->setValue(3);
        }
        if(rental_pkm_ppup_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}

void MainWindow::on_spinBox_Rental_PPUp1_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_1[buf16] = 0;

        if(rental_pkm_move_1[buf16]==0) ui->spinBox_Rental_PPUp1_6->setValue(0);
        rental_pkm_ppup_1[buf16] = ui->spinBox_Rental_PPUp1_6->value();

        if(rental_pkm_ppup_1[buf16]>3){
            rental_pkm_ppup_1[buf16]=3;
            ui->spinBox_Rental_PPUp1_6->setValue(3);
        }
        if(rental_pkm_ppup_1[buf16]>0){
            rental_pkm_pp_1[buf16] = move_pp[rental_pkm_move_1[buf16]] / 5;
            rental_pkm_pp_1[buf16] *= rental_pkm_ppup_1[buf16];
            rental_pkm_pp_1[buf16] |= rental_pkm_ppup_1[buf16]<<6;
        }
        rental_pkm_pp_1[buf16] += move_pp[rental_pkm_move_1[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp2_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_2[buf16] = 0;

        if(rental_pkm_move_2[buf16]==0) ui->spinBox_Rental_PPUp2_6->setValue(0);
        rental_pkm_ppup_2[buf16] = ui->spinBox_Rental_PPUp2_6->value();

        if(rental_pkm_ppup_2[buf16]>3){
            rental_pkm_ppup_2[buf16]=3;
            ui->spinBox_Rental_PPUp2_6->setValue(3);
        }
        if(rental_pkm_ppup_2[buf16]>0){
            rental_pkm_pp_2[buf16] = move_pp[rental_pkm_move_2[buf16]] / 5;
            rental_pkm_pp_2[buf16] *= rental_pkm_ppup_2[buf16];
            rental_pkm_pp_2[buf16] |= rental_pkm_ppup_2[buf16]<<6;
        }
        rental_pkm_pp_2[buf16] += move_pp[rental_pkm_move_2[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp3_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_3[buf16] = 0;

        if(rental_pkm_move_3[buf16]==0) ui->spinBox_Rental_PPUp3_6->setValue(0);
        rental_pkm_ppup_3[buf16] = ui->spinBox_Rental_PPUp3_6->value();

        if(rental_pkm_ppup_3[buf16]>3){
            rental_pkm_ppup_3[buf16]=3;
            ui->spinBox_Rental_PPUp3_6->setValue(3);
        }
        if(rental_pkm_ppup_3[buf16]>0){
            rental_pkm_pp_3[buf16] = move_pp[rental_pkm_move_3[buf16]] / 5;
            rental_pkm_pp_3[buf16] *= rental_pkm_ppup_3[buf16];
            rental_pkm_pp_3[buf16] |= rental_pkm_ppup_3[buf16]<<6;
        }
        rental_pkm_pp_3[buf16] += move_pp[rental_pkm_move_3[buf16]];
    }
}
void MainWindow::on_spinBox_Rental_PPUp4_6_valueChanged(int) {
    if(not_in_init){
        buf16 = ui->comboBox_Rental_Page->currentIndex();
        buf16 *= 6;
        buf16 += 5;
        if(buf16>1023) buf16=1023;
        rental_pkm_pp_4[buf16] = 0;

        if(rental_pkm_move_4[buf16]==0) ui->spinBox_Rental_PPUp4_6->setValue(0);
        rental_pkm_ppup_4[buf16] = ui->spinBox_Rental_PPUp4_6->value();

        if(rental_pkm_ppup_4[buf16]>3){
            rental_pkm_ppup_4[buf16]=3;
            ui->spinBox_Rental_PPUp4_6->setValue(3);
        }
        if(rental_pkm_ppup_4[buf16]>0){
            rental_pkm_pp_4[buf16] = move_pp[rental_pkm_move_4[buf16]] / 5;
            rental_pkm_pp_4[buf16] *= rental_pkm_ppup_4[buf16];
            rental_pkm_pp_4[buf16] |= rental_pkm_ppup_4[buf16]<<6;
        }
        rental_pkm_pp_4[buf16] += move_pp[rental_pkm_move_4[buf16]];
    }
}
