#include "Queue.cpp"
#include "Stack.cpp"
#include "Card.cpp"

#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
int main() {
    Queue myQueue;
    int numPairs = 6;  

    myQueue.createShuffledDeck(numPairs);

    std::cout << "Shuffled Deck: ";
    myQueue.printCards();

    // Don't forget to free memory
    myQueue.deleteDeck();

    return 0;

}