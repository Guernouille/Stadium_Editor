#include "mainwindow.h"

// Type 1
void MainWindow::type1_box_changed(int boxIndex) {
    if(not_in_init){
        buf8 = type1_comboboxes[boxIndex]->currentIndex();
        if(buf8 > 8) buf8 += 11;
        type_chart[boxIndex].setType1(buf8);
    }
}

// Type 2
void MainWindow::type2_box_changed(int boxIndex) {
    if(not_in_init){
        buf8 = type2_comboboxes[boxIndex]->currentIndex();
        if(buf8 > 8) buf8 += 11;
        type_chart[boxIndex].setType2(buf8);
    }
}

// Multiplier
void MainWindow::mult_spinbox_changed(int boxIndex) {
    if(not_in_init){
        type_chart[boxIndex].setMultiplier(mult_spinboxes[boxIndex]->value());
    }
}
