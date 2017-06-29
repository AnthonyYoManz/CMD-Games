#include "Menu.h"
#include "MenuSystem.h"
#include "Printer.h"
#include "Input.h"
#include "Messenger.h"

void Menu::cleanup()
{
	//Deletes the menu options
	for (auto& i : objects)
	{
		if (i)
		{
			delete i;
		}
	}
}

void Menu::draw(Printer* _printer)
{
	_printer->printMenu(x, y, width, height, objects, selection);
}

std::string Menu::update(Input* _input, Printer* _printer, Messenger* _messenger)
{
	//Allows menu navigation using the keyboard
	if (_input->checkInput(Key::UP) || _input->checkInput(Key::DOWN))
	{
		selection += (_input->checkInput(Key::UP) ? -1 : 1);
		//Wraps the menu selection from start to end
		if (selection < 0)
		{
			selection = objects.size() - 1;
		}
		if (selection >= objects.size())
		{
			selection = 0;
		}
	}
	if (_input->checkInput(Key::RETURN))
	{
		return objects.at(selection)->activate();
	}
	return "NULL";
}