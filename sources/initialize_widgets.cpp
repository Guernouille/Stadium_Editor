#include <QHBoxLayout>
#include "mainwindow.h"
#include "hexqspinbox.h"

void MainWindow::initialize_widgets()
{
    not_in_init = false;
    ui->tabWidget->setEnabled(false);
    ui->actionSave->setEnabled(false);
    // Clear widgets

    ui->comboBox_Pkmn_1->clear();
    ui->comboBox_Pkmn_2->clear();
    ui->comboBox_Pkmn_3->clear();
    ui->comboBox_Pkmn_4->clear();
    ui->comboBox_Pkmn_5->clear();
    ui->comboBox_Pkmn_6->clear();
    ui->comboBox_PokemonSpecies->clear();

    ui->comboBox_Rental_Pkmn_1->clear();
    ui->comboBox_Rental_Pkmn_2->clear();
    ui->comboBox_Rental_Pkmn_3->clear();
    ui->comboBox_Rental_Pkmn_4->clear();
    ui->comboBox_Rental_Pkmn_5->clear();
    ui->comboBox_Rental_Pkmn_6->clear();

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

    ui->comboBox_Rental_Move1_1->clear();
    ui->comboBox_Rental_Move2_1->clear();
    ui->comboBox_Rental_Move3_1->clear();
    ui->comboBox_Rental_Move4_1->clear();
    ui->comboBox_Rental_Move1_2->clear();
    ui->comboBox_Rental_Move2_2->clear();
    ui->comboBox_Rental_Move3_2->clear();
    ui->comboBox_Rental_Move4_2->clear();
    ui->comboBox_Rental_Move1_3->clear();
    ui->comboBox_Rental_Move2_3->clear();
    ui->comboBox_Rental_Move3_3->clear();
    ui->comboBox_Rental_Move4_3->clear();
    ui->comboBox_Rental_Move1_4->clear();
    ui->comboBox_Rental_Move2_4->clear();
    ui->comboBox_Rental_Move3_4->clear();
    ui->comboBox_Rental_Move4_4->clear();
    ui->comboBox_Rental_Move1_5->clear();
    ui->comboBox_Rental_Move2_5->clear();
    ui->comboBox_Rental_Move3_5->clear();
    ui->comboBox_Rental_Move4_5->clear();
    ui->comboBox_Rental_Move1_6->clear();
    ui->comboBox_Rental_Move2_6->clear();
    ui->comboBox_Rental_Move3_6->clear();
    ui->comboBox_Rental_Move4_6->clear();

    ui->comboBox_MovesList->clear();
    ui->comboBox_HighCH_MovesList_1->clear();
    ui->comboBox_HighCH_MovesList_2->clear();
    ui->comboBox_HighCH_MovesList_3->clear();
    ui->comboBox_HighCH_MovesList_4->clear();
    ui->spinBox_HighCH_shiftvalue->setValue(0);

    ui->comboBox_Pokemon_Type_1->clear();
    ui->comboBox_Pokemon_Type_2->clear();
    ui->comboBox_MoveType->clear();


    ui->comboBox_Type1_1->clear();
    ui->comboBox_Type1_2->clear();
    ui->comboBox_Type1_3->clear();
    ui->comboBox_Type1_4->clear();
    ui->comboBox_Type1_5->clear();
    ui->comboBox_Type1_6->clear();
    ui->comboBox_Type1_7->clear();
    ui->comboBox_Type1_8->clear();
    ui->comboBox_Type1_9->clear();
    ui->comboBox_Type1_10->clear();
    ui->comboBox_Type1_11->clear();
    ui->comboBox_Type1_12->clear();
    ui->comboBox_Type1_13->clear();
    ui->comboBox_Type1_14->clear();
    ui->comboBox_Type1_15->clear();
    ui->comboBox_Type1_16->clear();
    ui->comboBox_Type1_17->clear();
    ui->comboBox_Type1_18->clear();
    ui->comboBox_Type1_19->clear();
    ui->comboBox_Type1_20->clear();
    ui->comboBox_Type1_21->clear();
    ui->comboBox_Type1_22->clear();
    ui->comboBox_Type1_23->clear();
    ui->comboBox_Type1_24->clear();
    ui->comboBox_Type1_25->clear();
    ui->comboBox_Type1_26->clear();
    ui->comboBox_Type1_27->clear();
    ui->comboBox_Type1_28->clear();
    ui->comboBox_Type1_29->clear();
    ui->comboBox_Type1_30->clear();
    ui->comboBox_Type1_31->clear();
    ui->comboBox_Type1_32->clear();
    ui->comboBox_Type1_33->clear();
    ui->comboBox_Type1_34->clear();
    ui->comboBox_Type1_35->clear();
    ui->comboBox_Type1_36->clear();
    ui->comboBox_Type1_37->clear();
    ui->comboBox_Type1_38->clear();
    ui->comboBox_Type1_39->clear();
    ui->comboBox_Type1_40->clear();
    ui->comboBox_Type1_41->clear();
    ui->comboBox_Type1_42->clear();
    ui->comboBox_Type1_43->clear();
    ui->comboBox_Type1_44->clear();
    ui->comboBox_Type1_45->clear();
    ui->comboBox_Type1_46->clear();
    ui->comboBox_Type1_47->clear();
    ui->comboBox_Type1_48->clear();
    ui->comboBox_Type1_49->clear();
    ui->comboBox_Type1_50->clear();
    ui->comboBox_Type1_51->clear();
    ui->comboBox_Type1_52->clear();
    ui->comboBox_Type1_53->clear();
    ui->comboBox_Type1_54->clear();
    ui->comboBox_Type1_55->clear();
    ui->comboBox_Type1_56->clear();
    ui->comboBox_Type1_57->clear();
    ui->comboBox_Type1_58->clear();
    ui->comboBox_Type1_59->clear();
    ui->comboBox_Type1_60->clear();
    ui->comboBox_Type1_61->clear();
    ui->comboBox_Type1_62->clear();
    ui->comboBox_Type1_63->clear();
    ui->comboBox_Type1_64->clear();
    ui->comboBox_Type1_65->clear();
    ui->comboBox_Type1_66->clear();
    ui->comboBox_Type1_67->clear();
    ui->comboBox_Type1_68->clear();
    ui->comboBox_Type1_69->clear();
    ui->comboBox_Type1_70->clear();
    ui->comboBox_Type1_71->clear();
    ui->comboBox_Type1_72->clear();
    ui->comboBox_Type1_73->clear();
    ui->comboBox_Type1_74->clear();
    ui->comboBox_Type1_75->clear();
    ui->comboBox_Type1_76->clear();
    ui->comboBox_Type1_77->clear();
    ui->comboBox_Type1_78->clear();
    ui->comboBox_Type1_79->clear();
    ui->comboBox_Type1_80->clear();
    ui->comboBox_Type1_81->clear();
    ui->comboBox_Type1_82->clear();

    ui->comboBox_Type2_1->clear();
    ui->comboBox_Type2_2->clear();
    ui->comboBox_Type2_3->clear();
    ui->comboBox_Type2_4->clear();
    ui->comboBox_Type2_5->clear();
    ui->comboBox_Type2_6->clear();
    ui->comboBox_Type2_7->clear();
    ui->comboBox_Type2_8->clear();
    ui->comboBox_Type2_9->clear();
    ui->comboBox_Type2_10->clear();
    ui->comboBox_Type2_11->clear();
    ui->comboBox_Type2_12->clear();
    ui->comboBox_Type2_13->clear();
    ui->comboBox_Type2_14->clear();
    ui->comboBox_Type2_15->clear();
    ui->comboBox_Type2_16->clear();
    ui->comboBox_Type2_17->clear();
    ui->comboBox_Type2_18->clear();
    ui->comboBox_Type2_19->clear();
    ui->comboBox_Type2_20->clear();
    ui->comboBox_Type2_21->clear();
    ui->comboBox_Type2_22->clear();
    ui->comboBox_Type2_23->clear();
    ui->comboBox_Type2_24->clear();
    ui->comboBox_Type2_25->clear();
    ui->comboBox_Type2_26->clear();
    ui->comboBox_Type2_27->clear();
    ui->comboBox_Type2_28->clear();
    ui->comboBox_Type2_29->clear();
    ui->comboBox_Type2_30->clear();
    ui->comboBox_Type2_31->clear();
    ui->comboBox_Type2_32->clear();
    ui->comboBox_Type2_33->clear();
    ui->comboBox_Type2_34->clear();
    ui->comboBox_Type2_35->clear();
    ui->comboBox_Type2_36->clear();
    ui->comboBox_Type2_37->clear();
    ui->comboBox_Type2_38->clear();
    ui->comboBox_Type2_39->clear();
    ui->comboBox_Type2_40->clear();
    ui->comboBox_Type2_41->clear();
    ui->comboBox_Type2_42->clear();
    ui->comboBox_Type2_43->clear();
    ui->comboBox_Type2_44->clear();
    ui->comboBox_Type2_45->clear();
    ui->comboBox_Type2_46->clear();
    ui->comboBox_Type2_47->clear();
    ui->comboBox_Type2_48->clear();
    ui->comboBox_Type2_49->clear();
    ui->comboBox_Type2_50->clear();
    ui->comboBox_Type2_51->clear();
    ui->comboBox_Type2_52->clear();
    ui->comboBox_Type2_53->clear();
    ui->comboBox_Type2_54->clear();
    ui->comboBox_Type2_55->clear();
    ui->comboBox_Type2_56->clear();
    ui->comboBox_Type2_57->clear();
    ui->comboBox_Type2_58->clear();
    ui->comboBox_Type2_59->clear();
    ui->comboBox_Type2_60->clear();
    ui->comboBox_Type2_61->clear();
    ui->comboBox_Type2_62->clear();
    ui->comboBox_Type2_63->clear();
    ui->comboBox_Type2_64->clear();
    ui->comboBox_Type2_65->clear();
    ui->comboBox_Type2_66->clear();
    ui->comboBox_Type2_67->clear();
    ui->comboBox_Type2_68->clear();
    ui->comboBox_Type2_69->clear();
    ui->comboBox_Type2_70->clear();
    ui->comboBox_Type2_71->clear();
    ui->comboBox_Type2_72->clear();
    ui->comboBox_Type2_73->clear();
    ui->comboBox_Type2_74->clear();
    ui->comboBox_Type2_75->clear();
    ui->comboBox_Type2_76->clear();
    ui->comboBox_Type2_77->clear();
    ui->comboBox_Type2_78->clear();
    ui->comboBox_Type2_79->clear();
    ui->comboBox_Type2_80->clear();
    ui->comboBox_Type2_81->clear();
    ui->comboBox_Type2_82->clear();

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

    ui->spinBox_CH_formula_add->setValue(76);
    ui->spinBox_FE_CH_formula_add_1->setValue(76);
    ui->spinBox_FE_CH_formula_add_2->setValue(160);

    ui->comboBox_Status_Burn_shift->setCurrentIndex(1);
    ui->spinBox_Status_Burn_shiftvalue->setValue(1);
    ui->spinBox_DamageVariance_1->setValue(217);
    ui->spinBox_Status_Paralysis_probability->setValue(63);

    ui->textEdit_MoveTMHMText->clear();
    ui->textEdit_MoveDescrText->clear();


    // If the ROM is valid, populate the widgets
    if(this->romtype != INVALID){
        ui->tabWidget->setEnabled(true);
        ui->actionSave->setEnabled(true);

        /* Randomizer */

        /* CPU Trainers */
        ui->comboBox_CPU_Trainer->clear();

        // Pokémon
        ui->comboBox_Pkmn_1->addItem("-");
        ui->comboBox_Pkmn_2->addItem("-");
        ui->comboBox_Pkmn_3->addItem("-");
        ui->comboBox_Pkmn_4->addItem("-");
        ui->comboBox_Pkmn_5->addItem("-");
        ui->comboBox_Pkmn_6->addItem("-");
        ui->comboBox_Rental_Pkmn_1->addItem("-");
        ui->comboBox_Rental_Pkmn_2->addItem("-");
        ui->comboBox_Rental_Pkmn_3->addItem("-");
        ui->comboBox_Rental_Pkmn_4->addItem("-");
        ui->comboBox_Rental_Pkmn_5->addItem("-");
        ui->comboBox_Rental_Pkmn_6->addItem("-");

        for (short i=1;i<=total_pkm_name;i++){
            ui->comboBox_Pkmn_1->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_2->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_3->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_4->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_5->addItem(pkm_name[i]);
            ui->comboBox_Pkmn_6->addItem(pkm_name[i]);
            ui->comboBox_Rental_Pkmn_1->addItem(pkm_name[i]);
            ui->comboBox_Rental_Pkmn_2->addItem(pkm_name[i]);
            ui->comboBox_Rental_Pkmn_3->addItem(pkm_name[i]);
            ui->comboBox_Rental_Pkmn_4->addItem(pkm_name[i]);
            ui->comboBox_Rental_Pkmn_5->addItem(pkm_name[i]);
            ui->comboBox_Rental_Pkmn_6->addItem(pkm_name[i]);
            ui->comboBox_PokemonSpecies->addItem(pkm_name[i]);
        }


        // Types
        for (short i=0;i<total_type_name;i++){
            ui->comboBox_Pokemon_Type_1->addItem(type_name[i]);
            ui->comboBox_Pokemon_Type_2->addItem(type_name[i]);
            ui->comboBox_MoveType->addItem(type_name[i]);

            ui->comboBox_Type1_1->addItem(type_name[i]);
            ui->comboBox_Type1_2->addItem(type_name[i]);
            ui->comboBox_Type1_3->addItem(type_name[i]);
            ui->comboBox_Type1_4->addItem(type_name[i]);
            ui->comboBox_Type1_5->addItem(type_name[i]);
            ui->comboBox_Type1_6->addItem(type_name[i]);
            ui->comboBox_Type1_7->addItem(type_name[i]);
            ui->comboBox_Type1_8->addItem(type_name[i]);
            ui->comboBox_Type1_9->addItem(type_name[i]);
            ui->comboBox_Type1_10->addItem(type_name[i]);
            ui->comboBox_Type1_11->addItem(type_name[i]);
            ui->comboBox_Type1_12->addItem(type_name[i]);
            ui->comboBox_Type1_13->addItem(type_name[i]);
            ui->comboBox_Type1_14->addItem(type_name[i]);
            ui->comboBox_Type1_15->addItem(type_name[i]);
            ui->comboBox_Type1_16->addItem(type_name[i]);
            ui->comboBox_Type1_17->addItem(type_name[i]);
            ui->comboBox_Type1_18->addItem(type_name[i]);
            ui->comboBox_Type1_19->addItem(type_name[i]);
            ui->comboBox_Type1_20->addItem(type_name[i]);
            ui->comboBox_Type1_21->addItem(type_name[i]);
            ui->comboBox_Type1_22->addItem(type_name[i]);
            ui->comboBox_Type1_23->addItem(type_name[i]);
            ui->comboBox_Type1_24->addItem(type_name[i]);
            ui->comboBox_Type1_25->addItem(type_name[i]);
            ui->comboBox_Type1_26->addItem(type_name[i]);
            ui->comboBox_Type1_27->addItem(type_name[i]);
            ui->comboBox_Type1_28->addItem(type_name[i]);
            ui->comboBox_Type1_29->addItem(type_name[i]);
            ui->comboBox_Type1_30->addItem(type_name[i]);
            ui->comboBox_Type1_31->addItem(type_name[i]);
            ui->comboBox_Type1_32->addItem(type_name[i]);
            ui->comboBox_Type1_33->addItem(type_name[i]);
            ui->comboBox_Type1_34->addItem(type_name[i]);
            ui->comboBox_Type1_35->addItem(type_name[i]);
            ui->comboBox_Type1_36->addItem(type_name[i]);
            ui->comboBox_Type1_37->addItem(type_name[i]);
            ui->comboBox_Type1_38->addItem(type_name[i]);
            ui->comboBox_Type1_39->addItem(type_name[i]);
            ui->comboBox_Type1_40->addItem(type_name[i]);
            ui->comboBox_Type1_41->addItem(type_name[i]);
            ui->comboBox_Type1_42->addItem(type_name[i]);
            ui->comboBox_Type1_43->addItem(type_name[i]);
            ui->comboBox_Type1_44->addItem(type_name[i]);
            ui->comboBox_Type1_45->addItem(type_name[i]);
            ui->comboBox_Type1_46->addItem(type_name[i]);
            ui->comboBox_Type1_47->addItem(type_name[i]);
            ui->comboBox_Type1_48->addItem(type_name[i]);
            ui->comboBox_Type1_49->addItem(type_name[i]);
            ui->comboBox_Type1_50->addItem(type_name[i]);
            ui->comboBox_Type1_51->addItem(type_name[i]);
            ui->comboBox_Type1_52->addItem(type_name[i]);
            ui->comboBox_Type1_53->addItem(type_name[i]);
            ui->comboBox_Type1_54->addItem(type_name[i]);
            ui->comboBox_Type1_55->addItem(type_name[i]);
            ui->comboBox_Type1_56->addItem(type_name[i]);
            ui->comboBox_Type1_57->addItem(type_name[i]);
            ui->comboBox_Type1_58->addItem(type_name[i]);
            ui->comboBox_Type1_59->addItem(type_name[i]);
            ui->comboBox_Type1_60->addItem(type_name[i]);
            ui->comboBox_Type1_61->addItem(type_name[i]);
            ui->comboBox_Type1_62->addItem(type_name[i]);
            ui->comboBox_Type1_63->addItem(type_name[i]);
            ui->comboBox_Type1_64->addItem(type_name[i]);
            ui->comboBox_Type1_65->addItem(type_name[i]);
            ui->comboBox_Type1_66->addItem(type_name[i]);
            ui->comboBox_Type1_67->addItem(type_name[i]);
            ui->comboBox_Type1_68->addItem(type_name[i]);
            ui->comboBox_Type1_69->addItem(type_name[i]);
            ui->comboBox_Type1_70->addItem(type_name[i]);
            ui->comboBox_Type1_71->addItem(type_name[i]);
            ui->comboBox_Type1_72->addItem(type_name[i]);
            ui->comboBox_Type1_73->addItem(type_name[i]);
            ui->comboBox_Type1_74->addItem(type_name[i]);
            ui->comboBox_Type1_75->addItem(type_name[i]);
            ui->comboBox_Type1_76->addItem(type_name[i]);
            ui->comboBox_Type1_77->addItem(type_name[i]);
            ui->comboBox_Type1_78->addItem(type_name[i]);
            ui->comboBox_Type1_79->addItem(type_name[i]);
            ui->comboBox_Type1_80->addItem(type_name[i]);
            ui->comboBox_Type1_81->addItem(type_name[i]);
            ui->comboBox_Type1_82->addItem(type_name[i]);

            ui->comboBox_Type2_1->addItem(type_name[i]);
            ui->comboBox_Type2_2->addItem(type_name[i]);
            ui->comboBox_Type2_3->addItem(type_name[i]);
            ui->comboBox_Type2_4->addItem(type_name[i]);
            ui->comboBox_Type2_5->addItem(type_name[i]);
            ui->comboBox_Type2_6->addItem(type_name[i]);
            ui->comboBox_Type2_7->addItem(type_name[i]);
            ui->comboBox_Type2_8->addItem(type_name[i]);
            ui->comboBox_Type2_9->addItem(type_name[i]);
            ui->comboBox_Type2_10->addItem(type_name[i]);
            ui->comboBox_Type2_11->addItem(type_name[i]);
            ui->comboBox_Type2_12->addItem(type_name[i]);
            ui->comboBox_Type2_13->addItem(type_name[i]);
            ui->comboBox_Type2_14->addItem(type_name[i]);
            ui->comboBox_Type2_15->addItem(type_name[i]);
            ui->comboBox_Type2_16->addItem(type_name[i]);
            ui->comboBox_Type2_17->addItem(type_name[i]);
            ui->comboBox_Type2_18->addItem(type_name[i]);
            ui->comboBox_Type2_19->addItem(type_name[i]);
            ui->comboBox_Type2_20->addItem(type_name[i]);
            ui->comboBox_Type2_21->addItem(type_name[i]);
            ui->comboBox_Type2_22->addItem(type_name[i]);
            ui->comboBox_Type2_23->addItem(type_name[i]);
            ui->comboBox_Type2_24->addItem(type_name[i]);
            ui->comboBox_Type2_25->addItem(type_name[i]);
            ui->comboBox_Type2_26->addItem(type_name[i]);
            ui->comboBox_Type2_27->addItem(type_name[i]);
            ui->comboBox_Type2_28->addItem(type_name[i]);
            ui->comboBox_Type2_29->addItem(type_name[i]);
            ui->comboBox_Type2_30->addItem(type_name[i]);
            ui->comboBox_Type2_31->addItem(type_name[i]);
            ui->comboBox_Type2_32->addItem(type_name[i]);
            ui->comboBox_Type2_33->addItem(type_name[i]);
            ui->comboBox_Type2_34->addItem(type_name[i]);
            ui->comboBox_Type2_35->addItem(type_name[i]);
            ui->comboBox_Type2_36->addItem(type_name[i]);
            ui->comboBox_Type2_37->addItem(type_name[i]);
            ui->comboBox_Type2_38->addItem(type_name[i]);
            ui->comboBox_Type2_39->addItem(type_name[i]);
            ui->comboBox_Type2_40->addItem(type_name[i]);
            ui->comboBox_Type2_41->addItem(type_name[i]);
            ui->comboBox_Type2_42->addItem(type_name[i]);
            ui->comboBox_Type2_43->addItem(type_name[i]);
            ui->comboBox_Type2_44->addItem(type_name[i]);
            ui->comboBox_Type2_45->addItem(type_name[i]);
            ui->comboBox_Type2_46->addItem(type_name[i]);
            ui->comboBox_Type2_47->addItem(type_name[i]);
            ui->comboBox_Type2_48->addItem(type_name[i]);
            ui->comboBox_Type2_49->addItem(type_name[i]);
            ui->comboBox_Type2_50->addItem(type_name[i]);
            ui->comboBox_Type2_51->addItem(type_name[i]);
            ui->comboBox_Type2_52->addItem(type_name[i]);
            ui->comboBox_Type2_53->addItem(type_name[i]);
            ui->comboBox_Type2_54->addItem(type_name[i]);
            ui->comboBox_Type2_55->addItem(type_name[i]);
            ui->comboBox_Type2_56->addItem(type_name[i]);
            ui->comboBox_Type2_57->addItem(type_name[i]);
            ui->comboBox_Type2_58->addItem(type_name[i]);
            ui->comboBox_Type2_59->addItem(type_name[i]);
            ui->comboBox_Type2_60->addItem(type_name[i]);
            ui->comboBox_Type2_61->addItem(type_name[i]);
            ui->comboBox_Type2_62->addItem(type_name[i]);
            ui->comboBox_Type2_63->addItem(type_name[i]);
            ui->comboBox_Type2_64->addItem(type_name[i]);
            ui->comboBox_Type2_65->addItem(type_name[i]);
            ui->comboBox_Type2_66->addItem(type_name[i]);
            ui->comboBox_Type2_67->addItem(type_name[i]);
            ui->comboBox_Type2_68->addItem(type_name[i]);
            ui->comboBox_Type2_69->addItem(type_name[i]);
            ui->comboBox_Type2_70->addItem(type_name[i]);
            ui->comboBox_Type2_71->addItem(type_name[i]);
            ui->comboBox_Type2_72->addItem(type_name[i]);
            ui->comboBox_Type2_73->addItem(type_name[i]);
            ui->comboBox_Type2_74->addItem(type_name[i]);
            ui->comboBox_Type2_75->addItem(type_name[i]);
            ui->comboBox_Type2_76->addItem(type_name[i]);
            ui->comboBox_Type2_77->addItem(type_name[i]);
            ui->comboBox_Type2_78->addItem(type_name[i]);
            ui->comboBox_Type2_79->addItem(type_name[i]);
            ui->comboBox_Type2_80->addItem(type_name[i]);
            ui->comboBox_Type2_81->addItem(type_name[i]);
            ui->comboBox_Type2_82->addItem(type_name[i]);
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

        ui->comboBox_Rental_Move1_1->addItem("-");
        ui->comboBox_Rental_Move2_1->addItem("-");
        ui->comboBox_Rental_Move3_1->addItem("-");
        ui->comboBox_Rental_Move4_1->addItem("-");
        ui->comboBox_Rental_Move1_2->addItem("-");
        ui->comboBox_Rental_Move2_2->addItem("-");
        ui->comboBox_Rental_Move3_2->addItem("-");
        ui->comboBox_Rental_Move4_2->addItem("-");
        ui->comboBox_Rental_Move1_3->addItem("-");
        ui->comboBox_Rental_Move2_3->addItem("-");
        ui->comboBox_Rental_Move3_3->addItem("-");
        ui->comboBox_Rental_Move4_3->addItem("-");
        ui->comboBox_Rental_Move1_4->addItem("-");
        ui->comboBox_Rental_Move2_4->addItem("-");
        ui->comboBox_Rental_Move3_4->addItem("-");
        ui->comboBox_Rental_Move4_4->addItem("-");
        ui->comboBox_Rental_Move1_5->addItem("-");
        ui->comboBox_Rental_Move2_5->addItem("-");
        ui->comboBox_Rental_Move3_5->addItem("-");
        ui->comboBox_Rental_Move4_5->addItem("-");
        ui->comboBox_Rental_Move1_6->addItem("-");
        ui->comboBox_Rental_Move2_6->addItem("-");
        ui->comboBox_Rental_Move3_6->addItem("-");
        ui->comboBox_Rental_Move4_6->addItem("-");

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

            ui->comboBox_Rental_Move1_1->addItem(move_name[i]);
            ui->comboBox_Rental_Move2_1->addItem(move_name[i]);
            ui->comboBox_Rental_Move3_1->addItem(move_name[i]);
            ui->comboBox_Rental_Move4_1->addItem(move_name[i]);
            ui->comboBox_Rental_Move1_2->addItem(move_name[i]);
            ui->comboBox_Rental_Move2_2->addItem(move_name[i]);
            ui->comboBox_Rental_Move3_2->addItem(move_name[i]);
            ui->comboBox_Rental_Move4_2->addItem(move_name[i]);
            ui->comboBox_Rental_Move1_3->addItem(move_name[i]);
            ui->comboBox_Rental_Move2_3->addItem(move_name[i]);
            ui->comboBox_Rental_Move3_3->addItem(move_name[i]);
            ui->comboBox_Rental_Move4_3->addItem(move_name[i]);
            ui->comboBox_Rental_Move1_4->addItem(move_name[i]);
            ui->comboBox_Rental_Move2_4->addItem(move_name[i]);
            ui->comboBox_Rental_Move3_4->addItem(move_name[i]);
            ui->comboBox_Rental_Move4_4->addItem(move_name[i]);
            ui->comboBox_Rental_Move1_5->addItem(move_name[i]);
            ui->comboBox_Rental_Move2_5->addItem(move_name[i]);
            ui->comboBox_Rental_Move3_5->addItem(move_name[i]);
            ui->comboBox_Rental_Move4_5->addItem(move_name[i]);
            ui->comboBox_Rental_Move1_6->addItem(move_name[i]);
            ui->comboBox_Rental_Move2_6->addItem(move_name[i]);
            ui->comboBox_Rental_Move3_6->addItem(move_name[i]);
            ui->comboBox_Rental_Move4_6->addItem(move_name[i]);

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
        ui->comboBox_MoveEffect->setCurrentIndex(move_effect[1]);
        ui->comboBox_MoveType->setCurrentIndex(move_type[1]);


        /* Rental data */
        ui->comboBox_Rental_Page->clear();


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
        ui->comboBox_HighCH_shift->setCurrentIndex(burn_shift);
        ui->spinBox_HighCH_shiftvalue->setValue(burn_shiftvalue);

        // Critical Hit formula
        ui->spinBox_CH_formula_add->setValue(ch_formula_add);
        ui->spinBox_FE_CH_formula_add_1->setValue(ch_formula_add);
        ui->spinBox_FE_CH_formula_add_2->setValue(ch_fe_formula_add);

        //Battle Mechanics
        ui->comboBox_Status_Burn_shift->setCurrentIndex(burn_shift);
        ui->spinBox_Status_Burn_shiftvalue->setValue(burn_shiftvalue);
        ui->spinBox_DamageVariance_1->setValue(damage_variance_min);
        ui->spinBox_Status_Paralysis_probability->setValue(odds_paralysis);

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
        display_cpu_trainer_pkmn(0);


        // Rental initialization
        for(short i=0;i<current_rentals_number;i+=6){
            ui->comboBox_Rental_Page->addItem(QString::number(i+1)+"-"+QString::number(i+6));
        }
        display_rental_pkmn(0);

        // Type Chart
        display_type_chart();
    }
    not_in_init = true;
}

void MainWindow::set_widgets()
{
    ui->checkBox_Randomizer_Rental_NoSpore->setVisible(false);
    ui->tableWidget_MoveLevel_RB->setColumnWidth(0,28);
    ui->tableWidget_MoveLevel_RB->setColumnWidth(1,138);
    ui->tableWidget_MoveLevel_Y->setColumnWidth(0,28);
    ui->tableWidget_MoveLevel_Y->setColumnWidth(1,138);
    ui->tableWidget_MoveTM->setColumnWidth(0,18);
    ui->tableWidget_MoveTM->setColumnWidth(1,130);

    QHeaderView *verticalHeader1 = ui->tableWidget_StartingMoves->verticalHeader();
    QHeaderView *verticalHeader2 = ui->tableWidget_MoveLevel_RB->verticalHeader();
    QHeaderView *verticalHeader3 = ui->tableWidget_MoveLevel_Y->verticalHeader();
    QHeaderView *verticalHeader4 = ui->tableWidget_MoveTM->verticalHeader();
    verticalHeader1->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader1->setDefaultSectionSize(19);
    verticalHeader2->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader2->setDefaultSectionSize(19);
    verticalHeader3->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader3->setDefaultSectionSize(19);
    verticalHeader4->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader4->setDefaultSectionSize(19);

    ui->tableWidget_MoveTM->setRowCount(55);
    ui->tableWidget_MoveTM->setColumnCount(2);
    ui->tableWidget_MoveTM->setHorizontalHeaderItem(1, new QTableWidgetItem("TM HM Moves"));
    ui->tableWidget_MoveTM->verticalHeader()->setVisible(false);

    spinBox_PRNG_Seed_1 = new HexSpinBox(false,ui->groupBox_PRNG_Seeds);
    spinBox_PRNG_Seed_2 = new HexSpinBox(false,ui->groupBox_PRNG_Seeds);
    spinBox_PRNG_Seed_3 = new HexSpinBox(false,ui->groupBox_PRNG_Seeds);
    spinBox_PRNG_Seed_4 = new HexSpinBox(false,ui->groupBox_PRNG_Seeds);
    spinBox_PRNG_Seed_5 = new HexSpinBox(false,ui->groupBox_PRNG_Seeds);
    spinBox_PRNG_Seed_6 = new HexSpinBox(false,ui->groupBox_PRNG_Seeds);
    QVBoxLayout *prng_seeds_layout = new QVBoxLayout;

    prng_seeds_layout->addWidget(spinBox_PRNG_Seed_1);
    prng_seeds_layout->addWidget(spinBox_PRNG_Seed_2);
    prng_seeds_layout->addWidget(spinBox_PRNG_Seed_3);
    prng_seeds_layout->addWidget(spinBox_PRNG_Seed_4);
    prng_seeds_layout->addWidget(spinBox_PRNG_Seed_5);
    prng_seeds_layout->addWidget(spinBox_PRNG_Seed_6);

    spinBox_PRNG_Seed_1->setStyleSheet("font-family:Courier New");
    spinBox_PRNG_Seed_2->setStyleSheet("font-family:Courier New");
    spinBox_PRNG_Seed_3->setStyleSheet("font-family:Courier New");
    spinBox_PRNG_Seed_4->setStyleSheet("font-family:Courier New");
    spinBox_PRNG_Seed_5->setStyleSheet("font-family:Courier New");
    spinBox_PRNG_Seed_6->setStyleSheet("font-family:Courier New");

    ui->groupBox_PRNG_Seeds->setLayout(prng_seeds_layout);

    spinBox_PRNG_Seed_1->setValue(prng_seed[0]);
    spinBox_PRNG_Seed_2->setValue(prng_seed[1]);
    spinBox_PRNG_Seed_3->setValue(prng_seed[2]);
    spinBox_PRNG_Seed_4->setValue(prng_seed[3]);
    spinBox_PRNG_Seed_5->setValue(prng_seed[4]);
    spinBox_PRNG_Seed_6->setValue(prng_seed[5]);

    for(short i=1;i<56;i++){
        //QWidget *move_tmhm_checkbox_widget = new QWidget();
        //QHBoxLayout *move_tmhm_checkbox_layout = new QHBoxLayout();
        //move_tmhm_checkbox_layout->setAlignment(Qt::AlignCenter);
        //move_tmhm_checkbox_layout->setContentsMargins(0,0,0,0);
        //move_tmhm_checkbox_layout->addWidget(new QCheckBox);
        //move_tmhm_checkbox_widget->setLayout(move_tmhm_checkbox_layout);
        ui->tableWidget_MoveTM->setCellWidget(i-1,0, new QCheckBox);
    }
}
