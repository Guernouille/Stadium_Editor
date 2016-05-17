#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
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

    QString filename;
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

    quint16 current_rentals_number;
    quint8 current_rentals_cup;
    quint8 current_cpu_trainers_cup;
    quint8 current_cpu_trainers_number;

    quint16 cpu_rentals_arraylen[64];
    quint32 cpu_rentals_pointer[64];

    quint8  cpu_cup_id[256];
    quint8  cpu_cup_offset[256];
    QString cpu_tname[256];
    quint8  cpu_sprite_id[256];
    quint8  cpu_ai_id[256];
    quint8  cpu_party_size[256];
    quint8  cpu_pkm_id[256][6];
    QString cpu_pkm_nickname[256][6];
    quint8  cpu_pkm_level[256][6];
    quint32 cpu_pkm_experience[256][6];
    quint16 cpu_pkm_ev_hp[256][6];
    quint16 cpu_pkm_ev_atk[256][6];
    quint16 cpu_pkm_ev_def[256][6];
    quint16 cpu_pkm_ev_spc[256][6];
    quint16 cpu_pkm_ev_speed[256][6];
    quint16 cpu_pkm_ivs[256][6];
    quint8  cpu_pkm_iv_hp[256][6];
    quint8  cpu_pkm_iv_atk[256][6];
    quint8  cpu_pkm_iv_def[256][6];
    quint8  cpu_pkm_iv_spc[256][6];
    quint8  cpu_pkm_iv_speed[256][6];
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
    quint16 cpu_pkm_stat_hp[256][6];
    quint16 cpu_pkm_stat_atk[256][6];
    quint16 cpu_pkm_stat_def[256][6];
    quint16 cpu_pkm_stat_spc[256][6];
    quint16 cpu_pkm_stat_speed[256][6];

    quint32 experience_calc;
    quint32 experience_max[6];
    quint8 experience_param_1[6];
    quint8 experience_param_2[6];
    quint8 experience_param_3[6];
    quint8 experience_param_4[6];

    quint8 glc_level_min;
    quint8 glc_level_max;

    quint8 move_iid[256];
    QString move_description[256];
    quint16 move_description_pointer[256];
    QString move_name[256];
    quint16 move_name_pointer[256];
    quint8 move_tmhm[256];
    quint8 move_tmhm_byte;
    quint8 move_tmhm_flag;
    QList<QCheckBox*> move_tmhm_list;
    QString move_tmhm_text[256];
    quint8 move_effect[256];
    quint8 move_power[256];
    quint8 move_type[256];
    quint8 move_accuracy[256];
    quint8 move_pp[256];
    quint8 move_high_ch[4];
    quint8 move_high_ch_multiplier;
    bool strong_move[256] = {false};
    bool useless_move[256] = {false};
    bool weak_move[256] = {false};

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
    quint8 pkm_min_level[256];
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

    std::vector<quint8> gambler_moves_ids_vector;
    std::vector<quint8> moves_ids_vector;
    std::vector<quint8> strong_moves_ids_vector;
    std::vector<quint8> pkm_ids_vector_petitcup;
    std::vector<quint8> pkm_ids_vector_petitcup_gambler;
    std::vector<quint8> pkm_ids_vector_petitcup_toptier;
    std::vector<quint8> pkm_ids_vector_pikacup;
    std::vector<quint8> pkm_ids_vector_pikacup_gambler;
    std::vector<quint8> pkm_ids_vector_pikacup_toptier;
    std::vector<quint8> pkm_ids_vector_primecup;
    std::vector<quint8> pkm_ids_vector_primecup_gambler;
    std::vector<quint8> pkm_ids_vector_primecup_toptier;
    std::vector<quint8> pkm_ids_vector_pokecup;
    std::vector<quint8> pkm_ids_vector_pokecup_gambler;
    std::vector<quint8> pkm_ids_vector_pokecup_toptier;
    std::vector<quint8> pkm_ids_vector_vs_mewtwo;
    std::vector<quint8> pkm_ids_vector_vs_mewtwo_toptier;

    quint16 pokedex_entry_pointer[256];
    QString pokedex_entry[256];

    QString preset_nicknames[256][10];

    quint32 prng_seed[6];

    quint8  rental_cup_id[1024];
    quint8  rental_cup_offset[256];
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
    quint8  rental_pkm_ppup_1[1024];
    quint8  rental_pkm_ppup_2[1024];
    quint8  rental_pkm_ppup_3[1024];
    quint8  rental_pkm_ppup_4[1024];
    quint16 rental_pkm_stat_hp[1024];
    quint16 rental_pkm_stat_atk[1024];
    quint16 rental_pkm_stat_def[1024];
    quint16 rental_pkm_stat_spc[1024];
    quint16 rental_pkm_stat_speed[1024];

    QString type_name[256];

private:
    Ui::MainWindow *ui;

    // randomizer
    void randomize_init_pkmn();
    void randomize_cpu_level(std::mt19937 &mt_rand);
    void randomize_cpu_moves(std::mt19937 &mt_rand);
    void randomize_cpu_pkmn(std::mt19937 &mt_rand);

private slots:
    // romfile
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void write_pkm_data(QFile &romfile);
    void write_cpu_rentals(QFile &romfile);

    // autoconnect randomizer
    void on_pushButton_Randomize_CPU_Teams_pressed();
    void on_pushButton_CPU_Metronome_pressed();
    void on_pushButton_Rental_Metronome_pressed();
    void on_pushButton_Maximize_CPU_EVsIVs_pressed();
    void on_pushButton_Maximize_Rental_EVsIVs_pressed();
    void on_checkBox_Randomizer_Rental_MaxPPUps_stateChanged(int state);
    void on_checkBox_Randomizer_Rental_NoPPUps_stateChanged(int state);

    // autoconnect display
    void on_comboBox_CPU_Cup_currentIndexChanged(int);
    void on_comboBox_CPU_Trainer_currentIndexChanged(int);
    void on_comboBox_Rental_Cup_currentIndexChanged(int);
    void on_comboBox_Rental_Page_currentIndexChanged(int);
    void on_comboBox_MovesList_currentIndexChanged(int);
    void on_comboBox_PokemonSpecies_currentIndexChanged(int);

    // edit cpu trainer
    void on_comboBox_Move1_1_currentIndexChanged(int);
    void on_comboBox_Move2_1_currentIndexChanged(int);
    void on_comboBox_Move3_1_currentIndexChanged(int);
    void on_comboBox_Move4_1_currentIndexChanged(int);
    void on_comboBox_Move1_2_currentIndexChanged(int);
    void on_comboBox_Move2_2_currentIndexChanged(int);
    void on_comboBox_Move3_2_currentIndexChanged(int);
    void on_comboBox_Move4_2_currentIndexChanged(int);
    void on_comboBox_Move1_3_currentIndexChanged(int);
    void on_comboBox_Move2_3_currentIndexChanged(int);
    void on_comboBox_Move3_3_currentIndexChanged(int);
    void on_comboBox_Move4_3_currentIndexChanged(int);
    void on_comboBox_Move1_4_currentIndexChanged(int);
    void on_comboBox_Move2_4_currentIndexChanged(int);
    void on_comboBox_Move3_4_currentIndexChanged(int);
    void on_comboBox_Move4_4_currentIndexChanged(int);
    void on_comboBox_Move1_5_currentIndexChanged(int);
    void on_comboBox_Move2_5_currentIndexChanged(int);
    void on_comboBox_Move3_5_currentIndexChanged(int);
    void on_comboBox_Move4_5_currentIndexChanged(int);
    void on_comboBox_Move1_6_currentIndexChanged(int);
    void on_comboBox_Move2_6_currentIndexChanged(int);
    void on_comboBox_Move3_6_currentIndexChanged(int);
    void on_comboBox_Move4_6_currentIndexChanged(int);

    void on_comboBox_Pkmn_1_currentIndexChanged(int);
    void on_comboBox_Pkmn_2_currentIndexChanged(int);
    void on_comboBox_Pkmn_3_currentIndexChanged(int);
    void on_comboBox_Pkmn_4_currentIndexChanged(int);
    void on_comboBox_Pkmn_5_currentIndexChanged(int);
    void on_comboBox_Pkmn_6_currentIndexChanged(int);

    void on_spinBox_CPU_AI_valueChanged(int);
    void on_spinBox_CPU_PartySize_valueChanged(int);

    void on_spinBox_EV_HP_1_valueChanged(int);
    void on_spinBox_EV_HP_2_valueChanged(int);
    void on_spinBox_EV_HP_3_valueChanged(int);
    void on_spinBox_EV_HP_4_valueChanged(int);
    void on_spinBox_EV_HP_5_valueChanged(int);
    void on_spinBox_EV_HP_6_valueChanged(int);
    void on_spinBox_EV_Attack_1_valueChanged(int);
    void on_spinBox_EV_Attack_2_valueChanged(int);
    void on_spinBox_EV_Attack_3_valueChanged(int);
    void on_spinBox_EV_Attack_4_valueChanged(int);
    void on_spinBox_EV_Attack_5_valueChanged(int);
    void on_spinBox_EV_Attack_6_valueChanged(int);
    void on_spinBox_EV_Defense_1_valueChanged(int);
    void on_spinBox_EV_Defense_2_valueChanged(int);
    void on_spinBox_EV_Defense_3_valueChanged(int);
    void on_spinBox_EV_Defense_4_valueChanged(int);
    void on_spinBox_EV_Defense_5_valueChanged(int);
    void on_spinBox_EV_Defense_6_valueChanged(int);
    void on_spinBox_EV_Special_1_valueChanged(int);
    void on_spinBox_EV_Special_2_valueChanged(int);
    void on_spinBox_EV_Special_3_valueChanged(int);
    void on_spinBox_EV_Special_4_valueChanged(int);
    void on_spinBox_EV_Special_5_valueChanged(int);
    void on_spinBox_EV_Special_6_valueChanged(int);
    void on_spinBox_EV_Speed_1_valueChanged(int);
    void on_spinBox_EV_Speed_2_valueChanged(int);
    void on_spinBox_EV_Speed_3_valueChanged(int);
    void on_spinBox_EV_Speed_4_valueChanged(int);
    void on_spinBox_EV_Speed_5_valueChanged(int);
    void on_spinBox_EV_Speed_6_valueChanged(int);

    void on_spinBox_IV_Attack_1_valueChanged(int);
    void on_spinBox_IV_Attack_2_valueChanged(int);
    void on_spinBox_IV_Attack_3_valueChanged(int);
    void on_spinBox_IV_Attack_4_valueChanged(int);
    void on_spinBox_IV_Attack_5_valueChanged(int);
    void on_spinBox_IV_Attack_6_valueChanged(int);
    void on_spinBox_IV_Defense_1_valueChanged(int);
    void on_spinBox_IV_Defense_2_valueChanged(int);
    void on_spinBox_IV_Defense_3_valueChanged(int);
    void on_spinBox_IV_Defense_4_valueChanged(int);
    void on_spinBox_IV_Defense_5_valueChanged(int);
    void on_spinBox_IV_Defense_6_valueChanged(int);
    void on_spinBox_IV_Special_1_valueChanged(int);
    void on_spinBox_IV_Special_2_valueChanged(int);
    void on_spinBox_IV_Special_3_valueChanged(int);
    void on_spinBox_IV_Special_4_valueChanged(int);
    void on_spinBox_IV_Special_5_valueChanged(int);
    void on_spinBox_IV_Special_6_valueChanged(int);
    void on_spinBox_IV_Speed_1_valueChanged(int);
    void on_spinBox_IV_Speed_2_valueChanged(int);
    void on_spinBox_IV_Speed_3_valueChanged(int);
    void on_spinBox_IV_Speed_4_valueChanged(int);
    void on_spinBox_IV_Speed_5_valueChanged(int);
    void on_spinBox_IV_Speed_6_valueChanged(int);

    void on_spinBox_Lv_1_valueChanged(int);
    void on_spinBox_Lv_2_valueChanged(int);
    void on_spinBox_Lv_3_valueChanged(int);
    void on_spinBox_Lv_4_valueChanged(int);
    void on_spinBox_Lv_5_valueChanged(int);
    void on_spinBox_Lv_6_valueChanged(int);

    void on_spinBox_PPUp1_1_valueChanged(int);
    void on_spinBox_PPUp2_1_valueChanged(int);
    void on_spinBox_PPUp3_1_valueChanged(int);
    void on_spinBox_PPUp4_1_valueChanged(int);
    void on_spinBox_PPUp1_2_valueChanged(int);
    void on_spinBox_PPUp2_2_valueChanged(int);
    void on_spinBox_PPUp3_2_valueChanged(int);
    void on_spinBox_PPUp4_2_valueChanged(int);
    void on_spinBox_PPUp1_3_valueChanged(int);
    void on_spinBox_PPUp2_3_valueChanged(int);
    void on_spinBox_PPUp3_3_valueChanged(int);
    void on_spinBox_PPUp4_3_valueChanged(int);
    void on_spinBox_PPUp1_4_valueChanged(int);
    void on_spinBox_PPUp2_4_valueChanged(int);
    void on_spinBox_PPUp3_4_valueChanged(int);
    void on_spinBox_PPUp4_4_valueChanged(int);
    void on_spinBox_PPUp1_5_valueChanged(int);
    void on_spinBox_PPUp2_5_valueChanged(int);
    void on_spinBox_PPUp3_5_valueChanged(int);
    void on_spinBox_PPUp4_5_valueChanged(int);
    void on_spinBox_PPUp1_6_valueChanged(int);
    void on_spinBox_PPUp2_6_valueChanged(int);
    void on_spinBox_PPUp3_6_valueChanged(int);
    void on_spinBox_PPUp4_6_valueChanged(int);
    void on_spinBox_TrainerSpriteID_valueChanged(int);

    // edit movedata
    void on_spinBox_HighCH_multiplier_valueChanged(int);

    // initialize
    void initialize_char_table();
    void initialize_data();
    void initialize_min_levels();
    void initialize_nicknames();
    void initialize_widgets();
    void set_widgets();

    // display, read
    int  calc_experience(quint8 exp_group, quint8 level);
    void calc_experience_max();
    void display_cpu_trainer_pkmn(quint8 cpu_trainer_id);
    void display_cpu_trainer_sprite(quint8 cpu_trainer_sprite_id);
    void display_experience_max();
    void display_move_data(quint8 move_id);
    void display_pkm_data(quint8 pkm_id);
    void display_rental_pkmn(quint16 rental_pkm_offset);
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

    // prng
    void prng_seeds();

    // rom check
    void rom_check();
};

#endif // MAINWINDOW_H
