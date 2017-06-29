//Class Name: MenuPrinter
//Author: Anthony Arian
//Role: Menu that manages games with difficulty settings (hangman and snake)

#ifndef ANT_DIFFICULTY_MENU
#define ANT_DIFFICULTY_MENU

#include "Menu.h"
#include <string>

class DifficultyMenu : public Menu
{
private:
	std::string gameName;
public:
	~DifficultyMenu() = default;

	void initialise();

	void draw(Printer* _printer);

	std::string update(Input* _input, Printer* _printer, Messenger* _messenger);
};

#endif