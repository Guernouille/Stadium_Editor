#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_moves_tmhm(std::mt19937 &mt_rand)
{
    if(total_move_name > 55) {
        // Initialize randomized moves vector
        std::vector<quint8> vec_randomized_tmhms;
        bool noSpore = ui->Randomize_PkmnData_NoSpore->isChecked();
        bool noAmnesia = ui->Randomize_PkmnData_NoAmnesia->isChecked();
        bool noRecover = ui->Randomize_PkmnData_NoRecover->isChecked();

        for(uint8_t i=1; i<total_move_name; i++) {
            // Remove banned moves if options are checked
            if((noSpore==false || move_effect[i]!=0x20 || move_accuracy[i]<=0xBF) &&
               (noAmnesia==false || move_effect[i]!=0x35) &&
               (noRecover==false || move_effect[i]!=0x38)){
                vec_randomized_tmhms.push_back(i);
            }
        }

        if(vec_randomized_tmhms.size()>55){
            // Shuffle moves vector
            std::shuffle(vec_randomized_tmhms.begin(), vec_randomized_tmhms.end(), mt_rand);

            // Randomize TM/HM moves
            for(uint8_t i=1; i<56; i++) {
                move_tmhm[i] = vec_randomized_tmhms[i];
            }
        }
    }
}
