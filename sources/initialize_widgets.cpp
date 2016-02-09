#include <QHBoxLayout>
#include "mainwindow.h"

void MainWindow::initialize_widgets()
{
    ui->tabWidget->setEnabled(false);
    // Clear widgets
    ui->comboBox_Pkmn_1->clear();
    ui->comboBox_Pkmn_2->clear();
    ui->comboBox_Pkmn_3->clear();
    ui->comboBox_Pkmn_4->clear();
    ui->comboBox_Pkmn_5->clear();
    ui->comboBox_Pkmn_6->clear();
    ui->comboBox_PokemonSpecies->clear();

    ui->comboBox_Move1_1->clear();
    ui->comboBox_Move2_1->clear();
    ui->comboBox_Move3_1->clear();
    ui->comboBox_Move4_1->clear();
    ui->comboBox_Move1_2->clear();
    ui->comboBox_Move2_2->clear();
    ui->comboBox_Move3_2->clear();
    ui->comboBox_Move4_2->clear();
    ui->comboBox_Move1_3->clear();
    ui->comboBox_Move2_3->clear();
    ui->comboBox_Move3_3->clear();
    ui->comboBox_Move4_3->clear();
    ui->comboBox_Move1_4->clear();
    ui->comboBox_Move2_4->clear();
    ui->comboBox_Move3_4->clear();
    ui->comboBox_Move4_4->clear();
    ui->comboBox_Move1_5->clear();
    ui->comboBox_Move2_5->clear();
    ui->comboBox_Move3_5->clear();
    ui->comboBox_Move4_5->clear();
    ui->comboBox_Move1_6->clear();
    ui->comboBox_Move2_6->clear();
    ui->comboBox_Move3_6->clear();
    ui->comboBox_Move4_6->clear();
    ui->comboBox_MovesList->clear();
    ui->comboBox_HighCH_MovesList_1->clear();
    ui->comboBox_HighCH_MovesList_2->clear();
    ui->comboBox_HighCH_MovesList_3->clear();
    ui->comboBox_HighCH_MovesList_4->clear();

    ui->comboBox_Pokemon_Type_1->clear();
    ui->comboBox_Pokemon_Type_2->clear();
    ui->comboBox_MoveType->clear();

    ui->tableWidget_StartingMoves->clear();

    ui->comboBox_GrowthRate->clear();

    ui->spinBox_TrainerSpriteID->setValue(0);
    ui->img_TrainerSprite->clear();
    ui->spinBox_CPU_PartySize->setValue(1);

    ui->label_Pokemon_Sprite->clear();
    ui->spinBox_PokemonSpecie_Pointer->setValue(0);

    ui->lineEdit_Move_Name->setText("");
    ui->spinBox_MoveName_Pointer->setValue(0);
    ui->spinBox_MoveID->setValue(0);
    ui->spinBox_MoveAccuracy->setValue(0);
    ui->spinBox_MovePower->setValue(0);
    ui->spinBox_MovePP->setValue(0);
    ui->comboBox_MoveEffect->setCurrentIndex(0);

    ui->textEdit_PokedexEntry->clear();
    ui->spinBox_Pokedex_Pointer->setValue(0);

    ui->textEdit_MoveTMHMText->clear();
    ui->textEdit_MoveDescrText->clear();



    // If the ROM is valid, populate the widgets
    if(this->romtype != INVALID){
        ui->tabWidget->setEnabled(true);

        // CPU Trainers
        ui->comboBox_CPU_Trainer->clear();

        // Pokémon
        ui->comboBox_Pkmn_1->addItem("-");
        ui->comboBox_Pkmn_2->addItem("-");
        ui->comboBox_Pkmn_3->addItem("-");
        ui->comboBox_Pkmn_4->addItem("-");
        ui->comboBox_Pkmn_5->addItem("-");
        ui->comboBox_Pkmn_6->addItem("-");

        for (short i=1;i<=total_pkm_name;i++){
            ui->comboBox_Pkmn_1->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_2->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_3->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_4->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_5->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_6->addItem(pkm_name[i]);
            ui->comboBox_PokemonSpecies->addItem(pkm_name[i]);
        }
        // Moves
        ui->comboBox_Move1_1->addItem("-");
        ui->comboBox_Move2_1->addItem("-");
        ui->comboBox_Move3_1->addItem("-");
        ui->comboBox_Move4_1->addItem("-");
        ui->comboBox_Move1_2->addItem("-");
        ui->comboBox_Move2_2->addItem("-");
        ui->comboBox_Move3_2->addItem("-");
        ui->comboBox_Move4_2->addItem("-");
        ui->comboBox_Move1_3->addItem("-");
        ui->comboBox_Move2_3->addItem("-");
        ui->comboBox_Move3_3->addItem("-");
        ui->comboBox_Move4_3->addItem("-");
        ui->comboBox_Move1_4->addItem("-");
        ui->comboBox_Move2_4->addItem("-");
        ui->comboBox_Move3_4->addItem("-");
        ui->comboBox_Move4_4->addItem("-");
        ui->comboBox_Move1_5->addItem("-");
        ui->comboBox_Move2_5->addItem("-");
        ui->comboBox_Move3_5->addItem("-");
        ui->comboBox_Move4_5->addItem("-");
        ui->comboBox_Move1_6->addItem("-");
        ui->comboBox_Move2_6->addItem("-");
        ui->comboBox_Move3_6->addItem("-");
        ui->comboBox_Move4_6->addItem("-");
        ui->comboBox_HighCH_MovesList_1->addItem("-");
        ui->comboBox_HighCH_MovesList_2->addItem("-");
        ui->comboBox_HighCH_MovesList_3->addItem("-");
        ui->comboBox_HighCH_MovesList_4->addItem("-");

        for (short i=1;i<=total_move_name;i++){
            ui->comboBox_Move1_1->addItem(move_name[i]);
            ui->comboBox_Move2_1->addItem(move_name[i]);
            ui->comboBox_Move3_1->addItem(move_name[i]);
            ui->comboBox_Move4_1->addItem(move_name[i]);
            ui->comboBox_Move1_2->addItem(move_name[i]);
            ui->comboBox_Move2_2->addItem(move_name[i]);
            ui->comboBox_Move3_2->addItem(move_name[i]);
            ui->comboBox_Move4_2->addItem(move_name[i]);
            ui->comboBox_Move1_3->addItem(move_name[i]);
            ui->comboBox_Move2_3->addItem(move_name[i]);
            ui->comboBox_Move3_3->addItem(move_name[i]);
            ui->comboBox_Move4_3->addItem(move_name[i]);
            ui->comboBox_Move1_4->addItem(move_name[i]);
            ui->comboBox_Move2_4->addItem(move_name[i]);
            ui->comboBox_Move3_4->addItem(move_name[i]);
            ui->comboBox_Move4_4->addItem(move_name[i]);
            ui->comboBox_Move1_5->addItem(move_name[i]);
            ui->comboBox_Move2_5->addItem(move_name[i]);
            ui->comboBox_Move3_5->addItem(move_name[i]);
            ui->comboBox_Move4_5->addItem(move_name[i]);
            ui->comboBox_Move1_6->addItem(move_name[i]);
            ui->comboBox_Move2_6->addItem(move_name[i]);
            ui->comboBox_Move3_6->addItem(move_name[i]);
            ui->comboBox_Move4_6->addItem(move_name[i]);
            ui->comboBox_MovesList->addItem(move_name[i]);
            ui->comboBox_HighCH_MovesList_1->addItem(move_name[i]);
            ui->comboBox_HighCH_MovesList_2->addItem(move_name[i]);
            ui->comboBox_HighCH_MovesList_3->addItem(move_name[i]);
            ui->comboBox_HighCH_MovesList_4->addItem(move_name[i]);
        }

        ui->lineEdit_Move_Name->setText(move_name[1]);
        ui->spinBox_MoveName_Pointer->setValue(move_name_pointer[1]);
        ui->spinBox_MoveID->setValue(move_iid[1]);
        ui->spinBox_MoveAccuracy->setValue(move_accuracy[1]);
        ui->spinBox_MovePower->setValue(move_power[1]);
        ui->spinBox_MovePP->setValue(move_pp[1]);
        ui->comboBox_MoveType->setCurrentIndex(move_type[1]);
        ui->comboBox_MoveEffect->setCurrentIndex(move_effect[1]);


        // Types
        for (short i=0;i<total_type_name;i++){
            ui->comboBox_Pokemon_Type_1->addItem(type_name[i]);
            ui->comboBox_Pokemon_Type_2->addItem(type_name[i]);
            ui->comboBox_MoveType->addItem(type_name[i]);
        }



        // Pokémon data
        ui->lineEdit_Pokemon_Specie->setText(pkm_name[1]);
        ui->spinBox_PokemonSpecie_Pointer->setValue(pkm_name_pointer[1]);
        ui->spinBox_Base_HP->setValue(pkm_base_hp[1]);
        ui->spinBox_Base_Attack->setValue(pkm_base_atk[1]);
        ui->spinBox_Base_Defense->setValue(pkm_base_def[1]);
        ui->spinBox_Base_Special->setValue(pkm_base_speed[1]);
        ui->spinBox_Base_Speed->setValue(pkm_base_spc[1]);
        ui->spinBox_BaseExperience->setValue(pkm_base_experience[1]);
        ui->spinBox_CatchRate->setValue(pkm_catch_rate[1]);

        ui->comboBox_Pokemon_Type_1->setCurrentIndex(pkm_type_1[1]);
        ui->comboBox_Pokemon_Type_2->setCurrentIndex(pkm_type_2[1]);

        ui->tableWidget_StartingMoves->setRowCount(4);
        ui->tableWidget_StartingMoves->setColumnCount(1);
        ui->tableWidget_StartingMoves->setHorizontalHeaderItem(0, new QTableWidgetItem("Starting Moves"));
        ui->tableWidget_StartingMoves->verticalHeader()->setVisible(false);
        ui->tableWidget_StartingMoves->setItem(0,0,new QTableWidgetItem(move_name[pkm_start_move_1[1]]));
        ui->tableWidget_StartingMoves->setItem(1,0,new QTableWidgetItem(move_name[pkm_start_move_2[1]]));
        ui->tableWidget_StartingMoves->setItem(2,0,new QTableWidgetItem(move_name[pkm_start_move_3[1]]));
        ui->tableWidget_StartingMoves->setItem(3,0,new QTableWidgetItem(move_name[pkm_start_move_4[1]]));



        ui->tableWidget_MoveLevel_RB->setRowCount(10);
        ui->tableWidget_MoveLevel_RB->setColumnCount(2);
        ui->tableWidget_MoveLevel_RB->setHorizontalHeaderItem(0, new QTableWidgetItem("Lv"));
        ui->tableWidget_MoveLevel_RB->setHorizontalHeaderItem(1, new QTableWidgetItem("RB Level moves"));
        ui->tableWidget_MoveLevel_RB->verticalHeader()->setVisible(false);
        ui->tableWidget_MoveLevel_RB->setItem(0,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][0])));
        ui->tableWidget_MoveLevel_RB->setItem(1,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][1])));
        ui->tableWidget_MoveLevel_RB->setItem(2,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][2])));
        ui->tableWidget_MoveLevel_RB->setItem(3,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][3])));
        ui->tableWidget_MoveLevel_RB->setItem(4,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][4])));
        ui->tableWidget_MoveLevel_RB->setItem(5,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][5])));
        ui->tableWidget_MoveLevel_RB->setItem(6,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][6])));
        ui->tableWidget_MoveLevel_RB->setItem(7,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][7])));
        ui->tableWidget_MoveLevel_RB->setItem(8,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][8])));
        ui->tableWidget_MoveLevel_RB->setItem(9,0,new QTableWidgetItem(QString::number(pkm_rb_lvl[1][9])));
        ui->tableWidget_MoveLevel_RB->setItem(0,1,new QTableWidgetItem(move_name[pkm_rb_move[1][0]]));
        ui->tableWidget_MoveLevel_RB->setItem(1,1,new QTableWidgetItem(move_name[pkm_rb_move[1][1]]));
        ui->tableWidget_MoveLevel_RB->setItem(2,1,new QTableWidgetItem(move_name[pkm_rb_move[1][2]]));
        ui->tableWidget_MoveLevel_RB->setItem(3,1,new QTableWidgetItem(move_name[pkm_rb_move[1][3]]));
        ui->tableWidget_MoveLevel_RB->setItem(4,1,new QTableWidgetItem(move_name[pkm_rb_move[1][4]]));
        ui->tableWidget_MoveLevel_RB->setItem(5,1,new QTableWidgetItem(move_name[pkm_rb_move[1][5]]));
        ui->tableWidget_MoveLevel_RB->setItem(6,1,new QTableWidgetItem(move_name[pkm_rb_move[1][6]]));
        ui->tableWidget_MoveLevel_RB->setItem(7,1,new QTableWidgetItem(move_name[pkm_rb_move[1][7]]));
        ui->tableWidget_MoveLevel_RB->setItem(8,1,new QTableWidgetItem(move_name[pkm_rb_move[1][8]]));
        ui->tableWidget_MoveLevel_RB->setItem(9,1,new QTableWidgetItem(move_name[pkm_rb_move[1][9]]));

        ui->tableWidget_MoveLevel_Y->setRowCount(10);
        ui->tableWidget_MoveLevel_Y->setColumnCount(2);
        ui->tableWidget_MoveLevel_Y->setHorizontalHeaderItem(0, new QTableWidgetItem("Lv"));
        ui->tableWidget_MoveLevel_Y->setHorizontalHeaderItem(1, new QTableWidgetItem("Y Level moves"));
        ui->tableWidget_MoveLevel_Y->verticalHeader()->setVisible(false);
        ui->tableWidget_MoveLevel_Y->setItem(0,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][0])));
        ui->tableWidget_MoveLevel_Y->setItem(1,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][1])));
        ui->tableWidget_MoveLevel_Y->setItem(2,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][2])));
        ui->tableWidget_MoveLevel_Y->setItem(3,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][3])));
        ui->tableWidget_MoveLevel_Y->setItem(4,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][4])));
        ui->tableWidget_MoveLevel_Y->setItem(5,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][5])));
        ui->tableWidget_MoveLevel_Y->setItem(6,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][6])));
        ui->tableWidget_MoveLevel_Y->setItem(7,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][7])));
        ui->tableWidget_MoveLevel_Y->setItem(8,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][8])));
        ui->tableWidget_MoveLevel_Y->setItem(9,0,new QTableWidgetItem(QString::number(pkm_y_lvl[1][9])));
        ui->tableWidget_MoveLevel_Y->setItem(0,1,new QTableWidgetItem(move_name[pkm_y_move[1][0]]));
        ui->tableWidget_MoveLevel_Y->setItem(1,1,new QTableWidgetItem(move_name[pkm_y_move[1][1]]));
        ui->tableWidget_MoveLevel_Y->setItem(2,1,new QTableWidgetItem(move_name[pkm_y_move[1][2]]));
        ui->tableWidget_MoveLevel_Y->setItem(3,1,new QTableWidgetItem(move_name[pkm_y_move[1][3]]));
        ui->tableWidget_MoveLevel_Y->setItem(4,1,new QTableWidgetItem(move_name[pkm_y_move[1][4]]));
        ui->tableWidget_MoveLevel_Y->setItem(5,1,new QTableWidgetItem(move_name[pkm_y_move[1][5]]));
        ui->tableWidget_MoveLevel_Y->setItem(6,1,new QTableWidgetItem(move_name[pkm_y_move[1][6]]));
        ui->tableWidget_MoveLevel_Y->setItem(7,1,new QTableWidgetItem(move_name[pkm_y_move[1][7]]));
        ui->tableWidget_MoveLevel_Y->setItem(8,1,new QTableWidgetItem(move_name[pkm_y_move[1][8]]));
        ui->tableWidget_MoveLevel_Y->setItem(9,1,new QTableWidgetItem(move_name[pkm_y_move[1][9]]));

        // TM HM names and checkboxes
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

        ui->textEdit_MoveTMHMText->setText(move_tmhm_text[1]);
        ui->textEdit_MoveDescrText->setText(move_description[1]);


        ui->comboBox_HighCH_MovesList_1->setCurrentIndex(move_high_ch[0]);
        ui->comboBox_HighCH_MovesList_2->setCurrentIndex(move_high_ch[1]);
        ui->comboBox_HighCH_MovesList_3->setCurrentIndex(move_high_ch[2]);
        ui->comboBox_HighCH_MovesList_4->setCurrentIndex(move_high_ch[3]);



        // Misc data
        for (short i=0;i<6;i++){
            calc_experience_max();
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
        ui->comboBox_GrowthRate->setCurrentIndex(pkm_growth_rate[1]);

        // Pokédex data
        ui->textEdit_PokedexEntry->setText(pokedex_entry[1]);
        ui->spinBox_Pokedex_Pointer->setValue(pokedex_entry_pointer[1]);

        // Sprites
        img_path = ":/trainer_sprites/";
        img_path += QString::number(0);
        ui->img_TrainerSprite->setPixmap(img_path);

        img_path = ":/pkm_sprites/";
        img_path += QString::number(1);
        ui->label_Pokemon_Sprite->setPixmap(img_path);




        // CPU Team initialization
        for(short i=0;i<current_cpu_trainers_number;i++){
            ui->comboBox_CPU_Trainer->addItem(cpu_tname[i]);
        }
        ui->lineEdit_CPU_TrainerName->setText(cpu_tname[0]);
        ui->spinBox_TrainerSpriteID->setValue(cpu_sprite_id[0]);
        img_path = ":/trainer_sprites/";
        img_path += QString::number(cpu_sprite_id[0]);
        ui->img_TrainerSprite->setPixmap(QPixmap(img_path));
        ui->spinBox_CPU_PartySize->setValue(cpu_party_size[0]);
        ui->spinBox_CPU_AI->setValue(cpu_ai_id[0]);

        ui->comboBox_Pkmn_1->setCurrentIndex(cpu_pkm_id[0][0]);
        ui->comboBox_Pkmn_2->setCurrentIndex(cpu_pkm_id[0][1]);
        ui->comboBox_Pkmn_3->setCurrentIndex(cpu_pkm_id[0][2]);
        ui->comboBox_Pkmn_4->setCurrentIndex(cpu_pkm_id[0][3]);
        ui->comboBox_Pkmn_5->setCurrentIndex(cpu_pkm_id[0][4]);
        ui->comboBox_Pkmn_6->setCurrentIndex(cpu_pkm_id[0][5]);

        ui->lineEdit_Nickname_1->setText(cpu_pkm_nickname[0][0]);
        ui->lineEdit_Nickname_2->setText(cpu_pkm_nickname[0][1]);
        ui->lineEdit_Nickname_3->setText(cpu_pkm_nickname[0][2]);
        ui->lineEdit_Nickname_4->setText(cpu_pkm_nickname[0][3]);
        ui->lineEdit_Nickname_5->setText(cpu_pkm_nickname[0][4]);
        ui->lineEdit_Nickname_6->setText(cpu_pkm_nickname[0][5]);

        ui->spinBox_Lv_1->setValue(cpu_pkm_level[0][0]);
        ui->spinBox_Lv_2->setValue(cpu_pkm_level[0][1]);
        ui->spinBox_Lv_3->setValue(cpu_pkm_level[0][2]);
        ui->spinBox_Lv_4->setValue(cpu_pkm_level[0][3]);
        ui->spinBox_Lv_5->setValue(cpu_pkm_level[0][4]);
        ui->spinBox_Lv_6->setValue(cpu_pkm_level[0][5]);

        ui->spinBox_IV_HP_1->setValue(cpu_pkm_iv_hp[0][0]);
        ui->spinBox_IV_HP_2->setValue(cpu_pkm_iv_hp[0][1]);
        ui->spinBox_IV_HP_3->setValue(cpu_pkm_iv_hp[0][2]);
        ui->spinBox_IV_HP_4->setValue(cpu_pkm_iv_hp[0][3]);
        ui->spinBox_IV_HP_5->setValue(cpu_pkm_iv_hp[0][4]);
        ui->spinBox_IV_HP_6->setValue(cpu_pkm_iv_hp[0][5]);
        ui->spinBox_IV_Attack_1->setValue(cpu_pkm_iv_atk[0][0]);
        ui->spinBox_IV_Attack_2->setValue(cpu_pkm_iv_atk[0][1]);
        ui->spinBox_IV_Attack_3->setValue(cpu_pkm_iv_atk[0][2]);
        ui->spinBox_IV_Attack_4->setValue(cpu_pkm_iv_atk[0][3]);
        ui->spinBox_IV_Attack_5->setValue(cpu_pkm_iv_atk[0][4]);
        ui->spinBox_IV_Attack_6->setValue(cpu_pkm_iv_atk[0][5]);
        ui->spinBox_IV_Defense_1->setValue(cpu_pkm_iv_def[0][0]);
        ui->spinBox_IV_Defense_2->setValue(cpu_pkm_iv_def[0][1]);
        ui->spinBox_IV_Defense_3->setValue(cpu_pkm_iv_def[0][2]);
        ui->spinBox_IV_Defense_4->setValue(cpu_pkm_iv_def[0][3]);
        ui->spinBox_IV_Defense_5->setValue(cpu_pkm_iv_def[0][4]);
        ui->spinBox_IV_Defense_6->setValue(cpu_pkm_iv_def[0][5]);
        ui->spinBox_IV_Special_1->setValue(cpu_pkm_iv_spc[0][0]);
        ui->spinBox_IV_Special_2->setValue(cpu_pkm_iv_spc[0][1]);
        ui->spinBox_IV_Special_3->setValue(cpu_pkm_iv_spc[0][2]);
        ui->spinBox_IV_Special_4->setValue(cpu_pkm_iv_spc[0][3]);
        ui->spinBox_IV_Special_5->setValue(cpu_pkm_iv_spc[0][4]);
        ui->spinBox_IV_Special_6->setValue(cpu_pkm_iv_spc[0][5]);
        ui->spinBox_IV_Speed_1->setValue(cpu_pkm_iv_speed[0][0]);
        ui->spinBox_IV_Speed_2->setValue(cpu_pkm_iv_speed[0][1]);
        ui->spinBox_IV_Speed_3->setValue(cpu_pkm_iv_speed[0][2]);
        ui->spinBox_IV_Speed_4->setValue(cpu_pkm_iv_speed[0][3]);
        ui->spinBox_IV_Speed_5->setValue(cpu_pkm_iv_speed[0][4]);
        ui->spinBox_IV_Speed_6->setValue(cpu_pkm_iv_speed[0][5]);

        ui->spinBox_EV_HP_1->setValue(cpu_pkm_ev_hp[0][0]);
        ui->spinBox_EV_HP_2->setValue(cpu_pkm_ev_hp[0][1]);
        ui->spinBox_EV_HP_3->setValue(cpu_pkm_ev_hp[0][2]);
        ui->spinBox_EV_HP_4->setValue(cpu_pkm_ev_hp[0][3]);
        ui->spinBox_EV_HP_5->setValue(cpu_pkm_ev_hp[0][4]);
        ui->spinBox_EV_HP_6->setValue(cpu_pkm_ev_hp[0][5]);
        ui->spinBox_EV_Attack_1->setValue(cpu_pkm_ev_atk[0][0]);
        ui->spinBox_EV_Attack_2->setValue(cpu_pkm_ev_atk[0][1]);
        ui->spinBox_EV_Attack_3->setValue(cpu_pkm_ev_atk[0][2]);
        ui->spinBox_EV_Attack_4->setValue(cpu_pkm_ev_atk[0][3]);
        ui->spinBox_EV_Attack_5->setValue(cpu_pkm_ev_atk[0][4]);
        ui->spinBox_EV_Attack_6->setValue(cpu_pkm_ev_atk[0][5]);
        ui->spinBox_EV_Defense_1->setValue(cpu_pkm_ev_def[0][0]);
        ui->spinBox_EV_Defense_2->setValue(cpu_pkm_ev_def[0][1]);
        ui->spinBox_EV_Defense_3->setValue(cpu_pkm_ev_def[0][2]);
        ui->spinBox_EV_Defense_4->setValue(cpu_pkm_ev_def[0][3]);
        ui->spinBox_EV_Defense_5->setValue(cpu_pkm_ev_def[0][4]);
        ui->spinBox_EV_Defense_6->setValue(cpu_pkm_ev_def[0][5]);
        ui->spinBox_EV_Special_1->setValue(cpu_pkm_ev_spc[0][0]);
        ui->spinBox_EV_Special_2->setValue(cpu_pkm_ev_spc[0][1]);
        ui->spinBox_EV_Special_3->setValue(cpu_pkm_ev_spc[0][2]);
        ui->spinBox_EV_Special_4->setValue(cpu_pkm_ev_spc[0][3]);
        ui->spinBox_EV_Special_5->setValue(cpu_pkm_ev_spc[0][4]);
        ui->spinBox_EV_Special_6->setValue(cpu_pkm_ev_spc[0][5]);
        ui->spinBox_EV_Speed_1->setValue(cpu_pkm_ev_speed[0][0]);
        ui->spinBox_EV_Speed_2->setValue(cpu_pkm_ev_speed[0][1]);
        ui->spinBox_EV_Speed_3->setValue(cpu_pkm_ev_speed[0][2]);
        ui->spinBox_EV_Speed_4->setValue(cpu_pkm_ev_speed[0][3]);
        ui->spinBox_EV_Speed_5->setValue(cpu_pkm_ev_speed[0][4]);
        ui->spinBox_EV_Speed_6->setValue(cpu_pkm_ev_speed[0][5]);

        ui->comboBox_Move1_1->setCurrentIndex(cpu_pkm_move_1[0][0]);
        ui->comboBox_Move2_1->setCurrentIndex(cpu_pkm_move_2[0][0]);
        ui->comboBox_Move3_1->setCurrentIndex(cpu_pkm_move_3[0][0]);
        ui->comboBox_Move4_1->setCurrentIndex(cpu_pkm_move_4[0][0]);
        ui->comboBox_Move1_2->setCurrentIndex(cpu_pkm_move_1[0][1]);
        ui->comboBox_Move2_2->setCurrentIndex(cpu_pkm_move_2[0][1]);
        ui->comboBox_Move3_2->setCurrentIndex(cpu_pkm_move_3[0][1]);
        ui->comboBox_Move4_2->setCurrentIndex(cpu_pkm_move_4[0][1]);
        ui->comboBox_Move1_3->setCurrentIndex(cpu_pkm_move_1[0][2]);
        ui->comboBox_Move2_3->setCurrentIndex(cpu_pkm_move_2[0][2]);
        ui->comboBox_Move3_3->setCurrentIndex(cpu_pkm_move_3[0][2]);
        ui->comboBox_Move4_3->setCurrentIndex(cpu_pkm_move_4[0][2]);
        ui->comboBox_Move1_4->setCurrentIndex(cpu_pkm_move_1[0][3]);
        ui->comboBox_Move2_4->setCurrentIndex(cpu_pkm_move_2[0][3]);
        ui->comboBox_Move3_4->setCurrentIndex(cpu_pkm_move_3[0][3]);
        ui->comboBox_Move4_4->setCurrentIndex(cpu_pkm_move_4[0][3]);
        ui->comboBox_Move1_5->setCurrentIndex(cpu_pkm_move_1[0][4]);
        ui->comboBox_Move2_5->setCurrentIndex(cpu_pkm_move_2[0][4]);
        ui->comboBox_Move3_5->setCurrentIndex(cpu_pkm_move_3[0][4]);
        ui->comboBox_Move4_5->setCurrentIndex(cpu_pkm_move_4[0][4]);
        ui->comboBox_Move1_6->setCurrentIndex(cpu_pkm_move_1[0][5]);
        ui->comboBox_Move2_6->setCurrentIndex(cpu_pkm_move_2[0][5]);
        ui->comboBox_Move3_6->setCurrentIndex(cpu_pkm_move_3[0][5]);
        ui->comboBox_Move4_6->setCurrentIndex(cpu_pkm_move_4[0][5]);

        ui->spinBox_PPUp1_1->setValue(cpu_pkm_ppup_1[0][0]);
        ui->spinBox_PPUp2_1->setValue(cpu_pkm_ppup_2[0][0]);
        ui->spinBox_PPUp3_1->setValue(cpu_pkm_ppup_3[0][0]);
        ui->spinBox_PPUp4_1->setValue(cpu_pkm_ppup_4[0][0]);
        ui->spinBox_PPUp1_2->setValue(cpu_pkm_ppup_1[0][1]);
        ui->spinBox_PPUp2_2->setValue(cpu_pkm_ppup_2[0][1]);
        ui->spinBox_PPUp3_2->setValue(cpu_pkm_ppup_3[0][1]);
        ui->spinBox_PPUp4_2->setValue(cpu_pkm_ppup_4[0][1]);
        ui->spinBox_PPUp1_3->setValue(cpu_pkm_ppup_1[0][2]);
        ui->spinBox_PPUp2_3->setValue(cpu_pkm_ppup_2[0][2]);
        ui->spinBox_PPUp3_3->setValue(cpu_pkm_ppup_3[0][2]);
        ui->spinBox_PPUp4_3->setValue(cpu_pkm_ppup_4[0][2]);
        ui->spinBox_PPUp1_4->setValue(cpu_pkm_ppup_1[0][3]);
        ui->spinBox_PPUp2_4->setValue(cpu_pkm_ppup_2[0][3]);
        ui->spinBox_PPUp3_4->setValue(cpu_pkm_ppup_3[0][3]);
        ui->spinBox_PPUp4_4->setValue(cpu_pkm_ppup_4[0][3]);
        ui->spinBox_PPUp1_5->setValue(cpu_pkm_ppup_1[0][4]);
        ui->spinBox_PPUp2_5->setValue(cpu_pkm_ppup_2[0][4]);
        ui->spinBox_PPUp3_5->setValue(cpu_pkm_ppup_3[0][4]);
        ui->spinBox_PPUp4_5->setValue(cpu_pkm_ppup_4[0][4]);
        ui->spinBox_PPUp1_6->setValue(cpu_pkm_ppup_1[0][5]);
        ui->spinBox_PPUp2_6->setValue(cpu_pkm_ppup_2[0][5]);
        ui->spinBox_PPUp3_6->setValue(cpu_pkm_ppup_3[0][5]);
        ui->spinBox_PPUp4_6->setValue(cpu_pkm_ppup_4[0][5]);
    }
}
