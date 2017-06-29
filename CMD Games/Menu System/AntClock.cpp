#include "AntClock.h"

ant::Clock::Clock()
{
	cClock = clock();
}

void ant::Clock::restart()
{
	cClock = clock();
}

float ant::Clock::getTime()
{
	clock_t ticks = clock() - cClock;
	return (static_cast<float>(ticks) / CLOCKS_PER_SEC);
}