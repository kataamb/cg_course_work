#ifndef GAMECHECK_H
#define GAMECHECK_H

#include "checkcoordinate.h"
#include <utility>

#include "gamecheckcolor.h"

struct GameCheck
{
public:
    GameCheck();
    GameCheck(int id, CheckColor color, std::pair<int, int> init);

    std::pair<int, int> initCoordinate;
    std::pair<int, int> currCoordinate;

    int id;

    enum CheckColor checkColor;

};

#endif // GAMECHECK_H
