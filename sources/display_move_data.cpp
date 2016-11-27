#include "mainwindow.h"

void MainWindow::display_move_data(quint8 move_id)
{
    ui->lineEdit_Move_Name->setText(move_name[move_id]);
    ui->spinBox_MoveName_Pointer->setValue(move_name_pointer[move_id]);
    ui->spinBox_MoveID->setValue(move_iid[move_id]);
    ui->spinBox_MoveAccuracy->setValue(move_accuracy[move_id]);
    ui->spinBox_MovePower->setValue(move_power[move_id]);
    ui->spinBox_MovePP->setValue(move_pp[move_id]);
    ui->comboBox_MoveType->setCurrentIndex(move_type[move_id]);
    ui->comboBox_MoveEffect->setCurrentIndex(move_effect[move_id]);
    ui->textEdit_MoveDescrText->setText(move_description[move_id]);
}

void MainWindow::display_tmhm_data()
{
    for(short i=1;i<56;i++){
        ui->tableWidget_MoveTM->setItem(i-1,1,new QTableWidgetItem(move_name[move_tmhm[i]]));

        move_tmhm_flag = (i-1)%8;
        move_tmhm_byte = (i-1)/8;

        QCheckBox *move_tmhm_chkbox = qobject_cast<QCheckBox *>(ui->tableWidget_MoveTM->cellWidget(i-1,0));

        if((1<<move_tmhm_flag) & pkm_tmhm_flags[1][move_tmhm_byte]){
            move_tmhm_chkbox->setChecked(true);
        }
        else{
            move_tmhm_chkbox->setChecked(false);
        }
    }
}
