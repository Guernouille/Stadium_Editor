#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
#include "ui_mainwindow.h"
#include "type_chart.h"
#include "common.cpp"
#include "trainer_class.h"

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
    quint32 header_PI_settings;
    quint32 header_clockrate;
    quint32 header_boot_address;
    quint32 header_release;
    quint32 header_crc1;
    quint32 header_crc2;
    quint32 header_reserved1;
    quint32 header_reserved2;
    quint32 header_name1;
    quint32 header_name2;
    quint32 header_name3;
    quint32 header_name4;
    quint32 header_name5;
    quint32 header_reserved3;
    quint32 header_rom_format;
    quint16 header_game_id;
    quint8  header_region_code;
    quint8  header_rom_version;
    QString img_path;
    QString widget_text;
    QString debug;
    bool not_in_init = true;

    bool    bufbool;
    quint8  buf8;
    quint16 buf16;
    qint16  buf16s;
    quint32 buf32;
    QString buf_text;
    quint32 rom_offset;
    QString char_table[256];

    quint8 total_cpu_rentals_array;
    quint8 total_cpu_rentals;
    quint8 total_move_name;
    quint8 total_move_description;
    quint8 total_pkm_name;
    quint8 total_pokedex_entry;
    quint8 total_type_name;

    quint8 bsmin_hp = 10;
    quint8 bsmin_atk = 40;
    quint8 bsmin_def = 20;
    quint8 bsmin_spc = 20;
    quint8 bsmin_speed = 20;
    quint16 bsmin_total = 110;
    quint8 bsmax_hp = 110;
    quint8 bsmax_atk = 130;
    quint8 bsmax_def = 120;
    quint8 bsmax_spc = 120;
    quint8 bsmax_speed = 120;
    quint16 bsmax_total = 600;
    quint16 bstmin_basic = 275;
    quint16 bstmin_stage1 = 350;
    quint16 bstmin_fullevo = 430;
    quint16 bstmin_legend = 480;
    quint16 bstmax_basic = 310;
    quint16 bstmax_stage1 = 400;
    quint16 bstmax_fullevo = 480;
    quint16 bstmax_legend = 500;
    quint16 bst_temp = 0;
    quint8 burn_shift = 1;
    quint8 burn_shiftvalue = 1;

    quint8 ch_fe_formula_add = 160;
    quint8 ch_fe_formula_shift = 0;
    quint8 ch_fe_formula_shiftvalue = 0;
    quint8 ch_formula_add = 76;
    quint8 ch_formula_shift[3] = {0};
    quint8 ch_formula_shiftvalue[3] = {0};

    quint16 current_rentals_number;
    quint8 current_rentals_cup;
    quint8 current_cpu_trainers_cup;
    quint8 current_cpu_trainers_number;

    quint16 cpu_rentals_arraylen[64];
    quint32 cpu_rentals_pointer[64];

    std::array<Trainer, 256> cpu_trainers;
    quint8  cpu_cup_offset[256];
    quint8  cpu_ivs_min = 2;
    quint8  cpu_ivs_max = 15;
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
    quint16 cpu_stat_exp_min = 25600;
    quint16 cpu_stat_exp_max = 65535;

    quint8 damage_variance_min = 217;

    quint32 experience_calc;
    quint32 experience_max[6];
    quint8 experience_param_1[6];
    quint8 experience_param_2[6];
    quint8 experience_param_3[6];
    quint8 experience_param_4[6];

    quint8 glc_level_min;
    quint8 glc_level_max;

    quint8 iv_statexp_groups[256] = {0};

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
    quint8 move_high_ch_shift = 0;
    quint8 move_high_ch_shiftvalue = 2;
    bool strong_move[256] = {false};
    bool useless_move[256] = {false};
    bool weak_move[256] = {false};
    quint8 moverand_min = 40;
    quint8 moverand_max = 125;

    std::vector<quint8> gambler_moves_ids_vector;
    std::vector<quint8> moves_ids_vector;
    std::vector<quint8> strong_moves_ids_vector;

    quint8 odds_paralysis = 63;

    QString pkm_name[256];
    quint16 pkm_name_pointer[256];
    quint8 pkm_base_hp[256];
    quint8 pkm_base_atk[256];
    quint8 pkm_base_def[256];
    quint8 pkm_base_spc[256];
    quint8 pkm_base_speed[256];
    quint8 pkm_base_experience[256];
    quint8 pkm_catch_rate[256];
    quint8 pkm_evo_stage[256] = {0};
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
    std::vector<quint8> pkm_ids_vector_glc_lowminlv;
    std::vector<quint8> pkm_ids_vector_vs_mewtwo;
    std::vector<quint8> pkm_ids_vector_vs_mewtwo_toptier;
    std::vector<quint8> pkm_ids_vector_rental_petitcup;
    std::vector<quint8> pkm_ids_vector_rental_pikacup;
    std::vector<quint8> pkm_ids_vector_rental_primecup;
    std::vector<quint8> pkm_ids_vector_rental_pokecup;

    quint16 pokedex_entry_pointer[256];
    QString pokedex_entry[256];

    QString preset_nicknames[256][10];
    QString preset_trainers_names[256][5];

    quint32 prng_seed[6];

    quint8  rental_cup_id[1024];
    quint16 rental_cup_offset[256];
    quint8  rental_ivs_min = 0;
    quint8  rental_ivs_max = 15;
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
    quint16 rental_stat_exp_min = 16500;
    quint16 rental_stat_exp_max = 64500;

    QSpinBox *spinBox_PRNG_Seed_1;
    QSpinBox *spinBox_PRNG_Seed_2;
    QSpinBox *spinBox_PRNG_Seed_3;
    QSpinBox *spinBox_PRNG_Seed_4;
    QSpinBox *spinBox_PRNG_Seed_5;
    QSpinBox *spinBox_PRNG_Seed_6;

    TypeChart type_chart[82];
    QString type_name[256];

private:
    Ui::MainWindow *ui;

    QSignalMapper *type1_combobox_mapper;
    QSignalMapper *type2_combobox_mapper;
    QSignalMapper *mult_spinbox_mapper;
    QSignalMapper *lvl_spinbox_mapper;

    QSignalMapper *move1_combobox_mapper;
    QSignalMapper *move2_combobox_mapper;
    QSignalMapper *move3_combobox_mapper;
    QSignalMapper *move4_combobox_mapper;

    std::vector<QComboBox*> type1_comboboxes;
    std::vector<QComboBox*> type2_comboboxes;
    std::vector<QSpinBox*> mult_spinboxes;
    std::vector<QSpinBox*> lvl_spinboxes;

    std::vector<QComboBox*> move1_comboboxes;
    std::vector<QComboBox*> move2_comboboxes;
    std::vector<QComboBox*> move3_comboboxes;
    std::vector<QComboBox*> move4_comboboxes;

    // type chart
    quint8 convert_type_id(quint8 type_id);

    // control
    quint8 control_char_table(QString character_id);

    // initialize
    void initialize_char_table();
    void initialize_data();
    void initialize_evo_stages();
    void initialize_iv_statexp_groups();
    void initialize_min_levels();
    void initialize_nicknames();
    void initialize_trainers_names();
    void initialize_widgets();
    void set_widgets();

    void init_type1_box_vec();
    void init_type2_box_vec();
    void init_mult_box_vec();
    void init_lvl_box_vec();
    void init_move_box_vecs();

    // N64 CRC fix
    void n64crc(QFile &romfile);

    // randomizer
    void randomize_cpu_init_pkmn();

    void init_petit_cup_pool();
    void init_pika_cup_pool();
    void init_prime_cup_pool();
    void init_poke_cup_pool();
    void init_glc_lowlvl_pool();
    void init_vs_mewtwo_pool();

    void randomize_cpu_iv_stat_exp(std::mt19937 &mt_rand);
    void randomize_cpu_level(std::mt19937 &mt_rand);
    void randomize_cpu_moves(std::mt19937 &mt_rand);
    void randomize_cpu_nicknames(std::mt19937 &mt_rand);
    void randomize_cpu_pkmn(std::mt19937 &mt_rand);
    void randomize_cpu_sprites(std::mt19937 &mt_rand);
    void randomize_cpu_trainer_names(std::mt19937 &mt_rand);
    void randomize_moves_accuracy(std::mt19937 &mt_rand);
    void randomize_moves_effects(std::mt19937 &mt_rand);
    void randomize_moves_power(std::mt19937 &mt_rand);
    void randomize_moves_pp(std::mt19937 &mt_rand);
    void randomize_moves_tmhm(std::mt19937 &mt_rand);
    void randomize_moves_types(std::mt19937 &mt_rand);
    void randomize_pkm_base_stats(std::mt19937 &mt_rand);
    void randomize_pkm_learnsets(std::mt19937 &mt_rand);
    void randomize_pkm_types(std::mt19937 &mt_rand);
    void randomize_rental_init_pkmn();
    void randomize_rental_iv_stat_exp(std::mt19937 &mt_rand);
    void randomize_rental_level(std::mt19937 &mt_rand);
    void randomize_rental_moves(std::mt19937 &mt_rand);
    void randomize_rental_pkmn(std::mt19937 &mt_rand);
    void randomize_type_chart(std::mt19937 &mt_rand);

    // pkm data parameters
    void refresh_bs_parameters();

private slots:
    // menu
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionAbout_triggered();
    void on_actionHelp_triggered();
    void on_actionPika_triggered();

    // romfile
    void write_burn_shift(QFile &romfile);
    void write_ch_formula(QFile &romfile);
    void write_cpu_rentals(QFile &romfile);
    void write_damage_variance(QFile &romfile);
    void write_highCH_shift(QFile &romfile);
    void write_move_data(QFile &romfile);
    void write_n64crc(QFile &romfile);
    void write_odds_paralysis(QFile &romfile);
    void write_pkm_data(QFile &romfile);
    void write_tmhm_data(QFile &romfile);
    void write_type_chart(QFile &romfile);

    // autoconnect randomizer
    void on_checkBox_Bug_vs_Poison_stateChanged(int state);
    void on_checkBox_CPUTeams_stateChanged(int state);
    void on_checkBox_Ghost_vs_Psychic_stateChanged(int state);
    void on_checkBox_Ice_vs_Fire_stateChanged(int state);
    void on_checkBox_MoveData_stateChanged(int state);
    void on_checkBox_PkmnData_stateChanged(int state);
    void on_checkBox_Randomize_CPU_IVsEVs_stateChanged(int state);
    void on_checkBox_Randomize_CPU_Levels_stateChanged(int state);
    void on_checkBox_Randomize_CPU_Moves_stateChanged(int state);
    void on_checkBox_Randomize_CPU_Pkmn_stateChanged(int state);
    void on_checkBox_Randomize_MoveData_Powers_stateChanged(int state);
    void on_checkBox_Randomize_PkmnData_BS_stateChanged(int state);
    void on_checkBox_Randomize_PkmnData_Moves_stateChanged(int state);
    void on_checkBox_Randomize_Rental_IVsEVs_stateChanged(int state);
    void on_checkBox_Randomize_Rental_Levels_stateChanged(int state);
    void on_checkBox_Randomize_Rental_Moves_stateChanged(int state);
    void on_checkBox_Randomize_Rental_Pkmn_stateChanged(int state);
    void on_checkBox_Randomize_TypeChart_stateChanged(int state);
    void on_checkBox_Randomizer_CPU_GLPkmn_stateChanged(int state);
    void on_checkBox_Randomizer_Rental_MaxPPUps_stateChanged(int state);
    void on_checkBox_Randomizer_Rental_NoPPUps_stateChanged(int state);
    void on_checkBox_Randomizer_Rental_NoIllegalMoves_stateChanged(int state);
    void on_checkBox_RentalPkmn_stateChanged(int state);
    void on_pushButton_CPU_Metronome_pressed();
    void on_pushButton_Maximize_CPU_EVsIVs_pressed();
    void on_pushButton_Maximize_Rental_EVsIVs_pressed();
    void on_pushButton_Randomize_pressed();
    void on_pushButton_Rental_Metronome_pressed();
    void on_spinBox_Randomizer_GLCLevelRange_1_valueChanged(int);
    void on_spinBox_Randomizer_GLCLevelRange_2_valueChanged(int);
    void on_spinBox_BSmax_HP_valueChanged(int);
    void on_spinBox_BSmax_ATK_valueChanged(int);
    void on_spinBox_BSmax_DEF_valueChanged(int);
    void on_spinBox_BSmax_SPC_valueChanged(int);
    void on_spinBox_BSmax_SPEED_valueChanged(int);
    void on_spinBox_BSmin_HP_valueChanged(int);
    void on_spinBox_BSmin_ATK_valueChanged(int);
    void on_spinBox_BSmin_DEF_valueChanged(int);
    void on_spinBox_BSmin_SPC_valueChanged(int);
    void on_spinBox_BSmin_SPEED_valueChanged(int);
    void on_spinBox_BSTmin_Basic_valueChanged(int);
    void on_spinBox_BSTmin_Stage1_valueChanged(int);
    void on_spinBox_BSTmin_FullyEvolved_valueChanged(int);
    void on_spinBox_BSTmin_Legend_valueChanged(int);
    void on_spinBox_BSTmax_Basic_valueChanged(int);
    void on_spinBox_BSTmax_Stage1_valueChanged(int);
    void on_spinBox_BSTmax_FullyEvolved_valueChanged(int);
    void on_spinBox_BSTmax_Legend_valueChanged(int);
    void on_spinBox_CPU_IVs_min_valueChanged(int);
    void on_spinBox_CPU_IVs_max_valueChanged(int);
    void on_spinBox_CPU_StatExp_min_valueChanged(int);
    void on_spinBox_CPU_StatExp_max_valueChanged(int);
    void on_spinBox_MoveData_minPower_valueChanged(int);
    void on_spinBox_MoveData_maxPower_valueChanged(int);
    void on_spinBox_Rental_IVs_min_valueChanged(int);
    void on_spinBox_Rental_IVs_max_valueChanged(int);
    void on_spinBox_Rental_StatExp_min_valueChanged(int);
    void on_spinBox_Rental_StatExp_max_valueChanged(int);

    // autoconnect display
    void on_comboBox_CPU_Cup_currentIndexChanged(int);
    void on_comboBox_CPU_Trainer_currentIndexChanged(int);
    void on_comboBox_Rental_Cup_currentIndexChanged(int);
    void on_comboBox_Rental_Page_currentIndexChanged(int);
    void on_comboBox_MovesList_currentIndexChanged(int);
    void on_comboBox_PokemonSpecies_currentIndexChanged(int);
    void on_comboBox_TMsHMsNames_currentIndexChanged(int);

    // edit cpu trainer
    void move1_combobox_changed(int);
    void move2_combobox_changed(int);
    void move3_combobox_changed(int);
    void move4_combobox_changed(int);

    void on_comboBox_Pkmn_1_currentIndexChanged(int);
    void on_comboBox_Pkmn_2_currentIndexChanged(int);
    void on_comboBox_Pkmn_3_currentIndexChanged(int);
    void on_comboBox_Pkmn_4_currentIndexChanged(int);
    void on_comboBox_Pkmn_5_currentIndexChanged(int);
    void on_comboBox_Pkmn_6_currentIndexChanged(int);

    void on_lineEdit_Nickname_1_textEdited();
    void on_lineEdit_Nickname_2_textEdited();
    void on_lineEdit_Nickname_3_textEdited();
    void on_lineEdit_Nickname_4_textEdited();
    void on_lineEdit_Nickname_5_textEdited();
    void on_lineEdit_Nickname_6_textEdited();

    void on_lineEdit_Rental_Nickname_1_textEdited();
    void on_lineEdit_Rental_Nickname_2_textEdited();
    void on_lineEdit_Rental_Nickname_3_textEdited();
    void on_lineEdit_Rental_Nickname_4_textEdited();
    void on_lineEdit_Rental_Nickname_5_textEdited();
    void on_lineEdit_Rental_Nickname_6_textEdited();

    void on_lineEdit_CPU_TrainerName_textEdited();

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

    void lv_spinbox_changed(int);

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

    // edit rental Pokémon
    void on_comboBox_Rental_Move1_1_currentIndexChanged(int);
    void on_comboBox_Rental_Move2_1_currentIndexChanged(int);
    void on_comboBox_Rental_Move3_1_currentIndexChanged(int);
    void on_comboBox_Rental_Move4_1_currentIndexChanged(int);
    void on_comboBox_Rental_Move1_2_currentIndexChanged(int);
    void on_comboBox_Rental_Move2_2_currentIndexChanged(int);
    void on_comboBox_Rental_Move3_2_currentIndexChanged(int);
    void on_comboBox_Rental_Move4_2_currentIndexChanged(int);
    void on_comboBox_Rental_Move1_3_currentIndexChanged(int);
    void on_comboBox_Rental_Move2_3_currentIndexChanged(int);
    void on_comboBox_Rental_Move3_3_currentIndexChanged(int);
    void on_comboBox_Rental_Move4_3_currentIndexChanged(int);
    void on_comboBox_Rental_Move1_4_currentIndexChanged(int);
    void on_comboBox_Rental_Move2_4_currentIndexChanged(int);
    void on_comboBox_Rental_Move3_4_currentIndexChanged(int);
    void on_comboBox_Rental_Move4_4_currentIndexChanged(int);
    void on_comboBox_Rental_Move1_5_currentIndexChanged(int);
    void on_comboBox_Rental_Move2_5_currentIndexChanged(int);
    void on_comboBox_Rental_Move3_5_currentIndexChanged(int);
    void on_comboBox_Rental_Move4_5_currentIndexChanged(int);
    void on_comboBox_Rental_Move1_6_currentIndexChanged(int);
    void on_comboBox_Rental_Move2_6_currentIndexChanged(int);
    void on_comboBox_Rental_Move3_6_currentIndexChanged(int);
    void on_comboBox_Rental_Move4_6_currentIndexChanged(int);

    void on_comboBox_Rental_Pkmn_1_currentIndexChanged(int);
    void on_comboBox_Rental_Pkmn_2_currentIndexChanged(int);
    void on_comboBox_Rental_Pkmn_3_currentIndexChanged(int);
    void on_comboBox_Rental_Pkmn_4_currentIndexChanged(int);
    void on_comboBox_Rental_Pkmn_5_currentIndexChanged(int);
    void on_comboBox_Rental_Pkmn_6_currentIndexChanged(int);

    void on_spinBox_Rental_EV_HP_1_valueChanged(int);
    void on_spinBox_Rental_EV_HP_2_valueChanged(int);
    void on_spinBox_Rental_EV_HP_3_valueChanged(int);
    void on_spinBox_Rental_EV_HP_4_valueChanged(int);
    void on_spinBox_Rental_EV_HP_5_valueChanged(int);
    void on_spinBox_Rental_EV_HP_6_valueChanged(int);
    void on_spinBox_Rental_EV_Attack_1_valueChanged(int);
    void on_spinBox_Rental_EV_Attack_2_valueChanged(int);
    void on_spinBox_Rental_EV_Attack_3_valueChanged(int);
    void on_spinBox_Rental_EV_Attack_4_valueChanged(int);
    void on_spinBox_Rental_EV_Attack_5_valueChanged(int);
    void on_spinBox_Rental_EV_Attack_6_valueChanged(int);
    void on_spinBox_Rental_EV_Defense_1_valueChanged(int);
    void on_spinBox_Rental_EV_Defense_2_valueChanged(int);
    void on_spinBox_Rental_EV_Defense_3_valueChanged(int);
    void on_spinBox_Rental_EV_Defense_4_valueChanged(int);
    void on_spinBox_Rental_EV_Defense_5_valueChanged(int);
    void on_spinBox_Rental_EV_Defense_6_valueChanged(int);
    void on_spinBox_Rental_EV_Special_1_valueChanged(int);
    void on_spinBox_Rental_EV_Special_2_valueChanged(int);
    void on_spinBox_Rental_EV_Special_3_valueChanged(int);
    void on_spinBox_Rental_EV_Special_4_valueChanged(int);
    void on_spinBox_Rental_EV_Special_5_valueChanged(int);
    void on_spinBox_Rental_EV_Special_6_valueChanged(int);
    void on_spinBox_Rental_EV_Speed_1_valueChanged(int);
    void on_spinBox_Rental_EV_Speed_2_valueChanged(int);
    void on_spinBox_Rental_EV_Speed_3_valueChanged(int);
    void on_spinBox_Rental_EV_Speed_4_valueChanged(int);
    void on_spinBox_Rental_EV_Speed_5_valueChanged(int);
    void on_spinBox_Rental_EV_Speed_6_valueChanged(int);

    void on_spinBox_Rental_IV_Attack_1_valueChanged(int);
    void on_spinBox_Rental_IV_Attack_2_valueChanged(int);
    void on_spinBox_Rental_IV_Attack_3_valueChanged(int);
    void on_spinBox_Rental_IV_Attack_4_valueChanged(int);
    void on_spinBox_Rental_IV_Attack_5_valueChanged(int);
    void on_spinBox_Rental_IV_Attack_6_valueChanged(int);
    void on_spinBox_Rental_IV_Defense_1_valueChanged(int);
    void on_spinBox_Rental_IV_Defense_2_valueChanged(int);
    void on_spinBox_Rental_IV_Defense_3_valueChanged(int);
    void on_spinBox_Rental_IV_Defense_4_valueChanged(int);
    void on_spinBox_Rental_IV_Defense_5_valueChanged(int);
    void on_spinBox_Rental_IV_Defense_6_valueChanged(int);
    void on_spinBox_Rental_IV_Special_1_valueChanged(int);
    void on_spinBox_Rental_IV_Special_2_valueChanged(int);
    void on_spinBox_Rental_IV_Special_3_valueChanged(int);
    void on_spinBox_Rental_IV_Special_4_valueChanged(int);
    void on_spinBox_Rental_IV_Special_5_valueChanged(int);
    void on_spinBox_Rental_IV_Special_6_valueChanged(int);
    void on_spinBox_Rental_IV_Speed_1_valueChanged(int);
    void on_spinBox_Rental_IV_Speed_2_valueChanged(int);
    void on_spinBox_Rental_IV_Speed_3_valueChanged(int);
    void on_spinBox_Rental_IV_Speed_4_valueChanged(int);
    void on_spinBox_Rental_IV_Speed_5_valueChanged(int);
    void on_spinBox_Rental_IV_Speed_6_valueChanged(int);

    void on_spinBox_Rental_Lv_1_valueChanged(int);
    void on_spinBox_Rental_Lv_2_valueChanged(int);
    void on_spinBox_Rental_Lv_3_valueChanged(int);
    void on_spinBox_Rental_Lv_4_valueChanged(int);
    void on_spinBox_Rental_Lv_5_valueChanged(int);
    void on_spinBox_Rental_Lv_6_valueChanged(int);

    void on_spinBox_Rental_PPUp1_1_valueChanged(int);
    void on_spinBox_Rental_PPUp2_1_valueChanged(int);
    void on_spinBox_Rental_PPUp3_1_valueChanged(int);
    void on_spinBox_Rental_PPUp4_1_valueChanged(int);
    void on_spinBox_Rental_PPUp1_2_valueChanged(int);
    void on_spinBox_Rental_PPUp2_2_valueChanged(int);
    void on_spinBox_Rental_PPUp3_2_valueChanged(int);
    void on_spinBox_Rental_PPUp4_2_valueChanged(int);
    void on_spinBox_Rental_PPUp1_3_valueChanged(int);
    void on_spinBox_Rental_PPUp2_3_valueChanged(int);
    void on_spinBox_Rental_PPUp3_3_valueChanged(int);
    void on_spinBox_Rental_PPUp4_3_valueChanged(int);
    void on_spinBox_Rental_PPUp1_4_valueChanged(int);
    void on_spinBox_Rental_PPUp2_4_valueChanged(int);
    void on_spinBox_Rental_PPUp3_4_valueChanged(int);
    void on_spinBox_Rental_PPUp4_4_valueChanged(int);
    void on_spinBox_Rental_PPUp1_5_valueChanged(int);
    void on_spinBox_Rental_PPUp2_5_valueChanged(int);
    void on_spinBox_Rental_PPUp3_5_valueChanged(int);
    void on_spinBox_Rental_PPUp4_5_valueChanged(int);
    void on_spinBox_Rental_PPUp1_6_valueChanged(int);
    void on_spinBox_Rental_PPUp2_6_valueChanged(int);
    void on_spinBox_Rental_PPUp3_6_valueChanged(int);
    void on_spinBox_Rental_PPUp4_6_valueChanged(int);

    //edit pkm data
    void on_comboBox_GrowthRate_currentIndexChanged(int);
    void on_comboBox_Pokemon_Type_1_currentIndexChanged(int);
    void on_comboBox_Pokemon_Type_2_currentIndexChanged(int);

    void on_spinBox_BaseExperience_valueChanged(int);
    void on_spinBox_CatchRate_valueChanged(int);
    void on_spinBox_Base_HP_valueChanged(int);
    void on_spinBox_Base_Attack_valueChanged(int);
    void on_spinBox_Base_Defense_valueChanged(int);
    void on_spinBox_Base_Special_valueChanged(int);
    void on_spinBox_Base_Speed_valueChanged(int);

    // edit move data
    void on_comboBox_HighCH_MovesList_1_currentIndexChanged(int);
    void on_comboBox_HighCH_MovesList_2_currentIndexChanged(int);
    void on_comboBox_HighCH_MovesList_3_currentIndexChanged(int);
    void on_comboBox_HighCH_MovesList_4_currentIndexChanged(int);
    void on_comboBox_MoveEffect_currentIndexChanged(int);
    void on_comboBox_MoveType_currentIndexChanged(int);

    void on_comboBox_FE_CH_formula_shift_2_currentIndexChanged(int);
    void on_spinBox_FE_CH_formula_add_2_valueChanged(int);
    void on_comboBox_CH_formula_shift_1_currentIndexChanged(int);
    void on_comboBox_CH_formula_shift_2_currentIndexChanged(int);
    void on_comboBox_CH_formula_shift_3_currentIndexChanged(int);
    void on_spinBox_CH_formula_add_valueChanged(int);
    void on_spinBox_CH_formula_shiftvalue_1_valueChanged(int);
    void on_spinBox_CH_formula_shiftvalue_2_valueChanged(int);
    void on_spinBox_CH_formula_shiftvalue_3_valueChanged(int);
    void on_spinBox_MoveAccuracy_valueChanged(int);
    void on_spinBox_MovePower_valueChanged(int);
    void on_spinBox_MovePP_valueChanged(int);

    // edit battle mechanics
    void on_comboBox_HighCH_shift_currentIndexChanged(int);
    void on_comboBox_Status_Burn_shift_currentIndexChanged(int);
    void on_spinBox_DamageVariance_1_valueChanged(int);
    void on_spinBox_HighCH_shiftvalue_valueChanged(int);
    void on_spinBox_Status_Burn_shiftvalue_valueChanged(int);
    void on_spinBox_Status_Paralysis_probability_valueChanged(int);

    // edit type data
    void type1_box_changed(int);
    void type2_box_changed(int);
    void mult_spinbox_changed(int);

    // display, read
    int  calc_experience(quint8 exp_group, quint8 level);
    void calc_experience_max();
    void display_cpu_trainer_pkmn(quint8 cpu_trainer_id);
    void display_cpu_trainer_sprite(quint8 cpu_trainer_sprite_id);
    void display_experience_max();
    void display_move_data(quint8 move_id);
    void display_pkm_data(quint8 pkm_id);
    void display_rental_pkmn(quint16 rental_pkm_offset);
    void display_tmhm_data();
    void display_type_chart();
    void read_burn_shift(QFile &romfile);
    void read_ch_formula(QFile &romfile);
    void read_cpu_rentals(QFile &romfile);
    void read_damage_variance(QFile &romfile);
    void read_experience_data(QFile &romfile);
    void read_highCH_shift(QFile &romfile);
    void read_move_data(QFile &romfile);
    void read_move_descriptions(QFile &romfile);
    void read_move_names(QFile &romfile);
    void read_odds_paralysis(QFile &romfile);
    void read_pkm_data(QFile &romfile);
    void read_pkm_names(QFile &romfile);
    void read_pokedex_data(QFile &romfile);
    void read_tmhm_data(QFile &romfile);
    void read_type_chart(QFile &romfile);
    void read_type_names(QFile &romfile);

    // prng
    void prng_seeds();

    // rom check
    void rom_check();
};

#endif // MAINWINDOW_H
