#include "gamemanager.h"

#include <iostream>

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
    // Создание белых шашек
    int id = 0;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 1)
            {
                GameCheck newCheck(id, white, {row, col}); // Преобразуем row для правильного расположения
                this->checksOnPositions[{row, col}] = newCheck; // Сохраняем в обратном порядке
                ++id;
            }
        }
    }

    // Создание черных шашек
    id = 0;
    for (int row = 5; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 1)
            {
                GameCheck newCheck(id, black, {row, col}); // Преобразуем row для правильного расположения
                this->checksOnPositions[{row, col}] = newCheck; // Сохраняем в обратном порядке
                   ++id;

            }
        }
    }

}


void GameManager::return_initial_game()
{
    this->checksOnPositions.clear();
    // Создание белых шашек
    int id = 0;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 1)
            {
                GameCheck newCheck(id, white, {row, col}); // Преобразуем row для правильного расположения
                this->checksOnPositions[{row, col}] = newCheck; // Сохраняем в обратном порядке
                ++id;
            }
        }
    }

    // Создание черных шашек
    id = 0;
    for (int row = 5; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 1)
            {
                GameCheck newCheck(id, black, {row, col}); // Преобразуем row для правильного расположения
                this->checksOnPositions[{row, col}] = newCheck; // Сохраняем в обратном порядке
                   ++id;

            }
        }
    }
}

bool GameManager::can_take_move(std::pair<int, int>, std::pair<int, int>)
{

}



GameCheck GameManager::move_check(std::pair<int, int> curPos, std::pair<int, int> newPos)
{
    std::cout << "currCheck" << (this->checksOnPositions[curPos].id)  << (this->checksOnPositions[curPos].currCoordinate.first)<< " " << (this->checksOnPositions[curPos].currCoordinate.second)<< std::endl;

    GameCheck currCheck { this->checksOnPositions[curPos].id, this->checksOnPositions[curPos].checkColor, this->checksOnPositions[curPos].initCoordinate};
    this->checksOnPositions.erase(curPos);

    currCheck.currCoordinate = newPos;

    this->checksOnPositions[newPos] = currCheck;

    std::cout << "currCheck" << (this->checksOnPositions[newPos].checkColor)  << (this->checksOnPositions[newPos].currCoordinate.first)<< " " << (this->checksOnPositions[newPos].currCoordinate.second)<< std::endl;
    return currCheck;

}
