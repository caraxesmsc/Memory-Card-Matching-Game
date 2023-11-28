/*-- LQueue.h -------------------------------------------------------------

 This header file defines a Queue data type.
 Basic operations:
 constructor:  Constructs an empty queue
 empty:        Checks if a queue is empty
 enqueue:      Modifies a queue by adding a value at the back
 front:        Accesses the top queue value; leaves queue unchanged
 dequeue:      Modifies queue by removing the value at the front
 display:      Displays all the queue elements
 Note: Execution terminates if memory isn't available for a queue element.
 ---------------------------------------------------------------------------*/

#ifndef Queue_hpp
#define Queue_hpp
#include "Card.h"
#include <stdio.h>
#include <iostream>
using namespace std;


class Queue
{
public:
    /***** Function Members *****/
    /***** Constructors *****/

    Queue();
    /*-----------------------------------------------------------------------
     Construct a Queue object.

     Precondition:  None.
     Postcondition: An empty Queue object has been constructed.
     (myFront and myBack are initialized to null pointers).
     -----------------------------------------------------------------------*/

    Queue(const Queue& original);
    /*-----------------------------------------------------------------------
     Copy Constructor

     Precondition:  original is the queue to be copied and is received
     as a const reference parameter.
     Postcondition: A copy of original has been constructed.
     -----------------------------------------------------------------------*/

     /***** Destructor *****/
    ~Queue();
    /*-----------------------------------------------------------------------
     Class destructor

     Precondition:  None.
     Postcondition: The linked list in the queue has been deallocated.
     -----------------------------------------------------------------------*/

     /***** Assignment *****/
    const Queue& operator= (const Queue& rightHandSide);
    /*-----------------------------------------------------------------------
     Assignment Operator

     Precondition:  rightHandSide is the queue to be assigned and is
     received as a const reference parameter.
     Postcondition: The current queue becomes a copy of rightHandSide
     and a reference to it is returned.
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.

     Precondition:  None.
     Postcondition: Returns true if queue is empty and false otherwise.
     -----------------------------------------------------------------------*/

    void enqueue(const Card& value);
    /*-----------------------------------------------------------------------
     Add a value to a queue.

     Precondition:  value is to be added to this queue.
     Postcondition: value is added at back of queue.
     -----------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*-----------------------------------------------------------------------
     Display values stored in the queue.

     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been
     output to out.
     -----------------------------------------------------------------------*/

    Card front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless the queue
     is empty; in that case, an error message is displayed and a
     "garbage value" is returned.
     -----------------------------------------------------------------------*/

    void dequeue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    void deleteQueue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    void printCards();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    void displayGrid();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    void createShuffledQueue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    void shuffleArray(int arr[], int size);
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    bool ismatched(Queue& card1, Queue& card2);
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    bool checkMatch(int loc1, int loc2, Queue& card1, Queue& card2);
    int chooseCard();
    //private:
        /*** Node class ***/
    class Node
    {
    public:
        Card data;
        Node* next;
        //--- Node constructor
        Node(Card value, Node* link = 0)
            /*-------------------------------------------------------------------
             Precondition:  value and link are received
             Postcondition: A Node has been constructed with value in its
             data part and its next part set to link (default 0).
             ------------------------------------------------------------------*/
        {
            data = value; next = link;
        }

    };
    typedef Node* NodePointer;

    /***** Data Members *****/
    NodePointer myFront,      // pointer to front of queue
        myBack;       // pointer to back of queue


}; // end of class declaration

//------ Prototype of output operator
ostream& operator<< (ostream& out, const Queue& aList);


#endif /* Queue_hpp */