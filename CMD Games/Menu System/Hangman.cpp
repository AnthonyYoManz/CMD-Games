#include "Hangman.h"
#include "Input.h"
#include "Messenger.h"
#include "Printer.h"
#include <fstream>
#include <cctype>
#include <stdlib.h>
#include <time.h>

Hangman::Hangman() : hangingMan(ant::Vector2i(37, 4))
{
	active = true;
	srand(time(NULL));
	winScreenTimerSet = false;
}

void Hangman::setDifficulty(Difficulty _difficulty)
{
	std::string filename = "easyWords.txt";
	switch (_difficulty)
	{
	case Difficulty::HARD:
		filename = "hardWords.txt";
		break;
	case Difficulty::MEDIUM:
		filename = "mediumWords.txt";
		break;
	default:
		filename = "easyWords.txt";
		break;
	}
	loadWordPool(filename);
	chosenWord = rand() % wordPool.size();
	foggedWord = std::string(wordPool.at(chosenWord).length(), '-');
}

void Hangman::update(Input* _input, Messenger* _messenger)
{
	_input->update();
	int userInput = _input->getRawInput();
	if ((foggedWord == wordPool.at(chosenWord)) || (hangingMan.getLives() <= 0))
	{
		if (!winScreenTimerSet)
		{
			winScreenTimer.restart();
			winScreenTimerSet = true;
		}
		if (winScreenTimer.getTime() > 3.f)
		{
			active = false;
		}
	}
	else
	{
		if (userInput >= (int)'a')
		{
			userInput -= (int)'a' - (int)'A';
		}
		if (userInput >= (int)'A' && userInput <= (int)'Z')
		{
			if (!checkDuplicateLetter((char)userInput))
			{
				if (!verifyLetter((char)userInput))
				{
					hangingMan.dieABitMore();
				}
			}
		}
	}
}

void Hangman::draw(Printer* _printer)
{
	_printer->printString("Guess which letters are in this word!", 22, 1);
	_printer->printString(foggedWord, 40-foggedWord.length()/2, 11);
	int usedCharX = 27, usedCharY = 12;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		//26 letts
		bool letterHasBeenUsed = false;
		for (auto& j : usedLetters)
		{
			if (i == j)
			{
				letterHasBeenUsed = true;
			}
		}
		if (letterHasBeenUsed)
		{
			_printer->printString(" ", usedCharX + i - 'A', usedCharY);
		}
		else
		{
			_printer->printString(std::string(1, i), usedCharX + i - 'A', usedCharY);
		}
	}
	hangingMan.draw(_printer);
	if (foggedWord == wordPool.at(chosenWord))
	{
		_printer->printString("[You win m8]", 34, 13);
	}
	else if (hangingMan.getLives() <= 0)
	{
		_printer->printString("[You lose scrub]", 32, 13);
	}
}

std::string Hangman::stringToUpper(std::string _string)
{
	for (char& i : _string)
	{
		i = std::toupper(i);
	}
	return _string;
}

void Hangman::loadWordPool(std::string _filename)
{
	wordPool.clear();
	std::ifstream reader(_filename.c_str());
	if (reader.is_open())
	{
		while (reader.good())
		{
			std::string newWord = "";
			reader >> newWord;
			if (newWord != "")
			{
				wordPool.push_back(stringToUpper(newWord));
			}
		}
		reader.close();
	}
}

bool Hangman::checkDuplicateLetter(char _letter)
{
	for (auto& i : usedLetters)
	{
		if (i == _letter)
		{
			return true;
		}
	}
	usedLetters.push_back(_letter);
	return false;
}

bool Hangman::verifyLetter(char _letter)
{
	size_t position = wordPool.at(chosenWord).find(_letter);
	if (position == std::string::npos)
	{
		return false;
	}
	while (position != std::string::npos)
	{
		foggedWord.at(position) = _letter;
		position = wordPool.at(chosenWord).find(_letter, position + 1);
	}
	return true;
}