#include "Deck.h"
#include <iostream>
#include "Card.h"

using namespace std;

Deck::Deck()
{
    char ranks[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[4] = {'S','D','H','C'};
    int count = 0;
    unplayed = 52;

    for(int s = 0; s < 4; s++)
    {
        for(int r = 0; r < 13; r++)
        {
            Card c1(ranks[r], suits[s]);
            storage[count] = c1;
            count++;
        }
    }
}

void Deck::refreshDeck()
{
    char ranks[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[4] = {'S','D','H','C'};
    int count = 0;
    unplayed = 52;
    current = 0;

    for(int s = 0; s < 4; s++)
    {
        for(int r = 0; r < 13; r++)
        {
            Card c1(ranks[r], suits[s]);
            storage[count] = c1;
            count++;
        }
    }
    
}

void Deck::showDeck()
{
    int count = 0;
    for(int s = 0; s < 4; s++)
    {
        for(int r = 0; r < 13; r++)
        {
            storage[count].showCard();
            cout << ", ";
            count++;
        }
        cout << endl;
    }
}

void Deck::shuffle()
{
    for(int i = 0; i < 10000; i++)
    {
        int x = rand() % 52;
        int y = rand() % 52;
        Card temp = storage[x];
        storage[x] = storage[y];
        storage[y] = temp;
    }
}

Card Deck::deal()
{
    Card played('O', 'O');
    Card dealing = storage[current];
    storage[current] = played;
    current++;
    unplayed--;
    return dealing;
}

Card Deck::currentCard()
{
    return storage[current];
}

int Deck::cardsLeft()
{
    return unplayed;
}