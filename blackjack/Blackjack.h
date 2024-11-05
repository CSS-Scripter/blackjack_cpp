#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"

namespace Blackjack
{
    enum Result
    {
        player_win  = -1,
        tie         =  0,
        dealer_win  =  1,
    };

    Result play();
    bool playerTurn(Player& player, Deck& deck);
    bool dealerTurn(Player& dealer, Deck& deck);
    bool dealerTurn(Player& dealer, Deck& deck, int pointsToBeat);
    bool shouldHit();
};

#endif
