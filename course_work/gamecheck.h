#ifndef GAMECHECK_H
#define GAMECHECK_H

#include "checkcoordinate.h"
#include <utility>

enum CheckColor {
    black, white
};

struct GameCheck
{
public:
    GameCheck(CheckColor color);
    GameCheck(CheckColor color, std::pair<char, int> init);
    /*GameCheck(CheckColor color, CheckCoordinate init);
    CheckCoordinate initCoordinate;
    CheckCoordinate currCoordinate;*/
    std::pair<char, int> initCoordinate;
    std::pair<char, int> currCoordinate;

    enum CheckColor checkColor;

};

#endif // GAMECHECK_H
