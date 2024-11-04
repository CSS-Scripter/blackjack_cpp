#include "Deck.h"
#include "Card.h"
#include "Random.h"

#include <algorithm>

Card Deck::dealCard()
{
    return m_cards[m_nextCardIndex++];
}

void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
}
