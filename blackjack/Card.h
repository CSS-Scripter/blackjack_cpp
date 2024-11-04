#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <array>

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    constexpr static std::array allSuits { suit_club, suit_diamond, suit_heart, suit_spade };
    constexpr static std::array allRanks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };

    Rank rank {};
    Suit suit {};

    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
        static constexpr std::array suits { 'C', 'D', 'H', 'S' };
        static_assert(std::size(ranks) == max_ranks);
        static_assert(std::size(suits) == max_suits);

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    int value()
    {
        static constexpr std::array values { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        static_assert(std::size(values) == max_ranks);

        return values.data()[rank];
    }
};

#endif
