#include "mainwindow.h"
#include <QGridLayout>
#include <QSpacerItem>

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/trainer_sprites/37"));
    messageBox.setTextFormat(Qt::RichText);
    messageBox.setText("Stadium Editor v0.1 (June 20th 2016), an editor and randomizer for Pokémon Stadium. Coded in C++ with Qt. Hope you enjoy this program !<br>You can contact me on <a href='http://forums.pokemonspeedruns.com/memberlist.php?mode=viewprofile&u=430'>Pokémon Speedruns</a> (froggy25), <a href='http://www.smogon.com/forums/members/froggy25.6883/'>Smogon</a> (froggy25), <a href='http://pokeplayer.com'>PokéPlayer</a> (MégaLAG), or on <a href='http://datacrystal.romhacking.net/wiki/User_talk:Mantidactyle'>RHDN</a> (Mantidactyle).<br>Source code is available on <a href='https://github.com/Guernouille/Stadium_Editor/'>GitHub</a>.<br>I will work on improving the code and adding new functions in the next days, be sure to download the new version when it comes out!");
    messageBox.setWindowTitle("About");
    QGridLayout* layout = (QGridLayout*)messageBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    messageBox.exec();
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/pkm_sprites/25"));
    messageBox.setText("Click buttons. Do stuff. Easy.\nNah, I'll write a real Help when I get the time to do so, in next update.\nUntil then, contact me or leave a message on Pokemon Speedruns forums.");
    messageBox.setWindowTitle("Help meeeeeee, Pika...");
    QGridLayout* layout = (QGridLayout*)messageBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    messageBox.exec();
}

void MainWindow::on_actionPika_triggered()
{
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(200, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/pkm_sprites/152"));
    messageBox.setText("Pika !");
    messageBox.setWindowTitle("Pika ?");
    QGridLayout* layout = (QGridLayout*)messageBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    messageBox.exec();
}
