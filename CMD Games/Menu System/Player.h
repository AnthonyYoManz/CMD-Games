//Class Name: Player
//Author: Anthony Arian
//Role: A class for all of the player/lightbot information

#ifndef ANT_PLAYER
#define ANT_PLAYER

class Player
{
public:
	int dir;
	int x, y;
	void moveForward();
	void moveBackward();
	void turnRight();
	void turnLeft();
};

#endif