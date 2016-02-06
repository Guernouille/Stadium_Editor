#include "mainwindow.h"

void MainWindow::display_cpu_trainer_pkmn(quint8 cpu_trainer_id)
{
    // CPU Team initialization
    ui->lineEdit_CPU_TrainerName->setText(cpu_tname[cpu_trainer_id]);
    ui->spinBox_TrainerSpriteID->setValue(cpu_sprite_id[cpu_trainer_id]);
    img_path = ":/trainer_sprites/";
    img_path += QString::number(cpu_sprite_id[cpu_trainer_id]);
    ui->img_TrainerSprite->setPixmap(QPixmap(img_path));

    ui->comboBox_Pkmn_1->setCurrentIndex(cpu_pkm_id[cpu_trainer_id][0]);
    ui->comboBox_Pkmn_2->setCurrentIndex(cpu_pkm_id[cpu_trainer_id][1]);
    ui->comboBox_Pkmn_3->setCurrentIndex(cpu_pkm_id[cpu_trainer_id][2]);
    ui->comboBox_Pkmn_4->setCurrentIndex(cpu_pkm_id[cpu_trainer_id][3]);
    ui->comboBox_Pkmn_5->setCurrentIndex(cpu_pkm_id[cpu_trainer_id][4]);
    ui->comboBox_Pkmn_6->setCurrentIndex(cpu_pkm_id[cpu_trainer_id][5]);

    ui->lineEdit_Nickname_1->setText(cpu_pkm_nickname[cpu_trainer_id][0]);
    ui->lineEdit_Nickname_2->setText(cpu_pkm_nickname[cpu_trainer_id][1]);
    ui->lineEdit_Nickname_3->setText(cpu_pkm_nickname[cpu_trainer_id][2]);
    ui->lineEdit_Nickname_4->setText(cpu_pkm_nickname[cpu_trainer_id][3]);
    ui->lineEdit_Nickname_5->setText(cpu_pkm_nickname[cpu_trainer_id][4]);
    ui->lineEdit_Nickname_6->setText(cpu_pkm_nickname[cpu_trainer_id][5]);

    ui->spinBox_Lv_1->setValue(cpu_pkm_level[cpu_trainer_id][0]);
    ui->spinBox_Lv_2->setValue(cpu_pkm_level[cpu_trainer_id][1]);
    ui->spinBox_Lv_3->setValue(cpu_pkm_level[cpu_trainer_id][2]);
    ui->spinBox_Lv_4->setValue(cpu_pkm_level[cpu_trainer_id][3]);
    ui->spinBox_Lv_5->setValue(cpu_pkm_level[cpu_trainer_id][4]);
    ui->spinBox_Lv_6->setValue(cpu_pkm_level[cpu_trainer_id][5]);

    ui->spinBox_IV_HP_1->setValue(cpu_pkm_iv_hp[cpu_trainer_id][0]);
    ui->spinBox_IV_HP_2->setValue(cpu_pkm_iv_hp[cpu_trainer_id][1]);
    ui->spinBox_IV_HP_3->setValue(cpu_pkm_iv_hp[cpu_trainer_id][2]);
    ui->spinBox_IV_HP_4->setValue(cpu_pkm_iv_hp[cpu_trainer_id][3]);
    ui->spinBox_IV_HP_5->setValue(cpu_pkm_iv_hp[cpu_trainer_id][4]);
    ui->spinBox_IV_HP_6->setValue(cpu_pkm_iv_hp[cpu_trainer_id][5]);
    ui->spinBox_IV_Attack_1->setValue(cpu_pkm_iv_atk[cpu_trainer_id][0]);
    ui->spinBox_IV_Attack_2->setValue(cpu_pkm_iv_atk[cpu_trainer_id][1]);
    ui->spinBox_IV_Attack_3->setValue(cpu_pkm_iv_atk[cpu_trainer_id][2]);
    ui->spinBox_IV_Attack_4->setValue(cpu_pkm_iv_atk[cpu_trainer_id][3]);
    ui->spinBox_IV_Attack_5->setValue(cpu_pkm_iv_atk[cpu_trainer_id][4]);
    ui->spinBox_IV_Attack_6->setValue(cpu_pkm_iv_atk[cpu_trainer_id][5]);
    ui->spinBox_IV_Defense_1->setValue(cpu_pkm_iv_def[cpu_trainer_id][0]);
    ui->spinBox_IV_Defense_2->setValue(cpu_pkm_iv_def[cpu_trainer_id][1]);
    ui->spinBox_IV_Defense_3->setValue(cpu_pkm_iv_def[cpu_trainer_id][2]);
    ui->spinBox_IV_Defense_4->setValue(cpu_pkm_iv_def[cpu_trainer_id][3]);
    ui->spinBox_IV_Defense_5->setValue(cpu_pkm_iv_def[cpu_trainer_id][4]);
    ui->spinBox_IV_Defense_6->setValue(cpu_pkm_iv_def[cpu_trainer_id][5]);
    ui->spinBox_IV_Special_1->setValue(cpu_pkm_iv_spc[cpu_trainer_id][0]);
    ui->spinBox_IV_Special_2->setValue(cpu_pkm_iv_spc[cpu_trainer_id][1]);
    ui->spinBox_IV_Special_3->setValue(cpu_pkm_iv_spc[cpu_trainer_id][2]);
    ui->spinBox_IV_Special_4->setValue(cpu_pkm_iv_spc[cpu_trainer_id][3]);
    ui->spinBox_IV_Special_5->setValue(cpu_pkm_iv_spc[cpu_trainer_id][4]);
    ui->spinBox_IV_Special_6->setValue(cpu_pkm_iv_spc[cpu_trainer_id][5]);
    ui->spinBox_IV_Speed_1->setValue(cpu_pkm_iv_speed[cpu_trainer_id][0]);
    ui->spinBox_IV_Speed_2->setValue(cpu_pkm_iv_speed[cpu_trainer_id][1]);
    ui->spinBox_IV_Speed_3->setValue(cpu_pkm_iv_speed[cpu_trainer_id][2]);
    ui->spinBox_IV_Speed_4->setValue(cpu_pkm_iv_speed[cpu_trainer_id][3]);
    ui->spinBox_IV_Speed_5->setValue(cpu_pkm_iv_speed[cpu_trainer_id][4]);
    ui->spinBox_IV_Speed_6->setValue(cpu_pkm_iv_speed[cpu_trainer_id][5]);

    ui->spinBox_EV_HP_1->setValue(cpu_pkm_ev_hp[cpu_trainer_id][0]);
    ui->spinBox_EV_HP_2->setValue(cpu_pkm_ev_hp[cpu_trainer_id][1]);
    ui->spinBox_EV_HP_3->setValue(cpu_pkm_ev_hp[cpu_trainer_id][2]);
    ui->spinBox_EV_HP_4->setValue(cpu_pkm_ev_hp[cpu_trainer_id][3]);
    ui->spinBox_EV_HP_5->setValue(cpu_pkm_ev_hp[cpu_trainer_id][4]);
    ui->spinBox_EV_HP_6->setValue(cpu_pkm_ev_hp[cpu_trainer_id][5]);
    ui->spinBox_EV_Attack_1->setValue(cpu_pkm_ev_atk[cpu_trainer_id][0]);
    ui->spinBox_EV_Attack_2->setValue(cpu_pkm_ev_atk[cpu_trainer_id][1]);
    ui->spinBox_EV_Attack_3->setValue(cpu_pkm_ev_atk[cpu_trainer_id][2]);
    ui->spinBox_EV_Attack_4->setValue(cpu_pkm_ev_atk[cpu_trainer_id][3]);
    ui->spinBox_EV_Attack_5->setValue(cpu_pkm_ev_atk[cpu_trainer_id][4]);
    ui->spinBox_EV_Attack_6->setValue(cpu_pkm_ev_atk[cpu_trainer_id][5]);
    ui->spinBox_EV_Defense_1->setValue(cpu_pkm_ev_def[cpu_trainer_id][0]);
    ui->spinBox_EV_Defense_2->setValue(cpu_pkm_ev_def[cpu_trainer_id][1]);
    ui->spinBox_EV_Defense_3->setValue(cpu_pkm_ev_def[cpu_trainer_id][2]);
    ui->spinBox_EV_Defense_4->setValue(cpu_pkm_ev_def[cpu_trainer_id][3]);
    ui->spinBox_EV_Defense_5->setValue(cpu_pkm_ev_def[cpu_trainer_id][4]);
    ui->spinBox_EV_Defense_6->setValue(cpu_pkm_ev_def[cpu_trainer_id][5]);
    ui->spinBox_EV_Special_1->setValue(cpu_pkm_ev_spc[cpu_trainer_id][0]);
    ui->spinBox_EV_Special_2->setValue(cpu_pkm_ev_spc[cpu_trainer_id][1]);
    ui->spinBox_EV_Special_3->setValue(cpu_pkm_ev_spc[cpu_trainer_id][2]);
    ui->spinBox_EV_Special_4->setValue(cpu_pkm_ev_spc[cpu_trainer_id][3]);
    ui->spinBox_EV_Special_5->setValue(cpu_pkm_ev_spc[cpu_trainer_id][4]);
    ui->spinBox_EV_Special_6->setValue(cpu_pkm_ev_spc[cpu_trainer_id][5]);
    ui->spinBox_EV_Speed_1->setValue(cpu_pkm_ev_speed[cpu_trainer_id][0]);
    ui->spinBox_EV_Speed_2->setValue(cpu_pkm_ev_speed[cpu_trainer_id][1]);
    ui->spinBox_EV_Speed_3->setValue(cpu_pkm_ev_speed[cpu_trainer_id][2]);
    ui->spinBox_EV_Speed_4->setValue(cpu_pkm_ev_speed[cpu_trainer_id][3]);
    ui->spinBox_EV_Speed_5->setValue(cpu_pkm_ev_speed[cpu_trainer_id][4]);
    ui->spinBox_EV_Speed_6->setValue(cpu_pkm_ev_speed[cpu_trainer_id][5]);

    ui->comboBox_Move1_1->setCurrentIndex(cpu_pkm_move_1[cpu_trainer_id][0]);
    ui->comboBox_Move2_1->setCurrentIndex(cpu_pkm_move_2[cpu_trainer_id][0]);
    ui->comboBox_Move3_1->setCurrentIndex(cpu_pkm_move_3[cpu_trainer_id][0]);
    ui->comboBox_Move4_1->setCurrentIndex(cpu_pkm_move_4[cpu_trainer_id][0]);
    ui->comboBox_Move1_2->setCurrentIndex(cpu_pkm_move_1[cpu_trainer_id][1]);
    ui->comboBox_Move2_2->setCurrentIndex(cpu_pkm_move_2[cpu_trainer_id][1]);
    ui->comboBox_Move3_2->setCurrentIndex(cpu_pkm_move_3[cpu_trainer_id][1]);
    ui->comboBox_Move4_2->setCurrentIndex(cpu_pkm_move_4[cpu_trainer_id][1]);
    ui->comboBox_Move1_3->setCurrentIndex(cpu_pkm_move_1[cpu_trainer_id][2]);
    ui->comboBox_Move2_3->setCurrentIndex(cpu_pkm_move_2[cpu_trainer_id][2]);
    ui->comboBox_Move3_3->setCurrentIndex(cpu_pkm_move_3[cpu_trainer_id][2]);
    ui->comboBox_Move4_3->setCurrentIndex(cpu_pkm_move_4[cpu_trainer_id][2]);
    ui->comboBox_Move1_4->setCurrentIndex(cpu_pkm_move_1[cpu_trainer_id][3]);
    ui->comboBox_Move2_4->setCurrentIndex(cpu_pkm_move_2[cpu_trainer_id][3]);
    ui->comboBox_Move3_4->setCurrentIndex(cpu_pkm_move_3[cpu_trainer_id][3]);
    ui->comboBox_Move4_4->setCurrentIndex(cpu_pkm_move_4[cpu_trainer_id][3]);
    ui->comboBox_Move1_5->setCurrentIndex(cpu_pkm_move_1[cpu_trainer_id][4]);
    ui->comboBox_Move2_5->setCurrentIndex(cpu_pkm_move_2[cpu_trainer_id][4]);
    ui->comboBox_Move3_5->setCurrentIndex(cpu_pkm_move_3[cpu_trainer_id][4]);
    ui->comboBox_Move4_5->setCurrentIndex(cpu_pkm_move_4[cpu_trainer_id][4]);
    ui->comboBox_Move1_6->setCurrentIndex(cpu_pkm_move_1[cpu_trainer_id][5]);
    ui->comboBox_Move2_6->setCurrentIndex(cpu_pkm_move_2[cpu_trainer_id][5]);
    ui->comboBox_Move3_6->setCurrentIndex(cpu_pkm_move_3[cpu_trainer_id][5]);
    ui->comboBox_Move4_6->setCurrentIndex(cpu_pkm_move_4[cpu_trainer_id][5]);

    ui->spinBox_PPUp1_1->setValue(cpu_pkm_ppup_1[cpu_trainer_id][0]);
    ui->spinBox_PPUp2_1->setValue(cpu_pkm_ppup_2[cpu_trainer_id][0]);
    ui->spinBox_PPUp3_1->setValue(cpu_pkm_ppup_3[cpu_trainer_id][0]);
    ui->spinBox_PPUp4_1->setValue(cpu_pkm_ppup_4[cpu_trainer_id][0]);
    ui->spinBox_PPUp1_2->setValue(cpu_pkm_ppup_1[cpu_trainer_id][1]);
    ui->spinBox_PPUp2_2->setValue(cpu_pkm_ppup_2[cpu_trainer_id][1]);
    ui->spinBox_PPUp3_2->setValue(cpu_pkm_ppup_3[cpu_trainer_id][1]);
    ui->spinBox_PPUp4_2->setValue(cpu_pkm_ppup_4[cpu_trainer_id][1]);
    ui->spinBox_PPUp1_3->setValue(cpu_pkm_ppup_1[cpu_trainer_id][2]);
    ui->spinBox_PPUp2_3->setValue(cpu_pkm_ppup_2[cpu_trainer_id][2]);
    ui->spinBox_PPUp3_3->setValue(cpu_pkm_ppup_3[cpu_trainer_id][2]);
    ui->spinBox_PPUp4_3->setValue(cpu_pkm_ppup_4[cpu_trainer_id][2]);
    ui->spinBox_PPUp1_4->setValue(cpu_pkm_ppup_1[cpu_trainer_id][3]);
    ui->spinBox_PPUp2_4->setValue(cpu_pkm_ppup_2[cpu_trainer_id][3]);
    ui->spinBox_PPUp3_4->setValue(cpu_pkm_ppup_3[cpu_trainer_id][3]);
    ui->spinBox_PPUp4_4->setValue(cpu_pkm_ppup_4[cpu_trainer_id][3]);
    ui->spinBox_PPUp1_5->setValue(cpu_pkm_ppup_1[cpu_trainer_id][4]);
    ui->spinBox_PPUp2_5->setValue(cpu_pkm_ppup_2[cpu_trainer_id][4]);
    ui->spinBox_PPUp3_5->setValue(cpu_pkm_ppup_3[cpu_trainer_id][4]);
    ui->spinBox_PPUp4_5->setValue(cpu_pkm_ppup_4[cpu_trainer_id][4]);
    ui->spinBox_PPUp1_6->setValue(cpu_pkm_ppup_1[cpu_trainer_id][5]);
    ui->spinBox_PPUp2_6->setValue(cpu_pkm_ppup_2[cpu_trainer_id][5]);
    ui->spinBox_PPUp3_6->setValue(cpu_pkm_ppup_3[cpu_trainer_id][5]);
    ui->spinBox_PPUp4_6->setValue(cpu_pkm_ppup_4[cpu_trainer_id][5]);
}


void MainWindow::display_cpu_trainer_sprite(quint8 cpu_trainer_sprite_id)
{
    ui->img_TrainerSprite->clear();

    if(cpu_trainer_sprite_id > 53){
        cpu_trainer_sprite_id = 0;
    }

    img_path = ":/trainer_sprites/";
    img_path += QString::number(cpu_trainer_sprite_id);
    ui->img_TrainerSprite->setPixmap(img_path);
}
