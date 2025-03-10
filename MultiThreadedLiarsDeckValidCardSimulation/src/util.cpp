#include "util.h"

// functions
random_device rd;
mt19937 generator(rd());

int getRandomInt(int min, int max)
{
    uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

