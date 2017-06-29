//Author: Anthony Arian

#include "MainMenu.h"
#include "Printer.h"
#include "Input.h"
#include "Messenger.h"
#include "Blackjack.h"

void MainMenu::initialise()
{
	x = 0;
	y = 1;
	//Adds menu options
	objects.push_back(new MenuEntry("Snake", "DifficultyMenu"));
	objects.push_back(new MenuEntry("Hangman", "DifficultyMenu"));
	objects.push_back(new MenuEntry("Blackjack", "NULL"));	
	objects.push_back(new MenuEntry("Exit", "POP"));
	selection = 0;
	width = 22;
	height = objects.size() + 2;

	return;
}

void MainMenu::draw(Printer* _printer)
{
	Menu::draw(_printer);
	_printer->printString(
		"Use the arrow keys to navigate and the enter key to confirm your selection",
		0, 0);
	return;
}

std::string MainMenu::update(Input* _input, Printer* _printer, Messenger* _messenger)
{
	std::string returnValue = Menu::update(_input, _printer, _messenger);

	if (_input->checkInput(Key::RETURN) && selection < 2)
	{
		Message gameMessage;
		gameMessage.sender = "MainMenu";
		gameMessage.topic = "Game Name";
		gameMessage.message = objects.at(selection)->getName();
		_messenger->addMessage(gameMessage);
	}
	if (_input->checkInput(Key::RETURN) && selection == 2)
	{
		Blackjack blackjack;
		while (blackjack.isActive())
		{
			blackjack.update(_input, _messenger);
			blackjack.draw(_printer);
		}
	}

	return returnValue;
}