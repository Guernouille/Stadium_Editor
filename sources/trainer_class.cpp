#include "trainer_class.h"

bool is_petit_trainer(const Trainer& trainer)
{
    return (trainer.cup_id == 0) || (trainer.cup_id == 22);
}

bool is_pika_trainer(const Trainer& trainer)
{
    return (trainer.cup_id == 1) || (trainer.cup_id == 23);
}

bool is_prime_trainer(const Trainer& trainer)
{
    return ((trainer.cup_id >= 2) && (trainer.cup_id <= 5))
            || ((trainer.cup_id >= 24) && (trainer.cup_id <= 27));
}

bool is_poke_trainer(const Trainer& trainer)
{
    return ((trainer.cup_id >= 6) && (trainer.cup_id <= 9))
            || ((trainer.cup_id >= 28) && (trainer.cup_id <= 31));
}

bool is_glc_trainer(const Trainer& trainer)
{
    return ((trainer.cup_id >= 10) && (trainer.cup_id <= 19))
            || ((trainer.cup_id >= 32) && (trainer.cup_id <= 41));
}

bool is_mewtwo_trainer(const Trainer& trainer)
{
    return (trainer.cup_id == 20) || (trainer.cup_id == 42);
}

bool is_battle_now_trainer(const Trainer& trainer)
{
    return (trainer.cup_id == 21) || (trainer.cup_id == 43);
}
