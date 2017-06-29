#ifndef ANT_CLOCK
#define ANT_CLOCK

#include <time.h>

namespace ant
{
	class Clock
	{
	private:
		clock_t cClock;
	public:
		Clock();
		void restart();
		/*Returns the time elapsed in seconds*/
		float getTime();
	};
}

#endif