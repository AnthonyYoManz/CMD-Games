#ifndef ANT_BLACKJACK_CARDS
#define ANT_BLACKJACK_CARDS

enum class CardSuit
{
	SPADES = 0,
	CLUBS = 1,
	HEARTS = 2,
	DIAMONDS = 3
};

struct Card
{
	int value;
	CardSuit suit;
};

#endif