#ifndef TRAINER_CLASS_H
#define TRAINER_CLASS_H

#include <array>

#include <QString>
#include <QtGlobal>

struct Trainer
{
    quint8 cup_id;
    QString name;
    quint8 sprite_id;
    quint8 ai_id;
    quint8 party_size;
    std::array<quint8, 6> pkm_ids;
};

bool is_petit_trainer(const Trainer&);
bool is_pika_trainer(const Trainer&);
bool is_prime_trainer(const Trainer&);
bool is_poke_trainer(const Trainer&);
bool is_glc_trainer(const Trainer&);
bool is_mewtwo_trainer(const Trainer&);
bool is_battle_now_trainer(const Trainer&);

#endif // TRAINER_CLASS_H
