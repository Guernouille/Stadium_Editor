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
};

#endif // POKEMON_H
