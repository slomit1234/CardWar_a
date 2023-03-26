#include "card.hpp"

class Card {
public:
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(Rank rank = ACE, Suit suit = SPADES, bool isFaceUp = true);
    int getValue() const;
    void flip();

    friend ostream& operator<<(ostream& os, const Card& aCard);

private:
    Rank m_Rank;
    Suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(Rank rank, Suit suit, bool isFaceUp) :
    m_Rank(rank), m_Suit(suit), m_IsFaceUp(isFaceUp) {}

int Card::getValue() const {
    int value = 0;
    if (m_IsFaceUp) {
        value = m_Rank;
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}

void Card::flip() {
    m_IsFaceUp = !m_IsFaceUp;
}

ostream& operator<<(ostream& os, const Card& aCard) {
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp) {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else {
        os << "XX";
    }

    return os;
}