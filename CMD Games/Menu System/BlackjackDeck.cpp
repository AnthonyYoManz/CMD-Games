#include "BlackjackDeck.h"
#include <cstdlib>
#include <time.h>

BlackjackDeck::BlackjackDeck()
{
	currentDeckHeight = 52;
	int suit = 0;
	for (unsigned int i = 0; i < 52; i++)
	{
		Card newCard;
		newCard.value = (i % 13) + 1;
		newCard.suit = static_cast<CardSuit>(suit);
		if (newCard.value == 13)
		{
			suit++;
		}
		cards[i] = newCard;
	}
	srand(time(NULL));
}

void BlackjackDeck::swapCards(unsigned int _index1, unsigned int _index2)
{
	Card tempCard = cards[_index1];
	cards[_index1] = cards[_index2];
	cards[_index2] = tempCard;
}

int BlackjackDeck::getTopCardIndex()
{
	return currentDeckHeight - 1;
}

std::string BlackjackDeck::cardToString(Card _card)
{
	std::string newString;
	switch (_card.value)
	{
	case 1:
		newString = "Ace";
		break;
	case 11:
		newString = "Jack";
		break;
	case 12:
		newString = "Queen";
		break;
	case 13:
		newString = "King";
		break;
	default:
		newString = std::to_string(_card.value);
		break;
	}
	switch (_card.suit)
	{
	case CardSuit::CLUBS :
		newString += " of Clubs";
		break;
	case CardSuit::HEARTS:
		newString += " of Hearts";
		break;
	case CardSuit::SPADES:
		newString += " of Spades";
		break;
	case CardSuit::DIAMONDS:
		newString += " of Diamonds";
		break;
	}
	return newString;
}

void BlackjackDeck::shuffle()
{
	for (unsigned int i = 0; i < 52; i++)
	{
		swapCards(i, rand() % 52);
	}
	currentDeckHeight = 52;
}

Card BlackjackDeck::deal()
{
	Card topCard = cards[getTopCardIndex()];
	currentDeckHeight--;
	return topCard;
}