#include "BlackjackHand.h"

void BlackjackHand::addCardToHand(Card _card)
{
	hand.push_back(_card);
}

int BlackjackHand::getValue()
{
	int value = 0;
	for (auto& i : hand)
	{
		if (i.value == 1)
		{
			value += 11;
		}
		else if (i.value > 10)
		{
			value += 10;
		}
		else
		{
			value += i.value;
		}
	}
	if (value > 21)
	{
		for (auto& i : hand)
		{
			if (i.value == 1)
			{
				value -= 10;
				if (value <= 21)
				{
					break;
				}
			}
		}
	}
	return value;
}
unsigned int BlackjackHand::getSize()
{
	return hand.size();
}
Card BlackjackHand::getCard(unsigned int _index)
{
	Card returnValue;
	returnValue.value = 1;
	returnValue.suit = CardSuit::DIAMONDS;
	if (hand.size() >= _index + 1)
	{
		returnValue = hand.at(_index);
	}
	return returnValue;
}

void BlackjackHand::clear()
{
	hand.clear();
}