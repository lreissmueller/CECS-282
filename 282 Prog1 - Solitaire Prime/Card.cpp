#include "Card.h"
#include <iostream>
using namespace std;

Card::Card()
{
    rank;
    suit;
}

Card::Card(char r, char s)
{
    rank = r;
    suit = s;
}

void Card::showCard()
{
    cout << rank << "" << suit;
}

void Card::setCard(char rank, char suit)
{
    Card card(rank, suit);
}

int Card::getValue()
{
    char ranks[13] = {'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
    for (int i = 0; i < sizeof(ranks); i++)
    {
        if (i >= 9)
        {
            return 10;
        }
        if (ranks[i] == rank)
        {
            return i + 1;
        }
    }
}