#include <stdio.h>
#include <stdint.h>
#include <algorithm>

// All possible suits
enum Suit
{
    Spade,
    Club,
    Diamond,
    Heart,
};

// Language for all cards
const char *suitNames[] = {
    "Spades",
    "Clubs",
    "Diamonds",
    "Hearts",
};

const char *cardNames[] = {
    "Ace",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "Jack",
    "Queen",
    "King",
};

// A single card
struct Card
{
    Card(uint8_t _suit = 0, uint8_t _value = 0)
    {
        suit = static_cast<Suit>(_suit); // Cast to suit
        value = _value;
    }
    Suit suit;     // Face of this card
    uint8_t value; // Value (0)

    void show()
    {
        printf("%s of %s.\n", cardNames[value], suitNames[suit]);
    }
};

// A deck of cards
class Deck
{
public:
    Card cards[52];
    Deck()
    {
        // Put each card into the deck
        uint8_t pos = 0;
        for (uint8_t _face = 0; _face < 4; _face++)
        {
            for (uint8_t _value = 0; _value < 13; _value++)
            {
                cards[pos] = Card(_face, _value);
                pos++;
            }
        }

        // Shuffle the deck
        std::random_shuffle(cards, cards + 52); // Messy but, its ok
    }
};
