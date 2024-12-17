#include "gamecheck.h"

GameCheck::GameCheck()
{
    //this->checkColor = color;
}

GameCheck::GameCheck(int id, CheckColor color, std::pair<int, int> init)
{
    this->id = id;
    this->checkColor = color;
    this->initCoordinate = init;
    this->currCoordinate = init;
}
