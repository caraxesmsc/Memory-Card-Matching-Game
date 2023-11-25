#include "Card.h"
#include <string>
using namespace std;
class Card
{
public:
	Card();
	Card(string x);
	string CardName;
	//image CardImage;
	bool isShown;
private:

};

Card::Card()
{
}
//
Card::Card(string x)
{
	CardName = x;
	isShown = false;
}

