#include "gamecheck.h"

GameCheck::GameCheck(CheckColor color)
{
    this->checkColor = color;
}

GameCheck::GameCheck(CheckColor color, std::pair<char, int> init)
{
    this->checkColor = color;
    this->initCoordinate = init;
    this->currCoordinate = init;
}
