//Class Name: SnakeGrid
//Author: Anthony Arian
//Role: Provides some basic functions for the snake game's grid

#ifndef ANT_SNAKE_GRID
#define ANT_SNAKE_GRID

#include "AntVector2.h"

class Printer;

class SnakeGrid
{
private:
	ant::Vector2i position;
	ant::Vector2i size;
	char graphic;
public:
	SnakeGrid(ant::Vector2i _position, ant::Vector2i _size, char _graphic);
	void draw(Printer* _printer);
	ant::Vector2i getPosition();
	ant::Vector2i getSize();
	bool coordIsWithinBounds(ant::Vector2i _coord);
};

#endif