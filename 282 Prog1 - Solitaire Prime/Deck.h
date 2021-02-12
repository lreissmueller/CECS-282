#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
    private:
        Card storage[52];
    public:
        Deck();
        void refreshDeck();
        void showDeck();
        void shuffle();
        Card deal();
        int cardsLeft();
        Card currentCard();
        int unplayed = 0;
        int current = 0;
        
};

#endif