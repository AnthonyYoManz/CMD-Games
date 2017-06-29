//Class Name: Game
//Author: Anthony Arian
//Role: Base class for the games, provides isActive function

#ifndef ANT_GAME
#define ANT_GAME

class Input;
class Printer;
class Messenger;

class Game
{
protected:
	bool active;
public:
	virtual ~Game() = default;
	virtual void update(Input* _input, Messenger* _messenger) = 0;
	virtual void draw(Printer* _printer) = 0;
	bool isActive();
};

#endif