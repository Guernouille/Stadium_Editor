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
        cpu_trainers[buf8].pkm[pkm_num].move_1 = move1_comboboxes[pkm_num]->currentIndex();

        cpu_trainers[buf8].pkm[pkm_num].pp_1 = 0;
        if(cpu_trainers[buf8].pkm[pkm_num].ppup_1>0 && cpu_trainers[buf8].pkm[pkm_num].move_1>0){
            cpu_trainers[buf8].pkm[pkm_num].pp_1 = move_pp[cpu_trainers[buf8].pkm[pkm_num].move_1] / 5;
            cpu_trainers[buf8].pkm[pkm_num].pp_1 *= cpu_trainers[buf8].pkm[pkm_num].ppup_1;
            cpu_trainers[buf8].pkm[pkm_num].pp_1 |= cpu_trainers[buf8].pkm[pkm_num].ppup_1<<6;
        }
        else {
            ppup1_boxes[pkm_num]->setValue(0);
            cpu_trainers[buf8].pkm[pkm_num].ppup_1 = 0;
        }
        cpu_trainers[buf8].pkm[pkm_num].pp_1 += move_pp[cpu_trainers[buf8].pkm[pkm_num].move_1];
    }
}

void MainWindow::move2_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup2_boxes {
        ui->spinBox_PPUp2_1, ui->spinBox_PPUp2_2, ui->spinBox_PPUp2_3,
        ui->spinBox_PPUp2_4, ui->spinBox_PPUp2_5, ui->spinBox_PPUp2_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[pkm_num].move_2 = move2_comboboxes[pkm_num]->currentIndex();

        cpu_trainers[buf8].pkm[pkm_num].pp_2 = 0;
        if(cpu_trainers[buf8].pkm[pkm_num].ppup_2>0 && cpu_trainers[buf8].pkm[pkm_num].move_2>0){
            cpu_trainers[buf8].pkm[pkm_num].pp_2 = move_pp[cpu_trainers[buf8].pkm[pkm_num].move_2] / 5;
            cpu_trainers[buf8].pkm[pkm_num].pp_2 *= cpu_trainers[buf8].pkm[pkm_num].ppup_2;
            cpu_trainers[buf8].pkm[pkm_num].pp_2 |= cpu_trainers[buf8].pkm[pkm_num].ppup_2<<6;
        }
        else {
            ppup2_boxes[pkm_num]->setValue(0);
            cpu_trainers[buf8].pkm[pkm_num].ppup_2 = 0;
        }
        cpu_trainers[buf8].pkm[pkm_num].pp_2 += move_pp[cpu_trainers[buf8].pkm[pkm_num].move_2];
    }
}

void MainWindow::move3_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup3_boxes {
        ui->spinBox_PPUp3_1, ui->spinBox_PPUp3_2, ui->spinBox_PPUp3_3,
        ui->spinBox_PPUp3_4, ui->spinBox_PPUp3_5, ui->spinBox_PPUp3_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[pkm_num].move_3 = move3_comboboxes[pkm_num]->currentIndex();

        cpu_trainers[buf8].pkm[pkm_num].pp_3 = 0;
        if(cpu_trainers[buf8].pkm[pkm_num].ppup_3>0 && cpu_trainers[buf8].pkm[pkm_num].move_3>0){
            cpu_trainers[buf8].pkm[pkm_num].pp_3 = move_pp[cpu_trainers[buf8].pkm[pkm_num].move_3] / 5;
            cpu_trainers[buf8].pkm[pkm_num].pp_3 *= cpu_trainers[buf8].pkm[pkm_num].ppup_3;
            cpu_trainers[buf8].pkm[pkm_num].pp_3 |= cpu_trainers[buf8].pkm[pkm_num].ppup_3<<6;
        }
        else {
            ppup3_boxes[pkm_num]->setValue(0);
            cpu_trainers[buf8].pkm[pkm_num].ppup_3 = 0;
        }
        cpu_trainers[buf8].pkm[pkm_num].pp_3 += move_pp[cpu_trainers[buf8].pkm[pkm_num].move_3];
    }
}

void MainWindow::move4_combobox_changed(int pkm_num) {
    std::vector<QSpinBox*> ppup4_boxes {
        ui->spinBox_PPUp4_1, ui->spinBox_PPUp4_2, ui->spinBox_PPUp4_3,
        ui->spinBox_PPUp4_4, ui->spinBox_PPUp4_5, ui->spinBox_PPUp4_6
    };

    if (not_in_init) {
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[pkm_num].move_4 = move4_comboboxes[pkm_num]->currentIndex();

        cpu_trainers[buf8].pkm[pkm_num].pp_4 = 0;
        if(cpu_trainers[buf8].pkm[pkm_num].ppup_4>0 && cpu_trainers[buf8].pkm[pkm_num].move_4>0){
            cpu_trainers[buf8].pkm[pkm_num].pp_4 = move_pp[cpu_trainers[buf8].pkm[pkm_num].move_4] / 5;
            cpu_trainers[buf8].pkm[pkm_num].pp_4 *= cpu_trainers[buf8].pkm[pkm_num].ppup_4;
            cpu_trainers[buf8].pkm[pkm_num].pp_4 |= cpu_trainers[buf8].pkm[pkm_num].ppup_4<<6;
        }
        else {
            ppup4_boxes[pkm_num]->setValue(0);
            cpu_trainers[buf8].pkm[pkm_num].ppup_4 = 0;
        }
        cpu_trainers[buf8].pkm[pkm_num].pp_4 += move_pp[cpu_trainers[buf8].pkm[pkm_num].move_4];
    }
}

// Pokémon IDs
void MainWindow::on_comboBox_Pkmn_1_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].id = ui->comboBox_Pkmn_1->currentIndex();
        cpu_trainers[buf8].pkm[0].exp = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm[0].id],cpu_trainers[buf8].pkm[0].lvl);
    }
}
void MainWindow::on_comboBox_Pkmn_2_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].id = ui->comboBox_Pkmn_2->currentIndex();
        cpu_trainers[buf8].pkm[1].exp = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm[1].id],cpu_trainers[buf8].pkm[1].lvl);
    }
}
void MainWindow::on_comboBox_Pkmn_3_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].id = ui->comboBox_Pkmn_3->currentIndex();
        cpu_trainers[buf8].pkm[2].exp = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm[2].id],cpu_trainers[buf8].pkm[2].lvl);
    }
}
void MainWindow::on_comboBox_Pkmn_4_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].id = ui->comboBox_Pkmn_4->currentIndex();
        cpu_trainers[buf8].pkm[3].exp = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm[3].id],cpu_trainers[buf8].pkm[3].lvl);
    }
}
void MainWindow::on_comboBox_Pkmn_5_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].id = ui->comboBox_Pkmn_5->currentIndex();
        cpu_trainers[buf8].pkm[4].exp = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm[4].id],cpu_trainers[buf8].pkm[4].lvl);
    }
}
void MainWindow::on_comboBox_Pkmn_6_currentIndexChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].id = ui->comboBox_Pkmn_6->currentIndex();
        cpu_trainers[buf8].pkm[5].exp = calc_experience(pkm_growth_rate[cpu_trainers[buf8].pkm[5].id],cpu_trainers[buf8].pkm[5].lvl);
    }
}


// Nicknames
void MainWindow::on_lineEdit_Nickname_1_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_1->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].nick = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm[0].nick += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm[0].nick += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_1->setText(cpu_trainers[buf8].pkm[0].nick);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_2_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_2->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].nick = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm[1].nick += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm[1].nick += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_2->setText(cpu_trainers[buf8].pkm[1].nick);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_3_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_3->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].nick = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm[2].nick += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm[2].nick += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_3->setText(cpu_trainers[buf8].pkm[2].nick);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_4_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_4->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].nick = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm[3].nick += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm[3].nick += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_4->setText(cpu_trainers[buf8].pkm[3].nick);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_5_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_5->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].nick = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm[4].nick += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm[4].nick += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_5->setText(cpu_trainers[buf8].pkm[4].nick);
        not_in_init = true;
    }
}
void MainWindow::on_lineEdit_Nickname_6_textEdited(){
    if(not_in_init){
        buf_text = ui->lineEdit_Nickname_6->text();
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].nick = "";

        for(short k=0;k<buf_text.length();k++){
            if(control_char_table(buf_text.at(k)) < 253) {
                cpu_trainers[buf8].pkm[5].nick += buf_text.at(k);
            }
            else {
                cpu_trainers[buf8].pkm[5].nick += "?";
            }
        }
        not_in_init = false;
        ui->lineEdit_Nickname_6->setText(cpu_trainers[buf8].pkm[5].nick);
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
        cpu_trainers[buf8].pkm[0].hp_ev = ui->spinBox_EV_HP_1->value();
    }
}
void MainWindow::on_spinBox_EV_HP_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].hp_ev = ui->spinBox_EV_HP_2->value();
    }
}
void MainWindow::on_spinBox_EV_HP_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].hp_ev = ui->spinBox_EV_HP_3->value();
    }
}
void MainWindow::on_spinBox_EV_HP_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].hp_ev = ui->spinBox_EV_HP_4->value();
    }
}
void MainWindow::on_spinBox_EV_HP_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].hp_ev = ui->spinBox_EV_HP_5->value();
    }
}
void MainWindow::on_spinBox_EV_HP_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].hp_ev = ui->spinBox_EV_HP_6->value();
    }
}

void MainWindow::on_spinBox_EV_Attack_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].atk_ev = ui->spinBox_EV_Attack_1->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].atk_ev = ui->spinBox_EV_Attack_2->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].atk_ev = ui->spinBox_EV_Attack_3->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].atk_ev = ui->spinBox_EV_Attack_4->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].atk_ev = ui->spinBox_EV_Attack_5->value();
    }
}
void MainWindow::on_spinBox_EV_Attack_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].atk_ev = ui->spinBox_EV_Attack_6->value();
    }
}

void MainWindow::on_spinBox_EV_Defense_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].def_ev = ui->spinBox_EV_Defense_1->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].def_ev = ui->spinBox_EV_Defense_2->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].def_ev = ui->spinBox_EV_Defense_3->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].def_ev = ui->spinBox_EV_Defense_4->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].def_ev = ui->spinBox_EV_Defense_5->value();
    }
}
void MainWindow::on_spinBox_EV_Defense_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].def_ev = ui->spinBox_EV_Defense_6->value();
    }
}

void MainWindow::on_spinBox_EV_Special_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].spc_ev = ui->spinBox_EV_Special_1->value();
    }
}
void MainWindow::on_spinBox_EV_Special_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].spc_ev = ui->spinBox_EV_Special_2->value();
    }
}
void MainWindow::on_spinBox_EV_Special_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].spc_ev = ui->spinBox_EV_Special_3->value();
    }
}
void MainWindow::on_spinBox_EV_Special_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].spc_ev = ui->spinBox_EV_Special_4->value();
    }
}
void MainWindow::on_spinBox_EV_Special_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].spc_ev = ui->spinBox_EV_Special_5->value();
    }
}
void MainWindow::on_spinBox_EV_Special_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].spc_ev = ui->spinBox_EV_Special_6->value();
    }
}

void MainWindow::on_spinBox_EV_Speed_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].speed_ev = ui->spinBox_EV_Speed_1->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].speed_ev = ui->spinBox_EV_Speed_2->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].speed_ev = ui->spinBox_EV_Speed_3->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].speed_ev = ui->spinBox_EV_Speed_4->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].speed_ev = ui->spinBox_EV_Speed_5->value();
    }
}
void MainWindow::on_spinBox_EV_Speed_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].speed_ev = ui->spinBox_EV_Speed_6->value();
    }
}


// IVs
void MainWindow::on_spinBox_IV_Attack_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].atk_iv = ui->spinBox_IV_Attack_1->value();
        cpu_trainers[buf8].pkm[0].hp_iv = (cpu_trainers[buf8].pkm[0].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[0].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[0].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[0].spc_iv & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_trainers[buf8].pkm[0].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Attack_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].atk_iv = ui->spinBox_IV_Attack_2->value();
        cpu_trainers[buf8].pkm[1].hp_iv = (cpu_trainers[buf8].pkm[1].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[1].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[1].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[1].spc_iv & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_trainers[buf8].pkm[1].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Attack_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].atk_iv = ui->spinBox_IV_Attack_3->value();
        cpu_trainers[buf8].pkm[2].hp_iv = (cpu_trainers[buf8].pkm[2].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[2].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[2].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[2].spc_iv & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_trainers[buf8].pkm[2].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Attack_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].atk_iv = ui->spinBox_IV_Attack_4->value();
        cpu_trainers[buf8].pkm[3].hp_iv = (cpu_trainers[buf8].pkm[3].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[3].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[3].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[3].spc_iv & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_trainers[buf8].pkm[3].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Attack_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].atk_iv = ui->spinBox_IV_Attack_5->value();
        cpu_trainers[buf8].pkm[4].hp_iv = (cpu_trainers[buf8].pkm[4].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[4].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[4].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[4].spc_iv & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_trainers[buf8].pkm[4].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Attack_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].atk_iv = ui->spinBox_IV_Attack_6->value();
        cpu_trainers[buf8].pkm[5].hp_iv = (cpu_trainers[buf8].pkm[5].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[5].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[5].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[5].spc_iv & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_trainers[buf8].pkm[5].hp_iv);
    }
}

void MainWindow::on_spinBox_IV_Defense_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].def_iv = ui->spinBox_IV_Defense_1->value();
        cpu_trainers[buf8].pkm[0].hp_iv = (cpu_trainers[buf8].pkm[0].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[0].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[0].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[0].spc_iv & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_trainers[buf8].pkm[0].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Defense_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].def_iv = ui->spinBox_IV_Defense_2->value();
        cpu_trainers[buf8].pkm[1].hp_iv = (cpu_trainers[buf8].pkm[1].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[1].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[1].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[1].spc_iv & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_trainers[buf8].pkm[1].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Defense_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].def_iv = ui->spinBox_IV_Defense_3->value();
        cpu_trainers[buf8].pkm[2].hp_iv = (cpu_trainers[buf8].pkm[2].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[2].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[2].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[2].spc_iv & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_trainers[buf8].pkm[2].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Defense_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].def_iv = ui->spinBox_IV_Defense_4->value();
        cpu_trainers[buf8].pkm[3].hp_iv = (cpu_trainers[buf8].pkm[3].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[3].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[3].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[3].spc_iv & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_trainers[buf8].pkm[3].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Defense_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].def_iv = ui->spinBox_IV_Defense_5->value();
        cpu_trainers[buf8].pkm[4].hp_iv = (cpu_trainers[buf8].pkm[4].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[4].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[4].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[4].spc_iv & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_trainers[buf8].pkm[4].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Defense_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].def_iv = ui->spinBox_IV_Defense_6->value();
        cpu_trainers[buf8].pkm[5].hp_iv = (cpu_trainers[buf8].pkm[5].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[5].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[5].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[5].spc_iv & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_trainers[buf8].pkm[5].hp_iv);
    }
}

void MainWindow::on_spinBox_IV_Special_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].spc_iv = ui->spinBox_IV_Special_1->value();
        cpu_trainers[buf8].pkm[0].hp_iv = (cpu_trainers[buf8].pkm[0].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[0].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[0].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[0].spc_iv & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_trainers[buf8].pkm[0].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Special_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].spc_iv = ui->spinBox_IV_Special_2->value();
        cpu_trainers[buf8].pkm[1].hp_iv = (cpu_trainers[buf8].pkm[1].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[1].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[1].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[1].spc_iv & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_trainers[buf8].pkm[1].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Special_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].spc_iv = ui->spinBox_IV_Special_3->value();
        cpu_trainers[buf8].pkm[2].hp_iv = (cpu_trainers[buf8].pkm[2].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[2].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[2].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[2].spc_iv & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_trainers[buf8].pkm[2].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Special_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].spc_iv = ui->spinBox_IV_Special_4->value();
        cpu_trainers[buf8].pkm[3].hp_iv = (cpu_trainers[buf8].pkm[3].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[3].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[3].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[3].spc_iv & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_trainers[buf8].pkm[3].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Special_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].spc_iv = ui->spinBox_IV_Special_5->value();
        cpu_trainers[buf8].pkm[4].hp_iv = (cpu_trainers[buf8].pkm[4].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[4].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[4].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[4].spc_iv & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_trainers[buf8].pkm[4].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Special_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].spc_iv = ui->spinBox_IV_Special_6->value();
        cpu_trainers[buf8].pkm[5].hp_iv = (cpu_trainers[buf8].pkm[5].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[5].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[5].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[5].spc_iv & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_trainers[buf8].pkm[5].hp_iv);
    }
}

void MainWindow::on_spinBox_IV_Speed_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].speed_iv = ui->spinBox_IV_Speed_1->value();
        cpu_trainers[buf8].pkm[0].hp_iv = (cpu_trainers[buf8].pkm[0].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[0].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[0].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[0].spc_iv & 1);
        ui->spinBox_IV_HP_1->setValue(cpu_trainers[buf8].pkm[0].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Speed_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].speed_iv = ui->spinBox_IV_Speed_2->value();
        cpu_trainers[buf8].pkm[1].hp_iv = (cpu_trainers[buf8].pkm[1].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[1].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[1].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[1].spc_iv & 1);
        ui->spinBox_IV_HP_2->setValue(cpu_trainers[buf8].pkm[1].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Speed_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].speed_iv = ui->spinBox_IV_Speed_3->value();
        cpu_trainers[buf8].pkm[2].hp_iv = (cpu_trainers[buf8].pkm[2].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[2].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[2].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[2].spc_iv & 1);
        ui->spinBox_IV_HP_3->setValue(cpu_trainers[buf8].pkm[2].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Speed_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].speed_iv = ui->spinBox_IV_Speed_4->value();
        cpu_trainers[buf8].pkm[3].hp_iv = (cpu_trainers[buf8].pkm[3].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[3].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[3].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[3].spc_iv & 1);
        ui->spinBox_IV_HP_4->setValue(cpu_trainers[buf8].pkm[3].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Speed_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].speed_iv = ui->spinBox_IV_Speed_5->value();
        cpu_trainers[buf8].pkm[4].hp_iv = (cpu_trainers[buf8].pkm[4].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[4].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[4].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[4].spc_iv & 1);
        ui->spinBox_IV_HP_5->setValue(cpu_trainers[buf8].pkm[4].hp_iv);
    }
}
void MainWindow::on_spinBox_IV_Speed_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].speed_iv = ui->spinBox_IV_Speed_6->value();
        cpu_trainers[buf8].pkm[5].hp_iv = (cpu_trainers[buf8].pkm[5].atk_iv & 1)*8 + (cpu_trainers[buf8].pkm[5].def_iv & 1)*4 + (cpu_trainers[buf8].pkm[5].speed_iv & 1)*2 + (cpu_trainers[buf8].pkm[5].spc_iv & 1);
        ui->spinBox_IV_HP_6->setValue(cpu_trainers[buf8].pkm[5].hp_iv);
    }
}

// Pokémon Levels
void MainWindow::lv_spinbox_changed(int levelBox) {
    if (not_in_init) {
        quint8 trainer_id = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[trainer_id].pkm[levelBox].lvl = lvl_spinboxes[levelBox]->value();

        quint8 level = cpu_trainers[trainer_id].pkm[levelBox].lvl;
        level = std::min(level, static_cast<quint8>(100));
        level = std::max(level, static_cast<quint8>(2));
        cpu_trainers[trainer_id].pkm[levelBox].lvl = level;
        lvl_spinboxes[levelBox]->setValue(level);

        quint8 pkm_id = cpu_trainers[trainer_id].pkm[levelBox].id;
        pkm_growth_rate[pkm_id] = std::max(pkm_growth_rate[pkm_id],
                                           static_cast<quint8>(5));

        cpu_trainers[trainer_id].pkm[levelBox].exp =
                calc_experience(pkm_growth_rate[pkm_id], level);
    }
}

// PP Ups
void MainWindow::on_spinBox_PPUp1_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].pp_1 = 0;

        if(cpu_trainers[buf8].pkm[0].move_1==0) ui->spinBox_PPUp1_1->setValue(0);
        cpu_trainers[buf8].pkm[0].ppup_1 = ui->spinBox_PPUp1_1->value();

        if(cpu_trainers[buf8].pkm[0].ppup_1>3){
            cpu_trainers[buf8].pkm[0].ppup_1=3;
            ui->spinBox_PPUp1_1->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[0].ppup_1>0){
            cpu_trainers[buf8].pkm[0].pp_1 = move_pp[cpu_trainers[buf8].pkm[0].move_1] / 5;
            cpu_trainers[buf8].pkm[0].pp_1 *= cpu_trainers[buf8].pkm[0].ppup_1;
            cpu_trainers[buf8].pkm[0].pp_1 |= cpu_trainers[buf8].pkm[0].ppup_1<<6;
        }
        cpu_trainers[buf8].pkm[0].pp_1 += move_pp[cpu_trainers[buf8].pkm[0].move_1];
    }
}
void MainWindow::on_spinBox_PPUp2_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].pp_2 = 0;

        if(cpu_trainers[buf8].pkm[0].move_2==0) ui->spinBox_PPUp2_1->setValue(0);
        cpu_trainers[buf8].pkm[0].ppup_2 = ui->spinBox_PPUp2_1->value();

        if(cpu_trainers[buf8].pkm[0].ppup_2>3){
            cpu_trainers[buf8].pkm[0].ppup_2=3;
            ui->spinBox_PPUp2_1->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[0].ppup_2>0){
            cpu_trainers[buf8].pkm[0].pp_2 = move_pp[cpu_trainers[buf8].pkm[0].move_2] / 5;
            cpu_trainers[buf8].pkm[0].pp_2 *= cpu_trainers[buf8].pkm[0].ppup_2;
            cpu_trainers[buf8].pkm[0].pp_2 |= cpu_trainers[buf8].pkm[0].ppup_2<<6;
        }
        cpu_trainers[buf8].pkm[0].pp_2 += move_pp[cpu_trainers[buf8].pkm[0].move_2];
    }
}
void MainWindow::on_spinBox_PPUp3_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].pp_3 = 0;

        if(cpu_trainers[buf8].pkm[0].move_3==0) ui->spinBox_PPUp3_1->setValue(0);
        cpu_trainers[buf8].pkm[0].ppup_3 = ui->spinBox_PPUp3_1->value();

        if(cpu_trainers[buf8].pkm[0].ppup_3>3){
            cpu_trainers[buf8].pkm[0].ppup_3=3;
            ui->spinBox_PPUp3_1->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[0].ppup_3>0){
            cpu_trainers[buf8].pkm[0].pp_3 = move_pp[cpu_trainers[buf8].pkm[0].move_3] / 5;
            cpu_trainers[buf8].pkm[0].pp_3 *= cpu_trainers[buf8].pkm[0].ppup_3;
            cpu_trainers[buf8].pkm[0].pp_3 |= cpu_trainers[buf8].pkm[0].ppup_3<<6;
        }
        cpu_trainers[buf8].pkm[0].pp_3 += move_pp[cpu_trainers[buf8].pkm[0].move_3];
    }
}
void MainWindow::on_spinBox_PPUp4_1_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[0].pp_4 = 0;

        if(cpu_trainers[buf8].pkm[0].move_4==0) ui->spinBox_PPUp4_1->setValue(0);
        cpu_trainers[buf8].pkm[0].ppup_4 = ui->spinBox_PPUp4_1->value();

        if(cpu_trainers[buf8].pkm[0].ppup_4>3){
            cpu_trainers[buf8].pkm[0].ppup_4=3;
            ui->spinBox_PPUp4_1->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[0].ppup_4>0){
            cpu_trainers[buf8].pkm[0].pp_4 = move_pp[cpu_trainers[buf8].pkm[0].move_4] / 5;
            cpu_trainers[buf8].pkm[0].pp_4 *= cpu_trainers[buf8].pkm[0].ppup_4;
            cpu_trainers[buf8].pkm[0].pp_4 |= cpu_trainers[buf8].pkm[0].ppup_4<<6;
        }
        cpu_trainers[buf8].pkm[0].pp_4 += move_pp[cpu_trainers[buf8].pkm[0].move_4];
    }
}

void MainWindow::on_spinBox_PPUp1_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].pp_1 = 0;

        if(cpu_trainers[buf8].pkm[1].move_1==0) ui->spinBox_PPUp1_2->setValue(0);
        cpu_trainers[buf8].pkm[1].ppup_1 = ui->spinBox_PPUp1_2->value();

        if(cpu_trainers[buf8].pkm[1].ppup_1>3){
            cpu_trainers[buf8].pkm[1].ppup_1=3;
            ui->spinBox_PPUp1_2->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[1].ppup_1>0){
            cpu_trainers[buf8].pkm[1].pp_1 = move_pp[cpu_trainers[buf8].pkm[1].move_1] / 5;
            cpu_trainers[buf8].pkm[1].pp_1 *= cpu_trainers[buf8].pkm[1].ppup_1;
            cpu_trainers[buf8].pkm[1].pp_1 |= cpu_trainers[buf8].pkm[1].ppup_1<<6;
        }
        cpu_trainers[buf8].pkm[1].pp_1 += move_pp[cpu_trainers[buf8].pkm[1].move_1];
    }
}
void MainWindow::on_spinBox_PPUp2_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].pp_2 = 0;

        if(cpu_trainers[buf8].pkm[1].move_2==0) ui->spinBox_PPUp2_2->setValue(0);
        cpu_trainers[buf8].pkm[1].ppup_2 = ui->spinBox_PPUp2_2->value();

        if(cpu_trainers[buf8].pkm[1].ppup_2>3){
            cpu_trainers[buf8].pkm[1].ppup_2=3;
            ui->spinBox_PPUp2_2->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[1].ppup_2>0){
            cpu_trainers[buf8].pkm[1].pp_2 = move_pp[cpu_trainers[buf8].pkm[1].move_2] / 5;
            cpu_trainers[buf8].pkm[1].pp_2 *= cpu_trainers[buf8].pkm[1].ppup_2;
            cpu_trainers[buf8].pkm[1].pp_2 |= cpu_trainers[buf8].pkm[1].ppup_2<<6;
        }
        cpu_trainers[buf8].pkm[1].pp_2 += move_pp[cpu_trainers[buf8].pkm[1].move_2];
    }
}
void MainWindow::on_spinBox_PPUp3_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].pp_3 = 0;

        if(cpu_trainers[buf8].pkm[1].move_3==0) ui->spinBox_PPUp3_2->setValue(0);
        cpu_trainers[buf8].pkm[1].ppup_3 = ui->spinBox_PPUp3_2->value();

        if(cpu_trainers[buf8].pkm[1].ppup_3>3){
            cpu_trainers[buf8].pkm[1].ppup_3=3;
            ui->spinBox_PPUp3_2->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[1].ppup_3>0){
            cpu_trainers[buf8].pkm[1].pp_3 = move_pp[cpu_trainers[buf8].pkm[1].move_3] / 5;
            cpu_trainers[buf8].pkm[1].pp_3 *= cpu_trainers[buf8].pkm[1].ppup_3;
            cpu_trainers[buf8].pkm[1].pp_3 |= cpu_trainers[buf8].pkm[1].ppup_3<<6;
        }
        cpu_trainers[buf8].pkm[1].pp_3 += move_pp[cpu_trainers[buf8].pkm[1].move_3];
    }
}
void MainWindow::on_spinBox_PPUp4_2_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[1].pp_4 = 0;

        if(cpu_trainers[buf8].pkm[1].move_4==0) ui->spinBox_PPUp4_2->setValue(0);
        cpu_trainers[buf8].pkm[1].ppup_4 = ui->spinBox_PPUp4_2->value();

        if(cpu_trainers[buf8].pkm[1].ppup_4>3){
            cpu_trainers[buf8].pkm[1].ppup_4=3;
            ui->spinBox_PPUp4_2->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[1].ppup_4>0){
            cpu_trainers[buf8].pkm[1].pp_4 = move_pp[cpu_trainers[buf8].pkm[1].move_4] / 5;
            cpu_trainers[buf8].pkm[1].pp_4 *= cpu_trainers[buf8].pkm[1].ppup_4;
            cpu_trainers[buf8].pkm[1].pp_4 |= cpu_trainers[buf8].pkm[1].ppup_4<<6;
        }
        cpu_trainers[buf8].pkm[1].pp_4 += move_pp[cpu_trainers[buf8].pkm[1].move_4];
    }
}

void MainWindow::on_spinBox_PPUp1_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].pp_1 = 0;

        if(cpu_trainers[buf8].pkm[2].move_1==0) ui->spinBox_PPUp1_3->setValue(0);
        cpu_trainers[buf8].pkm[2].ppup_1 = ui->spinBox_PPUp1_3->value();

        if(cpu_trainers[buf8].pkm[2].ppup_1>3){
            cpu_trainers[buf8].pkm[2].ppup_1=3;
            ui->spinBox_PPUp1_3->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[2].ppup_1>0){
            cpu_trainers[buf8].pkm[2].pp_1 = move_pp[cpu_trainers[buf8].pkm[2].move_1] / 5;
            cpu_trainers[buf8].pkm[2].pp_1 *= cpu_trainers[buf8].pkm[2].ppup_1;
            cpu_trainers[buf8].pkm[2].pp_1 |= cpu_trainers[buf8].pkm[2].ppup_1<<6;
        }
        cpu_trainers[buf8].pkm[2].pp_1 += move_pp[cpu_trainers[buf8].pkm[2].move_1];
    }
}
void MainWindow::on_spinBox_PPUp2_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].pp_2 = 0;

        if(cpu_trainers[buf8].pkm[2].move_2==0) ui->spinBox_PPUp2_3->setValue(0);
        cpu_trainers[buf8].pkm[2].ppup_2 = ui->spinBox_PPUp2_3->value();

        if(cpu_trainers[buf8].pkm[2].ppup_2>3){
            cpu_trainers[buf8].pkm[2].ppup_2=3;
            ui->spinBox_PPUp2_3->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[2].ppup_2>0){
            cpu_trainers[buf8].pkm[2].pp_2 = move_pp[cpu_trainers[buf8].pkm[2].move_2] / 5;
            cpu_trainers[buf8].pkm[2].pp_2 *= cpu_trainers[buf8].pkm[2].ppup_2;
            cpu_trainers[buf8].pkm[2].pp_2 |= cpu_trainers[buf8].pkm[2].ppup_2<<6;
        }
        cpu_trainers[buf8].pkm[2].pp_2 += move_pp[cpu_trainers[buf8].pkm[2].move_2];
    }
}
void MainWindow::on_spinBox_PPUp3_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].pp_3 = 0;

        if(cpu_trainers[buf8].pkm[2].move_3==0) ui->spinBox_PPUp3_3->setValue(0);
        cpu_trainers[buf8].pkm[2].ppup_3 = ui->spinBox_PPUp3_3->value();

        if(cpu_trainers[buf8].pkm[2].ppup_3>3){
            cpu_trainers[buf8].pkm[2].ppup_3=3;
            ui->spinBox_PPUp3_3->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[2].ppup_3>0){
            cpu_trainers[buf8].pkm[2].pp_3 = move_pp[cpu_trainers[buf8].pkm[2].move_3] / 5;
            cpu_trainers[buf8].pkm[2].pp_3 *= cpu_trainers[buf8].pkm[2].ppup_3;
            cpu_trainers[buf8].pkm[2].pp_3 |= cpu_trainers[buf8].pkm[2].ppup_3<<6;
        }
        cpu_trainers[buf8].pkm[2].pp_3 += move_pp[cpu_trainers[buf8].pkm[2].move_3];
    }
}
void MainWindow::on_spinBox_PPUp4_3_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[2].pp_4 = 0;

        if(cpu_trainers[buf8].pkm[2].move_4==0) ui->spinBox_PPUp4_3->setValue(0);
        cpu_trainers[buf8].pkm[2].ppup_4 = ui->spinBox_PPUp4_3->value();

        if(cpu_trainers[buf8].pkm[2].ppup_4>3){
            cpu_trainers[buf8].pkm[2].ppup_4=3;
            ui->spinBox_PPUp4_3->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[2].ppup_4>0){
            cpu_trainers[buf8].pkm[2].pp_4 = move_pp[cpu_trainers[buf8].pkm[2].move_4] / 5;
            cpu_trainers[buf8].pkm[2].pp_4 *= cpu_trainers[buf8].pkm[2].ppup_4;
            cpu_trainers[buf8].pkm[2].pp_4 |= cpu_trainers[buf8].pkm[2].ppup_4<<6;
        }
        cpu_trainers[buf8].pkm[2].pp_4 += move_pp[cpu_trainers[buf8].pkm[2].move_4];
    }
}

void MainWindow::on_spinBox_PPUp1_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].pp_1 = 0;

        if(cpu_trainers[buf8].pkm[3].move_1==0) ui->spinBox_PPUp1_4->setValue(0);
        cpu_trainers[buf8].pkm[3].ppup_1 = ui->spinBox_PPUp1_4->value();

        if(cpu_trainers[buf8].pkm[3].ppup_1>3){
            cpu_trainers[buf8].pkm[3].ppup_1=3;
            ui->spinBox_PPUp1_4->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[3].ppup_1>0){
            cpu_trainers[buf8].pkm[3].pp_1 = move_pp[cpu_trainers[buf8].pkm[3].move_1] / 5;
            cpu_trainers[buf8].pkm[3].pp_1 *= cpu_trainers[buf8].pkm[3].ppup_1;
            cpu_trainers[buf8].pkm[3].pp_1 |= cpu_trainers[buf8].pkm[3].ppup_1<<6;
        }
        cpu_trainers[buf8].pkm[3].pp_1 += move_pp[cpu_trainers[buf8].pkm[3].move_1];
    }
}
void MainWindow::on_spinBox_PPUp2_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].pp_2 = 0;

        if(cpu_trainers[buf8].pkm[3].move_2==0) ui->spinBox_PPUp2_4->setValue(0);
        cpu_trainers[buf8].pkm[3].ppup_2 = ui->spinBox_PPUp2_4->value();

        if(cpu_trainers[buf8].pkm[3].ppup_2>3){
            cpu_trainers[buf8].pkm[3].ppup_2=3;
            ui->spinBox_PPUp2_4->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[3].ppup_2>0){
            cpu_trainers[buf8].pkm[3].pp_2 = move_pp[cpu_trainers[buf8].pkm[3].move_2] / 5;
            cpu_trainers[buf8].pkm[3].pp_2 *= cpu_trainers[buf8].pkm[3].ppup_2;
            cpu_trainers[buf8].pkm[3].pp_2 |= cpu_trainers[buf8].pkm[3].ppup_2<<6;
        }
        cpu_trainers[buf8].pkm[3].pp_2 += move_pp[cpu_trainers[buf8].pkm[3].move_2];
    }
}
void MainWindow::on_spinBox_PPUp3_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].pp_3 = 0;

        if(cpu_trainers[buf8].pkm[3].move_3==0) ui->spinBox_PPUp3_4->setValue(0);
        cpu_trainers[buf8].pkm[3].ppup_3 = ui->spinBox_PPUp3_4->value();

        if(cpu_trainers[buf8].pkm[3].ppup_3>3){
            cpu_trainers[buf8].pkm[3].ppup_3=3;
            ui->spinBox_PPUp3_4->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[3].ppup_3>0){
            cpu_trainers[buf8].pkm[3].pp_3 = move_pp[cpu_trainers[buf8].pkm[3].move_3] / 5;
            cpu_trainers[buf8].pkm[3].pp_3 *= cpu_trainers[buf8].pkm[3].ppup_3;
            cpu_trainers[buf8].pkm[3].pp_3 |= cpu_trainers[buf8].pkm[3].ppup_3<<6;
        }
        cpu_trainers[buf8].pkm[3].pp_3 += move_pp[cpu_trainers[buf8].pkm[3].move_3];
    }
}
void MainWindow::on_spinBox_PPUp4_4_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[3].pp_4 = 0;

        if(cpu_trainers[buf8].pkm[3].move_4==0) ui->spinBox_PPUp4_4->setValue(0);
        cpu_trainers[buf8].pkm[3].ppup_4 = ui->spinBox_PPUp4_4->value();

        if(cpu_trainers[buf8].pkm[3].ppup_4>3){
            cpu_trainers[buf8].pkm[3].ppup_4=3;
            ui->spinBox_PPUp4_4->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[3].ppup_4>0){
            cpu_trainers[buf8].pkm[3].pp_4 = move_pp[cpu_trainers[buf8].pkm[3].move_4] / 5;
            cpu_trainers[buf8].pkm[3].pp_4 *= cpu_trainers[buf8].pkm[3].ppup_4;
            cpu_trainers[buf8].pkm[3].pp_4 |= cpu_trainers[buf8].pkm[3].ppup_4<<6;
        }
        cpu_trainers[buf8].pkm[3].pp_4 += move_pp[cpu_trainers[buf8].pkm[3].move_4];
    }
}

void MainWindow::on_spinBox_PPUp1_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].pp_1 = 0;

        if(cpu_trainers[buf8].pkm[4].move_1==0) ui->spinBox_PPUp1_5->setValue(0);
        cpu_trainers[buf8].pkm[4].ppup_1 = ui->spinBox_PPUp1_5->value();

        if(cpu_trainers[buf8].pkm[4].ppup_1>3){
            cpu_trainers[buf8].pkm[4].ppup_1=3;
            ui->spinBox_PPUp1_5->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[4].ppup_1>0){
            cpu_trainers[buf8].pkm[4].pp_1 = move_pp[cpu_trainers[buf8].pkm[4].move_1] / 5;
            cpu_trainers[buf8].pkm[4].pp_1 *= cpu_trainers[buf8].pkm[4].ppup_1;
            cpu_trainers[buf8].pkm[4].pp_1 |= cpu_trainers[buf8].pkm[4].ppup_1<<6;
        }
        cpu_trainers[buf8].pkm[4].pp_1 += move_pp[cpu_trainers[buf8].pkm[4].move_1];
    }
}
void MainWindow::on_spinBox_PPUp2_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].pp_2 = 0;

        if(cpu_trainers[buf8].pkm[4].move_2==0) ui->spinBox_PPUp2_5->setValue(0);
        cpu_trainers[buf8].pkm[4].ppup_2 = ui->spinBox_PPUp2_5->value();

        if(cpu_trainers[buf8].pkm[4].ppup_2>3){
            cpu_trainers[buf8].pkm[4].ppup_2=3;
            ui->spinBox_PPUp2_5->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[4].ppup_2>0){
            cpu_trainers[buf8].pkm[4].pp_2 = move_pp[cpu_trainers[buf8].pkm[4].move_2] / 5;
            cpu_trainers[buf8].pkm[4].pp_2 *= cpu_trainers[buf8].pkm[4].ppup_2;
            cpu_trainers[buf8].pkm[4].pp_2 |= cpu_trainers[buf8].pkm[4].ppup_2<<6;
        }
        cpu_trainers[buf8].pkm[4].pp_2 += move_pp[cpu_trainers[buf8].pkm[4].move_2];
    }
}
void MainWindow::on_spinBox_PPUp3_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].pp_3 = 0;

        if(cpu_trainers[buf8].pkm[4].move_3==0) ui->spinBox_PPUp3_5->setValue(0);
        cpu_trainers[buf8].pkm[4].ppup_3 = ui->spinBox_PPUp3_5->value();

        if(cpu_trainers[buf8].pkm[4].ppup_3>3){
            cpu_trainers[buf8].pkm[4].ppup_3=3;
            ui->spinBox_PPUp3_5->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[4].ppup_3>0){
            cpu_trainers[buf8].pkm[4].pp_3 = move_pp[cpu_trainers[buf8].pkm[4].move_3] / 5;
            cpu_trainers[buf8].pkm[4].pp_3 *= cpu_trainers[buf8].pkm[4].ppup_3;
            cpu_trainers[buf8].pkm[4].pp_3 |= cpu_trainers[buf8].pkm[4].ppup_3<<6;
        }
        cpu_trainers[buf8].pkm[4].pp_3 += move_pp[cpu_trainers[buf8].pkm[4].move_3];
    }
}
void MainWindow::on_spinBox_PPUp4_5_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[4].pp_4 = 0;

        if(cpu_trainers[buf8].pkm[4].move_4==0) ui->spinBox_PPUp4_5->setValue(0);
        cpu_trainers[buf8].pkm[4].ppup_4 = ui->spinBox_PPUp4_5->value();

        if(cpu_trainers[buf8].pkm[4].ppup_4>3){
            cpu_trainers[buf8].pkm[4].ppup_4=3;
            ui->spinBox_PPUp4_5->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[4].ppup_4>0){
            cpu_trainers[buf8].pkm[4].pp_4 = move_pp[cpu_trainers[buf8].pkm[4].move_4] / 5;
            cpu_trainers[buf8].pkm[4].pp_4 *= cpu_trainers[buf8].pkm[4].ppup_4;
            cpu_trainers[buf8].pkm[4].pp_4 |= cpu_trainers[buf8].pkm[4].ppup_4<<6;
        }
        cpu_trainers[buf8].pkm[4].pp_4 += move_pp[cpu_trainers[buf8].pkm[4].move_4];
    }
}

void MainWindow::on_spinBox_PPUp1_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].pp_1 = 0;

        if(cpu_trainers[buf8].pkm[5].move_1==0) ui->spinBox_PPUp1_6->setValue(0);
        cpu_trainers[buf8].pkm[5].ppup_1 = ui->spinBox_PPUp1_6->value();

        if(cpu_trainers[buf8].pkm[5].ppup_1>3){
            cpu_trainers[buf8].pkm[5].ppup_1=3;
            ui->spinBox_PPUp1_6->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[5].ppup_1>0){
            cpu_trainers[buf8].pkm[5].pp_1 = move_pp[cpu_trainers[buf8].pkm[5].move_1] / 5;
            cpu_trainers[buf8].pkm[5].pp_1 *= cpu_trainers[buf8].pkm[5].ppup_1;
            cpu_trainers[buf8].pkm[5].pp_1 |= cpu_trainers[buf8].pkm[5].ppup_1<<6;
        }
        cpu_trainers[buf8].pkm[5].pp_1 += move_pp[cpu_trainers[buf8].pkm[5].move_1];
    }
}
void MainWindow::on_spinBox_PPUp2_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].pp_2 = 0;

        if(cpu_trainers[buf8].pkm[5].move_2==0) ui->spinBox_PPUp2_6->setValue(0);
        cpu_trainers[buf8].pkm[5].ppup_2 = ui->spinBox_PPUp2_6->value();

        if(cpu_trainers[buf8].pkm[5].ppup_2>3){
            cpu_trainers[buf8].pkm[5].ppup_2=3;
            ui->spinBox_PPUp2_6->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[5].ppup_2>0){
            cpu_trainers[buf8].pkm[5].pp_2 = move_pp[cpu_trainers[buf8].pkm[5].move_2] / 5;
            cpu_trainers[buf8].pkm[5].pp_2 *= cpu_trainers[buf8].pkm[5].ppup_2;
            cpu_trainers[buf8].pkm[5].pp_2 |= cpu_trainers[buf8].pkm[5].ppup_2<<6;
        }
        cpu_trainers[buf8].pkm[5].pp_2 += move_pp[cpu_trainers[buf8].pkm[5].move_2];
    }
}
void MainWindow::on_spinBox_PPUp3_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].pp_3 = 0;

        if(cpu_trainers[buf8].pkm[5].move_3==0) ui->spinBox_PPUp3_6->setValue(0);
        cpu_trainers[buf8].pkm[5].ppup_3 = ui->spinBox_PPUp3_6->value();

        if(cpu_trainers[buf8].pkm[5].ppup_3>3){
            cpu_trainers[buf8].pkm[5].ppup_3=3;
            ui->spinBox_PPUp3_6->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[5].ppup_3>0){
            cpu_trainers[buf8].pkm[5].pp_3 = move_pp[cpu_trainers[buf8].pkm[5].move_3] / 5;
            cpu_trainers[buf8].pkm[5].pp_3 *= cpu_trainers[buf8].pkm[5].ppup_3;
            cpu_trainers[buf8].pkm[5].pp_3 |= cpu_trainers[buf8].pkm[5].ppup_3<<6;
        }
        cpu_trainers[buf8].pkm[5].pp_3 += move_pp[cpu_trainers[buf8].pkm[5].move_3];
    }
}
void MainWindow::on_spinBox_PPUp4_6_valueChanged(int) {
    if(not_in_init){
        buf8 = ui->comboBox_CPU_Trainer->currentIndex();
        cpu_trainers[buf8].pkm[5].pp_4 = 0;

        if(cpu_trainers[buf8].pkm[5].move_4==0) ui->spinBox_PPUp4_6->setValue(0);
        cpu_trainers[buf8].pkm[5].ppup_4 = ui->spinBox_PPUp4_6->value();

        if(cpu_trainers[buf8].pkm[5].ppup_4>3){
            cpu_trainers[buf8].pkm[5].ppup_4=3;
            ui->spinBox_PPUp4_6->setValue(3);
        }
        if(cpu_trainers[buf8].pkm[5].ppup_4>0){
            cpu_trainers[buf8].pkm[5].pp_4 = move_pp[cpu_trainers[buf8].pkm[5].move_4] / 5;
            cpu_trainers[buf8].pkm[5].pp_4 *= cpu_trainers[buf8].pkm[5].ppup_4;
            cpu_trainers[buf8].pkm[5].pp_4 |= cpu_trainers[buf8].pkm[5].ppup_4<<6;
        }
        cpu_trainers[buf8].pkm[5].pp_4 += move_pp[cpu_trainers[buf8].pkm[5].move_4];
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
