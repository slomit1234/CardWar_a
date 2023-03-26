#include "player.hpp"

class Player {
public:
    Player(const string& name = "");

    void addCard(Card* pCard);
    void clear();
    int getTotal() const;

    const string& getName() const;

    friend ostream& operator<<(ostream& os, const Player& aPlayer);

protected:
    vector<Card*> m_Hand;
    string m_Name;
};

Player::Player(const string& name) :
    m_Name(name) {}

void Player::addCard(Card* pCard) {
    m_Hand.push_back(pCard);
}

void Player::clear() {
    m_Hand.clear();
}

int Player::getTotal() const {
    if (m_Hand.empty()) {
        return 0;
    }

    int total = 0;
    bool hasAce = false;

    for (Card* card : m_Hand) {
        total += card->getValue();
        if (card->getValue() == Card::ACE) {
            hasAce = true;
        }
    }

    if (hasAce && total <= 11) {
        total += 10;
    }

    return total;
}

const string& Player::getName() const {
    return m_Name;
}

ostream& operator<<(ostream& os, const Player& aPlayer) {
    os << aPlayer.m_Name << ":\t";

    if (!aPlayer.m_Hand.empty()) {
        for (const auto& card : aPlayer.m_Hand) {
            os << *card << "\t";
        }

        if (aPlayer.getTotal() != 0) {
            os << "(" << aPlayer.getTotal() << ")";
        }
    }
    else {
        os << "<empty>";
    }

    return os;
}
