#include "blackjack/Blackjack.h"

#include <iostream>

int main()
{
    Blackjack::Result result { Blackjack::play() };

    switch (result)
    {
        case Blackjack::player_win:
            std::cout << "You win!\n";
            break;
        case Blackjack::dealer_win:
            std::cout << "You lose!\n";
            break;
        case Blackjack::tie:
            std::cout << "You tied!\n";
            break;
    }

    return 0;
}
