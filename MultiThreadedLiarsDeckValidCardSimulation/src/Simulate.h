#ifndef SIMULATE_H
#define SIMULATE_H

#include "util.h"

// structs

// classes

// variables

extern mutex resultMutex;

// functions

void simulatePortion(int start, int end, int* result, int deckSize, int totalValidCards, int sizeOfHand, int Deviser, int& DeviserPercent);

#endif
