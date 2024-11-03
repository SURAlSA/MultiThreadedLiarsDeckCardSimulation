#include "util.h"
#include "Simulate.h"



int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " n" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    const int deckSize = 20;
    const int totalValidCards = 8;
    const int sizeOfHand = 5;
    const int Deviser = n / 10;
    int DeviserPercent = 0;

    srand(time(0)); // Seed the random number generator

    int results[sizeOfHand + 1] = {0}; // Initialize results array

    int numThreads = 4; // Adjust thread count as needed
    int chunkSize = n / numThreads;
    vector<thread> threads;

    for (int i = 0; i < numThreads; i++) 
    {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? n : start + chunkSize;
        threads.emplace_back(simulatePortion, start, end, results, deckSize, totalValidCards, sizeOfHand, Deviser, ref(DeviserPercent));
    }

    // Join threads
    for (auto& t : threads) 
    {
        t.join();
    }

    cout << "100%" << endl;

    // Display results
    for (int j = 0; j <= sizeOfHand; j++) 
    {
        cout << j << " Valid Cards: " << results[j] << endl;
    }

    return 0;
}