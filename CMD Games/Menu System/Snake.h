#ifndef ANT_SNAKE
#define ANT_SNAKE

#include "Game.h"
#include "Difficulties.h"
#include "SnakeGrid.h"
#include "Snaaake.h"
#include "AntClock.h"
#include "AntVector2.h"

class Snake : public Game
{
private:
	int score;
	bool lockInput;
	bool paused;
	ant::Clock loseScreenTimer;
	bool loseScreenTimerSet;
	ant::Clock frameTimer;
	float frameDelay;
	ant::Vector2i pickUpPosition;
	SnakeGrid grid;
	Snaaake snaaake;

	void relocatePickUp();
public:
	Snake();
	~Snake() = default;
	void update(Input* _input, Messenger* _messenger);
	void draw(Printer* _printer);
	void setDifficulty(Difficulty _difficulty);
};

#endif