#include "Queue.hpp"
#include "Card.hpp"

Queue::Queue() {
}
Queue::Queue(int numElements) {
    myFront = myBack = nullptr;
#ifndef LLQUEUE
    myCapacity = numElements;
#endif
}

Queue::Queue(const Queue& original) {
    myFront = myBack = nullptr;
#ifndef LLQUEUE
    myCapacity = original.myCapacity;
#endif
    if (!original.empty()) {
        *this = original;
    }
}

Queue::~Queue() {
    deleteQueue();
}

const Queue& Queue::operator= (const Queue& rhs) {
    if (this != &rhs) {
        deleteQueue();
#ifdef LLQUEUE
        Node* rhsCurrent = rhs.myFront;
        while (rhsCurrent != nullptr) {
            enqueue(rhsCurrent->data);
            rhsCurrent = rhsCurrent->next;
        }
#else
        myBack = myFront + (rhs.myBack - rhs.myFront);
        for (int i = 0; i <= rhs.myBack; ++i) {
            myArray[i] = rhs.myArray[i];
        }
#endif
    }
    return *this;
}

bool Queue::empty() const {
    return myFront == nullptr;
}

void Queue::enqueue(const QueueElement& value) {
#ifdef LLQUEUE
    Node* newNode = new Node(value);
    if (empty()) {
        myFront = myBack = newNode;
    }
    else {
        myBack->next = newNode;
        myBack = newNode;
    }
#else
    if (myBack >= myCapacity - 1) {
        cerr << "Queue Full!" << endl;
    }
    else {
        myBack = (myBack + 1) % myCapacity;
        myArray[myBack] = value;
        if (myFront == -1) {
            myFront = 0;
        }
    }
#endif
}

void Queue::display(ostream& out) const {
    Node* current = myFront;
    while (current != nullptr) {
        out << current->data.CardName << " ";
        current = current->next;
    }
    out << endl;
}

QueueElement Queue::front() const {
    if (empty()) {
        cerr << "Queue Empty!" << endl;
        return QueueElement();
    }
    else {
        return myFront->data;
    }
}

void Queue::dequeue() {
    if (empty()) {
        cout << "Queue Empty!" << endl;
    }
    else {
#ifdef LLQUEUE
        Node* temp = myFront;
        myFront = myFront->next;
        if (myFront == nullptr) {
            myBack = nullptr;
        }
        delete temp;
#else
        myFront = (myFront + 1) % myCapacity;
#endif
    }
}

void Queue::deleteQueue() {
    while (myFront != nullptr) {
        Node* temp = myFront;
        myFront = myFront->next;
        delete temp;
    }
    myBack = nullptr;
}

void Queue::printCards() {
    Node* current = myFront;
    while (current != nullptr) {
        cout << current->data.CardName << " ";
        current = current->next;
    }
    cout << endl;
}

void Queue::createShuffledDeck() {
    // Create an array to store the cards
    Card cards[12];
    std::string SUIT_NAMES[4] = { "Hearts", "Spades", "Clubs", "Diamonds" };
    // Populate the array with Card objects
    for (int i = 0; i < 4; i++) {
        cards[i] = Card("Ace of " + string(SUIT_NAMES[i]));
        cards[i + 4] = Card("2 of " + string(SUIT_NAMES[i]));
        cards[i + 8] = Card("3 of " + string(SUIT_NAMES[i]));
    }

    // Shuffle the cards array
    for (int i = 0; i < 12; i++) {
        int index = rand() % 12;
        Card temp = cards[i];
        cards[i] = cards[index];
        cards[index] = temp;
    }

    // Add the shuffled cards to the deck
    for (int i = 0; i < 12; i++) {
        enqueue(cards[i]);
    }
}