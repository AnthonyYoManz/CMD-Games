#ifndef ANT_HANGMAN
#define ANT_HANGMAN

#include "Game.h"
#include "HangingMan.h"
#include "AntClock.h"
#include "Difficulties.h"
#include <vector>
#include <string>

class Hangman : public Game
{
private:
	HangingMan hangingMan;
	std::vector<std::string> wordPool;
	std::vector<char> usedLetters;
	unsigned int chosenWord;
	std::string foggedWord;
	ant::Clock winScreenTimer;
	bool winScreenTimerSet;

	std::string stringToUpper(std::string _string);
	void loadWordPool(std::string _filename);
	bool checkDuplicateLetter(char _letter);
	bool verifyLetter(char _letter);
public:
	Hangman();
	~Hangman() = default;
	void update(Input* _input, Messenger* _messenger);
	void draw(Printer* _printer);
	void setDifficulty(Difficulty _difficulty);
};

#endif