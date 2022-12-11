#ifndef GAME_H
#define GAME_H

#include "fastenemy.h"
#include "slowenemy.h"
#include "userShip.h"


class game
{
public:
    game();
    void map(void);
    void setShips(void);
    void getShips(void);

private:
    userShip shipName;
    fastEnemy fast;
    slowEnemy slow;

};

#endif // GAME_H
