//Author: Anthony Arian

#include "Input.h"

bool Input::checkInput(Key::Name _key)
{
	return (_key == input);
}

int Input::getRawInput()
{
	return input;
}

void Input::update()
{
	input = getch();
	return void();
}