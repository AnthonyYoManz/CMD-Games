#ifndef ANT_SNAAAKE
#define ANT_SNAAAKE

#include "AntVector2.h"
#include <vector>

class Input;
class Printer;

class Snaaake
{
private:
	int lives;
	ant::Vector2i initialPosition;
	ant::Vector2i headPosition;
	std::vector<ant::Vector2i> bodyParts;
	int direction;
	char headGraphic[4];
	char bodyGraphic;

	void reset();
public:
	Snaaake();
	~Snaaake() = default;
	bool handleInput(Input* _input);
	bool update();
	void draw(Printer* _printer);
	void setPosition(ant::Vector2i _position);
	ant::Vector2i getPosition();
	int getLives();
	void collectBodyPart();
	void die();
};

#endif