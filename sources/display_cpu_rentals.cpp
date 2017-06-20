#include "mainwindow.h"

void MainWindow::display_cpu_trainer_pkmn(quint8 cpu_trainer_id)
{
    // CPU Team initialization
    ui->lineEdit_CPU_TrainerName->setText(cpu_trainers[cpu_trainer_id].name);
    ui->spinBox_TrainerSpriteID->setValue(cpu_trainers[cpu_trainer_id].sprite_id);
    img_path = ":/trainer_sprites/";
    img_path += QString::number(cpu_trainers[cpu_trainer_id].sprite_id);
    ui->img_TrainerSprite->setPixmap(QPixmap(img_path));
    ui->spinBox_CPU_PartySize->setValue(cpu_trainers[cpu_trainer_id].party_size);
    ui->spinBox_CPU_AI->setValue(cpu_trainers[cpu_trainer_id].ai_id);

    ui->comboBox_Pkmn_1->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[0].id);
    ui->comboBox_Pkmn_2->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[1].id);
    ui->comboBox_Pkmn_3->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[2].id);
    ui->comboBox_Pkmn_4->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[3].id);
    ui->comboBox_Pkmn_5->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[4].id);
    ui->comboBox_Pkmn_6->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[5].id);

    ui->lineEdit_Nickname_1->setText(cpu_trainers[cpu_trainer_id].pkm[0].nick);
    ui->lineEdit_Nickname_2->setText(cpu_trainers[cpu_trainer_id].pkm[1].nick);
    ui->lineEdit_Nickname_3->setText(cpu_trainers[cpu_trainer_id].pkm[2].nick);
    ui->lineEdit_Nickname_4->setText(cpu_trainers[cpu_trainer_id].pkm[3].nick);
    ui->lineEdit_Nickname_5->setText(cpu_trainers[cpu_trainer_id].pkm[4].nick);
    ui->lineEdit_Nickname_6->setText(cpu_trainers[cpu_trainer_id].pkm[5].nick);

    ui->spinBox_Lv_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].lvl);
    ui->spinBox_Lv_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].lvl);
    ui->spinBox_Lv_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].lvl);
    ui->spinBox_Lv_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].lvl);
    ui->spinBox_Lv_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].lvl);
    ui->spinBox_Lv_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].lvl);

    ui->spinBox_IV_HP_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].hp_iv);
    ui->spinBox_IV_HP_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].hp_iv);
    ui->spinBox_IV_HP_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].hp_iv);
    ui->spinBox_IV_HP_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].hp_iv);
    ui->spinBox_IV_HP_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].hp_iv);
    ui->spinBox_IV_HP_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].hp_iv);
    ui->spinBox_IV_Attack_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].atk_iv);
    ui->spinBox_IV_Attack_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].atk_iv);
    ui->spinBox_IV_Attack_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].atk_iv);
    ui->spinBox_IV_Attack_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].atk_iv);
    ui->spinBox_IV_Attack_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].atk_iv);
    ui->spinBox_IV_Attack_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].atk_iv);
    ui->spinBox_IV_Defense_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].def_iv);
    ui->spinBox_IV_Defense_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].def_iv);
    ui->spinBox_IV_Defense_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].def_iv);
    ui->spinBox_IV_Defense_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].def_iv);
    ui->spinBox_IV_Defense_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].def_iv);
    ui->spinBox_IV_Defense_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].def_iv);
    ui->spinBox_IV_Special_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].spc_iv);
    ui->spinBox_IV_Special_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].spc_iv);
    ui->spinBox_IV_Special_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].spc_iv);
    ui->spinBox_IV_Special_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].spc_iv);
    ui->spinBox_IV_Special_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].spc_iv);
    ui->spinBox_IV_Special_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].spc_iv);
    ui->spinBox_IV_Speed_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].speed_iv);
    ui->spinBox_IV_Speed_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].speed_iv);
    ui->spinBox_IV_Speed_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].speed_iv);
    ui->spinBox_IV_Speed_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].speed_iv);
    ui->spinBox_IV_Speed_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].speed_iv);
    ui->spinBox_IV_Speed_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].speed_iv);

    ui->spinBox_EV_HP_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].hp_ev);
    ui->spinBox_EV_HP_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].hp_ev);
    ui->spinBox_EV_HP_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].hp_ev);
    ui->spinBox_EV_HP_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].hp_ev);
    ui->spinBox_EV_HP_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].hp_ev);
    ui->spinBox_EV_HP_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].hp_ev);
    ui->spinBox_EV_Attack_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].atk_ev);
    ui->spinBox_EV_Attack_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].atk_ev);
    ui->spinBox_EV_Attack_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].atk_ev);
    ui->spinBox_EV_Attack_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].atk_ev);
    ui->spinBox_EV_Attack_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].atk_ev);
    ui->spinBox_EV_Attack_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].atk_ev);
    ui->spinBox_EV_Defense_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].def_ev);
    ui->spinBox_EV_Defense_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].def_ev);
    ui->spinBox_EV_Defense_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].def_ev);
    ui->spinBox_EV_Defense_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].def_ev);
    ui->spinBox_EV_Defense_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].def_ev);
    ui->spinBox_EV_Defense_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].def_ev);
    ui->spinBox_EV_Special_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].spc_ev);
    ui->spinBox_EV_Special_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].spc_ev);
    ui->spinBox_EV_Special_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].spc_ev);
    ui->spinBox_EV_Special_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].spc_ev);
    ui->spinBox_EV_Special_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].spc_ev);
    ui->spinBox_EV_Special_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].spc_ev);
    ui->spinBox_EV_Speed_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].speed_ev);
    ui->spinBox_EV_Speed_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].speed_ev);
    ui->spinBox_EV_Speed_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].speed_ev);
    ui->spinBox_EV_Speed_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].speed_ev);
    ui->spinBox_EV_Speed_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].speed_ev);
    ui->spinBox_EV_Speed_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].speed_ev);

    ui->comboBox_Move1_1->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[0].move_1);
    ui->comboBox_Move2_1->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[0].move_2);
    ui->comboBox_Move3_1->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[0].move_3);
    ui->comboBox_Move4_1->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[0].move_4);
    ui->comboBox_Move1_2->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[1].move_1);
    ui->comboBox_Move2_2->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[1].move_2);
    ui->comboBox_Move3_2->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[1].move_3);
    ui->comboBox_Move4_2->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[1].move_4);
    ui->comboBox_Move1_3->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[2].move_1);
    ui->comboBox_Move2_3->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[2].move_2);
    ui->comboBox_Move3_3->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[2].move_3);
    ui->comboBox_Move4_3->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[2].move_4);
    ui->comboBox_Move1_4->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[3].move_1);
    ui->comboBox_Move2_4->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[3].move_2);
    ui->comboBox_Move3_4->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[3].move_3);
    ui->comboBox_Move4_4->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[3].move_4);
    ui->comboBox_Move1_5->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[4].move_1);
    ui->comboBox_Move2_5->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[4].move_2);
    ui->comboBox_Move3_5->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[4].move_3);
    ui->comboBox_Move4_5->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[4].move_4);
    ui->comboBox_Move1_6->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[5].move_1);
    ui->comboBox_Move2_6->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[5].move_2);
    ui->comboBox_Move3_6->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[5].move_3);
    ui->comboBox_Move4_6->setCurrentIndex(cpu_trainers[cpu_trainer_id].pkm[5].move_4);

    ui->spinBox_PPUp1_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].ppup_1);
    ui->spinBox_PPUp2_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].ppup_2);
    ui->spinBox_PPUp3_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].ppup_3);
    ui->spinBox_PPUp4_1->setValue(cpu_trainers[cpu_trainer_id].pkm[0].ppup_4);
    ui->spinBox_PPUp1_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].ppup_1);
    ui->spinBox_PPUp2_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].ppup_2);
    ui->spinBox_PPUp3_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].ppup_3);
    ui->spinBox_PPUp4_2->setValue(cpu_trainers[cpu_trainer_id].pkm[1].ppup_4);
    ui->spinBox_PPUp1_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].ppup_1);
    ui->spinBox_PPUp2_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].ppup_2);
    ui->spinBox_PPUp3_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].ppup_3);
    ui->spinBox_PPUp4_3->setValue(cpu_trainers[cpu_trainer_id].pkm[2].ppup_4);
    ui->spinBox_PPUp1_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].ppup_1);
    ui->spinBox_PPUp2_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].ppup_2);
    ui->spinBox_PPUp3_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].ppup_3);
    ui->spinBox_PPUp4_4->setValue(cpu_trainers[cpu_trainer_id].pkm[3].ppup_4);
    ui->spinBox_PPUp1_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].ppup_1);
    ui->spinBox_PPUp2_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].ppup_2);
    ui->spinBox_PPUp3_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].ppup_3);
    ui->spinBox_PPUp4_5->setValue(cpu_trainers[cpu_trainer_id].pkm[4].ppup_4);
    ui->spinBox_PPUp1_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].ppup_1);
    ui->spinBox_PPUp2_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].ppup_2);
    ui->spinBox_PPUp3_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].ppup_3);
    ui->spinBox_PPUp4_6->setValue(cpu_trainers[cpu_trainer_id].pkm[5].ppup_4);
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


void MainWindow::display_rental_pkmn(quint16 rental_pkm_offset)
{
    ui->comboBox_Rental_Pkmn_1->setCurrentIndex(rental_pkm_id[rental_pkm_offset]);
    ui->comboBox_Rental_Pkmn_2->setCurrentIndex(rental_pkm_id[rental_pkm_offset+1]);
    ui->comboBox_Rental_Pkmn_3->setCurrentIndex(rental_pkm_id[rental_pkm_offset+2]);
    ui->comboBox_Rental_Pkmn_4->setCurrentIndex(rental_pkm_id[rental_pkm_offset+3]);
    ui->comboBox_Rental_Pkmn_5->setCurrentIndex(rental_pkm_id[rental_pkm_offset+4]);
    ui->comboBox_Rental_Pkmn_6->setCurrentIndex(rental_pkm_id[rental_pkm_offset+5]);

    ui->lineEdit_Rental_Nickname_1->setText(rental_pkm_nickname[rental_pkm_offset]);
    ui->lineEdit_Rental_Nickname_2->setText(rental_pkm_nickname[rental_pkm_offset+1]);
    ui->lineEdit_Rental_Nickname_3->setText(rental_pkm_nickname[rental_pkm_offset+2]);
    ui->lineEdit_Rental_Nickname_4->setText(rental_pkm_nickname[rental_pkm_offset+3]);
    ui->lineEdit_Rental_Nickname_5->setText(rental_pkm_nickname[rental_pkm_offset+4]);
    ui->lineEdit_Rental_Nickname_6->setText(rental_pkm_nickname[rental_pkm_offset+5]);

    ui->spinBox_Rental_Lv_1->setValue(rental_pkm_level[rental_pkm_offset]);
    ui->spinBox_Rental_Lv_2->setValue(rental_pkm_level[rental_pkm_offset+1]);
    ui->spinBox_Rental_Lv_3->setValue(rental_pkm_level[rental_pkm_offset+2]);
    ui->spinBox_Rental_Lv_4->setValue(rental_pkm_level[rental_pkm_offset+3]);
    ui->spinBox_Rental_Lv_5->setValue(rental_pkm_level[rental_pkm_offset+4]);
    ui->spinBox_Rental_Lv_6->setValue(rental_pkm_level[rental_pkm_offset+5]);

    ui->spinBox_Rental_IV_HP_1->setValue(rental_pkm_iv_hp[rental_pkm_offset]);
    ui->spinBox_Rental_IV_HP_2->setValue(rental_pkm_iv_hp[rental_pkm_offset+1]);
    ui->spinBox_Rental_IV_HP_3->setValue(rental_pkm_iv_hp[rental_pkm_offset+2]);
    ui->spinBox_Rental_IV_HP_4->setValue(rental_pkm_iv_hp[rental_pkm_offset+3]);
    ui->spinBox_Rental_IV_HP_5->setValue(rental_pkm_iv_hp[rental_pkm_offset+4]);
    ui->spinBox_Rental_IV_HP_6->setValue(rental_pkm_iv_hp[rental_pkm_offset+5]);
    ui->spinBox_Rental_IV_Attack_1->setValue(rental_pkm_iv_atk[rental_pkm_offset]);
    ui->spinBox_Rental_IV_Attack_2->setValue(rental_pkm_iv_atk[rental_pkm_offset+1]);
    ui->spinBox_Rental_IV_Attack_3->setValue(rental_pkm_iv_atk[rental_pkm_offset+2]);
    ui->spinBox_Rental_IV_Attack_4->setValue(rental_pkm_iv_atk[rental_pkm_offset+3]);
    ui->spinBox_Rental_IV_Attack_5->setValue(rental_pkm_iv_atk[rental_pkm_offset+4]);
    ui->spinBox_Rental_IV_Attack_6->setValue(rental_pkm_iv_atk[rental_pkm_offset+5]);
    ui->spinBox_Rental_IV_Defense_1->setValue(rental_pkm_iv_def[rental_pkm_offset]);
    ui->spinBox_Rental_IV_Defense_2->setValue(rental_pkm_iv_def[rental_pkm_offset+1]);
    ui->spinBox_Rental_IV_Defense_3->setValue(rental_pkm_iv_def[rental_pkm_offset+2]);
    ui->spinBox_Rental_IV_Defense_4->setValue(rental_pkm_iv_def[rental_pkm_offset+3]);
    ui->spinBox_Rental_IV_Defense_5->setValue(rental_pkm_iv_def[rental_pkm_offset+4]);
    ui->spinBox_Rental_IV_Defense_6->setValue(rental_pkm_iv_def[rental_pkm_offset+5]);
    ui->spinBox_Rental_IV_Special_1->setValue(rental_pkm_iv_spc[rental_pkm_offset]);
    ui->spinBox_Rental_IV_Special_2->setValue(rental_pkm_iv_spc[rental_pkm_offset+1]);
    ui->spinBox_Rental_IV_Special_3->setValue(rental_pkm_iv_spc[rental_pkm_offset+2]);
    ui->spinBox_Rental_IV_Special_4->setValue(rental_pkm_iv_spc[rental_pkm_offset+3]);
    ui->spinBox_Rental_IV_Special_5->setValue(rental_pkm_iv_spc[rental_pkm_offset+4]);
    ui->spinBox_Rental_IV_Special_6->setValue(rental_pkm_iv_spc[rental_pkm_offset+5]);
    ui->spinBox_Rental_IV_Speed_1->setValue(rental_pkm_iv_speed[rental_pkm_offset]);
    ui->spinBox_Rental_IV_Speed_2->setValue(rental_pkm_iv_speed[rental_pkm_offset+1]);
    ui->spinBox_Rental_IV_Speed_3->setValue(rental_pkm_iv_speed[rental_pkm_offset+2]);
    ui->spinBox_Rental_IV_Speed_4->setValue(rental_pkm_iv_speed[rental_pkm_offset+3]);
    ui->spinBox_Rental_IV_Speed_5->setValue(rental_pkm_iv_speed[rental_pkm_offset+4]);
    ui->spinBox_Rental_IV_Speed_6->setValue(rental_pkm_iv_speed[rental_pkm_offset+5]);

    ui->spinBox_Rental_EV_HP_1->setValue(rental_pkm_ev_hp[rental_pkm_offset]);
    ui->spinBox_Rental_EV_HP_2->setValue(rental_pkm_ev_hp[rental_pkm_offset+1]);
    ui->spinBox_Rental_EV_HP_3->setValue(rental_pkm_ev_hp[rental_pkm_offset+2]);
    ui->spinBox_Rental_EV_HP_4->setValue(rental_pkm_ev_hp[rental_pkm_offset+3]);
    ui->spinBox_Rental_EV_HP_5->setValue(rental_pkm_ev_hp[rental_pkm_offset+4]);
    ui->spinBox_Rental_EV_HP_6->setValue(rental_pkm_ev_hp[rental_pkm_offset+5]);
    ui->spinBox_Rental_EV_Attack_1->setValue(rental_pkm_ev_atk[rental_pkm_offset]);
    ui->spinBox_Rental_EV_Attack_2->setValue(rental_pkm_ev_atk[rental_pkm_offset+1]);
    ui->spinBox_Rental_EV_Attack_3->setValue(rental_pkm_ev_atk[rental_pkm_offset+2]);
    ui->spinBox_Rental_EV_Attack_4->setValue(rental_pkm_ev_atk[rental_pkm_offset+3]);
    ui->spinBox_Rental_EV_Attack_5->setValue(rental_pkm_ev_atk[rental_pkm_offset+4]);
    ui->spinBox_Rental_EV_Attack_6->setValue(rental_pkm_ev_atk[rental_pkm_offset+5]);
    ui->spinBox_Rental_EV_Defense_1->setValue(rental_pkm_ev_def[rental_pkm_offset]);
    ui->spinBox_Rental_EV_Defense_2->setValue(rental_pkm_ev_def[rental_pkm_offset+1]);
    ui->spinBox_Rental_EV_Defense_3->setValue(rental_pkm_ev_def[rental_pkm_offset+2]);
    ui->spinBox_Rental_EV_Defense_4->setValue(rental_pkm_ev_def[rental_pkm_offset+3]);
    ui->spinBox_Rental_EV_Defense_5->setValue(rental_pkm_ev_def[rental_pkm_offset+4]);
    ui->spinBox_Rental_EV_Defense_6->setValue(rental_pkm_ev_def[rental_pkm_offset+5]);
    ui->spinBox_Rental_EV_Special_1->setValue(rental_pkm_ev_spc[rental_pkm_offset]);
    ui->spinBox_Rental_EV_Special_2->setValue(rental_pkm_ev_spc[rental_pkm_offset+1]);
    ui->spinBox_Rental_EV_Special_3->setValue(rental_pkm_ev_spc[rental_pkm_offset+2]);
    ui->spinBox_Rental_EV_Special_4->setValue(rental_pkm_ev_spc[rental_pkm_offset+3]);
    ui->spinBox_Rental_EV_Special_5->setValue(rental_pkm_ev_spc[rental_pkm_offset+4]);
    ui->spinBox_Rental_EV_Special_6->setValue(rental_pkm_ev_spc[rental_pkm_offset+5]);
    ui->spinBox_Rental_EV_Speed_1->setValue(rental_pkm_ev_speed[rental_pkm_offset]);
    ui->spinBox_Rental_EV_Speed_2->setValue(rental_pkm_ev_speed[rental_pkm_offset+1]);
    ui->spinBox_Rental_EV_Speed_3->setValue(rental_pkm_ev_speed[rental_pkm_offset+2]);
    ui->spinBox_Rental_EV_Speed_4->setValue(rental_pkm_ev_speed[rental_pkm_offset+3]);
    ui->spinBox_Rental_EV_Speed_5->setValue(rental_pkm_ev_speed[rental_pkm_offset+4]);
    ui->spinBox_Rental_EV_Speed_6->setValue(rental_pkm_ev_speed[rental_pkm_offset+5]);

    ui->comboBox_Rental_Move1_1->setCurrentIndex(rental_pkm_move_1[rental_pkm_offset]);
    ui->comboBox_Rental_Move2_1->setCurrentIndex(rental_pkm_move_2[rental_pkm_offset]);
    ui->comboBox_Rental_Move3_1->setCurrentIndex(rental_pkm_move_3[rental_pkm_offset]);
    ui->comboBox_Rental_Move4_1->setCurrentIndex(rental_pkm_move_4[rental_pkm_offset]);
    ui->comboBox_Rental_Move1_2->setCurrentIndex(rental_pkm_move_1[rental_pkm_offset+1]);
    ui->comboBox_Rental_Move2_2->setCurrentIndex(rental_pkm_move_2[rental_pkm_offset+1]);
    ui->comboBox_Rental_Move3_2->setCurrentIndex(rental_pkm_move_3[rental_pkm_offset+1]);
    ui->comboBox_Rental_Move4_2->setCurrentIndex(rental_pkm_move_4[rental_pkm_offset+1]);
    ui->comboBox_Rental_Move1_3->setCurrentIndex(rental_pkm_move_1[rental_pkm_offset+2]);
    ui->comboBox_Rental_Move2_3->setCurrentIndex(rental_pkm_move_2[rental_pkm_offset+2]);
    ui->comboBox_Rental_Move3_3->setCurrentIndex(rental_pkm_move_3[rental_pkm_offset+2]);
    ui->comboBox_Rental_Move4_3->setCurrentIndex(rental_pkm_move_4[rental_pkm_offset+2]);
    ui->comboBox_Rental_Move1_4->setCurrentIndex(rental_pkm_move_1[rental_pkm_offset+3]);
    ui->comboBox_Rental_Move2_4->setCurrentIndex(rental_pkm_move_2[rental_pkm_offset+3]);
    ui->comboBox_Rental_Move3_4->setCurrentIndex(rental_pkm_move_3[rental_pkm_offset+3]);
    ui->comboBox_Rental_Move4_4->setCurrentIndex(rental_pkm_move_4[rental_pkm_offset+3]);
    ui->comboBox_Rental_Move1_5->setCurrentIndex(rental_pkm_move_1[rental_pkm_offset+4]);
    ui->comboBox_Rental_Move2_5->setCurrentIndex(rental_pkm_move_2[rental_pkm_offset+4]);
    ui->comboBox_Rental_Move3_5->setCurrentIndex(rental_pkm_move_3[rental_pkm_offset+4]);
    ui->comboBox_Rental_Move4_5->setCurrentIndex(rental_pkm_move_4[rental_pkm_offset+4]);
    ui->comboBox_Rental_Move1_6->setCurrentIndex(rental_pkm_move_1[rental_pkm_offset+5]);
    ui->comboBox_Rental_Move2_6->setCurrentIndex(rental_pkm_move_2[rental_pkm_offset+5]);
    ui->comboBox_Rental_Move3_6->setCurrentIndex(rental_pkm_move_3[rental_pkm_offset+5]);
    ui->comboBox_Rental_Move4_6->setCurrentIndex(rental_pkm_move_4[rental_pkm_offset+5]);

    ui->spinBox_Rental_PPUp1_1->setValue(rental_pkm_ppup_1[rental_pkm_offset]);
    ui->spinBox_Rental_PPUp2_1->setValue(rental_pkm_ppup_2[rental_pkm_offset]);
    ui->spinBox_Rental_PPUp3_1->setValue(rental_pkm_ppup_3[rental_pkm_offset]);
    ui->spinBox_Rental_PPUp4_1->setValue(rental_pkm_ppup_4[rental_pkm_offset]);
    ui->spinBox_Rental_PPUp1_2->setValue(rental_pkm_ppup_1[rental_pkm_offset+1]);
    ui->spinBox_Rental_PPUp2_2->setValue(rental_pkm_ppup_2[rental_pkm_offset+1]);
    ui->spinBox_Rental_PPUp3_2->setValue(rental_pkm_ppup_3[rental_pkm_offset+1]);
    ui->spinBox_Rental_PPUp4_2->setValue(rental_pkm_ppup_4[rental_pkm_offset+1]);
    ui->spinBox_Rental_PPUp1_3->setValue(rental_pkm_ppup_1[rental_pkm_offset+2]);
    ui->spinBox_Rental_PPUp2_3->setValue(rental_pkm_ppup_2[rental_pkm_offset+2]);
    ui->spinBox_Rental_PPUp3_3->setValue(rental_pkm_ppup_3[rental_pkm_offset+2]);
    ui->spinBox_Rental_PPUp4_3->setValue(rental_pkm_ppup_4[rental_pkm_offset+2]);
    ui->spinBox_Rental_PPUp1_4->setValue(rental_pkm_ppup_1[rental_pkm_offset+3]);
    ui->spinBox_Rental_PPUp2_4->setValue(rental_pkm_ppup_2[rental_pkm_offset+3]);
    ui->spinBox_Rental_PPUp3_4->setValue(rental_pkm_ppup_3[rental_pkm_offset+3]);
    ui->spinBox_Rental_PPUp4_4->setValue(rental_pkm_ppup_4[rental_pkm_offset+3]);
    ui->spinBox_Rental_PPUp1_5->setValue(rental_pkm_ppup_1[rental_pkm_offset+4]);
    ui->spinBox_Rental_PPUp2_5->setValue(rental_pkm_ppup_2[rental_pkm_offset+4]);
    ui->spinBox_Rental_PPUp3_5->setValue(rental_pkm_ppup_3[rental_pkm_offset+4]);
    ui->spinBox_Rental_PPUp4_5->setValue(rental_pkm_ppup_4[rental_pkm_offset+4]);
    ui->spinBox_Rental_PPUp1_6->setValue(rental_pkm_ppup_1[rental_pkm_offset+5]);
    ui->spinBox_Rental_PPUp2_6->setValue(rental_pkm_ppup_2[rental_pkm_offset+5]);
    ui->spinBox_Rental_PPUp3_6->setValue(rental_pkm_ppup_3[rental_pkm_offset+5]);
    ui->spinBox_Rental_PPUp4_6->setValue(rental_pkm_ppup_4[rental_pkm_offset+5]);
}
