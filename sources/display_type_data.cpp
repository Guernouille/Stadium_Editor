#include "mainwindow.h"

void MainWindow::display_type_chart() {
    not_in_init = false;

    buf8 = convert_type_id(type_chart[0].getType1());
    ui->comboBox_Type1_1->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[0].getType2());
    ui->comboBox_Type2_1->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_1->setValue(type_chart[0].getMultiplier());

    buf8 = convert_type_id(type_chart[1].getType1());
    ui->comboBox_Type1_2->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[1].getType2());
    ui->comboBox_Type2_2->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_2->setValue(type_chart[1].getMultiplier());

    buf8 = convert_type_id(type_chart[2].getType1());
    ui->comboBox_Type1_3->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[2].getType2());
    ui->comboBox_Type2_3->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_3->setValue(type_chart[2].getMultiplier());

    buf8 = convert_type_id(type_chart[3].getType1());
    ui->comboBox_Type1_4->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[3].getType2());
    ui->comboBox_Type2_4->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_4->setValue(type_chart[3].getMultiplier());

    buf8 = convert_type_id(type_chart[4].getType1());
    ui->comboBox_Type1_5->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[4].getType2());
    ui->comboBox_Type2_5->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_5->setValue(type_chart[4].getMultiplier());

    buf8 = convert_type_id(type_chart[5].getType1());
    ui->comboBox_Type1_6->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[5].getType2());
    ui->comboBox_Type2_6->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_6->setValue(type_chart[5].getMultiplier());

    buf8 = convert_type_id(type_chart[6].getType1());
    ui->comboBox_Type1_7->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[6].getType2());
    ui->comboBox_Type2_7->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_7->setValue(type_chart[6].getMultiplier());

    buf8 = convert_type_id(type_chart[7].getType1());
    ui->comboBox_Type1_8->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[7].getType2());
    ui->comboBox_Type2_8->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_8->setValue(type_chart[7].getMultiplier());

    buf8 = convert_type_id(type_chart[8].getType1());
    ui->comboBox_Type1_9->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[8].getType2());
    ui->comboBox_Type2_9->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_9->setValue(type_chart[8].getMultiplier());

    buf8 = convert_type_id(type_chart[9].getType1());
    ui->comboBox_Type1_10->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[9].getType2());
    ui->comboBox_Type2_10->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_10->setValue(type_chart[9].getMultiplier());

    buf8 = convert_type_id(type_chart[10].getType1());
    ui->comboBox_Type1_11->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[10].getType2());
    ui->comboBox_Type2_11->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_11->setValue(type_chart[10].getMultiplier());

    buf8 = convert_type_id(type_chart[11].getType1());
    ui->comboBox_Type1_12->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[11].getType2());
    ui->comboBox_Type2_12->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_12->setValue(type_chart[11].getMultiplier());

    buf8 = convert_type_id(type_chart[12].getType1());
    ui->comboBox_Type1_13->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[12].getType2());
    ui->comboBox_Type2_13->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_13->setValue(type_chart[12].getMultiplier());

    buf8 = convert_type_id(type_chart[13].getType1());
    ui->comboBox_Type1_14->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[13].getType2());
    ui->comboBox_Type2_14->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_14->setValue(type_chart[13].getMultiplier());

    buf8 = convert_type_id(type_chart[14].getType1());
    ui->comboBox_Type1_15->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[14].getType2());
    ui->comboBox_Type2_15->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_15->setValue(type_chart[14].getMultiplier());

    buf8 = convert_type_id(type_chart[15].getType1());
    ui->comboBox_Type1_16->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[15].getType2());
    ui->comboBox_Type2_16->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_16->setValue(type_chart[15].getMultiplier());

    buf8 = convert_type_id(type_chart[16].getType1());
    ui->comboBox_Type1_17->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[16].getType2());
    ui->comboBox_Type2_17->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_17->setValue(type_chart[16].getMultiplier());

    buf8 = convert_type_id(type_chart[17].getType1());
    ui->comboBox_Type1_18->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[17].getType2());
    ui->comboBox_Type2_18->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_18->setValue(type_chart[17].getMultiplier());

    buf8 = convert_type_id(type_chart[18].getType1());
    ui->comboBox_Type1_19->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[18].getType2());
    ui->comboBox_Type2_19->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_19->setValue(type_chart[18].getMultiplier());

    buf8 = convert_type_id(type_chart[19].getType1());
    ui->comboBox_Type1_20->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[19].getType2());
    ui->comboBox_Type2_20->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_20->setValue(type_chart[19].getMultiplier());

    buf8 = convert_type_id(type_chart[20].getType1());
    ui->comboBox_Type1_21->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[20].getType2());
    ui->comboBox_Type2_21->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_21->setValue(type_chart[20].getMultiplier());

    buf8 = convert_type_id(type_chart[21].getType1());
    ui->comboBox_Type1_22->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[21].getType2());
    ui->comboBox_Type2_22->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_22->setValue(type_chart[21].getMultiplier());

    buf8 = convert_type_id(type_chart[22].getType1());
    ui->comboBox_Type1_23->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[22].getType2());
    ui->comboBox_Type2_23->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_23->setValue(type_chart[22].getMultiplier());

    buf8 = convert_type_id(type_chart[23].getType1());
    ui->comboBox_Type1_24->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[23].getType2());
    ui->comboBox_Type2_24->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_24->setValue(type_chart[23].getMultiplier());

    buf8 = convert_type_id(type_chart[24].getType1());
    ui->comboBox_Type1_25->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[24].getType2());
    ui->comboBox_Type2_25->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_25->setValue(type_chart[24].getMultiplier());

    buf8 = convert_type_id(type_chart[25].getType1());
    ui->comboBox_Type1_26->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[25].getType2());
    ui->comboBox_Type2_26->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_26->setValue(type_chart[25].getMultiplier());

    buf8 = convert_type_id(type_chart[26].getType1());
    ui->comboBox_Type1_27->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[26].getType2());
    ui->comboBox_Type2_27->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_27->setValue(type_chart[26].getMultiplier());

    buf8 = convert_type_id(type_chart[27].getType1());
    ui->comboBox_Type1_28->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[27].getType2());
    ui->comboBox_Type2_28->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_28->setValue(type_chart[27].getMultiplier());

    buf8 = convert_type_id(type_chart[28].getType1());
    ui->comboBox_Type1_29->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[28].getType2());
    ui->comboBox_Type2_29->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_29->setValue(type_chart[28].getMultiplier());

    buf8 = convert_type_id(type_chart[29].getType1());
    ui->comboBox_Type1_30->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[29].getType2());
    ui->comboBox_Type2_30->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_30->setValue(type_chart[29].getMultiplier());

    buf8 = convert_type_id(type_chart[30].getType1());
    ui->comboBox_Type1_31->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[30].getType2());
    ui->comboBox_Type2_31->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_31->setValue(type_chart[30].getMultiplier());

    buf8 = convert_type_id(type_chart[31].getType1());
    ui->comboBox_Type1_32->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[31].getType2());
    ui->comboBox_Type2_32->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_32->setValue(type_chart[31].getMultiplier());

    buf8 = convert_type_id(type_chart[32].getType1());
    ui->comboBox_Type1_33->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[32].getType2());
    ui->comboBox_Type2_33->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_33->setValue(type_chart[32].getMultiplier());

    buf8 = convert_type_id(type_chart[33].getType1());
    ui->comboBox_Type1_34->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[33].getType2());
    ui->comboBox_Type2_34->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_34->setValue(type_chart[33].getMultiplier());

    buf8 = convert_type_id(type_chart[34].getType1());
    ui->comboBox_Type1_35->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[34].getType2());
    ui->comboBox_Type2_35->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_35->setValue(type_chart[34].getMultiplier());

    buf8 = convert_type_id(type_chart[35].getType1());
    ui->comboBox_Type1_36->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[35].getType2());
    ui->comboBox_Type2_36->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_36->setValue(type_chart[35].getMultiplier());

    buf8 = convert_type_id(type_chart[36].getType1());
    ui->comboBox_Type1_37->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[36].getType2());
    ui->comboBox_Type2_37->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_37->setValue(type_chart[36].getMultiplier());

    buf8 = convert_type_id(type_chart[37].getType1());
    ui->comboBox_Type1_38->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[37].getType2());
    ui->comboBox_Type2_38->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_38->setValue(type_chart[37].getMultiplier());

    buf8 = convert_type_id(type_chart[38].getType1());
    ui->comboBox_Type1_39->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[38].getType2());
    ui->comboBox_Type2_39->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_39->setValue(type_chart[38].getMultiplier());

    buf8 = convert_type_id(type_chart[39].getType1());
    ui->comboBox_Type1_40->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[39].getType2());
    ui->comboBox_Type2_40->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_40->setValue(type_chart[39].getMultiplier());

    buf8 = convert_type_id(type_chart[40].getType1());
    ui->comboBox_Type1_41->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[40].getType2());
    ui->comboBox_Type2_41->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_41->setValue(type_chart[40].getMultiplier());

    buf8 = convert_type_id(type_chart[41].getType1());
    ui->comboBox_Type1_42->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[41].getType2());
    ui->comboBox_Type2_42->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_42->setValue(type_chart[41].getMultiplier());

    buf8 = convert_type_id(type_chart[42].getType1());
    ui->comboBox_Type1_43->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[42].getType2());
    ui->comboBox_Type2_43->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_43->setValue(type_chart[42].getMultiplier());

    buf8 = convert_type_id(type_chart[43].getType1());
    ui->comboBox_Type1_44->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[43].getType2());
    ui->comboBox_Type2_44->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_44->setValue(type_chart[43].getMultiplier());

    buf8 = convert_type_id(type_chart[44].getType1());
    ui->comboBox_Type1_45->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[44].getType2());
    ui->comboBox_Type2_45->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_45->setValue(type_chart[44].getMultiplier());

    buf8 = convert_type_id(type_chart[45].getType1());
    ui->comboBox_Type1_46->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[45].getType2());
    ui->comboBox_Type2_46->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_46->setValue(type_chart[45].getMultiplier());

    buf8 = convert_type_id(type_chart[46].getType1());
    ui->comboBox_Type1_47->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[46].getType2());
    ui->comboBox_Type2_47->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_47->setValue(type_chart[46].getMultiplier());

    buf8 = convert_type_id(type_chart[47].getType1());
    ui->comboBox_Type1_48->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[47].getType2());
    ui->comboBox_Type2_48->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_48->setValue(type_chart[47].getMultiplier());

    buf8 = convert_type_id(type_chart[48].getType1());
    ui->comboBox_Type1_49->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[48].getType2());
    ui->comboBox_Type2_49->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_49->setValue(type_chart[48].getMultiplier());

    buf8 = convert_type_id(type_chart[49].getType1());
    ui->comboBox_Type1_50->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[49].getType2());
    ui->comboBox_Type2_50->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_50->setValue(type_chart[49].getMultiplier());

    buf8 = convert_type_id(type_chart[50].getType1());
    ui->comboBox_Type1_51->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[50].getType2());
    ui->comboBox_Type2_51->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_51->setValue(type_chart[50].getMultiplier());

    buf8 = convert_type_id(type_chart[51].getType1());
    ui->comboBox_Type1_52->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[51].getType2());
    ui->comboBox_Type2_52->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_52->setValue(type_chart[51].getMultiplier());

    buf8 = convert_type_id(type_chart[52].getType1());
    ui->comboBox_Type1_53->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[52].getType2());
    ui->comboBox_Type2_53->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_53->setValue(type_chart[52].getMultiplier());

    buf8 = convert_type_id(type_chart[53].getType1());
    ui->comboBox_Type1_54->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[53].getType2());
    ui->comboBox_Type2_54->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_54->setValue(type_chart[53].getMultiplier());

    buf8 = convert_type_id(type_chart[54].getType1());
    ui->comboBox_Type1_55->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[54].getType2());
    ui->comboBox_Type2_55->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_55->setValue(type_chart[54].getMultiplier());

    buf8 = convert_type_id(type_chart[55].getType1());
    ui->comboBox_Type1_56->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[55].getType2());
    ui->comboBox_Type2_56->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_56->setValue(type_chart[55].getMultiplier());

    buf8 = convert_type_id(type_chart[56].getType1());
    ui->comboBox_Type1_57->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[56].getType2());
    ui->comboBox_Type2_57->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_57->setValue(type_chart[56].getMultiplier());

    buf8 = convert_type_id(type_chart[57].getType1());
    ui->comboBox_Type1_58->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[57].getType2());
    ui->comboBox_Type2_58->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_58->setValue(type_chart[57].getMultiplier());

    buf8 = convert_type_id(type_chart[58].getType1());
    ui->comboBox_Type1_59->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[58].getType2());
    ui->comboBox_Type2_59->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_59->setValue(type_chart[58].getMultiplier());

    buf8 = convert_type_id(type_chart[59].getType1());
    ui->comboBox_Type1_60->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[59].getType2());
    ui->comboBox_Type2_60->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_60->setValue(type_chart[59].getMultiplier());

    buf8 = convert_type_id(type_chart[60].getType1());
    ui->comboBox_Type1_61->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[60].getType2());
    ui->comboBox_Type2_61->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_61->setValue(type_chart[60].getMultiplier());

    buf8 = convert_type_id(type_chart[61].getType1());
    ui->comboBox_Type1_62->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[61].getType2());
    ui->comboBox_Type2_62->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_62->setValue(type_chart[61].getMultiplier());

    buf8 = convert_type_id(type_chart[62].getType1());
    ui->comboBox_Type1_63->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[62].getType2());
    ui->comboBox_Type2_63->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_63->setValue(type_chart[62].getMultiplier());

    buf8 = convert_type_id(type_chart[63].getType1());
    ui->comboBox_Type1_64->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[63].getType2());
    ui->comboBox_Type2_64->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_64->setValue(type_chart[63].getMultiplier());

    buf8 = convert_type_id(type_chart[64].getType1());
    ui->comboBox_Type1_65->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[64].getType2());
    ui->comboBox_Type2_65->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_65->setValue(type_chart[64].getMultiplier());

    buf8 = convert_type_id(type_chart[65].getType1());
    ui->comboBox_Type1_66->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[65].getType2());
    ui->comboBox_Type2_66->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_66->setValue(type_chart[65].getMultiplier());

    buf8 = convert_type_id(type_chart[66].getType1());
    ui->comboBox_Type1_67->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[66].getType2());
    ui->comboBox_Type2_67->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_67->setValue(type_chart[66].getMultiplier());

    buf8 = convert_type_id(type_chart[67].getType1());
    ui->comboBox_Type1_68->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[67].getType2());
    ui->comboBox_Type2_68->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_68->setValue(type_chart[67].getMultiplier());

    buf8 = convert_type_id(type_chart[68].getType1());
    ui->comboBox_Type1_69->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[68].getType2());
    ui->comboBox_Type2_69->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_69->setValue(type_chart[68].getMultiplier());

    buf8 = convert_type_id(type_chart[69].getType1());
    ui->comboBox_Type1_70->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[69].getType2());
    ui->comboBox_Type2_70->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_70->setValue(type_chart[69].getMultiplier());

    buf8 = convert_type_id(type_chart[70].getType1());
    ui->comboBox_Type1_71->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[70].getType2());
    ui->comboBox_Type2_71->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_71->setValue(type_chart[70].getMultiplier());

    buf8 = convert_type_id(type_chart[71].getType1());
    ui->comboBox_Type1_72->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[71].getType2());
    ui->comboBox_Type2_72->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_72->setValue(type_chart[71].getMultiplier());

    buf8 = convert_type_id(type_chart[72].getType1());
    ui->comboBox_Type1_73->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[72].getType2());
    ui->comboBox_Type2_73->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_73->setValue(type_chart[72].getMultiplier());

    buf8 = convert_type_id(type_chart[73].getType1());
    ui->comboBox_Type1_74->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[73].getType2());
    ui->comboBox_Type2_74->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_74->setValue(type_chart[73].getMultiplier());

    buf8 = convert_type_id(type_chart[74].getType1());
    ui->comboBox_Type1_75->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[74].getType2());
    ui->comboBox_Type2_75->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_75->setValue(type_chart[74].getMultiplier());

    buf8 = convert_type_id(type_chart[75].getType1());
    ui->comboBox_Type1_76->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[75].getType2());
    ui->comboBox_Type2_76->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_76->setValue(type_chart[75].getMultiplier());

    buf8 = convert_type_id(type_chart[76].getType1());
    ui->comboBox_Type1_77->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[76].getType2());
    ui->comboBox_Type2_77->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_77->setValue(type_chart[76].getMultiplier());

    buf8 = convert_type_id(type_chart[77].getType1());
    ui->comboBox_Type1_78->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[77].getType2());
    ui->comboBox_Type2_78->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_78->setValue(type_chart[77].getMultiplier());

    buf8 = convert_type_id(type_chart[78].getType1());
    ui->comboBox_Type1_79->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[78].getType2());
    ui->comboBox_Type2_79->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_79->setValue(type_chart[78].getMultiplier());

    buf8 = convert_type_id(type_chart[79].getType1());
    ui->comboBox_Type1_80->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[79].getType2());
    ui->comboBox_Type2_80->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_80->setValue(type_chart[79].getMultiplier());

    buf8 = convert_type_id(type_chart[80].getType1());
    ui->comboBox_Type1_81->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[80].getType2());
    ui->comboBox_Type2_81->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_81->setValue(type_chart[80].getMultiplier());

    buf8 = convert_type_id(type_chart[81].getType1());
    ui->comboBox_Type1_82->setCurrentIndex(buf8);
    buf8 = convert_type_id(type_chart[81].getType2());
    ui->comboBox_Type2_82->setCurrentIndex(buf8);
    ui->spinBox_Multiplier_82->setValue(type_chart[81].getMultiplier());

    not_in_init = true;
}
