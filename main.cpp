#include <iostream>
#include <string.h>

#include "game.h"
#include "enemyship.h"



int main()
{
    game game;
    game.setShips();
    game.getShips();
    game.map();

    enemyShip *a;

    a = new fastEnemy();

    a->Mode();




    delete a;

    return 0;
}
