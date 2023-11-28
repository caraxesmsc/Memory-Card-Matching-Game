#include "Queue.hpp"
#ifdef LLQUEUE

Queue::Queue(int numElements) : myFront(NULL), myBack(NULL), myArray(new QueueElement[numElements]) {
    // Initialize other variables if needed
}
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
        out << myPtr->data << ' ';
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


// Example in Queue.cpp
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

    // Initialize garbage with a value
    QueueElement garbage = 0;  // Assign a meaningful value
}


ostream& operator<< (ostream& out, const Queue& aQueue) {
    aQueue.display(out);
    return out;
}

void Queue::displayGrid() {
    //Node* head = cardQueue.myFront;

        for (int i = 0; i < 12; i++) {
            cout << " [" << i << "]";
            if ((i + 1) % 3 == 0) {
                cout << endl;
            }
            //head = head->next;
        }
        
    
}
bool Queue::isMatched(int loc1, int loc2) {
    Queue::Node * head1 = myFront;
    Queue::Node * head2 = myFront;
    
    for (int i = 0; i < loc1; i++){
        head1 = head1->next;
    }
    for (int i = 0; i < loc2; i++){
        head2 = head2->next;
    }
    return head1->data == head2->data;
}

#endif // LLQUEUE

