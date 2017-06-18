#include "mainwindow.h"

// Move IDs

// TODO: Combine these four into one slot when enough refactoring has been done.

void MainWindow::move1_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup1_boxes {
        ui->spinBox_PPUp1_1, ui->spinBox_PPUp1_2, ui->spinBox_PPUp1_3,
        ui->spinBox_PPUp1_4, ui->spinBox_PPUp1_5, ui->spinBox_PPUp1_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_move_1[buf8][pkm_num] = move1_comboboxes[pkm_num]->currentIndex();

        cpu_pkm_pp_1[buf8][pkm_num] = 0;
        if(cpu_pkm_ppup_1[buf8][pkm_num]>0 && cpu_pkm_move_1[buf8][pkm_num]>0){
            cpu_pkm_pp_1[buf8][pkm_num] = move_pp[cpu_pkm_move_1[buf8][pkm_num]] / 5;
            cpu_pkm_pp_1[buf8][pkm_num] *= cpu_pkm_ppup_1[buf8][pkm_num];
            cpu_pkm_pp_1[buf8][pkm_num] |= cpu_pkm_ppup_1[buf8][pkm_num]<<6;
        }
        else {
            ppup1_boxes[pkm_num]->setValue(0);
            cpu_pkm_ppup_1[buf8][pkm_num] = 0;
        }
        cpu_pkm_pp_1[buf8][pkm_num] += move_pp[cpu_pkm_move_1[buf8][pkm_num]];
    }
}

void MainWindow::move2_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup2_boxes {
        ui->spinBox_PPUp2_1, ui->spinBox_PPUp2_2, ui->spinBox_PPUp2_3,
        ui->spinBox_PPUp2_4, ui->spinBox_PPUp2_5, ui->spinBox_PPUp2_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_move_2[buf8][pkm_num] = move2_comboboxes[pkm_num]->currentIndex();

        cpu_pkm_pp_2[buf8][pkm_num] = 0;
        if(cpu_pkm_ppup_2[buf8][pkm_num]>0 && cpu_pkm_move_2[buf8][pkm_num]>0){
            cpu_pkm_pp_2[buf8][pkm_num] = move_pp[cpu_pkm_move_2[buf8][pkm_num]] / 5;
            cpu_pkm_pp_2[buf8][pkm_num] *= cpu_pkm_ppup_2[buf8][pkm_num];
            cpu_pkm_pp_2[buf8][pkm_num] |= cpu_pkm_ppup_2[buf8][pkm_num]<<6;
        }
        else {
            ppup2_boxes[pkm_num]->setValue(0);
            cpu_pkm_ppup_2[buf8][pkm_num] = 0;
        }
        cpu_pkm_pp_2[buf8][pkm_num] += move_pp[cpu_pkm_move_2[buf8][pkm_num]];
    }
}

void MainWindow::move3_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup3_boxes {
        ui->spinBox_PPUp3_1, ui->spinBox_PPUp3_2, ui->spinBox_PPUp3_3,
        ui->spinBox_PPUp3_4, ui->spinBox_PPUp3_5, ui->spinBox_PPUp3_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_move_3[buf8][pkm_num] = move3_comboboxes[pkm_num]->currentIndex();

        cpu_pkm_pp_3[buf8][pkm_num] = 0;
        if(cpu_pkm_ppup_3[buf8][pkm_num]>0 && cpu_pkm_move_3[buf8][pkm_num]>0){
            cpu_pkm_pp_3[buf8][pkm_num] = move_pp[cpu_pkm_move_3[buf8][pkm_num]] / 5;
            cpu_pkm_pp_3[buf8][pkm_num] *= cpu_pkm_ppup_3[buf8][pkm_num];
            cpu_pkm_pp_3[buf8][pkm_num] |= cpu_pkm_ppup_3[buf8][pkm_num]<<6;
        }
        else {
            ppup3_boxes[pkm_num]->setValue(0);
            cpu_pkm_ppup_3[buf8][pkm_num] = 0;
        }
        cpu_pkm_pp_3[buf8][pkm_num] += move_pp[cpu_pkm_move_3[buf8][pkm_num]];
    }
}

void MainWindow::move4_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup4_boxes {
        ui->spinBox_PPUp4_1, ui->spinBox_PPUp4_2, ui->spinBox_PPUp4_3,
        ui->spinBox_PPUp4_4, ui->spinBox_PPUp4_5, ui->spinBox_PPUp4_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_move_4[buf8][pkm_num] = move4_comboboxes[pkm_num]->currentIndex();

        cpu_pkm_pp_4[buf8][pkm_num] = 0;
        if(cpu_pkm_ppup_4[buf8][pkm_num]>0 && cpu_pkm_move_4[buf8][pkm_num]>0){
            cpu_pkm_pp_4[buf8][pkm_num] = move_pp[cpu_pkm_move_4[buf8][pkm_num]] / 5;
            cpu_pkm_pp_4[buf8][pkm_num] *= cpu_pkm_ppup_4[buf8][pkm_num];
            cpu_pkm_pp_4[buf8][pkm_num] |= cpu_pkm_ppup_4[buf8][pkm_num]<<6;
        }
        else {
            ppup4_boxes[pkm_num]->setValue(0);
            cpu_pkm_ppup_4[buf8][pkm_num] = 0;
        }
        cpu_pkm_pp_4[buf8][pkm_num] += move_pp[cpu_pkm_move_4[buf8][pkm_num]];
    }
}

// Pokémon IDs
void MainWindow::on_comboBox_Pkmn_1_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_ids[0] = ui->comboBox_Pkmn_1->currentIndex();
        cpu_pkm_experience[buf8][0] = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm_ids[0]],cpu_trainers[buf8].pkm_lvls[0]);
    }
}
void MainWindow::on_comboBox_Pkmn_2_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_ids[1] = ui->comboBox_Pkmn_2->currentIndex();
        cpu_pkm_experience[buf8][1] = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm_ids[1]],cpu_trainers[buf8].pkm_lvls[1]);
    }
}
void MainWindow::on_comboBox_Pkmn_3_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_ids[2] = ui->comboBox_Pkmn_3->currentIndex();
        cpu_pkm_experience[buf8][2] = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm_ids[2]],cpu_trainers[buf8].pkm_lvls[2]);
    }
}
void MainWindow::on_comboBox_Pkmn_4_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_ids[3] = ui->comboBox_Pkmn_4->currentIndex();
        cpu_pkm_experience[buf8][3] = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm_ids[3]],cpu_trainers[buf8].pkm_lvls[3]);
    }
}
void MainWindow::on_comboBox_Pkmn_5_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_ids[4] = ui->comboBox_Pkmn_5->currentIndex();
        cpu_pkm_experience[buf8][4] = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm_ids[4]],cpu_trainers[buf8].pkm_lvls[4]);
    }
}
void MainWindow::on_comboBox_Pkmn_6_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_ids[5] = ui->comboBox_Pkmn_6->currentIndex();
        cpu_pkm_experience[buf8][5] = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm_ids[5]],cpu_trainers[buf8].pkm_lvls[5]);
    }
}


// Nicknames
void MainWindow::on_lineEdit_Nickname_1_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_1->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_nicks[0] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm_nicks[0] += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm_nicks[0] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_1->setText(cpu_trainers[buf8].pkm_nicks[0]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_2_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_2->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_nicks[1] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm_nicks[1] += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm_nicks[1] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_2->setText(cpu_trainers[buf8].pkm_nicks[1]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_3_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_3->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_nicks[2] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm_nicks[2] += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm_nicks[2] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_3->setText(cpu_trainers[buf8].pkm_nicks[2]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_4_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_4->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_nicks[3] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm_nicks[3] += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm_nicks[3] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_4->setText(cpu_trainers[buf8].pkm_nicks[3]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_5_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_5->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_nicks[4] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm_nicks[4] += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm_nicks[4] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_5->setText(cpu_trainers[buf8].pkm_nicks[4]);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_6_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_6->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm_nicks[5] = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm_nicks[5] += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm_nicks[5] += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_6->setText(cpu_trainers[buf8].pkm_nicks[5]);
        not_in_init = true;
    }
}


// Trainer Name
void MainWindow::on_lineEdit_CPU_TrainerName_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_CPU_TrainerName->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].name = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) cpu_trainers[buf8].name += buf_text.at(k);
            else cpu_trainers[buf8].name += "?";
        }
        not_in_init = false;
        ui->lineEdit_CPU_TrainerName->setText(cpu_trainers[buf8].name);
        ui->comboBox_CPU_Trainer->setItemText(buf8,cpu_trainers[buf8].name);
        not_in_init = true;
    }
}


// AI ID
void MainWindow::on_spinBox_CPU_AI_valueChanged(int){
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].ai_id = ui->spinBox_CPU_AI->value();
    }
}


// Party Size
void MainWindow::on_spinBox_CPU_PartySize_valueChanged(int){
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].party_size = ui->spinBox_CPU_PartySize->value();
    }
}


// EVs
void MainWindow::on_spinBox_EV_HP_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_hp[buf8][0] = ui->spinBox_EV_HP_1->value();
    }
}
void MainWindow::on_spinBox_EV_HP_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_hp[buf8][1] = ui->spinBox_EV_HP_2->value();
    }
}
void MainWindow::on_spinBox_EV_HP_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_hp[buf8][2] = ui->spinBox_EV_HP_3->value();
    }
}
void MainWindow::on_spinBox_EV_HP_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_hp[buf8][3] = ui->spinBox_EV_HP_4->value();
    }
}
void MainWindow::on_spinBox_EV_HP_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_hp[buf8][4] = ui->spinBox_EV_HP_5->value();
    }
}
void MainWindow::on_spinBox_EV_HP_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_hp[buf8][5] = ui->spinBox_EV_HP_6->value();
    }
}

void MainWindow::on_spinBox_EV_Attack_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_atk[buf8][0] = ui->spinBox_EV_Attack_1->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_atk[buf8][1] = ui->spinBox_EV_Attack_2->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_atk[buf8][2] = ui->spinBox_EV_Attack_3->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_atk[buf8][3] = ui->spinBox_EV_Attack_4->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_atk[buf8][4] = ui->spinBox_EV_Attack_5->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_atk[buf8][5] = ui->spinBox_EV_Attack_6->value();
    }
}

void MainWindow::on_spinBox_EV_Defense_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_def[buf8][0] = ui->spinBox_EV_Defense_1->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_def[buf8][1] = ui->spinBox_EV_Defense_2->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_def[buf8][2] = ui->spinBox_EV_Defense_3->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_def[buf8][3] = ui->spinBox_EV_Defense_4->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_def[buf8][4] = ui->spinBox_EV_Defense_5->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_def[buf8][5] = ui->spinBox_EV_Defense_6->value();
    }
}

void MainWindow::on_spinBox_EV_Special_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_spc[buf8][0] = ui->spinBox_EV_Special_1->value();
    }
}
void MainWindow::on_spinBox_EV_Special_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_spc[buf8][1] = ui->spinBox_EV_Special_2->value();
    }
}
void MainWindow::on_spinBox_EV_Special_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_spc[buf8][2] = ui->spinBox_EV_Special_3->value();
    }
}
void MainWindow::on_spinBox_EV_Special_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_spc[buf8][3] = ui->spinBox_EV_Special_4->value();
    }
}
void MainWindow::on_spinBox_EV_Special_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_spc[buf8][4] = ui->spinBox_EV_Special_5->value();
    }
}
void MainWindow::on_spinBox_EV_Special_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_spc[buf8][5] = ui->spinBox_EV_Special_6->value();
    }
}

void MainWindow::on_spinBox_EV_Speed_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_speed[buf8][0] = ui->spinBox_EV_Speed_1->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_speed[buf8][1] = ui->spinBox_EV_Speed_2->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_speed[buf8][2] = ui->spinBox_EV_Speed_3->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_speed[buf8][3] = ui->spinBox_EV_Speed_4->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_speed[buf8][4] = ui->spinBox_EV_Speed_5->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_ev_speed[buf8][5] = ui->spinBox_EV_Speed_6->value();
    }
}


// IVs
void MainWindow::on_spinBox_IV_Attack_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_atk[buf8][0] = ui->spinBox_IV_Attack_1->value();
        cpu_pkm_iv_hp[buf8][0] = (cpu_pkm_iv_atk[buf8][0] & 1)*8 + (cpu_pkm_iv_def[buf8][0] & 1)*4 + (cpu_pkm_iv_speed[buf8][0] & 1)*2 + (cpu_pkm_iv_spc[buf8][0] & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_pkm_iv_hp[buf8][0]);
    }
}
void MainWindow::on_spinBox_IV_Attack_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_atk[buf8][1] = ui->spinBox_IV_Attack_2->value();
        cpu_pkm_iv_hp[buf8][1] = (cpu_pkm_iv_atk[buf8][1] & 1)*8 + (cpu_pkm_iv_def[buf8][1] & 1)*4 + (cpu_pkm_iv_speed[buf8][1] & 1)*2 + (cpu_pkm_iv_spc[buf8][1] & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_pkm_iv_hp[buf8][1]);
    }
}
void MainWindow::on_spinBox_IV_Attack_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_atk[buf8][2] = ui->spinBox_IV_Attack_3->value();
        cpu_pkm_iv_hp[buf8][2] = (cpu_pkm_iv_atk[buf8][2] & 1)*8 + (cpu_pkm_iv_def[buf8][2] & 1)*4 + (cpu_pkm_iv_speed[buf8][2] & 1)*2 + (cpu_pkm_iv_spc[buf8][2] & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_pkm_iv_hp[buf8][2]);
    }
}
void MainWindow::on_spinBox_IV_Attack_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_atk[buf8][3] = ui->spinBox_IV_Attack_4->value();
        cpu_pkm_iv_hp[buf8][3] = (cpu_pkm_iv_atk[buf8][3] & 1)*8 + (cpu_pkm_iv_def[buf8][3] & 1)*4 + (cpu_pkm_iv_speed[buf8][3] & 1)*2 + (cpu_pkm_iv_spc[buf8][3] & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_pkm_iv_hp[buf8][3]);
    }
}
void MainWindow::on_spinBox_IV_Attack_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_atk[buf8][4] = ui->spinBox_IV_Attack_5->value();
        cpu_pkm_iv_hp[buf8][4] = (cpu_pkm_iv_atk[buf8][4] & 1)*8 + (cpu_pkm_iv_def[buf8][4] & 1)*4 + (cpu_pkm_iv_speed[buf8][4] & 1)*2 + (cpu_pkm_iv_spc[buf8][4] & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_pkm_iv_hp[buf8][4]);
    }
}
void MainWindow::on_spinBox_IV_Attack_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_atk[buf8][5] = ui->spinBox_IV_Attack_6->value();
        cpu_pkm_iv_hp[buf8][5] = (cpu_pkm_iv_atk[buf8][5] & 1)*8 + (cpu_pkm_iv_def[buf8][5] & 1)*4 + (cpu_pkm_iv_speed[buf8][5] & 1)*2 + (cpu_pkm_iv_spc[buf8][5] & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_pkm_iv_hp[buf8][5]);
    }
}

void MainWindow::on_spinBox_IV_Defense_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_def[buf8][0] = ui->spinBox_IV_Defense_1->value();
        cpu_pkm_iv_hp[buf8][0] = (cpu_pkm_iv_atk[buf8][0] & 1)*8 + (cpu_pkm_iv_def[buf8][0] & 1)*4 + (cpu_pkm_iv_speed[buf8][0] & 1)*2 + (cpu_pkm_iv_spc[buf8][0] & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_pkm_iv_hp[buf8][0]);
    }
}
void MainWindow::on_spinBox_IV_Defense_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_def[buf8][1] = ui->spinBox_IV_Defense_2->value();
        cpu_pkm_iv_hp[buf8][1] = (cpu_pkm_iv_atk[buf8][1] & 1)*8 + (cpu_pkm_iv_def[buf8][1] & 1)*4 + (cpu_pkm_iv_speed[buf8][1] & 1)*2 + (cpu_pkm_iv_spc[buf8][1] & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_pkm_iv_hp[buf8][1]);
    }
}
void MainWindow::on_spinBox_IV_Defense_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_def[buf8][2] = ui->spinBox_IV_Defense_3->value();
        cpu_pkm_iv_hp[buf8][2] = (cpu_pkm_iv_atk[buf8][2] & 1)*8 + (cpu_pkm_iv_def[buf8][2] & 1)*4 + (cpu_pkm_iv_speed[buf8][2] & 1)*2 + (cpu_pkm_iv_spc[buf8][2] & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_pkm_iv_hp[buf8][2]);
    }
}
void MainWindow::on_spinBox_IV_Defense_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_def[buf8][3] = ui->spinBox_IV_Defense_4->value();
        cpu_pkm_iv_hp[buf8][3] = (cpu_pkm_iv_atk[buf8][3] & 1)*8 + (cpu_pkm_iv_def[buf8][3] & 1)*4 + (cpu_pkm_iv_speed[buf8][3] & 1)*2 + (cpu_pkm_iv_spc[buf8][3] & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_pkm_iv_hp[buf8][3]);
    }
}
void MainWindow::on_spinBox_IV_Defense_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_def[buf8][4] = ui->spinBox_IV_Defense_5->value();
        cpu_pkm_iv_hp[buf8][4] = (cpu_pkm_iv_atk[buf8][4] & 1)*8 + (cpu_pkm_iv_def[buf8][4] & 1)*4 + (cpu_pkm_iv_speed[buf8][4] & 1)*2 + (cpu_pkm_iv_spc[buf8][4] & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_pkm_iv_hp[buf8][4]);
    }
}
void MainWindow::on_spinBox_IV_Defense_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_def[buf8][5] = ui->spinBox_IV_Defense_6->value();
        cpu_pkm_iv_hp[buf8][5] = (cpu_pkm_iv_atk[buf8][5] & 1)*8 + (cpu_pkm_iv_def[buf8][5] & 1)*4 + (cpu_pkm_iv_speed[buf8][5] & 1)*2 + (cpu_pkm_iv_spc[buf8][5] & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_pkm_iv_hp[buf8][5]);
    }
}

void MainWindow::on_spinBox_IV_Special_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_spc[buf8][0] = ui->spinBox_IV_Special_1->value();
        cpu_pkm_iv_hp[buf8][0] = (cpu_pkm_iv_atk[buf8][0] & 1)*8 + (cpu_pkm_iv_def[buf8][0] & 1)*4 + (cpu_pkm_iv_speed[buf8][0] & 1)*2 + (cpu_pkm_iv_spc[buf8][0] & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_pkm_iv_hp[buf8][0]);
    }
}
void MainWindow::on_spinBox_IV_Special_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_spc[buf8][1] = ui->spinBox_IV_Special_2->value();
        cpu_pkm_iv_hp[buf8][1] = (cpu_pkm_iv_atk[buf8][1] & 1)*8 + (cpu_pkm_iv_def[buf8][1] & 1)*4 + (cpu_pkm_iv_speed[buf8][1] & 1)*2 + (cpu_pkm_iv_spc[buf8][1] & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_pkm_iv_hp[buf8][1]);
    }
}
void MainWindow::on_spinBox_IV_Special_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_spc[buf8][2] = ui->spinBox_IV_Special_3->value();
        cpu_pkm_iv_hp[buf8][2] = (cpu_pkm_iv_atk[buf8][2] & 1)*8 + (cpu_pkm_iv_def[buf8][2] & 1)*4 + (cpu_pkm_iv_speed[buf8][2] & 1)*2 + (cpu_pkm_iv_spc[buf8][2] & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_pkm_iv_hp[buf8][2]);
    }
}
void MainWindow::on_spinBox_IV_Special_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_spc[buf8][3] = ui->spinBox_IV_Special_4->value();
        cpu_pkm_iv_hp[buf8][3] = (cpu_pkm_iv_atk[buf8][3] & 1)*8 + (cpu_pkm_iv_def[buf8][3] & 1)*4 + (cpu_pkm_iv_speed[buf8][3] & 1)*2 + (cpu_pkm_iv_spc[buf8][3] & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_pkm_iv_hp[buf8][3]);
    }
}
void MainWindow::on_spinBox_IV_Special_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_spc[buf8][4] = ui->spinBox_IV_Special_5->value();
        cpu_pkm_iv_hp[buf8][4] = (cpu_pkm_iv_atk[buf8][4] & 1)*8 + (cpu_pkm_iv_def[buf8][4] & 1)*4 + (cpu_pkm_iv_speed[buf8][4] & 1)*2 + (cpu_pkm_iv_spc[buf8][4] & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_pkm_iv_hp[buf8][4]);
    }
}
void MainWindow::on_spinBox_IV_Special_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_spc[buf8][5] = ui->spinBox_IV_Special_6->value();
        cpu_pkm_iv_hp[buf8][5] = (cpu_pkm_iv_atk[buf8][5] & 1)*8 + (cpu_pkm_iv_def[buf8][5] & 1)*4 + (cpu_pkm_iv_speed[buf8][5] & 1)*2 + (cpu_pkm_iv_spc[buf8][5] & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_pkm_iv_hp[buf8][5]);
    }
}

void MainWindow::on_spinBox_IV_Speed_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_speed[buf8][0] = ui->spinBox_IV_Speed_1->value();
        cpu_pkm_iv_hp[buf8][0] = (cpu_pkm_iv_atk[buf8][0] & 1)*8 + (cpu_pkm_iv_def[buf8][0] & 1)*4 + (cpu_pkm_iv_speed[buf8][0] & 1)*2 + (cpu_pkm_iv_spc[buf8][0] & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_pkm_iv_hp[buf8][0]);
    }
}
void MainWindow::on_spinBox_IV_Speed_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_speed[buf8][1] = ui->spinBox_IV_Speed_2->value();
        cpu_pkm_iv_hp[buf8][1] = (cpu_pkm_iv_atk[buf8][1] & 1)*8 + (cpu_pkm_iv_def[buf8][1] & 1)*4 + (cpu_pkm_iv_speed[buf8][1] & 1)*2 + (cpu_pkm_iv_spc[buf8][1] & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_pkm_iv_hp[buf8][1]);
    }
}
void MainWindow::on_spinBox_IV_Speed_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_speed[buf8][2] = ui->spinBox_IV_Speed_3->value();
        cpu_pkm_iv_hp[buf8][2] = (cpu_pkm_iv_atk[buf8][2] & 1)*8 + (cpu_pkm_iv_def[buf8][2] & 1)*4 + (cpu_pkm_iv_speed[buf8][2] & 1)*2 + (cpu_pkm_iv_spc[buf8][2] & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_pkm_iv_hp[buf8][2]);
    }
}
void MainWindow::on_spinBox_IV_Speed_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_speed[buf8][3] = ui->spinBox_IV_Speed_4->value();
        cpu_pkm_iv_hp[buf8][3] = (cpu_pkm_iv_atk[buf8][3] & 1)*8 + (cpu_pkm_iv_def[buf8][3] & 1)*4 + (cpu_pkm_iv_speed[buf8][3] & 1)*2 + (cpu_pkm_iv_spc[buf8][3] & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_pkm_iv_hp[buf8][3]);
    }
}
void MainWindow::on_spinBox_IV_Speed_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_speed[buf8][4] = ui->spinBox_IV_Speed_5->value();
        cpu_pkm_iv_hp[buf8][4] = (cpu_pkm_iv_atk[buf8][4] & 1)*8 + (cpu_pkm_iv_def[buf8][4] & 1)*4 + (cpu_pkm_iv_speed[buf8][4] & 1)*2 + (cpu_pkm_iv_spc[buf8][4] & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_pkm_iv_hp[buf8][4]);
    }
}
void MainWindow::on_spinBox_IV_Speed_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_iv_speed[buf8][5] = ui->spinBox_IV_Speed_6->value();
        cpu_pkm_iv_hp[buf8][5] = (cpu_pkm_iv_atk[buf8][5] & 1)*8 + (cpu_pkm_iv_def[buf8][5] & 1)*4 + (cpu_pkm_iv_speed[buf8][5] & 1)*2 + (cpu_pkm_iv_spc[buf8][5] & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_pkm_iv_hp[buf8][5]);
    }
}

// Pokémon Levels
void MainWindow::lv_spinbox_changed(int levelBox) {
    if (not_in_init) {
        quint8 trainer_id = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[trainer_id].pkm_lvls[levelBox] = lvl_spinboxes[levelBox]->value();

        quint8 level = cpu_trainers[trainer_id].pkm_lvls[levelBox];
        level = std::min(level, static_cast<quint8>(100));
        level = std::max(level, static_cast<quint8>(2));
        cpu_trainers[trainer_id].pkm_lvls[levelBox] = level;
        lvl_spinboxes[levelBox]->setValue(level);

        quint8 pkm_id = cpu_trainers[trainer_id].pkm_ids[levelBox];
        pkm_growth_rate[pkm_id] = std::max(pkm_growth_rate[pkm_id],
                                           static_cast<quint8>(5));

        cpu_pkm_experience[trainer_id][levelBox] =
                calc_experience(pkm_growth_rate[pkm_id], level);
    }
}

// PP Ups
void MainWindow::on_spinBox_PPUp1_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_1[buf8][0] = 0;

        if(cpu_pkm_move_1[buf8][0]==0) ui->spinBox_PPUp1_1->setValue(0);
        cpu_pkm_ppup_1[buf8][0] = ui->spinBox_PPUp1_1->value();

        if(cpu_pkm_ppup_1[buf8][0]>3){
            cpu_pkm_ppup_1[buf8][0]=3;
            ui->spinBox_PPUp1_1->setValue(3);
        }
        if(cpu_pkm_ppup_1[buf8][0]>0){
            cpu_pkm_pp_1[buf8][0] = move_pp[cpu_pkm_move_1[buf8][0]] / 5;
            cpu_pkm_pp_1[buf8][0] *= cpu_pkm_ppup_1[buf8][0];
            cpu_pkm_pp_1[buf8][0] |= cpu_pkm_ppup_1[buf8][0]<<6;
        }
        cpu_pkm_pp_1[buf8][0] += move_pp[cpu_pkm_move_1[buf8][0]];
    }
}
void MainWindow::on_spinBox_PPUp2_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_2[buf8][0] = 0;

        if(cpu_pkm_move_2[buf8][0]==0) ui->spinBox_PPUp2_1->setValue(0);
        cpu_pkm_ppup_2[buf8][0] = ui->spinBox_PPUp2_1->value();

        if(cpu_pkm_ppup_2[buf8][0]>3){
            cpu_pkm_ppup_2[buf8][0]=3;
            ui->spinBox_PPUp2_1->setValue(3);
        }
        if(cpu_pkm_ppup_2[buf8][0]>0){
            cpu_pkm_pp_2[buf8][0] = move_pp[cpu_pkm_move_2[buf8][0]] / 5;
            cpu_pkm_pp_2[buf8][0] *= cpu_pkm_ppup_2[buf8][0];
            cpu_pkm_pp_2[buf8][0] |= cpu_pkm_ppup_2[buf8][0]<<6;
        }
        cpu_pkm_pp_2[buf8][0] += move_pp[cpu_pkm_move_2[buf8][0]];
    }
}
void MainWindow::on_spinBox_PPUp3_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_3[buf8][0] = 0;

        if(cpu_pkm_move_3[buf8][0]==0) ui->spinBox_PPUp3_1->setValue(0);
        cpu_pkm_ppup_3[buf8][0] = ui->spinBox_PPUp3_1->value();

        if(cpu_pkm_ppup_3[buf8][0]>3){
            cpu_pkm_ppup_3[buf8][0]=3;
            ui->spinBox_PPUp3_1->setValue(3);
        }
        if(cpu_pkm_ppup_3[buf8][0]>0){
            cpu_pkm_pp_3[buf8][0] = move_pp[cpu_pkm_move_3[buf8][0]] / 5;
            cpu_pkm_pp_3[buf8][0] *= cpu_pkm_ppup_3[buf8][0];
            cpu_pkm_pp_3[buf8][0] |= cpu_pkm_ppup_3[buf8][0]<<6;
        }
        cpu_pkm_pp_3[buf8][0] += move_pp[cpu_pkm_move_3[buf8][0]];
    }
}
void MainWindow::on_spinBox_PPUp4_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_4[buf8][0] = 0;

        if(cpu_pkm_move_4[buf8][0]==0) ui->spinBox_PPUp4_1->setValue(0);
        cpu_pkm_ppup_4[buf8][0] = ui->spinBox_PPUp4_1->value();

        if(cpu_pkm_ppup_4[buf8][0]>3){
            cpu_pkm_ppup_4[buf8][0]=3;
            ui->spinBox_PPUp4_1->setValue(3);
        }
        if(cpu_pkm_ppup_4[buf8][0]>0){
            cpu_pkm_pp_4[buf8][0] = move_pp[cpu_pkm_move_4[buf8][0]] / 5;
            cpu_pkm_pp_4[buf8][0] *= cpu_pkm_ppup_4[buf8][0];
            cpu_pkm_pp_4[buf8][0] |= cpu_pkm_ppup_4[buf8][0]<<6;
        }
        cpu_pkm_pp_4[buf8][0] += move_pp[cpu_pkm_move_4[buf8][0]];
    }
}

void MainWindow::on_spinBox_PPUp1_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_1[buf8][1] = 0;

        if(cpu_pkm_move_1[buf8][1]==0) ui->spinBox_PPUp1_2->setValue(0);
        cpu_pkm_ppup_1[buf8][1] = ui->spinBox_PPUp1_2->value();

        if(cpu_pkm_ppup_1[buf8][1]>3){
            cpu_pkm_ppup_1[buf8][1]=3;
            ui->spinBox_PPUp1_2->setValue(3);
        }
        if(cpu_pkm_ppup_1[buf8][1]>0){
            cpu_pkm_pp_1[buf8][1] = move_pp[cpu_pkm_move_1[buf8][1]] / 5;
            cpu_pkm_pp_1[buf8][1] *= cpu_pkm_ppup_1[buf8][1];
            cpu_pkm_pp_1[buf8][1] |= cpu_pkm_ppup_1[buf8][1]<<6;
        }
        cpu_pkm_pp_1[buf8][1] += move_pp[cpu_pkm_move_1[buf8][1]];
    }
}
void MainWindow::on_spinBox_PPUp2_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_2[buf8][1] = 0;

        if(cpu_pkm_move_2[buf8][1]==0) ui->spinBox_PPUp2_2->setValue(0);
        cpu_pkm_ppup_2[buf8][1] = ui->spinBox_PPUp2_2->value();

        if(cpu_pkm_ppup_2[buf8][1]>3){
            cpu_pkm_ppup_2[buf8][1]=3;
            ui->spinBox_PPUp2_2->setValue(3);
        }
        if(cpu_pkm_ppup_2[buf8][1]>0){
            cpu_pkm_pp_2[buf8][1] = move_pp[cpu_pkm_move_2[buf8][1]] / 5;
            cpu_pkm_pp_2[buf8][1] *= cpu_pkm_ppup_2[buf8][1];
            cpu_pkm_pp_2[buf8][1] |= cpu_pkm_ppup_2[buf8][1]<<6;
        }
        cpu_pkm_pp_2[buf8][1] += move_pp[cpu_pkm_move_2[buf8][1]];
    }
}
void MainWindow::on_spinBox_PPUp3_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_3[buf8][1] = 0;

        if(cpu_pkm_move_3[buf8][1]==0) ui->spinBox_PPUp3_2->setValue(0);
        cpu_pkm_ppup_3[buf8][1] = ui->spinBox_PPUp3_2->value();

        if(cpu_pkm_ppup_3[buf8][1]>3){
            cpu_pkm_ppup_3[buf8][1]=3;
            ui->spinBox_PPUp3_2->setValue(3);
        }
        if(cpu_pkm_ppup_3[buf8][1]>0){
            cpu_pkm_pp_3[buf8][1] = move_pp[cpu_pkm_move_3[buf8][1]] / 5;
            cpu_pkm_pp_3[buf8][1] *= cpu_pkm_ppup_3[buf8][1];
            cpu_pkm_pp_3[buf8][1] |= cpu_pkm_ppup_3[buf8][1]<<6;
        }
        cpu_pkm_pp_3[buf8][1] += move_pp[cpu_pkm_move_3[buf8][1]];
    }
}
void MainWindow::on_spinBox_PPUp4_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_4[buf8][1] = 0;

        if(cpu_pkm_move_4[buf8][1]==0) ui->spinBox_PPUp4_2->setValue(0);
        cpu_pkm_ppup_4[buf8][1] = ui->spinBox_PPUp4_2->value();

        if(cpu_pkm_ppup_4[buf8][1]>3){
            cpu_pkm_ppup_4[buf8][1]=3;
            ui->spinBox_PPUp4_2->setValue(3);
        }
        if(cpu_pkm_ppup_4[buf8][1]>0){
            cpu_pkm_pp_4[buf8][1] = move_pp[cpu_pkm_move_4[buf8][1]] / 5;
            cpu_pkm_pp_4[buf8][1] *= cpu_pkm_ppup_4[buf8][1];
            cpu_pkm_pp_4[buf8][1] |= cpu_pkm_ppup_4[buf8][1]<<6;
        }
        cpu_pkm_pp_4[buf8][1] += move_pp[cpu_pkm_move_4[buf8][1]];
    }
}

void MainWindow::on_spinBox_PPUp1_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_1[buf8][2] = 0;

        if(cpu_pkm_move_1[buf8][2]==0) ui->spinBox_PPUp1_3->setValue(0);
        cpu_pkm_ppup_1[buf8][2] = ui->spinBox_PPUp1_3->value();

        if(cpu_pkm_ppup_1[buf8][2]>3){
            cpu_pkm_ppup_1[buf8][2]=3;
            ui->spinBox_PPUp1_3->setValue(3);
        }
        if(cpu_pkm_ppup_1[buf8][2]>0){
            cpu_pkm_pp_1[buf8][2] = move_pp[cpu_pkm_move_1[buf8][2]] / 5;
            cpu_pkm_pp_1[buf8][2] *= cpu_pkm_ppup_1[buf8][2];
            cpu_pkm_pp_1[buf8][2] |= cpu_pkm_ppup_1[buf8][2]<<6;
        }
        cpu_pkm_pp_1[buf8][2] += move_pp[cpu_pkm_move_1[buf8][2]];
    }
}
void MainWindow::on_spinBox_PPUp2_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_2[buf8][2] = 0;

        if(cpu_pkm_move_2[buf8][2]==0) ui->spinBox_PPUp2_3->setValue(0);
        cpu_pkm_ppup_2[buf8][2] = ui->spinBox_PPUp2_3->value();

        if(cpu_pkm_ppup_2[buf8][2]>3){
            cpu_pkm_ppup_2[buf8][2]=3;
            ui->spinBox_PPUp2_3->setValue(3);
        }
        if(cpu_pkm_ppup_2[buf8][2]>0){
            cpu_pkm_pp_2[buf8][2] = move_pp[cpu_pkm_move_2[buf8][2]] / 5;
            cpu_pkm_pp_2[buf8][2] *= cpu_pkm_ppup_2[buf8][2];
            cpu_pkm_pp_2[buf8][2] |= cpu_pkm_ppup_2[buf8][2]<<6;
        }
        cpu_pkm_pp_2[buf8][2] += move_pp[cpu_pkm_move_2[buf8][2]];
    }
}
void MainWindow::on_spinBox_PPUp3_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_3[buf8][2] = 0;

        if(cpu_pkm_move_3[buf8][2]==0) ui->spinBox_PPUp3_3->setValue(0);
        cpu_pkm_ppup_3[buf8][2] = ui->spinBox_PPUp3_3->value();

        if(cpu_pkm_ppup_3[buf8][2]>3){
            cpu_pkm_ppup_3[buf8][2]=3;
            ui->spinBox_PPUp3_3->setValue(3);
        }
        if(cpu_pkm_ppup_3[buf8][2]>0){
            cpu_pkm_pp_3[buf8][2] = move_pp[cpu_pkm_move_3[buf8][2]] / 5;
            cpu_pkm_pp_3[buf8][2] *= cpu_pkm_ppup_3[buf8][2];
            cpu_pkm_pp_3[buf8][2] |= cpu_pkm_ppup_3[buf8][2]<<6;
        }
        cpu_pkm_pp_3[buf8][2] += move_pp[cpu_pkm_move_3[buf8][2]];
    }
}
void MainWindow::on_spinBox_PPUp4_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_4[buf8][2] = 0;

        if(cpu_pkm_move_4[buf8][2]==0) ui->spinBox_PPUp4_3->setValue(0);
        cpu_pkm_ppup_4[buf8][2] = ui->spinBox_PPUp4_3->value();

        if(cpu_pkm_ppup_4[buf8][2]>3){
            cpu_pkm_ppup_4[buf8][2]=3;
            ui->spinBox_PPUp4_3->setValue(3);
        }
        if(cpu_pkm_ppup_4[buf8][2]>0){
            cpu_pkm_pp_4[buf8][2] = move_pp[cpu_pkm_move_4[buf8][2]] / 5;
            cpu_pkm_pp_4[buf8][2] *= cpu_pkm_ppup_4[buf8][2];
            cpu_pkm_pp_4[buf8][2] |= cpu_pkm_ppup_4[buf8][2]<<6;
        }
        cpu_pkm_pp_4[buf8][2] += move_pp[cpu_pkm_move_4[buf8][2]];
    }
}

void MainWindow::on_spinBox_PPUp1_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_1[buf8][3] = 0;

        if(cpu_pkm_move_1[buf8][3]==0) ui->spinBox_PPUp1_4->setValue(0);
        cpu_pkm_ppup_1[buf8][3] = ui->spinBox_PPUp1_4->value();

        if(cpu_pkm_ppup_1[buf8][3]>3){
            cpu_pkm_ppup_1[buf8][3]=3;
            ui->spinBox_PPUp1_4->setValue(3);
        }
        if(cpu_pkm_ppup_1[buf8][3]>0){
            cpu_pkm_pp_1[buf8][3] = move_pp[cpu_pkm_move_1[buf8][3]] / 5;
            cpu_pkm_pp_1[buf8][3] *= cpu_pkm_ppup_1[buf8][3];
            cpu_pkm_pp_1[buf8][3] |= cpu_pkm_ppup_1[buf8][3]<<6;
        }
        cpu_pkm_pp_1[buf8][3] += move_pp[cpu_pkm_move_1[buf8][3]];
    }
}
void MainWindow::on_spinBox_PPUp2_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_2[buf8][3] = 0;

        if(cpu_pkm_move_2[buf8][3]==0) ui->spinBox_PPUp2_4->setValue(0);
        cpu_pkm_ppup_2[buf8][3] = ui->spinBox_PPUp2_4->value();

        if(cpu_pkm_ppup_2[buf8][3]>3){
            cpu_pkm_ppup_2[buf8][3]=3;
            ui->spinBox_PPUp2_4->setValue(3);
        }
        if(cpu_pkm_ppup_2[buf8][3]>0){
            cpu_pkm_pp_2[buf8][3] = move_pp[cpu_pkm_move_2[buf8][3]] / 5;
            cpu_pkm_pp_2[buf8][3] *= cpu_pkm_ppup_2[buf8][3];
            cpu_pkm_pp_2[buf8][3] |= cpu_pkm_ppup_2[buf8][3]<<6;
        }
        cpu_pkm_pp_2[buf8][3] += move_pp[cpu_pkm_move_2[buf8][3]];
    }
}
void MainWindow::on_spinBox_PPUp3_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_3[buf8][3] = 0;

        if(cpu_pkm_move_3[buf8][3]==0) ui->spinBox_PPUp3_4->setValue(0);
        cpu_pkm_ppup_3[buf8][3] = ui->spinBox_PPUp3_4->value();

        if(cpu_pkm_ppup_3[buf8][3]>3){
            cpu_pkm_ppup_3[buf8][3]=3;
            ui->spinBox_PPUp3_4->setValue(3);
        }
        if(cpu_pkm_ppup_3[buf8][3]>0){
            cpu_pkm_pp_3[buf8][3] = move_pp[cpu_pkm_move_3[buf8][3]] / 5;
            cpu_pkm_pp_3[buf8][3] *= cpu_pkm_ppup_3[buf8][3];
            cpu_pkm_pp_3[buf8][3] |= cpu_pkm_ppup_3[buf8][3]<<6;
        }
        cpu_pkm_pp_3[buf8][3] += move_pp[cpu_pkm_move_3[buf8][3]];
    }
}
void MainWindow::on_spinBox_PPUp4_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_4[buf8][3] = 0;

        if(cpu_pkm_move_4[buf8][3]==0) ui->spinBox_PPUp4_4->setValue(0);
        cpu_pkm_ppup_4[buf8][3] = ui->spinBox_PPUp4_4->value();

        if(cpu_pkm_ppup_4[buf8][3]>3){
            cpu_pkm_ppup_4[buf8][3]=3;
            ui->spinBox_PPUp4_4->setValue(3);
        }
        if(cpu_pkm_ppup_4[buf8][3]>0){
            cpu_pkm_pp_4[buf8][3] = move_pp[cpu_pkm_move_4[buf8][3]] / 5;
            cpu_pkm_pp_4[buf8][3] *= cpu_pkm_ppup_4[buf8][3];
            cpu_pkm_pp_4[buf8][3] |= cpu_pkm_ppup_4[buf8][3]<<6;
        }
        cpu_pkm_pp_4[buf8][3] += move_pp[cpu_pkm_move_4[buf8][3]];
    }
}

void MainWindow::on_spinBox_PPUp1_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_1[buf8][4] = 0;

        if(cpu_pkm_move_1[buf8][4]==0) ui->spinBox_PPUp1_5->setValue(0);
        cpu_pkm_ppup_1[buf8][4] = ui->spinBox_PPUp1_5->value();

        if(cpu_pkm_ppup_1[buf8][4]>3){
            cpu_pkm_ppup_1[buf8][4]=3;
            ui->spinBox_PPUp1_5->setValue(3);
        }
        if(cpu_pkm_ppup_1[buf8][4]>0){
            cpu_pkm_pp_1[buf8][4] = move_pp[cpu_pkm_move_1[buf8][4]] / 5;
            cpu_pkm_pp_1[buf8][4] *= cpu_pkm_ppup_1[buf8][4];
            cpu_pkm_pp_1[buf8][4] |= cpu_pkm_ppup_1[buf8][4]<<6;
        }
        cpu_pkm_pp_1[buf8][4] += move_pp[cpu_pkm_move_1[buf8][4]];
    }
}
void MainWindow::on_spinBox_PPUp2_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_2[buf8][4] = 0;

        if(cpu_pkm_move_2[buf8][4]==0) ui->spinBox_PPUp2_5->setValue(0);
        cpu_pkm_ppup_2[buf8][4] = ui->spinBox_PPUp2_5->value();

        if(cpu_pkm_ppup_2[buf8][4]>3){
            cpu_pkm_ppup_2[buf8][4]=3;
            ui->spinBox_PPUp2_5->setValue(3);
        }
        if(cpu_pkm_ppup_2[buf8][4]>0){
            cpu_pkm_pp_2[buf8][4] = move_pp[cpu_pkm_move_2[buf8][4]] / 5;
            cpu_pkm_pp_2[buf8][4] *= cpu_pkm_ppup_2[buf8][4];
            cpu_pkm_pp_2[buf8][4] |= cpu_pkm_ppup_2[buf8][4]<<6;
        }
        cpu_pkm_pp_2[buf8][4] += move_pp[cpu_pkm_move_2[buf8][4]];
    }
}
void MainWindow::on_spinBox_PPUp3_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_3[buf8][4] = 0;

        if(cpu_pkm_move_3[buf8][4]==0) ui->spinBox_PPUp3_5->setValue(0);
        cpu_pkm_ppup_3[buf8][4] = ui->spinBox_PPUp3_5->value();

        if(cpu_pkm_ppup_3[buf8][4]>3){
            cpu_pkm_ppup_3[buf8][4]=3;
            ui->spinBox_PPUp3_5->setValue(3);
        }
        if(cpu_pkm_ppup_3[buf8][4]>0){
            cpu_pkm_pp_3[buf8][4] = move_pp[cpu_pkm_move_3[buf8][4]] / 5;
            cpu_pkm_pp_3[buf8][4] *= cpu_pkm_ppup_3[buf8][4];
            cpu_pkm_pp_3[buf8][4] |= cpu_pkm_ppup_3[buf8][4]<<6;
        }
        cpu_pkm_pp_3[buf8][4] += move_pp[cpu_pkm_move_3[buf8][4]];
    }
}
void MainWindow::on_spinBox_PPUp4_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_4[buf8][4] = 0;

        if(cpu_pkm_move_4[buf8][4]==0) ui->spinBox_PPUp4_5->setValue(0);
        cpu_pkm_ppup_4[buf8][4] = ui->spinBox_PPUp4_5->value();

        if(cpu_pkm_ppup_4[buf8][4]>3){
            cpu_pkm_ppup_4[buf8][4]=3;
            ui->spinBox_PPUp4_5->setValue(3);
        }
        if(cpu_pkm_ppup_4[buf8][4]>0){
            cpu_pkm_pp_4[buf8][4] = move_pp[cpu_pkm_move_4[buf8][4]] / 5;
            cpu_pkm_pp_4[buf8][4] *= cpu_pkm_ppup_4[buf8][4];
            cpu_pkm_pp_4[buf8][4] |= cpu_pkm_ppup_4[buf8][4]<<6;
        }
        cpu_pkm_pp_4[buf8][4] += move_pp[cpu_pkm_move_4[buf8][4]];
    }
}

void MainWindow::on_spinBox_PPUp1_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_1[buf8][5] = 0;

        if(cpu_pkm_move_1[buf8][5]==0) ui->spinBox_PPUp1_6->setValue(0);
        cpu_pkm_ppup_1[buf8][5] = ui->spinBox_PPUp1_6->value();

        if(cpu_pkm_ppup_1[buf8][5]>3){
            cpu_pkm_ppup_1[buf8][5]=3;
            ui->spinBox_PPUp1_6->setValue(3);
        }
        if(cpu_pkm_ppup_1[buf8][5]>0){
            cpu_pkm_pp_1[buf8][5] = move_pp[cpu_pkm_move_1[buf8][5]] / 5;
            cpu_pkm_pp_1[buf8][5] *= cpu_pkm_ppup_1[buf8][5];
            cpu_pkm_pp_1[buf8][5] |= cpu_pkm_ppup_1[buf8][5]<<6;
        }
        cpu_pkm_pp_1[buf8][5] += move_pp[cpu_pkm_move_1[buf8][5]];
    }
}
void MainWindow::on_spinBox_PPUp2_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_2[buf8][5] = 0;

        if(cpu_pkm_move_2[buf8][5]==0) ui->spinBox_PPUp2_6->setValue(0);
        cpu_pkm_ppup_2[buf8][5] = ui->spinBox_PPUp2_6->value();

        if(cpu_pkm_ppup_2[buf8][5]>3){
            cpu_pkm_ppup_2[buf8][5]=3;
            ui->spinBox_PPUp2_6->setValue(3);
        }
        if(cpu_pkm_ppup_2[buf8][5]>0){
            cpu_pkm_pp_2[buf8][5] = move_pp[cpu_pkm_move_2[buf8][5]] / 5;
            cpu_pkm_pp_2[buf8][5] *= cpu_pkm_ppup_2[buf8][5];
            cpu_pkm_pp_2[buf8][5] |= cpu_pkm_ppup_2[buf8][5]<<6;
        }
        cpu_pkm_pp_2[buf8][5] += move_pp[cpu_pkm_move_2[buf8][5]];
    }
}
void MainWindow::on_spinBox_PPUp3_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_3[buf8][5] = 0;

        if(cpu_pkm_move_3[buf8][5]==0) ui->spinBox_PPUp3_6->setValue(0);
        cpu_pkm_ppup_3[buf8][5] = ui->spinBox_PPUp3_6->value();

        if(cpu_pkm_ppup_3[buf8][5]>3){
            cpu_pkm_ppup_3[buf8][5]=3;
            ui->spinBox_PPUp3_6->setValue(3);
        }
        if(cpu_pkm_ppup_3[buf8][5]>0){
            cpu_pkm_pp_3[buf8][5] = move_pp[cpu_pkm_move_3[buf8][5]] / 5;
            cpu_pkm_pp_3[buf8][5] *= cpu_pkm_ppup_3[buf8][5];
            cpu_pkm_pp_3[buf8][5] |= cpu_pkm_ppup_3[buf8][5]<<6;
        }
        cpu_pkm_pp_3[buf8][5] += move_pp[cpu_pkm_move_3[buf8][5]];
    }
}
void MainWindow::on_spinBox_PPUp4_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_pkm_pp_4[buf8][5] = 0;

        if(cpu_pkm_move_4[buf8][5]==0) ui->spinBox_PPUp4_6->setValue(0);
        cpu_pkm_ppup_4[buf8][5] = ui->spinBox_PPUp4_6->value();

        if(cpu_pkm_ppup_4[buf8][5]>3){
            cpu_pkm_ppup_4[buf8][5]=3;
            ui->spinBox_PPUp4_6->setValue(3);
        }
        if(cpu_pkm_ppup_4[buf8][5]>0){
            cpu_pkm_pp_4[buf8][5] = move_pp[cpu_pkm_move_4[buf8][5]] / 5;
            cpu_pkm_pp_4[buf8][5] *= cpu_pkm_ppup_4[buf8][5];
            cpu_pkm_pp_4[buf8][5] |= cpu_pkm_ppup_4[buf8][5]<<6;
        }
        cpu_pkm_pp_4[buf8][5] += move_pp[cpu_pkm_move_4[buf8][5]];
    }
}


// Trainer sprite
void MainWindow::on_spinBox_TrainerSpriteID_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].sprite_id = ui->spinBox_TrainerSpriteID->value();
        if(cpu_trainers[buf8].sprite_id>53){
            cpu_trainers[buf8].sprite_id=0;
            ui->spinBox_TrainerSpriteID->setValue(0);
        }
        display_cpu_trainer_sprite(cpu_trainers[buf8].sprite_id);
    }
}
