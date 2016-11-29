#include "mainwindow.h"
#include <QGridLayout>
#include <QSpacerItem>

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox messageBox;
    QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    messageBox.setIconPixmap(QPixmap(":/trainer_sprites/37"));
    messageBox.setTextFormat(Qt::RichText);
    messageBox.setText("Stadium Editor v0.2 (November 29th 2016), an editor and randomizer for Pokémon Stadium. Coded in C++ with Qt. Hope you enjoy this program !<br>You can contact me on <a href='http://forums.pokemonspeedruns.com/memberlist.php?mode=viewprofile&u=430'>Pokémon Speedruns</a> (froggy25), <a href='http://www.smogon.com/forums/members/froggy25.6883/'>Smogon</a> (froggy25), <a href='http://pokeplayer.com'>PokéPlayer</a> (Mantidactyle), or on <a href='http://datacrystal.romhacking.net/wiki/User_talk:Mantidactyle'>RHDN</a> (Mantidactyle).<br>Source code is available on <a href='https://github.com/Guernouille/Stadium_Editor/'>GitHub</a>.<br>I will work on improving the code and adding new functions in the next weeks, be sure to download the new version when it comes out!");
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
    messageBox.setText("Click buttons. Do stuff. Easy.\nNah, I'll write a real Help when I get the time to do so, in another update.\nUntil then, contact me or leave a message on Pokemon Speedruns forums.\n\nIf you edit the Pokémon data or Move data, and you're using PJ64, you'll need to edit the .rdb config file, find the entry for your Pokémon Stadium ROM, and copy-paste it at the end of the .rdb file with the new CRCs.\nAlternatively, you can use another emulator (like Cen64 or BizHawk).");
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
