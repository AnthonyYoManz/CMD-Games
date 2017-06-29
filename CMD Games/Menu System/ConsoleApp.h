//Class Name: ConsoleApp
//Author: Anthony Arian
//Role: Central manager class handles the menu system

#ifndef ANT_CONSOLE_APP
#define ANT_CONSOLE_APP

#include <string>
#include "MenuSystem.h"
#include "MenuFactory.h"
#include "Printer.h"
#include "Input.h"
#include "Messenger.h"

//Make this work yea

class ConsoleApp
{
private:
	MenuSystem menuSystem;
	MenuFactory factory;
	Printer printer;
	Input input;
	Messenger messenger;
	bool running;
public:
	ConsoleApp();
	~ConsoleApp();
	void initialise(std::string _initialMenuName);
	void update();
	bool isRunning();
	MenuFactory& getFactory();
};

#endif