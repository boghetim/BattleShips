#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "enemyship.h"

class fastEnemy : public enemyShip  //inheritance class
{
public:
    fastEnemy(){};
    fastEnemy(std::string name); //oop: 2 (2/2)
    void Mode();
};

#endif // FASTENEMY_H
