#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

struct Player
{
    int score { };
    int aces { };

    Card drawCard(Deck& deck);
};

#endif
