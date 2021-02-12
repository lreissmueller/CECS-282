#ifndef CARD_H
#define CARD_H

class Card
{
    private:
        char rank;
        char suit;

    public:
        Card();
        Card(char, char);
        void showCard();
        void setCard(char, char);
        int getValue();
};

#endif