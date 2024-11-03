#include "Simulate.h"

// variables

mutex resultMutex;

// functions

void simulatePortion(int start, int end, int* results, int deckSize, int totalValidCards, int sizeOfHand, int Deviser, int& DeviserPercent) 
{
    for (int i = start; i < end; i++) 
    {
        bool simulatedDeck[deckSize] = {false}; // Reset deck: all cards initially invalid
        int validCardsPlaced = 0;

        // Randomly place 8 valid cards in the deck
        while (validCardsPlaced < totalValidCards) 
        {
            int position = getRandomInt(0, deckSize - 1);
            if (!simulatedDeck[position]) 
            {
                simulatedDeck[position] = true;
                validCardsPlaced++;
            }
        }

        // Draw 5 unique cards and count valid ones
        int validCardsInHand = 0;
        unordered_set<int> drawnCards;

        for (int j = 0; j < sizeOfHand; j++) 
        {
            int drawPosition;
            do 
            {
                drawPosition = getRandomInt(0, deckSize - 1);
            } 
            while (drawnCards.count(drawPosition));

            drawnCards.insert(drawPosition);
            if (simulatedDeck[drawPosition]) 
            {
                validCardsInHand++;
            }
        }

        // Thread-safe increment of result counts
        {
            lock_guard<mutex> lock(resultMutex);
            results[validCardsInHand]++;
        }

        // Progress output
        if (i % Deviser == 0)
        {
            lock_guard<mutex> lock(resultMutex);
            cout << DeviserPercent * 10 << "%" << endl;
            DeviserPercent++;
        }
    }
}
