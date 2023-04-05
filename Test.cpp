#include <iostream>
#include <stdexcept>

#include "doctest.h"

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;



TEST_CASE("Test Num 1 - Card")
{
	//first case
	Card a(1, "Hearts");
    Card b(1, "Diamonds");
	
	//first case - reversed
	Card c(1, "Diamonds");
    Card d(1, "Hearts");

	
	//second case
    Card e(9, "Heart");
    Card f(1, "Heart");
	
	//secod case - reversed
    Card g(1, "Heart");
    Card h(9, "Heart");
	
	//third case
    Card i(3, "Clover");
    Card j(5, "Heart");
	
	//third case - reversed
    Card k(5, "Heart");
    Card l(3, "Clover");

    CHECK(a.compareto(b) == 0);
    CHECK(c.compareto(d) == 0);
    CHECK(e.compareto(f) == 1);
    CHECK(g.compareto(h) == -1);
    CHECK(i.compareto(j) == -1);
    CHECK(k.compareto(l) == 1);
	
}


TEST_CASE("Test Num 2 - Player")
{
    Player p1("Dora");
    Player p2("Bots");
	Game game(p1, p2);

//initilize
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

//after one "generic" round
game.playTurn();

CHECK(p1.stacksize() == 25);
CHECK(p1.stacksize() == 24); 

CHECK(p2.stacksize() == 25);
CHECK(p1.stacksize() == 24);

//round mechanizm
    Player p11("Shish");
    Player p22("Barak");
	Game game2(p11, p22);
	
	Card A(1, "Diamonds");
    Card B(2, "Hearts");
	Card C(3, "Clover");
    Card D(4, "Pikes");
	
    p11.addCard(A);
    p22.addCard(B);

    CHECK(p1.stacksize() == 27);
	CHECK(p2.stacksize() == 27);
	
	p1.addCard(C);
    p2.addCard(D);
	
	 CHECK(p1.stacksize() == 28);
	CHECK(p2.stacksize() == 28);
	
    CHECK(p1.cardesTaken() == 29);
    CHECK(p2.cardesTaken() == 27);
    CHECK(p2.cardesTaken() == 28);
	
}

TEST_CASE("Test 3 -  Game class")
{
     //check end of the game
	Player p11("shlomi");
    Player p22("slomi");

    Game gam(p11, p22);
	gam.playAll();
    CHECK(gam.printWiner() != "No winner yet");
	
    if (p11.stacksize() == 0)
    {
        string winner = gam.printWiner();
        CHECK(winner == "slomi");
    }
    else
    {
        string winner = gam.printWiner();
        CHECK(winner == "shlomi");
    };
	
	 //check the start of the game
	Player p1("shlomit");
    Player p2("slomit");

    Game game(p1, p2);
    CHECK(game.printWiner() == "No winner yet");

    CHECK(p2.cardesTaken() >= 26);
    CHECK(p2.stacksize() == 52);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);
	
	
	Card a(1, "Hearts");
    Card b(13, "Diamonds");
	Card c(1, "Clover");
    Card d(9, "Pikes");

    p1.addCard(a);

	Card e(4, "Hearts");
    Card f(8,"Diamonds");
	Card g(10, "Clover");
    Card h(12, "Pikes");

    p2.addCard(e);
    p2.addCard(f);
	p2.addCard(g);
	p2.addCard(h);

    game.playTurn();
	string s1 = game.printLastTurn();
    CHECK(s1 == "shlomit played 1 of Hearts slomit played 4 of Hearts. slomit wins." );
	CHECK(s1 == "shlomit played 1 of Hearts slomit played 8 of Diamonds. slomit wins.");
	CHECK	(s1 == "shlomit played 1 of Hearts slomit played 10 of Clover. slomit wins." );
	CHECK(s1 == "shlomit played 1 of Hearts slomit played 12 of Pikes. slomit wins.");
	
	
	CHECK(p1.cardesTaken() == 1);
    CHECK(p2.stacksize() == 25);
	
	p1.addCard(b);
	
	game.playTurn();
    string s2 = game.printLastTurn();
    CHECK(s2 == "shlomit played 13 of Diamonds slomit played 4 of Hearts. shlomit wins." );
	CHECK(s2 == "shlomit played 13 of Diamonds slomit played 8 of Diamonds. shlomit wins.");
	CHECK(s2 == "shlomit played 13 of Diamonds slomit played 10 of Clover. shlomit wins." );
	CHECK(s2 == "shlomit played 13 of Diamonds slomit played 12 of Pikes. shlomit wins." );
	
	
	p1.addCard(c);
	
	game.playTurn();
	string s3 = game.printLastTurn();
    CHECK(s3 == "shlomit played 13 of Diamonds slomit played 4 of Hearts. shlomit wins." );
	CHECK(s3 == "shlomit played 13 of Diamonds slomit played 8 of Diamonds. shlomit wins.");
	CHECK(s3 == "shlomit played 13 of Diamonds slomit played 10 of Clover. shlomit wins." );
	CHECK(s3 == "shlomit played 13 of Diamonds slomit played 12 of Pikes. shlomit wins." );
	
	p1.addCard(d);
	
	game.playTurn();
	string s4 = game.printLastTurn();
    CHECK(s4 == "shlomit played 13 of Diamonds slomit played 4 of Hearts. shlomit wins." );
	CHECK(s4 == "shlomit played 13 of Diamonds slomit played 8 of Diamonds. shlomit wins.");
	CHECK(s4 == "shlomit played 13 of Diamonds slomit played 10 of Clover. shlomit wins." );
	CHECK(s4 == "shlomit played 13 of Diamonds slomit played 12 of Pikes. shlomit wins." );

}