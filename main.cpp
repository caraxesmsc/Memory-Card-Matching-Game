#include "Queue.hpp"
#include "Stack.hpp"
#include "Card.hpp"

#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
int main() {
    Queue myQueue;


    myQueue.createShuffledDeck();

    cout << "Shuffled Deck: ";
    myQueue.printCards();

    // Don't forget to free memory
    myQueue.deleteQueue();

    return 0;

}