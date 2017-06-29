//Class Name: Input
//Author: Anthony Arian
//Role: Record input information for access from menus

#include <map>	//std::map???
#include "curses.h"

#ifndef ANT_INPUT
#define ANT_INPUT

/*Keys used on the checkInput function so I can swap em around with other libs easily*/
struct Key
{
	enum Name
	{
		UP = KEY_UP,
		DOWN = KEY_DOWN,
		RIGHT = KEY_RIGHT,
		LEFT = KEY_LEFT,
		ENTER = 13,
		RETURN = 13,
		ESCAPE = 27
	};
};

class Input
{
private:
	/*Value is equal to the current input*/
	int input;
public:
	bool checkInput(Key::Name _key);
	int getRawInput();
	void update();
};

#endif