#include "Snake.h"
#include "Input.h"
#include "Messenger.h"
#include "Printer.h"
#include <stdlib.h>
#include <time.h>

Snake::Snake() : grid(ant::Vector2i(30, 2), ant::Vector2i(20, 21), '*')
{
	active = true;
	score = 0;
	paused = false;
	lockInput = false;
	loseScreenTimerSet = false;
	srand(time(NULL));
	snaaake.setPosition({ 40, 12 });
	relocatePickUp();
}

void Snake::relocatePickUp()
{
	pickUpPosition = ant::Vector2i(grid.getPosition().x + 1 + rand() % (grid.getSize().x - 2),
								grid.getPosition().y + 1 + rand() % (grid.getSize().y - 2));
}

void Snake::update(Input* _input, Messenger* _messenger)
{
	_input->update();
	if (snaaake.getLives() > 0)
	{
		if (!lockInput)
		{
			lockInput = snaaake.handleInput(_input);
		}
		if (_input->checkInput(Key::ESCAPE))
		{
			active = false;
		}
		if (_input->checkInput(Key::ENTER))
		{
			paused = !paused;
		}
		if (!paused)
		{
			if (frameTimer.getTime() >= frameDelay)
			{
				lockInput = false;
				snaaake.update();
				if (snaaake.getPosition().x == pickUpPosition.x &&
					snaaake.getPosition().y == pickUpPosition.y)
				{
					snaaake.collectBodyPart();
					relocatePickUp();
					score++;
				}
				if (!grid.coordIsWithinBounds(snaaake.getPosition()))
				{
					snaaake.die();
				}
			}
		}
	}
	else if(!loseScreenTimerSet)
	{
		loseScreenTimer.restart();
		loseScreenTimerSet = true;
	}
	else{
		if (loseScreenTimer.getTime() > 3.f)
		{
			active = false;
		}
	}
}

void Snake::draw(Printer* _printer)
{
	if (frameTimer.getTime() >= frameDelay)
	{
		_printer->clearConsole();
		_printer->printString("Use the arrow keys to move! Press enter to pause.", 0, 0);
		_printer->printString("Lives: " + std::to_string(snaaake.getLives()), 0, 1);
		_printer->printString("Score: " + std::to_string(score), 0, 2);
		frameTimer.restart();
		grid.draw(_printer);
		_printer->printString("#", pickUpPosition.x, pickUpPosition.y);
		snaaake.draw(_printer);
		if (paused)
		{
			_printer->printString("[PAUSED]", 36, 13);
		}
		if (snaaake.getLives() <= 0)
		{
			_printer->printString("[You lose scrub]", 32, 13);
		}
		_printer->display();
	}
}

void Snake::setDifficulty(Difficulty _difficulty)
{
	switch (_difficulty)
	{
	case Difficulty::HARD:
		frameDelay = 0.1;
		break;
	case Difficulty::MEDIUM:
		frameDelay = 0.3;
		break;
	default:
		frameDelay = 0.5;
		break;
	}
}