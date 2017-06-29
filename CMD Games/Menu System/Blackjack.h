#ifndef ANT_BLACKJACK
#define ANT_BLACKJACK

#include "Game.h"
#include "BlackjackDeck.h"
#include "BlackjackHand.h"
#include "AntClock.h"


enum class BlackjackState
{
	BET_MENU,
	HITSTAND_MENU,
	WIN_SCREEN,
	LOSE_SCREEN
};

class Blackjack : public Game
{
private:
	int money;
	int bet;
	BlackjackState state;
	BlackjackDeck deck;
	BlackjackHand playerHand;
	BlackjackHand dealerHand;
	ant::Clock winScreenTimer;
	bool timerSet;

	void beginGame();
public:
	Blackjack();
	~Blackjack() = default;
	void update(Input* _input, Messenger* _messenger);
	void draw(Printer* _printer);
};

#endif