#include <iostream>
#include <string.h>

#include "game.h"
#include "enemyship.h"

using namespace std;

int main()
{

    game game;
    game.setShips();
    game.getShips();

    enemyShip *a;

    a = new fastEnemy();

    a->Mode();




    delete a;

    return 0;
}
