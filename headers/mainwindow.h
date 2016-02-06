#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "common.cpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    romType romtype;
    quint32 magic[14];
    QString img_path;
    QString widget_text;
    QString debug;

    quint8  buf8;
    quint16 buf16;
    quint32 buf32;
    quint32 rom_offset;
    QString char_table[256];

    quint8 total_cpu_rentals_array;
    quint8 total_cpu_rentals;
    quint8 total_move_name;
    quint8 total_move_description;
    quint8 total_pkm_name;
    quint8 total_pokedex_entry;
    quint8 total_type_name;

    quint32 experience_max[6];
    quint8 experience_param_1[6];
    quint8 experience_param_2[6];
    quint8 experience_param_3[6];
    quint8 experience_param_4[6];

    quint8 move_iid[256];
    QString move_description[256];
    quint16 move_description_pointer[256];
    QString move_name[256];
    quint16 move_name_pointer[256];
    QString move_tmhm_text[256];
    quint8 move_effect[256];
    quint8 move_power[256];
    quint8 move_type[256];
    quint8 move_accuracy[256];
    quint8 move_pp[256];

    QString pkm_name[256];
    quint16 pkm_name_pointer[256];
    quint8 pkm_base_hp[256];
    quint8 pkm_base_atk[256];
    quint8 pkm_base_def[256];
    quint8 pkm_base_spc[256];
    quint8 pkm_base_speed[256];
    quint8 pkm_base_experience[256];
    quint8 pkm_catch_rate[256];
    quint8 pkm_growth_rate[256];
    quint8 pkm_rb_lvl[256][10];
    quint8 pkm_rb_move[256][10];
    quint8 pkm_start_move_1[256];
    quint8 pkm_start_move_2[256];
    quint8 pkm_start_move_3[256];
    quint8 pkm_start_move_4[256];
    quint8 pkm_tmhm_flags[256][7];
    quint8 pkm_type_1[256];
    quint8 pkm_type_2[256];
    quint8 pkm_y_lvl[256][10];
    quint8 pkm_y_move[256][10];

    quint16 pokedex_entry_pointer[256];
    QString pokedex_entry[256];

    quint8 tmhm[256];
    quint8 tmhm_byte;
    quint8 tmhm_flag;
    QList<QCheckBox*> tmhm_list;
    
    QString type_name[256];

    quint16 cpu_rentals_arraylen[64];
    quint32 cpu_rentals_pointer[64];

    QString cpu_tname[256];
    quint8  cpu_sprite_id[256];
    quint8  cpu_party_size[256];
    quint8  cpu_pkm_id[256][6];
    QString cpu_pkm_nickname[256][6];
    quint8  cpu_pkm_level[256][6];
    quint32 cpu_pkm_experience[256][6];
    quint16 cpu_pkm_ev_hp[256][6];
    quint16 cpu_pkm_ev_atk[256][6];
    quint16 cpu_pkm_ev_def[256][6];
    quint16 cpu_pkm_ev_speed[256][6];
    quint16 cpu_pkm_ev_spc[256][6];
    quint16 cpu_pkm_ivs[256][6];
    quint8  cpu_pkm_iv_hp[256][6];
    quint8  cpu_pkm_iv_atk[256][6];
    quint8  cpu_pkm_iv_def[256][6];
    quint8  cpu_pkm_iv_speed[256][6];
    quint8  cpu_pkm_iv_spc[256][6];
    quint8  cpu_pkm_move_1[256][6];
    quint8  cpu_pkm_move_2[256][6];
    quint8  cpu_pkm_move_3[256][6];
    quint8  cpu_pkm_move_4[256][6];
    quint8  cpu_pkm_pp_1[256][6];
    quint8  cpu_pkm_pp_2[256][6];
    quint8  cpu_pkm_pp_3[256][6];
    quint8  cpu_pkm_pp_4[256][6];
    quint8  cpu_pkm_ppup_1[256][6];
    quint8  cpu_pkm_ppup_2[256][6];
    quint8  cpu_pkm_ppup_3[256][6];
    quint8  cpu_pkm_ppup_4[256][6];

    quint8  rental_pkm_id[1024];
    QString rental_pkm_nickname[1024];
    quint8  rental_pkm_level[1024];
    quint32 rental_pkm_experience[1024];
    quint16 rental_pkm_ev_hp[1024];
    quint16 rental_pkm_ev_atk[1024];
    quint16 rental_pkm_ev_def[1024];
    quint16 rental_pkm_ev_speed[1024];
    quint16 rental_pkm_ev_spc[1024];
    quint16 rental_pkm_ivs[1024];
    quint8  rental_pkm_iv_hp[1024];
    quint8  rental_pkm_iv_atk[1024];
    quint8  rental_pkm_iv_def[1024];
    quint8  rental_pkm_iv_speed[1024];
    quint8  rental_pkm_iv_spc[1024];
    quint8  rental_pkm_move_1[1024];
    quint8  rental_pkm_move_2[1024];
    quint8  rental_pkm_move_3[1024];
    quint8  rental_pkm_move_4[1024];
    quint8  rental_pkm_pp_1[1024];
    quint8  rental_pkm_pp_2[1024];
    quint8  rental_pkm_pp_3[1024];
    quint8  rental_pkm_pp_4[1024];

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionOpen_triggered();
    void on_comboBox_MovesList_currentIndexChanged(int);
    void on_comboBox_PokemonSpecies_currentIndexChanged(int);
    void on_spinBox_TrainerSpriteID_valueChanged(int);

    void initialize_char_table();
    void initialize_widgets();

    void rom_check();

    void calc_experience_max();
    void display_cpu_trainer_pkmn(quint8 cpu_trainer_id);
    void display_cpu_trainer_sprite(quint8 cpu_trainer_sprite_id);
    void display_experience_data();
    void display_move_data(quint8 move_id);
    void display_pkm_data(quint8 pkm_id);
    void read_cpu_rentals(QFile &romfile);
    void read_experience_data(QFile &romfile);
    void read_move_data(QFile &romfile);
    void read_move_descriptions(QFile &romfile);
    void read_move_names(QFile &romfile);
    void read_pkm_data(QFile &romfile);
    void read_pkm_names(QFile &romfile);
    void read_pokedex_data(QFile &romfile);
    void read_tmhm_data(QFile &romfile);
    void read_type_names(QFile &romfile);
};

#endif // MAINWINDOW_H
