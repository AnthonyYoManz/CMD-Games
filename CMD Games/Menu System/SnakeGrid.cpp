#include "SnakeGrid.h"
#include "Printer.h"
#include <string>

SnakeGrid::SnakeGrid(ant::Vector2i _position, ant::Vector2i _size, char _graphic)
{
	position = _position;
	size = _size;
	graphic = _graphic;
}

void SnakeGrid::draw(Printer* _printer)
{
	for (int ix = position.x; ix < position.x + size.x; ix++)
	{
		for (int iy = position.y; iy < position.y + size.y; iy++)
		{
			if (ix == position.x || ix == position.x + size.x - 1 ||
				iy == position.y || iy == position.y + size.y - 1)
			{
				_printer->printString(std::string(1, graphic), ix, iy);
			}
		}
	}
}

ant::Vector2i SnakeGrid::getPosition()
{
	return position;
}

ant::Vector2i SnakeGrid::getSize()
{
	return size;
}

bool SnakeGrid::coordIsWithinBounds(ant::Vector2i _coord)
{
	return (_coord.x > position.x && _coord.x < position.x + size.x - 1 &&
			_coord.y > position.y && _coord.y < position.y + size.y - 1);
}