#include "mainwindow.h"
#include <algorithm>
#include <random>

void MainWindow::randomize_rental_level(std::mt19937 &mt_rand)
{
    // PRNG
    mt_rand.discard(700000);

    bool min_lv_rolled_petitcup = false;
    bool min_lv_rolled_pikacup = false;
    bool min_lv_rolled_pokecup = false;
    quint8 min_lv_petitcup_pkm = 0;
    quint8 min_lv_pikacup_pkm = 0;
    quint8 min_lv_pokecup_pkm = 0;

    if(rental_cup_offset[1]>2){
        std::uniform_int_distribution<> min_lv_petitcup(0,(rental_cup_offset[1]-1));
        min_lv_petitcup_pkm = min_lv_petitcup(mt_rand);
    }
    if((rental_cup_offset[2]-rental_cup_offset[1])>2){
        std::uniform_int_distribution<> min_lv_pikacup(rental_cup_offset[1],(rental_cup_offset[2]-1));
        min_lv_pikacup_pkm = min_lv_pikacup(mt_rand);
    }
    if((rental_cup_offset[4]-rental_cup_offset[3])>2){
        std::uniform_int_distribution<> min_lv_pokecup(rental_cup_offset[3],(rental_cup_offset[4]-1));
        min_lv_pokecup_pkm = min_lv_pokecup(mt_rand);
    }

    // Rental Levels generation
    for(short rental_id=0;rental_id<current_rentals_number;rental_id++){
        // Petit Cup: Lv 25 to Lv 30
        if(rental_cup_id[rental_id]==0){
            if(rental_id == min_lv_petitcup_pkm || (rental_id==(rental_cup_offset[1]-1) && min_lv_rolled_petitcup==false)){
                rental_pkm_level[rental_id]=25;
            }
            else{
                std::uniform_int_distribution<> level(25,30);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]==25 && min_lv_rolled_petitcup==false)
                    min_lv_rolled_petitcup = true;
            }
        }
        // Pika Cup: Lv 15 to Lv 20
        if(rental_cup_id[rental_id]==1){
            if(rental_id == min_lv_pikacup_pkm || (rental_id==(rental_cup_offset[2]-1) && min_lv_rolled_pikacup==false)){
                rental_pkm_level[rental_id]=15;
            }
            else{
                std::uniform_int_distribution<> level(15,20);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]==15 && min_lv_rolled_pikacup==false)
                    min_lv_rolled_pikacup = true;
            }
        }
        // Prime Cup 1: Lv 100
        if(rental_cup_id[rental_id]==2){
            rental_pkm_level[rental_id]=100;
        }
        // Poke Cup: Lv 50 to Lv 55
        if(rental_cup_id[rental_id]==3){
            if(rental_id == min_lv_pokecup_pkm || (rental_id==(rental_cup_offset[4]-2) && min_lv_rolled_pokecup==false)){
                rental_pkm_level[rental_id]=50;
            }
            else if(rental_id==(rental_cup_offset[4]-1)){
                rental_pkm_level[rental_id]=55;
            }
            else{
                std::uniform_int_distribution<> level(50,55);
                rental_pkm_level[rental_id] = level(mt_rand);
                if(rental_pkm_level[rental_id]==50 && min_lv_rolled_pokecup==false)
                    min_lv_rolled_pokecup = true;
            }
        }
        // Gym Leader Castle: Lv 50
        if(rental_cup_id[rental_id]==4){
            rental_pkm_level[rental_id]=50;
        }
        // Prime Cup 2: Lv 100
        if(rental_cup_id[rental_id]==5){
            rental_pkm_level[rental_id]=100;
        }
    }
}
