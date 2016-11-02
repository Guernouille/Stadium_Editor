#include "mainwindow.h"

void MainWindow::read_odds_paralysis(QFile &romfile)
{
    QDataStream read(&romfile);

    romfile.seek(0x35CC33);
    read>>odds_paralysis;
}
