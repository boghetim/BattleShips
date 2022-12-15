#ifndef GAME_H
#define GAME_H

#include "fastenemy.h"
#include "slowenemy.h"
#include "userShip.h"
#include <vector>


class game
{
public:
    game();
    void map(void);
    void ModifyMap(int yCoordinates, int xCoordinates);
    void setShips(void);
    void getShips(void);


private:
    userShip shipName;
    fastEnemy fast;
    slowEnemy slow;
    vector<vector<char>>gameArea;

};

#endif // GAME_H
