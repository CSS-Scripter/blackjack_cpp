#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <array>

class Deck
{

private:
    std::array<Card, 52> m_cards {};
    std::size_t m_nextCardIndex { 0 };

public:
    Deck()
    {
        std::size_t count { 0 };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                m_cards[count++] = Card{ rank, suit };
    }

    Card dealCard();
    void shuffle();

};

#endif
