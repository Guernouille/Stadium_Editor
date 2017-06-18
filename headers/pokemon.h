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
};

#endif // POKEMON_H
