#include "mainwindow.h"

void MainWindow::on_actionSave_triggered(){
    QFile romfile(filename);
    romfile.open(QIODevice::ReadWrite);

    write_move_data(romfile);
    write_tmhm_data(romfile);
    write_pkm_data(romfile);
    write_cpu_rentals(romfile);
    write_type_chart(romfile);
    write_ch_formula(romfile);
    write_damage_variance(romfile);
    write_highCH_shift(romfile);
    write_burn_shift(romfile);
    write_odds_paralysis(romfile);
    n64crc(romfile);
    write_n64crc(romfile);

    // Display CRC and Region Code info
    ui->lineEdit_crc1->setText(QString("%1").arg(header_crc1,8,16,QLatin1Char('0')).toUpper());
    ui->lineEdit_crc2->setText(QString("%1").arg(header_crc2,8,16,QLatin1Char('0')).toUpper());
    ui->lineEdit_RegionCode->setText(QString("%1").arg(header_region_code,2,16,QLatin1Char('0')).toUpper());

    romfile.close();
}
