#include "ConsoleApp.h"

ConsoleApp::ConsoleApp()
{
	//turn on curses and set it up for realtime input
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, true);
}

ConsoleApp::~ConsoleApp()
{
	//turn off curses
	endwin();
}

void ConsoleApp::initialise(std::string _initialMenuName)
{
	running = true;

	printer.initialise();
	menuSystem.initialise(&factory, &printer, &input, &messenger, _initialMenuName);
}

void ConsoleApp::update()
{
	if (menuSystem.isRunning())
	{
		menuSystem.update();
	}
	else
	{
		running = false;
	}
}

bool ConsoleApp::isRunning()
{
	return running;
}

MenuFactory& ConsoleApp::getFactory()
{
	return factory;
}