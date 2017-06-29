#include "HangingMan.h"
#include <fstream>
#include "Printer.h"

HangingMan::HangingMan(ant::Vector2i _position)
{
	position = _position;
	lives = 10;
	generateMan();
}

void HangingMan::generateMan()
{
	std::ifstream reader("hangedman.txt");
	if (reader.is_open())
	{
		unsigned int i = 0;
		while (reader.good() && (i < 66))
		{
			char curLine[10];
			reader.getline(curLine, 10);
			lines[i] = curLine;
			i++;
		}
		reader.close();
	}
	return;
}

void HangingMan::draw(Printer* _printer)
{
	if (lives < 0)
	{
		lives = 0;
	}
	for (unsigned int i = 0; i < 6; i++)
	{
		_printer->printString(lines[(60 - lives * 6) + i], position.x, position.y + i);
	}
	return;
}

int HangingMan::getLives()
{
	return lives;
}

void HangingMan::setLives(int _lives)
{
	lives = _lives;
	return;
}

void HangingMan::dieABitMore()
{
	lives -= 1;
}

ant::Vector2i HangingMan::getPosition()
{
	return position;
}

