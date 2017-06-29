#include "Printer.h"
#include "curses.h"

void Printer::initialise()
{
	colourEnabled = false;
	showCursor(false);
	if (has_colors() == TRUE)
	{
		start_color();
		enableColour(true);
	}
	defaultTextColour = Colour(Colour::WHITE, Colour::BLACK);
	highlightedTextColour = Colour(Colour::BLACK, Colour::WHITE);
	borderColour = Colour(Colour::WHITE, Colour::BLACK);
	setTextColours();
	borderChar = '*';
}

void Printer::setBorderColour(Colour _newBorderColour)
{
	borderColour = _newBorderColour;
	setTextColours();
	return;
}

void Printer::setDefaultTextColour(Colour _newDefaultTextColour)
{
	borderColour = _newDefaultTextColour;
	setTextColours();
	return;
}

void Printer::setHighlightedTextColour(Colour _newHighlightedTextColour)
{
	borderColour = _newHighlightedTextColour;
	setTextColours();
	return;
}

void Printer::setBorderChar(char _newBorderChar)
{
	borderChar = _newBorderChar;
	return;
}

void Printer::printString(std::string _string, int _colourPair)
{
	attron(COLOR_PAIR(_colourPair));
	printw(_string.c_str());
	attroff(COLOR_PAIR(_colourPair));
	return;
}

void Printer::printString(std::string _string, int _x, int _y, int _colourPair)
{
	setCursorPosition(_x, _y);
	printString(_string, _colourPair);
	return;
}

void Printer::printMenu(int _x, int _y, int _width, int _height, EntryList& _objects, 
							int _selection)
{
	//Loops through a rectangle and draws *s for the border
	for (int ix = 0; ix < _width; ix++)
	{
		for (int iy = 0; iy < _height; iy++)
		{
			if (iy == 0 || ix == 0 || iy == _height - 1 || ix == _width - 1)
			{
				setCursorPosition(_x + ix, _y + iy);
				printString(std::string(1, borderChar), 3);
			}
		}
	}
	//Lists the menu options
	int yPos = 0;
	for (auto& i : _objects)
	{
		setCursorPosition(1 + _x, 1 + _y + yPos);
		yPos++;
		printString(i->getName());
	}
	//Highlights the currently selected menu option
	setCursorPosition(1 + _x, 1 + _y + _selection);
	printString(_objects.at(_selection)->getName(), 2);
	return;
}

void Printer::updateForNewSelection(int _x, int _y, EntryList& _objects, int _selection, int _oldSelection)
{
	setCursorPosition(_x + 1, 1 + _y + _oldSelection);
	printString(_objects.at(_oldSelection)->getName());

	setCursorPosition(_x + 1, 1 + _y + _selection);
	printString(_objects.at(_selection)->getName(), 2);
	return;
}

void Printer::display()
{
	refresh();
	return;
}

void Printer::clearConsole()
{
	clear();
	return;
}

void Printer::clearRectangle(int _x, int _y, int _w, int _h)
{
	for (int ix = 0; ix < _w; ix++)
	{
		for (int iy = 0; iy < _h; iy++)
		{
			setCursorPosition(_x + ix, _y + iy);
			printString(" ");
		}
	}
	return;
}

void Printer::showCursor(bool _show)
{
	curs_set(_show ? 1 : 0);
	int thing = 5;
	return;
}

void Printer::setCursorPosition(int _x, int _y)
{
	cursorPos.x = _x;
	cursorPos.y = _y;
	move(_y, _x);
	return;
}

void Printer::setTextColours()
{
	if (colourEnabled)
	{
		init_pair(1, defaultTextColour.fg, defaultTextColour.bg);
		init_pair(2, highlightedTextColour.fg, highlightedTextColour.bg);
		init_pair(3, borderColour.fg, borderColour.bg);
	}
	return;
}

void Printer::enableColour(bool _enabled)
{
	colourEnabled = _enabled;
}