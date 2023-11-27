#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
public:

	string CardName;
	//image CardImage;
	bool isShown;

	Card();
	Card(string x);
	Card(int value);

};
#endif // CARD_H