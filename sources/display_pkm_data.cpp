#include "mainwindow.h"

void MainWindow::display_experience_max() {
    ui->comboBox_GrowthRate->clear();
    calc_experience_max();

    for (short i=0;i<6;i++){
        widget_text = "0" + QString::number(i) + " - ";
        if(experience_max[i]<10) widget_text += " ";
        if(experience_max[i]<100) widget_text += " ";
        if(experience_max[i]<1000) widget_text += "  ";
        if(experience_max[i]<10000) widget_text += " ";
        if(experience_max[i]<100000) widget_text += " ";
        if(experience_max[i]<1000000) widget_text += "  ";
        widget_text += QLocale(QLocale::English).toString(experience_max[i]);
        widget_text += " Exp";
        ui->comboBox_GrowthRate->addItem(widget_text);
    }
}

void MainWindow::display_pkm_data(quint8 pkm_id) {
    ui->lineEdit_Pokemon_Specie->setText(pkm_name[pkm_id]);
    ui->spinBox_PokemonSpecie_Pointer->setValue(pkm_name_pointer[pkm_id]);

    img_path = ":/pkm_sprites/";
    img_path += QString::number(pkm_id);
    ui->label_Pokemon_Sprite->setPixmap(img_path);

    ui->spinBox_Base_HP->setValue(pkm_base_hp[pkm_id]);
    ui->spinBox_Base_Attack->setValue(pkm_base_atk[pkm_id]);
    ui->spinBox_Base_Defense->setValue(pkm_base_def[pkm_id]);
    ui->spinBox_Base_Special->setValue(pkm_base_spc[pkm_id]);
    ui->spinBox_Base_Speed->setValue(pkm_base_speed[pkm_id]);
    ui->spinBox_BaseExperience->setValue(pkm_base_experience[pkm_id]);
    ui->spinBox_CatchRate->setValue(pkm_catch_rate[pkm_id]);

    ui->comboBox_Pokemon_Type_1->setCurrentIndex(pkm_type_1[pkm_id]);
    ui->comboBox_Pokemon_Type_2->setCurrentIndex(pkm_type_2[pkm_id]);
    ui->comboBox_GrowthRate->setCurrentIndex(pkm_growth_rate[pkm_id]);

    ui->tableWidget_StartingMoves->setItem(0,0,new QTableWidgetItem(move_name[pkm_start_move_1[pkm_id]]));
    ui->tableWidget_StartingMoves->setItem(1,0,new QTableWidgetItem(move_name[pkm_start_move_2[pkm_id]]));
    ui->tableWidget_StartingMoves->setItem(2,0,new QTableWidgetItem(move_name[pkm_start_move_3[pkm_id]]));
    ui->tableWidget_StartingMoves->setItem(3,0,new QTableWidgetItem(move_name[pkm_start_move_4[pkm_id]]));

    ui->tableWidget_MoveLevel_RB->setItem(0,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][0])));
    ui->tableWidget_MoveLevel_RB->setItem(1,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][1])));
    ui->tableWidget_MoveLevel_RB->setItem(2,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][2])));
    ui->tableWidget_MoveLevel_RB->setItem(3,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][3])));
    ui->tableWidget_MoveLevel_RB->setItem(4,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][4])));
    ui->tableWidget_MoveLevel_RB->setItem(5,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][5])));
    ui->tableWidget_MoveLevel_RB->setItem(6,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][6])));
    ui->tableWidget_MoveLevel_RB->setItem(7,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][7])));
    ui->tableWidget_MoveLevel_RB->setItem(8,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][8])));
    ui->tableWidget_MoveLevel_RB->setItem(9,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[pkm_id][9])));
    ui->tableWidget_MoveLevel_RB->setItem(0,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][0]]));
    ui->tableWidget_MoveLevel_RB->setItem(1,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][1]]));
    ui->tableWidget_MoveLevel_RB->setItem(2,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][2]]));
    ui->tableWidget_MoveLevel_RB->setItem(3,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][3]]));
    ui->tableWidget_MoveLevel_RB->setItem(4,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][4]]));
    ui->tableWidget_MoveLevel_RB->setItem(5,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][5]]));
    ui->tableWidget_MoveLevel_RB->setItem(6,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][6]]));
    ui->tableWidget_MoveLevel_RB->setItem(7,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][7]]));
    ui->tableWidget_MoveLevel_RB->setItem(8,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][8]]));
    ui->tableWidget_MoveLevel_RB->setItem(9,1,new QTableWidgetItem(move_name[pkm_rb_move[pkm_id][9]]));

    ui->tableWidget_MoveLevel_Y->setItem(0,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][0])));
    ui->tableWidget_MoveLevel_Y->setItem(1,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][1])));
    ui->tableWidget_MoveLevel_Y->setItem(2,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][2])));
    ui->tableWidget_MoveLevel_Y->setItem(3,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][3])));
    ui->tableWidget_MoveLevel_Y->setItem(4,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][4])));
    ui->tableWidget_MoveLevel_Y->setItem(5,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][5])));
    ui->tableWidget_MoveLevel_Y->setItem(6,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][6])));
    ui->tableWidget_MoveLevel_Y->setItem(7,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][7])));
    ui->tableWidget_MoveLevel_Y->setItem(8,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][8])));
    ui->tableWidget_MoveLevel_Y->setItem(9,0,new QTableWidgetItem(QString::number(pkm_y_lvl[pkm_id][9])));
    ui->tableWidget_MoveLevel_Y->setItem(0,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][0]]));
    ui->tableWidget_MoveLevel_Y->setItem(1,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][1]]));
    ui->tableWidget_MoveLevel_Y->setItem(2,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][2]]));
    ui->tableWidget_MoveLevel_Y->setItem(3,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][3]]));
    ui->tableWidget_MoveLevel_Y->setItem(4,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][4]]));
    ui->tableWidget_MoveLevel_Y->setItem(5,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][5]]));
    ui->tableWidget_MoveLevel_Y->setItem(6,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][6]]));
    ui->tableWidget_MoveLevel_Y->setItem(7,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][7]]));
    ui->tableWidget_MoveLevel_Y->setItem(8,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][8]]));
    ui->tableWidget_MoveLevel_Y->setItem(9,1,new QTableWidgetItem(move_name[pkm_y_move[pkm_id][9]]));

    move_tmhm_byte = 0;
    move_tmhm_flag = 0;

    for(short i=1;i<56;i++){
        move_tmhm_flag = (i-1)%8;
        move_tmhm_byte = (i-1)/8;

        QCheckBox *move_tmhm_chkboxs = qobject_cast<QCheckBox *>(ui->tableWidget_MoveTM->cellWidget(i-1,0));

        if((1<<move_tmhm_flag) & pkm_tmhm_flags[pkm_id][move_tmhm_byte]){
            move_tmhm_chkboxs->setChecked(true);
        }
        else{
            move_tmhm_chkboxs->setChecked(false);
        }
    }

    ui->textEdit_PokedexEntry->setText(pokedex_entry[pkm_id]);
    ui->spinBox_Pokedex_Pointer->setValue(pokedex_entry_pointer[pkm_id]);
}
