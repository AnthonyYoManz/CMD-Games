//Author: Anthony Arian

#include "Player.h"

void Player::moveForward()
{
	switch (dir){
	case 0: //North
		y -= 1;
		break;
	case 1: //East
		x += 1;
		break;
	case 2: //South
		y += 1;
		break;
	case 3: //West
		x -= 1;
		break;
	default:
		break;
	}

	return void();
}

void Player::moveBackward()
{
	switch (dir){
	case 0: //North
		y += 1;
		break;
	case 1: //East
		x -= 1;
		break;
	case 2: //South
		y -= 1;
		break;
	case 3: //West
		x += 1;
		break;
	default:
		break;
	}

	return void();
}

void Player::turnLeft()
{
	//Decreases dir by 1 and wraps it between 0 and 3
	dir = dir > 0 ? dir - 1 : 3;

	return void();
}

void Player::turnRight()
{
	//Increases dir by 1 and wraps it between 0 and 3
	dir = dir < 3 ? dir + 1 : 0;
	return void();
}