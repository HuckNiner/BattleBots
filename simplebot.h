#ifndef SIMPLEBOT_H
#define SIMPLEBOT_H

#include "battlebot.h"

class SimpleBot: public BattleBot
{
private:
	bool turning = false;
	bool turningAgain = false;


public:
	SimpleBot();
	void takeTurn();
};

#endif
