#include "mainwindow.h"

void MainWindow::calc_experience_max() {
    for (short i=0;i<6;i++){
        experience_max[i] = experience_param_1[i]>>4;
        experience_max[i] *= 1000000;
        experience_max[i] /= experience_param_1[i]&0xF;

        if(experience_param_2[i]&0x80){
            experience_max[i] -= 10000*(experience_param_2[i]&0x7F);
        }
        else{
            experience_max[i] += 10000*(experience_param_2[i]&0x7F);
        }

        experience_max[i] += 100*experience_param_3[i];
        experience_max[i] -= experience_param_4[i];
    }
}


void MainWindow::display_experience_data() {
    ui->comboBox_GrowthRate->clear();
    calc_experience_max();

    for (short i=0;i<6;i++){
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
}

