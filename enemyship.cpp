#include "enemyship.h"

#include <iostream>
#include <string>

using namespace std;

enemyShip::enemyShip(string name) : name(name)  //oop: 5
{

}


void enemyShip::setDiff(int newDiff)
{
 difficulty=newDiff;
}

int enemyShip::getDiff()
{
    return difficulty;
}





void enemyShip::Mode()
{

}
