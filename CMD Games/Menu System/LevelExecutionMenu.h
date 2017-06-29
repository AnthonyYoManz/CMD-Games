//Class Name: LevelExecutionMenu
//Author: Anthony Arian
//Role: Steps through the level execution script using the command queue

#ifndef ANT_LEVEL_EXECUTION_MENU
#define ANT_LEVEL_EXECUTION_MENU

#include "App.h"
#include "Menu.h"
#include "Level.h"
#include "CommandQueue.h"

class LevelExecutionMenu : public Menu
{
protected:
	int x, y, width, height;
	Level* level;
	CommandQueue* commandQueue;
public:
	void initialise(App* _app);
	void cleanup();
	void draw();
	std::string update();
};

#endif