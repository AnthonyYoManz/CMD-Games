#ifndef ANT_HANGING_MAN
#define ANT_HANGING_MAN

#include <string>
#include "AntVector2.h"

class Printer;

class HangingMan
{
private:
	int lives;
	std::string lines[66];
	ant::Vector2i position;
	void generateMan();
public:
	HangingMan(ant::Vector2i _position);
	void draw(Printer* _printer);
	int getLives();
	void setLives(int _lives);
	void dieABitMore();
	ant::Vector2i getPosition();
};

#endif