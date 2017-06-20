#ifndef POKEMON_H
#define POKEMON_H

#include <QtGlobal>
#include <QString>

struct Pokemon
{
    quint8 id;
    QString nick;
    quint8 lvl;
    quint32 exp;

    quint16 hp_ev;
    quint16 atk_ev;
    quint16 def_ev;
    quint16 spc_ev;
    quint16 speed_ev;

    quint16 ivs;
    quint8 hp_iv;
    quint8 atk_iv;
    quint8 def_iv;
    quint8 spc_iv;
    quint8 speed_iv;

    quint8 move_1;
    quint8 move_2;
    quint8 move_3;
    quint8 move_4;

    quint8 pp_1;
    quint8 pp_2;
    quint8 pp_3;
    quint8 pp_4;

    quint8 ppup_1;
    quint8 ppup_2;
    quint8 ppup_3;
    quint8 ppup_4;
};

#endif // POKEMON_H
