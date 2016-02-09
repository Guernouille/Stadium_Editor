#include "mainwindow.h"

int MainWindow::calc_experience(quint8 exp_group, quint8 level) {
    experience_calc = 0;
    experience_calc = experience_param_1[exp_group]>>4;
    experience_calc *= level;
    experience_calc *= level;
    experience_calc *= level;
    experience_calc /= experience_param_1[exp_group]&0xF;

    if(experience_param_2[exp_group]&0x80){
        experience_calc -= level*level*(experience_param_2[exp_group]&0x7F);
    }
    else{
        experience_calc += level*level*(experience_param_2[exp_group]&0x7F);
    }

    experience_calc += level*experience_param_3[exp_group];
    experience_calc -= experience_param_4[exp_group];


    return experience_calc;
}
