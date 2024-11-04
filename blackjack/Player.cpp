#include "Player.h"
#include "Card.h"
#include "Settings.h"

Card Player::drawCard(Deck& deck)
{
    Card card = deck.dealCard();
    score += card.value();
    if (card.rank == Card::rank_ace) ++aces;
    if (score > Settings::bustAt && aces > 0)
    {
        score -= 10;
        --aces;
    }

    return card;
}
