#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_type_chart(std::mt19937 &mt_rand){
    std::vector<quint8> type_matchup_vector(225);
    std::iota(type_matchup_vector.begin(), type_matchup_vector.end(), 0);
    std::shuffle(type_matchup_vector.begin(), type_matchup_vector.end(), mt_rand);

    for(short i=0;i<82;i++){
        buf8 = type_matchup_vector[i] / 15;
        if(buf8 >= 6){
            buf8++;
        }
        if(buf8 >= 9){
            buf8 += 11;
        }
        type_chart[i].setType1(buf8);

        buf8 = type_matchup_vector[i] % 15;
        if(buf8 >= 6){
            buf8++;
        }
        if(buf8 >= 9){
            buf8 += 11;
        }
        type_chart[i].setType2(buf8);

        buf8 = mt_rand();
        if(buf8%14 == 0){
            type_chart[i].setMultiplier(0);
        }
        else if(buf8%2 == 0){
            type_chart[i].setMultiplier(5);
        }
        else{
            type_chart[i].setMultiplier(20);
        }
    }
}
