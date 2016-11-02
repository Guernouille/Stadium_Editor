#include "mainwindow.h"

void MainWindow::write_odds_paralysis(QFile &romfile)
{
    QDataStream write(&romfile);

    romfile.seek(0x35CC33);
    write<<odds_paralysis;
}
