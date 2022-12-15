#ifndef GAME_H
#define GAME_H

#include "fastenemy.h"
#include "slowenemy.h"
#include "userShip.h"
#include <vector>


class game
{
public:
    game(); //oop:1  (1/2)
    void map(void); //oop: 9
    void ModifyMap(int yCoordinates, int xCoordinates);
    void setShips(void);
    void getShips(void);


private:
    userShip shipName;
    fastEnemy fast;
    slowEnemy slow;
    vector<vector<char>>gameArea; //oop: 11

};

#endif // GAME_H
