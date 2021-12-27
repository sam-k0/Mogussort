#ifndef MATHEDEALER_H
#define MATHEDEALER_H
#include <cmath>
#include <random>
#include <chrono>
/// EXTERN

//Variablen
bool RandomGen_initialised = false;
std::default_random_engine Generator;
std::uniform_int_distribution<int> Distribution;


//Funktionen von extern
int Num_random(int Min, int Max) noexcept
{
    if (Max < Min)
        std::swap(Min, Max);

    if (RandomGen_initialised == false)
    {
        unsigned int Seed = std::chrono::system_clock::now().time_since_epoch().count();
        Generator = std::default_random_engine(Seed);
        RandomGen_initialised = true;
    }

    if (std::uniform_int_distribution<int>(Min, Max) != Distribution)
    {
        Distribution = std::uniform_int_distribution<int>(Min, Max);
    }

    return Distribution(Generator);
}

//Quelle: https://www.cplusplus.com/reference/random/linear_congruential_engine/seed/





#endif // MATHEDEALER_H