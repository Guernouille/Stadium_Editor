#ifndef TRAINER_CLASS_H
#define TRAINER_CLASS_H

#include <QtGlobal>

struct Trainer
{
    quint8 cup_id;
};

bool is_petit_trainer(const Trainer&);
bool is_pika_trainer(const Trainer&);
bool is_prime_trainer(const Trainer&);
bool is_poke_trainer(const Trainer&);
bool is_glc_trainer(const Trainer&);
bool is_mewtwo_trainer(const Trainer&);
bool is_battle_now_trainer(const Trainer&);

#endif // TRAINER_CLASS_H
