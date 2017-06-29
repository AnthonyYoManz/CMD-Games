#ifndef ANT_BLACKJACK_DECK
#define ANT_BLACKJACK_DECK

#include <string>
#include "BlackjackCards.h"

class BlackjackDeck
{
private:
	Card cards[52];
	int currentDeckHeight;
	void swapCards(unsigned int _index1, unsigned int _index2);
	int getTopCardIndex();
public:
	BlackjackDeck();
	~BlackjackDeck() = default;
	void shuffle();
	Card deal();
	int getRemainingSize();
	std::string cardToString(Card _card);
};

#endif