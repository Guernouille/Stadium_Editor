#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    prng_seeds();
    set_widgets();

    init_type1_box_vec();
    init_type2_box_vec();
    init_mult_box_vec();
    init_lvl_box_vec();
    init_move_box_vecs();

    type1_combobox_mapper = new QSignalMapper(this);
    type2_combobox_mapper = new QSignalMapper(this);
    mult_spinbox_mapper = new QSignalMapper(this);
    lvl_spinbox_mapper = new QSignalMapper(this);

    move1_combobox_mapper = new QSignalMapper(this);
    move2_combobox_mapper = new QSignalMapper(this);
    move3_combobox_mapper = new QSignalMapper(this);
    move4_combobox_mapper = new QSignalMapper(this);

    for (unsigned int i = 0; i < type1_comboboxes.size(); ++i) {
        connect(type1_comboboxes[i], SIGNAL(currentIndexChanged(int)),
                type1_combobox_mapper, SLOT(map()));
        type1_combobox_mapper->setMapping(type1_comboboxes[i], i);
    }
    for (unsigned int i = 0; i < type2_comboboxes.size(); ++i) {
        connect(type2_comboboxes[i], SIGNAL(currentIndexChanged(int)),
                type2_combobox_mapper, SLOT(map()));
        type2_combobox_mapper->setMapping(type2_comboboxes[i], i);
    }
    for (unsigned int i = 0; i < mult_spinboxes.size(); ++i) {
        connect(mult_spinboxes[i], SIGNAL(valueChanged(int)),
                mult_spinbox_mapper, SLOT(map()));
        mult_spinbox_mapper->setMapping(mult_spinboxes[i], i);
    }
    for (unsigned int i = 0; i < lvl_spinboxes.size(); ++i) {
        connect(lvl_spinboxes[i], SIGNAL(valueChanged(int)),
                lvl_spinbox_mapper, SLOT(map()));
        lvl_spinbox_mapper->setMapping(lvl_spinboxes[i], i);
    }

    for (unsigned int i = 0; i < move1_comboboxes.size(); ++i) {
        connect(move1_comboboxes[i], SIGNAL(currentIndexChanged(int)),
                move1_combobox_mapper, SLOT(map()));
        move1_combobox_mapper->setMapping(move1_comboboxes[i], i);
    }
    for (unsigned int i = 0; i < move2_comboboxes.size(); ++i) {
        connect(move2_comboboxes[i], SIGNAL(currentIndexChanged(int)),
                move2_combobox_mapper, SLOT(map()));
        move2_combobox_mapper->setMapping(move2_comboboxes[i], i);
    }
    for (unsigned int i = 0; i < move3_comboboxes.size(); ++i) {
        connect(move3_comboboxes[i], SIGNAL(currentIndexChanged(int)),
                move3_combobox_mapper, SLOT(map()));
        move3_combobox_mapper->setMapping(move3_comboboxes[i], i);
    }
    for (unsigned int i = 0; i < move4_comboboxes.size(); ++i) {
        connect(move4_comboboxes[i], SIGNAL(currentIndexChanged(int)),
                move4_combobox_mapper, SLOT(map()));
        move4_combobox_mapper->setMapping(move4_comboboxes[i], i);
    }

    connect(type1_combobox_mapper, SIGNAL(mapped(int)),
            this, SLOT(type1_box_changed(int)));
    connect(type2_combobox_mapper, SIGNAL(mapped(int)),
            this, SLOT(type2_box_changed(int)));
    connect(mult_spinbox_mapper, SIGNAL(mapped(int)),
            this, SLOT(mult_spinbox_changed(int)));
    connect(lvl_spinbox_mapper, SIGNAL(mapped(int)),
            this, SLOT(lv_spinbox_changed(int)));

    connect(move1_combobox_mapper, SIGNAL(mapped(int)),
            this, SLOT(move1_combobox_changed(int)));
    connect(move2_combobox_mapper, SIGNAL(mapped(int)),
            this, SLOT(move2_combobox_changed(int)));
    connect(move3_combobox_mapper, SIGNAL(mapped(int)),
            this, SLOT(move3_combobox_changed(int)));
    connect(move4_combobox_mapper, SIGNAL(mapped(int)),
            this, SLOT(move4_combobox_changed(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_type1_box_vec()
{
    type1_comboboxes.push_back(ui->comboBox_Type1_1);
    type1_comboboxes.push_back(ui->comboBox_Type1_2);
    type1_comboboxes.push_back(ui->comboBox_Type1_3);
    type1_comboboxes.push_back(ui->comboBox_Type1_4);
    type1_comboboxes.push_back(ui->comboBox_Type1_5);
    type1_comboboxes.push_back(ui->comboBox_Type1_6);
    type1_comboboxes.push_back(ui->comboBox_Type1_7);
    type1_comboboxes.push_back(ui->comboBox_Type1_8);
    type1_comboboxes.push_back(ui->comboBox_Type1_9);
    type1_comboboxes.push_back(ui->comboBox_Type1_10);
    type1_comboboxes.push_back(ui->comboBox_Type1_11);
    type1_comboboxes.push_back(ui->comboBox_Type1_12);
    type1_comboboxes.push_back(ui->comboBox_Type1_13);
    type1_comboboxes.push_back(ui->comboBox_Type1_14);
    type1_comboboxes.push_back(ui->comboBox_Type1_15);
    type1_comboboxes.push_back(ui->comboBox_Type1_16);
    type1_comboboxes.push_back(ui->comboBox_Type1_17);
    type1_comboboxes.push_back(ui->comboBox_Type1_18);
    type1_comboboxes.push_back(ui->comboBox_Type1_19);
    type1_comboboxes.push_back(ui->comboBox_Type1_20);
    type1_comboboxes.push_back(ui->comboBox_Type1_21);
    type1_comboboxes.push_back(ui->comboBox_Type1_22);
    type1_comboboxes.push_back(ui->comboBox_Type1_23);
    type1_comboboxes.push_back(ui->comboBox_Type1_24);
    type1_comboboxes.push_back(ui->comboBox_Type1_25);
    type1_comboboxes.push_back(ui->comboBox_Type1_26);
    type1_comboboxes.push_back(ui->comboBox_Type1_27);
    type1_comboboxes.push_back(ui->comboBox_Type1_28);
    type1_comboboxes.push_back(ui->comboBox_Type1_29);
    type1_comboboxes.push_back(ui->comboBox_Type1_30);
    type1_comboboxes.push_back(ui->comboBox_Type1_31);
    type1_comboboxes.push_back(ui->comboBox_Type1_32);
    type1_comboboxes.push_back(ui->comboBox_Type1_33);
    type1_comboboxes.push_back(ui->comboBox_Type1_34);
    type1_comboboxes.push_back(ui->comboBox_Type1_35);
    type1_comboboxes.push_back(ui->comboBox_Type1_36);
    type1_comboboxes.push_back(ui->comboBox_Type1_37);
    type1_comboboxes.push_back(ui->comboBox_Type1_38);
    type1_comboboxes.push_back(ui->comboBox_Type1_39);
    type1_comboboxes.push_back(ui->comboBox_Type1_40);
    type1_comboboxes.push_back(ui->comboBox_Type1_41);
    type1_comboboxes.push_back(ui->comboBox_Type1_42);
    type1_comboboxes.push_back(ui->comboBox_Type1_43);
    type1_comboboxes.push_back(ui->comboBox_Type1_44);
    type1_comboboxes.push_back(ui->comboBox_Type1_45);
    type1_comboboxes.push_back(ui->comboBox_Type1_46);
    type1_comboboxes.push_back(ui->comboBox_Type1_47);
    type1_comboboxes.push_back(ui->comboBox_Type1_48);
    type1_comboboxes.push_back(ui->comboBox_Type1_49);
    type1_comboboxes.push_back(ui->comboBox_Type1_50);
    type1_comboboxes.push_back(ui->comboBox_Type1_51);
    type1_comboboxes.push_back(ui->comboBox_Type1_52);
    type1_comboboxes.push_back(ui->comboBox_Type1_53);
    type1_comboboxes.push_back(ui->comboBox_Type1_54);
    type1_comboboxes.push_back(ui->comboBox_Type1_55);
    type1_comboboxes.push_back(ui->comboBox_Type1_56);
    type1_comboboxes.push_back(ui->comboBox_Type1_57);
    type1_comboboxes.push_back(ui->comboBox_Type1_58);
    type1_comboboxes.push_back(ui->comboBox_Type1_59);
    type1_comboboxes.push_back(ui->comboBox_Type1_60);
    type1_comboboxes.push_back(ui->comboBox_Type1_61);
    type1_comboboxes.push_back(ui->comboBox_Type1_62);
    type1_comboboxes.push_back(ui->comboBox_Type1_63);
    type1_comboboxes.push_back(ui->comboBox_Type1_64);
    type1_comboboxes.push_back(ui->comboBox_Type1_65);
    type1_comboboxes.push_back(ui->comboBox_Type1_66);
    type1_comboboxes.push_back(ui->comboBox_Type1_67);
    type1_comboboxes.push_back(ui->comboBox_Type1_68);
    type1_comboboxes.push_back(ui->comboBox_Type1_69);
    type1_comboboxes.push_back(ui->comboBox_Type1_70);
    type1_comboboxes.push_back(ui->comboBox_Type1_71);
    type1_comboboxes.push_back(ui->comboBox_Type1_72);
    type1_comboboxes.push_back(ui->comboBox_Type1_73);
    type1_comboboxes.push_back(ui->comboBox_Type1_74);
    type1_comboboxes.push_back(ui->comboBox_Type1_75);
    type1_comboboxes.push_back(ui->comboBox_Type1_76);
    type1_comboboxes.push_back(ui->comboBox_Type1_77);
    type1_comboboxes.push_back(ui->comboBox_Type1_78);
    type1_comboboxes.push_back(ui->comboBox_Type1_79);
    type1_comboboxes.push_back(ui->comboBox_Type1_80);
    type1_comboboxes.push_back(ui->comboBox_Type1_81);
    type1_comboboxes.push_back(ui->comboBox_Type1_82);
}

void MainWindow::init_type2_box_vec()
{
    type2_comboboxes.push_back(ui->comboBox_Type2_1);
    type2_comboboxes.push_back(ui->comboBox_Type2_2);
    type2_comboboxes.push_back(ui->comboBox_Type2_3);
    type2_comboboxes.push_back(ui->comboBox_Type2_4);
    type2_comboboxes.push_back(ui->comboBox_Type2_5);
    type2_comboboxes.push_back(ui->comboBox_Type2_6);
    type2_comboboxes.push_back(ui->comboBox_Type2_7);
    type2_comboboxes.push_back(ui->comboBox_Type2_8);
    type2_comboboxes.push_back(ui->comboBox_Type2_9);
    type2_comboboxes.push_back(ui->comboBox_Type2_10);
    type2_comboboxes.push_back(ui->comboBox_Type2_11);
    type2_comboboxes.push_back(ui->comboBox_Type2_12);
    type2_comboboxes.push_back(ui->comboBox_Type2_13);
    type2_comboboxes.push_back(ui->comboBox_Type2_14);
    type2_comboboxes.push_back(ui->comboBox_Type2_15);
    type2_comboboxes.push_back(ui->comboBox_Type2_16);
    type2_comboboxes.push_back(ui->comboBox_Type2_17);
    type2_comboboxes.push_back(ui->comboBox_Type2_18);
    type2_comboboxes.push_back(ui->comboBox_Type2_19);
    type2_comboboxes.push_back(ui->comboBox_Type2_20);
    type2_comboboxes.push_back(ui->comboBox_Type2_21);
    type2_comboboxes.push_back(ui->comboBox_Type2_22);
    type2_comboboxes.push_back(ui->comboBox_Type2_23);
    type2_comboboxes.push_back(ui->comboBox_Type2_24);
    type2_comboboxes.push_back(ui->comboBox_Type2_25);
    type2_comboboxes.push_back(ui->comboBox_Type2_26);
    type2_comboboxes.push_back(ui->comboBox_Type2_27);
    type2_comboboxes.push_back(ui->comboBox_Type2_28);
    type2_comboboxes.push_back(ui->comboBox_Type2_29);
    type2_comboboxes.push_back(ui->comboBox_Type2_30);
    type2_comboboxes.push_back(ui->comboBox_Type2_31);
    type2_comboboxes.push_back(ui->comboBox_Type2_32);
    type2_comboboxes.push_back(ui->comboBox_Type2_33);
    type2_comboboxes.push_back(ui->comboBox_Type2_34);
    type2_comboboxes.push_back(ui->comboBox_Type2_35);
    type2_comboboxes.push_back(ui->comboBox_Type2_36);
    type2_comboboxes.push_back(ui->comboBox_Type2_37);
    type2_comboboxes.push_back(ui->comboBox_Type2_38);
    type2_comboboxes.push_back(ui->comboBox_Type2_39);
    type2_comboboxes.push_back(ui->comboBox_Type2_40);
    type2_comboboxes.push_back(ui->comboBox_Type2_41);
    type2_comboboxes.push_back(ui->comboBox_Type2_42);
    type2_comboboxes.push_back(ui->comboBox_Type2_43);
    type2_comboboxes.push_back(ui->comboBox_Type2_44);
    type2_comboboxes.push_back(ui->comboBox_Type2_45);
    type2_comboboxes.push_back(ui->comboBox_Type2_46);
    type2_comboboxes.push_back(ui->comboBox_Type2_47);
    type2_comboboxes.push_back(ui->comboBox_Type2_48);
    type2_comboboxes.push_back(ui->comboBox_Type2_49);
    type2_comboboxes.push_back(ui->comboBox_Type2_50);
    type2_comboboxes.push_back(ui->comboBox_Type2_51);
    type2_comboboxes.push_back(ui->comboBox_Type2_52);
    type2_comboboxes.push_back(ui->comboBox_Type2_53);
    type2_comboboxes.push_back(ui->comboBox_Type2_54);
    type2_comboboxes.push_back(ui->comboBox_Type2_55);
    type2_comboboxes.push_back(ui->comboBox_Type2_56);
    type2_comboboxes.push_back(ui->comboBox_Type2_57);
    type2_comboboxes.push_back(ui->comboBox_Type2_58);
    type2_comboboxes.push_back(ui->comboBox_Type2_59);
    type2_comboboxes.push_back(ui->comboBox_Type2_60);
    type2_comboboxes.push_back(ui->comboBox_Type2_61);
    type2_comboboxes.push_back(ui->comboBox_Type2_62);
    type2_comboboxes.push_back(ui->comboBox_Type2_63);
    type2_comboboxes.push_back(ui->comboBox_Type2_64);
    type2_comboboxes.push_back(ui->comboBox_Type2_65);
    type2_comboboxes.push_back(ui->comboBox_Type2_66);
    type2_comboboxes.push_back(ui->comboBox_Type2_67);
    type2_comboboxes.push_back(ui->comboBox_Type2_68);
    type2_comboboxes.push_back(ui->comboBox_Type2_69);
    type2_comboboxes.push_back(ui->comboBox_Type2_70);
    type2_comboboxes.push_back(ui->comboBox_Type2_71);
    type2_comboboxes.push_back(ui->comboBox_Type2_72);
    type2_comboboxes.push_back(ui->comboBox_Type2_73);
    type2_comboboxes.push_back(ui->comboBox_Type2_74);
    type2_comboboxes.push_back(ui->comboBox_Type2_75);
    type2_comboboxes.push_back(ui->comboBox_Type2_76);
    type2_comboboxes.push_back(ui->comboBox_Type2_77);
    type2_comboboxes.push_back(ui->comboBox_Type2_78);
    type2_comboboxes.push_back(ui->comboBox_Type2_79);
    type2_comboboxes.push_back(ui->comboBox_Type2_80);
    type2_comboboxes.push_back(ui->comboBox_Type2_81);
    type2_comboboxes.push_back(ui->comboBox_Type2_82);
}

void MainWindow::init_mult_box_vec()
{
    mult_spinboxes.push_back(ui->spinBox_Multiplier_1);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_2);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_3);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_4);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_5);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_6);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_7);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_8);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_9);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_10);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_11);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_12);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_13);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_14);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_15);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_16);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_17);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_18);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_19);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_20);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_21);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_22);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_23);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_24);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_25);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_26);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_27);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_28);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_29);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_30);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_31);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_32);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_33);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_34);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_35);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_36);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_37);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_38);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_39);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_40);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_41);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_42);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_43);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_44);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_45);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_46);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_47);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_48);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_49);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_50);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_51);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_52);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_53);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_54);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_55);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_56);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_57);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_58);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_59);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_60);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_61);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_62);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_63);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_64);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_65);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_66);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_67);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_68);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_69);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_70);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_71);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_72);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_73);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_74);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_75);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_76);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_77);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_78);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_79);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_80);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_81);
    mult_spinboxes.push_back(ui->spinBox_Multiplier_82);
}

void MainWindow::init_lvl_box_vec()
{
    lvl_spinboxes.push_back(ui->spinBox_Lv_1);
    lvl_spinboxes.push_back(ui->spinBox_Lv_2);
    lvl_spinboxes.push_back(ui->spinBox_Lv_3);
    lvl_spinboxes.push_back(ui->spinBox_Lv_4);
    lvl_spinboxes.push_back(ui->spinBox_Lv_5);
    lvl_spinboxes.push_back(ui->spinBox_Lv_6);
}

void MainWindow::init_move_box_vecs()
{
    move1_comboboxes.push_back(ui->comboBox_Move1_1);
    move1_comboboxes.push_back(ui->comboBox_Move1_2);
    move1_comboboxes.push_back(ui->comboBox_Move1_3);
    move1_comboboxes.push_back(ui->comboBox_Move1_4);
    move1_comboboxes.push_back(ui->comboBox_Move1_5);
    move1_comboboxes.push_back(ui->comboBox_Move1_6);
    move2_comboboxes.push_back(ui->comboBox_Move2_1);
    move2_comboboxes.push_back(ui->comboBox_Move2_2);
    move2_comboboxes.push_back(ui->comboBox_Move2_3);
    move2_comboboxes.push_back(ui->comboBox_Move2_4);
    move2_comboboxes.push_back(ui->comboBox_Move2_5);
    move2_comboboxes.push_back(ui->comboBox_Move2_6);
    move3_comboboxes.push_back(ui->comboBox_Move3_1);
    move3_comboboxes.push_back(ui->comboBox_Move3_2);
    move3_comboboxes.push_back(ui->comboBox_Move3_3);
    move3_comboboxes.push_back(ui->comboBox_Move3_4);
    move3_comboboxes.push_back(ui->comboBox_Move3_5);
    move3_comboboxes.push_back(ui->comboBox_Move3_6);
    move4_comboboxes.push_back(ui->comboBox_Move4_1);
    move4_comboboxes.push_back(ui->comboBox_Move4_2);
    move4_comboboxes.push_back(ui->comboBox_Move4_3);
    move4_comboboxes.push_back(ui->comboBox_Move4_4);
    move4_comboboxes.push_back(ui->comboBox_Move4_5);
    move4_comboboxes.push_back(ui->comboBox_Move4_6);
}
