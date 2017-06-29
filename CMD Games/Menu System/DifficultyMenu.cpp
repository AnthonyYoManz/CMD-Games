#include "DifficultyMenu.h"
#include "MenuSystem.h"
#include "Printer.h"
#include "Input.h"
#include "Messenger.h"
#include "Hangman.h"
#include "Snake.h"

void DifficultyMenu::initialise()
{
	gameName = "";
	x = 21;
	y = 1;
	//Adds menu options
	objects.push_back(new MenuEntry("Easy", "RESET"));
	objects.push_back(new MenuEntry("Medium", "RESET"));
	objects.push_back(new MenuEntry("Hard", "RESET"));
	objects.push_back(new MenuEntry("Back", "POP"));
	selection = 0;
	width = 8;
	height = objects.size() + 2;
}

void DifficultyMenu::draw(Printer* _printer)
{
	Menu::draw(_printer);
	_printer->clearRectangle(0, 0, 80, 1);
	_printer->printString("Select a difficulty", 0, 0);
}

std::string DifficultyMenu::update(Input* _input, Printer* _printer, Messenger* _messenger)
{
	std::string returnValue = Menu::update(_input, _printer, _messenger);

	if (gameName == "")
	{
		Message message;
		while (_messenger->pollMessage(message))
		{
			if (message.topic == "Game Name")
			{
				gameName = message.message;
			}
		}
	}

	if (_input->checkInput(Key::RETURN) && selection < 3)
	{
		Difficulty difficulty;
		switch (selection)
		{
		case 0:
			difficulty = Difficulty::EASY;
			break;
		case 1:
			difficulty = Difficulty::MEDIUM;
			break;
		default:
			difficulty = Difficulty::HARD;
			break;
		}
		if (gameName == "Hangman")
		{
			//Start game
			_printer->clearConsole();
			Hangman hangman;
			hangman.setDifficulty(difficulty);
			while (hangman.isActive())
			{
				hangman.update(_input, _messenger);
				hangman.draw(_printer);
			}
		}
		else if (gameName == "Snake")
		{
			//Start game
			_printer->clearConsole();
			Snake snake;
			snake.setDifficulty(difficulty);
			while (snake.isActive()){
				snake.update(_input, _messenger);
				snake.draw(_printer);
			}
		}
	}

	return returnValue;
}