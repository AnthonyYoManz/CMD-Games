#include "Blackjack.h"
#include "Input.h"
#include "Messenger.h"
#include "Printer.h"

Blackjack::Blackjack()
{
	active = true;
	money = 1000;
	bet = 0;
	state = BlackjackState::BET_MENU;
	timerSet = false;
	deck.shuffle();
}

void Blackjack::update(Input* _input, Messenger* _messenger)
{
	_input->update();
	if (_input->checkInput(Key::ESCAPE))
	{
		active = false;
	}
	else if (state == BlackjackState::BET_MENU)
	{
		if (_input->checkInput(Key::RIGHT))
		{
			if (bet + 10 <= money)
			{
				bet += 10;
			}
		}
		else if (_input->checkInput(Key::LEFT))
		{
			if (bet - 10 >= 0)
			{
				bet -= 10;
			}
		}
		else if (_input->checkInput(Key::ENTER) && bet > 0)
		{
			timerSet = false;
			playerHand.clear();
			dealerHand.clear();
			deck.shuffle();
			playerHand.addCardToHand(deck.deal());
			dealerHand.addCardToHand(deck.deal());
			playerHand.addCardToHand(deck.deal());
			dealerHand.addCardToHand(deck.deal());
			state = BlackjackState::HITSTAND_MENU;
		}
	}
	else if (state == BlackjackState::HITSTAND_MENU)
	{
		if (playerHand.getValue() > 21 || 
			(playerHand.getValue() != 21) && dealerHand.getValue() == 21)
		{
			//lose
			money -= bet;
			bet = 0;
			state = BlackjackState::LOSE_SCREEN;
		}
		else if (dealerHand.getValue() > 21 ||
			(dealerHand.getValue() != 21) && playerHand.getValue() == 21)
		{
			//win
			money += bet;
			bet = 0;
			state = BlackjackState::WIN_SCREEN;
		}
		else if (_input->checkInput(Key::ENTER))
		{
			while (dealerHand.getValue() < 18)
			{
				dealerHand.addCardToHand(deck.deal());
			}
			if (dealerHand.getValue() > 21 || 
				playerHand.getValue() > dealerHand.getValue())
			{
				//win
				money += bet;
				bet = 0;
				state = BlackjackState::WIN_SCREEN;
			}
			else
			{
				//lose
				money -= bet;
				bet = 0;
				state = BlackjackState::LOSE_SCREEN;
			}
		}
		else if (_input->getRawInput() == 'h' || 
				_input->getRawInput() == 'H')
		{
			playerHand.addCardToHand(deck.deal());
		}
	}
	else if (state == BlackjackState::LOSE_SCREEN ||
			state == BlackjackState::WIN_SCREEN)
	{
		if (_input->checkInput(Key::ENTER))
		{
			state = BlackjackState::BET_MENU;
			if (money == 0)
			{
				active = false;
			}
		}
	}
}

void Blackjack::draw(Printer* _printer)
{
	_printer->clearConsole();
	_printer->printString("Money: " + std::to_string(money - bet), 0, 0);
	_printer->printString("Bet: " + std::to_string(bet), 0, 1);
	if (state == BlackjackState::BET_MENU)
	{
		_printer->printString("Use the left or right arrows to change your bet.", 16, 12);
		_printer->printString("Press Enter to confirm.", 29, 13);
	}
	else if (state == BlackjackState::HITSTAND_MENU)
	{
		_printer->printString("Press H to hit or Enter to stand", 25, 12);
		_printer->printString("Your hand:", 0, 2);
		for (unsigned int i = 0; i < playerHand.getSize(); i++){
			_printer->printString(deck.cardToString(playerHand.getCard(i)),
								1, 3 + i);
		}
	}
	else if (state == BlackjackState::LOSE_SCREEN ||
			state == BlackjackState::WIN_SCREEN)
	{
		if (state == BlackjackState::LOSE_SCREEN)
		{
			_printer->printString("[You lose scrub]", 32, 6);
		}
		else
		{
			_printer->printString("[You win m8]", 34, 6);
		}
		_printer->printString("Press Enter to continue.", 28, 7);
		_printer->printString("Your hand:", 0, 2);
		for (unsigned int i = 0; i < playerHand.getSize(); i++)
		{
			_printer->printString(deck.cardToString(playerHand.getCard(i)),
				1, 3 + i);
		}
		_printer->printString("Dealer's hand:", 33, 10);
		for (unsigned int i = 0; i < dealerHand.getSize(); i++)
		{
			_printer->printString(deck.cardToString(dealerHand.getCard(i)),
				34, 11 + i);
		}
	}
	_printer->display();
}