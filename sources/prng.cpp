#include "mainwindow.h"
#include <chrono>
#include <functional>
#include <random>

void MainWindow::prng_seeds()
{
    std::random_device rd;
    if(rd.entropy()!=0){
        prng_seed[0] = rd();
        prng_seed[1] = rd();
        prng_seed[2] = rd();
        prng_seed[3] = rd();
        prng_seed[4] = rd();
        prng_seed[5] = rd();
    }
    // Fallback if random_device fails
    else{
        prng_seed[0] = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        prng_seed[0] *= 0x343FD;
        prng_seed[0] += 0x269EC3;
        prng_seed[0] ^= prng_seed[0] << 13;
        prng_seed[0] ^= prng_seed[0] >> 17;
        prng_seed[0] ^= prng_seed[0] << 5;

        for(short i=1;i<6;i++){
            prng_seed[i] = prng_seed[i-1];
            prng_seed[i] ^= prng_seed[i] << 13;
            prng_seed[i] ^= prng_seed[i] >> 17;
            prng_seed[i] ^= prng_seed[i] << 5;
        }

        std::seed_seq seeds{prng_seed[0], prng_seed[1], prng_seed[2], prng_seed[3], prng_seed[4], prng_seed[5]};
        std::mt19937 mt_rand(seeds);

        // Escape from Zeroland
        mt_rand.discard(700000);

        prng_seed[0] = mt_rand();
        prng_seed[1] = mt_rand();
        prng_seed[2] = mt_rand();
        prng_seed[3] = mt_rand();
        prng_seed[4] = mt_rand();
        prng_seed[5] = mt_rand();
    }
}
