#include "Queue.hpp"
#include <iostream>
using namespace std;
int main() {

    Queue q1(12);
    for (int i = 0; i < 12; i++) {
        cout << " [" << i << "]";
        q1.enqueue(i);
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
        //head = head->next;
    }
    int card1, card2;
    cout << "Enter first card" << endl;
    cin >> card1;
    cout << "Enter first card" << endl;
    cin >> card2;
    cout << q1.isMatched(card1, card2);
    return 0;
}
