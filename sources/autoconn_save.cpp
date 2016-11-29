#include "mainwindow.h"

void MainWindow::on_actionSave_triggered(){
    QFile romfile(filename);
    romfile.open(QIODevice::ReadWrite);

    ui->label_StatusBar->setText("");

    write_move_data(romfile);
    ui->progressBar->setValue(10);

    write_tmhm_data(romfile);
    ui->progressBar->setValue(15);

    write_pkm_data(romfile);
    ui->progressBar->setValue(31);

    write_cpu_rentals(romfile);
    ui->progressBar->setValue(65);

    write_type_chart(romfile);
    ui->progressBar->setValue(77);

    write_ch_formula(romfile);
    ui->progressBar->setValue(80);

    write_damage_variance(romfile);
    ui->progressBar->setValue(81);

    write_highCH_shift(romfile);
    ui->progressBar->setValue(83);

    write_burn_shift(romfile);
    ui->progressBar->setValue(84);

    write_odds_paralysis(romfile);
    ui->progressBar->setValue(85);

    n64crc(romfile);
    ui->progressBar->setValue(96);

    write_n64crc(romfile);
    ui->progressBar->setValue(99);

    romfile.close();

    // Display CRC and Region Code info
    ui->lineEdit_crc1->setText(QString("%1").arg(header_crc1,8,16,QLatin1Char('0')).toUpper());
    ui->lineEdit_crc2->setText(QString("%1").arg(header_crc2,8,16,QLatin1Char('0')).toUpper());
    ui->lineEdit_RegionCode->setText(QString("%1").arg(header_region_code,2,16,QLatin1Char('0')).toUpper());

    ui->progressBar->setValue(100);
    ui->label_StatusBar->setText("ROM saved!");

}
