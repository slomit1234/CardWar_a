#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
using namespace std;
using namespace ariel;

class Player
{

public:
    Player(string);
    int stacksize();
    int cardesTaken();
    void addCard(Card);
};

#endif