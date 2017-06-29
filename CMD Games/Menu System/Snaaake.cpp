#include "Snaaake.h"
#include "Input.h"
#include "Printer.h"

Snaaake::Snaaake()
{
	direction = 0;
	lives = 3;
	initialPosition = { 1, 1 };
	headPosition = initialPosition;
	headGraphic[0] = '>';
	headGraphic[1] = '^';
	headGraphic[2] = '<';
	headGraphic[3] = 'v';
	bodyGraphic = '+';
}

void Snaaake::reset()
{
	bodyParts.clear();
	headPosition = initialPosition;
	direction = 0;
}

bool Snaaake::handleInput(Input* _input)
{
	if (_input->checkInput(Key::RIGHT))
	{
		if (bodyParts.size() > 0)
		{
			if (direction != 2)
			{
				direction = 0;
			}
		}
		else
		{
			direction = 0;
		}
		return true;
	}
	else if (_input->checkInput(Key::UP))
	{
		if (bodyParts.size() > 0)
		{
			if (direction != 3)
			{
				direction = 1;
			}
		}
		else
		{
			direction = 1;
		}
		return true;
	}
	else if (_input->checkInput(Key::LEFT))
	{
		if (bodyParts.size() > 0)
		{
			if (direction != 0)
			{
				direction = 2;
			}
		}
		else
		{
			direction = 2;
		}
		return true;
	}
	else if (_input->checkInput(Key::DOWN))
	{
		if (bodyParts.size() > 0)
		{
			if (direction != 1)
			{
				direction = 3;
			}
		}
		else{
			direction = 3;
		}
		return true;
	}
	return false;
}

bool Snaaake::update()
{
	if (bodyParts.size() > 0)
	{
		for (unsigned int i = bodyParts.size() - 1; i >= 1; i--)
		{
			bodyParts.at(i) = bodyParts.at(i - 1);
		}
		bodyParts.at(0) = headPosition;
	}
	switch (direction)
	{
	case 0:
		headPosition.x++;
		break;
	case 1:
		headPosition.y--;
		break;
	case 2:
		headPosition.x--;
		break;
	case 3:
		headPosition.y++;
		break;
	}
	for (unsigned int i = 2; i < bodyParts.size(); i++)
	{
		ant::Vector2i& ref = bodyParts.at(i);
		if (headPosition.x == ref.x && headPosition.y == ref.y)
		{
			die();
			return true;
		}
	}
	return false;
}
void Snaaake::draw(Printer* _printer)
{
	for (auto& i : bodyParts)
	{
		_printer->printString(std::string(1, bodyGraphic), i.x, i.y);
	}
	_printer->printString(std::string(1, headGraphic[direction]), 
									headPosition.x, headPosition.y);
}
void Snaaake::setPosition(ant::Vector2i _position)
{
	headPosition = _position;
	initialPosition = headPosition;
}

ant::Vector2i Snaaake::getPosition()
{
	return headPosition;
}

int Snaaake::getLives()
{
	return lives;
}

void Snaaake::collectBodyPart()
{
	if (bodyParts.size() > 0)
	{
		bodyParts.push_back(bodyParts.back());
	}
	else
	{
		bodyParts.push_back(headPosition);
	}
}

void Snaaake::die()
{
	reset();
	lives--;
	if (lives <= 0)
	{
		lives = 0;
	}
}