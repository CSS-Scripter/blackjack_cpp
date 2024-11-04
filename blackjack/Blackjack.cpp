#include "Blackjack.h"
#include "Player.h"
#include "Deck.h"
#include "Settings.h"
#include "Sign.h"

Blackjack::Result Blackjack::play()
{
    Player player { Player{} };
    Player dealer { Player{} };

    Deck deck { Deck{} };
    deck.shuffle();

    Card c1 = player.drawCard(deck);
    Card c2 = player.drawCard(deck);
    Card c3 = dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score << " (" << c3 << ")\n";
    std::cout << "You have score: " << player.score << " (" << c1 << "," << c2 << ")\n";

    if (playerTurn(player, deck))
    {
        return dealer_win;
    }

    if (dealerTurn(dealer, deck))
    {
        return player_win;
    }

    // Sign converts numbers to either -1, 0 or 1 (-32 -> -1, 50 -> 1, 0 -> 0)
    // player win = -1, tie = 0, dealer win = 1
    // Higher player score means sign returns -1, higher dealer score means sign returns 1
    int result { sign(dealer.score - player.score) };
    return static_cast<Blackjack::Result>(result);
}

bool Blackjack::playerTurn(Player& player, Deck& deck)
{
    while ((player.score < Settings::bustAt) && shouldHit())
    {
        Card drawn = player.drawCard(deck);
        std::cout << "You were dealt " << drawn << ". You now have: " << player.score << '\n';
    }

    if (player.score > Settings::bustAt)
    {
        std::cout << "You went bust!\n";
        return true;
    }

    return false;
}

bool Blackjack::dealerTurn(Player& dealer, Deck& deck)
{
        while (dealer.score < Settings::dealerStandAt)
    {
        Card drawn = dealer.drawCard(deck);
        std::cout << "The dealer flips a " << drawn << ". They now have: " << dealer.score << '\n';
    }

    if (dealer.score > Settings::bustAt)
    {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return false;
}

bool Blackjack::shouldHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}
