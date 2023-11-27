#include "Queue.hpp"
#include "Card.hpp"

#ifdef LLQUEUE

Queue::Queue(int) : myFront(NULL), myBack(NULL) {} // numElements is ignored

Queue::Queue(const Queue& original) {
    if (original.empty()) {
        myFront = myBack = NULL;
    }
    else {
        myFront = myBack = new Queue::Node(original.front());
        Queue::NodePointer origPtr = original.myFront->next;
        while (origPtr != NULL) {
            myBack->next = new Queue::Node(origPtr->data);
            myBack = myBack->next;
            origPtr = origPtr->next;
        }
    }
}

Queue::~Queue() {
    Queue::NodePointer currPtr = myFront, nextPtr = NULL;
    while (currPtr != NULL) {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

const Queue& Queue::operator=(const Queue& rhs) {
    if (this != &rhs) {
        this->~Queue();
        if (rhs.empty()) {
            myFront = myBack = NULL;
        }
        else {
            myFront = myBack = new Queue::Node(rhs.front());
            Queue::NodePointer rhsPtr = rhs.myFront->next;
            while (rhsPtr != NULL) {
                myBack->next = new Queue::Node(rhsPtr->data);
                myBack = myBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

bool Queue::empty() const {
    return myFront == NULL;
}

void Queue::enqueue(const QueueElement& value) {
    Queue::NodePointer newptr = new Queue::Node(value);
    if (empty()) {
        myFront = myBack = newptr;
    }
    else {
        myBack->next = newptr;
        myBack = newptr;
    }
}

void Queue::display(ostream& out) const {
    if (empty()) {
        cerr << "Queue-empty!" << endl;
        return;
    }
    Queue::NodePointer myPtr = myFront;
    while (myPtr != NULL) {
        out << myPtr->data.CardName << ' ';
        myPtr = myPtr->next;
    }
    out << endl;
}

QueueElement Queue::front() const {
    if (!empty())
        return myFront->data;
    else {
        cerr << "Queue Empty -- Returning garbage." << endl;
        QueueElement garbage;
        return garbage;
    }
}

void Queue::dequeue() {
    if (!empty()) {
        Queue::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
        if (myFront == NULL)     // queue is now empty
            myBack = NULL;
    }
    else {
        cerr << "Queue Empty!" << endl;
    }
}

ostream& operator<< (ostream& out, const Queue& aQueue) {
    aQueue.display(out);
    return out;
}
// Function to shuffle a deck of cards into the queue
void Queue::createShuffledDeck( int numPairs) {
    // Create an array to store the cards
    Card cards[12];

    // Populate the array with pairs of cards
    for (int i = 0; i < numPairs; ++i) {
        
        cards[i * 2] = Card(i + 1);
        cards[i * 2 + 1] = Card(i + 1);
    }

    // Seed the random number generator
    std::srand(std::time(0));

    // Shuffle the cards using Fisher-Yates algorithm
    for (int i = numPairs * 2 - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    }

    // Build the queue
    for (int i = 0; i < numPairs * 2; ++i) {
        enqueue(cards[i]);
    }
}

// Function to print the cards in the queue
void Queue::printCards() {
    Node* current = myFront;
    while (current != nullptr) {
        std::cout << current->data.CardName << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to free memory allocated for the queue 
void Queue::deleteDeck() {
    while (myFront != nullptr) {
        Node* temp = myFront;
        myFront = myFront->next;
        delete temp;
    }
}
#endif // LLQUEUE