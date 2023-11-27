#include "Card.hpp"
#ifndef QUEUE
#define QUEUE

// #define SQUEUE
// #define DQUEUE
#define LLQUEUE

#include <iostream>
using namespace std;
typedef Card QueueElement;
const int DEFAULT_CAPACITY = 128;

class Queue {

public:
    Queue(int numElements = DEFAULT_CAPACITY);
    Queue(const Queue& original);
    ~Queue();
    const Queue& operator= (const Queue& rhs);
    bool empty() const;
    void enqueue(const QueueElement& value);
    void display(ostream& out) const;
    QueueElement front() const;
    void dequeue();
    void deleteDeck();
    void printCards();
    void createShuffledDeck(int numPairs);
private:
#ifdef SQUEUE
    QueueElement myArray[DEFAULT_CAPACITY];
#else
    QueueElement* myArray;
#endif


#ifdef LLQUEUE
    class Node {
    public:
        QueueElement data;
        Node* next;
        Node(QueueElement value, Node* link = 0) : data(value), next(link) {}
    };
    typedef Node* NodePointer;
    NodePointer myFront, myBack;
#else
    int myFront, myBack, myCapacity;
#endif
};

ostream& operator<< (ostream& out, const Queue& aList);

#endif /* QUEUE */
