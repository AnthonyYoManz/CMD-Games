//Class Name: MenuPrinter
//Author: Anthony Arian
//Role: Handles the printing of MenuObject content onto the console window

#ifndef ANT_PRINTER

#include <vector> //std::vector
#include <string> //std::string
#include "curses.h"
#include "MenuEntry.h" // MenuObject
#include "AntVector2.h" // ant::Vector2i

struct Colour
{
	enum Name
	{
		BLACK = COLOR_BLACK,
		WHITE = COLOR_WHITE,
		RED = COLOR_RED,
		BLUE = COLOR_BLUE,
		GREEN = COLOR_GREEN
	};
	Name fg;
	Name bg;
	Colour(Name _fg = WHITE, Name _bg = BLACK){
		fg = _fg;
		bg = _bg;
	}
};

class Printer
{
private:
	ant::Vector2i cursorPos;
	Colour borderColour;
	Colour defaultTextColour;
	Colour highlightedTextColour;
	bool colourEnabled;
	char borderChar;
	void setTextColours();
public:
	using EntryList = std::vector < MenuEntry* >;

	void initialise();

	/*Sets the colours for the border*/
	void setBorderColour(Colour _newBorderColour);

	/*Sets the colours for default/unselected text*/
	void setDefaultTextColour(Colour _newDefaultTextColour);

	/*Sets the colours for highlighted/selected text*/
	void setHighlightedTextColour(Colour _newHighlightedTextColour);

	/*Sets the character used for the border*/
	void setBorderChar(char _newBorderChar);

	/*Prints the provided string*/
	void printString(std::string _string, int _colourPair = 1);

	/*Prints the provided string*/
	void printString(std::string _string, int _x, int _y, int _colourPair = 1);

	/*Prints menu with provided details*/
	void printMenu(int _x, int _y, int _width, int _height, EntryList& _objects, 
					int _selection);

	/*Redraws only the previously and newly selected menu objects to avoid the screen
	flashing.*/
	void updateForNewSelection(int _x, int _y, EntryList& _objects, int _selection, 
								int _oldSelection);

	/*Refresh the screen*/
	void display();

	/*Clears the console window*/
	void clearConsole();

	/*Clears a rectangle with the specified parameters*/
	void clearRectangle(int _x, int _y, int _w, int _h);

	/*Allows the user to say whether or not to show the cursor in the console window*/
	void showCursor(bool show);

	/*Sets the position of the cursor for printing*/
	void setCursorPosition(int x, int y);

	/*Enables/disables the usage of colour*/
	void enableColour(bool _enable);
};

#define ANT_PRINTER
#endif