#include "mainwindow.h"

// Max PPs (Rental)
void MainWindow::on_checkBox_Randomizer_Rental_MaxPPUps_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_NoPPUps->setChecked(false);
    }
}

// Min PPs (Rental)
void MainWindow::on_checkBox_Randomizer_Rental_NoPPUps_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_MaxPPUps->setChecked(false);
    }
}


// Randomize
void MainWindow::on_pushButton_Randomize_pressed()
{
    ui->label_rom_randomized->clear();
    prng_seed[0] = spinBox_PRNG_Seed_1->value();
    prng_seed[1] = spinBox_PRNG_Seed_2->value();
    prng_seed[2] = spinBox_PRNG_Seed_3->value();
    prng_seed[3] = spinBox_PRNG_Seed_4->value();
    prng_seed[4] = spinBox_PRNG_Seed_5->value();
    prng_seed[5] = spinBox_PRNG_Seed_6->value();

    std::seed_seq seeds{prng_seed[0], prng_seed[1], prng_seed[2], prng_seed[3], prng_seed[4], prng_seed[5]};
    std::mt19937 mt_rand(seeds);
    mt_rand.discard(700000);

    // Pokémon data
    if(ui->checkBox_PkmnData->isChecked()){
        if(ui->checkBox_Randomize_PkmnData_BS->isChecked()){
            randomize_pkm_base_stats(mt_rand);
        }

        // Update display
        if(not_in_init){
            buf8 = ui->comboBox_PokemonSpecies->currentIndex();
            display_pkm_data(buf8+1);
        }
    }


    // CPU Teams
    if(ui->checkBox_CPUTeams->isChecked()){
        if(ui->checkBox_Randomize_CPU_Sprites->isChecked()){
            randomize_cpu_sprites(mt_rand);
        }

        if(ui->checkBox_Randomize_CPU_Levels->isChecked()){
            randomize_cpu_level(mt_rand);
        }

        if(ui->checkBox_Randomize_CPU_Pkmn->isChecked()){
            randomize_cpu_init_pkmn();
            randomize_cpu_pkmn(mt_rand);
        }

        if(ui->checkBox_Randomize_CPU_Moves->isChecked()){
            randomize_cpu_moves(mt_rand);
        }

        if(ui->checkBox_Randomize_CPU_IVsEVs->isChecked()){
            randomize_cpu_iv_stat_exp(mt_rand);
        }

        if(ui->checkBox_Randomizer_CPU_Names->isChecked()){
            randomize_cpu_nicknames(mt_rand);
            randomize_cpu_trainer_names(mt_rand);
        }

        // Update display
        if(not_in_init){
            display_cpu_trainer_pkmn(ui->comboBox_CPU_Trainer->currentIndex());
        }
    }


    // Rental
    if(ui->checkBox_RentalPkmn->isChecked()){
        if(ui->checkBox_Randomize_Rental_Levels->isChecked()){
            randomize_rental_level(mt_rand);
        }

        if(ui->checkBox_Randomize_Rental_Pkmn->isChecked()){
            randomize_rental_init_pkmn();
            randomize_rental_pkmn(mt_rand);
        }

        if(ui->checkBox_Randomize_Rental_Moves->isChecked()){
            randomize_rental_moves(mt_rand);
        }

        if(ui->checkBox_Randomize_Rental_IVsEVs->isChecked()){
            randomize_rental_iv_stat_exp(mt_rand);
        }

        // Update display
        if(not_in_init){
            display_rental_pkmn((ui->comboBox_Rental_Page->currentIndex())*6);
        }
    }


    // Type chart
    if(ui->checkBox_Randomize_TypeChart->isChecked()){
        randomize_type_chart(mt_rand);
    }
    else{
        if(ui->checkBox_Ghost_vs_Psychic->isChecked()){
            type_chart[75].setType1(0x8);
            type_chart[75].setType2(0x18);
            type_chart[75].setMultiplier(20);
        }
        else{
            type_chart[75].setType1(0x8);
            type_chart[75].setType2(0x18);
            type_chart[75].setMultiplier(0);
        }

        if(ui->checkBox_Ice_vs_Fire->isChecked()){
            type_chart[81].setType1(0x19);
            type_chart[81].setType2(0x14);
            type_chart[81].setMultiplier(5);
        }
        else{
            type_chart[81].setType1(0x1A);
            type_chart[81].setType2(0x1A);
            type_chart[81].setMultiplier(20);
        }

        if(ui->checkBox_Bug_vs_Poison->isChecked()){
            type_chart[67].setType1(0x7);
            type_chart[67].setType2(0x3);
            type_chart[67].setMultiplier(5);
        }
        else{
            type_chart[67].setType1(0x7);
            type_chart[67].setType2(0x3);
            type_chart[67].setMultiplier(20);
        }
    }
    // Update display
    if(not_in_init){
        display_type_chart();
    }


    // New seeds
    if(ui->checkBox_FixedSeeds->isChecked()==false){
        prng_seed[0] = mt_rand();
        prng_seed[1] = mt_rand();
        prng_seed[2] = mt_rand();
        prng_seed[3] = mt_rand();
        prng_seed[4] = mt_rand();
        prng_seed[5] = mt_rand();

        spinBox_PRNG_Seed_1->setValue(prng_seed[0]);
        spinBox_PRNG_Seed_2->setValue(prng_seed[1]);
        spinBox_PRNG_Seed_3->setValue(prng_seed[2]);
        spinBox_PRNG_Seed_4->setValue(prng_seed[3]);
        spinBox_PRNG_Seed_5->setValue(prng_seed[4]);
        spinBox_PRNG_Seed_6->setValue(prng_seed[5]);

        buf8 = mt_rand()%16;
        if(buf8==0) ui->label_rom_randomized->setText("Randomized!");
        else if(buf8==1) ui->label_rom_randomized->setText("Randomized.");
        else if(buf8==2) ui->label_rom_randomized->setText("Randomized~");
        else if(buf8==3) ui->label_rom_randomized->setText("Randomized?");
        else if(buf8==4) ui->label_rom_randomized->setText("Done.");
        else if(buf8==5) ui->label_rom_randomized->setText("Complete.");
        else if(buf8==6) ui->label_rom_randomized->setText("gl hf");
        else if(buf8==7) ui->label_rom_randomized->setText("At your service.");
        else if(buf8==8) ui->label_rom_randomized->setText("Aight.");
        else if(buf8==9) ui->label_rom_randomized->setText("You got it.");
        else if(buf8==10) ui->label_rom_randomized->setText("Mersenne Twistered.");
        else if(buf8==11) ui->label_rom_randomized->setText("~Randomized~");
        else if(buf8==12) ui->label_rom_randomized->setText("Randomized ROM.");
        else if(buf8==13) ui->label_rom_randomized->setText("Good luck!");
        else if(buf8==14) ui->label_rom_randomized->setText("Have fun.");
        else if(buf8==15) ui->label_rom_randomized->setText("Enjoy your ROM!");
    }
    else{
        ui->label_rom_randomized->setText("Fixed randomization.");
    }
}

void MainWindow::on_checkBox_CPUTeams_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_CPU_Pkmn->setEnabled(true);
        ui->checkBox_Randomize_CPU_Moves->setEnabled(true);
        ui->checkBox_Randomize_CPU_Levels->setEnabled(true);
        ui->checkBox_Randomize_CPU_IVsEVs->setEnabled(true);
        ui->checkBox_Randomize_CPU_Sprites->setEnabled(true);
        ui->checkBox_Randomizer_CPU_Names->setEnabled(true);

        ui->checkBox_Randomizer_CPU_NoIllegalMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoUselessMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoWeakMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoDragonRage->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoEvasion->setEnabled(true);
        ui->checkBox_Randomizer_CPU_OffensiveMove->setEnabled(true);
        ui->checkBox_Randomizer_CPU_STABMove->setEnabled(true);
        ui->checkBox_Randomizer_CPU_GamblerMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NFE_IVsEVs->setEnabled(true);
        ui->checkBox_Randomizer_CPU_MaxIVsEVsFinal->setEnabled(true);

        ui->checkBox_Randomizer_CPU_MewPrimeCup->setEnabled(true);
        ui->checkBox_Randomizer_CPU_MewtwoMewtwo->setEnabled(true);
        ui->checkBox_Randomizer_CPU_MewtwoFullParty->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoMewMewtwo->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoUselessPkmn->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoIllegalPkmn->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoSpeciesClause->setEnabled(true);
        ui->checkBox_Randomizer_CPU_FullyEvolved->setEnabled(true);
        ui->checkBox_Randomizer_CPU_GLPkmn->setEnabled(true);
        ui->checkBox_Randomizer_CPU_StrongPkmnFinal->setEnabled(true);

        ui->label_CPU_IVs_range_1->setEnabled(true);
        ui->label_CPU_IVs_range_2->setEnabled(true);
        ui->spinBox_CPU_IVs_min->setEnabled(true);
        ui->spinBox_CPU_IVs_max->setEnabled(true);
        ui->label_CPU_StatExp_range_1->setEnabled(true);
        ui->label_CPU_StatExp_range_2->setEnabled(true);
        ui->spinBox_CPU_StatExp_min->setEnabled(true);
        ui->spinBox_CPU_StatExp_max->setEnabled(true);
    }
    else{
        ui->checkBox_Randomize_CPU_Pkmn->setEnabled(false);
        ui->checkBox_Randomize_CPU_Moves->setEnabled(false);
        ui->checkBox_Randomize_CPU_Levels->setEnabled(false);
        ui->checkBox_Randomize_CPU_IVsEVs->setEnabled(false);
        ui->checkBox_Randomize_CPU_Sprites->setEnabled(false);
        ui->checkBox_Randomizer_CPU_Names->setEnabled(false);

        ui->checkBox_Randomizer_CPU_NoIllegalMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoUselessMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoWeakMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoDragonRage->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoEvasion->setEnabled(false);
        ui->checkBox_Randomizer_CPU_OffensiveMove->setEnabled(false);
        ui->checkBox_Randomizer_CPU_STABMove->setEnabled(false);
        ui->checkBox_Randomizer_CPU_GamblerMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NFE_IVsEVs->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MaxIVsEVsFinal->setEnabled(false);

        ui->checkBox_Randomizer_CPU_MewPrimeCup->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MewtwoMewtwo->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MewtwoFullParty->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoMewMewtwo->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoUselessPkmn->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoIllegalPkmn->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoSpeciesClause->setEnabled(false);
        ui->checkBox_Randomizer_CPU_FullyEvolved->setEnabled(false);
        ui->checkBox_Randomizer_CPU_GLPkmn->setEnabled(false);
        ui->checkBox_Randomizer_CPU_StrongPkmnFinal->setEnabled(false);

        ui->label_CPU_IVs_range_1->setEnabled(false);
        ui->label_CPU_IVs_range_2->setEnabled(false);
        ui->spinBox_CPU_IVs_min->setEnabled(false);
        ui->spinBox_CPU_IVs_max->setEnabled(false);
        ui->label_CPU_StatExp_range_1->setEnabled(false);
        ui->label_CPU_StatExp_range_2->setEnabled(false);
        ui->spinBox_CPU_StatExp_min->setEnabled(false);
        ui->spinBox_CPU_StatExp_max->setEnabled(false);
    }
}
void MainWindow::on_checkBox_MoveData_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_MoveData_Powers->setEnabled(true);
        ui->checkBox_Randomize_MoveData_Types->setEnabled(true);
        ui->checkBox_Randomize_MoveData_Effects->setEnabled(true);
        ui->checkBox_Randomize_MoveData_Accuracy->setEnabled(true);
        ui->checkBox_Randomizer_MoveData_Explosion->setEnabled(true);

        if(ui->checkBox_Randomize_MoveData_Accuracy->isChecked()){
            ui->checkBox_Randomizer_MoveData_PowerAccuracy->setEnabled(true);
            ui->checkBox_Randomizer_MoveData_Sleep->setEnabled(true);
            ui->checkBox_Randomizer_MoveData_Trap->setEnabled(true);
        }
        if(ui->checkBox_Randomize_MoveData_Powers->isChecked()){
            ui->checkBox_Randomizer_MoveData_EffectPower->setEnabled(true);
            ui->label_MoveData_Power_1->setEnabled(true);
            ui->label_MoveData_Power_2->setEnabled(true);
            ui->spinBox_MoveData_minPower->setEnabled(true);
            ui->spinBox_MoveData_maxPower->setEnabled(true);
        }
    }
    else{
        ui->checkBox_Randomize_MoveData_Powers->setEnabled(false);
        ui->checkBox_Randomize_MoveData_Types->setEnabled(false);
        ui->checkBox_Randomize_MoveData_Effects->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_Explosion->setEnabled(false);
        ui->checkBox_Randomize_MoveData_Accuracy->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_PowerAccuracy->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_Sleep->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_Trap->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_EffectPower->setEnabled(false);
        ui->label_MoveData_Power_1->setEnabled(false);
        ui->label_MoveData_Power_2->setEnabled(false);
        ui->spinBox_MoveData_minPower->setEnabled(false);
        ui->spinBox_MoveData_maxPower->setEnabled(false);
    }
}
void MainWindow::on_checkBox_PkmnData_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_PkmnData_BS->setEnabled(true);
        ui->checkBox_Randomize_PkmnData_Types->setEnabled(true);
        ui->checkBox_Randomize_PkmnData_Moves->setEnabled(true);

        if(ui->checkBox_Randomize_PkmnData_BS->isChecked()){
            ui->groupBox_PkmnData_MaxBS->setEnabled(true);
            ui->groupBox_PkmnData_BST->setEnabled(true);
        }
        if(ui->checkBox_Randomize_PkmnData_Moves->isChecked()){
            ui->Randomize_PkmnData_STABmove->setEnabled(true);
        }
    }
    else{
        ui->checkBox_Randomize_PkmnData_BS->setEnabled(false);
        ui->checkBox_Randomize_PkmnData_Types->setEnabled(false);
        ui->checkBox_Randomize_PkmnData_Moves->setEnabled(false);
        ui->Randomize_PkmnData_STABmove->setEnabled(false);
        ui->groupBox_PkmnData_MaxBS->setEnabled(false);
        ui->groupBox_PkmnData_BST->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_CPU_Pkmn_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_CPU_MewPrimeCup->setEnabled(true);
        ui->checkBox_Randomizer_CPU_MewtwoMewtwo->setEnabled(true);
        ui->checkBox_Randomizer_CPU_MewtwoFullParty->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoMewMewtwo->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoUselessPkmn->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoIllegalPkmn->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoSpeciesClause->setEnabled(true);
        ui->checkBox_Randomizer_CPU_FullyEvolved->setEnabled(true);
        ui->checkBox_Randomizer_CPU_GLPkmn->setEnabled(true);
        ui->checkBox_Randomizer_CPU_StrongPkmnFinal->setEnabled(true);
    }
    else{
        ui->checkBox_Randomizer_CPU_MewPrimeCup->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MewtwoMewtwo->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MewtwoFullParty->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MewtwoFullParty->setChecked(false);
        ui->checkBox_Randomizer_CPU_NoMewMewtwo->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoUselessPkmn->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoIllegalPkmn->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoSpeciesClause->setEnabled(false);
        ui->checkBox_Randomizer_CPU_FullyEvolved->setEnabled(false);
        ui->checkBox_Randomizer_CPU_GLPkmn->setEnabled(false);
        ui->checkBox_Randomizer_CPU_GLPkmn->setChecked(false);
        ui->checkBox_Randomizer_CPU_StrongPkmnFinal->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_CPU_Moves_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_CPU_NoIllegalMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoUselessMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoWeakMoves->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoDragonRage->setEnabled(true);
        ui->checkBox_Randomizer_CPU_NoEvasion->setEnabled(true);
        ui->checkBox_Randomizer_CPU_OffensiveMove->setEnabled(true);
        ui->checkBox_Randomizer_CPU_STABMove->setEnabled(true);
        ui->checkBox_Randomizer_CPU_GamblerMoves->setEnabled(true);
    }
    else{
        ui->checkBox_Randomizer_CPU_NoIllegalMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoUselessMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoWeakMoves->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoDragonRage->setEnabled(false);
        ui->checkBox_Randomizer_CPU_NoEvasion->setEnabled(false);
        ui->checkBox_Randomizer_CPU_OffensiveMove->setEnabled(false);
        ui->checkBox_Randomizer_CPU_STABMove->setEnabled(false);
        ui->checkBox_Randomizer_CPU_GamblerMoves->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_CPU_Levels_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->label_Randomizer_GLCLevelRange_1->setEnabled(true);
        ui->label_Randomizer_GLCLevelRange_2->setEnabled(true);
        ui->spinBox_Randomizer_GLCLevelRange_1->setEnabled(true);
        ui->spinBox_Randomizer_GLCLevelRange_2->setEnabled(true);
    }
    else if(ui->checkBox_Randomize_Rental_Levels->isChecked() == false){
        ui->label_Randomizer_GLCLevelRange_1->setEnabled(false);
        ui->label_Randomizer_GLCLevelRange_2->setEnabled(false);
        ui->spinBox_Randomizer_GLCLevelRange_1->setEnabled(false);
        ui->spinBox_Randomizer_GLCLevelRange_2->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_CPU_IVsEVs_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_CPU_NFE_IVsEVs->setEnabled(true);
        ui->checkBox_Randomizer_CPU_MaxIVsEVsFinal->setEnabled(true);
        ui->label_CPU_IVs_range_1->setEnabled(true);
        ui->label_CPU_IVs_range_2->setEnabled(true);
        ui->spinBox_CPU_IVs_min->setEnabled(true);
        ui->spinBox_CPU_IVs_max->setEnabled(true);
        ui->label_CPU_StatExp_range_1->setEnabled(true);
        ui->label_CPU_StatExp_range_2->setEnabled(true);
        ui->spinBox_CPU_StatExp_min->setEnabled(true);
        ui->spinBox_CPU_StatExp_max->setEnabled(true);
    }
    else{
        ui->checkBox_Randomizer_CPU_NFE_IVsEVs->setEnabled(false);
        ui->checkBox_Randomizer_CPU_MaxIVsEVsFinal->setEnabled(false);
        ui->label_CPU_IVs_range_1->setEnabled(false);
        ui->label_CPU_IVs_range_2->setEnabled(false);
        ui->spinBox_CPU_IVs_min->setEnabled(false);
        ui->spinBox_CPU_IVs_max->setEnabled(false);
        ui->label_CPU_StatExp_range_1->setEnabled(false);
        ui->label_CPU_StatExp_range_2->setEnabled(false);
        ui->spinBox_CPU_StatExp_min->setEnabled(false);
        ui->spinBox_CPU_StatExp_max->setEnabled(false);
    }
}

void MainWindow::on_checkBox_Randomize_MoveData_Accuracy_stateChanged(int state)
{
    if(state == Qt::Checked) {
        ui->checkBox_Randomizer_MoveData_PowerAccuracy->setEnabled(true);
        ui->checkBox_Randomizer_MoveData_Sleep->setEnabled(true);
        ui->checkBox_Randomizer_MoveData_Trap->setEnabled(true);
    }
    else {
        ui->checkBox_Randomizer_MoveData_PowerAccuracy->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_Sleep->setEnabled(false);
        ui->checkBox_Randomizer_MoveData_Trap->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_MoveData_Powers_stateChanged(int state)
{
    if(state == Qt::Checked) {
        ui->checkBox_Randomizer_MoveData_EffectPower->setEnabled(true);
        ui->label_MoveData_Power_1->setEnabled(true);
        ui->label_MoveData_Power_2->setEnabled(true);
        ui->spinBox_MoveData_minPower->setEnabled(true);
        ui->spinBox_MoveData_maxPower->setEnabled(true);
    }
    else {
        ui->checkBox_Randomizer_MoveData_EffectPower->setEnabled(false);
        ui->label_MoveData_Power_1->setEnabled(false);
        ui->label_MoveData_Power_2->setEnabled(false);
        ui->spinBox_MoveData_minPower->setEnabled(false);
        ui->spinBox_MoveData_maxPower->setEnabled(false);
    }
}


void MainWindow::on_checkBox_Randomize_PkmnData_BS_stateChanged(int state)
{
    if(state == Qt::Checked) {
        ui->groupBox_PkmnData_MaxBS->setEnabled(true);
        ui->groupBox_PkmnData_BST->setEnabled(true);
    }
    else {
        ui->groupBox_PkmnData_MaxBS->setEnabled(false);
        ui->groupBox_PkmnData_BST->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_PkmnData_Moves_stateChanged(int state)
{
    if(state == Qt::Checked) {
        ui->Randomize_PkmnData_STABmove->setEnabled(true);
    }
    else {
        ui->Randomize_PkmnData_STABmove->setEnabled(false);
    }
}

void MainWindow::on_checkBox_RentalPkmn_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_Rental_Pkmn->setEnabled(true);
        ui->checkBox_Randomize_Rental_Moves->setEnabled(true);
        ui->checkBox_Randomize_Rental_Levels->setEnabled(true);
        ui->checkBox_Randomize_Rental_IVsEVs->setEnabled(true);

        ui->checkBox_Randomizer_Rental_NoIllegalMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoUselessMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoWeakMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoDragonRage->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoEvasion->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoOHKOMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_OffensiveMove->setEnabled(true);
        ui->checkBox_Randomizer_Rental_STABMove->setEnabled(true);

        ui->checkBox_Randomizer_Rental_NoSpore->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoMewMewtwo->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoUselessPkmn->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoIllegalPkmn->setEnabled(true);
        ui->checkBox_Randomizer_Rental_FullyEvolved->setEnabled(true);
        ui->checkBox_Rental_NFE_IVsEVs->setEnabled(true);
        ui->checkBox_Randomizer_Rental_MaxPPUps->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoPPUps->setEnabled(true);

        ui->label_Rental_IVs_range_1->setEnabled(true);
        ui->label_Rental_IVs_range_2->setEnabled(true);
        ui->spinBox_Rental_IVs_min->setEnabled(true);
        ui->spinBox_Rental_IVs_max->setEnabled(true);
        ui->label_Rental_StatExp_range_1->setEnabled(true);
        ui->label_Rental_StatExp_range_2->setEnabled(true);
        ui->spinBox_Rental_StatExp_min->setEnabled(true);
        ui->spinBox_Rental_StatExp_max->setEnabled(true);
    }
    else{
        ui->checkBox_Randomize_Rental_Pkmn->setEnabled(false);
        ui->checkBox_Randomize_Rental_Moves->setEnabled(false);
        ui->checkBox_Randomize_Rental_Levels->setEnabled(false);
        ui->checkBox_Randomize_Rental_IVsEVs->setEnabled(false);

        ui->checkBox_Randomizer_Rental_NoIllegalMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoUselessMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoWeakMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoDragonRage->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoEvasion->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoOHKOMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_OffensiveMove->setEnabled(false);
        ui->checkBox_Randomizer_Rental_STABMove->setEnabled(false);

        ui->checkBox_Randomizer_Rental_NoSpore->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoMewMewtwo->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoUselessPkmn->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoIllegalPkmn->setEnabled(false);
        ui->checkBox_Randomizer_Rental_FullyEvolved->setEnabled(false);
        ui->checkBox_Rental_NFE_IVsEVs->setEnabled(false);
        ui->checkBox_Randomizer_Rental_MaxPPUps->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoPPUps->setEnabled(false);

        ui->label_Rental_IVs_range_1->setEnabled(false);
        ui->label_Rental_IVs_range_2->setEnabled(false);
        ui->spinBox_Rental_IVs_min->setEnabled(false);
        ui->spinBox_Rental_IVs_max->setEnabled(false);
        ui->label_Rental_StatExp_range_1->setEnabled(false);
        ui->label_Rental_StatExp_range_2->setEnabled(false);
        ui->spinBox_Rental_StatExp_min->setEnabled(false);
        ui->spinBox_Rental_StatExp_max->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_Rental_Pkmn_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_NoMewMewtwo->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoUselessPkmn->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoIllegalPkmn->setEnabled(true);
        ui->checkBox_Randomizer_Rental_FullyEvolved->setEnabled(true);
    }
    else{
        ui->checkBox_Randomizer_Rental_NoMewMewtwo->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoUselessPkmn->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoIllegalPkmn->setEnabled(false);
        ui->checkBox_Randomizer_Rental_FullyEvolved->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_Rental_Moves_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_NoIllegalMoves->setEnabled(true);
        if(ui->checkBox_Randomizer_Rental_NoIllegalMoves->isChecked()==false) ui->checkBox_Randomizer_Rental_NoSpore->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoUselessMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoWeakMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoDragonRage->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoEvasion->setEnabled(true);
        ui->checkBox_Randomizer_Rental_NoOHKOMoves->setEnabled(true);
        ui->checkBox_Randomizer_Rental_OffensiveMove->setEnabled(true);
        ui->checkBox_Randomizer_Rental_STABMove->setEnabled(true);
    }
    else{
        ui->checkBox_Randomizer_Rental_NoIllegalMoves->setEnabled(false);
        if(ui->checkBox_Randomizer_Rental_NoIllegalMoves->isChecked()==false) ui->checkBox_Randomizer_Rental_NoSpore->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoUselessMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoWeakMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoDragonRage->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoEvasion->setEnabled(false);
        ui->checkBox_Randomizer_Rental_NoOHKOMoves->setEnabled(false);
        ui->checkBox_Randomizer_Rental_OffensiveMove->setEnabled(false);
        ui->checkBox_Randomizer_Rental_STABMove->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_Rental_Levels_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->label_Randomizer_GLCLevelRange_1->setEnabled(true);
        ui->label_Randomizer_GLCLevelRange_2->setEnabled(true);
        ui->spinBox_Randomizer_GLCLevelRange_1->setEnabled(true);
        ui->spinBox_Randomizer_GLCLevelRange_2->setEnabled(true);
    }
    else if(ui->checkBox_Randomize_CPU_Levels->isChecked() == false){
        ui->label_Randomizer_GLCLevelRange_1->setEnabled(false);
        ui->label_Randomizer_GLCLevelRange_2->setEnabled(false);
        ui->spinBox_Randomizer_GLCLevelRange_1->setEnabled(false);
        ui->spinBox_Randomizer_GLCLevelRange_2->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomize_Rental_IVsEVs_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Rental_NFE_IVsEVs->setEnabled(true);
        ui->label_Rental_IVs_range_1->setEnabled(true);
        ui->label_Rental_IVs_range_2->setEnabled(true);
        ui->spinBox_Rental_IVs_min->setEnabled(true);
        ui->spinBox_Rental_IVs_max->setEnabled(true);
        ui->label_Rental_StatExp_range_1->setEnabled(true);
        ui->label_Rental_StatExp_range_2->setEnabled(true);
        ui->spinBox_Rental_StatExp_min->setEnabled(true);
        ui->spinBox_Rental_StatExp_max->setEnabled(true);
    }
    else{
        ui->checkBox_Rental_NFE_IVsEVs->setEnabled(false);
        ui->label_Rental_IVs_range_1->setEnabled(false);
        ui->label_Rental_IVs_range_2->setEnabled(false);
        ui->spinBox_Rental_IVs_min->setEnabled(false);
        ui->spinBox_Rental_IVs_max->setEnabled(false);
        ui->label_Rental_StatExp_range_1->setEnabled(false);
        ui->label_Rental_StatExp_range_2->setEnabled(false);
        ui->spinBox_Rental_StatExp_min->setEnabled(false);
        ui->spinBox_Rental_StatExp_max->setEnabled(false);
    }
}
void MainWindow::on_checkBox_Randomizer_Rental_NoIllegalMoves_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomizer_Rental_NoSpore->setChecked(false);
        ui->checkBox_Randomizer_Rental_NoSpore->setVisible(false);
    }
    else{
        ui->checkBox_Randomizer_Rental_NoSpore->setVisible(true);
        ui->checkBox_Randomizer_Rental_NoSpore->setChecked(true);
    }

}

// Base Stats range
void MainWindow::on_spinBox_BSmax_HP_valueChanged(int)
{
    if(not_in_init){
        bsmax_hp = ui->spinBox_BSmax_HP->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmax_ATK_valueChanged(int)
{
    if(not_in_init){
        bsmax_atk = ui->spinBox_BSmax_ATK->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmax_DEF_valueChanged(int)
{
    if(not_in_init){
        bsmax_def = ui->spinBox_BSmax_DEF->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmax_SPC_valueChanged(int)
{
    if(not_in_init){
        bsmax_spc = ui->spinBox_BSmax_SPC->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmax_SPEED_valueChanged(int)
{
    if(not_in_init){
        bsmax_speed = ui->spinBox_BSmax_SPEED->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmin_HP_valueChanged(int)
{
    if(not_in_init){
        bsmin_hp = ui->spinBox_BSmin_HP->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmin_ATK_valueChanged(int)
{
    if(not_in_init){
        bsmin_atk = ui->spinBox_BSmin_ATK->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmin_DEF_valueChanged(int)
{
    if(not_in_init){
        bsmin_def = ui->spinBox_BSmin_DEF->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmin_SPC_valueChanged(int)
{
    if(not_in_init){
        bsmin_spc = ui->spinBox_BSmin_SPC->value();
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSmin_SPEED_valueChanged(int)
{
    if(not_in_init){
        bsmin_speed = ui->spinBox_BSmin_SPEED->value();
        refresh_bs_parameters();
    }
}

void MainWindow::on_spinBox_BSTmin_Basic_valueChanged(int)
{
    if(not_in_init){
        bstmin_basic = ui->spinBox_BSTmin_Basic->value();
        if(bstmin_basic > bstmax_basic) {
            bstmax_basic = bstmin_basic;
            ui->spinBox_BSTmax_Basic->setValue(bstmax_basic);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmin_Stage1_valueChanged(int)
{
    if(not_in_init){
        bstmin_stage1 = ui->spinBox_BSTmin_Stage1->value();
        if(bstmin_stage1 > bstmax_stage1) {
            bstmax_stage1 = bstmin_stage1;
            ui->spinBox_BSTmax_Stage1->setValue(bstmax_stage1);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmin_FullyEvolved_valueChanged(int)
{
    if(not_in_init){
        bstmin_fullevo = ui->spinBox_BSTmin_FullyEvolved->value();
        if(bstmin_fullevo > bstmax_fullevo) {
            bstmax_fullevo = bstmin_fullevo;
            ui->spinBox_BSTmax_FullyEvolved->setValue(bstmax_fullevo);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmin_Legend_valueChanged(int)
{
    if(not_in_init){
        bstmin_legend = ui->spinBox_BSTmin_Legend->value();
        if(bstmin_legend > bstmax_legend) {
            bstmax_legend = bstmin_legend;
            ui->spinBox_BSTmax_Legend->setValue(bstmax_legend);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmax_Basic_valueChanged(int)
{
    if(not_in_init){
        bstmax_basic = ui->spinBox_BSTmax_Basic->value();
        if(bstmin_basic > bstmax_basic) {
            bstmin_basic = bstmax_basic;
            ui->spinBox_BSTmin_Basic->setValue(bstmin_basic);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmax_Stage1_valueChanged(int)
{
    if(not_in_init){
        bstmax_stage1 = ui->spinBox_BSTmax_Stage1->value();
        if(bstmin_stage1 > bstmax_stage1) {
            bstmin_stage1 = bstmax_stage1;
            ui->spinBox_BSTmin_Stage1->setValue(bstmin_stage1);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmax_FullyEvolved_valueChanged(int)
{
    if(not_in_init){
        bstmax_fullevo = ui->spinBox_BSTmax_FullyEvolved->value();
        if(bstmin_fullevo > bstmax_fullevo) {
            bstmin_fullevo = bstmax_fullevo;
            ui->spinBox_BSTmin_FullyEvolved->setValue(bstmin_fullevo);
        }
        refresh_bs_parameters();
    }
}
void MainWindow::on_spinBox_BSTmax_Legend_valueChanged(int)
{
    if(not_in_init){
        bstmax_legend = ui->spinBox_BSTmax_Legend->value();
        if(bstmin_legend > bstmax_legend) {
            bstmin_legend = bstmax_legend;
            ui->spinBox_BSTmin_Legend->setValue(bstmin_legend);
        }
        refresh_bs_parameters();
    }
}

// Move Powers range
void MainWindow::on_spinBox_MoveData_minPower_valueChanged(int)
{
    if(not_in_init) {
        moverand_min = ui->spinBox_MoveData_minPower->value();
        if(moverand_min > moverand_max) {
            moverand_max = moverand_min;
            ui->spinBox_MoveData_maxPower->setValue(moverand_max);
        }
    }
}
void MainWindow::on_spinBox_MoveData_maxPower_valueChanged(int)
{
    if(not_in_init) {
        moverand_max = ui->spinBox_MoveData_maxPower->value();
        if(moverand_min > moverand_max) {
            moverand_min = moverand_max;
            ui->spinBox_MoveData_minPower->setValue(moverand_min);
        }
    }
}

// CPU IVs range
void MainWindow::on_spinBox_CPU_IVs_min_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        cpu_ivs_min = ui->spinBox_CPU_IVs_min->value();
        if(cpu_ivs_min > cpu_ivs_max){
            cpu_ivs_max = cpu_ivs_min;
            ui->spinBox_CPU_IVs_max->setValue(cpu_ivs_max);
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_CPU_IVs_max_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        cpu_ivs_max = ui->spinBox_CPU_IVs_max->value();
        if(cpu_ivs_max < cpu_ivs_min){
            cpu_ivs_min = cpu_ivs_max;
            ui->spinBox_CPU_IVs_min->setValue(cpu_ivs_min);
        }
        not_in_init = true;
    }
}
// Rental IVs range
void MainWindow::on_spinBox_Rental_IVs_min_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        rental_ivs_min = ui->spinBox_Rental_IVs_min->value();
        if(rental_ivs_min > rental_ivs_max){
            rental_ivs_max = rental_ivs_min;
            ui->spinBox_Rental_IVs_max->setValue(rental_ivs_max);
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_Rental_IVs_max_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        rental_ivs_max = ui->spinBox_Rental_IVs_max->value();
        if(rental_ivs_max < rental_ivs_min){
            rental_ivs_min = rental_ivs_max;
            ui->spinBox_Rental_IVs_min->setValue(rental_ivs_min);
        }
        not_in_init = true;
    }
}

// CPU Stat Exp range
void MainWindow::on_spinBox_CPU_StatExp_min_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        cpu_stat_exp_min = ui->spinBox_CPU_StatExp_min->value();
        if(cpu_stat_exp_min > cpu_stat_exp_max){
            cpu_stat_exp_max = cpu_stat_exp_min;
            ui->spinBox_CPU_StatExp_max->setValue(cpu_stat_exp_max);
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_CPU_StatExp_max_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        cpu_stat_exp_max = ui->spinBox_CPU_StatExp_max->value();
        if(cpu_stat_exp_max < cpu_stat_exp_min){
            cpu_stat_exp_min = cpu_stat_exp_max;
            ui->spinBox_CPU_StatExp_min->setValue(cpu_stat_exp_min);
        }
        not_in_init = true;
    }
}
// Rental Stat Exp range
void MainWindow::on_spinBox_Rental_StatExp_min_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        rental_stat_exp_min = ui->spinBox_Rental_StatExp_min->value();
        if(rental_stat_exp_min > rental_stat_exp_max){
            rental_stat_exp_max = rental_stat_exp_min;
            ui->spinBox_Rental_StatExp_max->setValue(rental_stat_exp_max);
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_Rental_StatExp_max_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        rental_stat_exp_max = ui->spinBox_Rental_StatExp_max->value();
        if(rental_stat_exp_max < rental_stat_exp_min){
            rental_stat_exp_min = rental_stat_exp_max;
            ui->spinBox_Rental_StatExp_min->setValue(rental_stat_exp_min);
        }
        not_in_init = true;
    }
}


// Full Metronome (CPU)
void MainWindow::on_pushButton_CPU_Metronome_pressed()
{
    for(short i=0;i<256;i++){
        for(short j=0;j<6;j++){
            cpu_pkm_move_1[i][j] = 0x76;
            cpu_pkm_move_2[i][j] = 0x76;
            cpu_pkm_move_3[i][j] = 0x76;
            cpu_pkm_move_4[i][j] = 0x76;
        }
    }
    ui->comboBox_Move1_1->setCurrentIndex(0x76);
    ui->comboBox_Move2_1->setCurrentIndex(0x76);
    ui->comboBox_Move3_1->setCurrentIndex(0x76);
    ui->comboBox_Move4_1->setCurrentIndex(0x76);
    ui->comboBox_Move1_2->setCurrentIndex(0x76);
    ui->comboBox_Move2_2->setCurrentIndex(0x76);
    ui->comboBox_Move3_2->setCurrentIndex(0x76);
    ui->comboBox_Move4_2->setCurrentIndex(0x76);
    ui->comboBox_Move1_3->setCurrentIndex(0x76);
    ui->comboBox_Move2_3->setCurrentIndex(0x76);
    ui->comboBox_Move3_3->setCurrentIndex(0x76);
    ui->comboBox_Move4_3->setCurrentIndex(0x76);
    ui->comboBox_Move1_4->setCurrentIndex(0x76);
    ui->comboBox_Move2_4->setCurrentIndex(0x76);
    ui->comboBox_Move3_4->setCurrentIndex(0x76);
    ui->comboBox_Move4_4->setCurrentIndex(0x76);
    ui->comboBox_Move1_5->setCurrentIndex(0x76);
    ui->comboBox_Move2_5->setCurrentIndex(0x76);
    ui->comboBox_Move3_5->setCurrentIndex(0x76);
    ui->comboBox_Move4_5->setCurrentIndex(0x76);
    ui->comboBox_Move1_6->setCurrentIndex(0x76);
    ui->comboBox_Move2_6->setCurrentIndex(0x76);
    ui->comboBox_Move3_6->setCurrentIndex(0x76);
    ui->comboBox_Move4_6->setCurrentIndex(0x76);
}


// Full Metronome (Rentals)
void MainWindow::on_pushButton_Rental_Metronome_pressed()
{
    for(short i=0;i<1024;i++){
        rental_pkm_move_1[i] = 0x76;
        rental_pkm_move_2[i] = 0x76;
        rental_pkm_move_3[i] = 0x76;
        rental_pkm_move_4[i] = 0x76;
    }

    ui->comboBox_Rental_Move1_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_1->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_2->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_3->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_4->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_5->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move1_6->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move2_6->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move3_6->setCurrentIndex(0x76);
    ui->comboBox_Rental_Move4_6->setCurrentIndex(0x76);
}


// Max EVs IVs (CPU)
void MainWindow::on_pushButton_Maximize_CPU_EVsIVs_pressed()
{
    for(short i=0;i<256;i++){
        for(short j=0;j<6;j++){
            cpu_pkm_ev_hp[i][j] = 0xFFFF;
            cpu_pkm_ev_atk[i][j] = 0xFFFF;
            cpu_pkm_ev_def[i][j] = 0xFFFF;
            cpu_pkm_ev_spc[i][j] = 0xFFFF;
            cpu_pkm_ev_speed[i][j] = 0xFFFF;
            cpu_pkm_ivs[i][j] = 0xFFFF;
            cpu_pkm_iv_hp[i][j] = 0xF;
            cpu_pkm_iv_atk[i][j] = 0xF;
            cpu_pkm_iv_def[i][j] = 0xF;
            cpu_pkm_iv_spc[i][j] = 0xF;
            cpu_pkm_iv_speed[i][j] = 0xF;
        }
    }

    ui->spinBox_EV_HP_1->setValue(0xFFFF);
    ui->spinBox_EV_HP_2->setValue(0xFFFF);
    ui->spinBox_EV_HP_3->setValue(0xFFFF);
    ui->spinBox_EV_HP_4->setValue(0xFFFF);
    ui->spinBox_EV_HP_5->setValue(0xFFFF);
    ui->spinBox_EV_HP_6->setValue(0xFFFF);
    ui->spinBox_EV_Attack_1->setValue(0xFFFF);
    ui->spinBox_EV_Attack_2->setValue(0xFFFF);
    ui->spinBox_EV_Attack_3->setValue(0xFFFF);
    ui->spinBox_EV_Attack_4->setValue(0xFFFF);
    ui->spinBox_EV_Attack_5->setValue(0xFFFF);
    ui->spinBox_EV_Attack_6->setValue(0xFFFF);
    ui->spinBox_EV_Defense_1->setValue(0xFFFF);
    ui->spinBox_EV_Defense_2->setValue(0xFFFF);
    ui->spinBox_EV_Defense_3->setValue(0xFFFF);
    ui->spinBox_EV_Defense_4->setValue(0xFFFF);
    ui->spinBox_EV_Defense_5->setValue(0xFFFF);
    ui->spinBox_EV_Defense_6->setValue(0xFFFF);
    ui->spinBox_EV_Special_1->setValue(0xFFFF);
    ui->spinBox_EV_Special_2->setValue(0xFFFF);
    ui->spinBox_EV_Special_3->setValue(0xFFFF);
    ui->spinBox_EV_Special_4->setValue(0xFFFF);
    ui->spinBox_EV_Special_5->setValue(0xFFFF);
    ui->spinBox_EV_Special_6->setValue(0xFFFF);
    ui->spinBox_EV_Speed_1->setValue(0xFFFF);
    ui->spinBox_EV_Speed_2->setValue(0xFFFF);
    ui->spinBox_EV_Speed_3->setValue(0xFFFF);
    ui->spinBox_EV_Speed_4->setValue(0xFFFF);
    ui->spinBox_EV_Speed_5->setValue(0xFFFF);
    ui->spinBox_EV_Speed_6->setValue(0xFFFF);
    ui->spinBox_IV_HP_1->setValue(0xF);
    ui->spinBox_IV_HP_2->setValue(0xF);
    ui->spinBox_IV_HP_3->setValue(0xF);
    ui->spinBox_IV_HP_4->setValue(0xF);
    ui->spinBox_IV_HP_5->setValue(0xF);
    ui->spinBox_IV_HP_6->setValue(0xF);
    ui->spinBox_IV_Attack_1->setValue(0xF);
    ui->spinBox_IV_Attack_2->setValue(0xF);
    ui->spinBox_IV_Attack_3->setValue(0xF);
    ui->spinBox_IV_Attack_4->setValue(0xF);
    ui->spinBox_IV_Attack_5->setValue(0xF);
    ui->spinBox_IV_Attack_6->setValue(0xF);
    ui->spinBox_IV_Defense_1->setValue(0xF);
    ui->spinBox_IV_Defense_2->setValue(0xF);
    ui->spinBox_IV_Defense_3->setValue(0xF);
    ui->spinBox_IV_Defense_4->setValue(0xF);
    ui->spinBox_IV_Defense_5->setValue(0xF);
    ui->spinBox_IV_Defense_6->setValue(0xF);
    ui->spinBox_IV_Special_1->setValue(0xF);
    ui->spinBox_IV_Special_2->setValue(0xF);
    ui->spinBox_IV_Special_3->setValue(0xF);
    ui->spinBox_IV_Special_4->setValue(0xF);
    ui->spinBox_IV_Special_5->setValue(0xF);
    ui->spinBox_IV_Special_6->setValue(0xF);
    ui->spinBox_IV_Speed_1->setValue(0xF);
    ui->spinBox_IV_Speed_2->setValue(0xF);
    ui->spinBox_IV_Speed_3->setValue(0xF);
    ui->spinBox_IV_Speed_4->setValue(0xF);
    ui->spinBox_IV_Speed_5->setValue(0xF);
    ui->spinBox_IV_Speed_6->setValue(0xF);
}


// Max EVs IVs (Rentals)
void MainWindow::on_pushButton_Maximize_Rental_EVsIVs_pressed()
{
    for(short i=0;i<1024;i++){
        rental_pkm_ev_hp[i] = 0xFFFF;
        rental_pkm_ev_atk[i] = 0xFFFF;
        rental_pkm_ev_def[i] = 0xFFFF;
        rental_pkm_ev_spc[i] = 0xFFFF;
        rental_pkm_ev_speed[i] = 0xFFFF;
        rental_pkm_ivs[i] = 0xFFFF;
        rental_pkm_iv_hp[i] = 0xF;
        rental_pkm_iv_atk[i] = 0xF;
        rental_pkm_iv_def[i] = 0xF;
        rental_pkm_iv_spc[i] = 0xF;
        rental_pkm_iv_speed[i] = 0xF;
    }

    ui->spinBox_Rental_EV_HP_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_HP_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Attack_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Defense_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Special_6->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_1->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_2->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_3->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_4->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_5->setValue(0xFFFF);
    ui->spinBox_Rental_EV_Speed_6->setValue(0xFFFF);
    ui->spinBox_Rental_IV_HP_1->setValue(0xF);
    ui->spinBox_Rental_IV_HP_2->setValue(0xF);
    ui->spinBox_Rental_IV_HP_3->setValue(0xF);
    ui->spinBox_Rental_IV_HP_4->setValue(0xF);
    ui->spinBox_Rental_IV_HP_5->setValue(0xF);
    ui->spinBox_Rental_IV_HP_6->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_1->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_2->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_3->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_4->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_5->setValue(0xF);
    ui->spinBox_Rental_IV_Attack_6->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_1->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_2->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_3->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_4->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_5->setValue(0xF);
    ui->spinBox_Rental_IV_Defense_6->setValue(0xF);
    ui->spinBox_Rental_IV_Special_1->setValue(0xF);
    ui->spinBox_Rental_IV_Special_2->setValue(0xF);
    ui->spinBox_Rental_IV_Special_3->setValue(0xF);
    ui->spinBox_Rental_IV_Special_4->setValue(0xF);
    ui->spinBox_Rental_IV_Special_5->setValue(0xF);
    ui->spinBox_Rental_IV_Special_6->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_1->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_2->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_3->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_4->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_5->setValue(0xF);
    ui->spinBox_Rental_IV_Speed_6->setValue(0xF);
}


// Gym Leader Castle
void MainWindow::on_checkBox_Randomizer_CPU_GLPkmn_stateChanged(int state)
{
    if(not_in_init){
        not_in_init = false;
        if(state == Qt::Checked){
            if(glc_level_min < 10){
                glc_level_min = 10;
                ui->spinBox_Randomizer_GLCLevelRange_1->setValue(glc_level_min);
                if(glc_level_max < glc_level_min){
                    glc_level_max = glc_level_min;
                    ui->spinBox_Randomizer_GLCLevelRange_2->setValue(glc_level_max);
                }
            }
            if(glc_level_max > 78){
                glc_level_max = 78;
                ui->spinBox_Randomizer_GLCLevelRange_2->setValue(glc_level_max);
                if(glc_level_min > glc_level_max){
                    glc_level_min = glc_level_max;
                    ui->spinBox_Randomizer_GLCLevelRange_1->setValue(glc_level_min);
                }
            }
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_Randomizer_GLCLevelRange_1_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        glc_level_min = ui->spinBox_Randomizer_GLCLevelRange_1->value();
        if(glc_level_min > glc_level_max){
            glc_level_max = glc_level_min;
            ui->spinBox_Randomizer_GLCLevelRange_2->setValue(glc_level_max);
        }
        if(glc_level_max > 78){
            ui->checkBox_Randomizer_CPU_GLPkmn->setChecked(false);
        }
        not_in_init = true;
    }
}
void MainWindow::on_spinBox_Randomizer_GLCLevelRange_2_valueChanged(int)
{
    if(not_in_init){
        not_in_init = false;
        glc_level_max = ui->spinBox_Randomizer_GLCLevelRange_2->value();
        if(glc_level_max < glc_level_min){
            glc_level_min = glc_level_max;
            ui->spinBox_Randomizer_GLCLevelRange_1->setValue(glc_level_min);
        }
        if(glc_level_max > 78){
            ui->checkBox_Randomizer_CPU_GLPkmn->setChecked(false);
        }
        not_in_init = true;
    }
}


// Type chart
void MainWindow::on_checkBox_Ghost_vs_Psychic_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_TypeChart->setChecked(false);
    }
}
void MainWindow::on_checkBox_Ice_vs_Fire_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_TypeChart->setChecked(false);
    }
}
void MainWindow::on_checkBox_Bug_vs_Poison_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Randomize_TypeChart->setChecked(false);
    }
}
void MainWindow::on_checkBox_Randomize_TypeChart_stateChanged(int state)
{
    if(state == Qt::Checked){
        ui->checkBox_Ghost_vs_Psychic->setChecked(false);
        ui->checkBox_Ice_vs_Fire->setChecked(false);
        ui->checkBox_Bug_vs_Poison->setChecked(false);
    }
}
