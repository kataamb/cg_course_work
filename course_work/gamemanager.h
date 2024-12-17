#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <map>
#include "gamecheck.h"

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);
    bool can_take_move(std::pair<int, int>, std::pair<int, int>);

    GameCheck move_check(std::pair<int, int> curPos, std::pair<int, int> newPos);

    std::map< std::pair<int, int>,  GameCheck > checksOnPositions;

    void return_initial_game();

signals:

};

#endif // GAMEMANAGER_H
