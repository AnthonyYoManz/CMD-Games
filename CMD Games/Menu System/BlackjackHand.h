#ifndef ANT_BLACKJACK_HAND
#define ANT_BLACKJACK_HAND

#include "BlackjackCards.h"
#include <vector>

class BlackjackHand
{
private:
	std::vector<Card> hand;
public:
	void addCardToHand(Card _card);
	int getValue();
	unsigned int getSize();
	Card getCard(unsigned int _index);
	void clear();
};

#endif