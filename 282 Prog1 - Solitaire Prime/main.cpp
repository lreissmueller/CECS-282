// Luke Reissmueller
// CECS 282-01
// Prog 1 - Solitaire Prime
// 02/08/2021
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

bool isPrime(int pile)
{
	bool flag = true;
	if (pile <= 1)
	{
		return false;
	}
	for (int i = 2; i < pile; i++)
	{
		if (pile == 2)
		{
			return true;
		}
		if (pile % i == 0)
		{
			return false;
		}
	}
	return flag;
}

Deck play(Deck dk)
{

	int pileValue = 0;
	while (dk.cardsLeft() != 0)
	{
		if (isPrime(pileValue))
		{
			cout << "Prime: " << pileValue << endl;
			pileValue = 0;
		}
		else
		{
			pileValue += dk.currentCard().getValue();
			dk.deal().showCard();
			cout << ", ";
		}
	}
	if (isPrime(pileValue))
	{
		cout << "Prime: " << pileValue << "\nWinner!" << endl;
		
	}
	else
	{
		cout << "Not Prime: " << pileValue << " -- Loser.. Try again?" << endl;
	}
	pileValue = 0;
	return dk;
}

void menu(Deck dk)
{
	string input;
	cout << "1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitaire Prime\n5) Exit\n" << endl;
	cin >> input;

	if (input == "1")
	{
		cout << "Renewing deck...\n";
		dk.refreshDeck();
		cout << "Deck Renewed.\n\n";
		menu(dk);
	}
	else if (input == "2")
	{
		cout << "Showing deck...\n";
		dk.showDeck();
		cout << "\n\n";
		menu(dk);
	}
	else if (input == "3")
	{
		cout << "Shuffling deck...\n";
		dk.shuffle();
		cout << "Deck shuffled\n\n";
		menu(dk);
	}
	else if (input == "4")
	{
		dk = play(dk);
		menu(dk);
		dk.refreshDeck();
	}
	else if (input == "5")
	{
		cout << "Thanks for playing!";
	}
	else
	{
		menu(dk);
	}
}

int main()
{
	cout << rand(52);
	cout << "Welcome to Solitaire Prime!!!\n";
	Deck dk;
	menu(dk);
}

