
#include <iostream>
using namespace std;

#include "Queue.hpp"


int main(int argc, const char* argv[]) {
    Queue q1, card1, card2;
    cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;
    q1.createShuffledQueue();


    cout << "Contents of queue q1 (via  cout):\n";
    cout << q1 << endl;

    cout << "Contents of queue q1 (via  printCards() ):\n";
    q1.printCards();

    bool gameMode = true;
    while (gameMode) {
        cout << "\nContents of queue q1 (via  displayGrid() ):\n\n";
        q1.displayGrid();
        int loc1 = q1.chooseCard();
        int loc2 = q1.chooseCard();
        bool checkFlag = q1.checkMatch(loc1, loc2, card1, card2);

        if (checkFlag) {
            cout << "Cards are matched." << endl;

        }
        else {
            cout << "Cards are not matched." << endl;
        }
    }

    q1.deleteQueue();
}
