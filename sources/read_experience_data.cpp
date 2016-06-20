#include "mainwindow.h"

void MainWindow::read_experience_data(QFile &romfile)
{
    QDataStream read(&romfile);
    romfile.seek(0x7DE453);

    for(uint8_t i=0;i<6;i++){
        read>>experience_param_1[i];
        if(i<4){
            read>>experience_param_2[i];
            read>>experience_param_3[i];
            read>>experience_param_4[i];
        }
        else{
            experience_param_2[i] = 0;
            experience_param_3[i] = 0;
            experience_param_4[i] = 0;
        }
    }
}
