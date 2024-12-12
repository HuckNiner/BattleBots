#include "simplebot.h"
#include <iostream>

SimpleBot::SimpleBot()
{

}
enum LastTurn {
    Left, 
    Right  
};
LastTurn lastTurn = LastTurn::Right;
void SimpleBot::takeTurn()
{
    if (amOnExit()) {
        return;
    }
    if (!frontIsClear() && !rightIsClear()) {
        turnLeft();
    }
    if (turning) {      
        turningAgain = true;
        turning = false;
        move();
        cout << "turning is true" << endl;
    }
    else if (turningAgain) {
        cout << "turningAgain is true" << endl;
        if (lastTurn == LastTurn::Right) {
            turnLeft();
            turningAgain = false;
            lastTurn = LastTurn::Left;
        }
        else if (lastTurn == LastTurn::Left) {
            turnRight();
            turningAgain = false;
            lastTurn = LastTurn::Right;
        }
    }
    else if (frontIsClear()) {
        move();
    }
    else {
        if (lastTurn == LastTurn::Left) {
            turnRight();
            turning = true;
        }
        else if (lastTurn == LastTurn::Right) {
            turnLeft();
            turning = true;
        }
    }


}
