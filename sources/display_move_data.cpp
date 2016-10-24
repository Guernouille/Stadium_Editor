#include "mainwindow.h"

void MainWindow::display_move_data(quint8 move_id) {
    not_in_init=false;
    ui->lineEdit_Move_Name->setText(move_name[move_id]);
    ui->spinBox_MoveName_Pointer->setValue(move_name_pointer[move_id]);
    ui->spinBox_MoveID->setValue(move_iid[move_id]);
    ui->spinBox_MoveAccuracy->setValue(move_accuracy[move_id]);
    ui->spinBox_MovePower->setValue(move_power[move_id]);
    ui->spinBox_MovePP->setValue(move_pp[move_id]);
    ui->comboBox_MoveType->setCurrentIndex(move_type[move_id]);
    ui->comboBox_MoveEffect->setCurrentIndex(move_effect[move_id]);
    ui->textEdit_MoveDescrText->setText(move_description[move_id]);
    not_in_init=true;
}
